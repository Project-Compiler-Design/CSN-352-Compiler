#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

#include "../include/utility.h" // Include your utility header
using namespace std;

// Simulated symbol table structure


// Symbol table type
int currentInstructionIndex = -1;

map<pair<scoped_symtab*,string>,string> var_to_reg;
unordered_map<string,pair<scoped_symtab*,string>> reg_to_var;
map<string, int> funcStackSize;

// --- Global Variables ---
unordered_map<string, string> regMap;
vector<string> availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5"};
vector<string> mipsCode;
unordered_map<string, bool> loadedConstants;
unordered_map<string,string> reg_of_const;

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};


struct LivenessInfo {
    scoped_symtab* scope;
    string code;
    unordered_set<pair<scoped_symtab*, string>, pair_hash> use, def, live_in, live_out;
    vector<int> successors;
    int index;
};

vector<LivenessInfo> currentLiveness;


vector<string> operators = {
    "==", "!=", "<=", ">=", "&&", "||", "+=", "-=", "*=", "/=", "%=",
    "<<", ">>", "<", ">", "+", "-", "*", "/", "%", "=", "&", "|", "^", "!", "~"
};

// --- Helper Functions ---
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

bool isConstantLiteral(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

void handleRegisterSpill(scoped_symtab* currentScope, const string& newVar) {
    cout << "Handling register spill for " << newVar << endl;

    for (auto it = var_to_reg.begin(); it != var_to_reg.end(); ++it) {
        auto [vscope, vname] = it->first;
        string reg = it->second;

        bool isLiveInFuture = false;

        // 1. Check future liveness
        for (int i = currentInstructionIndex + 1; i < currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                isLiveInFuture = true;
                break;
            }
        }

        // 2. Check use in current instruction
        bool isUsedNow = currentLiveness[currentInstructionIndex].use.count({vscope, vname});

        if (!isLiveInFuture && !isUsedNow) {
            cout<<"Spilling " << vname << " from " << reg << endl;
            mipsCode.push_back("    # Spilling " + vname + " from " + reg);
            availableRegs.push_back(reg);
            reg_to_var.erase(reg);
            var_to_reg.erase({vscope, vname});
            return;
        }
    }

    cerr << "Register spill failed: all registers are live or in use\n";
    exit(1);
}




string getRegister(scoped_symtab* scope,const string& var) {
    cout<<"Getting register for " << var << endl;
    if(var_to_reg.count({scope,var})) {
        return var_to_reg[{scope,var}];
    }
    // if (regMap.count(var)) return regMap[var];
    if (availableRegs.empty()) {
        handleRegisterSpill(scope,var);
    }
    string reg = availableRegs.back();
    availableRegs.pop_back();
    var_to_reg[{scope,var}] = reg;
    return reg;
}

pair<size_t, string> find_operator(const string& line) {
    string detectedOp;
    size_t opPos = string::npos;
    for (const string& op : operators) {
        size_t pos = line.find(op);
        if (pos != string::npos && (opPos == string::npos || pos < opPos)) {
            opPos = pos;
            detectedOp = op;
        }
    }
    return {opPos, detectedOp};
}

void generate_func_begin_MIPS(const string &func, int stackSize) {
    mipsCode.push_back(func + ":");
    mipsCode.push_back("    addi $sp, $sp, -" + to_string(stackSize));
    mipsCode.push_back("    sw   $ra, " + to_string(stackSize - 4) + "($sp)");
    mipsCode.push_back("    sw   $fp, " + to_string(stackSize - 8) + "($sp)");
    mipsCode.push_back("    move $fp, $sp");
}

void generate_func_end_MIPS(const string &func, int stackSize) {
    mipsCode.push_back("    move $sp, $fp");
    mipsCode.push_back("    lw   $fp, " + to_string(stackSize - 8) + "($sp)");
    mipsCode.push_back("    lw   $ra, " + to_string(stackSize - 4) + "($sp)");
    mipsCode.push_back("    addi $sp, $sp, " + to_string(stackSize));
    mipsCode.push_back("    jr   $ra");
    regMap.clear();
    availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4"};
    loadedConstants.clear();
}

