%{
	#include <functions.h>
    using namespace std;

	#define MAX_ARGS 100

    void yyerror(const char *s);
	void print_errors();
	void codegen_main();

    extern int yylex();
    extern int yylineno;
    extern char *yytext; 

    vector<pair<string,scoped_symtab*>> cleaned_TAC;
	vector<pair<scoped_symtab*,string>> static_variables;
	vector<pair<string,scoped_symtab*>> static_variables_code;

	std::stack<std::string> parsing_stack;
    std::stack<int> pointer_info;
	std::map<std::string,std::string> type_def_mapping;

    scoped_symtab* curr_scope = new scoped_symtab();
    std::vector<scoped_symtab*> all_scopes={curr_scope};

    std::vector<std::string> error_list;
	vector<scoped_symtab*> scope_list;
    vector<string> type_list = {};
	vector<string> var_name={};
	map<string,string> goto_list;
    stack<queue<pair<string,string>>> case_list;

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
%token AUTO STRUCT BOOL BREAK CASE CONTINUE GOTO DO DEFAULT IF ELSE FOR CONST TRUE FALSE STATIC SWITCH WHILE UNTIL VOID RETURN SIZEOF FLOAT INT DOUBLE EXTERN SHORT LONG CHAR ENUM REGISTER SIGNED TYPEDEF UNION UNSIGNED VOLATILE 
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
    | STRING_LITERAL     
	{
		$$ = new symbol_info("", "char*", $1->ptr, $1->symbol_size);
        $$->str_val=$1->str_val;
        $$->place=qid($1->str_val,nullptr);
        $$->code=$1->str_val;
	}
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
            symbol_info* new_symbol = new symbol_info($1);
            $$ = new_symbol;
            
			//3AC code
			symbol_info* find_symbol = lookup_symbol_global($1, curr_scope);
			if(find_symbol==nullptr){
                error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+$1);
			}
			else{
				$$->place=qid($1,find_symbol);
				$$->code="";
				$$->type=find_symbol->type;
				$$->is_array=find_symbol->is_array;
			}
        }
	| constant		
	{
		$$ = $1;
	}
	| STRING_LITERAL 
	| LPARENTHESES expression RPARENTHESES
	{
		symbol_info* new_symbol = new symbol_info();
		new_symbol->place=newtemp($2->type,curr_scope);
		new_symbol->type=$2->type;
		// debug("here ",new_symbol->place.first);
        string temp=new_symbol->place.first+" := ( "+$2->place.first+" )";
        new_symbol->final_code = $2->final_code;
        new_symbol->final_code.push_back({temp,curr_scope});
		new_symbol->code=$2->code+"\n"+temp;
		$$=new_symbol;
	}
	;

