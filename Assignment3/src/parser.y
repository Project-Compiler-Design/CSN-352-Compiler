%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include<iostream>
	#include<fstream>
    #include<map>
    #include<vector>
	#include<stack>

	#include "functions.h"
    using namespace std;

	#define MAX_ARGS 100

    void yyerror(const char *s);

    extern int yylex();
    extern int yylineno;
    extern char *yytext;  

	stack<string> parsing_stack;

    scoped_symtab* curr_scope = new scoped_symtab();
    vector<scoped_symtab*> all_scopes={curr_scope};
	
	std::ofstream file("output.txt");

    
    


	struct ArgList {
        char *args[MAX_ARGS];
        int count_arg;
    } argList;

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

%type <symbol_info> struct_declaration_list struct_declaration 
%type <symbol_info> struct_declarator_list struct_declarator 
%type <symbol_info> enumerator_list enumerator declarator 
%type <symbol_info> direct_declarator pointer type_qualifier_list parameter_type_list 
%type <symbol_info> parameter_list parameter_declaration identifier_list type_name 
%type <symbol_info> abstract_declarator direct_abstract_declarator initializer 
%type <symbol_info> initializer_list statement labeled_statement compound_statement 
%type <symbol_info> declaration_list statement_list expression_statement statement_declaration_list
%type <symbol_info> selection_statement iteration_statement jump_statement 
%type <symbol_info> translation_unit external_declaration function_definition

%type <str> declaration_specifiers storage_class_specifier type_qualifier type_specifier enum_specifier specifier_qualifier_list
%type <str> struct_or_union struct_or_union_specifier 

%start translation_unit

%%

constant: 
    DECIMAL_LITERAL      
	{
		$$= new symbol_info("", "int", $1->ptr, $1->symbol_size);
		$$->place=qid(std::to_string(*(int*)($1->ptr)),nullptr);
		$$->code=std::to_string(*(int*)($1->ptr));
	}
    | FLOAT_LITERAL      
	{
		$$= new symbol_info("", "float", $1->ptr, $1->symbol_size);
		$$->place=qid(std::to_string(*(float*)($1->ptr)),nullptr);
		$$->code=std::to_string(*(float*)($1->ptr));
	}
    | EXP_LITERAL        {$$ = new symbol_info("", "exp", $1->ptr, $1->symbol_size);} 
    | HEXA_LITERAL       {$$ = new symbol_info("", "hexa", $1->ptr, $1->symbol_size);}
    | REAL_LITERAL       {$$ = new symbol_info("", "real", $1->ptr, $1->symbol_size);}
    | STRING_LITERAL     {$$ = new symbol_info("", "string", $1->ptr, $1->symbol_size);}
    | OCTAL_LITERAL      {$$ = new symbol_info("", "octal", $1->ptr, $1->symbol_size);}
    | CHARACTER_LITERAL  
	{
		$$ = new symbol_info("", "char", $1->ptr, $1->symbol_size);
        string tempp = "'";
        tempp+=(*(char*)($1->ptr));
        tempp+='\'';
		$$->place=qid(tempp,nullptr);
		$$->code=tempp;
	}


primary_expression
	: ID		
        {
            cerr<<"ID found: "<<$1<<endl;
            printf("ID %s\n",$1);
            symbol_info* new_symbol = new symbol_info($1);
            $$ = new_symbol;
            printf("ID2 %s\n",$$->name.c_str());
            cerr<<"check"<<endl;
            
			//3AC code
			symbol_info* find_symbol = lookup_symbol_global($1, curr_scope);
			if(find_symbol==nullptr){
				cerr<<"Error: Undeclared variable "<<$1<<endl;
			}
			else{
				$$->place=qid($1,find_symbol);
				$$->code="";
				cerr<<"Symbol found "<<$$->place.second->name<<endl;
				cerr<<"Code "<<$$->code<<endl;
			}
        }
	| constant		
	{
		cerr << "con\n";$$ = $1;
		
	}
	| STRING_LITERAL 
	| LPARENTHESES expression RPARENTHESES
	;

