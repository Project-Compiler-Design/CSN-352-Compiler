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

    using namespace std;
    map<string,string> LexemetoToken;

%}

%option yylineno

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
STRING_KEYWORD  "string"

DELIM           [ \t\n]
WS              {DELIM}+
LETTER          [A-Za-z]
DIGIT           [0-9]
ID              ({LETTER}|_)({LETTER}|_|{DIGIT})*
INTEGER         {DIGIT}+
FLOAT           {DIGIT}+(\.{DIGIT}+)?
STRING          \"(\\.|[^"\\])*\"
CHARACTER       (L|u8|u|U)?'((\\.)|[^'\\])'
SINCMNT         \/\/.*
MULCMNT         /\/\*\_.\{-}\*\/

LBRACE         	"\}"
RBRACE          "\{"
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
DOUBLE_COLON   	"::"
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

%%

{BOOL}          { cout<<("BOOL")<<endl; LexemetoToken[yytext] = "BOOL"}
{BREAK}         { cout<<("BREAK")<<endl; LexemetoToken[yytext] = "BREAK"}
{CASE}          { cout<<("CASE")<<endl; LexemetoToken[yytext] = "CASE"}
{CONTINUE}      { cout<<("CONTINUE")<<endl; LexemetoToken[yytext] = "CONTINUE"}
{GOTO}          { cout<<("GOTO")<<endl; LexemetoToken[yytext] = "GOTO"}
{DO}            { cout<<("DO")<<endl; LexemetoToken[yytext] = "DO"}
{DEFAULT}       { cout<<("DEFAULT")<<endl; LexemetoToken[yytext] = "DEFAULT"}
{IF}            { cout<<("IF");<<endl  LexemetoToken[yytext] = "IF"}
{ELSE}          { cout<<("ELSE")<<endl; LexemetoToken[yytext] = "ELSE"}
{FOR}           { cout<<("FOR")<<endl; LexemetoToken[yytext] = "FOR"}
{CONST}         { cout<<("CONST")<<endl; LexemetoToken[yytext] = "CONST"}
{TRUE}          { cout<<("TRUE")<<endl; LexemetoToken[yytext] = "TRUE"}
{FALSE}         { cout<<("FALSE")<<endl; LexemetoToken[yytext] = "FALSE"}
{STATIC}        { cout<<("STATIC")<<endl; LexemetoToken[yytext] = "STATIC"}
{SWITCH}        { cout<<("SWITCH")<<endl; LexemetoToken[yytext] = "SWITCH"}
{WHILE}         { cout<<("WHILE")<<endl; LexemetoToken[yytext] = "WHILE"}
{VOID}          { cout<<("VOID")<<endl; LexemetoToken[yytext] = "VOID"}
{RETURN}        { cout<<("RETURN")<<endl; LexemetoToken[yytext] = "RETURN"}
{SIZEOF}        { cout<<("SIZEOF")<<endl; LexemetoToken[yytext] = "SIZEOF"}
{FLOAT}         { cout<<("FLOAT")<<endl; LexemetoToken[yytext] = "FLOAT"}
{INT}           { cout<<("INT")<<endl; LexemetoToken[yytext] = "INT"}
{DOUBLE}        { cout<<("DOUBLE")<<endl; LexemetoToken[yytext] = "DOUBLE"}
{EXTERN}        { cout<<("EXTERN")<<endl; LexemetoToken[yytext] = "EXTERN"}
{SHORT}         { cout<<("SHORT")<<endl; LexemetoToken[yytext] = "SHORT"}
{LONG}          { cout<<("LONG")<<endl; LexemetoToken[yytext] = "LONG"}
{CHAR}          { cout<<("CHAR")<<endl; LexemetoToken[yytext] = "CHAR"}
{STRING_KEYWORD} { cout<<("STRING_KEYWORD")<<endl; LexemetoToken[yytext] = "STRING_KEYWORD"}