postfix_expression
	: primary_expression 
        {
            $$=$1;
        }
	| postfix_expression LBRACKET expression RBRACKET
	{
		string array_name=$1->name;
		symbol_info* find_symbol = lookup_symbol_global(array_name, curr_scope);
		if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+array_name);
		}
		else{
			if(find_symbol->is_array==false){
                error_list.push_back("Line "+to_string(yylineno)+" : Not an array "+array_name);
			}
			else{
                string code=$3->code;
                qid temp=newtemp("int",curr_scope);

                string add_str="";
                if(find_symbol->type=="int"){
                    add_str=temp.first+" := "+"4 * "+$3->place.first;
					// code=code+"\n"+temp.first+":= "+"4 * "+$3->place.first;
				}
				else if(find_symbol->type=="float"){
                    add_str=temp.first+" := "+"4 * "+$3->place.first;
					// code=code+"\n"+temp.first+":= "+"4 * "+$3->place.first;
				}
				else if(find_symbol->type=="char"){
                    add_str=temp.first+" := "+"2 * "+$3->place.first;
					// code=code+"\n"+temp.first+":= "+"2 * "+$3->place.first;
				}

                qid temp2=newtemp(find_symbol->type,curr_scope);
                $$->final_code = $3->final_code;
                $$->final_code.push_back({add_str,curr_scope});
                code = code + "\n" + add_str;
                add_str = temp2.first+" := *( "+$1->place.first+" + "+temp.first+" )";
                $$->final_code.push_back({add_str,curr_scope});
                code=code+"\n"+add_str;
                $$->code=code;
                $$->place.first=temp2.first;
			}
			
		}
	}
	| postfix_expression LPARENTHESES RPARENTHESES		
    {
        symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
        if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared function "+$1->name);
        }
        else{
            std::vector<std::string> original_list=find_symbol->param_types;
            if($1->name=="printf"){
                    error_list.push_back("Line "+to_string(yylineno)+" : Empty printf statement");
				}
                else if( $1->name=="scanf"){error_list.push_back("Line "+to_string(yylineno)+" : Empty scanf statement");}
                else if($1->name=="sizeof"){error_list.push_back("Line "+to_string(yylineno)+" : Sizeof operator cannot be used with function call");}
                else if(original_list.size()>0)
                {
                    error_list.push_back("Line "+to_string(yylineno)+" : Size of actual and formal parameter list does not match");
                }
        }
            qid temp=newtemp($1->type,curr_scope);
            if(find_symbol->type!="void"){
                $$->final_code = $1->final_code;
                string add_str=$1->code + temp.first+" := CALL "+$1->place.first;
                $$->code=add_str + "\n";
                $$->final_code.push_back({add_str,curr_scope});
                $$->place=temp;
                $$->type=find_symbol->type;
            }
            else{
                $$->final_code = $1->final_code;
                string add_str=$1->code + "CALL "+$1->place.first;
                $$->code=add_str + "\n";
                $$->final_code.push_back({add_str,curr_scope});
                $$->type=find_symbol->type;
            }
			
    }		
	| postfix_expression LPARENTHESES argument_expression_list RPARENTHESES   
	    {
            $$ = new symbol_info();
			symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
			if(find_symbol == nullptr) {
                error_list.push_back("Line "+to_string(yylineno)+" : Undeclared function "+$1->name);
			}
			else{
		  		std::vector<std::string> original_list=find_symbol->param_types;
				std::vector<std::string> new_list=$3->param_types;

				if($1->name!="printf" && $1->name!="scanf" && original_list.size()!=new_list.size()){
                    error_list.push_back("Line "+to_string(yylineno)+" : Size of actual and formal parameter list does not match");
				}
				else{
					for(int i=0;i<original_list.size();i++){
						if(type_priority[original_list[i]]<type_priority[new_list[i]]){
							//cout<<"Error: Type of actual and formal parameter does not match"<<endl;
							break;
						}
					}
				}

			}
			qid temp=newtemp($1->type,curr_scope);
			string middle="";
            vector<pair<string,scoped_symtab*>> temp_list;
			for(int i=0;i<$3->param_list.size();i++){
				middle=middle+"PARAM "+$3->param_list[i]+"\n";
                int star=0;
                string temp_str="";
                if($3->param_list[i][0]=='*')
                {
                     while($3->param_list[i][0]=='*')
                    {
                        star++;
                        $3->param_list[i]=$3->param_list[i].substr(1);
                    }
                    temp_str=$3->param_list[i];
                    while(star)
                    {
                        qid temp2=newtemp("int",curr_scope);
                        temp_list.push_back({temp2.first+" := *"+temp_str,curr_scope});
                        temp_str=temp2.first;
                        star--;
                    }
                    temp_list.push_back({"PARAM "+temp_str,curr_scope});
                }
              
               else temp_list.push_back({"PARAM "+$3->param_list[i],curr_scope});                
			} 
            if(find_symbol->type!="void"){
                // debug("idhar",$1->code);  
                $$->final_code = $1->final_code;
                $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                string add_str = middle + temp.first+" := CALL "+$1->place.first + ","+to_string($3->param_list.size());
                $$->code=$1->code + "\n"+ $3->code + "\n"+ add_str + "\n";
                $$->final_code.insert($$->final_code.end(), temp_list.begin(), temp_list.end());
                $$->final_code.push_back({temp.first+" := CALL "+$1->place.first + ","+to_string($3->param_list.size()),curr_scope});
                $$->place=temp;
                $$->type=find_symbol->type;
            }else{
                $$->final_code = $1->final_code;
                $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                string add_str = middle + "CALL "+$1->place.first + ","+to_string($3->param_list.size());   
                $$->final_code.insert($$->final_code.end(), temp_list.begin(), temp_list.end());
                $$->final_code.push_back({"CALL "+$1->place.first + ","+to_string($3->param_list.size()),curr_scope});
                $$->code=$1->code + "\n"+ $3->code + "\n"+add_str + "\n";
                $$->type=find_symbol->type;
            }
        }
	| postfix_expression DOT ID
	{
		symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
		if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+$1->name);
		}
		else{
			if((find_symbol->type).substr(0,6)=="struct"){
				symbol_info* find_struct;
				if((find_symbol->type).substr(0,6)=="struct") find_struct=lookup_symbol_global((find_symbol->type).substr(7), curr_scope);
				int flag=0;
				string var_type="";
				int offset=0;
				for(int i=0;i<find_struct->param_list.size();i++){
					if(find_struct->param_list[i]==$3){
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
					offset+=get_size(find_struct->param_types[i]);

				}
				if(flag==0){
                    error_list.push_back("Line "+to_string(yylineno)+" : No such attribute found in struct or union "+$1->name);
				}
				else{
					parsing_stack.push($1->name);
					parsing_stack.push($3);
					parsing_stack.push(to_string(offset));
					parsing_stack.push(var_type);
					
					find_symbol->name=$1->name;
					$$=find_symbol;
				}
				
			}
			else if((find_symbol->type).substr(0,5)=="union")
			{
				symbol_info* find_struct;
				if((find_symbol->type).substr(0,5)=="union") find_struct=lookup_symbol_global((find_symbol->type).substr(6), curr_scope);
				int flag=0;
				string var_type="";
				int offset=0;
				for(int i=0;i<find_struct->param_list.size();i++){
					if(find_struct->param_list[i]==$3){
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
					// offset=max(offset,get_size(find_struct->param_types[i]));

				}
				if(flag==0){
                    error_list.push_back("Line "+to_string(yylineno)+" : No such attribute found in struct or union "+$1->name);
				}
				else{
					parsing_stack.push($1->name);
					parsing_stack.push($3);
					parsing_stack.push(to_string(offset));
					parsing_stack.push(var_type);
					
					find_symbol->name=$1->name;
					$$=find_symbol;
				}
			}
			else{
                error_list.push_back("Line "+to_string(yylineno)+" : Not a struct or union "+$1->name);
			}
			
		}
	}
	| postfix_expression LAMBDA_ARROW ID
	| postfix_expression INCREMENT
	{
		if($1->is_array==true){
			string code = get_last_line($1->code);
			
            string add_str=code+" := "+code+" + 1";
            $$->code=$1->code + "\n" + add_str + "\n";
            $$->final_code = $1->final_code;
            $$->final_code.push_back({add_str,curr_scope});
		}
		else  {
            $$->final_code = $1->final_code;
            string add_str= $1->place.first+" :=  "+$1->place.first+" + 1 ";
            $$->code=$1->code + "\n" + add_str + "\n";
            $$->final_code.push_back({add_str,curr_scope});
        }
		
	}
	| postfix_expression DECREMENT
	{
		if($1->is_array==true){
			string code = get_last_line($1->code);
            string add_str=code + " := "+code+" - 1 ";
			$$->code=$1->code + "\n" + add_str+"\n";
            $$->final_code = $1->final_code;
            $$->final_code.push_back({add_str,curr_scope});
		}
		else  {
            string add_str= $1->place.first+" :=  "+$1->place.first+" - 1 ";
            $$->final_code = $1->final_code;
            $$->code=$1->code + "\n" + add_str + "\n";
            $$->final_code.push_back({add_str,curr_scope});
        }
	}
	;

argument_expression_list
    : assignment_expression
    { 
		if($1->place.first!=""){
			// debug("herrrr ", $1->code);
			$$->code=$1->code;
            $$->final_code = $1->final_code;
			$$->param_types.push_back($1->type);
			$$->param_list.push_back($1->place.first);
		}
		else{
			if($1->name==""){
				$$=new symbol_info($1);
				$$->param_types.push_back($1->type);
				if($1->type=="int")$$->param_list.push_back(std::to_string(*(int*)($1->ptr)));
				else if($1->type=="float")$$->param_list.push_back(std::to_string(*(float*)($1->ptr)));
				else if($1->type=="char")$$->param_list.push_back(std::to_string(*(char*)($1->ptr)));
				else if($1->type=="char*")$$->param_list.push_back($1->str_val);
			}
			else{
				symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
				if(find_symbol == nullptr) {
					error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+$1->name);
				}
				else{
					$$=new symbol_info(find_symbol);
					$$->param_types.push_back(find_symbol->type);
					$$->param_list.push_back(find_symbol->name);
				}
			} 
		}
        
      }
    | argument_expression_list COMMA assignment_expression

        { 
			if($3->place.first!=""){
                $$->final_code = $1->final_code;
                $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
				$$->code=$1->code + "\n" + $3->code;
				//debug("herrrrrrrrrrr ", $3->place.first);
				$$->param_types.push_back($1->type);
				$$->param_list.push_back($3->place.first);
			}
			else{
				if($3->name==""){
                $$=new symbol_info($1);
                //check 1 or 3
                $$->param_types.push_back($3->type);
                if($3->type=="int")$$->param_list.push_back(std::to_string(*(int*)($3->ptr)));
                else if($3->type=="float")$$->param_list.push_back(std::to_string(*(float*)($3->ptr)));
                else if($3->type=="char")$$->param_list.push_back(std::to_string(*(char*)($3->ptr)));
                else if($3->type=="char*")$$->param_list.push_back($3->str_val);
            }
            else{
                symbol_info* find_symbol = lookup_symbol_global($3->name, curr_scope);
                if(find_symbol == nullptr) {
                    error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+$3->name);
                }
                else{
                    $$=new symbol_info($1);
                    $$->param_types.push_back(find_symbol->type);
                    $$->param_list.push_back(find_symbol->name);
                }
            } 
			}
                      
        }
    ;

