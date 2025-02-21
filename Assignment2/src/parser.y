%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

	#define MAX_ARGS 100

    void yyerror(const char *s);
    int search_symtab(char *);
    void assign_type();

    extern int yylex();
    extern int yylineno;
    extern char *yytext;  // Fix for yytext undeclared error

    int count_sym = 0;
    int count_const = 0;

    char d_type[10];

    struct sym_tab {
        char identifier_name[50];  // Use a fixed-size array instead of pointer
        char datatype[50];
        char type[20];
        int lineno;
    };

    struct sym_tab symbol_table[100]; // Use an array instead of C++ vector

    struct const_tab {
        char constant_value[50];
        char constant_type[50];
        int lineno;
    };

    struct const_tab constant_table[100];

	struct ArgList {
    char *args[MAX_ARGS];
    int count_arg;
} argList;

    void insert_symtab(char c, char *yytext) {
        if (search_symtab(yytext) == 0) {
            strcpy(symbol_table[count_sym].identifier_name, yytext);
            symbol_table[count_sym].lineno = yylineno;

            if (c == 'H') {
                strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Header");
            }
            else if (c == 'K') {
                strcpy(symbol_table[count_sym].datatype, yytext);
                strcpy(symbol_table[count_sym].type, "Keyword");
            }
            else if (c == 'V') {
                strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Variable");
            }
            else if (c == 'C') {
                strcpy(symbol_table[count_sym].datatype, "CONST");
                strcpy(symbol_table[count_sym].type, "Constant");
            }
            else if (c == 'F') {
                strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Function");
            }
			else if(c=='G'){
				strcpy(symbol_table[count_sym].datatype, "GOTO");
                strcpy(symbol_table[count_sym].type, "Label");
			}
			else if(c=='P'){
				strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Pointer");
			}
			else if(c=='f'){
				strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Pointer");
			}
			else if(c=='E'){
				strcpy(symbol_table[count_sym].datatype, d_type);
                strcpy(symbol_table[count_sym].type, "Enum");
			}
            count_sym++;
        }
    }

    void insert_const_tab(char c, char *yytext) {
        
        strcpy(constant_table[count_const].constant_value, yytext);
        constant_table[count_const].lineno = yylineno;

        if (c == 'I') {
            strcpy(constant_table[count_const].constant_type, "Integer Constant");
        }
        else if (c == 'F') {
            strcpy(constant_table[count_const].constant_type, "Float Constant");
        }
        else if (c == 'E') {
            strcpy(constant_table[count_const].constant_type, "Exponential Constant");
        }
        else if (c == 'H') {
            strcpy(constant_table[count_const].constant_type, "Hexadecimal Constant");
        }
        else if (c == 'R') {
            strcpy(constant_table[count_const].constant_type, "Real Constant");
        }
        else if (c == 'S') {
            strcpy(constant_table[count_const].constant_type, "String Constant");
        }
        else if (c == 'O') {
            strcpy(constant_table[count_const].constant_type, "Octal Constant");
        }
        else if (c == 'C') {
            strcpy(constant_table[count_const].constant_type, "Character Constant");
        }
        count_const++;
        
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
	}
	else if (strcmp(type_spec, "void") == 0) {
        strcpy(type_str, "VOID");	
	}
	else if (strcmp(type_spec, "struct") == 0) {
        strcpy(type_str, "STRUCT");
	}
	else if (strcmp(type_spec, "enum") == 0) {
        strcpy(type_str, "ENUM");
	
    }
	else if (strcmp(type_spec, "union") == 0) {
        strcpy(type_str, "UNION");
	
    }
	 else {
        strcpy(type_str, type_spec);
    }
}



    void print_symbol_table() {
        printf("\nSYMBOL TABLE\n");
        printf("-----------------------------------------------------------------\n");
        printf("| %-15s | %-20s | %-10s | Line No |\n", "Identifier", "Type", "Data Type");
        printf("-----------------------------------------------------------------\n");
        for (int i = 0; i < count_sym; i++) {
            printf("| %-15s | %-20s | %-10s | %-7d |\n",
                   symbol_table[i].identifier_name,
                   symbol_table[i].type,
                   symbol_table[i].datatype,
                   symbol_table[i].lineno);
        }
        printf("-----------------------------------------------------------------\n");
    }

    void print_constant_table() {
        printf("\nConstant Table:\n");
        printf("-----------------------------------------------------\n");
        printf("| %-15s | %-20s | Line no. |\n", "Constant Value", "Constant Type");
        printf("-----------------------------------------------------\n");
        for (int i = 0; i < count_const; i++) {
            printf("| %-15s | %-20s | %-8d |\n",
                   constant_table[i].constant_value,
                   constant_table[i].constant_type, 
                   constant_table[i].lineno);
        }
        printf("-----------------------------------------------------\n");
    }