postfix_expression
	: primary_expression 
        {
            $$=$1;
            cerr << "Primary expression found: " << $1->type << endl;
        }
	| postfix_expression LBRACKET expression RBRACKET
	| postfix_expression LPARENTHESES RPARENTHESES					
	| postfix_expression LPARENTHESES argument_expression_list RPARENTHESES   
	    {
			symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared function "<<$1->name<<endl;
				
			}
			else{
				cout<<"Function type "<<find_symbol->type<<endl;
		  		std::vector<std::string> original_list=find_symbol->param_types;
				std::vector<std::string> new_list=$3->param_types;
				if(original_list.size()!=new_list.size()){
					cout<<"Error: Size of actual and formal parameter list does not match "<<endl;
				}
				else{
					for(int i=0;i<original_list.size();i++){
						if(type_priority[original_list[i]]<type_priority[new_list[i]]){
							cout<<"Error: Type of actual and formal parameter does not match"<<endl;
							break;
						}
					}
				}

			}

            //printf("Function call= %s\n",$1);
        }
	| postfix_expression DOT ID
	{
		symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
		if(find_symbol == nullptr) {
			cerr<<"Error: Undeclared variable "<<$1->name<<endl;
		}
		else{
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				cout<<"Struct or union found "<<find_symbol->type<<endl;
				symbol_info* find_struct;
				if((find_symbol->type).substr(0,6)=="struct") find_struct=lookup_symbol_global((find_symbol->type).substr(7), curr_scope);
				else find_struct=lookup_symbol_global((find_symbol->type).substr(6), curr_scope);
				int flag=0;
				string var_type="";
				cerr<<"Struct or union name "<<find_struct->type<<endl;
				for(int i=0;i<find_struct->param_list.size();i++){
					cerr<<"Param list "<<find_struct->param_list[i]<<endl;
					if(find_struct->param_list[i]==$3){
						cerr<<"Found "<<$3<<" with type "<<find_struct->param_types[i]<<endl;
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
				}
				if(flag==0){
					cerr<<"Error: no such attribute found in struct or union"<<endl;
				}
				else{
					parsing_stack.push($1->name);
					parsing_stack.push($3);
					parsing_stack.push(var_type);
					find_symbol->name=$1->name;
					$$=find_symbol;
				}
				
			}
			else{
				cerr<<"Error: Not a struct or union"<<endl;
			}
			
		}
	}
	| postfix_expression LAMBDA_ARROW ID
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	;

argument_expression_list
    : assignment_expression
      { 
			cout<<"$1 ka name "<<$1->name<<endl;
		  if($1->name==""){

			cout<<"is a number "<<$1->type<<endl;
			$$=$1;
			$$->param_types.push_back($1->type);
		  }
		  else{
			symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared variable "<<$1->name<<endl;
			}
			else{
				cout<<"Ass exp "<<find_symbol->type<<endl;
		  		$$=find_symbol;
		  		$$->param_types.push_back(find_symbol->type);
			}
		  }
		  
          
      }
    | argument_expression_list COMMA assignment_expression

       { 
			cout<<"$3 ka name "<<$3->name<<endl;
		  if($3->name==""){

			cout<<"is a number "<<$3->type<<endl;
			$$=$1;
			$$->param_types.push_back($3->type);
		  }
		  else{
			symbol_info* find_symbol = lookup_symbol_global($3->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared variable "<<$3->name<<endl;
				
			}
			else{
				cout<<"Ass exp222 "<<find_symbol->type<<endl;
		  		$$=$1;
		  		$$->param_types.push_back(find_symbol->type);
			}
			
			cout<<"Ass exp111 "<<$1->type<<endl;
		  }
			
           
       }
    ;