void generate_return_MIPS(string val) {

    mipsCode.push_back("    li $v0, " + val);
}

// --- Operation/Assignment Handlers ---
void load_if_constant(scoped_symtab* scope, const string& var, const string& reg) {
    if (loadedConstants[var]) return;
    if(isConstantLiteral(var)) {
        if(reg_of_const.count(var)) {
            mipsCode.push_back("    move " + reg + ", " + reg_of_const[var]);
            cout << "Loaded constant literal " << var << " into " << reg << endl;
            return;
        }
        mipsCode.push_back("    li " + reg + ", " + var);
        loadedConstants[var] = true;
        reg_of_const[var]=reg;
        cout << "Loaded constant literal " << var << " into " << reg << endl;
        return;
    }
    
    symbol_info* sym = scope->symbol_map[var];
    if (sym && sym->ptr && sym->type == "int") {
        int* val = static_cast<int*>(sym->ptr);
        mipsCode.push_back("    li " + reg + ", " + to_string(*val));
        loadedConstants[var] = true;
        cout << "Loaded constant " << var << " into " << reg << endl;
    }
    
}

void handle_operation(string lhs, string rhs, size_t operator_pos, const string& opp, scoped_symtab* scope) {
    cout<<"Handling operation: " << lhs << " := " << rhs << endl;
    string op1 = trim(rhs.substr(0, operator_pos));
    string op2 = trim(rhs.substr(operator_pos + opp.size()));
    string r1 = getRegister(scope,op1);
    string r2 = getRegister(scope,op2);
    string rd = getRegister(scope,lhs);
    cout<<"Operation: " << op1 << " " << opp << " " << op2 << endl;
    cout<<"Registers: " << r1 << ", " << r2 << ", " << rd << endl;
    load_if_constant(scope, op1, r1);
    load_if_constant(scope, op2, r2);

    if (opp == "+") mipsCode.push_back("    add " + rd + ", " + r1 + ", " + r2);
    else if (opp == "-") mipsCode.push_back("    sub " + rd + ", " + r1 + ", " + r2);
    else if (opp == "*") mipsCode.push_back("    mul " + rd + ", " + r1 + ", " + r2);
    else if (opp == "/") {
        mipsCode.push_back("    div " + r1 + ", " + r2);
        mipsCode.push_back("    mflo " + rd);
    }
    else if(opp=="=="){
        mipsCode.push_back("    seq " + rd + ", " + r1 + ", " + r2);
    }
    else if (opp == "!=") mipsCode.push_back("    sne " + rd + ", " + r1 + ", " + r2);
    else if (opp == "<")  mipsCode.push_back("    slt " + rd + ", " + r1 + ", " + r2);
    else if (opp == "<=") {
        mipsCode.push_back("    slt " + rd + ", " + r2 + ", " + r1);
        mipsCode.push_back("    xori " + rd + ", " + rd + ", 1");
    }
    else if (opp == ">")  mipsCode.push_back("    slt " + rd + ", " + r2 + ", " + r1);
    else if (opp == ">=") {
        mipsCode.push_back("    slt " + rd + ", " + r1 + ", " + r2);
        mipsCode.push_back("    xori " + rd + ", " + rd + ", 1");
    }

}