%}

%union {
    char *str;
}


%token <str> ID DECIMAL_LITERAL HEXA_LITERAL OCTAL_LITERAL EXP_LITERAL REAL_LITERAL FLOAT_LITERAL STRING_LITERAL CHARACTER_LITERAL INCLUDE INVALID_ID
%token AUTO STRUCT BOOL BREAK CASE CONTINUE GOTO DO DEFAULT IF ELSE FOR CONST TRUE FALSE STATIC SWITCH WHILE VOID RETURN SIZEOF FLOAT INT DOUBLE EXTERN SHORT LONG CHAR ENUM REGISTER SIGNED TYPEDEF UNION UNSIGNED VOLATILE 
%token CLASS PUBLIC PRIVATE PROTECTED NULLPTR NAMESPACE VIRTUAL CATCH
%token RBRACE LBRACE LBRACKET RBRACKET LPARENTHESES RPARENTHESES DOT COMMA COLON SEMICOLON PLUS MINUS STAR DIVIDE MODULO AMPERSAND OR XOR EXCLAMATION TILDE EQUALS LESS_THAN GREATER_THAN QUESTION_MARK INCREMENT DECREMENT REL_AND REL_OR REL_EQUALS REL_NOT_EQ LESS_EQUALS GREATER_EQUALS ASSIGN_PLUS ASSIGN_MINUS ASSIGN_STAR ASSIGN_DIV ASSIGN_MOD ASSIGN_AND ASSIGN_OR ASSIGN_XOR LEFT_SHIFT LEFT_SHIFT_EQ RIGHT_SHIFT RIGHT_SHIFT_EQ LAMBDA_ARROW VARIABLE_ARGS


%type <str> primary_expression postfix_expression argument_expression_list unary_expression 
%type <str> unary_operator cast_expression multiplicative_expression additive_expression 
%type <str> shift_expression relational_expression equality_expression and_expression 
%type <str> exclusive_or_expression inclusive_or_expression logical_and_expression 
%type <str> logical_or_expression conditional_expression assignment_expression 
%type <str> assignment_operator expression constant_expression declaration 
%type <str> declaration_specifiers init_declarator_list init_declarator 
%type <str> storage_class_specifier type_specifier struct_or_union_specifier 
%type <str> struct_or_union struct_declaration_list struct_declaration 
%type <str> specifier_qualifier_list struct_declarator_list struct_declarator 
%type <str> enum_specifier enumerator_list enumerator type_qualifier declarator 
%type <str> direct_declarator pointer type_qualifier_list parameter_type_list 
%type <str> parameter_list parameter_declaration identifier_list type_name 
%type <str> abstract_declarator direct_abstract_declarator initializer 
%type <str> initializer_list statement labeled_statement compound_statement 
%type <str> declaration_list statement_list expression_statement 
%type <str> selection_statement iteration_statement jump_statement 
%type <str> translation_unit external_declaration function_definition

%start translation_unit

%%
// program:
//     include_statements function_definitions
//     ;

// include_statements:
//     include_statements include_statement
//     | /* empty */
//     ;

// include_statement:
//     INCLUDE { printf("This is an include statement: %s\n", $1); }
//     | INCLUDE ID { printf("This is an include statement: %s\n", $1); }
//     ;

// function_definitions:
//     function_definitions function_definition
//     | 
//     ;

