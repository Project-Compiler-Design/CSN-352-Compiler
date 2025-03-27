#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>

struct symbol_info {
    std::string type;  // Use std::string instead of char* for safety
    std::string name;
    void* ptr = nullptr;  // Pointer to hold int* or float*
    int symbol_size=0;
};

#endif // SYMBOL_TABLE_H
