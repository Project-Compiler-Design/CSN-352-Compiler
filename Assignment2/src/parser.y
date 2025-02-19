%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    int search_symtab(char *);
    void assign_type();

    extern int yylex();
    extern int yylineno;
    extern char *yytext;  // Fix for yytext undeclared error

    int count = 0;
    char d_type[10];

    struct sym_tab {
        char identifier_name[50];  // Use a fixed-size array instead of pointer
        char datatype[50];
        char type[20];
        int lineno;
    };

    struct sym_tab symbol_table[100]; // Use an array instead of C++ vector

    void insert_symtab(char c, char *yytext) {
        if (search_symtab(yytext) == 0) {
            strcpy(symbol_table[count].identifier_name, yytext);
            symbol_table[count].lineno = yylineno;

            if (c == 'H') {
                strcpy(symbol_table[count].datatype, d_type);
                strcpy(symbol_table[count].type, "Header");
            }
            else if (c == 'K') {
                strcpy(symbol_table[count].datatype, yytext);
                strcpy(symbol_table[count].type, "Keyword");
            }
            else if (c == 'V') {
                strcpy(symbol_table[count].datatype, d_type);
                strcpy(symbol_table[count].type, "Variable");
            }
            else if (c == 'C') {
                strcpy(symbol_table[count].datatype, "CONST");
                strcpy(symbol_table[count].type, "Constant");
            }
            else if (c == 'F') {
                strcpy(symbol_table[count].datatype, d_type);
                strcpy(symbol_table[count].type, "Function");
            }
            count++;
        }
    }

    
    void get_type_string(char *type_str, char *type_spec) {
    if (strcmp(type_spec, "int") == 0) {
        strcpy(type_str, "INT");
    } else if (strcmp(type_spec, "float") == 0) {
        strcpy(type_str, "FLOAT");
    } else if (strcmp(type_spec, "double") == 0) {
        strcpy(type_str, "DOUBLE");
    } else if (strcmp(type_spec, "char") == 0) {
        strcpy(type_str, "CHAR");
    } else if (strcmp(type_spec, "long") == 0) {
        strcpy(type_str, "LONG");
    } else {
        strcpy(type_str, "UNKNOWN");
    }
}



    void print_symbol_table() {
        printf("\nSYMBOL TABLE\n");
        printf("------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-10s | Line No |\n", "Identifier", "Type", "Data Type");
        printf("------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("| %-15s | %-10s | %-10s | %-7d |\n",
                   symbol_table[i].identifier_name,
                   symbol_table[i].type,
                   symbol_table[i].datatype,
                   symbol_table[i].lineno);
        }
        printf("------------------------------------------------------\n");
    }

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
    type_specifier ID LPARENTHESES RPARENTHESES LBRACE statements RBRACE 
    { printf("This is a function: %s\n", $2);
      char type_str[10];
      get_type_string(type_str,$1);
      assign_type(type_str);
      insert_symtab('F',$2); }
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
        char type_str[10];
        get_type_string(type_str, $1);
        printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        insert_symtab('V', $2); 
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

int search_symtab(char *id_name) {
	
	for(int i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].identifier_name, id_name)==0) {
			return 1;
			break;
		}
	}
	return 0;
}

void assign_type(char *str) {
	strcpy(d_type, str);
}


int main() {
    yyparse();
    print_symbol_table();




}