// function_definition:
//     type_specifier ID LPARENTHESES RPARENTHESES LBRACE statements RBRACE 
//     { printf("This is a function: %s\n", $2);
//       char type_str[10];
//       get_type_string(type_str,$1);
//       assign_type(type_str);
//       insert_symtab('F',$2); }
//     ;




// statements:
//     statements statement
//     | /* empty */
//     ;

// statement:
//     RETURN DECIMAL_LITERAL SEMICOLON { printf("Return statement with value %s\n", $2); }
//     | RETURN SEMICOLON { printf("Return statement without value\n"); }
//     | variable_declaration
//     | /* other statements */
//     ;

// variable_declaration:
//     type_specifier ID EQUALS constant SEMICOLON { 
        // char type_str[10];
        // get_type_string(type_str, $1);
        // printf("Variable declaration: %s = %s\n", $1, $2); 
        // assign_type(type_str);
        // insert_symtab('V', $2); 
//     }
//     ;

constant: 
    DECIMAL_LITERAL      { insert_const_tab('I', $1); }
    | FLOAT_LITERAL      { insert_const_tab('F', $1); }
    | EXP_LITERAL        { insert_const_tab('E', $1); }
    | HEXA_LITERAL       { insert_const_tab('H', $1); }
    | REAL_LITERAL       { insert_const_tab('R', $1); }
    | STRING_LITERAL     { insert_const_tab('S', $1); }
    | OCTAL_LITERAL      { insert_const_tab('O', $1); }
    | CHARACTER_LITERAL  { insert_const_tab('C', $1); }


primary_expression
	: ID			{ $$ = strdup($1); }
	| constant		
	| STRING_LITERAL {
        printf("This is a string literal: %s",$1);
    }
	| LPARENTHESES expression RPARENTHESES
	;

postfix_expression
	: primary_expression
	| postfix_expression LBRACKET expression RBRACKET
	| postfix_expression LPARENTHESES RPARENTHESES					{printf("Brackets found\n");}
	| postfix_expression LPARENTHESES argument_expression_list RPARENTHESES   
	{printf("Function call\n");
		for (int i = 0; i < argList.count_arg; i++) {
            printf("%s", argList.args[i]);
            if (i < argList.count_arg - 1) printf(", ");
        }
        printf("\n");
	}
	| postfix_expression DOT ID
	| postfix_expression LAMBDA_ARROW ID
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	;

argument_expression_list
    : assignment_expression
      { 
          if (argList.count_arg < MAX_ARGS) {
              argList.args[argList.count_arg++] = strdup($1);
          }
      }
    | argument_expression_list COMMA assignment_expression
      { 
          if (argList.count_arg < MAX_ARGS) {
              argList.args[argList.count_arg++] = strdup($3);
          }
      }
    ;

unary_expression
	: postfix_expression
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF LPARENTHESES type_name RPARENTHESES
	;

unary_operator
	: AMPERSAND
	| STAR
	| PLUS
	| MINUS
	| TILDE
	| EXCLAMATION
	;

cast_expression
	: unary_expression
	| LPARENTHESES type_name RPARENTHESES cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression STAR cast_expression
	| multiplicative_expression DIVIDE cast_expression
	| multiplicative_expression MODULO cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression PLUS multiplicative_expression
	| additive_expression MINUS multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_SHIFT additive_expression
	| shift_expression RIGHT_SHIFT additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression LESS_THAN shift_expression
	| relational_expression GREATER_THAN shift_expression
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
	| and_expression AMPERSAND equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression XOR and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression OR exclusive_or_expression
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
	| logical_or_expression QUESTION_MARK expression COLON conditional_expression
	;

assignment_expression
	: conditional_expression				
	{ 
		printf("conditional inside assignment = %s\n",$$);
		$$ = strdup($1);
	}
	| unary_expression assignment_operator assignment_expression {printf("Assignment expression = %s\n",$1);}
	;

