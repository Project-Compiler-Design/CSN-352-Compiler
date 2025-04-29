#include<bits/stdc++.h>
#include<fstream>
#include <utility.h>
using namespace std;
int currentInstructionIndex = -1;
static int paramCounter = 0;
static int paramFloatCounter = 0;
int paramReceiveCounter = 0;
int param_receive_offset=0;
int paramFloatReceiveCounter = 0;
int string_counter = 0;
map<pair<scoped_symtab*,string>,string> var_to_reg;
map<string,pair<scoped_symtab*,string>> reg_to_var;
std::vector<pair<scoped_symtab*, string>> static_var;
map<scoped_symtab*,int> scope_id;
map<string, int> funcStackSize;
map<string,int> size_of_extra_parameters;
stack<int> last_offset;
vector<string> functionparams;
// --- Global Variables ---
map<string, string> regMap;
static vector<string> argRegisters = {"$a0", "$a1", "$a2", "$a3"};
vector<string> availableRegs = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5","$t6", "$t7", "$t8", "$t9"};
vector<string> availableFloatRegs = {"$f0", "$f1", "$f2", "$f3", "$f4", "$f5", "$f6", "$f7","$f8", "$f9", "$f10", "$f11", "$f12", "$f13", "$f14", "$f15", "$f16", "$f17", "$f18", "$f19", "$f20", "$f21", "$f22", "$f23", "$f24", "$f25", "$f26", "$f27", "$f28", "$f29", "$f30", "$f31"};
map<pair<scoped_symtab*, string>, string> floatVarToReg;
vector<string> availableDoubleRegs={"$f0","$f2","$f4","$f6","$f8","$f10","$f12","$f14","$f16","$f18","$f20","$f22","$f24","$f26","$f28","$f30"};
map<pair<scoped_symtab*, string>, string> doubleVarToReg;
vector<string> mipsCode;
vector<string> data_section;
vector<string> paramtype;
map<string,string> string_to_label;
map<string, bool> loadedConstants;
map<string,string> reg_of_const;
vector<string> reg_for_scanf;
int get_size_from_type(string type);
void handle_function_call(const string& line);

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

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

bool isIntLiteral(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

bool isCharLiteral(const std::string& s) {
    return s.length() >= 3 && s.front() == '\'' && s.back() == '\'' && s.length() == 3;
}
bool isStringLiteral(const std::string& s) {
    return s.length() >= 2 && s.front() == '"' && s.back() == '"';
}

bool isFloatLiteral(const string& s) {
    size_t dotPos = s.find('.');
    if (dotPos == string::npos) return false;

    string intPart = s.substr(0, dotPos);
    string fracPart = s.substr(dotPos + 1);

    return !intPart.empty() && !fracPart.empty() &&
           all_of(intPart.begin(), intPart.end(), ::isdigit) &&
           all_of(fracPart.begin(), fracPart.end(), ::isdigit);
}


scoped_symtab* getScope(scoped_symtab* scope, string& var) {
    if (var=="PARAM"||var=="CALL"||var=="RETURN") return scope;
    while(scope != nullptr) {
        if (scope->symbol_map.count(var)) {
            return scope;
        }
        scope = scope->parent;
    }
    return nullptr;
}


// Pushes a variable from register to stack, handles different data types

void push_into_stack(pair<scoped_symtab*, string> varPair){
    mipsCode.push_back("    #Pushing " + varPair.second + " to stack");
    scoped_symtab* scope = varPair.first;
    string var = varPair.second;
    symbol_info* sym = scope->symbol_map[var];
    string type=sym->type;
    string reg;
    if(type.find("struct") != string::npos || type.find("union") != string::npos){
        reg=var_to_reg[{scope, var}];
        availableRegs.push_back(reg);
        return;
            
    }
    if(type.substr(0,3)=="int") reg = var_to_reg[{scope, var}];
    else if(type.substr(0,5)=="float") reg = floatVarToReg[{scope, var}];
    else if(type.substr(0,6)=="double"){
        reg = doubleVarToReg[{scope, var}];
    }
    if(scope->symbol_map[var]->offset == -1){
        sym->offset = last_offset.top();
        last_offset.top()+=get_size_from_type(sym->type);
        if(type.substr(0,3)=="int")
            mipsCode.push_back("    sw " + reg + ", " + to_string(sym->offset) + "($sp)");
        else if(type.substr(0,5)=="float")
            mipsCode.push_back("    s.s " + reg + ", " + to_string(sym->offset) + "($sp)");
        else if(type.substr(0,6)=="double")
            mipsCode.push_back("    s.d " + reg + ", " + to_string(sym->offset) + "($sp)");
        else{
            return;
        }
    }else{
        if(type.substr(0,3)=="int")
            mipsCode.push_back("    sw " + reg + ", " + to_string(sym->offset) + "($sp)");
        else if(type.substr(0,5)=="float")
            mipsCode.push_back("    s.s " + reg + ", " + to_string(sym->offset) + "($sp)");
        else if(type.substr(0,6)=="double")
            mipsCode.push_back("    s.d " + reg + ", " + to_string(sym->offset) + "($sp)");
        else{
            return;
        }
    }
    if(type.substr(0,3)=="int")
    {
        availableRegs.push_back(reg);
        var_to_reg.erase({scope, var});
    }
    else if(type.substr(0,5)=="float")
    {
        
        floatVarToReg.erase({scope, var});
    }
    else if(type.substr(0,6)=="double")
    {
        
        doubleVarToReg.erase({scope, var});
    }
    else{
        return;
    }
   
    reg_to_var.erase(reg);
}

// Handles register spill for double precision values by finding unused registers

void handleDoubleRegisterSpill(scoped_symtab* currentScope, const string& newVar) {
    
    for (auto it = doubleVarToReg.begin(); it != doubleVarToReg.end(); ++it) {
        auto [vscope, vname] = it->first;
        string reg = it->second;

        bool usedNow = currentLiveness[currentInstructionIndex]
                           .use.count({vscope, vname});
        bool liveFuture = false;
        for (int i = currentInstructionIndex + 1;
                 i < (int)currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                liveFuture = true;
                break;
            }
        }

        if (!usedNow && !liveFuture) {
            mipsCode.push_back("    # Spilling " + vname + " from " + reg);
            availableDoubleRegs.push_back(reg);
            availableFloatRegs.push_back(reg);
            int num = stoi(reg.substr(2));
            string odd = "$f" + to_string(num + 1);
            availableFloatRegs.push_back(odd);
            doubleVarToReg.erase(it);
            return;
        }
    }

    for (auto fit = floatVarToReg.begin(); fit != floatVarToReg.end(); ++fit) {
        auto [vscope, vname] = fit->first;
        string reg = fit->second;

        bool usedNow = currentLiveness[currentInstructionIndex]
                           .use.count({vscope, vname});
        bool liveFuture = false;
        for (int i = currentInstructionIndex + 1;
                 i < (int)currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                liveFuture = true;
                break;
            }
        }
        if (usedNow || liveFuture) 
            continue; 

        int num = stoi(reg.substr(2));
        bool regIsEven = (num % 2 == 0);
        string buddy = "$f" + to_string(regIsEven ? num + 1 : num - 1);
        auto budIt = find_if(
            floatVarToReg.begin(), floatVarToReg.end(),
            [&](auto const& kv){ return kv.second == buddy; }
        );
        if (budIt == floatVarToReg.end())
            continue;  
        auto [bScope, bName] = budIt->first;
        bool budUsedNow = currentLiveness[currentInstructionIndex]
                              .use.count({bScope, bName});
        bool budLiveFuture = false;
        for (int i = currentInstructionIndex + 1;
                 i < (int)currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({bScope, bName})) {
                budLiveFuture = true;
                break;
            }
        }
        if (budUsedNow || budLiveFuture)
            continue; 

        mipsCode.push_back("    # Spilling " + vname + " from " + reg);
        availableFloatRegs.push_back(reg);
        floatVarToReg.erase(fit);

        mipsCode.push_back("    # Spilling " + bName + " from " + buddy);
        availableFloatRegs.push_back(buddy);
        floatVarToReg.erase(budIt);

        string evenReg = regIsEven ? reg : buddy;
        auto dit = find(availableDoubleRegs.begin(),
                        availableDoubleRegs.end(), evenReg);
        if (dit != availableDoubleRegs.end())
            availableDoubleRegs.erase(dit);

        doubleVarToReg[{currentScope, newVar}] = evenReg;
        return;
    }

    auto dit = doubleVarToReg.begin();
    auto varPair = dit->first;
    string regToSpill = dit->second;
    mipsCode.push_back("    # Spilling " + varPair.second
                       + " from " + regToSpill);
    availableDoubleRegs.push_back(regToSpill);
    int n = stoi(regToSpill.substr(2));
    string odd2 = "$f" + to_string(n + 1);
    availableFloatRegs.push_back(regToSpill);
    availableFloatRegs.push_back(odd2);
    doubleVarToReg.erase(dit);
    push_into_stack(varPair);
}


