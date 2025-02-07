%option noyywrap
%{
    #include <algorithm>
    #include <iostream>
    #include <utility>
    #include <iomanip>
    #include <math.h>
    #include <cstdio> 
    #include <vector>
    #include <string>
    #include <map>
    #include<fstream>
    extern "C" int yylex();


    using namespace std;
    struct TokenTable
    {
        string lexeme;
        string token_type;

        TokenTable(string lexval,string tokenval)
        {
        lexeme = lexval;         // Correct assignment to data member
        token_type = tokenval;   // Correct assignment to data member
        }
    };
    vector<TokenTable> tokens;
    vector<string> errors;
    void error_call(string s,int t){
        if(t==0) errors.push_back("Invalid identifier: "+s+" in line no. "+std::to_string(yylineno));
        else errors.push_back("Invalid token: "+s+" in line no. "+std::to_string(yylineno));
    }

%}

%option yylineno

DELIM           [ \t\n\r]
WS              {DELIM}+

INCLUDE         ^#include.*\n
AUTO            "auto"
STRUCT          "struct"
BOOL			"bool"
BREAK         	"break"
CASE           	"case"
CONTINUE       	"continue"
GOTO           	"goto"
DO             	"do"
DEFAULT        	"default"
IF             	"if"
ELSE           	"else"
FOR            	"for"
CONST          	"const"
TRUE           	"true"
FALSE          	"false"
STATIC         	"static"
SWITCH         	"switch"
WHILE          	"while"
VOID           	"void"
RETURN          "return"
SIZEOF         	"sizeof"
FLOAT          	"float"
INT       	    "int"
DOUBLE         	"double"
EXTERN         	"extern"
SHORT          	"short"
LONG           	"long"
CHAR            "char"
ENUM            "enum"
REGISTER        "register"
SIGNED          "signed"
TYPEDEF         "typedef"
UNION           "union"
UNSIGNED        "unsigned" 
VOLATILE        "volatile"

NOTLETTER       [^A-Za-z_]
LETTER          [A-Za-z]
DIGIT           [0-9]
HEXA_DIGIT      [a-fA-F0-9]
EXP             [Ee][+-]?{DIGIT}+
FS			    (f|F|l|L)
IS			    (u|U|l|L)*


ID              ({LETTER}|_)({LETTER}|_|{DIGIT})*
HEXA_LITERAL      0[xX]{HEXA_DIGIT}+{IS}?
OCTAL_LITERAL    0[0-7]+{IS}?
DECIMAL_LITERAL   {DIGIT}+{IS}?
EXP_LITERAL       {DIGIT}+[Ee][+-]?{DIGIT}+{FS}?
REAL_LITERAL           {DIGIT}*"."{DIGIT}+({EXP})?
FLOAT_LITERAL     {DIGIT}*"."{DIGIT}+({EXP})?{FS}

STRING_LITERAL         L?\"(\\.|[^\\"])*\"
CHARACTER_LITERAL       (L|u8|u|U)?'((\\.)|[^'\\])'
SINCMNT         \/\/.*
MULCMNT         "/*"([^*]|\*+[^*/])*\*+"/"


RBRACE         	"\}"
LBRACE          "\{"
LBRACKET        "\]"
RBRACKET       	"\["
LPARENTHESES   	"\("
RPARENTHESES   	"\)"
DOT            	"\."
COMMA          	","
COLON          	":"
SEMICOLON      	";"
PLUS           	"\+"
MINUS          	"-"
STAR           	"\*"
DIVIDE        	"\/"
MODULO         	"%"
AMPERSAND      	"&"
OR             	"\|"
XOR            	"\^"
EXCLAMATION    	"!"
TILDE          	"~"
EQUALS        	"="
LESS_THAN      	"<"
GREATER_THAN   	">"
QUESTION_MARK  	"\?"
INCREMENT      	"\+\+"
DECREMENT      	"--"
REL_AND        	"&&"
REL_OR         	"\|\|"
REL_EQUALS     	"=="
REL_NOT_EQ     	"!="
LESS_EQUALS    	"<="
GREATER_EQUALS 	">=	"
ASSIGN_PLUS    	"\+="
ASSIGN_MINUS   	"-="
ASSIGN_STAR    	"\*="
ASSIGN_DIV     	"\/="
ASSIGN_MOD    	"%="
ASSIGN_AND     	"&="
ASSIGN_OR      	"\|="
ASSIGN_XOR     	"\^="
LEFT_SHIFT     	"<<"
LEFT_SHIFT_EQ  	"<<="
RIGHT_SHIFT    	">>"
RIGHT_SHIFT_EQ 	"\>>="
LAMBDA_ARROW   	"->"
VARIABLE_ARGS  	"..."

