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


primary_expression
	: ID
	| constant
	| STRING_LITERAL {
        printf("This is a string literal: %s",$1);
    }
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' ID
	| postfix_expression LAMBDA_ARROW ID
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_SHIFT additive_expression
	| shift_expression RIGHT_SHIFT additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LESS_EQUALS shift_expression
	| relational_expression GREATER_EQUALS shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression REL_EQUALS relational_expression
	| equality_expression REL_NOT_EQ relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression REL_AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression REL_OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| ASSIGN_STAR
	| ASSIGN_DIV
	| ASSIGN_MOD
	| ASSIGN_PLUS
	| ASSIGN_MINUS
	| LEFT_SHIFT_EQ
	| RIGHT_SHIFT_EQ
	| ASSIGN_AND
	| ASSIGN_XOR
	| ASSIGN_OR
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	// | TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union ID '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union ID

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM ID '{' enumerator_list '}'
	| ENUM ID
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: ID
	| ID '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: ID
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' VARIABLE_ARGS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID
	| identifier_list ',' ID
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: ID ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO ID ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;
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


int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    freopen(argv[1], "r", stdin);
    yyparse();
    print_symbol_table();




}