// Manages register spilling for floating point values when no free registers are available
void handleFloatRegisterSpill(scoped_symtab* currentScope, const string& newVar) {

    for (auto it = floatVarToReg.begin(); it != floatVarToReg.end(); ++it) {
        auto [vscope, vname] = it->first;
        string reg = it->second;

        bool usedNow = currentLiveness[currentInstructionIndex]
                           .use.count({vscope, vname});
        bool liveFuture = false;
        for (int i = currentInstructionIndex + 1;
                 i < (int)currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                liveFuture = true;
                break;
            }
        }

        if (!usedNow && !liveFuture) {
            mipsCode.push_back("    # Spilling " + vname + " from " + reg);
            availableFloatRegs.push_back(reg);
            int reg_num = stoi(reg.substr(2));
            if(reg_num%2==1)
            {
                string pair=reg.substr(0,2)+to_string(reg_num-1);
                if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end())
                {
                    availableDoubleRegs.push_back(pair);
                }
                
            }
            else{
                string pair=reg.substr(0,2)+to_string(reg_num+1);
                if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end())
                {
                    availableDoubleRegs.push_back(reg);
                }
            }
            floatVarToReg.erase(it);
            return;
        }
    }

    for (auto it = doubleVarToReg.begin(); it != doubleVarToReg.end(); ++it) {
        auto [vscope, vname] = it->first;
        string reg = it->second;

        bool usedNow = currentLiveness[currentInstructionIndex]
                           .use.count({vscope, vname});
        bool liveFuture = false;
        for (int i = currentInstructionIndex + 1;
                 i < (int)currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                liveFuture = true;
                break;
            }
        }

        if (!usedNow && !liveFuture) {
            mipsCode.push_back("    # Spilling double " + vname + " from " + reg);
            string pair=reg.substr(0,2)+to_string(stoi(reg.substr(2))+1);
            availableDoubleRegs.push_back(reg);
            availableFloatRegs.push_back(reg);
            availableFloatRegs.push_back(pair);
            doubleVarToReg.erase(it);
            return;
        }
    }

    auto it      = floatVarToReg.begin();
    auto varPair = it->first;           
    string reg   = it->second;
    mipsCode.push_back("    # Spilling " + varPair.second + " from " + reg);
    availableFloatRegs.push_back(reg);
    int reg_num = stoi(reg.substr(2));
    if(reg_num%2==1)
    {
        string pair=reg.substr(0,2)+to_string(reg_num-1);
        if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end())
        {
            availableDoubleRegs.push_back(pair);
        }
        
    }
    else{
        string pair=reg.substr(0,2)+to_string(reg_num+1);
        if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end())
        {
            availableDoubleRegs.push_back(reg);
        }
    }
    floatVarToReg.erase(it);
    
    push_into_stack(varPair);
}



// Manages register spilling for integer values by selecting least-used registers

void handleRegisterSpill(scoped_symtab* currentScope, string& newVar) {
    int maxdist=0;
    string regi="$t0";
    for (auto it = var_to_reg.begin(); it != var_to_reg.end(); ++it) {
        auto [vscope, vname] = it->first;
        string reg = it->second;
        bool isUsedNow = currentLiveness[currentInstructionIndex].use.count({vscope, vname});
        bool isLiveInFuture = false;

        for (int i = currentInstructionIndex + 1; i < currentLiveness.size(); ++i) {
            if (currentLiveness[i].live_in.count({vscope, vname})) {
                if (currentLiveness[i].index - currentInstructionIndex > maxdist && !isUsedNow) {
                    maxdist = currentLiveness[i].index - currentInstructionIndex;
                    regi = reg;
                }
                isLiveInFuture = true;
                break;
            }
        }
        if (!isLiveInFuture && !isUsedNow) {
            mipsCode.push_back("    # Spilling " + vname + " from " + reg);
            availableRegs.push_back(reg);
            reg_to_var.erase(reg);
            var_to_reg.erase({vscope, vname});
            return;
        }
    }
    pair<scoped_symtab*, string> varPair = reg_to_var[regi];
    if(varPair.second==""){
        availableRegs.push_back(regi);
        reg_to_var.erase(regi);

        return;
    }
    push_into_stack(varPair);
}

// Returns a float register for a variable, handling register allocation for both float and double types

string getFloatRegister(scoped_symtab* scope, string& var,string type="float") {
    scope = getScope(scope, var);
    if (availableFloatRegs.empty()) {
        exit(1);
    }
    if(type=="float")
    {
        if (floatVarToReg.count({scope, var})) return floatVarToReg[{scope, var}];
        
        string freg = availableFloatRegs.back();
        availableFloatRegs.pop_back();
        string correspondingdreg=freg;
        if(stoi(freg.substr(2))%2==1)
        {
            correspondingdreg="$f"+to_string(stoi(freg.substr(2))-1);
        }
        auto it = find(availableDoubleRegs.begin(), availableDoubleRegs.end(), correspondingdreg);
        if (it != availableDoubleRegs.end())  availableDoubleRegs.erase(it);
        floatVarToReg[{scope, var}] = freg;
        return freg;
    }
    else if(type=="double")
    {
        if (doubleVarToReg.count({scope, var})) return doubleVarToReg[{scope, var}];
    
        string freg = availableDoubleRegs.back();
        availableDoubleRegs.pop_back();
        string s="$f"+to_string(stoi(freg.substr(2))+1);
        auto it = find(availableFloatRegs.begin(), availableFloatRegs.end(), freg);
        if (it != availableFloatRegs.end())  availableFloatRegs.erase(it);
        auto it2=find(availableFloatRegs.begin(), availableFloatRegs.end(), s);
        if(it2 != availableFloatRegs.end()) availableFloatRegs.erase(it2);
        doubleVarToReg[{scope, var}] = freg;
        return freg;
    }
    
} 

// Returns a register for a variable, handling cases like constants and variables already in registers