INVALID_ID     (({DIGIT})+({LETTER}|_)*|{DIGIT}+{LETTER}+(\.{DIGIT}*)?)

%%
{WS}            {}
{INCLUDE}       {tokens.push_back(TokenTable(yytext, "INCLUDE DIRECTIVE"));}

{AUTO}          { tokens.push_back(TokenTable(yytext, "AUTO")); }
{STRUCT}        { tokens.push_back(TokenTable(yytext, "STRUCT")); }
{BOOL}          { tokens.push_back(TokenTable(yytext, "BOOL")); }
{BREAK}         { tokens.push_back(TokenTable(yytext, "BREAK")); }
{CASE}          { tokens.push_back(TokenTable(yytext, "CASE")); }
{CONTINUE}      { tokens.push_back(TokenTable(yytext, "CONTINUE")); }
{GOTO}          { tokens.push_back(TokenTable(yytext, "GOTO")); }
{DO}            { tokens.push_back(TokenTable(yytext, "DO")); }
{DEFAULT}       { tokens.push_back(TokenTable(yytext, "DEFAULT")); }
{IF}            { tokens.push_back(TokenTable(yytext, "IF")); }
{ELSE}          { tokens.push_back(TokenTable(yytext, "ELSE")); }
{FOR}           { tokens.push_back(TokenTable(yytext, "FOR")); }
{CONST}         { tokens.push_back(TokenTable(yytext, "CONST")); }
{TRUE}          { tokens.push_back(TokenTable(yytext, "TRUE")); }
{FALSE}         { tokens.push_back(TokenTable(yytext, "FALSE")); }
{STATIC}        { tokens.push_back(TokenTable(yytext, "STATIC")); }
{SWITCH}        { tokens.push_back(TokenTable(yytext, "SWITCH")); }
{WHILE}         { tokens.push_back(TokenTable(yytext, "WHILE")); }
{VOID}          { tokens.push_back(TokenTable(yytext, "VOID")); }
{RETURN}        { tokens.push_back(TokenTable(yytext, "RETURN")); }
{SIZEOF}        { tokens.push_back(TokenTable(yytext, "SIZEOF")); }
{FLOAT}         { tokens.push_back(TokenTable(yytext, "FLOAT")); }
{INT}           { tokens.push_back(TokenTable(yytext, "INT")); }
{DOUBLE}        { tokens.push_back(TokenTable(yytext, "DOUBLE")); }
{EXTERN}        { tokens.push_back(TokenTable(yytext, "EXTERN")); }
{SHORT}         { tokens.push_back(TokenTable(yytext, "SHORT")); }
{LONG}          { tokens.push_back(TokenTable(yytext, "LONG")); }
{CHAR}          { tokens.push_back(TokenTable(yytext, "CHAR")); }
{ENUM}          { tokens.push_back(TokenTable(yytext, "ENUM")); }
{REGISTER}      { tokens.push_back(TokenTable(yytext, "REGISTER")); }
{SIGNED}        { tokens.push_back(TokenTable(yytext, "SIGNED")); }
{TYPEDEF}       { tokens.push_back(TokenTable(yytext, "TYPEDEF")); }
{UNION}         { tokens.push_back(TokenTable(yytext, "UNION")); }
{UNSIGNED}      { tokens.push_back(TokenTable(yytext, "UNSIGNED")); }
{VOLATILE}      { tokens.push_back(TokenTable(yytext, "VOLATILE")); }



