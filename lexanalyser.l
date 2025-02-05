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

BOOL			"bool"
BREAK         	"break"
CASE           	"case"
CONTINUE       	"continue"
GOTO           	"goto"
DO             	"do"
DEFAULT        	"default "
IF             	"if"
ELSE           	"else"
FOR            	"for "
CONST          	"const"
TRUE           	"true"
FALSE          	"false"
STATIC         	"static"
SWITCH         	"switch"
WHILE          	"while"
VOID           	"void "
RETURN          "return "
SIZEOF         	"sizeof"
FLOAT          	"float"
INT       	    "int"
DOUBLE         	"double"
EXTERN         	"extern "
SHORT          	"short"
LONG           	"long"
CHAR            "char"
STRING_KEYWORD  "string"

DELIM	 		[ \t\n]
WS	 			{DELIM}+
LETTER	 		[A-Za-z]
DIGIT    		[0-9]
ID	 			({LETTER}|_)({LETTER}|_|{DIGIT})*
INTEGER	 		{DIGIT}+
FLOAT    		{DIGIT}+(\.{DIGIT}+)?
STRING   		\"(\\.|[^"\\])*\"
CHARACTER     	(L|u8|u|U)?'((\\.)|[^'\\])'
SINCMNT  		\/\/.*
MULCMNT  		/\/\*\_.\{-}\*\/

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
MODULO         	"%	"
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
{STRING_KEYWORD}{ cout<<("STRING_KEYWORD")<<endl; LexemetoToken[yytext] = "STRING_KEYWORD"}

%%







