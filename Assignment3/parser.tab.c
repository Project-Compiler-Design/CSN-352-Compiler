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
        std::map<string,symbol_info> symbol_map;
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


#line 287 "parser.tab.c"

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
  YYSYMBOL_declaration_specifiers = 127,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 128,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 129,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 130,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 131,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 132, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 133,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 134,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 135,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 136, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 137,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 138,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 139,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 140,          /* enumerator_list  */
  YYSYMBOL_enumerator = 141,               /* enumerator  */
  YYSYMBOL_type_qualifier = 142,           /* type_qualifier  */
  YYSYMBOL_declarator = 143,               /* declarator  */
  YYSYMBOL_direct_declarator = 144,        /* direct_declarator  */
  YYSYMBOL_pointer = 145,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 146,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 147,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 148,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 149,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 150,          /* identifier_list  */
  YYSYMBOL_type_name = 151,                /* type_name  */
  YYSYMBOL_abstract_declarator = 152,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 153, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 154,              /* initializer  */
  YYSYMBOL_initializer_list = 155,         /* initializer_list  */
  YYSYMBOL_statement = 156,                /* statement  */
  YYSYMBOL_labeled_statement = 157,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 158,       /* compound_statement  */
  YYSYMBOL_statement_declaration_list = 159, /* statement_declaration_list  */
  YYSYMBOL_declaration_list = 160,         /* declaration_list  */
  YYSYMBOL_statement_list = 161,           /* statement_list  */
  YYSYMBOL_expression_statement = 162,     /* expression_statement  */
  YYSYMBOL_selection_statement = 163,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 164,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 165,           /* jump_statement  */
  YYSYMBOL_translation_unit = 166,         /* translation_unit  */
  YYSYMBOL_external_declaration = 167,     /* external_declaration  */
  YYSYMBOL_function_definition = 168       /* function_definition  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1886

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

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
       0,   256,   256,   260,   263,   264,   265,   266,   267,   268,
     272,   273,   274,   277,   281,   282,   283,   284,   297,   298,
     299,   300,   304,   310,   319,   320,   321,   322,   323,   324,
     328,   329,   330,   331,   332,   333,   337,   338,   342,   343,
     344,   345,   349,   350,   351,   355,   356,   357,   361,   362,
     363,   364,   365,   369,   370,   371,   375,   376,   380,   381,
     385,   386,   390,   391,   395,   396,   400,   401,   405,   411,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   429,   430,   434,   438,   439,   487,   488,   489,   490,
     491,   492,   496,   500,   512,   516,   530,   531,   532,   533,
     534,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   552,   560,   561,   573,   574,   578,   579,   583,
     619,   620,   621,   622,   626,   627,   631,   632,   633,   637,
     638,   646,   650,   651,   655,   656,   660,   661,   665,   675,
     682,   683,   688,   689,   690,   691,   692,   696,   697,   698,
     707,   711,   712,   717,   718,   722,   723,   727,   764,   765,
     769,   770,   774,   775,   779,   780,   781,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   797,   798,   799,   803,
     804,   808,   809,   810,   811,   812,   813,   817,   818,   819,
     823,   824,   825,   826,   827,   831,   832,   833,   834,   838,
     839,   840,   844,   845,   846,   850,   851,   855,   856,   857,
     861,   862,   863,   864,   868,   876,   877,   878,   879,   883,
     884,   885,   889,   890,   894,   895,   902,   903
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
  "expression", "constant_expression", "declaration",
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

#define YYPACT_NINF (-230)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-199)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1578,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,    17,  -230,  -230,  -230,  -230,  -230,
    -230,    11,    57,  -230,    -3,  1838,  1838,  -230,    27,  -230,
    1838,  1626,    59,    21,  1502,  -230,  -230,     2,     5,   -43,
    -230,  -230,    57,  -230,    67,  -230,  1448,  -230,  -230,     7,
    1404,  -230,    20,   350,  -230,    -3,  -230,  1769,  1000,  1699,
      59,  -230,  -230,     5,   -32,     4,  -230,  -230,  -230,  -230,
      11,  -230,  1036,  -230,  1769,  1404,  1404,   254,  -230,     9,
    1404,  -230,    51,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,    56,    64,  1320,    78,   114,   920,    85,    76,    94,
      98,   188,  1080,  1356,  -230,   840,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  1400,  1400,  -230,  -230,   129,   879,  1320,
    -230,    71,   118,    52,    22,   123,   127,   186,   189,   182,
     -41,  -230,  -230,    90,  -230,  -230,  -230,   210,   432,   514,
    -230,  -230,  -230,  -230,   191,  -230,  -230,  -230,  -230,  -230,
    -230,   211,  -230,  -230,    12,   212,   209,  -230,    96,    31,
    1320,  -230,     5,  -230,  1036,  -230,  -230,  -230,  1803,  -230,
    -230,  -230,  1320,   125,  -230,   213,  -230,  -230,   920,  -230,
     216,  -230,   219,   245,   920,  1320,  1116,  1320,  1320,  -230,
     132,   840,  -230,   138,   -28,   225,  1320,  -230,  -230,  1320,
    1160,   277,  -230,  -230,   281,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  1320,  -230,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,
    1320,  1320,  1320,  1320,  1320,  1320,  1320,  1320,  -230,  -230,
    -230,  -230,  -230,   596,   678,  -230,  -230,  -230,   760,  -230,
    1196,  1540,  -230,    18,  -230,   155,  -230,   302,  -230,   286,
    -230,  -230,  -230,  -230,    72,  -230,  -230,     9,  -230,  1320,
    -230,   920,  -230,   238,  -230,   162,  1116,   165,   169,  -230,
     241,  -230,  1661,   158,  -230,  1320,   -13,  -230,   170,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,    71,    71,   118,   118,
      52,    52,    52,    52,    22,    22,   123,   127,   186,   189,
     181,   182,  -230,  -230,  -230,   244,  -230,   243,   246,   155,
    1240,  1734,  -230,  -230,  -230,  -230,   956,  -230,  -230,  -230,
    1320,   920,  1276,   920,   920,  -230,  -230,  -230,  -230,  1320,
    1320,  -230,  -230,  -230,  -230,   249,  -230,   248,  -230,  -230,
     173,   282,   920,   177,  -230,  -230,  -230,  -230,  -230,  -230,
     252,   920,  -230,   920,  -230,  -230,  -230
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     221,   140,    99,   115,   136,    98,   101,   106,   104,   107,
      97,   103,   105,   102,     0,   100,   108,    96,   116,   109,
     137,     0,   147,   223,     0,    86,    88,   110,     0,   111,
      90,     0,   139,     0,     0,   219,   222,   131,     0,     0,
     151,   149,   148,    84,     0,    92,     0,    87,    89,   114,
       0,    91,     0,     0,   199,     0,   227,     0,     0,     0,
     138,     1,   220,     0,   134,     0,   132,   141,   152,   150,
       0,    85,     0,   225,     0,     0,   121,     0,   117,     0,
     123,   201,     0,     2,     5,     8,     4,     6,     3,     7,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   205,    32,    33,    31,
      30,    35,    34,     0,     0,    11,    14,    24,    36,     0,
      38,    42,    45,    48,    53,    56,    58,    60,    62,    64,
      66,    68,    81,     0,   202,   181,   182,     0,     0,     0,
     183,   184,   185,   186,    94,   200,   226,    10,   143,    36,
      83,     0,   160,   146,   159,     0,   153,   155,     0,     0,
       0,   129,     0,    93,     0,   176,    95,   224,     0,   120,
     113,   118,     0,     0,   124,   126,   122,   201,     0,   216,
       0,   215,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,    28,     0,   162,     0,     0,    25,    26,     0,
       0,     0,    20,    21,     0,    70,    74,    75,    71,    72,
      73,    78,    80,    79,    76,    77,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,   191,
     193,   199,   196,     0,     0,   192,   202,   195,     0,   142,
       0,     0,   157,   164,   158,   165,   144,     0,   145,     0,
     130,   135,   133,   179,     0,   112,   127,     0,   119,     0,
     187,     0,   214,     0,   189,     0,     0,     0,     0,   218,
       0,    13,     0,   164,   163,     0,     0,    16,     0,    22,
      18,    19,    69,    39,    40,    41,    43,    44,    46,    47,
      49,    50,    51,    52,    54,    55,    57,    59,    61,    63,
       0,    65,    82,   194,   168,     0,   172,     0,     0,   166,
       0,     0,   154,   156,   161,   177,     0,   125,   128,   188,
       0,     0,     0,     0,     0,    29,    37,    15,    17,     0,
       0,   169,   173,   167,   170,     0,   174,     0,   178,   180,
       0,   207,     0,     0,   209,   210,    23,    67,   171,   175,
       0,     0,   212,     0,   211,   208,   213
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,  -230,  -230,   -57,  -230,  -107,    26,    32,
     -21,    29,    81,    82,    86,    88,    79,  -230,   -56,   -19,
    -230,   -53,   -66,    10,     0,  -230,   253,  -230,   145,  -230,
    -230,   250,   -70,   -63,  -230,    60,  -230,   261,   164,    47,
     -15,   -30,    -7,  -230,   -55,  -230,    73,  -230,   141,  -104,
    -229,  -143,  -230,   -91,  -230,    45,   -42,    61,   -39,  -168,
    -230,  -230,  -230,  -230,   295,  -230
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   115,   116,   117,   288,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     216,   133,   151,    54,    55,    44,    45,    25,    26,    27,
      28,    77,    78,    79,   173,   174,    29,    65,    66,    30,
      31,    32,    33,    42,   317,   156,   157,   158,   195,   318,
     255,   166,   264,   134,   135,   136,   247,   243,   248,   140,
     141,   142,   143,    34,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   149,   150,    60,   155,   183,    39,   171,     1,    46,
      23,   137,   217,   169,   139,    41,    64,   176,   276,    67,
       1,   263,     1,     1,   319,    47,    48,   180,    37,     1,
      51,   250,     1,   282,    24,    69,   149,   150,    49,   235,
     144,    22,   194,   236,    23,   160,   192,   337,   246,   190,
     254,   237,   193,   165,   319,   144,   197,   198,    21,   154,
      63,   161,   149,    43,   175,    75,    22,   145,   162,    40,
      21,   250,    21,   251,   172,    38,    56,   250,    22,   251,
      22,    22,    21,     4,   145,    50,    81,   270,   260,    68,
     284,    73,    57,   274,   261,   162,   242,    80,   171,   244,
     225,   226,   146,   149,   150,    20,   266,    74,   332,   227,
     228,   293,   294,   295,   138,   149,   150,   177,    58,   167,
      59,   178,    80,    80,    80,   182,    22,    80,   194,   325,
     179,    70,   275,    71,   277,   278,   326,   185,   193,   252,
     218,   219,   220,   193,   181,   165,   286,   253,   241,   223,
     184,   224,    80,   246,   237,   186,   238,   246,   258,   187,
     259,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   336,   149,
     329,   289,   310,   349,   315,   221,   222,   283,   199,   267,
     200,   268,   201,   149,   150,    76,   237,   292,   279,   231,
     281,   242,   237,   328,   300,   301,   302,   303,   229,   230,
     202,   203,   149,   150,   320,    80,   321,   250,   312,   282,
      76,    76,    76,    60,   331,    76,   237,   333,   149,   237,
     204,   334,   338,   237,   339,   360,    39,   237,    80,   363,
     351,   237,   354,   355,   253,   237,   340,   296,   297,   188,
      76,   154,   175,   241,   345,   298,   299,   154,   304,   305,
     232,   362,   233,   149,   150,   234,   347,   239,    72,     3,
     365,   249,   366,   257,   256,   283,   273,   350,   269,   353,
       4,   271,   154,   149,   357,   272,     6,   285,   290,     7,
       8,     9,   291,    11,    12,    13,    14,   324,    16,   330,
      18,    19,    20,   335,   341,   342,   361,   165,   343,   358,
     359,   170,   306,    76,   307,   311,     2,     3,   364,   308,
     356,   154,   309,   163,   159,   168,   262,   327,     4,    62,
     323,     5,   280,     0,     6,     0,    76,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    82,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     2,     3,     0,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     4,     0,     0,     5,
     100,   101,     6,   102,   103,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,   322,     0,     0,   104,    53,     0,
       0,   105,     0,     0,     0,     0,   106,   107,   108,   109,
       0,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     2,     3,     0,    92,
      93,    94,    95,    96,    97,    98,     0,    99,     4,     0,
       0,     5,   100,   101,     6,   102,   103,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,   240,
      53,     0,     0,   105,     0,     0,     0,     0,   106,   107,
     108,   109,     0,     0,   110,     0,     0,   111,   112,     0,
       0,     0,     0,   113,   114,    82,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     2,     3,
       0,    92,    93,    94,    95,    96,    97,    98,     0,    99,
       4,     0,     0,     5,   100,   101,     6,   102,   103,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,   245,    53,     0,     0,   105,     0,     0,     0,     0,
     106,   107,   108,   109,     0,     0,   110,     0,     0,   111,
     112,     0,     0,     0,     0,   113,   114,    82,     0,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       2,     3,     0,    92,    93,    94,    95,    96,    97,    98,
       0,    99,     4,     0,     0,     5,   100,   101,     6,   102,
     103,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,  -198,    53,     0,     0,   105,     0,     0,
       0,     0,   106,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,     0,     0,     0,   113,   114,    82,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     2,     3,     0,    92,    93,    94,    95,    96,
      97,    98,     0,    99,     4,     0,     0,     5,   100,   101,
       6,   102,   103,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,   313,    53,     0,     0,   105,
       0,     0,     0,     0,   106,   107,   108,   109,     0,     0,
     110,     0,     0,   111,   112,     0,     0,     0,     0,   113,
     114,    82,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     2,     3,     0,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     4,     0,     0,     5,
     100,   101,     6,   102,   103,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,  -197,    53,     0,
       0,   105,     0,     0,     0,     0,   106,   107,   108,   109,
       0,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     6,     0,   103,     7,     8,     9,     0,    11,
      12,    13,    14,     0,    16,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,   107,   108,   109,
       0,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     0,     0,     0,     0,
     100,   101,     0,   102,   103,     0,   205,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,   147,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   214,    53,   215,
       0,   105,     0,     0,     0,     0,   106,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,   348,   164,     0,     0,   105,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,   103,     0,     0,   113,   114,    83,
      84,    85,    86,    87,    88,    89,    90,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   105,     0,     0,     0,     0,     0,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,   164,     0,     0,   105,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,   103,     0,     0,   113,   114,    83,
      84,    85,    86,    87,    88,    89,    90,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,   189,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,   106,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,   103,     0,     0,   113,   114,    83,
      84,    85,    86,    87,    88,    89,    90,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   287,     0,     0,     0,     0,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,     0,     0,   314,   105,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,   103,     0,     0,   113,   114,    83,
      84,    85,    86,    87,    88,    89,    90,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,   105,     0,     0,     0,     0,     0,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,     0,     0,     0,   105,   352,     0,
       0,     0,     0,   107,   108,   109,     0,     0,   110,     0,
       0,   111,   112,     0,   103,     0,     0,   113,   114,    83,
      84,    85,    86,    87,    88,    89,    90,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,   107,   108,   109,
     103,     0,   110,     0,     0,   111,   112,     0,     0,     0,
       0,   113,   114,    83,    84,    85,    86,    87,    88,    89,
      90,   147,     0,     0,     0,     0,     0,   191,     0,     3,
       0,     0,     0,   107,   108,   109,     0,     0,   110,     0,
       4,   111,   112,     0,   103,     0,     6,   113,   114,     7,
       8,     9,     0,    11,    12,    13,    14,     0,    16,    52,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     2,     3,     0,     0,     0,   107,   108,   109,
       0,     0,   110,     0,     4,   111,   112,     5,     0,     0,
       6,   113,   114,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    61,     0,     0,     0,    53,     0,     0,     0,
       0,     0,   -94,     1,   -94,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     1,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     4,     0,     0,     5,
       0,    22,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     1,
       0,     0,     2,     3,     0,     0,     0,     0,     0,   250,
       0,   251,   316,     0,     4,     0,     0,     5,     0,    22,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       2,     3,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     2,     3,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     152,     0,     0,     2,     3,     0,     0,     0,     0,     0,
     250,     0,   282,   316,     0,     4,     0,     0,     5,     0,
      22,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,   153,     0,     5,     0,     0,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,   346,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     3,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     4,
       0,     0,     0,     0,     0,     6,     0,     0,     7,     8,
       9,     0,    11,    12,    13,    14,     0,    16,     0,    18,
      19,    20,     2,     3,     0,     0,     0,     0,     0,     0,
     265,     0,     0,     0,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    58,    58,    33,    59,    96,    21,    77,    11,    24,
       0,    53,   119,    76,    53,    22,    11,    80,   186,    62,
      11,   164,    11,    11,   253,    25,    26,    93,    11,    11,
      30,    59,    11,    61,    34,    42,    93,    93,    11,    80,
      55,    69,   105,    84,    34,    77,   103,    60,   139,   102,
     154,    64,   105,    72,   283,    70,   113,   114,    61,    59,
      58,    57,   119,    66,    79,    58,    69,    57,    64,    22,
      61,    59,    61,    61,    65,    58,    31,    59,    69,    61,
      69,    69,    61,    26,    74,    58,    66,   178,    57,    42,
     194,    46,    31,   184,   160,    64,   138,    50,   168,   138,
      78,    79,    57,   160,   160,    48,   172,    46,   276,    87,
      88,   218,   219,   220,    53,   172,   172,    66,    59,    74,
      61,    65,    75,    76,    77,    11,    69,    80,   191,    57,
      66,    64,   185,    66,   187,   188,    64,    61,   191,   154,
      69,    70,    71,   196,    66,   164,   199,   154,   138,    97,
      65,    99,   105,   244,    64,    61,    66,   248,    62,    61,
      64,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   285,   236,
     271,   200,   235,   326,   250,    67,    68,   194,    59,    64,
      61,    66,    63,   250,   250,    50,    64,   216,    66,    72,
      62,   243,    64,   269,   225,   226,   227,   228,    85,    86,
      81,    82,   269,   269,    59,   168,    61,    59,   237,    61,
      75,    76,    77,   253,    62,    80,    64,    62,   285,    64,
     101,    62,    62,    64,    64,    62,   251,    64,   191,    62,
     331,    64,   333,   334,   251,    64,    65,   221,   222,    61,
     105,   251,   267,   243,   320,   223,   224,   257,   229,   230,
      74,   352,    73,   320,   320,    83,   321,    57,    77,    15,
     361,    60,   363,    64,    62,   282,    31,   330,    65,   332,
      26,    65,   282,   340,   340,    66,    32,    62,    11,    35,
      36,    37,    11,    39,    40,    41,    42,    11,    44,    61,
      46,    47,    48,    62,    60,    62,    24,   326,    62,    60,
      62,    57,   231,   168,   232,   236,    14,    15,    66,   233,
     339,   321,   234,    70,    63,    75,   162,   267,    26,    34,
     257,    29,   191,    -1,    32,    -1,   191,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    57,    58,    -1,
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
      82,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    -1,    44,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    77,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    98,    58,   100,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    61,    -1,    15,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      26,    75,    76,    -1,    34,    -1,    32,    81,    82,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,     1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    14,    15,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    26,    75,    76,    29,    -1,    -1,
      32,    81,    82,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    11,    66,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    26,    -1,    -1,    29,
      -1,    69,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    11,
      -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    61,    62,    -1,    26,    -1,    -1,    29,    -1,    69,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      14,    15,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    62,    -1,    26,    -1,    -1,    29,    -1,
      69,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    62,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    62,    -1,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    -1,    46,
      47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    61,    69,   126,   127,   130,   131,   132,   133,   139,
     142,   143,   144,   145,   166,   167,   168,    11,    58,   143,
     142,   145,   146,    66,   128,   129,   143,   127,   127,    11,
      58,   127,     1,    58,   126,   127,   158,   160,    59,    61,
     144,     0,   167,    58,    11,   140,   141,    62,   142,   145,
      64,    66,    77,   158,   160,    58,   131,   134,   135,   136,
     142,    66,     1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    17,    18,    19,    20,    21,    22,    23,    25,
      30,    31,    33,    34,    57,    61,    66,    67,    68,    69,
      72,    75,    76,    81,    82,   104,   105,   106,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   124,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   143,   126,   158,    11,    60,   108,
     121,   125,    11,    62,   127,   147,   148,   149,   150,   140,
      77,    57,    64,   129,    58,   122,   154,   158,   134,   136,
      57,   135,    65,   137,   138,   143,   136,    66,    65,    66,
     125,    66,    11,   156,    65,    61,    61,    61,    61,    66,
     124,    61,   108,   124,   136,   151,    61,   108,   108,    59,
      61,    63,    81,    82,   101,    77,    89,    90,    91,    92,
      93,    94,    95,    96,    98,   100,   123,   110,    69,    70,
      71,    67,    68,    97,    99,    78,    79,    87,    88,    85,
      86,    72,    74,    73,    83,    80,    84,    64,    66,    57,
      57,   126,   159,   160,   161,    57,   156,   159,   161,    60,
      59,    61,   143,   145,   152,   153,    62,    64,    62,    64,
      57,   125,   141,   154,   155,    57,   125,    64,    66,    65,
     156,    65,    66,    31,   156,   124,   162,   124,   124,    66,
     151,    62,    61,   145,   152,    62,   124,    62,   107,   122,
      11,    11,   122,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   116,   117,   118,
     124,   119,   122,    57,    60,   125,    62,   147,   152,   153,
      59,    61,   102,   149,    11,    57,    64,   138,   125,   156,
      61,    62,   162,    62,    62,    62,   110,    60,    62,    64,
      65,    60,    62,    62,    60,   125,    62,   147,    57,   154,
     124,   156,    62,   124,   156,   156,   122,   121,    60,    62,
      62,    24,   156,    62,    66,   156,   156
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
     123,   124,   124,   125,   126,   126,   127,   127,   127,   127,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   135,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   157,   157,   157,
     158,   158,   158,   158,   158,   159,   159,   159,   159,   160,
     160,   160,   161,   161,   161,   162,   162,   163,   163,   163,
     164,   164,   164,   164,   165,   165,   165,   165,   165,   166,
     166,   166,   167,   167,   168,   168,   168,   168
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
       1,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     3,     4,     3,     4,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     2,     3,     3,     4,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     3,     3,     4,     2,     2,     1,     1,     1,
       2,     2,     1,     2,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     0,     1,     1,     4,     3,     3,     2
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
#line 257 "src/parser.y"
        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2040 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 261 "src/parser.y"
        { (yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2047 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 273 "src/parser.y"
                                {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 2053 "parser.tab.c"
    break;

  case 12: /* primary_expression: STRING_LITERAL  */