void handle_assignment(string lhs, string rhs, scoped_symtab* scope) {
    cout<<"Handling assignment: " << lhs << " := " << rhs << endl;
    string dst = getRegister(scope,lhs);
    if (isConstantLiteral(rhs)) {
        if(reg_of_const.count(rhs)) {
            mipsCode.push_back("    move " + dst + ", " + reg_of_const[rhs]);
            loadedConstants[lhs] = true;
            cout << "Loaded constant literal " << rhs << " into " << dst << endl;
            return;
        }
        mipsCode.push_back("    li " + dst + ", " + rhs);
        loadedConstants[lhs] = true;
        reg_of_const[rhs]=dst;
    } else {
        
        string src = getRegister(scope,rhs);
        mipsCode.push_back("    move " + dst + ", " + src);
    }
}
int get_symbol_size(symbol_info* sym) {
    if (sym->is_array) {
        return sym->symbol_size * sym->array_length;
    }
    if (!sym->struct_attr_values.empty()) {
        int total = 0;
        for (auto* attr : sym->struct_attr_values) {
            total += get_symbol_size(attr);
        }
        return total;
    }
    if (sym->pointer_depth > 0) {
        return 4; // assuming 4 bytes per pointer
    }
    return sym->symbol_size;
}

int get_size_from_type(string type) {
    if (type == "int") return 4;
    else if (type == "float") return 4;
    else if(type == "char")return 1;
    else if(type == "bool")return 1;
}

int calculate_function_stack_size(scoped_symtab* scope) {
    int size = 0;

    for (const auto& [name, sym] : scope->symbol_map) {
        if (!sym->is_param_list && !sym->is_return) {
            size += sym->type == "string" ? get_symbol_size(sym) : get_size_from_type(sym->type);
        }
    }
    size += 8; // Space for old FP and RA
    return size;
}

void pass1(vector<pair<string, scoped_symtab*>>& codeList){
    for(auto &code : codeList){
        string t = trim(code.first);
        if(t.empty()){
            cout << "empty codelist error" << endl;
        }
        else{
            if(t.rfind("FUNC_BEGIN", 0) == 0){
                scoped_symtab* scope = code.second;
                int stack_size = calculate_function_stack_size(scope);
                istringstream iss(t);
                string dummy, funcName;
                iss >> dummy >> funcName;
                int frameBytes = calculate_function_stack_size(scope);
                funcStackSize[funcName] = frameBytes;
            }
        }
    }
}


void pass2(vector<pair<string, scoped_symtab*>>& codeList){
    for(int idx = 0; idx < codeList.size(); ++idx){
        auto& code = codeList[idx];
        currentInstructionIndex = idx;
        string t = trim(code.first);
        cout << t << "\n";
        if (t.empty()){
            cout << "empty codelist error" << endl;
        }
        else{
            if(t.rfind("FUNC_BEGIN", 0) == 0){
                istringstream iss(t);
                string dummy, funcName;
                iss >> dummy >> funcName;
                generate_func_begin_MIPS(funcName, funcStackSize[funcName]);
            }
            else if (t.rfind("FUNC_END",0) == 0) {
                istringstream iss(t);
                string dummy, funcName;
                iss >> dummy >> funcName;
                generate_func_end_MIPS(funcName, funcStackSize[funcName]);
                continue;
            }
            else if(t.rfind("RETURN",0) == 0){
                istringstream iss(t);
                string keyword, val;
                iss >> keyword >> val;
                generate_return_MIPS(val);
            }
            else if (t.rfind("if(", 0) == 0 && t.find("goto") != string::npos) {
                size_t start = t.find('(') + 1;
                size_t end = t.find(')');
                string condition = t.substr(start, end - start);
                string label = trim(t.substr(t.find("goto") + 4));
                cout<<"Condition: " << condition << ", Label: " << label << endl;
                string reg = getRegister(code.second, condition);
                load_if_constant(code.second, condition, reg);
                mipsCode.push_back("    bnez " + reg + ", " + label);
            }
            else if (t.rfind("goto", 0) == 0) {
                string label = trim(t.substr(4));
                mipsCode.push_back("    j " + label);
            }
            else if (t.back() == ':' && isalpha(t[0])) {
                // Handle labels like LABEL0:
                mipsCode.push_back(t);
            }
            if (t.find(":=") != string::npos) {
                size_t lhsEnd = t.find(":=");
                string lhs = trim(t.substr(0, lhsEnd));
                string rhs = trim(t.substr(lhsEnd + 2));
        
                auto [opPos, opp] = find_operator(rhs);
                if (opPos != string::npos) handle_operation(lhs, rhs, opPos, opp, code.second);
                else handle_assignment(lhs, rhs, code.second);
            }
        }
    }
}

