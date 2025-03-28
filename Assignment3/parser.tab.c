/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

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


#line 288 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DECIMAL_LITERAL = 3,            /* DECIMAL_LITERAL  */
  YYSYMBOL_HEXA_LITERAL = 4,               /* HEXA_LITERAL  */
  YYSYMBOL_OCTAL_LITERAL = 5,              /* OCTAL_LITERAL  */
  YYSYMBOL_EXP_LITERAL = 6,                /* EXP_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 7,               /* REAL_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 8,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 9,             /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 10,         /* CHARACTER_LITERAL  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_INVALID_ID = 12,                /* INVALID_ID  */
  YYSYMBOL_INCLUDE = 13,                   /* INCLUDE  */
  YYSYMBOL_AUTO = 14,                      /* AUTO  */
  YYSYMBOL_STRUCT = 15,                    /* STRUCT  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_GOTO = 20,                      /* GOTO  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_DEFAULT = 22,                   /* DEFAULT  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_CONST = 26,                     /* CONST  */
  YYSYMBOL_TRUE = 27,                      /* TRUE  */
  YYSYMBOL_FALSE = 28,                     /* FALSE  */
  YYSYMBOL_STATIC = 29,                    /* STATIC  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_VOID = 32,                      /* VOID  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_SIZEOF = 34,                    /* SIZEOF  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_DOUBLE = 37,                    /* DOUBLE  */
  YYSYMBOL_EXTERN = 38,                    /* EXTERN  */
  YYSYMBOL_SHORT = 39,                     /* SHORT  */
  YYSYMBOL_LONG = 40,                      /* LONG  */
  YYSYMBOL_CHAR = 41,                      /* CHAR  */
  YYSYMBOL_ENUM = 42,                      /* ENUM  */
  YYSYMBOL_REGISTER = 43,                  /* REGISTER  */
  YYSYMBOL_SIGNED = 44,                    /* SIGNED  */
  YYSYMBOL_TYPEDEF = 45,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 47,                  /* UNSIGNED  */
  YYSYMBOL_VOLATILE = 48,                  /* VOLATILE  */
  YYSYMBOL_CLASS = 49,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 50,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 51,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 52,                 /* PROTECTED  */
  YYSYMBOL_NULLPTR = 53,                   /* NULLPTR  */
  YYSYMBOL_NAMESPACE = 54,                 /* NAMESPACE  */
  YYSYMBOL_VIRTUAL = 55,                   /* VIRTUAL  */
  YYSYMBOL_CATCH = 56,                     /* CATCH  */
  YYSYMBOL_RBRACE = 57,                    /* RBRACE  */
  YYSYMBOL_LBRACE = 58,                    /* LBRACE  */
  YYSYMBOL_LBRACKET = 59,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 60,                  /* RBRACKET  */
  YYSYMBOL_LPARENTHESES = 61,              /* LPARENTHESES  */
  YYSYMBOL_RPARENTHESES = 62,              /* RPARENTHESES  */
  YYSYMBOL_DOT = 63,                       /* DOT  */
  YYSYMBOL_COMMA = 64,                     /* COMMA  */
  YYSYMBOL_COLON = 65,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 66,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 67,                      /* PLUS  */
  YYSYMBOL_MINUS = 68,                     /* MINUS  */
  YYSYMBOL_STAR = 69,                      /* STAR  */
  YYSYMBOL_DIVIDE = 70,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 71,                    /* MODULO  */
  YYSYMBOL_AMPERSAND = 72,                 /* AMPERSAND  */
  YYSYMBOL_OR = 73,                        /* OR  */
  YYSYMBOL_XOR = 74,                       /* XOR  */
  YYSYMBOL_EXCLAMATION = 75,               /* EXCLAMATION  */
  YYSYMBOL_TILDE = 76,                     /* TILDE  */
  YYSYMBOL_EQUALS = 77,                    /* EQUALS  */
  YYSYMBOL_LESS_THAN = 78,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 79,              /* GREATER_THAN  */
  YYSYMBOL_QUESTION_MARK = 80,             /* QUESTION_MARK  */
  YYSYMBOL_INCREMENT = 81,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 82,                 /* DECREMENT  */
  YYSYMBOL_REL_AND = 83,                   /* REL_AND  */
  YYSYMBOL_REL_OR = 84,                    /* REL_OR  */
  YYSYMBOL_REL_EQUALS = 85,                /* REL_EQUALS  */
  YYSYMBOL_REL_NOT_EQ = 86,                /* REL_NOT_EQ  */
  YYSYMBOL_LESS_EQUALS = 87,               /* LESS_EQUALS  */
  YYSYMBOL_GREATER_EQUALS = 88,            /* GREATER_EQUALS  */
  YYSYMBOL_ASSIGN_PLUS = 89,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 90,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_STAR = 91,               /* ASSIGN_STAR  */
  YYSYMBOL_ASSIGN_DIV = 92,                /* ASSIGN_DIV  */
  YYSYMBOL_ASSIGN_MOD = 93,                /* ASSIGN_MOD  */
  YYSYMBOL_ASSIGN_AND = 94,                /* ASSIGN_AND  */
  YYSYMBOL_ASSIGN_OR = 95,                 /* ASSIGN_OR  */
  YYSYMBOL_ASSIGN_XOR = 96,                /* ASSIGN_XOR  */
  YYSYMBOL_LEFT_SHIFT = 97,                /* LEFT_SHIFT  */
  YYSYMBOL_LEFT_SHIFT_EQ = 98,             /* LEFT_SHIFT_EQ  */
  YYSYMBOL_RIGHT_SHIFT = 99,               /* RIGHT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT_EQ = 100,           /* RIGHT_SHIFT_EQ  */
  YYSYMBOL_LAMBDA_ARROW = 101,             /* LAMBDA_ARROW  */
  YYSYMBOL_VARIABLE_ARGS = 102,            /* VARIABLE_ARGS  */
  YYSYMBOL_YYACCEPT = 103,                 /* $accept  */
  YYSYMBOL_constant = 104,                 /* constant  */
  YYSYMBOL_primary_expression = 105,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 106,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 107, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 108,         /* unary_expression  */
  YYSYMBOL_unary_operator = 109,           /* unary_operator  */
  YYSYMBOL_cast_expression = 110,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 111, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 112,      /* additive_expression  */
  YYSYMBOL_shift_expression = 113,         /* shift_expression  */
  YYSYMBOL_relational_expression = 114,    /* relational_expression  */
  YYSYMBOL_equality_expression = 115,      /* equality_expression  */
  YYSYMBOL_and_expression = 116,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 117,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 118,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 119,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 120,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 121,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 122,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 123,      /* assignment_operator  */
  YYSYMBOL_expression = 124,               /* expression  */
  YYSYMBOL_constant_expression = 125,      /* constant_expression  */
  YYSYMBOL_declaration = 126,              /* declaration  */
  YYSYMBOL_127_1 = 127,                    /* $@1  */
  YYSYMBOL_declaration_specifiers = 128,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 129,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 130,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 131,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 132,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 133, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 134,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 135,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 136,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 137, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 138,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 139,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 140,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 141,          /* enumerator_list  */
  YYSYMBOL_enumerator = 142,               /* enumerator  */
  YYSYMBOL_type_qualifier = 143,           /* type_qualifier  */
  YYSYMBOL_declarator = 144,               /* declarator  */
  YYSYMBOL_direct_declarator = 145,        /* direct_declarator  */
  YYSYMBOL_pointer = 146,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 147,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 148,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 149,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 150,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 151,          /* identifier_list  */
  YYSYMBOL_type_name = 152,                /* type_name  */
  YYSYMBOL_abstract_declarator = 153,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 154, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 155,              /* initializer  */
  YYSYMBOL_initializer_list = 156,         /* initializer_list  */
  YYSYMBOL_statement = 157,                /* statement  */
  YYSYMBOL_labeled_statement = 158,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 159,       /* compound_statement  */
  YYSYMBOL_statement_declaration_list = 160, /* statement_declaration_list  */
  YYSYMBOL_declaration_list = 161,         /* declaration_list  */
  YYSYMBOL_statement_list = 162,           /* statement_list  */
  YYSYMBOL_expression_statement = 163,     /* expression_statement  */
  YYSYMBOL_selection_statement = 164,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 165,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 166,           /* jump_statement  */
  YYSYMBOL_translation_unit = 167,         /* translation_unit  */
  YYSYMBOL_external_declaration = 168,     /* external_declaration  */
  YYSYMBOL_function_definition = 169       /* function_definition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1843

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   357


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   259,   259,   264,   268,   269,   270,   271,   272,   273,
     277,   286,   287,   290,   294,   298,   299,   300,   313,   314,
     315,   316,   320,   326,   335,   340,   341,   342,   343,   344,
     348,   349,   350,   351,   352,   353,   357,   362,   366,   367,
     368,   369,   373,   374,   375,   379,   380,   381,   385,   386,
     387,   388,   389,   393,   394,   395,   399,   400,   404,   405,
     409,   410,   414,   415,   419,   420,   424,   425,   429,   437,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   472,   473,   477,   481,   482,   482,   554,   555,   556,
     557,   558,   559,   563,   568,   582,   589,   608,   609,   610,
     611,   612,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   630,   638,   639,   651,   652,   656,   657,
     661,   697,   698,   699,   700,   704,   705,   709,   710,   711,
     715,   716,   724,   728,   729,   733,   734,   738,   739,   743,
     753,   762,   771,   776,   777,   778,   779,   780,   784,   785,
     786,   795,   799,   800,   805,   806,   810,   811,   815,   852,
     853,   857,   858,   862,   863,   867,   868,   869,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   885,   886,   887,
     891,   892,   896,   897,   898,   899,   900,   901,   905,   906,
     907,   911,   912,   913,   914,   915,   919,   920,   921,   922,
     926,   927,   928,   932,   933,   934,   938,   939,   943,   944,
     945,   949,   950,   951,   952,   956,   964,   965,   966,   967,
     971,   972,   973,   977,   978,   982,   983,   990,   991
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DECIMAL_LITERAL",
  "HEXA_LITERAL", "OCTAL_LITERAL", "EXP_LITERAL", "REAL_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "CHARACTER_LITERAL", "ID",
  "INVALID_ID", "INCLUDE", "AUTO", "STRUCT", "BOOL", "BREAK", "CASE",
  "CONTINUE", "GOTO", "DO", "DEFAULT", "IF", "ELSE", "FOR", "CONST",
  "TRUE", "FALSE", "STATIC", "SWITCH", "WHILE", "VOID", "RETURN", "SIZEOF",
  "FLOAT", "INT", "DOUBLE", "EXTERN", "SHORT", "LONG", "CHAR", "ENUM",
  "REGISTER", "SIGNED", "TYPEDEF", "UNION", "UNSIGNED", "VOLATILE",
  "CLASS", "PUBLIC", "PRIVATE", "PROTECTED", "NULLPTR", "NAMESPACE",
  "VIRTUAL", "CATCH", "RBRACE", "LBRACE", "LBRACKET", "RBRACKET",
  "LPARENTHESES", "RPARENTHESES", "DOT", "COMMA", "COLON", "SEMICOLON",
  "PLUS", "MINUS", "STAR", "DIVIDE", "MODULO", "AMPERSAND", "OR", "XOR",
  "EXCLAMATION", "TILDE", "EQUALS", "LESS_THAN", "GREATER_THAN",
  "QUESTION_MARK", "INCREMENT", "DECREMENT", "REL_AND", "REL_OR",
  "REL_EQUALS", "REL_NOT_EQ", "LESS_EQUALS", "GREATER_EQUALS",
  "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_STAR", "ASSIGN_DIV", "ASSIGN_MOD",
  "ASSIGN_AND", "ASSIGN_OR", "ASSIGN_XOR", "LEFT_SHIFT", "LEFT_SHIFT_EQ",
  "RIGHT_SHIFT", "RIGHT_SHIFT_EQ", "LAMBDA_ARROW", "VARIABLE_ARGS",
  "$accept", "constant", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration", "$@1",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "statement_declaration_list", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-242)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-200)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1482,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,    22,  -242,  -242,  -242,  -242,  -242,
    -242,    13,    -8,  -242,    12,  1761,  1761,  -242,    30,  -242,
    1761,  1530,    79,    18,  1406,  -242,  -242,   -26,    39,    -3,
    -242,  -242,    -8,  -242,    13,  1530,  -242,  -242,    37,  1795,
    -242,    54,   308,  -242,    68,  -242,  1673,   958,  1603,    79,
    -242,  -242,    39,    65,     6,  -242,  -242,  -242,  -242,    85,
    -242,    75,  -242,  1673,  1795,  1795,  1707,  -242,    66,  1795,
    -242,    90,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
     137,   124,  1278,   139,   197,   878,   146,   154,   196,   198,
     204,   994,  1314,  -242,   798,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  1358,  1358,  -242,  -242,   125,   837,  1278,  -242,
      47,     8,    58,   122,   112,   200,   202,   205,   187,   -29,
    -242,  -242,   121,  -242,  -242,  -242,   223,   390,   472,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,   222,
    -242,  -242,    60,   225,   221,  -242,   131,    29,  1278,  -242,
      39,    13,  -242,  1038,  -242,  1726,  -242,  -242,  -242,  1278,
     157,  -242,   226,  -242,  -242,   878,  -242,   228,  -242,   224,
     257,   878,  1278,  1074,  1278,  1278,  -242,   158,   798,  -242,
     163,   -16,   232,  1278,  -242,  -242,  1278,  1118,   299,  -242,
    -242,   310,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  1278,  -242,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  -242,  -242,  -242,  -242,  -242,
     554,   636,  -242,  -242,  -242,   718,  -242,  1154,  1444,  -242,
      28,  -242,   170,  -242,   260,  -242,   313,  -242,  -242,  -242,
    -242,  1038,  -242,  -242,  -242,  -242,    66,  -242,  1278,  -242,
     878,  -242,   271,  -242,   168,  1074,   172,   176,  -242,   273,
    -242,  1565,   184,  -242,  1278,    36,  -242,   182,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,    47,    47,     8,     8,    58,
      58,    58,    58,   122,   122,   112,   200,   202,   205,    81,
     187,  -242,  -242,  -242,   276,  -242,   295,   296,   170,  1198,
    1638,  -242,  -242,  -242,  -242,    35,  -242,  -242,  -242,  1278,
     878,  1234,   878,   878,  -242,  -242,  -242,  -242,  1278,  1278,
    -242,  -242,  -242,  -242,   300,  -242,   297,  -242,   914,   185,
     337,   878,   194,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,   298,   878,  -242,   878,  -242,  -242,  -242
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     222,   141,   100,   116,   137,    99,   102,   107,   105,   108,
      98,   104,   106,   103,     0,   101,   109,    97,   117,   110,
     138,     0,   148,   224,     0,    87,    89,   111,     0,   112,
      91,     0,   140,     0,     0,   220,   223,   132,     0,     0,
     152,   150,   149,    84,     0,     0,    88,    90,   115,     0,
      92,     0,     0,   200,    85,   228,     0,     0,     0,   139,
       1,   221,     0,   135,     0,   133,   142,   153,   151,     0,
      93,    95,   226,     0,     0,   122,     0,   118,     0,   124,
     202,     0,     2,     5,     8,     4,     6,     3,     7,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,   206,    32,    33,    31,    30,
      35,    34,     0,     0,    11,    14,    24,    36,     0,    38,
      42,    45,    48,    53,    56,    58,    60,    62,    64,    66,
      68,    81,     0,   203,   182,   183,     0,     0,     0,   184,
     185,   186,   187,   201,   227,    10,   144,    36,    83,     0,
     161,   147,   160,     0,   154,   156,     0,     0,     0,   130,
       0,     0,    86,     0,   225,     0,   121,   114,   119,     0,
       0,   125,   127,   123,   202,     0,   217,     0,   216,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,    28,
       0,   163,     0,     0,    25,    26,     0,     0,     0,    20,
      21,     0,    70,    74,    75,    71,    72,    73,    78,    80,
      79,    76,    77,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   207,   192,   194,   200,   197,
       0,     0,   193,   203,   196,     0,   143,     0,     0,   158,
     165,   159,   166,   145,     0,   146,     0,   131,   136,   134,
      94,     0,   177,    96,   113,   128,     0,   120,     0,   188,
       0,   215,     0,   190,     0,     0,     0,     0,   219,     0,
      13,     0,   165,   164,     0,     0,    16,     0,    22,    18,
      19,    69,    39,    40,    41,    43,    44,    46,    47,    49,
      50,    51,    52,    54,    55,    57,    59,    61,    63,     0,
      65,    82,   195,   169,     0,   173,     0,     0,   167,     0,
       0,   155,   157,   162,   180,     0,   126,   129,   189,     0,
       0,     0,     0,     0,    29,    37,    15,    17,     0,     0,
     170,   174,   168,   171,     0,   175,     0,   178,     0,     0,
     208,     0,     0,   210,   211,    23,    67,   172,   176,   179,
     181,     0,     0,   213,     0,   212,   209,   214
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,  -242,  -242,  -242,  -242,   -56,  -242,  -106,    33,    41,
      -6,    42,   135,   138,   140,   141,   145,  -242,   -55,  -149,
    -242,   -52,   -64,    10,  -242,     0,  -242,   207,  -242,    49,
    -242,  -242,   305,   -59,   -66,  -242,   105,  -242,   311,   227,
      -7,   -13,   -30,   -15,  -242,   -53,  -242,   127,  -242,   214,
    -131,  -228,  -241,  -242,   -91,  -242,    70,   -46,   151,   -33,
    -167,  -242,  -242,  -242,  -242,   348,  -242
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   114,   115,   116,   287,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     213,   132,   149,    53,    44,    54,    69,    70,    25,    26,
      27,    28,    76,    77,    78,   170,   171,    29,    64,    65,
      30,    31,    32,    33,    42,   316,   154,   155,   156,   192,
     317,   252,   263,   325,   133,   134,   135,   244,   240,   245,
     139,   140,   141,   142,    34,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   147,   148,    59,   180,   153,   136,    41,    39,   166,
      23,    45,   214,   173,   262,    40,   275,   168,     4,   138,
     324,   251,   318,     1,     1,    46,    47,    68,   177,     1,
      50,    71,    62,    37,    24,    67,   147,   148,   191,     1,
      20,    48,    79,   247,    23,   281,   189,   243,   288,   187,
      63,   232,   190,    22,   318,   233,   194,   195,   152,    66,
     283,    22,   147,   159,   291,   172,   143,    79,    79,    79,
     160,     1,    79,    21,    21,   218,   219,     1,    43,    21,
      38,    22,    22,   143,   269,   311,   257,   247,    49,   248,
     273,   239,   347,   160,   258,    74,   336,    79,    75,   348,
     234,    55,   147,   148,   241,   265,   168,   360,   331,   292,
     293,   294,   262,   147,   148,    72,   215,   216,   217,   247,
      80,   248,   191,    75,    75,    75,   144,    21,    75,    22,
     274,   169,   276,   277,    43,    22,   190,   250,    57,   249,
      58,   190,   158,   164,   285,   234,   339,   238,    71,   161,
     243,   162,   163,    75,   243,   220,   174,   221,    79,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   282,   147,   335,   328,
     309,    79,    56,   314,   196,   234,   197,   235,   198,   355,
     176,   147,   148,   255,   239,   256,    73,   226,   227,   262,
     222,   223,   175,   137,   327,   178,   199,   200,   179,   224,
     225,   181,   147,   148,    75,   182,   299,   300,   301,   302,
      59,   266,   234,   267,   278,   280,   201,   234,   147,   319,
     330,   320,   234,   250,   332,    39,   234,    75,   333,   350,
     234,   353,   354,   247,   337,   281,   338,   361,   152,   234,
     238,   295,   296,   172,   152,   344,   364,   183,   234,   184,
     363,   297,   298,   147,   148,   185,   282,   346,   303,   304,
     231,   366,   228,   367,     2,     3,   229,   349,   230,   352,
     236,   152,   246,   147,   356,   254,     4,   253,   272,     5,
     271,   268,     6,   270,   284,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    81,
     289,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     152,   290,     2,     3,   323,    91,    92,    93,    94,    95,
      96,    97,   329,    98,     4,   334,   340,     5,    99,   100,
       6,   101,   102,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   341,   342,   358,
     357,   362,   321,   305,   365,   103,    52,   306,   260,   104,
     307,   326,   308,   157,   105,   106,   107,   108,   310,   165,
     109,   322,    61,   110,   111,     0,     0,   259,     0,   112,
     113,    81,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   279,     0,     2,     3,     0,    91,    92,    93,
      94,    95,    96,    97,     0,    98,     4,     0,     0,     5,
      99,   100,     6,   101,   102,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,   237,    52,     0,
       0,   104,     0,     0,     0,     0,   105,   106,   107,   108,
       0,     0,   109,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,    81,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     2,     3,     0,    91,
      92,    93,    94,    95,    96,    97,     0,    98,     4,     0,
       0,     5,    99,   100,     6,   101,   102,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,   242,
      52,     0,     0,   104,     0,     0,     0,     0,   105,   106,
     107,   108,     0,     0,   109,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,    81,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     2,     3,
       0,    91,    92,    93,    94,    95,    96,    97,     0,    98,
       4,     0,     0,     5,    99,   100,     6,   101,   102,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,  -199,    52,     0,     0,   104,     0,     0,     0,     0,
     105,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,    81,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       2,     3,     0,    91,    92,    93,    94,    95,    96,    97,
       0,    98,     4,     0,     0,     5,    99,   100,     6,   101,
     102,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,   312,    52,     0,     0,   104,     0,     0,
       0,     0,   105,   106,   107,   108,     0,     0,   109,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,    81,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     2,     3,     0,    91,    92,    93,    94,    95,
      96,    97,     0,    98,     4,     0,     0,     5,    99,   100,
       6,   101,   102,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,  -198,    52,     0,     0,   104,
       0,     0,     0,     0,   105,   106,   107,   108,     0,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       6,     0,   102,     7,     8,     9,     0,    11,    12,    13,
      14,     0,    16,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,   106,   107,   108,     0,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,     0,    98,     0,     0,     0,     0,    99,   100,
       0,   101,   102,     0,   202,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,   145,   203,   204,   205,   206,
     207,   208,   209,   210,     0,   211,    52,   212,     0,   104,
       0,     0,     0,     0,   105,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,   359,   261,     0,     0,   104,     0,     0,     0,     0,
       0,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,    82,    83,    84,
      85,    86,    87,    88,    89,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   104,
       0,     0,     0,     0,     0,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
     186,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,    82,    83,    84,
      85,    86,    87,    88,    89,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,   104,
       0,     0,     0,     0,     0,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
     105,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,    82,    83,    84,
      85,    86,    87,    88,    89,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     286,     0,     0,     0,     0,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     0,   313,   104,     0,     0,     0,     0,
       0,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,    82,    83,    84,
      85,    86,    87,    88,    89,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   343,   104,
       0,     0,     0,     0,     0,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     0,     0,   104,   351,     0,     0,     0,
       0,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,    82,    83,    84,
      85,    86,    87,    88,    89,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,   106,   107,   108,   102,     0,
     109,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,    82,    83,    84,    85,    86,    87,    88,    89,   145,
       0,     0,     0,     0,     0,   188,     0,     0,     0,     0,
       0,   106,   107,   108,     0,     0,   109,     0,     0,   110,
     111,     0,   102,     0,     0,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   193,
       2,     3,     0,     0,     0,   106,   107,   108,     0,     0,
     109,     0,     4,   110,   111,     5,     0,     0,     6,   112,
     113,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     1,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       4,     0,     0,     5,     0,    22,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     1,     0,     0,     2,     3,     0,     0,
       0,     0,     0,   247,     0,   248,   315,     0,     4,     0,
       0,     5,     0,    22,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     2,     3,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     4,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     2,
       3,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   150,     0,     0,     2,     3,     0,
       0,     0,     0,     0,   247,     0,   281,   315,     0,     4,
       0,     0,     5,     0,    22,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,   151,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
     345,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     3,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     4,     0,     0,     0,     0,     0,     6,
       0,     3,     7,     8,     9,     0,    11,    12,    13,    14,
       0,    16,     4,    18,    19,    20,     0,     0,     6,     0,
       0,     7,     8,     9,   167,    11,    12,    13,    14,     0,
      16,     0,    18,    19,    20,     2,     3,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     6,     0,     0,
       7,     8,     9,     0,    11,    12,    13,    14,     0,    16,
       0,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    57,    57,    33,    95,    58,    52,    22,    21,    75,
       0,    24,   118,    79,   163,    22,   183,    76,    26,    52,
     261,   152,   250,    11,    11,    25,    26,    42,    92,    11,
      30,    44,    58,    11,    34,    42,    92,    92,   104,    11,
      48,    11,    49,    59,    34,    61,   102,   138,   197,   101,
      11,    80,   104,    69,   282,    84,   112,   113,    58,    62,
     191,    69,   118,    57,   213,    78,    56,    74,    75,    76,
      64,    11,    79,    61,    61,    67,    68,    11,    66,    61,
      58,    69,    69,    73,   175,   234,    57,    59,    58,    61,
     181,   137,    57,    64,   158,    58,    60,   104,    49,    64,
      64,    31,   158,   158,   137,   169,   165,   348,   275,   215,
     216,   217,   261,   169,   169,    45,    69,    70,    71,    59,
      66,    61,   188,    74,    75,    76,    56,    61,    79,    69,
     182,    65,   184,   185,    66,    69,   188,   152,    59,   152,
      61,   193,    77,    73,   196,    64,    65,   137,   161,    64,
     241,    66,    77,   104,   245,    97,    66,    99,   165,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   191,   233,   284,   270,
     232,   188,    31,   247,    59,    64,    61,    66,    63,   338,
      66,   247,   247,    62,   240,    64,    45,    85,    86,   348,
      78,    79,    65,    52,   268,    66,    81,    82,    11,    87,
      88,    65,   268,   268,   165,    61,   222,   223,   224,   225,
     250,    64,    64,    66,    66,    62,   101,    64,   284,    59,
      62,    61,    64,   248,    62,   248,    64,   188,    62,   330,
      64,   332,   333,    59,    62,    61,    64,    62,   248,    64,
     240,   218,   219,   266,   254,   319,    62,    61,    64,    61,
     351,   220,   221,   319,   319,    61,   281,   320,   226,   227,
      83,   362,    72,   364,    14,    15,    74,   329,    73,   331,
      57,   281,    60,   339,   339,    64,    26,    62,    31,    29,
      66,    65,    32,    65,    62,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     1,
      11,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     320,    11,    14,    15,    11,    17,    18,    19,    20,    21,
      22,    23,    61,    25,    26,    62,    60,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    62,    62,    62,
      60,    24,   102,   228,    66,    57,    58,   229,   161,    61,
     230,   266,   231,    62,    66,    67,    68,    69,   233,    74,
      72,   254,    34,    75,    76,    -1,    -1,   160,    -1,    81,
      82,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   188,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    82,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    82,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    44,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    77,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    98,    58,   100,    -1,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    34,    -1,
      72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    34,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    61,
      14,    15,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    26,    75,    76,    29,    -1,    -1,    32,    81,
      82,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    11,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      26,    -1,    -1,    29,    -1,    69,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    11,    -1,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    61,    62,    -1,    26,    -1,
      -1,    29,    -1,    69,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    14,    15,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    11,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,    26,
      -1,    -1,    29,    -1,    69,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    62,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      62,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    15,    35,    36,    37,    -1,    39,    40,    41,    42,
      -1,    44,    26,    46,    47,    48,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    57,    39,    40,    41,    42,    -1,
      44,    -1,    46,    47,    48,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    -1,    39,    40,    41,    42,    -1,    44,
      -1,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    61,    69,   126,   128,   131,   132,   133,   134,   140,
     143,   144,   145,   146,   167,   168,   169,    11,    58,   144,
     143,   146,   147,    66,   127,   144,   128,   128,    11,    58,
     128,     1,    58,   126,   128,   159,   161,    59,    61,   145,
       0,   168,    58,    11,   141,   142,    62,   143,   146,   129,
     130,   144,   159,   161,    58,   132,   135,   136,   137,   143,
      66,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    17,    18,    19,    20,    21,    22,    23,    25,    30,
      31,    33,    34,    57,    61,    66,    67,    68,    69,    72,
      75,    76,    81,    82,   104,   105,   106,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   124,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   126,   159,    11,    60,   108,   121,   125,
      11,    62,   128,   148,   149,   150,   151,   141,    77,    57,
      64,    64,    66,    77,   159,   135,   137,    57,   136,    65,
     138,   139,   144,   137,    66,    65,    66,   125,    66,    11,
     157,    65,    61,    61,    61,    61,    66,   124,    61,   108,
     124,   137,   152,    61,   108,   108,    59,    61,    63,    81,
      82,   101,    77,    89,    90,    91,    92,    93,    94,    95,
      96,    98,   100,   123,   110,    69,    70,    71,    67,    68,
      97,    99,    78,    79,    87,    88,    85,    86,    72,    74,
      73,    83,    80,    84,    64,    66,    57,    57,   126,   160,
     161,   162,    57,   157,   160,   162,    60,    59,    61,   144,
     146,   153,   154,    62,    64,    62,    64,    57,   125,   142,
     130,    58,   122,   155,    57,   125,    64,    66,    65,   157,
      65,    66,    31,   157,   124,   163,   124,   124,    66,   152,
      62,    61,   146,   153,    62,   124,    62,   107,   122,    11,
      11,   122,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   114,   115,   116,   117,   118,   124,
     119,   122,    57,    60,   125,    62,   148,   153,   154,    59,
      61,   102,   150,    11,   155,   156,   139,   125,   157,    61,
      62,   163,    62,    62,    62,   110,    60,    62,    64,    65,
      60,    62,    62,    60,   125,    62,   148,    57,    64,   124,
     157,    62,   124,   157,   157,   122,   121,    60,    62,    57,
     155,    62,    24,   157,    62,    66,   157,   157
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   126,   127,   126,   128,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   137,   137,   137,   137,   138,   138,   139,   139,   139,
     140,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   145,   145,   145,   145,   145,   146,   146,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     150,   151,   151,   152,   152,   153,   153,   153,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   155,   155,
     156,   156,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   159,   159,   159,   159,   159,   160,   160,   160,   160,
     161,   161,   161,   162,   162,   162,   163,   163,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   166,   166,
     167,   167,   167,   168,   168,   169,   169,   169,   169
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     0,     4,     1,     2,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     1,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     1,     2,     3,
       4,     5,     2,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     3,     4,     3,     4,     4,     3,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     3,     3,     4,     2,     2,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     0,     1,     1,     4,     3,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* constant: DECIMAL_LITERAL  */
