%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    extern int yylex();
    extern int yylineno;
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
    statement
    | program statement
    ;

statement:
    declaration SEMICOLON
    | expression SEMICOLON
    | RETURN expression SEMICOLON
    | IF LPARENTHESES expression RPARENTHESES statement ELSE statement
    | IF LPARENTHESES expression RPARENTHESES statement
    | WHILE LPARENTHESES expression RPARENTHESES statement
    | FOR LPARENTHESES declaration SEMICOLON expression SEMICOLON expression RPARENTHESES statement
    | LBRACE program RBRACE
    ;

declaration:
    type_specifier ID
    | type_specifier ID EQUALS expression
    ;

expression:
    ID
    | DECIMAL_LITERAL
    | HEXA_LITERAL
    | OCTAL_LITERAL
    | EXP_LITERAL
    | REAL_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | CHARACTER_LITERAL
    | expression PLUS expression
    | expression MINUS expression
    | expression STAR expression
    | expression DIVIDE expression
    | expression MODULO expression
    | LPARENTHESES expression RPARENTHESES
    ;

type_specifier:
    INT | FLOAT | DOUBLE | CHAR | VOID
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

int main() {
    return yyparse();
}