unary_expression
	: postfix_expression 
	{
		$$=$1;        
	}
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression 
    {
		symbol_info* new_symbol=new symbol_info();
		string original_type=$2->type;
		$$=new_symbol;

		if($1->code=="&"){
			$$->type=original_type+"*";
		}
        if($1->code=="*"){
            if(original_type.back()!='*') error_list.push_back("Line "+to_string(yylineno)+" : Trying to dereference non pointer "+$2->name);
            else{
				$$->type=original_type;
				$$->type.pop_back();
			}
        }
		
		$$->name=$2->name;
        string add_str=$1->code+$2->place.first;
        $$->final_code = $2->final_code;
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$2->code+"\n"+add_str+"\n";
		$$->place.first=$1->code+$2->place.first;
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
	}
	| LPARENTHESES type_name RPARENTHESES cast_expression
    {
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
        string add_str=var.first+" :=  "+$1->place.first+" * "+$3->place.first;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	}
	| multiplicative_expression DIVIDE cast_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        qid var=newtemp($1->type,curr_scope);
        string add_str=var.first+" :=  "+$1->place.first+" / "+$3->place.first;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
        $$->place=var;
    }
	| multiplicative_expression MODULO cast_expression
    {
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : Modulo operator can only be used with int type");
        }
        qid var=newtemp($1->type,curr_scope);
        string add_str=var.first+" :=  "+$1->place.first+" % "+$3->place.first;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" + "+$3->place.first + "\n";
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str;
		$$->place=var;
	}
	| additive_expression MINUS multiplicative_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" - "+$3->place.first + "\n";
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str;
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
            error_list.push_back("Line "+to_string(yylineno)+" : Left shift operator can only be used with int type");
        }
		qid var=newtemp($1->type,curr_scope);
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" << "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	}
	| shift_expression RIGHT_SHIFT additive_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
        if($$->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : Right shift operator can only be used with int type");
        }
		qid var=newtemp($1->type,curr_scope);
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" >> "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" < "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	}
	| relational_expression GREATER_THAN shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];        
		qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" > "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
		$$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	}
	| relational_expression LESS_EQUALS shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" <= "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	
	}
	| relational_expression GREATER_EQUALS shift_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" >= "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" == "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
		$$->place=var;
	}
	| equality_expression REL_NOT_EQ relational_expression
	{
        $$ = $1;
        $$->type = priority_to_type[max(type_priority[$1->type],type_priority[$3->type])];
		qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" != "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
            error_list.push_back("Line "+to_string(yylineno)+" : And operator can only be used with int type");
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
            error_list.push_back("Line "+to_string(yylineno)+" : XOR operator can only be used with int type");
        }
        qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" ^ "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
        qid var=newtemp($1->type,curr_scope);
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        string add_str=var.first+" :=  "+$1->place.first+" | "+$3->place.first;
        $$->final_code.push_back({add_str,curr_scope});
        $$->code=$1->code + "\n" + $3->code +"\n" + add_str + "\n";
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
            error_list.push_back("Line "+to_string(yylineno)+" : AND operator can only be used with int type");
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
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
    }
	;

conditional_expression
	: logical_or_expression 			{$$=$1;}
	| logical_or_expression QUESTION_MARK expression COLON conditional_expression
	;

assignment_expression
	: conditional_expression			{$$=$1;}
	| unary_expression assignment_operator assignment_expression 
	{
		$$ = new symbol_info();
        symbol_info* find_symbol = lookup_symbol_global($1->name, curr_scope);
        if(find_symbol != nullptr) {
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				if(parsing_stack.top()==$3->type){
					//Semantic Analysis
					parsing_stack.pop();
					string offset = parsing_stack.top();
					parsing_stack.pop();
					string attr=parsing_stack.top();
					parsing_stack.pop();
					string struct_inst_name=parsing_stack.top();
					parsing_stack.pop();
					symbol_info* find_struct=lookup_symbol_global(struct_inst_name, curr_scope);
					find_struct->param_list.push_back(attr);
					find_struct->struct_attr_values.push_back($3);
                    //checkerror
					//3AC code kabhi toh karenge
					qid var=newtemp(find_symbol->type,curr_scope);
                    $$->final_code = $1->final_code;
                    $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                    string add_str=var.first+" := "+$1->place.first+" + "+offset;
					string tempo="";
					tempo=tempo+$1->code;
					tempo=tempo+"\n"+$3->code;
					tempo=tempo+"\n"+add_str;
                    $$->final_code.push_back({add_str,curr_scope});
                    add_str="*"+var.first+" := "+$3->place.first;
					tempo=tempo+"\n"+add_str + "\n";
                    $$->final_code.push_back({add_str,curr_scope});
					$$->code=$$->code + tempo;
					$$->place=var;	
				}
				else{
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment of struct or union attributes");
				}
			}
			else{
                if(find_symbol->type=="char*"){
                    error_list.push_back("Line "+to_string(yylineno)+" : char* is not modifiable");
                }
                if(min(type_priority[$1->type],type_priority[$3->type])==0 && $1->type!=$3->type){
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment");
                }
                if(type_priority[$1->type]<type_priority[$3->type]){
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment");
                }
                string third_code=$3->code;
                string first_code=$1->code;
                if(min(type_priority[$1->type],type_priority[find_symbol->type])>0) find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[$3->type])];
				
                find_symbol->name=$1->name;
                find_symbol->place=$1->place;
                find_symbol->final_code=$1->final_code;
                find_symbol->final_code.insert(find_symbol->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                string add_str=$1->place.first + ":=  " + $3->place.first;
                find_symbol->final_code.push_back({add_str,curr_scope});
                find_symbol->code=$1->code + "\n" + $3->code + "\n" + add_str + "\n";

                //3AC code
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
                        $$->final_code = $1->final_code;
                        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                        string add_str;
						for(int i=0;i<count_init_starr-1;i++){
                            add_str=temp.first+" := *"+prev;
							code=code+"\n"+add_str;
                            $$->final_code.push_back({add_str,curr_scope});
							prev=temp.first;
							temp=newtemp($1->type,curr_scope);
						}
                        add_str="*"+prev+" := "+$3->place.first;
						code=code+"\n"+add_str+"\n";
                        $$->final_code.push_back({add_str,curr_scope});
						$$->code=$1->code+"\n"+$3->code+"\n"+code;
						$$->place=temp;
					}
				}
				if($3->place.first[0]=='*'){
					int count_init_starr=count_init_star($3->place.first);
					if(count_init_starr>1){
						flag=1;
						string code="",add_str="";
						qid temp=newtemp($3->type,curr_scope);
						string prev=($3->place.first).erase(0,count_init_starr);
                        $$->final_code = $1->final_code;
                        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
						for(int i=0;i<count_init_starr-1;i++){
                            add_str=temp.first+" := *"+prev;
                            $$->final_code.push_back({add_str,curr_scope});
							code=code+"\n"+add_str;
							prev=temp.first;
							temp=newtemp($3->type,curr_scope);
						}
                        add_str=$1->place.first+" := *"+temp.first;
						code=code+"\n"+add_str+"\n";
                        $$->final_code.push_back({add_str,curr_scope});
						$$->code=$1->code+"\n"+$3->code+"\n"+code;
						$$->place=$1->place;
					}
				}
                if(flag==0){
                    if(find_symbol->is_array==true){
                        string code=remove_equal(first_code);
                        $$->final_code = $3->final_code;
                        $$->final_code.push_back({add_str,curr_scope});
                        add_str = code + " := " + $3->place.first;
                        int index=0;
                        string temp="";
                        while(index<add_str.length()){
                            while(index<add_str.length() && add_str[index]!='\n'){
                                temp+=add_str[index];
                                index++;
                            }
                            index++;
                            $$->final_code.push_back({temp,curr_scope});
                            temp="";
                        }
                        $$->code=$3->code+"\n"+add_str+"\n";
                    }
                    else{
                        string op=$2->code;
                        string tcode=get_assignment_statement($1->place.first,op,$3->place.first);
                        
                        if(tcode=="error"){
                            error_list.push_back("Line "+to_string(yylineno)+" : Invalid assignment operator");
                        }
                        $$->final_code = $1->final_code;
                        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
                        $$->final_code.push_back({tcode,curr_scope});
                        $$->code=$1->code + "\n" + third_code + "\n" + tcode+"\n";
                        $$->place=$1->place;
                    }                   
				} 				
			}
			
		}
        else{
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared symbol "+$1->name);
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
        $$=$1;
	}	
	| expression COMMA assignment_expression
	{
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
		$$->code=$1->code + "\n" + $3->code;
	}
	;

