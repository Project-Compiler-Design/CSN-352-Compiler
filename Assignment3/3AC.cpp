#include "3AC.h"
int counter=0;
vector<quad*> quad_list;

qid newtemp(string type,scoped_symtab* curr_scope){
    string temp = "t" + to_string(counter);
    counter++;
    symbol_info* temp_info = new symbol_info(temp, type);
    curr_scope->symbol_map[temp] = temp_info;
    qid temp_qid = make_pair(temp, temp_info);
    return temp_qid;
}   

void emit(qid op, qid arg1, qid arg2, qid res, int idx){
    quad* new_quad = new quad;
    new_quad->op = op;
    new_quad->arg1 = arg1;
    new_quad->arg2 = arg2;
    new_quad->res = res;
    new_quad->idx = idx;
    quad_list.push_back(new_quad);
}



