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
    stack<int> pointer_info;

    scoped_symtab* curr_scope = new scoped_symtab();
    vector<scoped_symtab*> all_scopes={curr_scope};
	
	std::ofstream file("output.txt");

    vector<string> type_list = {};
	vector<string> var_name={};
	vector<string> goto_list={};
    


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
%type <symbol_info> translation_unit external_declaration function_definition start_symbol

%type <str> declaration_specifiers storage_class_specifier type_qualifier type_specifier enum_specifier specifier_qualifier_list
%type <str> struct_or_union struct_or_union_specifier 

%start start_symbol

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
				$$->type=find_symbol->type;
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
	{
		string array_name=$1->name;
		symbol_info* find_symbol = lookup_symbol_global(array_name, curr_scope);
		if(find_symbol == nullptr) {
			cerr<<"Error: Undeclared variable "<<array_name<<endl;
		}
		else{
			if(find_symbol->is_array==false){
				cerr<<"Error: Not an array "<<array_name<<endl;
			}
			else{
				cerr<<"Array found "<<find_symbol->type<<endl;
                string code=$3->code;
                qid temp=newtemp(find_symbol->type,curr_scope);
                code=code+"\n"+temp.first+":= "+"4 * "+$3->place.first;
                qid temp2=newtemp(find_symbol->type,curr_scope);
                code=code+"\n"+temp2.first+":= *("+$1->place.first+" + "+temp.first+")";
                $$->code=code;
                $$->place.first=temp2.first;
                
                
				
			}
			
		}
		cerr<<"here is array access "<<endl;
	}
	| postfix_expression LPARENTHESES RPARENTHESES	
	{
		
	}				
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
			qid temp=newtemp($1->type,curr_scope);
			string middle="";
			for(int i=0;i<$3->param_list.size();i++){
				middle=middle+"PARAM "+$3->param_list[i]+"\n";
			}
			$$->code=$1->code + middle + temp.first+":= CALL "+$1->place.first;
			$$->place=temp;
			cerr<<"ppfffix exp"<<$$->code<<endl;
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
	{
		$$=$1;
		$$->code=$1->code + "\n" + $1->place.first+":=  "+$1->place.first+"+1";
		
	}
	| postfix_expression DECREMENT
	{
		$$=$1;
		$$->code=$1->code + "\n" + $1->place.first+":=  "+$1->place.first+"-1";
	}
	;

argument_expression_list
    : assignment_expression
      { 
			cout<<"$1 ka name "<<$1->name<<endl;
		  if($1->name==""){

			cout<<"is a number "<<$1->type<<endl;
			$$=$1;
			$$->param_types.push_back($1->type);
			$$->param_list.push_back(std::to_string(*(int*)($1->ptr)));
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
				$$->param_list.push_back(find_symbol->name);
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
			$$->param_list.push_back(std::to_string(*(int*)($1->ptr)));
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
				$$->param_list.push_back(find_symbol->name);
			}
			
			cout<<"Ass exp111 "<<$1->type<<endl;
		  }
			
           
       }
    ;

unary_expression
	: postfix_expression 
	{
		$$=$1;
		// cerr << "postfix expression found: " << $1->type << endl;
        
	}
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression {
		symbol_info* new_symbol=new symbol_info();
		
		// file<<"cast ka place "<<$2->place.first<<endl;
		string original_type=$2->type;
		$$=new_symbol;
		if($1->code=="&"){
			$$->type=original_type+"*";
			
		}
        if($1->code=="*"){
            if(original_type.back()!='*') cerr<<"ERROR!!!!!! star applied to non pointer"<<endl;
            else{
				$$->type=original_type;
				$$->type.pop_back();
			}
        }
		
		$$->name=$2->name;
		$$->code=$2->code+"\n"+$1->code+$2->place.first;
		$$->place.first=$1->code+$2->place.first;
		// file<<"cast ka code ffff"<<$$->code<<endl;
		cerr<<"Found unary_operator "<<endl;
	}
	| SIZEOF unary_expression
	| SIZEOF LPARENTHESES type_name RPARENTHESES
	;