assignment_operator
	: EQUALS
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
	| expression COMMA assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
    : declaration_specifiers SEMICOLON
    | declaration_specifiers init_declarator_list SEMICOLON 
    {
        printf("declaration  = %s\n", $2);
        char type_str[10];
        get_type_string(type_str, $1);

        // Tokenize the init_declarator_list to extract variable names
        char *token = strtok($2, ",");
        while (token != NULL) {
            char *var_name = token;
            char *value = strchr(token, '=');

            if (value) {
                *value = '\0';  // Split variable name from value
                value++;  // Move to actual value
            }

            assign_type(type_str);

            // Count '*' characters to determine pointer level
            int pointer_level = 0;
            while (*var_name == '*') {
                pointer_level++;
                var_name++;  // Move past '*'
            }
			assign_type(type_str);
            if (pointer_level > 0) {
                insert_symtab('P',var_name);
            } else {
                insert_symtab('V',var_name);
            }

            token = strtok(NULL, ",");
        }
    }
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
    : init_declarator { 
        $$ = strdup($1);  
        printf("init_declarator = %s\n", $$);
    }
    | init_declarator_list COMMA init_declarator { 
        $$ = malloc(strlen($1) + strlen($3) + 2); 
        sprintf($$, "%s,%s", $1, $3);  
        free($1); free($3);
        printf("init_declarator_list = %s\n", $$);
    }
    ;

