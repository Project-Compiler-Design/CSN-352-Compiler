#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

// Simulated symbol table structure
struct symbol_info {
    string name, type, str_val, return_type, code;
    void* ptr = nullptr;
    int symbol_size = 0;
    bool is_array = false, is_param_list = false, is_return = false;
    int array_length = 0, parameter_no = 0, pointer_depth = 0;
    vector<symbol_info*> int_array, struct_attr_values;
    vector<string> param_types, param_list;
};

// Symbol table type
struct symbol_table {
    unordered_map<string, symbol_info*> symbol_map;
};

map<pair<symbol_table*,string>,string> var_to_reg;
unordered_map<string,pair<symbol_table*,string>> reg_to_var;
map<string, int> funcStackSize;

// --- Global Variables ---
unordered_map<string, string> regMap;
vector<string> availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
vector<string> mipsCode;
unordered_map<string, bool> loadedConstants;
unordered_map<string,string> reg_of_const;

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

string getRegister(symbol_table* scope,const string& var) {
    if(var_to_reg.count({scope,var})) {
        return var_to_reg[{scope,var}];
    }
    // if (regMap.count(var)) return regMap[var];
    if (availableRegs.empty()) {
        cerr << "Register spill not handled\n";
        exit(1);
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
void load_if_constant(symbol_table* scope, const string& var, const string& reg) {
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

void handle_operation(string lhs, string rhs, size_t operator_pos, const string& opp, symbol_table* scope) {
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
    // Extend here with ==, !=, <, etc.
}

void handle_assignment(string lhs, string rhs, symbol_table* scope) {
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

int calculate_function_stack_size(symbol_table* scope) {
    int size = 0;

    for (const auto& [name, sym] : scope->symbol_map) {
        if (!sym->is_param_list && !sym->is_return) {
            size += sym->type == "string" ? get_symbol_size(sym) : get_size_from_type(sym->type);
        }
    }
    size += 8; // Space for old FP and RA
    return size;
}

void pass1(vector<pair<string, symbol_table*>>& codeList){
    for(auto &code : codeList){
        string t = trim(code.first);
        if(t.empty()){
            cout << "empty codelist error" << endl;
        }
        else{
            if(t.rfind("FUNC_BEGIN", 0) == 0){
                symbol_table* scope = code.second;
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


void pass2(vector<pair<string, symbol_table*>>& codeList){
    for(auto &code : codeList){
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



// --- Main MIPS Generator per line ---
// void generateMIPS(const string& line, symbol_table* scope) {
//     cout<<"Processing line: " << line << endl;
//     string trimmed = trim(line);
//     if (trimmed.find("FUNC_BEGIN") == 0) return generate_func_begin_MIPS(trimmed);
//     if (trimmed.find("FUNC_END") == 0) return generate_func_end_MIPS(trimmed);
//     if (trimmed.find("RETURN") == 0) return generate_return_MIPS(trimmed);

//     if (trimmed.find(":=") != string::npos) {
//         size_t lhsEnd = trimmed.find(":=");
//         string lhs = trim(trimmed.substr(0, lhsEnd));
//         string rhs = trim(trimmed.substr(lhsEnd + 2));

//         auto [opPos, opp] = find_operator(rhs);
//         if (opPos != string::npos) handle_operation(lhs, rhs, opPos, opp, scope);
//         else handle_assignment(lhs, rhs, scope);
//     }
// }

// --- Main ---
int main() {
    // Simulated 3AC input with dummy symbol_table*
    vector<pair<string, symbol_table*>> codeList;

    // Example symbol table with values
    auto* globalScope = new symbol_table();
    int a_val = 2, b_val = 3;
    globalScope->symbol_map["d"] = new symbol_info{"d", "int"};
    globalScope->symbol_map["e"] = new symbol_info{"e", "int"};
    globalScope->symbol_map["d"]->ptr = &a_val;
    globalScope->symbol_map["e"]->ptr = &b_val;
    globalScope->symbol_map["a"] = new symbol_info{"a", "int"};
    globalScope->symbol_map["b"] = new symbol_info{"b", "int"};


    // Example 3AC with symbol table per line
    // codeList.push_back({"FUNC_BEGIN main", globalScope});
    // codeList.push_back({"a := 3", globalScope});
    // codeList.push_back({"b := 3", globalScope});
    // codeList.push_back({"c := a", globalScope});
    // codeList.push_back({"d := b + a", globalScope});
    // codeList.push_back({"e := d + c", globalScope});
    // codeList.push_back({"RETURN 0", globalScope});
    // codeList.push_back({"FUNC_END main", globalScope});
    codeList.push_back({"FUNC_BEGIN add", globalScope});
    codeList.push_back({"d := 2", globalScope});
    codeList.push_back({"e := 3", globalScope});
    codeList.push_back({"RETURN d + e", globalScope});
    codeList.push_back({"FUNC_END add", globalScope});

    // for (const auto& [code, scope] : codeList) {
    //     generateMIPS(code, scope);
    // }
    pass1(codeList);
    pass2(codeList);

    cout << "# MIPS Assembly Code:\n";
    for (const string& line : mipsCode) {
        cout << line << endl;
    }

    return 0;
}