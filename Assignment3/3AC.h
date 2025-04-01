#include <bits/stdc++.h>
#include "utility.h"
using namespace std;


// extern map<int , string> gotoLabels;

void emit(qid, qid , qid , qid , int );
void backpatch(vector<int>& , int);
qid newtemp(string,scoped_symtab* );
int assign_exp(string op, string type, string type1,string type2, qid arg1, qid arg2);
void casepatch(vector<int>& bplist, qid target);
void print3AC_code();
void backpatch_rem();
string newlabel();