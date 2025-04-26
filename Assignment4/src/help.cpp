#include<bits/stdc++.h>
#include <regex>
using namespace std;
vector<string> avail_Regs = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
string get_reg(){
    if (avail_Regs.empty()) {
        cerr << "No available registers!" << endl;
        return "";
    }
    string reg = avail_Regs.back();
    avail_Regs.pop_back();
    return reg;
}

void free_reg(string reg){
    avail_Regs.push_back(reg);
}

bool is_constant(const string& s) {
    return regex_match(s, regex(R"(\d+)")); // matches integers only
}
void handle_arithmetic_operation(string tac){
    regex pattern(R"(^\s*(\w+)\s*:=\s*(\w+)\s*([\+\-\*/])\s*(\w+)\s*$)");
    smatch match;
    string result;
    string arg1;
    string op;
    string arg2;
    if (regex_match(tac, match, pattern)) {
        result = match[1];
        arg1 = match[2];
        op = match[3];
        arg2 = match[4];
        cout << "Result variable: " << result << endl;
        cout << "Operand 1: " << arg1 << endl;
        cout << "Operator: " << op << endl;
        cout << "Operand 2: " << arg2 << endl;
    }
    if(is_constant (arg1) && is_constant(arg2)){
        string reg = get_reg();
        string val;
        if(op=="+"){
            val = to_string(stoi(arg1) + stoi(arg2));
        }
        else if(op=="-"){
            val = to_string(stoi(arg1) - stoi(arg2));
        }
        else if(op=="*"){
            val = to_string(stoi(arg1) * stoi(arg2));
        }
        else if(op=="/"){
            val = to_string(stoi(arg1) / stoi(arg2));
        }
        cout<<"li "<<reg<<","<<val<<endl;
    }
    else if(is_constant(arg2) && op=="+"){
        string reg=get_reg();
        cout<<"addi"<<""<<reg<<","<<arg1<<","<<arg2<<endl;
    }
    else{
        cout<<"Both operands are variables."<<endl;
    }
}
int main()
{
    string tac = "t1:= 4 + 3";
    handle_arithmetic_operation(tac);
    
    return 0;
}