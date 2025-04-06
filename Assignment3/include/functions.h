#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "3AC.h"



map<string, int> type_priority = {{"char",1},{"int",2},{"float",3},{"double",4}};
string priority_to_type[] = {"","char", "int", "float", "double"};

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

void convert_type(symbol_info* &sym, std::string new_type){
    std::string curr_type = sym->type;
    if(new_type == "int"){
        if(curr_type == "char"){
            char* temp = (char*)sym->ptr;
            int* new_ptr = (int*)malloc(sizeof(int));
            *new_ptr = (int)*temp;
            sym->ptr = new_ptr;
            sym->type = "int";
        }
    }
    else if(new_type == "float"){
        if(curr_type == "int"){
            int* temp = (int*)sym->ptr;
            float* new_ptr = (float*)malloc(sizeof(float));
            *new_ptr = (float)*temp;
            sym->ptr = new_ptr;
            sym->type = "float";
        }
        else if(curr_type == "char"){
            char* temp = (char*)sym->ptr;
            float* new_ptr = (float*)malloc(sizeof(float));
            *new_ptr = (float)*temp;
            sym->ptr = new_ptr;
            sym->type = "float";
        }
    }
    else if(new_type == "double"){
        if(curr_type == "int"){
            int* temp = (int*)sym->ptr;
            double* new_ptr = (double*)malloc(sizeof(double));
            *new_ptr = (double)*temp;
            sym->ptr = new_ptr;
            sym->type = "double";
        }
        else if(curr_type == "float"){
            float* temp = (float*)sym->ptr;
            double* new_ptr = (double*)malloc(sizeof(double));
            *new_ptr = (double)*temp;
            sym->ptr = new_ptr;
            sym->type = "double";
        }
    }
}

bool isSingleNumber(const string &line) {
    for (char ch : line) {
        if (!isdigit(ch)) return false;  // If any non-digit character is found, return false
    }
    return !line.empty();  // Ensure it's not an empty string
}
bool startsWithPointerOrAddress(const string& line) {
    regex pattern(R"(^(\*\*\w+)|(^\*\w+)|(^&&\w+)|(^&\w+))");
    return regex_search(line, pattern);
}

// Function to clean Three-Address Code from input file and write to output file
void cleanTAC(string input) {

    string line="";
    int index=0;
    while(index<input.length()){
        line="";
        while(index<input.length()){
            if(input[index]!='\n'){
                line+=input[index];
                index++;
            }
            else{
                index++;
                break;
            }
        }
        
        // Trim leading and trailing spaces
        while (!line.empty() && isspace(line.front())) line.erase(line.begin());
        while (!line.empty() && isspace(line.back())) line.pop_back();

        // Skip empty lines and lines with only a single number
        if (line.empty() || isSingleNumber(line)) continue;

        // Skip lines with pointers or address-of expressions
        if (startsWithPointerOrAddress(line) && line.find('=') == string::npos) {
            continue;
        }

        // Check if the line is a label or function
        if (!line.empty() && line.back() == ':' || !line.empty() && line.substr(0,4)=="FUNC") {
            cerr << line << endl;  // Labels should not be indented
        } else {
            cerr << "    " << line << endl;  // Indent normal instructions
        }   
    }
    cout << "Cleaning complete! Check " << endl;
}

string replace_break_continue(string original_code,string end_label,string update_label,int i){
    string new_code = original_code;
    int flag=0;
    size_t pos = 0;
    while ((pos = new_code.find("break")) != std::string::npos) {
        new_code.replace(pos, 5, "goto " + end_label + "\n");
    }

    pos = 0;
    while ((pos = new_code.find("continue")) != std::string::npos) {
        new_code.replace(pos, 8, "goto " + update_label + "\n");
        flag=1;
    }
    if(flag==0 && i==0)
    {
        pos=0;
        while ((pos = new_code.find(update_label)) != std::string::npos) {
        new_code.replace(pos, update_label.length()+1, "\n");
        flag=1;
    }
    }
    return new_code;
}

int count_star(string s){
    // cerr<<"hey"<<endl;
    int count = 0;
    while(s.back() == '*'){
        count++;
        s.pop_back();
    }
    return count;
}

int count_init_star(string s){
    // cerr<<"hey"<<endl;
    int count = 0;
    while(s.front() == '*'){
        count++;
        s.erase(0,1);
    }
    return count;
}


string remove_equal(string s) {
    int lastpos=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='\n'){
            lastpos=i;
        }
    }
    string temp = s.substr(0, lastpos+1);
    int index=lastpos;
    while(s[index]!='=') index++;
    index++;
    while(index<s.length()){
        temp+=s[index];
        index++;
    }
    return temp;
}

string get_last_line(string s) {
    size_t pos = s.rfind(":=");
    if (pos != string::npos) {
        return s.substr(pos + 2); // Get everything after the last :=
    }
    return ""; // Return empty string if := is not found
}

void debug(string s1,string s2)
	{
		cerr<<s1<<endl;
		cerr<<s2<<endl;
		cerr<<s1<<endl;
	}

#endif