#line 260 "src/parser.y"
        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("I am in int\n");
	}
#line 2035 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 265 "src/parser.y"
        { (yyval.symbol_info)=(yyvsp[0].symbol_info);
	printf("I am in float\n");
	}
#line 2043 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 278 "src/parser.y"
        {
		printf("ID %s\n",(yyvsp[0].str));
		symbol_info* new_symbol = new symbol_info();
		new_symbol->name = (yyvsp[0].str);
		(yyval.symbol_info) = new_symbol;
		printf("ID2 %s\n",(yyval.symbol_info)->name.c_str());
		
	}
#line 2056 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 286 "src/parser.y"
                                {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 2062 "parser.tab.c"
    break;

  case 12: /* primary_expression: STRING_LITERAL  */
#line 287 "src/parser.y"
                         {
        // printf("This is a string literal: %s",$1);
    }
#line 2070 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 295 "src/parser.y"
        {(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("Primary expression %s\n",(yyval.symbol_info)->name.c_str());
	}
#line 2078 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 301 "src/parser.y"
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
#line 2095 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 336 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("Postfix expression %s\n",(yyval.symbol_info)->name.c_str());
		}
#line 2104 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 358 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("Unary expression %s\n",(yyval.symbol_info)->name.c_str());
		}
#line 2113 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 366 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2119 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 373 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2125 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 379 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2131 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 385 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2137 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 393 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2143 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 399 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2149 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 404 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2155 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 409 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2161 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 414 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2167 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 419 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2173 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 424 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2179 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 430 "src/parser.y"
        { 
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("cond expression = %s\n",(yyvsp[0].symbol_info)->type.c_str());
		printf("cond expression2 = %s\n",(yyvsp[0].symbol_info)->name.c_str());
	}
