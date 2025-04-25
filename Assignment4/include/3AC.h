#include <bits/stdc++.h>
#include <utility.h>
using namespace std;


// extern map<int , string> gotoLabels;


int counter=0;
int counter_lab=0;

qid newtemp(string type,scoped_symtab* curr_scope){
    string temp = "t" + to_string(counter);
    counter++;
    symbol_info* temp_info = new symbol_info(temp, type);
    curr_scope->symbol_map[temp] = temp_info;
    qid temp_qid = make_pair(temp, temp_info);
    return temp_qid;
}   


string newlabel(){
    string label = "LABEL" + to_string(counter_lab);
    counter_lab++;
    return label;
}