constant_expression
	: conditional_expression{$$=$1;}
	;

declaration
    : declaration_specifiers SEMICOLON
    | declaration_specifiers init_declarator_list SEMICOLON 
    {
		if(std::string($1).substr(0, 7) == "typedef"){
			string new_type=parsing_stack.top();
			parsing_stack.pop();
			string old_type=std::string($1).substr(8);
			type_def_mapping[new_type]=old_type;
		}
		
		
		int flag=0;
		string code="";
		symbol_info* nsss=new symbol_info();
		$$=nsss;
		while (!parsing_stack.empty()) {
			std::string top_symbol = parsing_stack.top();
			
            int depth = pointer_info.top();
			
			parsing_stack.pop();
            pointer_info.pop();
			if (curr_scope->symbol_map[top_symbol]->type!= ""){
                if(depth!=count_star(curr_scope->symbol_map[top_symbol]->type)){
                    error_list.push_back("Line "+to_string(yylineno)+" : Pointer depth mismatch");
                    flag = 1;
                }

				if (type_priority[$1] < type_priority[curr_scope->symbol_map[top_symbol]->type]) {
					string left=$1;
					if(curr_scope->symbol_map[top_symbol]->type=="int" && left=="static,int"){
						static_variables.push_back({curr_scope,top_symbol});
					}
					else if (curr_scope->symbol_map[top_symbol]->type=="float" && left=="static,float"){
						static_variables.push_back({curr_scope,top_symbol});
					}
					else{
						error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in declaration");
						flag = 1;
					}
                    
				}
				
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                if(type_priority[$1]>0 && type_priority[curr_scope->symbol_map[top_symbol]->type]>0) curr_scope->symbol_map[top_symbol]->type = priority_to_type[max(type_priority[$1], type_priority[curr_scope->symbol_map[top_symbol]->type])];
                
				// debug("declaration specifiers121 ", $2->code);

				
				code=$2->code;

			} else {
				curr_scope->symbol_map[top_symbol]->type = $1;
				if(curr_scope->symbol_map[top_symbol]->type.substr(0,6)=="static"){
					static_variables.push_back({curr_scope,top_symbol});
					if(curr_scope->symbol_map[top_symbol]->type=="static,int"){
						static_variables_code.push_back({top_symbol+":= 0",curr_scope});
					}
					else if(curr_scope->symbol_map[top_symbol]->type=="static,float"){
						static_variables_code.push_back({top_symbol+":= 0.0",curr_scope});
					}
					
					
				}
                for(int i=0;i<depth;i++){
                    curr_scope->symbol_map[top_symbol]->type+="*";
                }
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                curr_scope->symbol_map[top_symbol]->pointer_depth = depth;

				if((curr_scope->symbol_map[top_symbol]->type).substr(0,6)=="struct")
				{
					string struct_name=(curr_scope->symbol_map[top_symbol]->type).substr(7);
					symbol_info* find_struct=lookup_symbol_global(struct_name, curr_scope);
					int size=0;
					for(int i=0;i<find_struct->param_list.size();i++){
						size+=get_size(find_struct->param_types[i]);
					}
					//debug("Struct size: ",to_string(size));
					code=code+top_symbol+":= alloc " +to_string(size)+"\n";
					

				}
				else if((curr_scope->symbol_map[top_symbol]->type).substr(0,5)=="union")
				{
					string struct_name=(curr_scope->symbol_map[top_symbol]->type).substr(6);
					symbol_info* find_struct=lookup_symbol_global(struct_name, curr_scope);
					int size=0;
					for(int i=0;i<find_struct->param_list.size();i++){
						size=max(size,get_size(find_struct->param_types[i]));
					}
					//debug("Struct size: ",to_string(size));
					code=code+top_symbol+":= alloc " +to_string(size)+"\n";
					

				}
				symbol_info* new_symbol = new symbol_info();
				new_symbol = new symbol_info($2);
				$$=new_symbol;

			}
			
		}
		// debug("declaration specifiers ", to_string(parsing_stack.size()));
		$$->code=code;
		$$->final_code = {};
        int index=0;
        string temp="";
        while(index<$$->code.size()){
            while(index<$$->code.size() && $$->code[index]!='\n'){
                temp+=$$->code[index];
                index++;
            }
			int fla=0;
			for(auto x:static_variables){
				//cout<<temp.substr(0,temp.find(":="))<<endl;
				if(x.first==curr_scope && x.second==trimm(temp.substr(0,temp.find(":=")))){
					static_variables_code.push_back({temp,curr_scope});
					//cout<<"static variable code: "<<temp<<endl;
					fla=1;
					break;
				}
			}
			
			if(fla==0) $$->final_code.push_back({temp,curr_scope});
            temp="";
            index++;
        }
		//debug("Declaration: ",curr_scope->symbol_map["p"]->code);
    }
    ;


declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers 
	{
		// debug("storage class specifier ", $1);
		// debug("storage class specifier ", $2);
		char* buf = (char*)malloc(strlen($1) + strlen($2) + 2); // 1 for comma, 1 for null terminator
		sprintf(buf, "%s,%s", $1, $2);
		$$ = buf;
		// debug("storage class specifier ", $$);

	}
	| type_specifier {$$=$1;}
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
    : init_declarator { 
        $$ = $1; 
    }
    | init_declarator_list COMMA init_declarator { 
		$$=$3;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
		$$->code = $1->code + "\n" + $3->code;
    }
    ;

init_declarator
    : declarator { 
		if(lookup_symbol_global($1->name, curr_scope)!=nullptr){
            error_list.push_back("Line "+to_string(yylineno)+" : Redeclaration error "+$1->name);
		}
        symbol_info* new_symbol = new symbol_info();
        new_symbol=$1;
		curr_scope->symbol_map[$1->name]=new_symbol;
		curr_scope->symbol_map[$1->name]->name=$1->name;
		if($1->is_array==true){
			curr_scope->symbol_map[$1->name]->is_array=true;
			curr_scope->symbol_map[$1->name]->array_length=$1->array_length;
			 if($1->type=="int" || $1->type=="float"){
				string code=$1->name+" := alloc " +to_string(4*$1->array_length);
				$$->code=code;
                $$->final_code.push_back({code,curr_scope});
			}
			else if($1->type=="char"){
                string code=$1->name+" := alloc " +to_string(2*$1->array_length);
                $$->final_code.push_back({code,curr_scope});
				$$->code=code;
			} 
		}
		
		curr_scope->symbol_map[$1->name]->type=$1->type;
		
        $$ =new_symbol;
		
		parsing_stack.push($1->name.c_str());
        pointer_info.push($1->pointer_depth);
    }
    | declarator EQUALS initializer { 
		if(lookup_symbol_local($1->name, curr_scope)!=nullptr){
            error_list.push_back("Line "+to_string(yylineno)+" : Redeclaration error "+$1->name);
		}
		
		curr_scope->symbol_map[$1->name]=$3;
		parsing_stack.push($1->name.c_str());
        pointer_info.push($1->pointer_depth);

		if($1->is_array){
			if($3->int_array.size() > $1->array_length){
                error_list.push_back("Line "+to_string(yylineno)+" : Array size mismatch "+$1->name);
			}
			else{
				$1->int_array = $3->int_array;
				$1->type = $3->type;
				curr_scope->symbol_map[$1->name]->is_array=true;
				string code=$1->name+" := alloc ";
				if($1->type=="int" || $1->type=="float"){
					code=code+to_string(4*$1->array_length);
				}
				else if($1->type=="char"){
					code=code+to_string(2*$1->array_length);
				}
				for(int i=0;i<$1->array_length;i++){
					qid temp=newtemp("int",curr_scope);
					code=code+"\n"+temp.first+":= "+to_string(i)+" * ";
					if($1->type=="int") code=code+"4\n"+"*( "+$1->name+" + "+temp.first+" ) := "+to_string(*(int*)($1->int_array[i]->ptr));
					else if($1->type=="float") code=code+"4\n"+"*( "+$1->name+" + "+temp.first+" ) := "+to_string(*(float*)($1->int_array[i]->ptr));
					else if($1->type=="char") code=code+"2\n"+"*( "+$1->name+" + "+temp.first+" ) := "+char(*(char*)($1->int_array[i]->ptr));
					else if($1->type=="char*") code=code+"2\n"+"*( "+$1->name+" + "+temp.first+" ) := "+$1->int_array[i]->str_val;
				} 
				$$->code=code;
                int index=0;
                string temp="";
                while(index<code.size()){
                    while(index<code.size() && code[index]!='\n'){
                        temp+=code[index];
                        index++;
                    }
                    $$->final_code.push_back({temp,curr_scope});
                    temp="";
                    index++;
                }

			}
		}
        if(!$1->is_array){
			$$ = $1;
            if($3->place.first[0]!='t' && $3->place.first[0]!='&' && $3->place.first[0]!='*' && $3->place.first[0]!='-' && $3->place.first[0]!='!'){
                $3->code="";
            }
			
            $$->code=$3->code+"\n"+$1->place.first+":= "+$3->place.first;
            int index=0;
            string temp="";
            while(index<$$->code.size()){
                while(index<$$->code.size() && $$->code[index]!='\n'){
                    temp+=$$->code[index];
                    index++;
                }
                $$->final_code.push_back({temp,curr_scope});
                temp="";
                index++;
            }
            $$->place=$1->place;
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
	| ID {
		if(type_def_mapping.find($1) != type_def_mapping.end()){
			$$=strdup(type_def_mapping[$1].c_str());
		}
		else{
			error_list.push_back("Line "+to_string(yylineno)+" : Typedef error "+$1);
		}
	}
	;	

struct_or_union_specifier
	: struct_or_union ID LBRACE struct_declaration_list RBRACE 
	{
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type = $1;
		new_symbol->param_list = $4->param_list;
		new_symbol->param_types = $4->param_types;
		curr_scope->symbol_map[$2]=new_symbol;
	}
	| struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union ID
	{
		symbol_info* find_symbol = lookup_symbol_global($2, curr_scope);
		if (find_symbol != nullptr) {
			if (find_symbol->type == "struct" || find_symbol->type == "union") {
				std::string temp = std::string($1) + " " + std::string($2);
				$$ = strdup(temp.c_str());
			} else {
                error_list.push_back("Line "+to_string(yylineno)+" : Variable not of type struct or union");
			}
		} else {
            error_list.push_back("Line "+to_string(yylineno)+" : Struct or Union not declared "+$2);
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
		$$=$2;
		for(auto it: $2->param_list)
					{
						//cerr<<it<<endl;
						symbol_info* x=new symbol_info();
						x->type = $1;
						
						curr_scope->symbol_map[it]=x;
						$$->param_types.push_back($1);
					}
		
		

	}
	;

specifier_qualifier_list
	: type_specifier
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
	: declarator     {$$=$1;}   
	| COLON constant_expression
	| declarator COLON constant_expression
	;

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM ID LBRACE enumerator_list RBRACE 
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
    }
    | direct_declarator { 
		$$=$1; 
    }
    ;

direct_declarator
	: ID     
	{
		symbol_info* x=new symbol_info();
		x->name = $1;
		x->place.first=$1;
		$$=x;
	}       
	| LPARENTHESES declarator RPARENTHESES			
	| direct_declarator LBRACKET constant_expression RBRACKET			
    {
        $$->is_array = true;
        if($3->type=="int"){
            $$->array_length = *(int*)($3->ptr);
        }
        else{
            error_list.push_back("Line "+to_string(yylineno)+" : Array size not an integer "+$1->name);
            $$->array_length=100;
        }
    }
	| direct_declarator LBRACKET RBRACKET
    {
        $$->is_array = true, $$->array_length = 100;
    }
	| direct_declarator LPARENTHESES parameter_type_list RPARENTHESES     
	{
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type=$1->type;
		new_symbol->parameter_no=$3->parameter_no;
		new_symbol->param_types=$3->param_types;
		new_symbol->param_list=$3->param_list;
		new_symbol->is_param_list=$3->is_param_list;
		new_symbol->name=$1->name;
		curr_scope->symbol_map[$1->name]=new_symbol;

		$$=new_symbol;
	}
	| direct_declarator LPARENTHESES identifier_list RPARENTHESES   
	| direct_declarator LPARENTHESES RPARENTHESES
	{
        symbol_info* new_symbol=new symbol_info();      
        new_symbol->type=$1->type;
        new_symbol->parameter_no=0;
        new_symbol->param_types={}; 
        new_symbol->param_list={};
        new_symbol->name=$1->name;
        new_symbol->is_param_list=false;
        curr_scope->symbol_map[$1->name]=new_symbol;
        $$=new_symbol;
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
	: parameter_list
    {
		symbol_info* new_symbol=new symbol_info();
		$$->parameter_no=$1->parameter_no;
		$$->is_param_list=$1->is_param_list;
		$$->param_types=$1->param_types;
		$$->param_list=$1->param_list;
		$$=$1;
		
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
	}
	| declaration_specifiers abstract_declarator{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->name=$2->name;
	}
	| declaration_specifiers{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->type=$1;
		$$->name="";
	}
	;

identifier_list
	: ID		
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
	| LPARENTHESES RPARENTHESES											
	| LPARENTHESES parameter_type_list RPARENTHESES
	| direct_abstract_declarator LPARENTHESES RPARENTHESES       
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
            error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in initializer list");
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
		$$=$1;

	}
	| compound_statement
	{
		$$=$1;
	}
	| expression_statement
    {
		$$=$1;
	}
	| selection_statement{$$=$1;}
	| iteration_statement{$$=$1;}
	| jump_statement{$$=$1;}
    
	;

labeled_statement
	: ID COLON statement
	{
		if(lookup_symbol_global($1, curr_scope)!=nullptr){
			error_list.push_back("Line "+to_string(yylineno)+" : Label Redeclaration error "+$1);
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			$$=new_symbol;
			if(goto_list.find($1)!=goto_list.end()){
				
				string label=goto_list[$1];
				// debug("labellllll", $3->code);
                $$->final_code.push_back({label + ":",curr_scope});
				$$->code=label+":\n"+$3->code;
                $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
				// debug("label", $$->code);
			}
			else{
                //debug("labellllll", $3->code);
				string label=newlabel();
                $$->final_code.push_back({label + ":",curr_scope});
				$$->code=label+":\n"+$3->code;
				$$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
				goto_list[$1]=label;
			}
			curr_scope->symbol_map[$1]=new symbol_info();
			curr_scope->symbol_map[$1]->name=$1;
			curr_scope->symbol_map[$1]->type="label";
		}
	}
	| ID COLON declaration
	{
		
		if(lookup_symbol_global($1, curr_scope)!=nullptr){
			error_list.push_back("Line "+to_string(yylineno)+" : Label Redeclaration error "+$1);
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			$$=new_symbol;
			if(goto_list.find($1)!=goto_list.end()){
				
				string label=goto_list[$1];
				// debug("labellllll", $3->code);
                $$->final_code.push_back({label + ":",curr_scope});
				$$->code=label+":\n"+$3->code;
                $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
				// debug("label", $$->code);
			}
			else{
				//debug("labellllll", $3->code);
				string label=newlabel();
                $$->final_code.push_back({label + ":",curr_scope});
				$$->code=label+":\n"+$3->code;
				$$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
				goto_list[$1]=label;
			}
			curr_scope->symbol_map[$1]=new symbol_info();
			curr_scope->symbol_map[$1]->name=$1;
			curr_scope->symbol_map[$1]->type="label";
		}
	}
	| ID COLON
	| CASE constant_expression COLON statement
	{
		string label=newlabel();
        $$->final_code.push_back({label + ":",curr_scope});
		$$->code = label +":\n"+ $4->code;
        $$->final_code.insert($$->final_code.end(), $4->final_code.begin(), $4->final_code.end());
		case_list.top().push({$2->code,label});
		
	}
	| DEFAULT COLON statement
	{
		string label=newlabel();
		case_list.top().push({"default",label});
        $$->final_code.push_back({label + ":",curr_scope});
		$$->code = label+":\n"+ $3->code;
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());

	}
	;

compound_statement
	: LBRACE RBRACE
	| LBRACE 
	{
		curr_scope = new scoped_symtab(curr_scope);
		for(int i=0;i<var_name.size();i++){
			curr_scope->symbol_map[var_name[i]]=new symbol_info();
			curr_scope->symbol_map[var_name[i]]->type=type_list[i];
			curr_scope->symbol_map[var_name[i]]->name=var_name[i];
		}
		var_name={};
		type_list={};
	} 
	statement_declaration_list RBRACE 

	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
        $$->final_code = $3->final_code;
		$$->is_return=$3->is_return;
		$$->return_type=$3->return_type;
		all_scopes.push_back(curr_scope);scope_list.push_back(curr_scope); curr_scope = curr_scope->parent;
	}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} statement_list RBRACE {symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
        $$->final_code = $3->final_code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list RBRACE {symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code;
        $$->final_code = $3->final_code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
	| LBRACE {curr_scope = new scoped_symtab(curr_scope);} declaration_list statement_list RBRACE 
        {
            symbol_info* new_symbol=new symbol_info();
		    $$=new_symbol;
		    $$->code=$3->code+"\n"+$4->code;
            $$->final_code = $3->final_code;
            $$->final_code.insert($$->final_code.end(), $4->final_code.begin(), $4->final_code.end());
            all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;
        }
	;

statement_declaration_list
	: statement_list statement_declaration_list
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
		$$->code=$1->code + "\n" + $2->code;
		$$->is_return=($1->is_return)|($2->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		
        

	}
	| declaration_list statement_declaration_list
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
		$$->code=$1->code + "\n" + $2->code;
		$$->is_return=$2->is_return;
		// $$->return_type=$2->return_type;
		
        
		
	}
	| statement_list
    {
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$1->code;
        $$->final_code = $1->final_code;
		$$->is_return=$1->is_return;
		//dikkat badi hai
		// $$->return_type=$1->return_type;
	}
	| declaration_list
	{
		$$=$1;
	}
	;

declaration_list
	: declaration
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$1->code;
        $$->final_code = $1->final_code;
		//debug("declaration_list", $$->code);
	}
	| declaration_list declaration
	{
		$$->code=$1->code + "\n" + $2->code;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
	}
	| error SEMICOLON {yyerrok;}
	;