{ID}            { tokens.push_back(TokenTable(yytext, "IDENTIFIER")); }
{HEXA_LITERAL}    { tokens.push_back(TokenTable(yytext, "HEXADECIMAL LITERAL")); }
{OCTAL_LITERAL}    { tokens.push_back(TokenTable(yytext, "OCTAL LITERAL")); }
{DECIMAL_LITERAL}    { tokens.push_back(TokenTable(yytext, "DECIMAL LITERAL")); }
{CHARACTER_LITERAL}     { tokens.push_back(TokenTable(yytext, "CHARACTER LITERAL")); }
{EXP_LITERAL}    { tokens.push_back(TokenTable(yytext, "LITERAL")); }
{FLOAT_LITERAL}    { tokens.push_back(TokenTable(yytext, "FLOAT LITERAL")); }
{REAL_LITERAL}    { tokens.push_back(TokenTable(yytext, "REAL LITERAL")); }





{STRING_LITERAL} { tokens.push_back(TokenTable(yytext, "STRING_LITERAL")); }

{SINCMNT}       { tokens.push_back(TokenTable(yytext, "SINCMNT")); }
{MULCMNT}       { tokens.push_back(TokenTable(yytext, "MULCMNT")); }

{VARIABLE_ARGS} { tokens.push_back(TokenTable(yytext, "VARIABLE_ARGS")); }
{RIGHT_SHIFT_EQ} { tokens.push_back(TokenTable(yytext, "RIGHT_SHIFT_EQ")); }
{LEFT_SHIFT_EQ} { tokens.push_back(TokenTable(yytext, "LEFT_SHIFT_EQ")); }
{ASSIGN_PLUS}   { tokens.push_back(TokenTable(yytext, "ASSIGN_PLUS")); }
{ASSIGN_MINUS}  { tokens.push_back(TokenTable(yytext, "ASSIGN_MINUS")); }
{ASSIGN_STAR}   { tokens.push_back(TokenTable(yytext, "ASSIGN_STAR")); }
{ASSIGN_DIV}    { tokens.push_back(TokenTable(yytext, "ASSIGN_DIV")); }
{ASSIGN_MOD}    { tokens.push_back(TokenTable(yytext, "ASSIGN_MOD")); }
{ASSIGN_AND}    { tokens.push_back(TokenTable(yytext, "ASSIGN_AND")); }
{ASSIGN_OR}     { tokens.push_back(TokenTable(yytext, "ASSIGN_OR")); }
{ASSIGN_XOR}    { tokens.push_back(TokenTable(yytext, "ASSIGN_XOR")); }

{LEFT_SHIFT}    { tokens.push_back(TokenTable(yytext, "LEFT_SHIFT")); }
{RIGHT_SHIFT}   { tokens.push_back(TokenTable(yytext, "RIGHT_SHIFT")); }
{INCREMENT}     { tokens.push_back(TokenTable(yytext, "INCREMENT")); }
{DECREMENT}     { tokens.push_back(TokenTable(yytext, "DECREMENT")); }
{LAMBDA_ARROW}  { tokens.push_back(TokenTable(yytext, "LAMBDA_ARROW")); }

{REL_AND}       { tokens.push_back(TokenTable(yytext, "REL_AND")); }
{REL_OR}        { tokens.push_back(TokenTable(yytext, "REL_OR")); }
{LESS_EQUALS}   { tokens.push_back(TokenTable(yytext, "LESS_EQUALS")); }
{GREATER_EQUALS} { tokens.push_back(TokenTable(yytext, "GREATER_EQUALS")); }
{REL_EQUALS}    { tokens.push_back(TokenTable(yytext, "REL_EQUALS")); }
{REL_NOT_EQ}    { tokens.push_back(TokenTable(yytext, "REL_NOT_EQ")); }