#line 2191 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 438 "src/parser.y"
        {
		printf("unary inside assignment = %s\n",(yyvsp[-2].symbol_info)->name.c_str());
		printf("Assignment expression = %s\n",(yyvsp[0].symbol_info)->type.c_str());
		if(curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]!=nullptr){
			printf("Symbol found\n");
			if(curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]->type!=(yyvsp[0].symbol_info)->type){
				printf("Error: Type mismatch in assignment\n");
			}
			else{
				printf("Correct type assignment\n");
				curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=(yyvsp[0].symbol_info);
			}
		}
		else{
			printf("Symbol not found\n");
		}
	}
#line 2213 "parser.tab.c"
    break;

  case 85: /* $@1: %empty  */
#line 482 "src/parser.y"
                             {parsing_stack.push((yyvsp[0].str));}
#line 2219 "parser.tab.c"
    break;

  case 86: /* declaration: declaration_specifiers $@1 init_declarator_list SEMICOLON  */
#line 483 "src/parser.y"
    {
		printf("parsing stack top = %s\n",parsing_stack.top().c_str());
		printf("Declaration specifiers = %s\n", (yyvsp[-3].str));
		printf("Init declarator list = %f\n", (yyvsp[-1].symbol_info)->name.c_str());
		printf("dollar 3 type = %s\n",(yyvsp[-1].symbol_info)->type);
		// while(!parsing_stack.empty()){
		// 	printf("top= %s\n",parsing_stack.top().c_str());
		// 	parsing_stack.pop();
		// }
		int flag=0;
		while (parsing_stack.top() != (yyvsp[-3].str)) {
			std::string top_symbol = parsing_stack.top();  // Store the top of the stack
			parsing_stack.pop();  // Pop before using it in the map (avoids multiple lookups)

			// Check if the symbol exists in the current scope
			if (curr_scope->symbol_map[top_symbol] != nullptr) {
				printf("top ka type = %s\n", curr_scope->symbol_map[top_symbol]->type.c_str());

				if ((yyvsp[-3].str) != curr_scope->symbol_map[top_symbol]->type) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
			} else {
				// Create new symbol_info and assign type = $1
				symbol_info* new_symbol = new symbol_info();
				new_symbol->type = (yyvsp[-3].str);
				curr_scope->symbol_map[top_symbol] = new_symbol;
				printf("Created new symbol: %s with type %s\n", top_symbol.c_str(), ((yyvsp[-3].str)));
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
#line 2291 "parser.tab.c"
    break;

  case 89: /* declaration_specifiers: type_specifier  */
#line 556 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 2297 "parser.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator  */
#line 563 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
		printf("init_d %s\n",(yyval.symbol_info)->name.c_str());  
        //printf("init_declarator = %s\n", $$);
    }
#line 2307 "parser.tab.c"
    break;

  case 94: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 568 "src/parser.y"
                                                 { 
        // $$ = (char*)malloc(strlen($1) + strlen($3) + 2); 
        // sprintf($$, "%s,%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "," + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator_list = %s\n", $$);
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("init_D %s\n",(yyval.symbol_info)->name.c_str()); 
    }
#line 2323 "parser.tab.c"
    break;

  case 95: /* init_declarator: declarator  */
#line 582 "src/parser.y"
                 { 
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]=nullptr;
        (yyval.symbol_info) =(yyvsp[0].symbol_info);
		printf("declarator %s\n",(yyval.symbol_info)->name.c_str()); 
		parsing_stack.push((yyvsp[0].symbol_info)->name.c_str());
        //printf("declarator = %s\n", $$);
    }
#line 2335 "parser.tab.c"
    break;

  case 96: /* init_declarator: declarator EQUALS initializer  */
#line 589 "src/parser.y"
                                    { 
        // $$ = malloc(strlen($1) + strlen($3) + 2);  
        // sprintf($$, "%s=%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "=" + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator with initializer = %s\n", $$);
		curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=(yyvsp[0].symbol_info);
		if((yyvsp[0].symbol_info)->type=="float") printf("Yes float found\n");
		if((yyvsp[0].symbol_info)->type=="int") printf("Yes int found\n");
		parsing_stack.push((yyvsp[-2].symbol_info)->name.c_str());
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
		printf("declarator equals initializer %s\n",(yyval.symbol_info)->name.c_str()); 
		
    }
#line 2356 "parser.tab.c"
    break;

  case 105: /* type_specifier: INT  */
#line 619 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 2362 "parser.tab.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 621 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 2368 "parser.tab.c"
    break;

  case 113: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 631 "src/parser.y"
        {
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        // assign_type(type_str);
        // insert_symtab('V', $2); 
	}
#line 2380 "parser.tab.c"
    break;

  case 115: /* struct_or_union_specifier: struct_or_union ID  */
#line 641 "src/parser.y"
        {
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        // insert_symtab('V', $2); 
	}
#line 2392 "parser.tab.c"
    break;

  case 120: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 662 "src/parser.y"
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
#line 2429 "parser.tab.c"
    break;

  case 131: /* enum_specifier: ENUM ID LBRACE enumerator_list RBRACE  */
#line 717 "src/parser.y"
        {
		//printf("enum is here = %s\n",$$);
		char type_str[10];
      	// get_type_string(type_str,$$);
      	assign_type(type_str);
      	// insert_symtab('V',$2);
	}
#line 2441 "parser.tab.c"
    break;

  case 139: /* declarator: pointer direct_declarator  */
#line 743 "src/parser.y"
                                { 
		//printf("Pointer direct declarator\n");
        // $$ = malloc(strlen($1) + strlen($2) + 1); 
        // sprintf($$, "%s%s", $1, $2); 
		// //printf("it is $$: %s\n",$$); 
        // free($1); free($2);

        // string result = string($1) + string($2);
        // $$ = strdup(result.c_str());
    }
#line 2456 "parser.tab.c"
    break;

  case 140: /* declarator: direct_declarator  */
#line 753 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
        // $$ = strdup($1);  
		//printf("Direct declarator %s\n",$$);
		printf("Direct declarator %s\n",(yyval.symbol_info)->name.c_str());
    }