bool isAddress(const std::string& token) {
    return token.size() > 2 && token[0] == '0' && token[1] == 'x';
}

void compute_use_def(LivenessInfo& inst) {
    const string& line = inst.code;
    if (line.find(":=") != string::npos) {
        size_t eq = line.find(":=");
        string lhs = trim(line.substr(0, eq));
        string rhs = trim(line.substr(eq + 2));
        inst.def.insert({inst.scope, lhs});
        istringstream iss(rhs);
        string token;
        while (iss >> token)
            if (isalpha(token[0]) && token != lhs)
                inst.use.insert({inst.scope, token});
    } else if (line.find("if(") == 0) {
        size_t start = line.find('(') + 1;
        size_t end = line.find(')');
        string cond = line.substr(start, end - start);
        istringstream iss(cond);
        string token;
        while (iss >> token)
            if (isalpha(token[0]))
                inst.use.insert({inst.scope, token});
    } else if (line.find("RETURN") == 0) {
        string word, val;
        istringstream iss(line);
        iss >> word >> val;
        inst.use.insert({inst.scope, val});
    }
}

void compute_successors(vector<LivenessInfo>& program) {
    for (int i = 0; i < program.size(); ++i) {
        string line = trim(program[i].code);
        if (line.find("goto") == 0) {
            string label = trim(line.substr(4));
            for (int j = 0; j < program.size(); ++j)
                if (program[j].code == label + ":")
                    program[i].successors = {j};
        } else if (line.find("if(") == 0) {
            string label = trim(line.substr(line.find("goto") + 4));
            for (int j = 0; j < program.size(); ++j)
                if (program[j].code == label + ":") {
                    program[i].successors = {i + 1, j};
                    break;
                }
        } else if (line.back() != ':') {
            program[i].successors = {i + 1};
        }
    }
}

void run_liveness(vector<LivenessInfo>& program) {
    compute_successors(program);
    for (auto& inst : program)
        compute_use_def(inst);

    bool changed;
    do {
        changed = false;
        for (int i = program.size() - 1; i >= 0; --i) {
            auto old_in = program[i].live_in;
            auto old_out = program[i].live_out;

            program[i].live_out.clear();
            for (int s : program[i].successors)
                program[i].live_out.insert(program[s].live_in.begin(), program[s].live_in.end());

            program[i].live_in = program[i].use;
            for (auto& v : program[i].live_out)
                if (!program[i].def.count(v))
                    program[i].live_in.insert(v);

            if (old_in != program[i].live_in || old_out != program[i].live_out)
                changed = true;
        }
    } while (changed);
}



void codegen_main() {

    std::ifstream infile("output/output1.txt");  // Replace with your file path
    if (!infile.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return;
    }

    std::vector<std::pair<std::string,scoped_symtab*>> codeList;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string addressStr;
        if (!(iss >> addressStr) || !isAddress(addressStr)) {
            continue; // skip invalid address
        }

        // Convert hex string to pointer
        scoped_symtab* address = reinterpret_cast<scoped_symtab*>(std::stoull(addressStr, nullptr, 16));

        std::string restOfLine;
        std::getline(iss, restOfLine);
        if (!restOfLine.empty() && restOfLine[0] == ' ')
            restOfLine = restOfLine.substr(1); // remove leading space

        codeList.emplace_back(restOfLine, address);
    }

    pass1(codeList);

    currentLiveness.clear();
    for (int i = 0; i < codeList.size(); ++i) {
        currentLiveness.push_back({
            codeList[i].second, // scope
            codeList[i].first,  // code
            {}, {}, {}, {}, {}, i
        });
    }
    run_liveness(currentLiveness);

    pass2(codeList);

    cout << "# MIPS Assembly Code:\n";
    for (const string& line : mipsCode) {
        cout << line << endl;
    }

    return;
}