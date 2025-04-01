#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include<map>
#include<bits/stdc++.h>
struct scoped_symtab;
struct symbol_info;
static symbol_info* lookup_symbol_local(const std::string& name, scoped_symtab* curr_scope);
static symbol_info* lookup_symbol_global(const std::string& name, scoped_symtab* curr_scope);

struct scoped_symtab{
    scoped_symtab* parent = nullptr;
    std::map<std::string,symbol_info*> symbol_map;
    std::vector<scoped_symtab*> child_list; 

    scoped_symtab(scoped_symtab* parent = nullptr){
        this->parent = parent;
    }
};

typedef std::pair <std::string, symbol_info*> qid;

typedef struct quadruple{
    qid op;
    qid arg1;
    qid arg2;
    qid res;
    int idx;
} quad;
struct symbol_info {
    std::string name;
    std::string type;  // Use std::string instead of char* for safety
    void* ptr = nullptr;  // Pointer to hold int* or float*
    int symbol_size=0;
    std::string str_val;
    bool is_array = false;
    int array_length = 0;
    std::vector<symbol_info*> int_array;
    bool is_param_list=false;
    int parameter_no=0;
    std::vector<std::string> param_types;
    std::vector<std::string> param_list;
    std::vector<symbol_info*> struct_attr_values;

    qid place;
    std::string code;

    bool is_continue=false;
    bool is_break=false;


    symbol_info(std::string name="", std::string type="", void* ptr=nullptr, int symbol_size=0, bool is_array=false, int array_length=0, std::vector<int> int_array={},bool is_param_list=false,std::vector<std::string> param_types={},std::vector<std::string> param_list={},int parameter_no=0,qid place = {"", nullptr}, std::string code = "",
                std::vector<symbol_info*> struct_attr_values = {},bool is_continue=false,bool is_break=false)
        : name(name), type(type), ptr(ptr), symbol_size(symbol_size){}
};

symbol_info* lookup_symbol_local(const std::string& name, scoped_symtab* curr_scope){
    auto ptr = curr_scope->symbol_map.find(name);
    if (ptr != curr_scope->symbol_map.end()) {
        return ptr->second;
    }
    return nullptr;
}

symbol_info* lookup_symbol_global(const std::string& name, scoped_symtab* curr_scope){
    scoped_symtab* scope = curr_scope;
    while (scope != nullptr) {
        if(scope->symbol_map.find(name) != scope->symbol_map.end()){
            return scope->symbol_map[name];
        }
        scope = scope->parent;
    }
    return nullptr;
}

#endif // SYMBOL_TABLE_H
