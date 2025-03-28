%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include<iostream>
    #include<map>
    #include<vector>
	#include<stack>

	#include "symbol_table.h"
    using namespace std;

	#define MAX_ARGS 100

    void yyerror(const char *s);
    int search_symtab(char *);

    extern int yylex();
    extern int yylineno;
    extern char *yytext;  

    int count_sym = 0;
    int count_const = 0;

    char d_type[10];
    void assign_type(char *str) {
	    strcpy(d_type, str);
    }

	stack<string> parsing_stack;

    struct sym_tab {
        char identifier_name[50]; 
        char datatype[50];
        char type[20];
        int lineno;
    };

    struct sym_tab symbol_table[100]; 

    struct scoped_symtab;

    

    struct scoped_symtab{
        scoped_symtab* parent = nullptr;
        std::map<string,symbol_info*> symbol_map;
        std::vector<scoped_symtab*> child_list; 
    };

    scoped_symtab* curr_scope = new scoped_symtab();


	



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
		else if (strcmp(type_spec, "unknown") == 0) {
            strcpy(type_str, "UNKNOWN");
        
        }
        else {
            strcpy(type_str, "UNKNOWN");
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
        printf("-----------------------------------------------------------------\n");
        printf("| %-27s | %-20s | Line no. |\n", "Constant Value", "Constant Type");
        printf("-----------------------------------------------------------------\n");
        for (int i = 0; i < count_const; i++) {
            printf("| %-27s | %-20s | %-8d |\n",
                   constant_table[i].constant_value,
                   constant_table[i].constant_type, 
                   constant_table[i].lineno);
        }
        printf("-----------------------------------------------------------------\n");
    }

%}

%union {
    char* str;  // For type_specifier, declarator
    struct symbol_info* symbol_info; // For expressions and constants
}


%token <symbol_info> DECIMAL_LITERAL HEXA_LITERAL OCTAL_LITERAL EXP_LITERAL REAL_LITERAL FLOAT_LITERAL STRING_LITERAL CHARACTER_LITERAL 
%token <str> ID INVALID_ID INCLUDE
%token AUTO STRUCT BOOL BREAK CASE CONTINUE GOTO DO DEFAULT IF ELSE FOR CONST TRUE FALSE STATIC SWITCH WHILE VOID RETURN SIZEOF FLOAT INT DOUBLE EXTERN SHORT LONG CHAR ENUM REGISTER SIGNED TYPEDEF UNION UNSIGNED VOLATILE 
%token CLASS PUBLIC PRIVATE PROTECTED NULLPTR NAMESPACE VIRTUAL CATCH
%token RBRACE LBRACE LBRACKET RBRACKET LPARENTHESES RPARENTHESES DOT COMMA COLON SEMICOLON PLUS MINUS STAR DIVIDE MODULO AMPERSAND OR XOR EXCLAMATION TILDE EQUALS LESS_THAN GREATER_THAN QUESTION_MARK INCREMENT DECREMENT REL_AND REL_OR REL_EQUALS REL_NOT_EQ LESS_EQUALS GREATER_EQUALS ASSIGN_PLUS ASSIGN_MINUS ASSIGN_STAR ASSIGN_DIV ASSIGN_MOD ASSIGN_AND ASSIGN_OR ASSIGN_XOR LEFT_SHIFT LEFT_SHIFT_EQ RIGHT_SHIFT RIGHT_SHIFT_EQ LAMBDA_ARROW VARIABLE_ARGS


%type <symbol_info> primary_expression postfix_expression argument_expression_list unary_expression 
%type <symbol_info> unary_operator cast_expression multiplicative_expression additive_expression 
%type <symbol_info> shift_expression relational_expression equality_expression and_expression 
%type <symbol_info> exclusive_or_expression inclusive_or_expression logical_and_expression 
%type <symbol_info> logical_or_expression conditional_expression assignment_expression 
%type <symbol_info> assignment_operator expression constant_expression declaration 
%type <symbol_info> constant

%type <symbol_info> init_declarator init_declarator_list