string getRegister(scoped_symtab* scope, string& var) {
    if(isIntLiteral(var)){
        if(availableRegs.empty()) handleRegisterSpill(scope,var);
        string reg = availableRegs.back();
        availableRegs.pop_back();
        return reg;
    }
    scope = getScope(scope, var);
    if(var_to_reg.count({scope,var})) {
        return var_to_reg[{scope,var}];
    }
    
    if (availableRegs.empty()) {
        handleRegisterSpill(scope,var);
    }
    if(scope->symbol_map[var]->offset != -1){
        string reg = availableRegs.back();
        availableRegs.pop_back();
        mipsCode.push_back("    lw " + reg + ", " + to_string(scope->symbol_map[var]->offset) + "($sp)");
        var_to_reg[{scope,var}] = reg;
        reg_to_var[reg] = {scope,var};
        return reg;
    }
    string reg = availableRegs.back();
    availableRegs.pop_back();
    var_to_reg[{scope,var}] = reg;
    reg_to_var[reg] = {scope,var};
    return reg;
}

// Returns a register for a variable, handling cases like constants and variables already in registers

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

// Generates MIPS code for function entry, setting up stack frame and saving registers


void generate_func_begin_MIPS(const string &func, int stackSize) {
    if (func != "main")
        stackSize += 40;
    mipsCode.push_back(func + ":");
    mipsCode.push_back("    move $fp, $sp");
    mipsCode.push_back("    addi $sp, $sp, -" + to_string(stackSize) );
    mipsCode.push_back("    sw   $ra, " + to_string(stackSize - 4) + "($sp)");
    mipsCode.push_back("    sw   $fp, " + to_string(stackSize - 8) + "($sp)");
    if (func != "main")
    {
        int spillCount = 10;
        int slot = 0;
        for (int i = 0; i < spillCount; i++){
            string reg = "$t" + to_string(i);
            mipsCode.push_back("    sw   " + reg + ", " + to_string(stackSize - 12 - 4*slot) + "($sp)");
            slot++;
        }
    }
    last_offset.push(0);
}

// Cleans up at function end, restoring registers and stack pointer


void generate_func_end_MIPS( string &func, int stackSize) {
    if(!last_offset.empty())
    last_offset.pop();
}

// Generates MIPS code for return statements, restoring registers and frame pointer


void generate_return_MIPS(string& func, scoped_symtab* scope,string val) {
    if(isIntLiteral(val) || isFloatLiteral(val)) 
    {
      mipsCode.push_back("    li $v0, " + val);
    }
   else{
        string reg=getRegister(scope,val);
        mipsCode.push_back("    move $v0, " + reg);
    }
    int stackSize = funcStackSize[func];
    if(func!="main")stackSize += 40;
    mipsCode.push_back("    lw   $fp, " + to_string(stackSize - 8) + "($sp)");
    mipsCode.push_back("    lw   $ra, " + to_string(stackSize - 4) + "($sp)");
    if(func != "main"){
        int slot = 0, spillCount = 10;
        for (int i = 0; i < spillCount; i++){
            string reg = "$t" + to_string(i);
            mipsCode.push_back("    lw   " + reg + ", " + to_string(stackSize - 12 - 4*slot) + "($sp)");
            slot++;
        }
        mipsCode.push_back("    addi $sp, $sp, " + to_string(stackSize));
    }
    if(func!="main") mipsCode.push_back("    jr   $ra");
    
}

// Loads constants (integer or float) into registers

void load_if_constant(scoped_symtab* scope, string& var, const string& reg) {
    if (isIntLiteral(var)) {
        mipsCode.push_back("    li " + reg + ", " + var);
        loadedConstants[var] = true;
        reg_of_const[var] = reg;
        return;
    }

    if (isFloatLiteral(var)) {
        string floatLabel = "float_const_" + var;  // like float_const_3.14
        static set<string> emittedFloats;
        if (!emittedFloats.count(var)) {
            emittedFloats.insert(var);
            mipsCode.insert(mipsCode.begin(), floatLabel + ": .float " + var);
        }
        if(availableRegs.empty()) handleRegisterSpill(scope,var);
        string reg1 = availableRegs.back();
        mipsCode.push_back("    la " + reg1 + ", " + floatLabel);
        mipsCode.push_back("    l.s " + reg + ", 0(" + reg1 + ")");
        loadedConstants[var] = true;
        reg_of_const[var] = reg;
        return;
    }

    symbol_info* sym = scope->symbol_map[var];
    if (sym && sym->ptr) {
        if (sym->type == "int") {
            int* val = static_cast<int*>(sym->ptr);
            mipsCode.push_back("    li " + reg + ", " + to_string(*val));
            loadedConstants[var] = true;
            reg_of_const[var] = reg;
        } else if (sym->type == "float") {
            float* val = static_cast<float*>(sym->ptr);
            string valStr = to_string(*val);
            string floatLabel = "float_sym_" + var;
            mipsCode.insert(mipsCode.begin(), floatLabel + ": .float " + valStr);

            mipsCode.push_back("    la " + reg + ", " + floatLabel);
            mipsCode.push_back("    l.s " + reg + ", 0(" + reg + ")");
            loadedConstants[var] = true;
            reg_of_const[var] = reg;
        }
    }
}

// Handles arithmetic and comparison operations between two operands