unary_expression
	: postfix_expression 
	{
		$$=$1;
		cerr << "postfix expression found: " << $1->type << endl;
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
    {
        cout<<"casting"<<endl;
        $$ = $4;
        $$->type = $2->type;
    }
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression STAR cast_expression 
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"*"+$3->place.first;
		$$->place=var;
		

	}
	| multiplicative_expression DIVIDE cast_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        qid var=newtemp($1->type,curr_scope);
        $$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"/"+$3->place.first;
        $$->place=var;
    }
	| multiplicative_expression MODULO cast_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: Modulo operator can only be used with int type\n");
        }
        qid var=newtemp($1->type,curr_scope);
        $$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"%"+$3->place.first;
        $$->place=var;
    }
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression PLUS multiplicative_expression 
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"+"+$3->place.first;
		$$->place=var;
	}
	| additive_expression MINUS multiplicative_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"-"+$3->place.first;
		$$->place=var;
	}
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_SHIFT additive_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: Left shift operator can only be used with int type\n");
        }
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"<<"+$3->place.first;
		$$->place=var;
	}
	| shift_expression RIGHT_SHIFT additive_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: Right shift operator can only be used with int type\n");
        }
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+">>"+$3->place.first;
		$$->place=var;
	}
	;

relational_expression
	: shift_expression 		{$$=$1;}
	| relational_expression LESS_THAN shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"<"+$3->place.first;
		$$->place=var;
	}
	| relational_expression GREATER_THAN shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];        
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+">"+$3->place.first;
		$$->place=var;
	}
	| relational_expression LESS_EQUALS shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"<="+$3->place.first;
		$$->place=var;
	
	}
	| relational_expression GREATER_EQUALS shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+">="+$3->place.first;
		$$->place=var;
	}
	;

equality_expression
	: relational_expression	{$$=$1;}
	| equality_expression REL_EQUALS relational_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"=="+$3->place.first;
		$$->place=var;
		// file<<$$->code<<endl;
	}
	| equality_expression REL_NOT_EQ relational_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
		$$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"!="+$3->place.first;
		$$->place=var;
	}

	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression AMPERSAND equality_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: And operator can only be used with int type\n");
        }
    }
	;

exclusive_or_expression
	: and_expression 			{$$=$1;}
	| exclusive_or_expression XOR and_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: XOR operator can only be used with int type\n");
        }
        qid var=newtemp($1->type,curr_scope);
        $$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"^"+$3->place.first;
        $$->place=var;
    }
	;

inclusive_or_expression
	: exclusive_or_expression 		{$$=$1;}
	| inclusive_or_expression OR exclusive_or_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: OR operator can only be used with int type\n");
        }
        qid var=newtemp($1->type,curr_scope);
        $$->code=$1->code + "\n" + $3->code +"\n" + var.first+":=  "+$1->place.first+"|"+$3->place.first;
        $$->place=var;
    }
	;

logical_and_expression
	: inclusive_or_expression 			{$$=$1;}
	| logical_and_expression REL_AND inclusive_or_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: AND operator can only be used with int type\n");
        }
        
    }
	;