%type <symbol_info> struct_or_union struct_declaration_list struct_declaration 
%type <symbol_info> specifier_qualifier_list struct_declarator_list struct_declarator 
%type <symbol_info> enumerator_list enumerator declarator 
%type <symbol_info> direct_declarator pointer type_qualifier_list parameter_type_list 
%type <symbol_info> parameter_list parameter_declaration identifier_list type_name 
%type <symbol_info> abstract_declarator direct_abstract_declarator initializer 
%type <symbol_info> initializer_list statement labeled_statement compound_statement 
%type <symbol_info> declaration_list statement_list expression_statement 
%type <symbol_info> selection_statement iteration_statement jump_statement 
%type <symbol_info> translation_unit external_declaration function_definition

%type <str> declaration_specifiers storage_class_specifier type_qualifier type_specifier struct_or_union_specifier enum_specifier

%start translation_unit

%%

constant: 
    DECIMAL_LITERAL      
	{ 
		$$=$1;
		printf("I am in int\n");
	}//insert_const_tab('I', $1); }
    | FLOAT_LITERAL      
	{ $$=$1;
	printf("I am in float\n");
	}//insert_const_tab('F', $1); }
    | EXP_LITERAL         //insert_const_tab('E', $1); }
    | HEXA_LITERAL       //{ insert_const_tab('H', $1); }
    | REAL_LITERAL       //{ insert_const_tab('R', $1); }
    | STRING_LITERAL     //{ insert_const_tab('S', $1); }
    | OCTAL_LITERAL      //{ insert_const_tab('O', $1); }
    | CHARACTER_LITERAL  //{ insert_const_tab('C', $1); }


primary_expression
	: ID		
	{
		printf("ID %s\n",$1);
		symbol_info* new_symbol = new symbol_info();
		new_symbol->name = $1;
		$$ = new_symbol;
		printf("ID2 %s\n",$$->name.c_str());
		
	}
	| constant		{$$ = $1;}
	| STRING_LITERAL {
        // printf("This is a string literal: %s",$1);
    }
	| LPARENTHESES expression RPARENTHESES
	;

postfix_expression
	: primary_expression 
	{$$=$1;
		printf("Primary expression %s\n",$$->name.c_str());
	}
	| postfix_expression LBRACKET expression RBRACKET
	| postfix_expression LPARENTHESES RPARENTHESES					//{printf("Brackets found\n");}
	| postfix_expression LPARENTHESES argument_expression_list RPARENTHESES   
	{//printf("Function call= %s\n",$1);
		char type_str[10];
        get_type_string(type_str, "unknown");
 
        assign_type(type_str);
        //insert_symtab('F', $1);
		for (int i = 0; i < argList.count_arg; i++) {
            //printf("%s", argList.args[i]);
            if (i < argList.count_arg - 1){} //printf(", ");
        }
        //printf("\n");
	}
	| postfix_expression DOT ID
	| postfix_expression LAMBDA_ARROW ID
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	;

argument_expression_list
    : assignment_expression
    //   { 
    //       if (argList.count_arg < MAX_ARGS) {
    //           argList.args[argList.count_arg++] = strdup($1);
    //       }
    //   }
    | argument_expression_list COMMA assignment_expression
    //   { 
    //       if (argList.count_arg < MAX_ARGS) {
    //           argList.args[argList.count_arg++] = strdup($3);
    //       }
    //   }
    ;

unary_expression
	: postfix_expression 
	{
		$$=$1;
		printf("Postfix expression %s\n",$$->name.c_str());
		}
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
	{
		$$=$1;
		printf("Unary expression %s\n",$$->name.c_str());
		}
	| LPARENTHESES type_name RPARENTHESES cast_expression
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression STAR cast_expression
	| multiplicative_expression DIVIDE cast_expression
	| multiplicative_expression MODULO cast_expression
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression PLUS multiplicative_expression
	| additive_expression MINUS multiplicative_expression
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_SHIFT additive_expression
	| shift_expression RIGHT_SHIFT additive_expression
	;

relational_expression
	: shift_expression 		{$$=$1;}
	| relational_expression LESS_THAN shift_expression
	| relational_expression GREATER_THAN shift_expression
	| relational_expression LESS_EQUALS shift_expression
	| relational_expression GREATER_EQUALS shift_expression
	;

equality_expression
	: relational_expression	{$$=$1;}
	| equality_expression REL_EQUALS relational_expression
	| equality_expression REL_NOT_EQ relational_expression
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression AMPERSAND equality_expression
	;