#line 2467 "parser.tab.c"
    break;

  case 141: /* direct_declarator: ID  */
#line 763 "src/parser.y"
        {
		printf("%s\n",(yyvsp[0].str));
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);

		(yyval.symbol_info)=x;
		printf("ID %s\n",(yyval.symbol_info)->name.c_str());
	}
#line 2480 "parser.tab.c"
    break;

  case 142: /* direct_declarator: LPARENTHESES declarator RPARENTHESES  */
#line 772 "src/parser.y"
        { 
		//printf("LPar declarator RPar= %s\n",$2);
		// $$=strdup($2);
	}
#line 2489 "parser.tab.c"
    break;

  case 150: /* pointer: STAR pointer  */
#line 787 "src/parser.y"
        { 
        // $$ = malloc(strlen($2) + 2); 
        // sprintf($$, "*%s", $2);  
        // free($2);

        // string result = string("*") + string($2);
        // $$ = strdup(result.c_str());
    }
#line 2502 "parser.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers declarator  */
#line 816 "src/parser.y"
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
#line 2543 "parser.tab.c"
    break;

  case 177: /* initializer: assignment_expression  */
#line 885 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2549 "parser.tab.c"
    break;

  case 202: /* declaration_list: error SEMICOLON  */
#line 928 "src/parser.y"
                          {yyerrok;}
#line 2555 "parser.tab.c"
    break;

  case 205: /* statement_list: error SEMICOLON  */
#line 934 "src/parser.y"
                          {yyerrok;}
#line 2561 "parser.tab.c"
    break;

  case 215: /* jump_statement: GOTO ID SEMICOLON  */
#line 957 "src/parser.y"
        { 
		//printf("Goto statement: %s\n",$2);
		
      	// insert_symtab('G',$2);
		

	}
#line 2573 "parser.tab.c"
    break;

  case 226: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 984 "src/parser.y"
        {   //printf("Function is there: %s %s\n",$1,$2);
		char type_str[10];
      	// get_type_string(type_str,$1);
      	assign_type(type_str);
      	// insert_symtab('F',$2);
	}
#line 2584 "parser.tab.c"
    break;


#line 2588 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 993 "src/parser.y"


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