logical_or_expression
	: logical_and_expression		{$$=$1;}
	| logical_or_expression REL_OR logical_and_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            printf("ERROR!!!!!!: OR operator can only be used with int type\n");
        }
    }
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
		cerr << "condi expression found: " << $1->code << endl;
	}
	| unary_expression assignment_operator assignment_expression 
	{
		printf("unary inside assignment = %s\n",$1->name.c_str());
		printf("Assignment expression = %s\n",$3->type.c_str());
        symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
        if(find_symbol != nullptr) {
			cerr<<"find symbol type: "<<(find_symbol->type).substr(0,6)<<endl;
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				if(parsing_stack.top()==$3->type){
					//Semantic Analysis
					parsing_stack.pop();
					string attr=parsing_stack.top();
					parsing_stack.pop();
					string struct_inst_name=parsing_stack.top();
					parsing_stack.pop();
					symbol_info* find_struct=lookup_symbol_global(struct_inst_name, curr_scope);
					find_struct->param_list.push_back(attr);
					find_struct->struct_attr_values.push_back($3);
					cerr<<"Error in struct or union attr values"<<endl;

					//3AC code
					

				}
				else{
					printf("Error: Type mismatch in assignment of struct or union attributes\n");
				}
			}
			else{
                if(type_priority[find_symbol->type]<type_priority[$3->type]){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }else{
                    printf("Correct type assignment\n");
                }
                
                find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[$3->type])];
                find_symbol->name=$1->name;
                find_symbol->place=$1->place;
                find_symbol->code=$1->code + "\n" + $3->code + "\n" + $1->place.first + ":=  " + $3->place.first;
                //file<<find_symbol->code<<endl;
                
                cerr<<"Correct type assignment"<<endl;

                //3AC code
                cerr<<"3AC code for assignment"<<endl;
                $$->code=$1->code + "\n" + $3->code + "\n" + $1->place.first + ":=  " + $3->place.first;
                $$->place=$1->place;
                //file<<$$->code<<endl;
				
			}
			
		}
			
           else{
			printf("Symbol not found\n");
		} 
            
        }

	
		
	
	;

assignment_operator
	: EQUALS {$$=new symbol_info("","equals",nullptr,0); $$->code="=";}
	| ASSIGN_STAR {$$=new symbol_info("","assign_star",nullptr,0); $$->code="*=";}
	| ASSIGN_DIV {$$=new symbol_info("","assign_div",nullptr,0); $$->code="/=";}
	| ASSIGN_MOD {$$=new symbol_info("","assign_mod",nullptr,0); $$->code="%=";}
	| ASSIGN_PLUS {$$=new symbol_info("","assign_plus",nullptr,0); $$->code="+=";}
	| ASSIGN_MINUS {$$=new symbol_info("","assign_minus",nullptr,0); $$->code="-=";}
	| LEFT_SHIFT_EQ {$$=new symbol_info("","left_shift_eq",nullptr,0); $$->code="<<=";}
	| RIGHT_SHIFT_EQ {$$=new symbol_info("","right_shift_eq",nullptr,0); $$->code=">>=";}
	| ASSIGN_AND {$$=new symbol_info("","assign_and",nullptr,0); $$->code="&=";}
	| ASSIGN_XOR {$$=new symbol_info("","assign_xor",nullptr,0); $$->code="^=";}
	| ASSIGN_OR {$$=new symbol_info("","assign_or",nullptr,0); $$->code="|=";}
	;

expression
	: assignment_expression 	
	{
		// cout<<"Assignment expression = "<<$1->code<<endl;
		// file<<$1->code<<endl;
		$$=$1;
	}	
	| expression COMMA assignment_expression
    //means?
	;

constant_expression
	: conditional_expression
	;

declaration
    : declaration_specifiers SEMICOLON
    | declaration_specifiers init_declarator_list SEMICOLON 
    {
		
		printf("parsing stack top = %s\n",parsing_stack.top().c_str());
		printf("Declaration specifiers = %s\n", $1);
		printf("Init declarator list = %f\n", $2->name.c_str());
		printf("dollar 3 type = %s\n",$2->type);
		// while(!parsing_stack.empty()){
		// 	printf("top= %s\n",parsing_stack.top().c_str());
		// 	parsing_stack.pop();
		// }
		int flag=0;
		while (!parsing_stack.empty()) {
			std::string top_symbol = parsing_stack.top();  // Store the top of the stack
			parsing_stack.pop();  // Pop before using it in the map (avoids multiple lookups)

			// Check if the symbol exists in the current scope
			if (curr_scope->symbol_map[top_symbol]->type!= "") {
				printf("top ka type = %s\n", curr_scope->symbol_map[top_symbol]->type.c_str());

				if ($1 != curr_scope->symbol_map[top_symbol]->type) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
                curr_scope->symbol_map[top_symbol]->name = top_symbol;

			} else {
				// Create new symbol_info and assign type = $1
				curr_scope->symbol_map[top_symbol]->type = $1;
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
				printf("Created new symbol: %s with type %s\n", top_symbol.c_str(), ($1));
			}
		}
		
		$$->code = $2->code;
		if(flag==0) printf("Correct type declaration\n");
		
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
    }
    | init_declarator_list COMMA init_declarator { 
		$$=$3;
		$$->code = $1->code + "\n" + $3->code;
		printf("init_D %s\n",$$->name.c_str()); 
    }
    ;