init_declarator
    : declarator { 
        $$ = strdup($1); 
        printf("declarator = %s\n", $$);
    }
    | declarator EQUALS initializer { 
        $$ = malloc(strlen($1) + strlen($3) + 2);  
        sprintf($$, "%s=%s", $1, $3);  
        free($1); free($3);
        printf("init_declarator with initializer = %s\n", $$);
    }
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
	| CHAR				{printf("Character\n");}
	| SHORT
	| INT				{printf("Integer\n");}
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
	: struct_or_union ID LBRACE struct_declaration_list RBRACE 
	{
		char type_str[10];
        get_type_string(type_str, $1);
        printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        insert_symtab('V', $2); 
	}
	| struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union ID 
	
	{
		char type_str[10];
        get_type_string(type_str, $1);
        printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        insert_symtab('V', $2); 
	}
	

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMICOLON      
	{ 
		printf("Struct declaration %s = %s\n",$1,$2);
		char type_str[10];
        get_type_string(type_str, $1);
        
        assign_type(type_str);
        insert_symtab('V', $2); 
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA struct_declarator
	;

struct_declarator
	: declarator        {printf("Struct declarator = %s\n",$1);}
	| COLON constant_expression
	| declarator COLON constant_expression
	;

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM ID LBRACE enumerator_list RBRACE 
	{
		printf("enum is here = %s\n",$$);
		char type_str[10];
      	get_type_string(type_str,$$);
      	assign_type(type_str);
      	insert_symtab('V',$2);
	}
	| ENUM ID
	;

enumerator_list
	: enumerator
	| enumerator_list COMMA enumerator
	;

enumerator
	: ID
	| ID EQUALS constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
    : pointer direct_declarator { 
		printf("Pointer direct declarator\n");
        $$ = malloc(strlen($1) + strlen($2) + 1); 
        sprintf($$, "%s%s", $1, $2); 
		printf("it is $$: %s\n",$$); 
        free($1); free($2);
    }
    | direct_declarator { 
        $$ = strdup($1);  
		printf("Direct declarator %s\n",$$);
    }
    ;

direct_declarator
	: ID                {printf("Identifier in direct declaratorrr = %s\n",$1);}
	| LPARENTHESES declarator RPARENTHESES			
	{ 
		printf("LPar declarator RPar= %s\n",$2);
		$$=strdup($2);
	}
	| direct_declarator LBRACKET constant_expression RBRACKET
	| direct_declarator LBRACKET RBRACKET								{printf("Array\n");}
	| direct_declarator LPARENTHESES parameter_type_list RPARENTHESES     {printf("Brackets found with parameter= %s\n",$1);}
	| direct_declarator LPARENTHESES identifier_list RPARENTHESES          {printf("Brackets found\n");}
	| direct_declarator LPARENTHESES RPARENTHESES 						{printf("Brackets found\n");}
	;

pointer
	: STAR { $$ = strdup("*"); }
	| STAR type_qualifier_list
	| STAR pointer   
	{ 
        $$ = malloc(strlen($2) + 2); 
        sprintf($$, "*%s", $2);  
        free($2);
    }
	| STAR type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list COMMA VARIABLE_ARGS
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator  
	{
		// char type_str[10];
        // get_type_string(type_str, $1);
        // printf("Variable declaration: %s = %s\n", $1, $2); 
        // assign_type(type_str);
        // insert_symtab('V', $2);
		char type_str[10];
        get_type_string(type_str, $1);

        // Tokenize the init_declarator_list to extract variable names
        char *token = strtok($2, ",");
        while (token != NULL) {
            char *var_name = token;
            char *value = strchr(token, '=');

            if (value) {
                *value = '\0';  // Split variable name from value
                value++;  // Move to actual value
            }

            assign_type(type_str);

            // Count '*' characters to determine pointer level
            int pointer_level = 0;
            while (*var_name == '*') {
                pointer_level++;
                var_name++;  // Move past '*'
            }
			assign_type(type_str);
            if (pointer_level > 0) {
                insert_symtab('f',var_name);
            } else {
                insert_symtab('V',var_name);
            }

            token = strtok(NULL, ",");
        } 
	}
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID				{printf("Identifier in list = %s",$1);}
	| identifier_list COMMA ID
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
	: LPARENTHESES abstract_declarator RPARENTHESES
	| LBRACKET RBRACKET
	| LBRACKET constant_expression RBRACKET
	| direct_abstract_declarator LBRACKET RBRACKET
	| direct_abstract_declarator LBRACKET constant_expression RBRACKET
	| LPARENTHESES RPARENTHESES											{printf("Brackets found\n");}
	| LPARENTHESES parameter_type_list RPARENTHESES
	| direct_abstract_declarator LPARENTHESES RPARENTHESES         {printf("Brackets found\n");}
	| direct_abstract_declarator LPARENTHESES parameter_type_list RPARENTHESES
	;

initializer
	: assignment_expression
	| LBRACE initializer_list RBRACE
	| LBRACE initializer_list COMMA RBRACE
	;

initializer_list
	: initializer
	| initializer_list COMMA initializer
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
	: ID COLON statement
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	;

compound_statement
	: LBRACE RBRACE
	| LBRACE statement_declaration_list RBRACE
	| LBRACE statement_list RBRACE
	| LBRACE declaration_list RBRACE
	| LBRACE declaration_list statement_list RBRACE
	;

statement_declaration_list
	: statement_list statement_declaration_list
	| declaration_list statement_declaration_list
	| statement_list
	| declaration_list
	;

declaration_list
	: declaration
	| declaration_list declaration
	| error SEMICOLON {yyerrok;}
	;

statement_list
	: statement
	| statement_list statement
	| error SEMICOLON {yyerrok;}
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON   {printf("Expression semicolon\n");}
	;

selection_statement
	: IF LPARENTHESES expression RPARENTHESES statement
	| IF LPARENTHESES expression RPARENTHESES statement ELSE statement      {printf("It is in if-else block\n");}
	| SWITCH LPARENTHESES expression RPARENTHESES statement					{printf("It is in switch block\n");}
	;

iteration_statement
	: WHILE LPARENTHESES expression RPARENTHESES statement
	| DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON
	| FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement
	| FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement    {printf("For loop\n");}
	;

jump_statement
	: GOTO ID SEMICOLON				
	{ 
		printf("Goto statement: %s\n",$2);
		
      	insert_symtab('G',$2);
		

	}
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation_unit
	: external_declaration 				{printf("Reached the root node.\n");}
	| translation_unit external_declaration {printf("Reached the root node.\n");}
	| 
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement    
	{printf("Function is there: %s %s\n",$1,$2);
		char type_str[10];
      	get_type_string(type_str,$1);
      	assign_type(type_str);
      	insert_symtab('F',$2);
	}
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;
%%

void yyerror(const char *s) {
    
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

int search_symtab(char *id_name) {
	
	for(int i=count_sym-1; i>=0; i--) {
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
    print_constant_table();



}
