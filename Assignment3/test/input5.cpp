#include<iostream>
#include<map> 
#include "../functions.h"
using namespace std;

int main(){
    std::string hi="hi";
    symbol_info* sym = new symbol_info("hi","int",new int(5));
    symbol_info* sym2 = new symbol_info("yo","int",new int(7));
    void* ptr = new int(6);
    set_pointer_data(sym,"int",ptr);
    cout<<*((int*)(sym->ptr))<<endl;
}