init_declarator
    : declarator { 
		printf("declarator11 %s\n",$1->name.c_str());
		if(curr_scope->symbol_map[$1->name]!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		symbol_info* new_symbol=new symbol_info();

		curr_scope->symbol_map[$1->name]=new_symbol;
        $$ =$1;
		printf("declarator %s\n",$$->name.c_str()); 
		parsing_stack.push($1->name.c_str());
    }
    | declarator EQUALS initializer { 
		printf("declaratoreiii %s\n",$1->name.c_str());
		if(curr_scope->symbol_map[$1->name]!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		curr_scope->symbol_map[$1->name]=$3;
		if($3->type=="float") printf("Yes float found\n");
		if($3->type=="int") printf("Yes int found\n");
		if($3->type=="char") printf("Yes char found %s\n",$3->str_val.c_str());
		parsing_stack.push($1->name.c_str());
		if($1->is_array){
			if($3->int_array.size() > $1->array_length){
				printf("Error: Elements Greater than Declared\n");
			}
			else{
				$1->int_array = $3->int_array;
				$1->type = $3->type;
			}
		}
		
		$$ = $1;
		if($3->place.first[0]!='t')
		{
			$3->code="";
		}
		$$->code=$3->code+"\n"+$1->place.first+":= "+$3->place.first;
		$$->place=$1->place;
		// file<<$$->code<<endl;
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
	: VOID				{$$=strdup("void");}
	| CHAR				{$$=strdup("char");}
	| SHORT				{$$=strdup("short");}
	| INT				{$$=strdup("int");}
	| LONG				{$$=strdup("long");}
	| FLOAT				{$$=strdup("float");}
	| DOUBLE			{$$=strdup("double");}
	| SIGNED			{$$=strdup("signed");}
	| UNSIGNED			{$$=strdup("unsigned");}
	| struct_or_union_specifier {$$=$1;}
	| enum_specifier
	;

struct_or_union_specifier
	: struct_or_union ID LBRACE struct_declaration_list RBRACE 
	{
		
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type = $1;
		new_symbol->param_list = $4->param_list;
		new_symbol->param_types = $4->param_types;
		curr_scope->symbol_map[$2]=new_symbol;
		for(int i=0;i<curr_scope->symbol_map[$2]->param_list.size();i++){
			printf("Struct or union declaration %s = %s\n",curr_scope->symbol_map[$2]->param_types[i].c_str(),curr_scope->symbol_map[$2]->param_list[i].c_str());
		}
	}
	| struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union ID
	{
		symbol_info* find_symbol = lookup_symbol_global($2, curr_scope);
		if (find_symbol != nullptr) {
			if (find_symbol->type == "struct" || find_symbol->type == "union") {
				std::string temp = std::string($1) + " " + std::string($2);
				$$ = strdup(temp.c_str());  // strdup allocates new memory for the concatenated string
			} else {
				std::cerr << "Error: Variable not of type struct or union" << std::endl;
			}
		} else {
			std::cerr << "Error: Struct or Union not declared" << std::endl;
		}
	} 
	;

struct_or_union
	: STRUCT {$$=strdup("struct");}
	| UNION {$$=strdup("union");}
	;

struct_declaration_list
	: struct_declaration {$$=$1;}
	| struct_declaration_list struct_declaration
	{
		$$=$1;
		for(int i=0;i<$2->param_list.size();i++){
			$$->param_list.push_back($2->param_list[i]);
			$$->param_types.push_back($2->param_types[i]);
		}
		
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMICOLON      
	{ 
		//printf("Struct declaration %s = %s\n",$1,$2);
		$$=$2;
		for(auto it: $2->param_list)
					{
						cerr<<it<<endl;
						symbol_info* x=new symbol_info();
						x->type = $1;
						
						curr_scope->symbol_map[it]=x;
						$$->param_types.push_back($1);
					}
		
		

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
	{
		$$=$1;
		$$->param_list.push_back($1->name);
	}
	| struct_declarator_list COMMA struct_declarator
	{
		$$=$1;
		$$->param_list.push_back($3->name);
	}
	;

struct_declarator
	: declarator     {$$=$1;}   //{printf("Struct declarator = %s\n",$1);}
	| COLON constant_expression
	| declarator COLON constant_expression
	;

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM ID LBRACE enumerator_list RBRACE 
	{
		
		//printf("enum is here = %s\n",$$);
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
    }
    | direct_declarator { 
		$$=$1; 
		printf("Direct declarator %s\n",$$->name.c_str());
    }
    ;

direct_declarator
	: ID     
	{
		printf("%s\n",$1);
		symbol_info* x=new symbol_info();
		x->name = $1;
		x->place.first=$1;
		$$=x;
		printf("ID %s\n",$$->name.c_str());
	}        //{printf("Identifier in direct declaratorrr = %s\n",$1);}
	| LPARENTHESES declarator RPARENTHESES			
	{ 
		//printf("LPar declarator RPar= %s\n",$2);
	}
	| direct_declarator LBRACKET constant_expression RBRACKET			{$$->is_array = true;
																		if($3->type=="int"){
																			$$->array_length = *(int*)($3->ptr);
																			printf("Array length = %d\n",$$->array_length);
																		}
																		else{
																			printf("Error: Array size not an integer\n");
																			$$->array_length=100;
																		}}
	| direct_declarator LBRACKET RBRACKET								{printf("Array Size not declared\n"), $$->is_array = true, $$->array_length = 100;}
	| direct_declarator LPARENTHESES parameter_type_list RPARENTHESES     
	{
		printf("Brackets found with parameter= %s\n",$1->name.c_str());
		printf("Par list %d\n",$3->parameter_no);
		for(auto it: $3->param_types)
					{
						cout<<it<<endl;
					}
		curr_scope->symbol_map[$1->name]=$3;
	}
	| direct_declarator LPARENTHESES identifier_list RPARENTHESES          //{printf("Brackets found in function calllll\n");}
	| direct_declarator LPARENTHESES RPARENTHESES 						//{printf("Brackets found\n");}
	;

pointer
	: STAR //{ $$ = strdup("*"); }
	| STAR type_qualifier_list
	| STAR pointer   
	| STAR type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list{
		$$=$1;
		for(auto it: $1->param_types)
					{
						cout<<it<<endl;
					}
		cout<<"par num"<<$$->parameter_no<<endl;
				}

	| parameter_list COMMA VARIABLE_ARGS
	;

parameter_list
	: parameter_declaration{$$->is_param_list=true;
	   						$$->parameter_no=1;
							
	   						$$->param_types.push_back($1->type);}
	| parameter_list COMMA parameter_declaration {$$->is_param_list=true;
							cout<<"par num $1 "<<$1->parameter_no<<endl;
							cout<<"par num $3 "<<$3->parameter_no<<endl;
	   						$$->parameter_no=$1->parameter_no+$3->parameter_no;
	   						$$->param_types.push_back($3->type);
							
												}
	
	;

parameter_declaration
	: declaration_specifiers declarator  
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->parameter_no=1;
		// printf("%s",$$->type);
	}
	| declaration_specifiers abstract_declarator{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		// printf("%s",$$->type);
	}
	| declaration_specifiers{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		// printf("%s",$$->type);
	}
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
	: assignment_expression {
		$1->int_array.push_back($1);
		$$=$1;
	}
	| LBRACE initializer_list RBRACE {$$ = $2;}
	| LBRACE initializer_list COMMA RBRACE {$$ = $2;}
	;

initializer_list
	: initializer {$$ = $1;}
	| initializer_list COMMA initializer {
		if($1->type != $3->type){
			printf("Error: Type mismatch in initializer list\n");
		}
		else{
			$1->int_array.push_back($3);
		}
		$$ = $1;
	}
	;

statement
	: labeled_statement
	| compound_statement
	{
		$$=$1;
		//file<<$$->code<<endl;
	}
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
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} statement_declaration_list RBRACE {
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
		//file<<$$->code<<endl; 
	}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} statement_list RBRACE {all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list RBRACE {all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list statement_list RBRACE {all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	;

statement_declaration_list
	: statement_list statement_declaration_list
	| declaration_list statement_declaration_list
	{

		$$->code=$1->code + "\n" + $2->code;
		//file<<"heloo"<<$$->code<<endl;
	}
	| statement_list
	| declaration_list
	{
		$$=$1;
		//file<<$$->code<<endl;
	}
	;

declaration_list
	: declaration
	{
		$$=$1;
		//file<<$$->code<<endl;
	}
	| declaration_list declaration
	{
		cout<<"Maaaai yaha honnnn"<<endl;
		$$->code=$1->code + "\n" + $2->code;
		//file<<$$->code<<endl;
	}
	| error SEMICOLON {yyerrok;}
	;

statement_list
	: statement { 
		$$=$1;
	}
	| statement_list statement
	{
		$$->code=$1->code + "\n" + $2->code;
	}
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
	}
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation_unit
	: external_declaration 				 
	{
		$$=$1;
		file<<$$->code<<endl;
	}   //{printf("Reached the root node.\n");}
	| translation_unit external_declaration //{printf("Reached the root node.\n");}
	| 
	;

external_declaration
	: function_definition 
	{
		$$=$1;
		//file<<$$->code<<endl;
	}
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement 
	{
		//abhi ke liye
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
		// file<<$$->code<<endl;
	}   
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;
%%

void yyerror(const char *s) {
    
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

void print_scope_table() {
	cerr<<"Printing scope table"<<endl;
	int count=0;
	for(auto scope : all_scopes) {count++;}
	cerr<<"Count of scopes "<<count<<endl;
	// cerr<<"Curr scope "<<curr_scope->symbol_map.size()<<endl;
    for(auto scope : all_scopes) {
    printf("-----------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-7s | %-10s |\n", "Identifier", "Type", "Size", "Value");
    printf("-----------------------------------------------------------------\n");
	
    for (const auto& it : scope->symbol_map) {
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
            valueStr = it.second->str_val;
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

		if((it.second->type).substr(0,6)=="struct"){
			for(int i=0;i<it.second->struct_attr_values.size();i++){
				printf("| %-15s | %-20s | %-7d | %-10s |\n",
               (it.first+"."+it.second->param_list[i]).c_str(),          // Identifier
               it.second->struct_attr_values[i]->type.c_str(),   // Type
               4,                      // Size
               std::to_string(*(int*)(it.second->struct_attr_values[i]->ptr)).c_str());         // Value
			}
		}
		if((it.second->type).substr(0,5)=="union"){
			for(int i=0;i<it.second->struct_attr_values.size();i++){
				printf("| %-15s | %-20s | %-7d | %-10s |\n",
               (it.first+"."+it.second->param_list[i]).c_str(),          // Identifier
               it.second->struct_attr_values[i]->type.c_str(),   // Type
               4,                      // Size
               std::to_string(*(int*)(it.second->struct_attr_values[i]->ptr)).c_str());         // Value
			}
		}
    }

    printf("-----------------------------------------------------------------\n");
	cerr<<"Scope is here"<<endl;
    }
}





int main() {
	
    

    yyparse();

    
	printf("Parsing stack size = %d\n",parsing_stack.size());
	while(!parsing_stack.empty()){
		printf("Parsing stack%s\n",parsing_stack.top().c_str());
		parsing_stack.pop();
	}
	print_scope_table();
	file.close();
}
