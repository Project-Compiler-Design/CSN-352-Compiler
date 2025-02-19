%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    
    extern int yylex();
    extern int yylineno;

    // int count=0;

    // struct sym_tab{
    //     char *identifier_name;
    //     char *datatype;
    //     char *type;
    //     int lineno;

    //     sym_tab(char c, char *yytext, char *datatype){
    //         identifier_name=strdup(yytext);
            
            
    //     }
    // } symbol_table[40];



%}

%union {
    char *str;
}


%token <str> ID DECIMAL_LITERAL HEXA_LITERAL OCTAL_LITERAL EXP_LITERAL REAL_LITERAL FLOAT_LITERAL STRING_LITERAL CHARACTER_LITERAL INCLUDE INVALID_ID
%token AUTO STRUCT BOOL BREAK CASE CONTINUE GOTO DO DEFAULT IF ELSE FOR CONST TRUE FALSE STATIC SWITCH WHILE VOID RETURN SIZEOF FLOAT INT DOUBLE EXTERN SHORT LONG CHAR ENUM REGISTER SIGNED TYPEDEF UNION UNSIGNED VOLATILE 

%token RBRACE LBRACE LBRACKET RBRACKET LPARENTHESES RPARENTHESES DOT COMMA COLON SEMICOLON PLUS MINUS STAR DIVIDE MODULO AMPERSAND OR XOR EXCLAMATION TILDE EQUALS LESS_THAN GREATER_THAN QUESTION_MARK INCREMENT DECREMENT REL_AND REL_OR REL_EQUALS REL_NOT_EQ LESS_EQUALS GREATER_EQUALS ASSIGN_PLUS ASSIGN_MINUS ASSIGN_STAR ASSIGN_DIV ASSIGN_MOD ASSIGN_AND ASSIGN_OR ASSIGN_XOR LEFT_SHIFT LEFT_SHIFT_EQ RIGHT_SHIFT RIGHT_SHIFT_EQ LAMBDA_ARROW VARIABLE_ARGS

%type <str> expression statement declaration type_specifier program

%%
program:
    include_statements function_definitions
    ;

include_statements:
    include_statements include_statement
    | /* empty */
    ;

include_statement:
    INCLUDE { printf("This is an include statement: %s\n", $1); }
    | INCLUDE ID { printf("This is an include statement: %s\n", $1); }
    ;

function_definitions:
    function_definitions function_definition
    | 
    ;

function_definition:
    type_specifier ID LPARENTHESES RPARENTHESES LBRACE statements RBRACE { printf("This is a function: %s\n", $2); }
    ;

type_specifier:
    INT
    | FLOAT
    | DOUBLE
    | CHAR
    | LONG
    ;

statements:
    statements statement
    | /* empty */
    ;

statement:
    RETURN DECIMAL_LITERAL SEMICOLON { printf("Return statement with value %s\n", $2); }
    | RETURN SEMICOLON { printf("Return statement without value\n"); }
    | variable_declaration
    | /* other statements */
    ;

variable_declaration:
    type_specifier ID EQUALS constant SEMICOLON { 
        printf("Variable declaration: %s = %s\n", $1, $2); 
    }
    ;

constant: 
    DECIMAL_LITERAL
    | FLOAT_LITERAL
    | EXP_LITERAL
    | HEXA_LITERAL
    | REAL_LITERAL
    | STRING_LITERAL
    | OCTAL_LITERAL
    | CHARACTER_LITERAL

%%

void yyerror(const char *s) {
    
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

// int search(char *id_name) {
	
// 	for(int i=count-1; i>=0; i--) {
// 		if(strcmp(symbol_table[i].identifier_name, id_name)==0) {
// 			return -1;
// 			break;
// 		}
// 	}
// 	return 0;
// }

int main() {
    return yyparse();
}
