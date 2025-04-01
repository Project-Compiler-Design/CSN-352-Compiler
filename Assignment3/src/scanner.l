%option noyywrap
%{
    #include "parser.tab.h"
    #include "utility.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylineno;
    extern int yylex();
    extern YYSTYPE yylval;

    #define MAX_ERRORS 100  

    char *errors[MAX_ERRORS];  
    int error_count = 0;       

    void error_call(const char *s, int t) {
        if (error_count >= MAX_ERRORS) {
            fprintf(stderr, "Error buffer full!\n");
            return;
        }

        char buffer[256];  
        if (t == 0) {
            snprintf(buffer, sizeof(buffer), "Invalid identifier: %s in line no. %d", s, yylineno);
        } else {
            snprintf(buffer, sizeof(buffer), "Invalid token: %s in line no. %d", s, yylineno);
        }

        errors[error_count] = strdup(buffer);  
        error_count++;
    }
%}

%option yylineno

DELIM           [ \t\n\r]
WS              {DELIM}+

INCLUDE         "#include"[ \t]*("<"[^">"]+">"|"\""[^\"]+"\"")
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

CLASS           "class"
PUBLIC          "public"
PRIVATE         "private"
PROTECTED       "protected"
NULLPTR         "nullptr"
NAMESPACE       "namespace"
VIRTUAL         "virtual"
CATCH           "catch"

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
LBRACKET        "\["
RBRACKET       	"\]"
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
{WS}               {}
{INCLUDE}          {yylval.str = strdup(yytext); return INCLUDE; }
{AUTO}             { yylval.str = strdup(yytext); return AUTO; }
{STRUCT}           { yylval.str = strdup(yytext); return STRUCT; }
{BOOL}             { yylval.str = strdup(yytext); return BOOL; }
{BREAK}            { yylval.str = strdup(yytext); return BREAK; }
{CASE}             { yylval.str = strdup(yytext); return CASE; }
{CONTINUE}         { yylval.str = strdup(yytext); return CONTINUE; }
{GOTO}             { yylval.str = strdup(yytext); return GOTO; }
{DO}               { yylval.str = strdup(yytext); return DO; }
{DEFAULT}          { yylval.str = strdup(yytext); return DEFAULT; }
{IF}               { yylval.str = strdup(yytext); return IF; }
{ELSE}             { yylval.str = strdup(yytext); return ELSE; }
{FOR}              { yylval.str = strdup(yytext); return FOR; }
{CONST}            { yylval.str = strdup(yytext); return CONST; }
{TRUE}             { yylval.str = strdup(yytext); return TRUE; }
{FALSE}            { yylval.str = strdup(yytext); return FALSE; }
{STATIC}           { yylval.str = strdup(yytext); return STATIC; }
{SWITCH}           { yylval.str = strdup(yytext); return SWITCH; }
{WHILE}            { yylval.str = strdup(yytext); return WHILE; }
{VOID}             { yylval.str = strdup(yytext); return VOID; }
{RETURN}           { yylval.str = strdup(yytext); return RETURN; }
{SIZEOF}           { yylval.str = strdup(yytext); return SIZEOF; }
{FLOAT}            { yylval.str = strdup(yytext); return FLOAT; }
{INT}              { yylval.str = strdup(yytext); return INT; }
{DOUBLE}           { yylval.str = strdup(yytext); return DOUBLE; }
{EXTERN}           { yylval.str = strdup(yytext); return EXTERN; }
{SHORT}            { yylval.str = strdup(yytext); return SHORT; }
{LONG}             { yylval.str = strdup(yytext); return LONG; }
{CHAR}             { yylval.str = strdup(yytext); return CHAR; }
{ENUM}             { yylval.str = strdup(yytext); return ENUM; }
{REGISTER}         { yylval.str = strdup(yytext); return REGISTER; }
{SIGNED}           { yylval.str = strdup(yytext); return SIGNED; }
{TYPEDEF}          { yylval.str = strdup(yytext); return TYPEDEF; }
{UNION}            { yylval.str = strdup(yytext); return UNION; }
{UNSIGNED}         { yylval.str = strdup(yytext); return UNSIGNED; }
{VOLATILE}         { yylval.str = strdup(yytext); return VOLATILE; }
{CLASS}            { yylval.str = strdup(yytext); return CLASS; }
{PUBLIC}           { yylval.str = strdup(yytext); return PUBLIC; }
{PRIVATE}          { yylval.str = strdup(yytext); return PRIVATE; }
{PROTECTED}        { yylval.str = strdup(yytext); return PROTECTED; }
{NULLPTR}          { yylval.str = strdup(yytext); return NULLPTR; }
{NAMESPACE}        { yylval.str = strdup(yytext); return NAMESPACE; }
{VIRTUAL}          { yylval.str = strdup(yytext); return VIRTUAL; }
{CATCH}            { yylval.str = strdup(yytext); return CATCH; }



{ID}               { yylval.str = strdup(yytext); return ID; }
{HEXA_LITERAL}     { yylval.str = strdup(yytext); return HEXA_LITERAL; }
{OCTAL_LITERAL}    { yylval.str = strdup(yytext); return OCTAL_LITERAL; }
{DECIMAL_LITERAL}  { yylval.symbol_info = new symbol_info();
    yylval.symbol_info->type = "int";
    yylval.symbol_info->ptr = new int(atoi(yytext));
    yylval.symbol_info->symbol_size=4;
    return DECIMAL_LITERAL; }
{EXP_LITERAL}      { yylval.str = strdup(yytext); return EXP_LITERAL; }
{FLOAT_LITERAL}    { yylval.symbol_info = new symbol_info();
    yylval.symbol_info->type = "float";
    yylval.symbol_info->ptr = new float(atof(yytext));
    yylval.symbol_info->symbol_size=4;
    return FLOAT_LITERAL; }
{STRING_LITERAL}   {  yylval.symbol_info = new symbol_info();
    yylval.symbol_info->type = "string";
    yylval.symbol_info->str_val= strdup(yytext);
    yylval.symbol_info->symbol_size=strlen(yytext);
    return STRING_LITERAL; }
{CHARACTER_LITERAL} { yylval.symbol_info = new symbol_info();
    yylval.symbol_info->type = "char";
    char* temp = strdup(yytext);
    yylval.symbol_info->ptr = new char(temp[1]);
    yylval.symbol_info->str_val = std::string(temp + 1); 
    yylval.symbol_info->symbol_size=1; return CHARACTER_LITERAL; free(temp);}
{REAL_LITERAL}     { yylval.str = strdup(yytext); return REAL_LITERAL; }
{SINCMNT}          { /* ignore single-line comment */ }
{MULCMNT}          { /* ignore multi-line comment */ }


{RBRACE}           { return RBRACE; }
{LBRACE}           { return LBRACE; }
{LBRACKET}         { return LBRACKET; }
{RBRACKET}         { return RBRACKET; }
{LPARENTHESES}     { return LPARENTHESES; }
{RPARENTHESES}     { return RPARENTHESES; }
{DOT}              { return DOT; }
{COMMA}            { return COMMA; }
{COLON}            { return COLON; }
{SEMICOLON}        { return SEMICOLON; }
{PLUS}             { return PLUS; }
{MINUS}            { return MINUS; }
{STAR}             { return STAR; }
{DIVIDE}           { return DIVIDE; }
{MODULO}           { return MODULO; }
{AMPERSAND}        { return AMPERSAND; }
{OR}               { return OR; }
{XOR}              { return XOR; }
{EXCLAMATION}      { return EXCLAMATION; }
{TILDE}            { return TILDE; }
{EQUALS}           { return EQUALS; }
{LESS_THAN}        { return LESS_THAN; }
{GREATER_THAN}     { return GREATER_THAN; }
{QUESTION_MARK}    { return QUESTION_MARK; }
{INCREMENT}        { return INCREMENT; }
{DECREMENT}        { return DECREMENT; }
{REL_AND}          { return REL_AND; }
{REL_OR}           { return REL_OR; }
{REL_EQUALS}       { return REL_EQUALS; }
{REL_NOT_EQ}       { return REL_NOT_EQ; }
{LESS_EQUALS}      { return LESS_EQUALS; }
{GREATER_EQUALS}   { return GREATER_EQUALS; }
{ASSIGN_PLUS}      { return ASSIGN_PLUS; }
{ASSIGN_MINUS}     { return ASSIGN_MINUS; }
{ASSIGN_STAR}      { return ASSIGN_STAR; }
{ASSIGN_DIV}       { return ASSIGN_DIV; }
{ASSIGN_MOD}       { return ASSIGN_MOD; }
{ASSIGN_AND}       { return ASSIGN_AND; }
{ASSIGN_OR}        { return ASSIGN_OR; }
{ASSIGN_XOR}       { return ASSIGN_XOR; }
{LEFT_SHIFT}       { return LEFT_SHIFT; }
{LEFT_SHIFT_EQ}    { return LEFT_SHIFT_EQ; }
{RIGHT_SHIFT}      { return RIGHT_SHIFT; }
{RIGHT_SHIFT_EQ}   { return RIGHT_SHIFT_EQ; }
{LAMBDA_ARROW}     { return LAMBDA_ARROW; }
{VARIABLE_ARGS}    { return VARIABLE_ARGS; }

{INVALID_ID}       { fprintf(stderr, "Invalid identifier: %s at line %d\n", yytext, yylineno); return INVALID_ID; }

.                  { fprintf(stderr, "Invalid token: %s at line %d\n", yytext, yylineno); return yytext[0]; }    

%%