statement_list
	: statement { 
		$$=$1;
	}
	| statement_list statement
	{
		$$->is_return=($1->is_return)|($2->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		$$->code=$1->code + "\n" + $2->code;
		$$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
	}
	| error SEMICOLON {yyerrok;}
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON   {$$=$1;}
	;

selection_statement
	: IF LPARENTHESES expression RPARENTHESES statement
	{
		string truelabel=newlabel();	
		string falselabel=newlabel();
        symbol_info* new_symbol=new symbol_info();
        $$=new_symbol;
		$$->code=$3->code+"\n"+"if ("+ $3->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+$5->code+"\n"+falselabel+":\n";
        $$->final_code = $3->final_code;
        $$->final_code.push_back({"if ("+ $3->place.first +") goto "+truelabel,curr_scope});
        $$->final_code.push_back({"goto "+falselabel,curr_scope});
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
        $$->final_code.push_back({falselabel+":",curr_scope});
	}
	| IF LPARENTHESES expression RPARENTHESES statement ELSE statement
	{
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
        symbol_info* new_symbol=new symbol_info();
        $$=new_symbol;
		$$->code=$3->code+"\n"+"if ("+ $3->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+$5->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+$7->code+"\n"+endlabel+":\n";
        $$->final_code = $3->final_code;
        $$->final_code.push_back({"if ("+ $3->place.first +") goto "+truelabel,curr_scope});
        $$->final_code.push_back({"goto "+falselabel,curr_scope});
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
        $$->final_code.push_back({"goto "+endlabel,curr_scope});
        $$->final_code.push_back({falselabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $7->final_code.begin(), $7->final_code.end());
        $$->final_code.push_back({endlabel+":",curr_scope});
	}      
	| SWITCH{queue<std::pair<std::string, std::string>> q;
		case_list.push(q);
		}LPARENTHESES expression RPARENTHESES statement
	{
		string str="";
        vector<pair<string,scoped_symtab*>> temp;
		while(!case_list.top().empty()){
			string label=case_list.top().front().second;
			string case_value=case_list.top().front().first;
			case_list.top().pop();
			if(case_value=="default")
			{
				str+="goto "+label+"\n";
                temp.push_back({"goto "+label,curr_scope});
			}
			else{
				qid var=newtemp("int",curr_scope);
				str+=var.first+" := "+$4->place.first+" == "+case_value;
                //str+="if ( "+$4->place.first+" == "+case_value+") goto "+label+"\n";
				str+="if ( "+var.first+" ) goto "+label+"\n";
                //temp.push_back({"if ( "+$4->place.first+" == "+case_value+") goto "+label,curr_scope});
				temp.push_back({var.first+" := "+$4->place.first+" == "+case_value,curr_scope});
				temp.push_back({"if ( "+var.first+" ) goto "+label,curr_scope});

            }
		}
		string endlabel=newlabel();
        $$=new symbol_info();
		$$->code= $4->code+"\n"+str+"\n"+$6->code+"\n"+endlabel+":\n";
        $$->final_code = $4->final_code;
        $$->final_code.insert($$->final_code.end(), temp.begin(), temp.end());
        $$->final_code.insert($$->final_code.end(), $6->final_code.begin(), $6->final_code.end());
        $$->final_code.push_back({endlabel+":",curr_scope});
		$$->code=replace_break_continue($$->code,endlabel," ",1);
		$$->final_code=replace_break_continue_final($$->final_code,endlabel," ",1);
		case_list.pop();
	}			
	;

iteration_statement
	: WHILE LPARENTHESES expression RPARENTHESES statement
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=startlabel+":\n"+$3->code+"\n"+"if ("+$3->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$5->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
        $$->final_code.push_back({startlabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
        $$->final_code.push_back({"if ("+$3->place.first+") goto "+truelabel,curr_scope});
        $$->final_code.push_back({"goto "+endlabel,curr_scope});
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
        $$->final_code.push_back({"goto "+startlabel,curr_scope});
        $$->final_code.push_back({endlabel+":",curr_scope});

		$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
        $$->final_code=replace_break_continue_final($$->final_code,endlabel,startlabel,1);
	}
	| UNTIL LPARENTHESES expression RPARENTHESES statement
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code=$3->code+"\n"+startlabel+":\n"+"if ("+$3->place.first+") goto "+endlabel+"\n"+" goto "+truelabel+"\n"+truelabel+":\n"+$5->code+"\n"+"\n"+" goto "+startlabel+"\n"+endlabel+":\n";
		$$->final_code.push_back({startlabel+":",curr_scope});
		$$->final_code.insert($$->final_code.end(), $3->final_code.begin(), $3->final_code.end());
		$$->final_code.push_back({"if ("+$3->place.first+") goto "+endlabel,curr_scope});
		$$->final_code.push_back({"goto "+truelabel,curr_scope});
		$$->final_code.push_back({truelabel+":",curr_scope});
		$$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
		$$->final_code.push_back({"goto "+startlabel,curr_scope});
		$$->final_code.push_back({endlabel+":",curr_scope});
		$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
		$$->final_code=replace_break_continue_final($$->final_code,endlabel,startlabel,1);
	}
	| DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
        $$->final_code.push_back({startlabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
        $$->final_code.push_back({"if ("+$5->place.first+") goto "+startlabel,curr_scope});
        $$->final_code.push_back({"goto "+endlabel,curr_scope});
        $$->final_code.push_back({endlabel+":",curr_scope});
		$$->code=startlabel+":\n"+$2->code+"\n"+truelabel+":\n"+$5->code+"\n"+"\n"+"if ("+$5->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		$$->code=replace_break_continue($$->code,endlabel,startlabel,1);
        $$->final_code=replace_break_continue_final($$->final_code,endlabel,startlabel,1);
	}
	| FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
        $$->final_code = $3->final_code;
        $$->final_code.push_back({startlabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $4->final_code.begin(), $4->final_code.end());
        $$->final_code.push_back({"if ("+$4->place.first+") goto "+truelabel,curr_scope});
        $$->final_code.push_back({"goto "+endlabel,curr_scope});
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $6->final_code.begin(), $6->final_code.end());
        $$->final_code.push_back({"goto "+startlabel,curr_scope});
        $$->final_code.push_back({endlabel+":",curr_scope});
		$$->code=$3->code+"\n"+startlabel+":\n"+$4->code+"\n"+"if ("+$4->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$6->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
        $$->code=replace_break_continue($$->code,endlabel,startlabel,1);
        $$->final_code=replace_break_continue_final($$->final_code,endlabel,startlabel,1);
	}
	| FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement   
	{
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		string updatelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->final_code = $3->final_code;
        $$->final_code.push_back({startlabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $4->final_code.begin(), $4->final_code.end());
        $$->final_code.push_back({"if ("+$4->place.first+") goto "+truelabel,curr_scope});
        $$->final_code.push_back({"goto "+endlabel,curr_scope});
        $$->final_code.push_back({truelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $7->final_code.begin(), $7->final_code.end());
        $$->final_code.push_back({updatelabel+":",curr_scope});
        $$->final_code.insert($$->final_code.end(), $5->final_code.begin(), $5->final_code.end());
        $$->final_code.push_back({"goto "+startlabel,curr_scope});
        $$->final_code.push_back({endlabel+":",curr_scope});
		$$->code=$3->code+"\n"+startlabel+":\n"+$4->code+"\n"+"if ("+$4->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+$7->code+"\n"+updatelabel+":\n"+$5->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
        $$->code=replace_break_continue($$->code,endlabel,updatelabel,0);
        $$->final_code=replace_break_continue_final($$->final_code,endlabel,updatelabel,0);
	}
	;

jump_statement
	: GOTO ID SEMICOLON				
	{ 
		//idhar ID ko symtab me insert karna he
		if(goto_list.find($2)==goto_list.end()){
			string label=newlabel();
			goto_list[$2]=label;
			symbol_info* new_symbol=new symbol_info();
            new_symbol->final_code.push_back({"goto "+label,curr_scope});
			new_symbol->code="goto "+label+"\n";
			$$=new_symbol;
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			$$=new_symbol;
			string label=goto_list[$2];
            $$->final_code.push_back({"goto "+label,curr_scope});
			$$->code="goto "+label+"\n";
			// debug("goto", $$->code);
		}
		
		// debug("goto1111 ",new_symbol->code);
		
		
		// cerr << "goto\n";
	}
	| CONTINUE SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_continue=true;
        $$->final_code.push_back({"continue",curr_scope});
		$$->code="\n continue \n";
	}
	| BREAK SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_break=true;
        $$->final_code.push_back({"break",curr_scope});
		$$->code="\n break \n";
	}
	| RETURN SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_return=true;
		$$->return_type="void";
        $$->final_code.push_back({"RETURN",curr_scope});
		$$->code="\nRETURN\n";
	}
	| RETURN expression SEMICOLON
	{
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->is_return=true;
		$$->return_type=$2->type;
        $$->final_code = $2->final_code;
        $$->final_code.push_back({"RETURN "+$2->place.first,curr_scope});
		$$->code=$2->code + "\nRETURN "+$2->place.first+"\n";
		//debug("return ",$$->code);
	}
	;

start_symbol: translation_unit
{
	//cerr<<"-----------------"<<endl<<$1->code<<"----------------"<<endl;
    
	print_errors();
	// cleanTAC($1->code);
    // cerr<<endl<<endl<<endl;
	vector<pair<string,scoped_symtab*>> temp=$1->final_code;
	static_variables_code.insert(static_variables_code.end(), temp.begin(), temp.end());
    cleaned_TAC=clean_vector_TAC(static_variables_code);
    // print_vector($1->final_code);
	// print_vector(cleaned_TAC);	
}
;
translation_unit
	: external_declaration 				 
	{
		$$->code=$1->code;
        $$->final_code = $1->final_code;
	} 
	| translation_unit external_declaration 
	{
		$$->code=$1->code+$2->code;
        $$->final_code = $1->final_code;
        $$->final_code.insert($$->final_code.end(), $2->final_code.begin(), $2->final_code.end());
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
        curr_scope->symbol_map[$2->name]->type=$1;
	} 
	compound_statement 
	{
        if(strcmp($1,"void")==0){
		
			// if($4->return_type!="void"){
            //     error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
			// }
		}
		else{
			if($4->is_return==0){
                error_list.push_back("Line "+to_string(yylineno)+" : Missing return statement");
			}
			else{
				// if($4->return_type!=$1){
                //     error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
				// }
			}
		}
		symbol_info* new_symbol=new symbol_info();
		$$=new_symbol;
		$$->code="\nFUNC_BEGIN "+$2->name+"\n";
        $$->final_code.push_back({"FUNC_BEGIN "+$2->name,curr_scope});
		for(int i=0;i<$2->param_list.size();i++){
            $$->final_code.push_back({"param"+std::to_string(i)+" := PARAM",scope_list[0]});
			$$->code=$$->code+"param"+std::to_string(i)+" := PARAM\n";
		}
		for(int i=0;i<$2->param_list.size();i++){
            $$->final_code.push_back({$2->param_list[i]+" := param"+std::to_string(i),scope_list[0]});
			$$->code=$$->code+$2->param_list[i]+" := param"+std::to_string(i)+"\n";
		}
        $$->final_code.insert($$->final_code.end(), $4->final_code.begin(), $4->final_code.end());
        $$->final_code.push_back({"FUNC_END "+$2->name,curr_scope});
		$$->code=$$->code+$4->code+"\nFUNC_END "+$2->name+"\n";
		scope_list.pop_back();

	}   
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

void print_errors() {
    if(error_list.size()==0){
        cerr<<"# ======================================================================"<<endl;
        cerr<<"# No Errors in the code"<<endl;
        cerr<<"# Intermediate code generated successfully"<<endl;
        cerr<<"# ======================================================================"<<endl;
    }
    else{
        cerr<<"# =====================LIST OF ERRORS==================================="<<endl;
    for(auto it:error_list){
        cerr<<"#"<<it<<endl;
    }
    cerr<<"# ======================================================================"<<endl;
    }

}

void print_scope_table(){
    
    cerr<<"======================================================================"<<endl;
	cerr<<"Printing scope table"<<endl;
	int count=0;
	for(auto scope : all_scopes) {count++;}
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
	// cerr<<"Scope is here"<<endl;
    }
}

int main() {
	symbol_info* new_symbol=new symbol_info();
	curr_scope->symbol_map["printf"]=new_symbol;
	curr_scope->symbol_map["scanf"]=new_symbol;
	yyparse();
	/* print_scope_table(); */
	codegen_main();
	 
}