{DELIM}         { cout<<("DELIM")<<endl; LexemetoToken[yytext] = "DELIM"}
{WS}            { cout<<("WS")<<endl; LexemetoToken[yytext] = "WS"}
{LETTER}        { cout<<("LETTER")<<endl; LexemetoToken[yytext] = "LETTER"}
{DIGIT}         { cout<<("DIGIT")<<endl; LexemetoToken[yytext] = "DIGIT"}
{ID}            { cout<<("ID")<<endl; LexemetoToken[yytext] = "ID"}
{INTEGER}       { cout<<("INTEGER")<<endl; LexemetoToken[yytext] = "INTEGER"}
{FLOAT}         { cout<<("FLOAT")<<endl; LexemetoToken[yytext] = "FLOAT"}
{STRING}        { cout<<("STRING")<<endl; LexemetoToken[yytext] = "STRING"}
{CHARACTER}     { cout<<("CHARACTER")<<endl; LexemetoToken[yytext] = "CHARACTER"}
{SINCMNT}       { cout<<("SINCMNT")<<endl; LexemetoToken[yytext] = "SINCMNT"}
{MULCMNT}       { cout<<("MULCMNT")<<endl; LexemetoToken[yytext] = "MULCMNT"}
{LBRACE}          { cout<<("LBRACE")<<endl; LexemetoToken[yytext] = "LBRACE"}

