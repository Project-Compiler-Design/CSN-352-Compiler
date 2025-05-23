#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;
struct scoped_symtab;
struct symbol_info;

static symbol_info* lookup_symbol_local(const std::string& name, scoped_symtab* curr_scope);
static symbol_info* lookup_symbol_global(const std::string& name, scoped_symtab* curr_scope);
extern vector<pair<string,scoped_symtab*>> cleaned_TAC;

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
    int pointer_depth=0;
    qid place;
    std::vector<std::pair<std::string, scoped_symtab*>> final_code;
    std::string code;
    
    bool is_return=false;
    std::string return_type="";
    bool is_array_access=false;
    bool is_continue=false;
    bool is_break=false;
    int offset=-1;
    
    symbol_info(std::string name="", std::string type="", void* ptr=nullptr, int symbol_size=0, bool is_array=false, int array_length=0, std::vector<int> int_array={},bool is_param_list=false,std::vector<std::string> param_types={},std::vector<std::string> param_list={},int parameter_no=0,int pointer_depth=0, qid place = {"", nullptr}, std::string code = "",
        std::vector<symbol_info*> struct_attr_values = {}, int offset=-1)
        : name(name), type(type), ptr(ptr), symbol_size(symbol_size){}

    symbol_info(symbol_info* sym)
        : name(sym->name), type(sym->type), ptr(sym->ptr), symbol_size(sym->symbol_size),
          is_array(sym->is_array), array_length(sym->array_length), int_array(sym->int_array),
          is_param_list(sym->is_param_list), parameter_no(sym->parameter_no),
          param_types(sym->param_types), param_list(sym->param_list),
          struct_attr_values(sym->struct_attr_values), pointer_depth(sym->pointer_depth),
          place(sym->place), code(sym->code), offset(sym->offset) {
                // Copy the final_code vector
                for (const auto& item : sym->final_code) {
                final_code.push_back(item);
            }
          }
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
    