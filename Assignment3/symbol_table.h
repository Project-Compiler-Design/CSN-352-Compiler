#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include<map>

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

struct symbol_info {
    std::string name;
    std::string type;  // Use std::string instead of char* for safety
    void* ptr = nullptr;  // Pointer to hold int* or float*
    int symbol_size=0;
    std::string str_val;
    bool is_array = false;
    int array_length = 0;
    std::vector<symbol_info*> int_array;


    symbol_info(std::string name="", std::string type="", void* ptr=nullptr, int symbol_size=0, bool is_array=false, int array_length=0, std::vector<int> int_array={})
        : name(name), type(type), ptr(ptr), symbol_size(symbol_size){}
};

symbol_info* lookup_symbol_local(const std::string& name, scoped_symtab* curr_scope){
    return curr_scope->symbol_map[name];
}

symbol_info* lookup_symbol_global(const std::string& name, scoped_symtab* curr_scope){
    scoped_symtab* scope = curr_scope;
    while (scope != nullptr) {
        if(scope->symbol_map[name] != nullptr){
            return scope->symbol_map[name];
        }
        scope = scope->parent;
    }
    return nullptr;
}

#endif // SYMBOL_TABLE_H