#line 274 "src/parser.y"
                         {
        // printf("This is a string literal: %s",$1);
    }
#line 2061 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 281 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2067 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 285 "src/parser.y"
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
#line 2084 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 319 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2090 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 337 "src/parser.y"
                           {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2096 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 342 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2102 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 349 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2108 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 355 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2114 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 361 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2120 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 369 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2126 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 375 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2132 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 380 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2138 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 385 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2144 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 390 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2150 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 395 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2156 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 400 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2162 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 406 "src/parser.y"
        { 
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2172 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 440 "src/parser.y"
    {
		printf("Declaration specifiers = %s\n", (yyvsp[-2].str));
		printf("Init declarator list = %f\n", (yyvsp[-1].symbol_info)->symbol_size);
		if((yyvsp[-2].str)!=(yyvsp[-1].symbol_info)->type){
			printf("Error: Type mismatch in declaration\n");
			exit(1);
		}
		
		else printf("Declaration is correct\n");
		
		

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
#line 2220 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 489 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 2226 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 496 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info);  
        //printf("init_declarator = %s\n", $$);
    }
#line 2235 "parser.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 500 "src/parser.y"
                                                 { 
        // $$ = (char*)malloc(strlen($1) + strlen($3) + 2); 
        // sprintf($$, "%s,%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "," + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator_list = %s\n", $$);
    }
#line 2249 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator  */
#line 512 "src/parser.y"
                 { 
        (yyval.symbol_info) =(yyvsp[0].symbol_info); 
        //printf("declarator = %s\n", $$);
    }
#line 2258 "parser.tab.c"
    break;

  case 95: /* init_declarator: declarator EQUALS initializer  */
#line 516 "src/parser.y"
                                    { 
        // $$ = malloc(strlen($1) + strlen($3) + 2);  
        // sprintf($$, "%s=%s", $1, $3);  
        // free($1); free($3);

        // string result = string($1) + "=" + string($3);
        // $$ = strdup(result.c_str());
        //printf("init_declarator with initializer = %s\n", $$);

		(yyval.symbol_info) = (yyvsp[0].symbol_info);
    }
#line 2274 "parser.tab.c"
    break;

  case 104: /* type_specifier: INT  */
#line 541 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 2280 "parser.tab.c"
    break;

  case 106: /* type_specifier: FLOAT  */
#line 543 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 2286 "parser.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 553 "src/parser.y"
        {
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        // assign_type(type_str);
        // insert_symtab('V', $2); 
	}
#line 2298 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID  */
#line 563 "src/parser.y"
        {
		char type_str[10];
        // get_type_string(type_str, $1);
        //printf("Variable declaration: %s = %s\n", $1, $2); 
        assign_type(type_str);
        // insert_symtab('V', $2); 
	}
#line 2310 "parser.tab.c"
    break;

  case 119: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 584 "src/parser.y"
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
#line 2347 "parser.tab.c"
    break;

  case 130: /* enum_specifier: ENUM ID LBRACE enumerator_list RBRACE  */
#line 639 "src/parser.y"
        {
		//printf("enum is here = %s\n",$$);
		char type_str[10];
      	// get_type_string(type_str,$$);
      	assign_type(type_str);
      	// insert_symtab('V',$2);
	}
#line 2359 "parser.tab.c"
    break;

  case 138: /* declarator: pointer direct_declarator  */
#line 665 "src/parser.y"
                                { 
		//printf("Pointer direct declarator\n");
        // $$ = malloc(strlen($1) + strlen($2) + 1); 
        // sprintf($$, "%s%s", $1, $2); 
		// //printf("it is $$: %s\n",$$); 
        // free($1); free($2);

        // string result = string($1) + string($2);
        // $$ = strdup(result.c_str());
    }
#line 2374 "parser.tab.c"
    break;

  case 139: /* declarator: direct_declarator  */
#line 675 "src/parser.y"
                        { 
        // $$ = strdup($1);  
		//printf("Direct declarator %s\n",$$);
    }
#line 2383 "parser.tab.c"
    break;

  case 141: /* direct_declarator: LPARENTHESES declarator RPARENTHESES  */
#line 684 "src/parser.y"
        { 
		//printf("LPar declarator RPar= %s\n",$2);
		// $$=strdup($2);
	}
#line 2392 "parser.tab.c"
    break;

  case 149: /* pointer: STAR pointer  */
#line 699 "src/parser.y"
        { 
        // $$ = malloc(strlen($2) + 2); 
        // sprintf($$, "*%s", $2);  
        // free($2);

        // string result = string("*") + string($2);
        // $$ = strdup(result.c_str());
    }
#line 2405 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 728 "src/parser.y"
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
#line 2446 "parser.tab.c"
    break;

  case 176: /* initializer: assignment_expression  */
#line 797 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2452 "parser.tab.c"
    break;

  case 201: /* declaration_list: error SEMICOLON  */
#line 840 "src/parser.y"
                          {yyerrok;}
#line 2458 "parser.tab.c"
    break;

  case 204: /* statement_list: error SEMICOLON  */
#line 846 "src/parser.y"
                          {yyerrok;}
#line 2464 "parser.tab.c"
    break;

  case 214: /* jump_statement: GOTO ID SEMICOLON  */
#line 869 "src/parser.y"
        { 
		//printf("Goto statement: %s\n",$2);
		
      	// insert_symtab('G',$2);
		

	}
#line 2476 "parser.tab.c"
    break;

  case 225: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 896 "src/parser.y"
        {   //printf("Function is there: %s %s\n",$1,$2);
		char type_str[10];
      	// get_type_string(type_str,$1);
      	assign_type(type_str);
      	// insert_symtab('F',$2);
	}
#line 2487 "parser.tab.c"
    break;


#line 2491 "parser.tab.c"

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

#line 905 "src/parser.y"


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



int main() {

    yyparse();

    print_symbol_table();
    printf("\n");
    print_constant_table();

}
