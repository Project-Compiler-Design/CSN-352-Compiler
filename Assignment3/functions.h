#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "utility.h"

//set_pointer_data function
// This function sets the value of a pointer in the symbol_info struct based on the type provided.
void set_pointer_data(symbol_info* sym, std::string type, void* ptr){
    if(sym->ptr == nullptr){
        sym->ptr = malloc(sizeof(sym->type));
    }
    if(type == "int"){
        *((int*)(sym->ptr)) = *((int*)ptr);
    }
    else if(type == "float"){
        *((float*)(sym->ptr)) = *((float*)ptr);
    }
    else if(type == "string"){
        *((std::string*)(sym->ptr)) = *((std::string*)ptr);
    }
    else if(type == "char"){
        *((char*)(sym->ptr)) = *((char*)ptr);
    }
    else if(type == "bool"){
        *((bool*)(sym->ptr)) = *((bool*)ptr);
    }
    else if(type == "double"){
        *((double*)(sym->ptr)) = *((double*)ptr);
    }
    else if(type == "long"){
        *((long*)(sym->ptr)) = *((long*)ptr);
    }
    else if(type == "short"){
        *((short*)(sym->ptr)) = *((short*)ptr);
    }
    else if(type == "unsigned int"){
        *((unsigned int*)(sym->ptr)) = *((unsigned int*)ptr);
    }
    else if(type == "unsigned char"){
        *((unsigned char*)(sym->ptr)) = *((unsigned char*)ptr);
    }
    else if(type == "unsigned long"){
        *((unsigned long*)(sym->ptr)) = *((unsigned long*)ptr);
    }
    else if(type == "unsigned short"){
        *((unsigned short*)(sym->ptr)) = *((unsigned short*)ptr);
    }
    else if(type == "unsigned long long"){
        *((unsigned long long*)(sym->ptr)) = *((unsigned long long*)ptr);
    }
    else if(type == "long long"){
        *((long long*)(sym->ptr)) = *((long long*)ptr);
    }
    else if(type == "void*"){
        *((void**)(sym->ptr)) = *((void**)ptr);
    }
    else if(type == "char*"){
        *((char**)(sym->ptr)) = *((char**)ptr);
    }
    else if(type == "int*"){
        *((int**)(sym->ptr)) = *((int**)ptr);
    }
    else if(type == "float*"){
        *((float**)(sym->ptr)) = *((float**)ptr);
    }
    else if(type == "string*"){
        *((std::string**)(sym->ptr)) = *((std::string**)ptr);
    }
    else if(type == "bool*"){
        *((bool**)(sym->ptr)) = *((bool**)ptr);
    }

}

#endif