void handle_operation(string lhs, string rhs, size_t operator_pos, const string& opp, scoped_symtab* scope) {
    bool isFloat;
    isFloat = (getScope(scope,lhs)->symbol_map[lhs]->type == "float");
    string op1 = trim(rhs.substr(0, operator_pos));
    string op2 = trim(rhs.substr(operator_pos + opp.size()));
    if (isFloat){
        string r1,r2,rd;
        string rx,ry;
        if(isFloatLiteral(op1)){
            if(availableFloatRegs.empty()) handleRegisterSpill(scope,op1);
            r1=availableFloatRegs.back();
            rx=r1;
            availableFloatRegs.pop_back();
            load_if_constant(scope, op1, r1);
        }
        else{
            int fl=0;
            
            for(auto x:static_var){
                if(x.first==scope && x.second==op1){
                    r1 = getRegister(scope,op1);
                    mipsCode.push_back("    la " + r1 + ", " + "static_" + op1);
                    string rr=getFloatRegister(scope,op1);
                    mipsCode.push_back("    l.s "+rr+", 0("+r1+")");
                    floatVarToReg[{scope,op1}] = rr;
                    reg_to_var[rr] = {scope,op1};
                    fl=1;
                    rx=rr;
                    break;
                    
                }
            }
            if(fl==0){
                string typ = getScope(scope,op1)->symbol_map[op1]->type;
                if(typ == "int"){
                    string r1 = getRegister(scope,op1);
                    string tempr = getFloatRegister(scope,op1);
                    mipsCode.push_back("    mtc1 " + r1 + ", " + tempr);
                    mipsCode.push_back("    cvt.s.w " + tempr+ ", " + tempr);
                    rx = tempr;
                }
                else{
                    string tempr = getFloatRegister(scope,op1);
                    rx = tempr;
                }
            }
            
            
        }
        if(isFloatLiteral(op2)){
            if(availableFloatRegs.empty()) handleRegisterSpill(scope,op1);
            r2=availableFloatRegs.back();
            ry=r2;
            availableFloatRegs.pop_back();
            load_if_constant(scope, op2, r2);
        }
        else{
            int fl=0;
            
            for(auto x:static_var){
                if(x.first==scope && x.second==op1){
                    r2 = getRegister(scope,op1);
                    mipsCode.push_back("    la " + r2 + ", " + "static_" + op2);
                    string rr=getFloatRegister(scope,op2);
                    mipsCode.push_back("    l.s "+rr+", 0("+r2+")");
                    floatVarToReg[{scope,op1}] = rr;
                    reg_to_var[rr] = {scope,op1};
                    fl=1;
                    ry=rr;
                    break;
                    
                }
            }
            if(fl==0){
                string typ = getScope(scope,op2)->symbol_map[op2]->type;
                if(typ == "int"){
                    string r1 = getRegister(scope,op2);
                    string tempr = getFloatRegister(scope,op2);
                    mipsCode.push_back("    mtc1 " + r1 + ", " + tempr);
                    mipsCode.push_back("    cvt.s.w " + tempr+ ", " + tempr);
                    ry = tempr;
                }
                else{
                    string tempr = getFloatRegister(scope,op2);
                    ry = tempr;
                }
            }
            
        }
        rd = getFloatRegister(scope,lhs);
        
        if (opp == "+") mipsCode.push_back("    add.s " + rd + ", " + rx + ", " + ry );
        else if (opp == "-") mipsCode.push_back("    sub.s " + rd + ", " +  rx + ", " + ry );
        else if (opp == "*") mipsCode.push_back("    mul.s " + rd + ", " +  rx + ", " + ry );
        else if (opp == "/") mipsCode.push_back("    div.s " + rd + ", " +  rx + ", " + ry );
        return;
    }
    string r1,r2,rd;
    
    if(isIntLiteral(op1)){
        if(availableRegs.empty()) handleRegisterSpill(scope,op1);
        r1=availableRegs.back();
        availableRegs.pop_back();
        load_if_constant(scope, op1, r1);
    }
    else{
        int fl=0;
        
        for(auto x:static_var){
            if(x.first==scope && x.second==op1){
                r1 = getRegister(scope,op1);
                mipsCode.push_back("    lw " + r1 + ", " + "static_" + op1);
                var_to_reg[{scope,op1}] = r1;
                reg_to_var[r1] = {scope,op1};
                fl=1;
                break;
                
            }
        }
        if(fl==0){
            r1 = getRegister(scope,op1);
        }
        
    }
    if(isIntLiteral(op2)){
        if(availableRegs.empty()) handleRegisterSpill(scope,op1);
        r2=availableRegs.back();
        availableRegs.pop_back();
        load_if_constant(scope, op2, r2);
    }
    else{
        int fl=0;
        
        for(auto x:static_var){
            if(x.first==scope && x.second==op1){
                r2 = getRegister(scope,op2);
                mipsCode.push_back("    lw " + r2 + ", " + "static_" + op2);
                var_to_reg[{scope,op2}] = r2;
                reg_to_var[r2] = {scope,op2};
                fl=1;
                break;
                
            }
        }
        if(fl==0){
            r2 = getRegister(scope,op2);
        }
    }
    rd = getRegister(scope,lhs);
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

// Processes assignment statements, handling different data types


void handle_assignment(string lhs, string rhs, scoped_symtab* scope) {

    symbol_info* lhsInfo = getScope(scope,lhs)->symbol_map[lhs];
    bool isFloat = (lhsInfo && lhsInfo->type == "float" && rhs.find("CALL") == string::npos && rhs.find("alloc") == string::npos);
    bool isDouble = (lhsInfo && lhsInfo->type == "double" && rhs.find("CALL") == string::npos && rhs.find("alloc") == string::npos);
    if (isFloat) {
        string dst = getFloatRegister(scope, lhs);
        if (isFloatLiteral(rhs)) {
            
            mipsCode.push_back("    li.s " + dst + ", " + rhs);
        } 
        else if (isIntLiteral(rhs)) {
            
            mipsCode.push_back("    li.s " + dst + ", " + rhs+".0");
        } 
        else {
            string src = getFloatRegister(scope, rhs);
            mipsCode.push_back("    mov.s " + dst + ", " + src);
        }
        return;
    }
    
    else if (isDouble) {
        string dst = getFloatRegister(scope, lhs,"double");  
        if (isFloatLiteral(rhs)) {
            mipsCode.push_back("    li.d " + dst + ", " + rhs);  
        }
        else if (isIntLiteral(rhs)) {
           
            mipsCode.push_back("    li.d " + dst + ", " + rhs+".0"); 
        }
        else {
            string src = getFloatRegister(scope, rhs,"double"); 
            mipsCode.push_back("    mov.d " + dst + ", " + src); 
        }
        return;
    }
    if(rhs.find("alloc")!=string::npos){
        int rest=stoi(rhs.substr(rhs.find("alloc")+6));
        lhsInfo->offset=last_offset.top();
        last_offset.top()+=rest;
        return;
    }
    string dst = getRegister(scope,lhs);
    if(rhs.find("CALL") != string::npos){
        handle_function_call(rhs);
        mipsCode.push_back("    move " + dst + ", $v0");
        return;
    }
    if (isIntLiteral(rhs)||isCharLiteral(rhs)) {
        mipsCode.push_back("    li " + dst + ", " + rhs);
        loadedConstants[lhs] = true;
        reg_of_const[rhs]=dst;
    }
    else {
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
        return 4; 
    }
    return sym->symbol_size;
}

int get_size_from_type(string type) {
    if (type == "int") return 4;
    else if (type == "float") return 4;
    else if(type == "char")return 4;
    else if(type == "bool")return 1;
    else if(type=="double")return 8;
    return 4;
}

int calculate_function_stack_size(scoped_symtab* scope) {
    int size = 0;
    for (const auto& [name, sym] : scope->symbol_map) {
        if (!sym->is_param_list && !sym->is_return) {
            size += sym->type == "string" ? get_symbol_size(sym) : get_size_from_type(sym->type);
        }
    }
    return size;
}

int space_for_extra_params(symbol_info* sym) {
    int size = 0;
    if (sym->param_list.size() > 4) {
        for (int i=4; i < sym->param_list.size(); ++i) {
            size += get_size_from_type(sym->param_types[i]);
        }
    }
    return size;
}
string newstring(){
    string label = "str" + to_string(string_counter);
    string_counter++;
    return label;
}

// Handles function parameter passing for function calls

void handle_param_pass(const string& line, scoped_symtab* scope) {
    string var = trim(line.substr(5)); // after "PARAM"
    if(var[0] == '&')var = var.substr(1);
    string srcReg;
    if(isStringLiteral(var))
    {
        string literal = var;
    size_t pos = var.find('%');
    if (pos != string::npos) {
        literal = var.substr(0, pos);
    }
    else literal.pop_back();
    size_t start = literal.find_first_not_of(' ');
    size_t end = literal.find_last_not_of(' ');
    if (start != string::npos && end != string::npos) {
        literal = literal.substr(start, end - start + 1);
        literal=literal+"\"";
    } else {
        literal = "";
    }
        string str=newstring();
        data_section.push_back(str+": .asciiz "+literal);
        string_to_label[var]=str;
        mipsCode.push_back("    la $a0, " + str);
        paramCounter++;
        paramtype.push_back("string");
        return;
    }
    if(isIntLiteral(var)){
        paramtype.push_back("int");
        if (paramCounter >= argRegisters.size()) {
            srcReg=getRegister(scope, var);
            functionparams.push_back("    addi $sp, $sp, -4 \n    li "+srcReg+", "+var+"\n    sw " + srcReg + ", " + to_string(0) + "($sp)");
            param_receive_offset=0;
        }
        else if(paramCounter == argRegisters.size()){
            mipsCode.push_back("    li " + argRegisters[paramCounter] + ", " + var);
            param_receive_offset=0;
        }
        else mipsCode.push_back("    li " + argRegisters[paramCounter] + ", " + var);
        paramCounter++;
        return;

    }
    else if(isFloatLiteral(var)){
        paramtype.push_back("float");
        if (paramFloatCounter == 0)
            mipsCode.push_back("    li.s $f12, " + var);
        else if (paramFloatCounter == 1)
            mipsCode.push_back("    li.s $f14, " + var);
        else {
            srcReg=getFloatRegister(scope, var);
            functionparams.push_back("    addi $sp, $sp, -4 \n   li.s "+srcReg+", "+var+"\n    s.s " + srcReg + ", " + to_string(0) + "($sp)");
        }
        paramFloatCounter++;
        return;
        
    }
    symbol_info* sym = getScope(scope, var)->symbol_map[var];
    if (!sym) {
        exit(1);
    }
    
    if (sym->type == "float") {
        paramtype.push_back("float");
        srcReg = getFloatRegister(scope, var);
        reg_for_scanf.push_back(srcReg);
        if (paramFloatCounter == 0)
            mipsCode.push_back("    mov.s $f12, " + srcReg);
        else if (paramFloatCounter == 1)
            mipsCode.push_back("    mov.s $f14, " + srcReg);
        else {
            functionparams.push_back("    addi $sp, $sp, -4 \n    s.s " + srcReg + ", " + to_string(0) + "($sp)");
        }
        paramFloatCounter++;
    } 
    else if (sym->type =="int" || sym->type == "char") {
         if(sym->type=="int") paramtype.push_back("int");
         if(sym->type=="char") paramtype.push_back("char");
        srcReg = getRegister(scope, var);
        reg_for_scanf.push_back(srcReg);
        if (paramCounter >= argRegisters.size()) {
            functionparams.push_back("    addi $sp, $sp, -4 \n    sw " + srcReg + ", " + to_string(0) + "($sp)");
            param_receive_offset=0;
        }
        else if(paramCounter == argRegisters.size()){
            mipsCode.push_back("    move " + argRegisters[paramCounter] + ", " + srcReg);
            param_receive_offset=0;
        }
        else mipsCode.push_back("    move " + argRegisters[paramCounter] + ", " + srcReg);
        paramCounter++;
    }

    
}
// Processes function calls, including system calls like printf and scanf

void handle_function_call(const string& line) {
    istringstream iss(line);
    string call, funcWithComma;
    int argCount;
    iss >> call >> funcWithComma;
    iss.ignore();
    iss >> argCount;
    int arg_no=0;
    string funcName = trim(funcWithComma);
    if (!funcName.empty() && funcName.back() == ',') funcName.pop_back();
    if(funcName.find(",")!=string::npos){
        arg_no=stoi(funcName.substr(funcName.find(",")+1));
        funcName = funcName.substr(0,funcName.find(","));
        
    }
    if(funcName=="printf")
    {
        int floatCounter = 0;
        mipsCode.push_back("#printf");
        int cnt=0;
        for(auto &type : paramtype){
            if(type=="int" || type=="char" || type=="string") {mipsCode.push_back(" move $a0, $a"+to_string(cnt));cnt++;}
            if(type=="float"||type=="double") {mipsCode.push_back("    mov.s $f12, $f"+to_string(12+2*floatCounter));floatCounter++;}
            if(type=="int") mipsCode.push_back("    li $v0, 1");
            else if(type=="char") mipsCode.push_back("    li $v0, 11");
            else if(type=="string") mipsCode.push_back("    li $v0, 4");
            else if(type=="float") mipsCode.push_back("    li $v0, 2");
            else if(type=="bool") mipsCode.push_back("    li $v0, 1");
            else if(type=="double") mipsCode.push_back("    li $v0, 3");
            mipsCode.push_back("syscall");
            mipsCode.push_back("  li $v0, 4 \n la $a0, newline \n syscall");
        }
        paramtype.clear();
        reg_for_scanf.clear();
        arg_no=0;
        paramCounter = 0;
        paramFloatCounter = 0;
        return;
    }
    if(funcName == "scanf") {
        int floatCounter=0;
        int cnt=0;
        mipsCode.push_back("#scanf");
        for(auto &type : paramtype){
            if(type=="int") 
            {mipsCode.push_back("    li $v0, 5"); mipsCode.push_back("syscall"); mipsCode.push_back("move "+ reg_for_scanf[cnt]+" ,$v0");cnt++;}
            else if(type=="char") {mipsCode.push_back("    li $v0, 12"), mipsCode.push_back("syscall"); mipsCode.push_back("move "+ reg_for_scanf[cnt]+" ,$v0");cnt++;}
            else if(type=="string") 
            {
                mipsCode.push_back("    li $v0, 4");
                mipsCode.push_back("syscall");
            }
            else if(type=="float") 
            {mipsCode.push_back("    li $v0, 6");
                mipsCode.push_back("syscall");
                mipsCode.push_back("mov.s "+reg_for_scanf[cnt]+",$f0");
                cnt++;
            }
            else if(type=="double") {mipsCode.push_back("    li $v0, 7");
                mipsCode.push_back("syscall");
                mipsCode.push_back("mov.d "+reg_for_scanf[cnt]+",$f0");
                cnt++;
            } 
        }
        reg_for_scanf.clear();
        paramtype.clear();
        paramCounter = 0; // Reset after call
        paramFloatCounter = 0;
        arg_no=0;
        return;
    }
    if(functionparams.size() > 0){
        reverse(functionparams.begin(), functionparams.end());
        for(auto &param : functionparams){
            mipsCode.push_back(param);
        }
        functionparams.clear();
    }
    
    paramtype.clear();
    mipsCode.push_back("    jal " + funcName);
    paramCounter = 0;
    paramFloatCounter = 0;
    arg_no=0;
    reg_for_scanf.clear();
}

// Handles parameter receiving at the beginning of functions


void handle_param_receive(const string& line, scoped_symtab* scope) {
    size_t assignPos = line.find(":=");
    string lhs = trim(line.substr(0, assignPos));
    symbol_info* sym = getScope(scope, lhs)->symbol_map[lhs];
    if (!sym) {
        exit(1);
    }

    string dst;

    if (sym->type == "float") {
        dst= getFloatRegister(scope, lhs);
        if (paramFloatReceiveCounter == 0)
            mipsCode.push_back("    mov.s " + dst + ", $f12");
        else if (paramFloatReceiveCounter == 1)
            mipsCode.push_back("    mov.s " + dst + ", $f14");
        else {
            mipsCode.push_back("    #popping from stack to " + dst);
            mipsCode.push_back("    l.s " + dst + ", " +to_string(param_receive_offset) + "($fp)");
            param_receive_offset+=4;
            mipsCode.push_back("    #pushing into function stack");
            sym->offset = last_offset.top();
            last_offset.top()+=get_size_from_type(sym->type);
            mipsCode.push_back("    s.s " + dst + ", " + to_string(sym->offset) + "($sp)");
        }
        paramFloatReceiveCounter++;
    } else {

        dst= getRegister(scope, lhs);
        if (paramReceiveCounter >= argRegisters.size()) {
            mipsCode.push_back("    #popping from stack to " + dst);
            mipsCode.push_back("    lw " + dst + ", " +to_string(param_receive_offset) + "($fp)");
            param_receive_offset+=4;
            mipsCode.push_back("    #pushing into function stack");
            sym->offset = last_offset.top();
            last_offset.top()+=get_size_from_type(sym->type);
            mipsCode.push_back("    sw " + dst + ", " + to_string(sym->offset) + "($sp)");
        }
        else{
            string from = argRegisters[paramReceiveCounter];
            mipsCode.push_back("    move " + dst + ", " + from);
        }
        paramReceiveCounter++;
        
    }

}

// Processes array accesses and assignments


void handle_array(const string& line, scoped_symtab* scope) {
    size_t assignPos = line.find(":=");
    string lhs = trim(line.substr(0, assignPos));
    string rhs = trim(line.substr(assignPos + 2));
    string r1;
    if(line[0]=='*'){
        string arr_name=trim(lhs.substr(2).substr(0,lhs.substr(2).find("+")));
        if(isIntLiteral(rhs)){
            if(availableRegs.empty()) handleRegisterSpill(scope,rhs);
            r1=availableRegs.back();
            availableRegs.pop_back();
            load_if_constant(scope, rhs, r1);
            lhs = lhs.substr(3);
            //split on plus
            size_t plusPos = lhs.find("+");
            string lhs1 = trim(lhs.substr(0, plusPos));
            string lhs2 = trim(lhs.substr(plusPos + 1));
            lhs2.pop_back();
            lhs2 = trim(lhs2);
            string regis = getRegister(scope,lhs2);
            mipsCode.push_back("    addi " + regis + ", " + regis + ", " + to_string(getScope(scope,lhs1)->symbol_map[lhs1]->offset));
            mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
            mipsCode.push_back("    sw " + r1 + ", 0(" + regis + ")");
        }
        else if(isFloatLiteral(rhs)){
            if(getScope(scope,arr_name)->symbol_map[arr_name]->type=="float"){
                r1=getFloatRegister(scope,rhs);
                load_if_constant(scope, rhs, r1);
                lhs = lhs.substr(3);
                //split on plus
                size_t plusPos = lhs.find("+");
                string lhs1 = trim(lhs.substr(0, plusPos));
                string lhs2 = trim(lhs.substr(plusPos + 1));
                lhs2.pop_back();
                lhs2 = trim(lhs2);
                string regis = getRegister(scope,lhs2);
                string val=to_string(getScope(scope,lhs1)->symbol_map[lhs1]->offset);
                string regii = getRegister(scope,val);
                mipsCode.push_back("    li " + regii + ", " + val);
                mipsCode.push_back("   add " + regis + ", " + regis + ", " + regii);
                mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
                mipsCode.push_back("    s.s " + r1 + ", 0(" + regis + ")");
            }
            else if(getScope(scope,arr_name)->symbol_map[arr_name]->type=="double"){
                r1=getFloatRegister(scope,rhs,"double");
                load_if_constant(scope, rhs, r1);
                lhs = lhs.substr(3);
                //split on plus
                size_t plusPos = lhs.find("+");
                string lhs1 = trim(lhs.substr(0, plusPos));
                string lhs2 = trim(lhs.substr(plusPos + 1));
                lhs2.pop_back();
                lhs2 = trim(lhs2);
                string regis = getRegister(scope,lhs2);
                string val=to_string(getScope(scope,lhs1)->symbol_map[lhs1]->offset);
                string regii = getRegister(scope,val);
                mipsCode.push_back("    li " + regii + ", " + val);
                mipsCode.push_back("   add " + regis + ", " + regis + ", " + regii);

                mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
                mipsCode.push_back("    s.d" + r1 + ", 0(" + regis + ")");
            }     
        }  
    }else{
        rhs = rhs.substr(3);
        string arr_name=trim(rhs.substr(0,rhs.find("+")));
        size_t plusPos = rhs.find("+");
        string rhs1 = trim(rhs.substr(0, plusPos));
        string rhs2 = trim(rhs.substr(plusPos + 1));
        rhs2.pop_back();
        rhs2 = trim(rhs2);
        if(getScope(scope,arr_name)->symbol_map[arr_name]->type=="float"){
            string regis = getRegister(scope,rhs2);
            string val=to_string(getScope(scope,rhs1)->symbol_map[rhs1]->offset);
            string regii = getRegister(scope,val);
            mipsCode.push_back("    li " + regii + ", " + val);
            mipsCode.push_back("   add " + regis + ", " + regis + ", " + regii);
            mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
            string dst = getFloatRegister(scope,lhs);
            mipsCode.push_back("    l.s " + dst + ", 0(" + regis + ")");
        }
        else if(getScope(scope,arr_name)->symbol_map[arr_name]->type=="double"){
            string regis = getRegister(scope,rhs2);
            string val=to_string(getScope(scope,rhs1)->symbol_map[rhs1]->offset);
            string regii = getRegister(scope,val);
            mipsCode.push_back("    li " + regii + ", " + val);
            mipsCode.push_back("   add " + regis + ", " + regis + ", " + regii);
            mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
            string dst = getFloatRegister(scope,lhs,"double");
            mipsCode.push_back("    l.d " + dst + ", 0(" + regis + ")");
        }
        else{
            string regis = getRegister(scope,rhs2);
            mipsCode.push_back("    addi " + regis + ", " + regis + ", " + to_string(getScope(scope,rhs1)->symbol_map[rhs1]->offset));
            mipsCode.push_back("    add " + regis + ", " + regis + ", $sp");
            string dst = getRegister(scope,lhs);
            mipsCode.push_back("    lw " + dst + ", 0(" + regis + ")");
        }
        
    }
}

// Handles pointer operations like dereferencing and address-of


void handle_pointer(const string& line, scoped_symtab* scope) {
    size_t assignPos = line.find(":=");
    string lhs = trim(line.substr(0, assignPos));
    string rhs = trim(line.substr(assignPos + 2));
    int rhs_ptr=0;
    size_t amppos = rhs.find("&");
    if(lhs[0] == '*'){
        lhs = lhs.substr(1);
    }
    string dst;
    if (amppos != string::npos) 
        rhs = rhs.substr(amppos + 1);
    if(rhs[0] == '*'){
        rhs = rhs.substr(1);
        rhs_ptr=1;
    }
    if(isIntLiteral(rhs)){
        dst=getRegister(scope, lhs);
            mipsCode.push_back("    #Loading constant " + rhs + " into register");
            if(availableRegs.empty()){
                handleRegisterSpill(scope,rhs);
            }
            string reg = availableRegs.back();
            availableRegs.pop_back();
            mipsCode.push_back("    li " + reg + ", " + rhs);
            loadedConstants[rhs] = true;
            reg_of_const[rhs] = reg;
            mipsCode.push_back("    sw " + reg + ", " + to_string(0) + "("+dst + ")");
    }
    else if(isFloatLiteral(rhs)){
       if(getScope(scope,lhs)->symbol_map[lhs]->type=="float"){
        dst=getFloatRegister(scope, lhs);
            mipsCode.push_back("    #Loading constant " + rhs + " into register");
            if(availableFloatRegs.empty()){
                handleFloatRegisterSpill(scope,rhs);
            }
            string reg = getFloatRegister(scope,rhs);
            mipsCode.push_back("    li.s " + reg + ", " + rhs);
            loadedConstants[rhs] = true;
            reg_of_const[rhs] = reg;
            mipsCode.push_back("    s.s " + reg + ", " + to_string(0) + "("+dst + ")");
       }
       else {
        dst=getFloatRegister(scope, lhs,"double");
            mipsCode.push_back("    #Loading constant " + rhs + " into register");
            if(availableFloatRegs.empty()){
                handleDoubleRegisterSpill(scope,rhs);
            }
            string reg =getFloatRegister(scope,rhs,"double");
            mipsCode.push_back("    li.d " + reg + ", " + rhs);
            loadedConstants[rhs] = true;
            reg_of_const[rhs] = reg;
            mipsCode.push_back("    s.d " + reg + ", " + to_string(0) + "("+dst + ")");    
       }
       
    }
    
    else{
        if(rhs_ptr){
            if(var_to_reg.count({getScope(scope, rhs), rhs})){
                dst=getRegister(scope, lhs);
                mipsCode.push_back("    lw " + dst + ", " + "0(" + var_to_reg[{getScope(scope, rhs), rhs}] + ")");
                symbol_info* sym = getScope(scope, rhs)->symbol_map[rhs];
                if(getScope(scope, rhs)->symbol_map[rhs]->offset == -1){
                    sym->offset = last_offset.top();
                    last_offset.top()+=get_size_from_type(sym->type);
                    mipsCode.push_back("    sw " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
                else{
                    mipsCode.push_back("    sw " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
            }
            else if(floatVarToReg.count({getScope(scope, rhs), rhs})){
                dst=getFloatRegister(scope, lhs);
                mipsCode.push_back("    l.s " + dst + ", " + "0(" + floatVarToReg[{getScope(scope, rhs), rhs}] + ")");
                symbol_info* sym = getScope(scope, rhs)->symbol_map[rhs];
                if(getScope(scope, rhs)->symbol_map[rhs]->offset == -1){
                    sym->offset = last_offset.top();
                    last_offset.top()+=get_size_from_type(sym->type);
                    mipsCode.push_back("    s.s " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
                else{
                    mipsCode.push_back("    s.s " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
            }
            else if(doubleVarToReg.count({getScope(scope, rhs), rhs})){
                dst=getFloatRegister(scope, lhs,"double");
                mipsCode.push_back("    l.d " + dst + ", " + "0(" + doubleVarToReg[{getScope(scope, rhs), rhs}] + ")");
                symbol_info* sym = getScope(scope, rhs)->symbol_map[rhs];
                if(getScope(scope, rhs)->symbol_map[rhs]->offset == -1){
                    sym->offset = last_offset.top();
                    last_offset.top()+=get_size_from_type(sym->type);
                    mipsCode.push_back("    s.d " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
                else{
                    mipsCode.push_back("    s.d " + dst + ", " + to_string(sym->offset) + "($sp)");
                }
            }
        }
        else{
            symbol_info* rhsInfo = getScope(scope, rhs)->symbol_map[rhs];
            if(rhsInfo->type.substr(0,3)=="int"){
                dst=getRegister(scope, lhs);
                if(var_to_reg.count({scope, rhs})){
                    push_into_stack({scope, rhs});
                }
                mipsCode.push_back("    addi " + dst + ", $sp, " + to_string(rhsInfo->offset));
            }
            else if(rhsInfo->type.substr(0,5)=="float"){
                dst=getFloatRegister(scope, lhs);
                string regis=floatVarToReg[{scope, rhs}];
                if(floatVarToReg.count({scope, rhs})){
                    push_into_stack({scope, rhs});
                }
                availableFloatRegs.push_back(regis);
                if(stoi(regis.substr(2))%2==1){
                    string pair=regis.substr(0,2)+to_string(stoi(regis.substr(2))-1);
                    if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end()){
                        availableDoubleRegs.push_back(pair);
                    }
                }
                else{
                    string pair=regis.substr(0,2)+to_string(stoi(regis.substr(2))+1);
                    if(find(availableFloatRegs.begin(), availableFloatRegs.end(), pair) != availableFloatRegs.end()){
                        availableDoubleRegs.push_back(regis);
                    }
                }
                string val=to_string(rhsInfo->offset);
                string regii = getFloatRegister(scope,val);
                mipsCode.push_back("    li.s " + regii + ", " + val);
                mipsCode.push_back("   add.s " + dst + ", $sp, " + regii);
            }
            else if(rhsInfo->type.substr(0,6)=="double"){
                string reg = getFloatRegister(scope, rhs,"double");
                string regis=doubleVarToReg[{scope, rhs}];
                if(doubleVarToReg.count({scope, rhs})){
                    push_into_stack({scope, rhs});
                }
                availableDoubleRegs.push_back(regis);
                string pair=regis.substr(0,2)+to_string(stoi(regis.substr(2))+1);
                availableFloatRegs.push_back(pair);
                availableFloatRegs.push_back(regis);
                string val=to_string(rhsInfo->offset);
                string regii = getFloatRegister(scope,val,"double");
                mipsCode.push_back("    li.d " + regii + ", " + val);
                mipsCode.push_back("   add.d " + reg + ", $sp, " + regii);
            }
            
            
        }
    }
}

bool check_struct(const string& line, scoped_symtab* scope) {
    auto pos = line.find(":=");
    string lhs = trim(line.substr(0, pos));
    string rhs = trim(line.substr(pos + 2));
    auto ppos = rhs.find("+");
    if(ppos == string::npos) return false;
    if(isIntLiteral(trim(rhs.substr(0,ppos))) || isFloatLiteral(trim(rhs.substr(0,ppos)))) return false;
    string structName = trim(rhs.substr(0, ppos));
    if(isIntLiteral(structName) || isFloatLiteral(structName) || isStringLiteral(structName)){
        return false;
    }
    symbol_info* sym = getScope(scope, structName)->symbol_map[structName];
    if(sym->type.substr(0,6) == "struct" || sym->type.substr(0,5) == "union") {
        return true;
    }
    return false;
}

void handle_struct(const string& line, scoped_symtab* scope) {
    auto pos = line.find(":=");
    string lhs = trim(line.substr(0, pos));
    string rhs = trim(line.substr(pos + 2));
    auto ppos = rhs.find("+");
    string structName = trim(rhs.substr(0, ppos));
    int offset = stoi(trim(rhs.substr(ppos + 2)));
    int symoffset = getScope(scope,structName)->symbol_map[structName]->offset;
    string dst = getRegister(scope, lhs);
    if (var_to_reg.count({scope, structName})) {
        push_into_stack({scope, structName});
    }
      
    if(symoffset == -1){
        push_into_stack({scope, structName});
    }
    symoffset = scope->symbol_map[structName]->offset;
    int totoffset = symoffset + offset;
    mipsCode.push_back("    addi " + dst + ", $sp, " + to_string(totoffset));
}

// First pass to calculate function stack sizes and parameter sizes

void pass1(vector<pair<string, scoped_symtab*>>& codeList) {
    for (int i = 0; i < codeList.size(); i++) {
        string t = trim(codeList[i].first);
        if (t.empty()) {
        } else if (t.rfind("FUNC_BEGIN", 0) == 0) {
            istringstream iss(t);
            string dummy, funcName;
            iss >> dummy >> funcName;
            int size=0;
            i++;
            map<scoped_symtab*,int> visited_scopes;
            while(i<codeList.size()){
                string t = trim(codeList[i].first);
                if(t.empty()){
                    ;
                }
                else if (t.rfind("FUNC_END", 0) == 0){
                    size_of_extra_parameters[funcName]=space_for_extra_params(codeList[i].second->symbol_map[funcName]);  
                    funcStackSize[funcName] = size+8;
                    break;
                }else{
                    scoped_symtab* scope = codeList[i].second;
                    if(visited_scopes.find(scope)==visited_scopes.end()){
                        visited_scopes[scope]=1;
                        size+=calculate_function_stack_size(scope);
                    }
                }
                i++;
            }
        }
    }
}


string curr_func;

// Second pass that generates MIPS code for each TAC instruction

void pass2(vector<pair<string, scoped_symtab*>>& codeList){
    for(int idx = 0; idx < codeList.size(); ++idx){
        auto& code = codeList[idx];
        currentInstructionIndex = idx;
        string t = trim(code.first);
        if (t.empty()){
            continue;
        }
        else{
            if(t.rfind("FUNC_BEGIN", 0) == 0){
                istringstream iss(t);
                string dummy, funcName;
                iss >> dummy >> funcName;
                trim(funcName);
                curr_func = funcName;
                generate_func_begin_MIPS(funcName, funcStackSize[funcName]);
                paramReceiveCounter = 0;
                paramFloatReceiveCounter = 0;
            }
            else if (t.rfind("FUNC_END",0) == 0) {
                istringstream iss(t);
                string dummy, funcName;
                iss >> dummy >> funcName;
                curr_func = "";   
                generate_func_end_MIPS(funcName, funcStackSize[funcName]);

                continue;
            }
            else if(t.rfind("RETURN",0) == 0){
                istringstream iss(t);
                string keyword, val;
                iss >> keyword >> val;
                generate_return_MIPS(curr_func, code.second, val);
            }
            else if (t.rfind("if (", 0) == 0 && t.find("goto") != string::npos) {
                size_t start = t.find('(') + 1;
                size_t end = t.find(')');
                string condition = t.substr(start, end - start);
                string label = trim(t.substr(t.find("goto") + 4));
                string reg = getRegister(code.second, condition);
                load_if_constant(code.second, condition, reg);
                mipsCode.push_back("    bnez " + reg + ", " + label);
            }
            else if (t.rfind("goto", 0) == 0) {
                string label = trim(t.substr(4));
                mipsCode.push_back("    j " + label);
            }
            else if (t.back() == ':' && isalpha(t[0])) {
                mipsCode.push_back(t);
            }
            else if (t.rfind("PARAM", 0) == 0) {
                handle_param_pass(t, code.second);
                continue;
            }
            else if (t.rfind("CALL", 0) == 0) {
                handle_function_call(t);
                continue;
            }
            else if (t.find(":= PARAM") != string::npos) {
                handle_param_receive(t, code.second);
                continue;
            }
            else if((t.find("*") != string::npos && t.find("(")!=string::npos && t[t.find("*")+1] == '(')){
                handle_array(t, code.second);
                continue;
            }
            else if(t.find("&") != string::npos || (t.find("*") != string::npos && t[t.find("*")+1] != ' ')){
                handle_pointer(t, code.second);
                continue;
            }
            else if(check_struct(t, code.second)){
                handle_struct(t, code.second);
                continue;
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

// Computes use-def information for liveness analysis

void compute_use_def(LivenessInfo& inst) {
    const string& line = inst.code;
    if (line.find(":=") != string::npos) {
        size_t eq = line.find(":=");
        string lhs = trim(line.substr(0, eq));
        string rhs = trim(line.substr(eq + 2));
        if(lhs[0] == '*'){
            lhs = lhs.substr(1);
        }
        istringstream iss(rhs);
        string token;
        while (iss >> token)
            if (isalpha(token[0]) && token != lhs){
                inst.use.insert({getScope(inst.scope,token), token});
            }

        istringstream iss2(lhs);
        string token2;
        bool first=true;
        while (iss2 >> token2)
            if (isalpha(token2[0])){
                if(first){
                    inst.def.insert({getScope(inst.scope,token2), token2});
                    inst.use.insert({getScope(inst.scope,token2), token2});
                    first=false;
                    
                }
                else{
                    inst.use.insert({getScope(inst.scope,token2), token2});
                }
            }
    } else if (line.find("if(") == 0) {
        size_t start = line.find('(') + 1;
        size_t end = line.find(')');
        string cond = line.substr(start, end - start);
        istringstream iss(cond);
        string token;
        while (iss >> token)
            if (isalpha(token[0])){
                inst.use.insert({getScope(inst.scope,token), token});
            }
    } else if (line.find("RETURN") == 0) {
        string word, val;
        istringstream iss(line);
        iss >> word >> val;
        if(isalpha(val[0])) inst.use.insert({getScope(inst.scope,val), val});
    }
}

// Identifies successor instructions for control flow graph construction

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

// Performs liveness analysis on the three-address code

void run_liveness(vector<LivenessInfo>& program) {
    compute_successors(program);
    for (auto& inst : program)
        compute_use_def(inst);
    
    bool changed;
    do {
        changed = false; 

        for (int i = (int)program.size() - 1; i >= 0; --i) {
            auto old_in = program[i].live_in;
            auto old_out = program[i].live_out;
            program[i].live_out.clear();
            for (int s : program[i].successors){
                if(program[s].live_in.empty())
                    program[i].live_out.insert(program[s].live_in.begin(), program[s].live_in.end());
            }

            program[i].live_in = program[i].use;
            for (auto& v : program[i].live_out)
                if (!program[i].def.count(v))
                    program[i].live_in.insert(v);

            if (old_in != program[i].live_in || old_out != program[i].live_out)
                changed = true;
        }
    } while (changed);
    
}

// Extracts static variables and adds them to data section

vector<pair<string, scoped_symtab*>> handle_static_code(vector<pair<string, scoped_symtab*>>& codeList) {
    vector<pair<string, scoped_symtab*>> staticCode;
    for (int i = 0; i < codeList.size(); ++i) {
        string t = trim(codeList[i].first);
        if (t.empty()) {
        } else if (t.rfind("FUNC_BEGIN", 0) == 0) {
            break;
        } else {
            staticCode.push_back(codeList[i]);
        }
    }
    //remove static code from original list
    codeList.erase(codeList.begin(), codeList.begin() + staticCode.size());
    
    //iterate over static code and find all the variables and put in data section with name static_<variable>
    for (auto& code : staticCode) {
        string line = code.first;
        size_t assignPos = line.find(":=");
        if (assignPos != string::npos) {
            string lhs = trim(line.substr(0, assignPos));
            string rhs = trim(line.substr(assignPos + 2));
            static_var.push_back({code.second,lhs});
            if (isIntLiteral(rhs)) {
                data_section.push_back("static_"+ lhs + ": .word " + rhs);
            } else if (isFloatLiteral(rhs)) {
                data_section.push_back("static_" + lhs + ": .float " + rhs);
            } else if (isStringLiteral(rhs)) {
                data_section.push_back("static_" + lhs + ": .asciiz \"" + rhs.substr(1, rhs.size() - 2) + "\"");
            }
        }
    }

    return codeList;


}

// Main function for code generation that coordinates the entire process

void codegen_main() {
    mipsCode.push_back(".text");
    mipsCode.push_back(".globl main");
    data_section.push_back(".data");
    data_section.push_back("newline: .asciiz \"\\n\"");
    std::vector<std::pair<std::string,scoped_symtab*>> codeList=handle_static_code(cleaned_TAC);
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
    mipsCode.push_back("    li $v0, 10");
    mipsCode.push_back("    syscall");

    for(auto data : data_section){
        cerr << data << endl;
    }
    for (const string& line : mipsCode) {
        cerr << line << endl;
    }
    return;
}