exclusive_or_expression
	: and_expression 			{$$=$1;}
	| exclusive_or_expression XOR and_expression
	;

inclusive_or_expression
	: exclusive_or_expression 		{$$=$1;}
	| inclusive_or_expression OR exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression 			{$$=$1;}
	| logical_and_expression REL_AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression		{$$=$1;}
	| logical_or_expression REL_OR logical_and_expression
	;

conditional_expression
	: logical_or_expression 			{$$=$1;}
	| logical_or_expression QUESTION_MARK expression COLON conditional_expression
	;

assignment_expression
	: conditional_expression				
	{ 
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		$$=$1;
		printf("cond expression = %s\n",$1->type.c_str());
		printf("cond expression2 = %s\n",$1->name.c_str());
	}
	| unary_expression assignment_operator assignment_expression 
	{
		printf("unary inside assignment = %s\n",$1->name.c_str());
		printf("Assignment expression = %s\n",$3->type.c_str());
		if(curr_scope->symbol_map[$1->name]!=nullptr){
			printf("Symbol found\n");
			if(curr_scope->symbol_map[$1->name]->type!=$3->type){
				printf("Error: Type mismatch in assignment\n");
			}
			else{
				printf("Correct type assignment\n");
				curr_scope->symbol_map[$1->name]=$3;
			}
		}
		else{
			printf("Symbol not found\n");
		}
	}
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
    | declaration_specifiers {parsing_stack.push($1);} init_declarator_list SEMICOLON 
    {
		printf("parsing stack top = %s\n",parsing_stack.top().c_str());
		printf("Declaration specifiers = %s\n", $1);
		printf("Init declarator list = %f\n", $3->name.c_str());
		printf("dollar 3 type = %s\n",$3->type);
		// while(!parsing_stack.empty()){
		// 	printf("top= %s\n",parsing_stack.top().c_str());
		// 	parsing_stack.pop();
		// }
		int flag=0;
		while (parsing_stack.top() != $1) {
			std::string top_symbol = parsing_stack.top();  // Store the top of the stack
			parsing_stack.pop();  // Pop before using it in the map (avoids multiple lookups)

			// Check if the symbol exists in the current scope
			if (curr_scope->symbol_map[top_symbol] != nullptr) {
				printf("top ka type = %s\n", curr_scope->symbol_map[top_symbol]->type.c_str());

				if ($1 != curr_scope->symbol_map[top_symbol]->type) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
			} else {
				// Create new symbol_info and assign type = $1
				symbol_info* new_symbol = new symbol_info();
				new_symbol->type = $1;
				curr_scope->symbol_map[top_symbol] = new_symbol;
				printf("Created new symbol: %s with type %s\n", top_symbol.c_str(), ($1));
			}
		}
		parsing_stack.pop();
		
		if(flag==0) printf("Correct type declaration\n");
		
		

        //printf("declaration  = %s\n", $2);
        // char type_str[10];
        // get_type_string(type_str, $1);

        // char *token = strtok($2, ",");
        // while (token != NULL) {
        //     char *var_name = token;
        //     char *value = strchr(token, '=');

        //     if (value) {
        //         *value = '\0';  
        //         value++;  
        //     }

        //     assign_type(type_str);

        //     int pointer_level = 0;
        //     while (*var_name == '*') {
        //         pointer_level++;
        //         var_name++;  
        //     }
		// 	assign_type(type_str);
        //     if (pointer_level > 0) {
        //         insert_symtab('P',var_name);
        //     } else {
        //         insert_symtab('V',var_name);
        //     }

        //     token = strtok(NULL, ",");
        // }
    }
    ;


declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier {$$=$1;}
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
    : init_declarator { 
        $$ = $1; 
		printf("init_d %s\n",$$->name.c_str());  
        //printf("init_declarator = %s\n", $$);
    }
    | init_declarator_list COMMA init_declarator { 
        // $$ = (char*)malloc(strlen($1) + strlen($3) + 2); 
        // sprintf($$, "%s,%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "," + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator_list = %s\n", $$);
		$$=$3;
		printf("init_D %s\n",$$->name.c_str()); 
    }
    ;

