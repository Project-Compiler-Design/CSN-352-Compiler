#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// --- Global Variables ---
unordered_map<string, string> regMap;
vector<string> availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4"};

unordered_map<string, string> constValue = {
    {"a", "3"},
    {"b", "4"}
};

// Track loaded constants to avoid redundant li
unordered_map<string, bool> loadedConstants;

vector<string> mipsCode;

// --- Helper Functions ---
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

bool isConstant(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

string getRegister(const string& var) {
    if (regMap.count(var)) return regMap[var];
    if (availableRegs.empty()) {
        cerr << "Register spill not handled\n";
        exit(1);
    }
    string reg = availableRegs.back();
    availableRegs.pop_back();
    regMap[var] = reg;
    return reg;
}

// --- MIPS Code Generator ---
void generateMIPS(const string& line) {
    string trimmed = trim(line);

    if (trimmed.find("FUNC_BEGIN") == 0) {
        istringstream iss(trimmed);
        string dummy, funcName;
        iss >> dummy >> funcName;
        mipsCode.push_back(funcName + ":");
        mipsCode.push_back("    addi $sp, $sp, -16");
        mipsCode.push_back("    sw $ra, 4($sp)");
        mipsCode.push_back("    sw $fp, 0($sp)");
        mipsCode.push_back("    move $fp, $sp");
        return;
    }

    if (trimmed.find("FUNC_END") == 0) {
        mipsCode.push_back("    move $sp, $fp");
        mipsCode.push_back("    lw $fp, 0($sp)");
        mipsCode.push_back("    lw $ra, 4($sp)");
        mipsCode.push_back("    addi $sp, $sp, 16");
        mipsCode.push_back("    jr $ra");

        // Clear tracking state for new functions
        regMap.clear();
        availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4"};
        loadedConstants.clear();
        return;
    }

    if (trimmed.find("RETURN") == 0) {
        istringstream iss(trimmed);
        string keyword, val;
        iss >> keyword >> val;
        mipsCode.push_back("    li $v0, " + val);
        return;
    }

    if (trimmed.find(":=") != string::npos) {
        size_t lhsEnd = trimmed.find(":=");
        string lhs = trim(trimmed.substr(0, lhsEnd));
        string rhs = trim(trimmed.substr(lhsEnd + 2));

        size_t opPos = rhs.find_first_of("+-*/");

        if (opPos != string::npos) {
            string op1 = trim(rhs.substr(0, opPos));
            string op2 = trim(rhs.substr(opPos + 1));
            char op = rhs[opPos];

            string r1 = getRegister(op1);
            string r2 = getRegister(op2);
            string rd = getRegister(lhs);

            // if (constValue.count(op1) && !loadedConstants[op1]) {
            //     mipsCode.push_back("    li " + r1 + ", " + constValue[op1]);
            //     loadedConstants[op1] = true;
            // }
            // if (constValue.count(op2) && !loadedConstants[op2]) {
            //     mipsCode.push_back("    li " + r2 + ", " + constValue[op2]);
            //     loadedConstants[op2] = true;
            // }

            switch (op) {
                case '+': mipsCode.push_back("    add " + rd + ", " + r1 + ", " + r2); break;
                case '-': mipsCode.push_back("    sub " + rd + ", " + r1 + ", " + r2); break;
                case '*': mipsCode.push_back("    mul " + rd + ", " + r1 + ", " + r2); break;
                case '/':
                    mipsCode.push_back("    div " + r1 + ", " + r2);
                    mipsCode.push_back("    mflo " + rd);
                    break;
            }
        } else {
            string dst = getRegister(lhs);
            if (constValue.count(rhs) && !loadedConstants[rhs]) {
                mipsCode.push_back("    li " + dst + ", " + constValue[rhs]);
                loadedConstants[rhs] = true;
                // cout<<"Loaded constant: " << rhs << " into " << dst << endl;
            } else if (isConstant(rhs)) {
                mipsCode.push_back("    li " + dst + ", " + rhs);
                cout<<"Loaded constant: " << rhs << " into " << dst << endl;
            } else {
                string src = getRegister(rhs);
                mipsCode.push_back("    move " + dst + ", " + src);
            }
        }
    }
}

// --- Main Function ---
int main() {
    ifstream infile("../output/output1.txt");
    if (!infile.is_open()) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    vector<string> cleanedLines;
    string line;

    while (getline(infile, line)) {
        line = trim(line);
        size_t dotPos = line.find('.');
        if (dotPos != string::npos) {
            line = trim(line.substr(dotPos + 1));  // remove line number and trim again
        }
        if (!line.empty()) cleanedLines.push_back(line);
    }

    for (const string& codeLine : cleanedLines) {
        generateMIPS(codeLine);
    }

    cout << "# MIPS Assembly Code:\n";
    for (auto& line : mipsCode) {
        cout << line << endl;
    }

    return 0;
}