{RBRACE}        { cout<<("RBRACE")<<endl; LexemetoToken[yytext] = "RBRACE"}
{LBRACKET}      { cout<<("LBRACKET")<<endl; LexemetoToken[yytext] = "LBRACKET"}
{RBRACKET}      { cout<<("RBRACKET")<<endl; LexemetoToken[yytext] = "RBRACKET"}
{LPARENTHESES}  { cout<<("LPARENTHESES")<<endl; LexemetoToken[yytext] = "LPARENTHESES"}
{RPARENTHESES}  { cout<<("RPARENTHESES")<<endl; LexemetoToken[yytext] = "RPARENTHESES"}
{DOT}           { cout<<("DOT")<<endl; LexemetoToken[yytext] = "DOT"}
{COMMA}         { cout<<("COMMA")<<endl; LexemetoToken[yytext] = "COMMA"}
{COLON}         { cout<<("COLON")<<endl; LexemetoToken[yytext] = "COLON"}
{SEMICOLON}     { cout<<("SEMICOLON")<<endl; LexemetoToken[yytext] = "SEMICOLON"}
{PLUS}          { cout<<("PLUS")<<endl; LexemetoToken[yytext] = "PLUS"}
{MINUS}         { cout<<("MINUS")<<endl; LexemetoToken[yytext] = "MINUS"}
{STAR}          { cout<<("STAR")<<endl; LexemetoToken[yytext] = "STAR"}
{DIVIDE}        { cout<<("DIVIDE")<<endl; LexemetoToken[yytext] = "DIVIDE"}
{MODULO}        { cout<<("MODULO")<<endl; LexemetoToken[yytext] = "MODULO"}
{AMPERSAND}     { cout<<("AMPERSAND")<<endl; LexemetoToken[yytext] = "AMPERSAND"}
{OR}            { cout<<("OR")<<endl; LexemetoToken[yytext] = "OR"}
{XOR}           { cout<<("XOR")<<endl; LexemetoToken[yytext] = "XOR"}
{EXCLAMATION}   { cout<<("EXCLAMATION")<<endl; LexemetoToken[yytext] = "EXCLAMATION"}
{TILDE}         { cout<<("TILDE")<<endl; LexemetoToken[yytext] = "TILDE"}
{EQUALS}        { cout<<("EQUALS")<<endl; LexemetoToken[yytext] = "EQUALS"}
{LESS_THAN}     { cout<<("LESS_THAN")<<endl; LexemetoToken[yytext] = "LESS_THAN"}
{GREATER_THAN}  { cout<<("GREATER_THAN")<<endl; LexemetoToken[yytext] = "GREATER_THAN"}
{QUESTION_MARK} { cout<<("QUESTION_MARK")<<endl; LexemetoToken[yytext] = "QUESTION_MARK"}
{DOUBLE_COLON}  { cout<<("DOUBLE_COLON")<<endl; LexemetoToken[yytext] = "DOUBLE_COLON"}
{INCREMENT}     { cout<<("INCREMENT")<<endl; LexemetoToken[yytext] = "INCREMENT"}
{DECREMENT}     { cout<<("DECREMENT")<<endl; LexemetoToken[yytext] = "DECREMENT"}
{REL_AND}       { cout<<("REL_AND")<<endl; LexemetoToken[yytext] = "REL_AND"}
{REL_OR}        { cout<<("REL_OR")<<endl; LexemetoToken[yytext] = "REL_OR"}
{REL_EQUALS}    { cout<<("REL_EQUALS")<<endl; LexemetoToken[yytext] = "REL_EQUALS"}
{REL_NOT_EQ}    { cout<<("REL_NOT_EQ")<<endl; LexemetoToken[yytext] = "REL_NOT_EQ"}
{LESS_EQUALS}   { cout<<("LESS_EQUALS")<<endl; LexemetoToken[yytext] = "LESS_EQUALS"}
{GREATER_EQUALS} { cout<<("GREATER_EQUALS")<<endl; LexemetoToken[yytext] = "GREATER_EQUALS"}
{ASSIGN_PLUS}   { cout<<("ASSIGN_PLUS")<<endl; LexemetoToken[yytext] = "ASSIGN_PLUS"}
{ASSIGN_MINUS}  { cout<<("ASSIGN_MINUS")<<endl; LexemetoToken[yytext] = "ASSIGN_MINUS"}
{ASSIGN_STAR}   { cout<<("ASSIGN_STAR")<<endl; LexemetoToken[yytext] = "ASSIGN_STAR"}
{ASSIGN_DIV}    { cout<<("ASSIGN_DIV")<<endl; LexemetoToken[yytext] = "ASSIGN_DIV"}
{ASSIGN_MOD}    { cout<<("ASSIGN_MOD")<<endl; LexemetoToken[yytext] = "ASSIGN_MOD"}
{ASSIGN_AND}    { cout<<("ASSIGN_AND")<<endl; LexemetoToken[yytext] = "ASSIGN_AND"}
{ASSIGN_OR}     { cout<<("ASSIGN_OR")<<endl; LexemetoToken[yytext] = "ASSIGN_OR"}
{ASSIGN_XOR}    { cout<<("ASSIGN_XOR")<<endl; LexemetoToken[yytext] = "ASSIGN_XOR"}
{LEFT_SHIFT}    { cout<<("LEFT_SHIFT")<<endl; LexemetoToken[yytext] = "LEFT_SHIFT"}
{LEFT_SHIFT_EQ} { cout<<("LEFT_SHIFT_EQ")<<endl; LexemetoToken[yytext] = "LEFT_SHIFT_EQ"}
{RIGHT_SHIFT}   { cout<<("RIGHT_SHIFT")<<endl; LexemetoToken[yytext] = "RIGHT_SHIFT"}
{RIGHT_SHIFT_EQ} { cout<<("RIGHT_SHIFT_EQ")<<endl; LexemetoToken[yytext] = "RIGHT_SHIFT_EQ"}
{LAMBDA_ARROW}  { cout<<("LAMBDA_ARROW")<<endl; LexemetoToken[yytext] = "LAMBDA_ARROW"}
{VARIABLE_ARGS} { cout<<("VARIABLE_ARGS")<<endl; LexemetoToken[yytext] = "VARIABLE_ARGS"}
.               { error_call(yytext);}

%%

void error_call(string s){
    cout<<"Error! Invalid word: "<<s<<" in line no. "<<yylineno<<endl;
}

int main(){
    int num = yylex();

}