unary_operator
	: AMPERSAND {
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="ampersand";
		$$->code="&";
        $$->pointer_depth++;
		cerr<<"ampersand "<<endl;
	}
	| STAR
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="star";
		$$->code="*";
	}
	| PLUS
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="plus";
		$$->code="+";
	}
	| MINUS
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="minus";
		$$->code="-";
	}
	| TILDE
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="tilde";
		$$->code="~";
	}
	| EXCLAMATION
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->name="exclamation";
		$$->code="!";

	}
	;

cast_expression
	: unary_expression 
	{
		$$=$1;
		cerr<<"found unnnnary expree"<<endl;
		// printf("Unary expression %s\n",$$->name.c_str());
		
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
		cerr<<"condiiiiiii"<<endl;
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		$$=$1;
		// printf("cond expression = %s\n",$1->type.c_str());
		// printf("cond expression2 = %s\n",$1->name.c_str());
		cerr << "condi expression found: " << $1->type << endl;
        
	}
	| unary_expression assignment_operator assignment_expression 
	{
		printf("unary inside assignment = %s\n",$1->name.c_str());
		printf("Assignment expression = %s\n",$1->type.c_str());
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
                cerr<<"idharrrrrrrrrrrrrrrr"<<endl;
                cerr<<find_symbol->type<<endl;
                cerr<<$3->type<<endl;
                if(min(type_priority[$1->type],type_priority[$3->type])==0 && $1->type!=$3->type){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }
                if(type_priority[$1->type]<type_priority[$3->type]){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }else{
                    printf("Correct type assignment\n");
                }
                string third_code=$3->code;
                string first_code=$1->code;
                cerr<<$3->type<<endl;
                if(min(type_priority[$1->type],type_priority[find_symbol->type])>0) find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[$3->type])];
				
                find_symbol->name=$1->name;
                find_symbol->place=$1->place;
                find_symbol->code=$1->code + "\n" + $3->code + "\n" + $1->place.first + ":=  " + $3->place.first;
                //file<<find_symbol->code<<endl;
                
                

                //3AC code
                cerr<<"3AC code for assignment"<<endl;
				if($3->place.first[0]!='t' && $3->place.first[0]!='&' && $3->place.first[0]!='*' && $3->place.first[0]!='+' && $3->place.first[0]!='-' && $3->place.first[0]!='~' && $3->place.first[0]!='!')
				{
					$3->code="";
				}
				int flag=0;
				if($1->place.first[0]=='*'){
					int count_init_starr=count_init_star($1->place.first);
					if(count_init_starr>1){
						flag=1;
						string code="";
						qid temp=newtemp($1->type,curr_scope);
						string prev=($1->place.first).erase(0,count_init_starr);
						for(int i=0;i<count_init_starr;i++){
							code=code+"\n"+temp.first+":= *"+prev;
							prev=temp.first;
							temp=newtemp($1->type,curr_scope);
						}
						$$->code=$1->code+"\n"+$3->code+"\n"+code;
						$$->place=temp;
					}
				}
                if(flag==0){
                    if(find_symbol->is_array==true){
                        string code=remove_equal(first_code);

                        $$->code=$3->code+"\n"+code+":= "+$3->place.first;
                    }
                    else{
                         // file<<"find symbol ka codeeee "<<third_code<<endl;
                        $$->code=$1->code + "\n" + third_code + "\n" + $1->place.first + ":=  " + $3->place.first;
                        $$->place=$1->place;
                    }
                   
				} 
                // file<<"hiiiiiiiiiiiii "<<$$->code<<endl;
				
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
        cerr<<"IDHAR HU MAIIII2"<<endl;
        $$=$1;
        // file<<"Assignment expression = "<<$1->code<<endl;
		// cout<<"Assignment expression = "<<$1->code<<endl;
		// file<<$1->code<<endl;
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
		cerr<<"hi"<<endl;
		cerr<<"parsing stack top = "<<parsing_stack.top().c_str()<<endl;
		cerr<<"Declaration specifiers = "<<$1<<endl;
		cerr<<"Init declarator list = "<<$2->name.c_str()<<endl;
		cerr<<"dollar 3 type = "<<$2->type<<endl;
		// while(!parsing_stack.empty()){
		// 	printf("top= %s\n",parsing_stack.top().c_str());
		// 	parsing_stack.pop();
		// }
		int flag=0;
		while (!parsing_stack.empty()) {
			std::string top_symbol = parsing_stack.top();  // Store the top of the stack
            int depth = pointer_info.top();
			parsing_stack.pop();  // Pop before using it in the map (avoids multiple lookups)
            pointer_info.pop();
			// Check if the symbol exists in the current scope
			if (curr_scope->symbol_map[top_symbol]->type!= ""){
				cerr<<"top ka type = "<<curr_scope->symbol_map[top_symbol]->type.c_str()<<endl;
                if(depth!=count_star(curr_scope->symbol_map[top_symbol]->type)){
                    cerr<<("Error: Pointer depth mismatch\n")<<endl;
                    flag = 1;
                }

				if (type_priority[$1] < type_priority[curr_scope->symbol_map[top_symbol]->type]) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
				// file<<"decl ka code "<<$2->code<<endl;
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                if(type_priority[$1]>0 && type_priority[curr_scope->symbol_map[top_symbol]->type]>0) curr_scope->symbol_map[top_symbol]->type = priority_to_type[max(type_priority[$1], type_priority[curr_scope->symbol_map[top_symbol]->type])];
                else{
                    cout<<"ERROR!!!!!!: Type mismatch in declaration\n";
                }
				$$->code = $2->code;

			} else {
				// Create new symbol_info and assign type = $1
				curr_scope->symbol_map[top_symbol]->type = $1;
                for(int i=0;i<depth;i++){
                    curr_scope->symbol_map[top_symbol]->type+="*";
                }
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                curr_scope->symbol_map[top_symbol]->pointer_depth = depth;
				cerr<<"Created new symbol: "<<top_symbol.c_str()<<" with type "<<($1)<<endl;
				symbol_info* new_symbol = new symbol_info();
				new_symbol = $2;
				$$=new_symbol;
			}
		}
		
		// $$->code = $2->code;
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
		cerr<<("init_d %s\n",$$->name.c_str())<<endl;  
    }
    | init_declarator_list COMMA init_declarator { 
		$$=$3;
		$$->code = $1->code + "\n" + $3->code;
		printf("init_D %s\n",$$->name.c_str()); 
    }
    ;