{LBRACE}        { tokens.push_back(TokenTable(yytext, "LBRACE")); }
{RBRACE}        { tokens.push_back(TokenTable(yytext, "RBRACE")); }
{LBRACKET}      { tokens.push_back(TokenTable(yytext, "LBRACKET")); }
{RBRACKET}      { tokens.push_back(TokenTable(yytext, "RBRACKET")); }
{LPARENTHESES}  { tokens.push_back(TokenTable(yytext, "LPARENTHESES")); }
{RPARENTHESES}  { tokens.push_back(TokenTable(yytext, "RPARENTHESES")); }
{DOT}           { tokens.push_back(TokenTable(yytext, "DOT")); }
{COMMA}         { tokens.push_back(TokenTable(yytext, "COMMA")); }
{COLON}         { tokens.push_back(TokenTable(yytext, "COLON")); }
{SEMICOLON}     { tokens.push_back(TokenTable(yytext, "SEMICOLON")); }
{PLUS}          { tokens.push_back(TokenTable(yytext, "PLUS")); }
{MINUS}         { tokens.push_back(TokenTable(yytext, "MINUS")); }
{STAR}          { tokens.push_back(TokenTable(yytext, "STAR")); }
{DIVIDE}        { tokens.push_back(TokenTable(yytext, "DIVIDE")); }
{MODULO}        { tokens.push_back(TokenTable(yytext, "MODULO")); }
{AMPERSAND}     { tokens.push_back(TokenTable(yytext, "AMPERSAND")); }
{OR}            { tokens.push_back(TokenTable(yytext, "OR")); }
{XOR}           { tokens.push_back(TokenTable(yytext, "XOR")); }
{EXCLAMATION}   { tokens.push_back(TokenTable(yytext, "EXCLAMATION")); }
{TILDE}         { tokens.push_back(TokenTable(yytext, "TILDE")); }
{EQUALS}        { tokens.push_back(TokenTable(yytext, "EQUALS")); }
{LESS_THAN}     { tokens.push_back(TokenTable(yytext, "LESS_THAN")); }
{GREATER_THAN}  { tokens.push_back(TokenTable(yytext, "GREATER_THAN")); }
{QUESTION_MARK} { tokens.push_back(TokenTable(yytext, "QUESTION_MARK")); }


{INVALID_ID}        { error_call(yytext,0); tokens.push_back(TokenTable(yytext, "ERROR! INVALID IDENTIFIER"));}
.                   { error_call(yytext,1);tokens.push_back(TokenTable(yytext, "ERROR! INVALID TOKEN"));}    

%%


int main(int argc, char *argv[]) {
    // Check if both input and output file arguments are passed
    if (argc < 3) {
        cerr << "Error: Please provide an input file and an output file." << endl;
        return 1;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];

    // Open input file
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    // Ensure output directory exists
    system("mkdir -p output");

    // Open output file
    ofstream file(outputFileName);
    if (!file) {
        cerr << "Error creating output file: " << outputFileName << endl;
        return 1;
    }

    // Set yyin to read from the provided input file
    yyin = fopen(argv[1], "r");
    yylex(); // Perform lexical analysis

    file<<"Following errors were found in the source code\n";
    if (errors.empty())  // Use empty() for clarity, or errors.size() == 0
        {
    file << "NONE\n";
    file << "------------------------------------------\n";
    }
    else
    {
    for (const std::string& error : errors) // Use const reference to avoid unnecessary copies
    {
        file << error << std::endl;
        file << "------------------------------------------\n";
    }
    }
    file<<"Tokens generated are \n\n";
    // Print table headers with borders
    file << "+----------------+--------------------------+\n";
    file << "| Lexeme         | Token Type               |\n";
    file << "+----------------+--------------------------+\n";

    // Print tokens in table format
    for (const auto &token : tokens) {
        file << "| " << left << setw(15) << token.lexeme
             << "| " << left << setw(25) << token.token_type << "|\n";
        file << "+----------------+--------------------------+\n";
    }

    file.close();

    return 0;
}