init_declarator
    : declarator { 
		curr_scope->symbol_map[$1->name]=nullptr;
        $$ =$1;
		printf("declarator %s\n",$$->name.c_str()); 
		parsing_stack.push($1->name.c_str());
        //printf("declarator = %s\n", $$);
    }
    | declarator EQUALS initializer { 
        // $$ = malloc(strlen($1) + strlen($3) + 2);  
        // sprintf($$, "%s=%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "=" + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator with initializer = %s\n", $$);
		curr_scope->symbol_map[$1->name]=$3;
		if($3->type=="float") printf("Yes float found\n");
		if($3->type=="int") printf("Yes int found\n");
		parsing_stack.push($1->name.c_str());
		$$ = $1;
		printf("declarator equals initializer %s\n",$$->name.c_str()); 
		
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
	| CHAR				//{printf("Character\n");}
	| SHORT
	| INT				{$$=strdup("int");}
	| LONG
	| FLOAT				{$$=strdup("float");}
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	;

struct_or_union_specifier
	: struct_or_union ID LBRACE struct_declaration_list RBRACE 
	{
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        // assign_type(type_str);
        // insert_symtab('V', $2); 
	}
	| struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union ID 
	
	{
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        // insert_symtab('V', $2); 
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
		//printf("Struct declaration %s = %s\n",$1,$2);
		char type_str[10];
        // get_type_string(type_str, $1);
        
        // char *token = strtok($2, ",");
        // while (token != NULL) {
        //     char *var_name = token;
        //     char *value = strchr(token, '=');

        //     if (value) {
        //         *value = '\0';  
        //         value++;  
        //     }

        //     assign_type(type_str);

        //     int pointer_level = 0;
        //     while (*var_name == '*') {
        //         pointer_level++;
        //         var_name++;  
        //     }
		// 	assign_type(type_str);
        //     if (pointer_level > 0) {
        //         insert_symtab('P',var_name);
        //     } else {
        //         insert_symtab('V',var_name);
        //     }

        //     token = strtok(NULL, ",");
        // } 
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
	: declarator        //{printf("Struct declarator = %s\n",$1);}
	| COLON constant_expression
	| declarator COLON constant_expression
	;

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM ID LBRACE enumerator_list RBRACE 
	{
		//printf("enum is here = %s\n",$$);
		char type_str[10];
      	// get_type_string(type_str,$$);
      	assign_type(type_str);
      	// insert_symtab('V',$2);
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
		//printf("Pointer direct declarator\n");
        // $$ = malloc(strlen($1) + strlen($2) + 1); 
        // sprintf($$, "%s%s", $1, $2); 
		// //printf("it is $$: %s\n",$$); 
        // free($1); free($2);

        // string result = string($1) + string($2);
        // $$ = strdup(result.c_str());
    }
    | direct_declarator { 
		$$=$1;
        // $$ = strdup($1);  
		//printf("Direct declarator %s\n",$$);
		printf("Direct declarator %s\n",$$->name.c_str());
    }
    ;

direct_declarator
	: ID     
	{
		printf("%s\n",$1);
		symbol_info* x=new symbol_info();
		x->name = $1;

		$$=x;
		printf("ID %s\n",$$->name.c_str());
	}        //{printf("Identifier in direct declaratorrr = %s\n",$1);}
	| LPARENTHESES declarator RPARENTHESES			
	{ 
		//printf("LPar declarator RPar= %s\n",$2);
		// $$=strdup($2);
	}
	| direct_declarator LBRACKET constant_expression RBRACKET
	| direct_declarator LBRACKET RBRACKET								//{printf("Array\n");}
	| direct_declarator LPARENTHESES parameter_type_list RPARENTHESES     //{printf("Brackets found with parameter= %s\n",$1);}
	| direct_declarator LPARENTHESES identifier_list RPARENTHESES          //{printf("Brackets found\n");}
	| direct_declarator LPARENTHESES RPARENTHESES 						//{printf("Brackets found\n");}
	;

pointer
	: STAR //{ $$ = strdup("*"); }
	| STAR type_qualifier_list
	| STAR pointer   
	{ 
        // $$ = malloc(strlen($2) + 2); 
        // sprintf($$, "*%s", $2);  
        // free($2);

        // string result = string("*") + string($2);
        // $$ = strdup(result.c_str());
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
        // get_type_string(type_str, $1);

        // char *token = strtok($2, ",");
        // while (token != NULL) {
        //     char *var_name = token;
        //     char *value = strchr(token, '=');

        //     if (value) {
        //         *value = '\0';  
        //         value++;  
        //     }

        //     assign_type(type_str);

        //     int pointer_level = 0;
        //     while (*var_name == '*') {
        //         pointer_level++;
        //         var_name++;  
        //     }
		// 	assign_type(type_str);
        //     if (pointer_level > 0) {
        //         insert_symtab('f',var_name);
        //     } else {
        //         insert_symtab('V',var_name);
        //     }

        //     token = strtok(NULL, ",");
        // } 
	}
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID				//{printf("Identifier in list = %s",$1);}
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
	| LPARENTHESES RPARENTHESES											//{printf("Brackets found\n");}
	| LPARENTHESES parameter_type_list RPARENTHESES
	| direct_abstract_declarator LPARENTHESES RPARENTHESES         //{printf("Brackets found\n");}
	| direct_abstract_declarator LPARENTHESES parameter_type_list RPARENTHESES
	;

initializer
	: assignment_expression {$$=$1;}
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
	| expression SEMICOLON   //{printf("Expression semicolon\n");}
	;

selection_statement
	: IF LPARENTHESES expression RPARENTHESES statement
	| IF LPARENTHESES expression RPARENTHESES statement ELSE statement      //{printf("It is in if-else block\n");}
	| SWITCH LPARENTHESES expression RPARENTHESES statement					//{printf("It is in switch block\n");}
	;

iteration_statement
	: WHILE LPARENTHESES expression RPARENTHESES statement
	| DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON
	| FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement
	| FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement    //{printf("For loop\n");}
	;

jump_statement
	: GOTO ID SEMICOLON				
	{ 
		//printf("Goto statement: %s\n",$2);
		
      	// insert_symtab('G',$2);
		

	}
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation_unit
	: external_declaration 				    //{printf("Reached the root node.\n");}
	| translation_unit external_declaration //{printf("Reached the root node.\n");}
	| 
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement    
	{   //printf("Function is there: %s %s\n",$1,$2);
		char type_str[10];
      	// get_type_string(type_str,$1);
      	assign_type(type_str);
      	// insert_symtab('F',$2);
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

void print_scope_table() {
    printf("-----------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-7s | %-10s |\n", "Identifier", "Type", "Size", "Value");
    printf("-----------------------------------------------------------------\n");

    for (const auto& it : curr_scope->symbol_map) {
        if (!it.second) {  // Check if symbol_info* is null (shouldn't happen after your fix)
            printf("| %-15s | %-20s | %-7s | %-10s |\n",
                   it.first.c_str(), "uninitialized", "N/A", "N/A");
            continue;
        }

        std::string valueStr = "N/A";  // Default value
        int size = 0;  // Default size

        // Assign size based on type
        if (it.second->type == "int") {
            size = 4;
            if (it.second->ptr) valueStr = std::to_string(*(int*)(it.second->ptr));
        } else if (it.second->type == "float") {
            size = 4;
            if (it.second->ptr) valueStr = std::to_string(*(float*)(it.second->ptr));
        } else if (it.second->type == "char") {
            size = 2;
            if (it.second->ptr) valueStr = std::string(1, *(char*)(it.second->ptr));
        } else if (it.second->type == "long") {
            size = 8;
            if (it.second->ptr) valueStr = std::to_string(*(long*)(it.second->ptr));
        } else {
            size = 0;  // Unknown type
        }

        printf("| %-15s | %-20s | %-7d | %-10s |\n",
               it.first.c_str(),          // Identifier
               it.second->type.c_str(),   // Type
               size,                      // Size
               valueStr.c_str());         // Value
    }

    printf("-----------------------------------------------------------------\n");
}





int main() {

    yyparse();

    // print_symbol_table();
    // printf("\n");
    // print_constant_table();
	printf("Parsing stack size = %d\n",parsing_stack.size());
	while(!parsing_stack.empty()){
		printf("Parsing stack%s\n",parsing_stack.top().c_str());
		parsing_stack.pop();
	}
	print_scope_table();

}