init_declarator
    : declarator { 
		cerr<<("declarator11 %s\n",$1->name.c_str())<<endl;
		if(lookup_symbol_global($1->name, curr_scope)!=nullptr){
			printf("Redeclaration error \n"); 
			exit(1);
		}
        cerr<<"hiiii"<<endl;
        symbol_info* new_symbol = new symbol_info();
        new_symbol=$1;
		curr_scope->symbol_map[$1->name]=new_symbol;
        $$ =new_symbol;
		cerr<<"declarator "<<$$->name.c_str()<<endl; 
		parsing_stack.push($1->name.c_str());
        pointer_info.push($1->pointer_depth);
    }
    | declarator EQUALS initializer { 
		printf("declaratoreiii %s\n",$1->name.c_str());
		if(lookup_symbol_local($1->name, curr_scope)!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		curr_scope->symbol_map[$1->name]=$3;
		if($3->type=="float") printf("Yes float found\n");
		if($3->type=="int") printf("Yes int found\n");
		if($3->type=="char") printf("Yes char found %s\n",$3->str_val.c_str());
		parsing_stack.push($1->name.c_str());
        pointer_info.push($1->pointer_depth);
		if($1->is_array){
			if($3->int_array.size() > $1->array_length){
				printf("Error: Elements Greater than Declared\n");
			}
			else{
				$1->int_array = $3->int_array;
				$1->type = $3->type;
				curr_scope->symbol_map[$1->name]->is_array=true;
				string code=$1->name+":= alloc " +to_string(4*$1->array_length);
				for(int i=0;i<$1->array_length;i++){
					qid temp=newtemp($1->type,curr_scope);
					code=code+"\n"+temp.first+":= "+to_string(i)+"*4";
					code=code+"\n"+"*( "+$1->name+" + "+temp.first+" ):= "+to_string(*(int*)($1->int_array[i]->ptr));
				}
				// file<<code<<endl;
				$$->code=code;
			}
		}
        if($1->is_array==false){
			$$ = $1;
		if($3->place.first[0]!='t' && $3->place.first[0]!='&' && $3->place.first[0]!='*' && $3->place.first[0]!='-' && $3->place.first[0]!='!'){
			$3->code="";
		}
		
		$$->code=$3->code+"\n"+$1->place.first+":= "+$3->place.first;
		$$->place=$1->place;
		
		printf("declarator equals initializer %s\n",$$->name.c_str()); 
		}
		
		
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
        $$=$2;
        $$->pointer_depth=$1->pointer_depth;
		cerr<<"Pointer direct declarator with depth "<<$$->pointer_depth<<endl;
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
	| direct_declarator LBRACKET constant_expression RBRACKET			
    {
        $$->is_array = true;
        if($3->type=="int"){
            $$->array_length = *(int*)($3->ptr);
            printf("Array length = %d\n",$$->array_length);
        }
        else{
            printf("Error: Array size not an integer\n");
            $$->array_length=100;
        }
    }
	| direct_declarator LBRACKET RBRACKET								{printf("Array Size not declared\n"), $$->is_array = true, $$->array_length = 100;}
	| direct_declarator LPARENTHESES parameter_type_list RPARENTHESES     
	{
		printf("Brackets found with parameter= %s\n",$1->name.c_str());
		printf("Par list %d\n",$3->parameter_no);
		cerr<<"param list size "<<$3->param_list.size()<<endl;
		for(auto it: $3->param_types)
					{
						cout<<it<<endl;
					}
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type=$1->type;
		new_symbol->parameter_no=$3->parameter_no;
		new_symbol->param_types=$3->param_types;
		new_symbol->param_list=$3->param_list;
		new_symbol->is_param_list=$3->is_param_list;
		new_symbol->name=$1->name;
		curr_scope->symbol_map[$1->name]=new_symbol;

		$$=new_symbol;
		cerr<<"has a parameter or not "<<$$->param_list.size()<<endl;
	}
	| direct_declarator LPARENTHESES identifier_list RPARENTHESES          //{printf("Brackets found in function calllll\n");}
	| direct_declarator LPARENTHESES RPARENTHESES
	{
		$$->is_param_list=false;
		cerr<<"It is function without params "<<endl;
		cerr<<"has a parameter or not "<<$$->is_param_list<<endl;
	}
	;

pointer
	: STAR {$$=new symbol_info(); $$->pointer_depth=1;}
	| STAR type_qualifier_list 
	| STAR pointer {$$=$2; $$->pointer_depth++;}   
	| STAR type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list{
		symbol_info* new_symbol=new symbol_info();
		$$->parameter_no=$1->parameter_no;
		$$->is_param_list=$1->is_param_list;
		$$->param_types=$1->param_types;
		$$->param_list=$1->param_list;
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
	: parameter_declaration
    {
        $$->is_param_list=true;
        $$->parameter_no=1;
        $$->param_types.push_back($1->type);
		$$->param_list.push_back($1->name);
    }
	| parameter_list COMMA parameter_declaration 
    {
        $$->is_param_list=true;
        cout<<"par num $1 "<<$1->parameter_no<<endl;
        cout<<"par num $3 "<<$3->parameter_no<<endl;
        $$->parameter_no=$1->parameter_no+$3->parameter_no;
        $$->param_types.push_back($3->type);
		$$->param_list.push_back($3->name);
    }
	
	;

parameter_declaration
	: declaration_specifiers declarator  
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->name=$2->name;
		$$->parameter_no=1;
		// printf("%s",$$->type);
	}
	| declaration_specifiers abstract_declarator{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->name=$2->name;
		// printf("%s",$$->type);
	}
	| declaration_specifiers{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->name="";
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
        cerr<<"IDHAR HU MAIIII"<<endl;
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
	{
		$$=$1;cerr<<"label\n";

	}
	| compound_statement
	{
		$$=$1;

		//file<<$$->code<<endl;
	}
	| expression_statement
	| selection_statement{$$=$1;}
	| iteration_statement{$$=$1;}
	| jump_statement{$$=$1;
	cout<<$$->is_break<<"break check in statement"<<endl;}
	;

labeled_statement
	: ID COLON statement
	{

		// curr-scope->symbol_map[$1]=new symbol_info();
		// curr_scope->symbol_map[$1]->name=$1;
		// curr_scope->symbol_map[$1]->type="label";
		cerr<<"ID COLON statement"<<$1<<endl;
	}
	| ID COLON declaration{
		cerr<<"ID COLON declaration"<<$1<<endl;
	}
	| ID COLON
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	;

compound_statement
	: LBRACE RBRACE
	| LBRACE 
	{
		curr_scope = new scoped_symtab(curr_scope);
		cerr<<"inside compound stt"<<endl;
		for(int i=0;i<var_name.size();i++){
			cerr<<"fffff"<<var_name[i]<<endl;
			curr_scope->symbol_map[var_name[i]]=new symbol_info();
			curr_scope->symbol_map[var_name[i]]->type=type_list[i];
			curr_scope->symbol_map[var_name[i]]->name=var_name[i];
		}
		cerr<<"inside compound stt"<<endl;
		var_name={};
		type_list={};
	} 
	statement_declaration_list RBRACE 

	{
		cerr<<"inside compound sttttttttttttt"<<endl;
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
		$$->is_return=$3->is_return;
		$$->return_type=$3->return_type;
		
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
        
		//file<<$$->code<<endl; 
	}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} statement_list RBRACE {symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list RBRACE {symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list statement_list RBRACE {symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code+"\n"+$4->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	;

statement_declaration_list
	: statement_list statement_declaration_list
	{
        cerr<<"statement lis222222 found"<<endl;
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$1->code + "\n" + $2->code;
		$$->is_return=($1->is_return)|($2->is_return);
		if($1->return_type!="") $$->return_type=$1->return_type;
		else $$->return_type=$2->return_type;
		
        

	}
	| declaration_list statement_declaration_list
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
        cerr<<"statement list11111 found"<<endl;
		$$->code=$1->code + "\n" + $2->code;
		$$->is_return=$2->is_return;
		$$->return_type=$2->return_type;
		
        
		
	}
	| statement_list{
		
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$1->code;
		$$->is_return=$1->is_return;
		$$->return_type=$1->return_type;
		cerr<<"statement list found"<<$$->code<<endl;
		
		
	}
	| declaration_list
	{
		$$=$1;
		cerr<<"Hello?\n";
		//file<<$$->code<<endl;
	}
	;

declaration_list
	: declaration
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$1->code;
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
		cerr<<"statement list\n";

	}
	| statement_list statement
	{
		$$->is_return=($1->is_return)|($2->is_return);
		if($1->return_type!="") $$->return_type=$1->return_type;
		else $$->return_type=$2->return_type;
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
	{
		string truelabel=newlabel();	
		string falselabel=newlabel();
		$$->code=$3->code+"\n"+"if("+ $3->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+$5->code+"\n"+falselabel+":\n";
		//file<<$$->code<<endl;
	}
	| IF LPARENTHESES expression RPARENTHESES statement ELSE statement
	{
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		$$->code=$3->code+"\n"+"if("+ $3->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+$5->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+$7->code+"\n"+endlabel+":\n";
		//file<<$$->code<<endl;
	}      //{printf("It is in if-else block\n");}
	| SWITCH LPARENTHESES expression RPARENTHESES statement					//{printf("It is in switch block\n");}
	;

iteration_statement
	: WHILE LPARENTHESES expression RPARENTHESES statement
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=startlabel+":\n"+$3->code+"\n"+"if("+$3->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$5->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
		$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
	}
	| DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=startlabel+":\n"+$2->code+"\n"+truelabel+":\n"+$5->code+"\n"+"\n"+"if("+$5->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
	}
	| FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code+"\n"+startlabel+":\n"+$4->code+"\n"+"if("+$4->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$6->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
		// file<<$$->code<<endl;
	}
	| FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement   
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		string updatelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		
		$$->code=$3->code+"\n"+startlabel+":\n"+$4->code+"\n"+"if("+$4->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$7->code+"\n"+updatelabel+":\n"+$5->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";

			$$->code=replace_break_continue($$->code,endlabel,updatelabel,0);
		
		// file<<$$->code<<endl;
		}
	;

