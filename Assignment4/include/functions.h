#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <3AC.h>



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
    int lineno=1;
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
        //cerr<<lineno<<".  ";
        if (!line.empty() && line.back() == ':' || !line.empty() && line.substr(0,4)=="FUNC") {
            //cerr << line << endl;  // Labels should not be indented
        } else {
            //cerr << "    " << line << endl;  // Indent normal instructions
        }   
        lineno++;
    }
    // cout << "Cleaning complete! Check " << endl;
}



bool isSingleFloat(const string& line) {
    return regex_match(line, regex("^[0-9]*\\.[0-9]+$"));
}

bool isSingleStringLiteral(const string& line) {
    return regex_match(line, regex("^\".*\"$"));
}

string trimm(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}
template<typename T>
std::string pointer_to_string(T* ptr) {
    std::ostringstream oss;
    oss << ptr;             // streams the address in hex (e.g. 0x7ffc1234abcd)
    return oss.str();
}
vector<pair<string, scoped_symtab*>> clean_vector_TAC(vector<pair<string, scoped_symtab*>>& input) {
    vector<pair<string, scoped_symtab*>> cleaned_TAC;
    unordered_set<string> paramVars;  // to remember param0, param1, …

    for (auto& entry : input) {
        string& line = entry.first;
        scoped_symtab* scope = entry.second;
        while(line.back() == '\n'){
            line.pop_back();
        }
        string address=pointer_to_string(entry.second);
        // 2) Skip trivial or empty lines
        if (line.empty() ||
            isSingleNumber(line) ||
            isSingleFloat(line) ||
            isSingleStringLiteral(line) ||
            (startsWithPointerOrAddress(line) && line.find('=') == string::npos))
        {
            continue;
        }

        // 3) Param logic (handles both ":=" and "=")
        auto eqPos = line.find('=');
        if (eqPos != string::npos) {
            string lhs = trimm(line.substr(0, eqPos-1));
            //cout<<"lhs: " << lhs << endl;
            string rhs = trimm(line.substr(eqPos + 1));

            // normalize leading ":=" if present
            if (!rhs.empty() && rhs[0] == ':') {
                auto p = rhs.find_first_not_of(":=");
                if (p != string::npos) rhs = trimm(rhs.substr(p));
            }

            // 3a) collect & drop param declarations
            if (rhs == "PARAM") {
                paramVars.insert(lhs);
                continue;
            }

            // 3b) replace var := paramX → var := PARAM
            if (paramVars.count(rhs)) {
                cleaned_TAC.emplace_back(
                     lhs + " := PARAM",
                    scope
                );
                continue;
            }
        }

        // 4) otherwise, keep the line verbatim (with its address)
        cleaned_TAC.emplace_back(line, scope);
    }

    return cleaned_TAC;
}



void print_vector(const vector<pair<string,scoped_symtab*>>& vec) {
    for (const auto& pair : vec) {
        cerr<<pair.second<<" "<<pair.first<<endl;
    }
}

string replace_break_continue(string original_code,string end_label,string update_label,int i){
    string new_code = original_code;
    // cout << "Original code: " << original_code << endl;
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

vector<pair<string,scoped_symtab*>> replace_break_continue_final(vector<pair<string,scoped_symtab*>> original_code,string end_label,string update_label,int i){
    vector<pair<string,scoped_symtab*>> new_code;
    int flag=0;
    for(int j=0;j<original_code.size();j++){
        string code=original_code[j].first;
        scoped_symtab* curr_scope2=original_code[j].second;
        string new_code_str = code;
        size_t pos = 0;
        while ((pos = new_code_str.find("break")) != std::string::npos) {
            new_code_str = new_code_str.substr(0, pos) + "goto " + end_label + "\n" + new_code_str.substr(pos+5);
        }

        pos = 0;
        while ((pos = new_code_str.find("continue")) != std::string::npos) {
            new_code_str = new_code_str.substr(0, pos) + "goto " + update_label + "\n" + new_code_str.substr(pos+8);
            flag=1;
        }
        if(flag==0 && i==0)
        {
            pos=0;
            while ((pos = new_code_str.find(update_label)) != std::string::npos) {
                new_code_str = new_code_str.substr(0, pos) + "\n" + new_code_str.substr(pos+update_label.length()+1);
                flag=1;
            }
        }
        new_code.push_back({new_code_str,curr_scope2});
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

string find_last_line(string s){
    int lastpos=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='\n'){
            lastpos=i;
        }
    }
    string temp = "";
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
int get_size(const std::string& type) {
    if (type == "int") return 4;
    if (type == "char") return 2;
    if (type == "float") return 4;
    if (type == "double") return 8;
    if (type == "short") return 2;
    if (type == "long") return 8;
    if (type == "void") return 0;
    return 4;
}

string get_assignment_statement(string t1,string op,string t2)
{
    string tcode="";
    if(op=="=")
    {
        tcode=t1 + ":=  " + t2;
    }
    else if(op=="*=")
    {
        tcode=t1 + ":=  " + t1+"*"+t2;
    }
    else if(op=="/=")
    {
        tcode=t1 + ":=  " + t1+"/"+t2;
    }
    else if(op=="%=")
    {
        tcode=t1 + ":=  " + t1+"%"+t2;
    }
    else if(op=="+=")
    {
        tcode=t1 + ":=  " + t1+"+"+t2;
    }
    else if(op=="-=")
    {
        tcode=t1 + ":=  " + t1+"-"+t2;
    }
    else if(op=="<<=")
    {
        tcode=t1 + ":=  " + t1+"<<"+t2;
    }
    else if(op==">>=")
    {
        tcode=t1 + ":=  " + t1+">>"+t2;
    }
    else if(op=="&=")
    {
        tcode=t1 + ":=  " + t1+"&"+t2;
    }
    else if(op=="^=")
    {
        tcode=t1 + ":=  " + t1+"^"+t2;
    }
    else if(op=="|=")
    {
        tcode=t1 + ":=  " + t1+"|"+t2;
    }   
    else{
        tcode="error";
    }
    return tcode;
}
void debug(string s1,string s2)
	{
		cerr<<s1<<endl;
		cerr<<s2<<endl;
		cerr<<s1<<endl;
	}

#endif