jump_statement
	: GOTO ID SEMICOLON				
	{ 
		//printf("Goto statement: %s\n",$2);
		//idhar ID ko symtab me insert karna he
		goto_list.push_back($2);
		cerr << "goto\n";
	}
	| CONTINUE SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_continue=true;
		$$->code="\n continue \n";
	}
	| BREAK SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_break=true;
		$$->code="\n break \n";
	}
	| RETURN SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_return=true;
		$$->return_type="void";
		$$->code="\nRETURN\n";
	}
	| RETURN expression SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_return=true;
		$$->return_type=$2->type;
		$$->code=$2->code + "\nRETURN "+$2->place.first+"\n";
	}
	;

start_symbol: translation_unit
{
	file<<$1->code<<endl;
}
;
translation_unit
	: external_declaration 				 
	{
		$$->code=$1->code;
		// file<<$$->code<<endl;
	}   //{printf("Reached the root node.\n");}
	| translation_unit external_declaration //{printf("Reached the root node.\n");}
	{
		$$->code=$1->code+$2->code;
		// file<<$$->code<<endl;
	}
	| 
	;

external_declaration
	: function_definition 
	{
		$$=$1;
	}
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator
	{
		var_name=$2->param_list;
		type_list=$2->param_types;
	} 
	compound_statement 
	{
		cerr<<"function definition ke right "<<$2->is_param_list<<endl;
		// for(auto it:$2->param_list){
		// 	cerr<<it<<endl;
		// }
		// cerr<<"function def endddd"<<endl;
		//abhi ke liye
		// cerr<<"decl spee "<<$1<<endl;
		
		// cerr<<"decl spee "<<$1<<"mmmm"<<endl;
        if(strcmp($1,"void")==0){
		
			if($4->return_type=="void"){
				cerr<<"Return type matched"<<endl;
			}
			else{
				cerr<<"Error: Return type not matched"<<endl;
			}
		}
		else{
			cerr<<"hellllo"<<endl;
			if($4->is_return==0){
				cerr<<"Error: Missing return statement"<<endl;
			}
			else{
				if($4->return_type!=$1){
					cerr<<"Error: Return type not matching"<<endl;
				}
				else{
					cerr<<"Return type matched"<<endl;
				}
			}
		}
		cout<<"ffffnnnnname"<<$2->name<<"fffffnnnnnn"<<endl;
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code="FUNC_BEGIN "+$2->name+"\n";
		for(int i=0;i<$2->param_list.size();i++){
			$$->code=$$->code+"param"+std::to_string(i)+" := PARAM\n";
		}
		for(int i=0;i<$2->param_list.size();i++){
			$$->code=$$->code+$2->param_list[i]+" := param"+std::to_string(i)+"\n";
		}
		$$->code=$$->code+$4->code+"FUNC_END "+$2->name+"\n";


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
	cleanTAC("output.txt", "cleaned_output.txt");
	file.close();
}
