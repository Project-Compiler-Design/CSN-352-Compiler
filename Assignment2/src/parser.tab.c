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
#line 1 "parser.y"

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


#line 161 "parser.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_DECIMAL_LITERAL = 4,            /* DECIMAL_LITERAL  */
  YYSYMBOL_HEXA_LITERAL = 5,               /* HEXA_LITERAL  */
  YYSYMBOL_OCTAL_LITERAL = 6,              /* OCTAL_LITERAL  */
  YYSYMBOL_EXP_LITERAL = 7,                /* EXP_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 8,               /* REAL_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 9,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 10,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 11,         /* CHARACTER_LITERAL  */
  YYSYMBOL_INCLUDE = 12,                   /* INCLUDE  */
  YYSYMBOL_INVALID_ID = 13,                /* INVALID_ID  */
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
  YYSYMBOL_RBRACE = 49,                    /* RBRACE  */
  YYSYMBOL_LBRACE = 50,                    /* LBRACE  */
  YYSYMBOL_LBRACKET = 51,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 52,                  /* RBRACKET  */
  YYSYMBOL_LPARENTHESES = 53,              /* LPARENTHESES  */
  YYSYMBOL_RPARENTHESES = 54,              /* RPARENTHESES  */
  YYSYMBOL_DOT = 55,                       /* DOT  */
  YYSYMBOL_COMMA = 56,                     /* COMMA  */
  YYSYMBOL_COLON = 57,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 58,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 59,                      /* PLUS  */
  YYSYMBOL_MINUS = 60,                     /* MINUS  */
  YYSYMBOL_STAR = 61,                      /* STAR  */
  YYSYMBOL_DIVIDE = 62,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 63,                    /* MODULO  */
  YYSYMBOL_AMPERSAND = 64,                 /* AMPERSAND  */
  YYSYMBOL_OR = 65,                        /* OR  */
  YYSYMBOL_XOR = 66,                       /* XOR  */
  YYSYMBOL_EXCLAMATION = 67,               /* EXCLAMATION  */
  YYSYMBOL_TILDE = 68,                     /* TILDE  */
  YYSYMBOL_EQUALS = 69,                    /* EQUALS  */
  YYSYMBOL_LESS_THAN = 70,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 71,              /* GREATER_THAN  */
  YYSYMBOL_QUESTION_MARK = 72,             /* QUESTION_MARK  */
  YYSYMBOL_INCREMENT = 73,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 74,                 /* DECREMENT  */
  YYSYMBOL_REL_AND = 75,                   /* REL_AND  */
  YYSYMBOL_REL_OR = 76,                    /* REL_OR  */
  YYSYMBOL_REL_EQUALS = 77,                /* REL_EQUALS  */
  YYSYMBOL_REL_NOT_EQ = 78,                /* REL_NOT_EQ  */
  YYSYMBOL_LESS_EQUALS = 79,               /* LESS_EQUALS  */
  YYSYMBOL_GREATER_EQUALS = 80,            /* GREATER_EQUALS  */
  YYSYMBOL_ASSIGN_PLUS = 81,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 82,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_STAR = 83,               /* ASSIGN_STAR  */
  YYSYMBOL_ASSIGN_DIV = 84,                /* ASSIGN_DIV  */
  YYSYMBOL_ASSIGN_MOD = 85,                /* ASSIGN_MOD  */
  YYSYMBOL_ASSIGN_AND = 86,                /* ASSIGN_AND  */
  YYSYMBOL_ASSIGN_OR = 87,                 /* ASSIGN_OR  */
  YYSYMBOL_ASSIGN_XOR = 88,                /* ASSIGN_XOR  */
  YYSYMBOL_LEFT_SHIFT = 89,                /* LEFT_SHIFT  */
  YYSYMBOL_LEFT_SHIFT_EQ = 90,             /* LEFT_SHIFT_EQ  */
  YYSYMBOL_RIGHT_SHIFT = 91,               /* RIGHT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT_EQ = 92,            /* RIGHT_SHIFT_EQ  */
  YYSYMBOL_LAMBDA_ARROW = 93,              /* LAMBDA_ARROW  */
  YYSYMBOL_VARIABLE_ARGS = 94,             /* VARIABLE_ARGS  */
  YYSYMBOL_95_ = 95,                       /* '('  */
  YYSYMBOL_96_ = 96,                       /* ')'  */
  YYSYMBOL_97_ = 97,                       /* '['  */
  YYSYMBOL_98_ = 98,                       /* ']'  */
  YYSYMBOL_99_ = 99,                       /* '.'  */
  YYSYMBOL_100_ = 100,                     /* ','  */
  YYSYMBOL_101_ = 101,                     /* '&'  */
  YYSYMBOL_102_ = 102,                     /* '*'  */
  YYSYMBOL_103_ = 103,                     /* '+'  */
  YYSYMBOL_104_ = 104,                     /* '-'  */
  YYSYMBOL_105_ = 105,                     /* '~'  */
  YYSYMBOL_106_ = 106,                     /* '!'  */
  YYSYMBOL_107_ = 107,                     /* '/'  */
  YYSYMBOL_108_ = 108,                     /* '%'  */
  YYSYMBOL_109_ = 109,                     /* '<'  */
  YYSYMBOL_110_ = 110,                     /* '>'  */
  YYSYMBOL_111_ = 111,                     /* '^'  */
  YYSYMBOL_112_ = 112,                     /* '|'  */
  YYSYMBOL_113_ = 113,                     /* '?'  */
  YYSYMBOL_114_ = 114,                     /* ':'  */
  YYSYMBOL_115_ = 115,                     /* '='  */
  YYSYMBOL_116_ = 116,                     /* ';'  */
  YYSYMBOL_117_ = 117,                     /* '{'  */
  YYSYMBOL_118_ = 118,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 119,                 /* $accept  */
  YYSYMBOL_program = 120,                  /* program  */
  YYSYMBOL_include_statements = 121,       /* include_statements  */
  YYSYMBOL_include_statement = 122,        /* include_statement  */
  YYSYMBOL_function_definitions = 123,     /* function_definitions  */
  YYSYMBOL_function_definition = 124,      /* function_definition  */
  YYSYMBOL_type_specifier = 125,           /* type_specifier  */
  YYSYMBOL_statements = 126,               /* statements  */
  YYSYMBOL_statement = 127,                /* statement  */
  YYSYMBOL_variable_declaration = 128,     /* variable_declaration  */
  YYSYMBOL_constant = 129,                 /* constant  */
  YYSYMBOL_primary_expression = 130,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 131,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 132, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 133,         /* unary_expression  */
  YYSYMBOL_unary_operator = 134,           /* unary_operator  */
  YYSYMBOL_cast_expression = 135,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 136, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 137,      /* additive_expression  */
  YYSYMBOL_shift_expression = 138,         /* shift_expression  */
  YYSYMBOL_relational_expression = 139,    /* relational_expression  */
  YYSYMBOL_equality_expression = 140,      /* equality_expression  */
  YYSYMBOL_and_expression = 141,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 142,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 143,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 144,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 145,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 146,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 147,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 148,      /* assignment_operator  */
  YYSYMBOL_expression = 149,               /* expression  */
  YYSYMBOL_constant_expression = 150,      /* constant_expression  */
  YYSYMBOL_declaration = 151,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 152,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 153,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 154,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 155,  /* storage_class_specifier  */
  YYSYMBOL_struct_or_union_specifier = 156, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 157,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 158,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 159,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 160, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 161,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 162,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 163,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 164,          /* enumerator_list  */
  YYSYMBOL_enumerator = 165,               /* enumerator  */
  YYSYMBOL_type_qualifier = 166,           /* type_qualifier  */
  YYSYMBOL_declarator = 167,               /* declarator  */
  YYSYMBOL_direct_declarator = 168,        /* direct_declarator  */
  YYSYMBOL_pointer = 169,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 170,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 171,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 172,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 173,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 174,          /* identifier_list  */
  YYSYMBOL_type_name = 175,                /* type_name  */
  YYSYMBOL_abstract_declarator = 176,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 177, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 178,              /* initializer  */
  YYSYMBOL_initializer_list = 179,         /* initializer_list  */
  YYSYMBOL_labeled_statement = 180,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 181,       /* compound_statement  */
  YYSYMBOL_declaration_list = 182,         /* declaration_list  */
  YYSYMBOL_statement_list = 183,           /* statement_list  */
  YYSYMBOL_expression_statement = 184,     /* expression_statement  */
  YYSYMBOL_selection_statement = 185,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 186,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 187            /* jump_statement  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1771

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   349


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
       2,     2,     2,   106,     2,     2,     2,   108,   101,     2,
      95,    96,   102,   103,   100,   104,    99,   107,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   114,   116,
     109,   115,   110,   113,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,    98,   111,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   117,   112,   118,   105,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   105,   105,   109,   110,   114,   115,   119,   120,   124,
     133,   134,   135,   136,   137,   141,   142,   146,   147,   148,
     149,   153,   163,   164,   165,   166,   167,   168,   169,   170,
     174,   175,   176,   179,   183,   184,   185,   186,   187,   188,
     189,   190,   194,   195,   199,   200,   201,   202,   203,   204,
     208,   209,   210,   211,   212,   213,   217,   218,   222,   223,
     224,   225,   229,   230,   231,   235,   236,   237,   241,   242,
     243,   244,   245,   249,   250,   251,   255,   256,   260,   261,
     265,   266,   270,   271,   275,   276,   280,   281,   285,   286,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   304,   305,   309,   313,   314,   318,   319,   320,   321,
     322,   323,   327,   328,   332,   333,   337,   338,   339,   340,
     341,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   360,   361,   362,   365,   366,   370,   371,   375,
     379,   380,   381,   382,   386,   387,   391,   392,   393,   397,
     398,   399,   403,   404,   408,   409,   413,   414,   418,   419,
     423,   424,   425,   426,   427,   428,   429,   433,   434,   435,
     436,   440,   441,   446,   447,   451,   452,   456,   457,   458,
     462,   463,   467,   468,   472,   473,   474,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   490,   491,   492,   496,
     497,   501,   502,   503,   504,   505,   506,   510,   511,   512,
     516,   517,   518,   519,   523,   524,   528,   529,   533,   534,
     538,   539,   540,   544,   545,   546,   547,   551,   552,   553,
     554,   555,   569,   570,   571,   572
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
  "\"end of file\"", "error", "\"invalid token\"", "ID",
  "DECIMAL_LITERAL", "HEXA_LITERAL", "OCTAL_LITERAL", "EXP_LITERAL",
  "REAL_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "CHARACTER_LITERAL",
  "INCLUDE", "INVALID_ID", "AUTO", "STRUCT", "BOOL", "BREAK", "CASE",
  "CONTINUE", "GOTO", "DO", "DEFAULT", "IF", "ELSE", "FOR", "CONST",
  "TRUE", "FALSE", "STATIC", "SWITCH", "WHILE", "VOID", "RETURN", "SIZEOF",
  "FLOAT", "INT", "DOUBLE", "EXTERN", "SHORT", "LONG", "CHAR", "ENUM",
  "REGISTER", "SIGNED", "TYPEDEF", "UNION", "UNSIGNED", "VOLATILE",
  "RBRACE", "LBRACE", "LBRACKET", "RBRACKET", "LPARENTHESES",
  "RPARENTHESES", "DOT", "COMMA", "COLON", "SEMICOLON", "PLUS", "MINUS",
  "STAR", "DIVIDE", "MODULO", "AMPERSAND", "OR", "XOR", "EXCLAMATION",
  "TILDE", "EQUALS", "LESS_THAN", "GREATER_THAN", "QUESTION_MARK",
  "INCREMENT", "DECREMENT", "REL_AND", "REL_OR", "REL_EQUALS",
  "REL_NOT_EQ", "LESS_EQUALS", "GREATER_EQUALS", "ASSIGN_PLUS",
  "ASSIGN_MINUS", "ASSIGN_STAR", "ASSIGN_DIV", "ASSIGN_MOD", "ASSIGN_AND",
  "ASSIGN_OR", "ASSIGN_XOR", "LEFT_SHIFT", "LEFT_SHIFT_EQ", "RIGHT_SHIFT",
  "RIGHT_SHIFT_EQ", "LAMBDA_ARROW", "VARIABLE_ARGS", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "program", "include_statements", "include_statement",
  "function_definitions", "function_definition", "type_specifier",
  "statements", "statement", "variable_declaration", "constant",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-300)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -300,    22,    66,  -300,    30,  -300,  1488,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,     1,  -300,  -300,  -300,  -300,  -300,  -300,    41,    47,
    -300,   298,    41,  1395,  -300,     2,  -300,  1395,  1006,   -38,
      14,   -34,    84,    15,  -300,  -300,    47,    75,  1395,  -300,
    1006,  -300,    38,   459,  -300,   363,  -300,    21,  -300,  1006,
    1556,  1070,   -38,    84,     5,   -62,  -300,  -300,  -300,  -300,
      77,  -300,  1006,   459,   459,   663,  -300,    37,   459,    50,
    -300,  -300,  -300,  -300,  -300,  -300,  -300,  -300,    65,  1242,
     102,   188,   768,   107,   137,   148,   152,   160,   842,  1276,
    1349,  1349,   966,  -300,  -300,  -300,  -300,  -300,  -300,  -300,
    -300,  1723,  -300,  -300,  -300,  -300,   165,   272,  1242,  -300,
      54,    42,    89,   -28,    94,   158,   159,   151,   196,   -55,
    -300,  -300,   -71,  -300,  -300,   409,   513,  -300,  -300,  -300,
    -300,  -300,   -66,  -300,   157,  -300,  -300,  -300,  -300,    45,
     177,   175,  -300,    57,  -300,  -300,  -300,  -300,   178,   -29,
    1242,    84,  -300,   228,  -300,  1358,  -300,  -300,  -300,  1242,
     -15,  -300,   166,  -300,   768,  -300,   168,  -300,   167,   281,
     254,   768,  1242,   883,  1242,  1242,   239,  -300,  -300,   -12,
     966,  -300,  1242,  -300,  -300,    67,    20,   190,   230,  -300,
    -300,   297,  1082,  1242,   300,  -300,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,  -300,  -300,  -300,  1242,  -300,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1242,  -300,  -300,
     559,  -300,  -300,    41,  -300,   825,  1442,  1123,  -300,    10,
    -300,   136,  -300,  1663,  -300,   301,  -300,  -300,  -300,  -300,
    -300,  -300,  -300,    37,  -300,  1242,  -300,   768,  -300,   210,
    -300,    74,   883,    83,    92,  -300,  -300,   212,  -300,  1591,
     155,  -300,  1242,   285,  -300,  -300,   117,  -300,    -8,  -300,
    -300,  -300,  -300,  -300,    54,    54,    42,    42,    89,    89,
      89,    89,   -28,   -28,    94,   158,   159,   151,   196,   -37,
    -300,  -300,  -300,   825,  -300,  -300,  -300,   213,   214,  -300,
     208,   136,  1627,  1196,  -300,  -300,  -300,   721,  -300,  -300,
    -300,  1242,   768,  1230,   768,   768,  -300,  -300,  -300,   253,
    -300,  1242,  -300,  1242,  -300,   -21,  -300,  -300,  -300,  -300,
     218,  -300,   217,  -300,  -300,   119,   292,   768,   124,  -300,
    -300,  -300,  -300,  -300,   617,  -300,  -300,  -300,   203,   768,
    -300,   768,  -300,  -300,  -300,  -300,  -300
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     8,     1,     5,     3,     2,     6,   160,   119,
     135,   156,   118,   121,    11,    10,    12,   117,   123,    14,
      13,     0,   120,   128,   116,   136,   129,   157,     0,   167,
       7,   108,     0,   106,   130,     0,   131,   110,     0,   159,
       0,   151,     0,     0,   171,   169,   168,     0,   108,   109,
       0,   107,   134,     0,   111,     0,   214,     0,   235,     0,
       0,     0,   158,     0,   154,     0,   152,   161,   172,   170,
       0,   233,     0,     0,   141,     0,   137,     0,   143,    30,
      22,    25,    28,    24,    26,    23,    27,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,   218,
     210,   108,   216,    19,    31,    34,    44,    56,     0,    58,
      62,    65,    68,    73,    76,    78,    80,    82,    84,    86,
      88,   101,     0,   201,   202,     0,     0,   203,   204,   205,
     206,   104,     0,   112,   114,   215,   234,   180,   166,   179,
       0,   173,   175,     0,    30,   163,    56,   103,     0,     0,
       0,     0,   149,     0,   232,     0,   140,   133,   138,     0,
       0,   144,   146,   142,    20,   229,     0,   228,     0,     0,
       0,    20,     0,     0,     0,     0,    22,    18,   230,     0,
       0,    48,     0,    45,    46,     0,   182,     0,     0,    40,
      41,     0,     0,     0,     0,    94,    95,    91,    92,    93,
      98,   100,    99,    96,    97,    90,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   212,
       0,   211,   217,     0,   105,     0,     0,     0,   177,   184,
     178,   185,   164,     0,   165,     0,   162,   150,   155,   153,
      16,   132,   147,     0,   139,     0,   207,    20,   227,     0,
     209,     0,     0,     0,     0,    17,   231,     0,    33,     0,
     184,   183,     0,     0,    39,    36,     0,    42,     0,    38,
      89,    59,    60,    61,    63,    64,    66,    67,    71,    72,
      69,    70,    74,    75,    77,    79,    81,    83,    85,     0,
     102,   213,   113,     0,   196,   115,   192,     0,     0,   188,
       0,   186,     0,     0,   174,   176,   181,     0,   145,   148,
     208,     0,    20,     0,    20,    20,    49,    57,    27,     0,
      37,     0,    35,     0,   199,     0,   193,   187,   189,   194,
       0,   190,     0,     9,    15,     0,   220,    20,     0,   222,
     223,    21,    43,    87,     0,   197,   195,   191,     0,    20,
     225,    20,   198,   200,   224,   221,   226
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -300,  -300,  -300,  -300,  -300,  -300,    -6,  -300,   -90,  -300,
      40,  -300,  -300,  -300,   -25,  -300,  -106,    32,    12,     0,
      39,    91,    88,    98,   113,    90,  -300,   -36,  -175,  -300,
     -82,   -35,   -41,    -5,  -300,   105,  -300,  -300,  -300,   259,
     -67,   -63,  -300,    86,  -300,   287,   191,   112,     3,   -33,
     -23,  -300,   -57,  -300,   108,  -300,   185,  -130,  -219,  -299,
    -300,  -300,   110,   -13,   241,  -173,  -300,  -300,  -300
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,    30,    48,   327,   112,   113,
     114,   115,   116,   286,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   216,
     132,   158,    56,    57,   142,   143,    33,    34,    35,    75,
      76,    77,   170,   171,    36,    65,    66,    37,    43,    39,
      40,    46,   317,   151,   152,   153,   197,   318,   251,   315,
     345,   133,   134,    59,   136,   137,   138,   139,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    32,   180,   150,    41,    52,    45,    62,   168,    38,
     272,   166,   217,     8,   344,   173,   189,     8,   145,   250,
     195,   235,     3,    69,     8,   157,    49,   287,    51,   237,
     321,   145,    54,     7,   243,    50,   156,    72,   161,   196,
       8,   290,   135,    49,     8,   238,   242,    74,     8,   111,
     244,   225,   226,   157,   176,   149,   162,    60,   236,    61,
     144,   321,   310,   237,   156,   373,   281,    74,    74,    74,
     314,   161,    74,    11,   191,   193,   194,   343,     4,   364,
     172,   227,   228,    63,   266,   263,   179,    64,   237,   257,
     342,   270,   237,   156,   145,    27,    74,   365,   168,   333,
     271,   264,   273,   274,   276,   246,    49,   247,   195,    28,
     195,    67,   291,   292,   293,   279,    28,   247,    42,    53,
     160,   288,    29,    29,   157,   258,   249,   196,    70,   111,
     179,   163,    28,   157,   262,   156,    28,   141,   314,    29,
     246,    44,   247,    29,   156,   221,   222,    29,    58,    29,
     242,   169,   248,   254,   309,    73,   218,   255,    68,    74,
      71,   219,   220,   278,   174,    78,   362,   237,   179,   146,
     332,   229,   230,   280,   237,   179,   337,   330,   223,   334,
     224,   175,   164,   237,    74,    78,    78,    78,   335,   314,
      78,   178,   237,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   320,   340,    78,   368,    62,   341,   177,   237,
     371,   181,   156,   249,   237,   298,   299,   300,   301,   157,
     329,   322,   182,   323,   179,   296,   297,   354,   199,   200,
     156,   149,   356,   183,   359,   360,   144,   184,   149,   355,
     279,   358,   247,   294,   295,   185,   280,   156,   201,   231,
     202,   179,   203,   233,   204,   350,   172,   370,   302,   303,
     232,   234,   245,   252,   149,   253,   256,    78,   260,   375,
     265,   376,   267,   268,   198,   269,   282,   157,   352,    80,
      81,    82,    83,    84,    85,   338,    87,   275,   156,   283,
     284,    47,    78,   289,   326,   331,   348,   363,   336,   346,
     347,   361,     9,    10,   366,   367,   369,   149,   156,   374,
     305,   179,   304,   339,    11,   308,   179,    12,   179,   179,
      13,   306,   165,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   307,   312,   328,
     159,   179,   259,   205,   206,   207,   208,   209,   210,   211,
     212,   325,   213,   179,   214,   179,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   277,   240,     9,    10,     0,
      88,    89,    90,    91,    92,    93,    94,   215,    95,    11,
       0,     0,    12,    96,    97,    13,    98,    99,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     9,    10,     0,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    11,   100,   101,    12,    96,
      97,    13,    98,    99,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   102,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,    10,     0,     0,     0,     0,   109,
      55,   110,   100,   101,     0,    11,     0,     0,     0,     0,
       0,    13,     0,     0,    14,    15,    16,     0,    18,    19,
      20,    21,     0,    23,   102,    25,    26,    27,     0,     0,
     103,   104,   105,   106,   107,   108,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   109,    55,   239,    10,     0,
      88,    89,    90,    91,    92,    93,    94,     0,    95,     0,
       0,     0,     0,    96,    97,    13,    98,    99,    14,    15,
      16,     0,    18,    19,    20,    21,     0,    23,     0,    25,
      26,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,    10,     0,    88,    89,    90,    91,
      92,    93,    94,     0,    95,     0,   100,   101,     0,    96,
      97,    13,    98,    99,    14,    15,    16,     0,    18,    19,
      20,    21,     0,    23,     0,    25,    26,     0,   102,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     154,    80,    81,    82,    83,    84,    85,    86,    87,   109,
      55,   241,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   102,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,    55,   311,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
     100,   101,     0,     0,     0,    13,     0,     0,    14,    15,
      16,     0,    18,    19,    20,    21,     0,    23,     0,    25,
      26,    27,   102,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,   313,   372,    10,     0,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,     0,     0,
       0,    96,    97,    13,    98,    99,    14,    15,    16,     0,
      18,    19,    20,    21,     0,    23,     0,    25,    26,     0,
     353,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,   167,     0,    10,     0,    88,    89,    90,    91,    92,
      93,    94,     0,    95,   100,   101,     0,     0,    96,    97,
      13,    98,    99,    14,    15,    16,     0,    18,    19,    20,
      21,     0,    23,     0,    25,    26,   102,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   154,    80,
      81,    82,    83,    84,    85,    86,    87,   109,    55,     0,
       0,   100,   101,     0,     0,   154,   186,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,    99,
       0,     0,     0,   102,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   109,    55,   154,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,   100,   101,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,    99,     0,     0,
     102,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,   313,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
      80,    81,    82,    83,    84,    85,    86,    87,   102,     0,
       0,    10,     0,     0,   103,   104,   105,   106,   107,   108,
       0,     0,    11,     0,     0,     0,     0,     0,    13,   109,
      99,    14,    15,    16,     0,    18,    19,    20,    21,     0,
      23,     0,    25,    26,    27,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,    12,     0,     0,    13,   100,
     101,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,   102,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   154,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,   154,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   154,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,    99,     0,     0,
       0,     0,     0,     0,     0,   102,     0,     0,   155,     0,
       0,   103,   104,   105,   106,   107,   108,   102,   285,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,   100,   101,     0,   154,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,   319,     0,     0,   103,   104,   105,   106,   107,   108,
      99,     0,     0,   154,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,   154,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,   100,
     101,     0,     0,     0,     0,     0,    99,     0,     0,   154,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,   102,     0,     0,   351,     0,     0,   103,   104,   105,
     106,   107,   108,   100,   101,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   357,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   102,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   100,
     101,     0,   154,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,     0,    10,     0,     0,     0,   103,   104,   105,
     106,   107,   108,    99,    11,     0,     0,     0,     0,     0,
      13,     0,     0,    14,    15,    16,     0,    18,    19,    20,
      21,     0,    23,     0,    25,    26,    27,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,   100,   101,    12,     0,     0,    13,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   192,     8,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,    12,     0,     0,    13,     0,   261,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,    12,     0,     0,
      13,     0,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   246,   316,   247,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    28,     0,    12,     0,     0,    13,     0,
      29,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
      12,     0,     0,    13,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    11,     0,     0,    12,     0,     0,    13,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,   279,   316,   247,    11,
       0,     0,    12,    29,     0,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    12,     0,     0,    13,     0,   324,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27
};

static const yytype_int16 yycheck[] =
{
       6,     6,    92,    60,     3,     3,    29,    40,    75,     6,
     183,    74,   118,     3,   313,    78,    98,     3,    59,   149,
     102,    76,     0,    46,     3,    61,    31,   202,    33,   100,
     249,    72,    37,     3,   100,    32,    61,    50,   100,   102,
       3,   216,    55,    48,     3,   116,   136,    53,     3,    55,
     116,    79,    80,    89,    89,    60,   118,    95,   113,    97,
      57,   280,   237,   100,    89,   364,   196,    73,    74,    75,
     245,   100,    78,    26,    99,   100,   101,   114,    12,   100,
      77,   109,   110,   117,   174,   100,    92,     3,   100,   118,
      98,   181,   100,   118,   135,    48,   102,   118,   165,   272,
     182,   116,   184,   185,   116,    95,   111,    97,   190,    95,
     192,    96,   218,   219,   220,    95,    95,    97,   117,   117,
     115,   203,   102,   102,   160,   160,   149,   190,    53,   135,
     136,    54,    95,   169,   169,   160,    95,   116,   313,   102,
      95,    29,    97,   102,   169,   103,   104,   102,    38,   102,
     240,   114,   149,    96,   236,   117,   102,   100,    46,   165,
      50,   107,   108,    96,   114,    53,   341,   100,   174,    59,
      96,    77,    78,   196,   100,   181,   282,   267,    89,    96,
      91,   116,    72,   100,   190,    73,    74,    75,    96,   364,
      78,     3,   100,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   247,   247,    96,   102,    96,   249,   100,   116,   100,
      96,   114,   247,   246,   100,   225,   226,   227,   228,   265,
     265,    95,    95,    97,   240,   223,   224,   327,    73,    74,
     265,   246,   332,    95,   334,   335,   243,    95,   253,   331,
      95,   333,    97,   221,   222,    95,   279,   282,    93,   101,
      95,   267,    97,   112,    99,   322,   263,   357,   229,   230,
     111,    75,   115,    96,   279,   100,    98,   165,    50,   369,
     114,   371,   114,   116,     3,    31,    96,   323,   323,     4,
       5,     6,     7,     8,     9,    10,    11,    58,   323,    69,
       3,     3,   190,     3,     3,    95,    98,   343,    96,    96,
      96,    58,    14,    15,    96,    98,    24,   322,   343,   116,
     232,   327,   231,   283,    26,   235,   332,    29,   334,   335,
      32,   233,    73,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   234,   243,   263,
      63,   357,   161,    81,    82,    83,    84,    85,    86,    87,
      88,   253,    90,   369,    92,   371,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   190,   135,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,   115,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    73,    74,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    95,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,   116,
     117,   118,    73,    74,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    -1,    44,    95,    46,    47,    48,    -1,    -1,
     101,   102,   103,   104,   105,   106,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   116,   117,   118,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    -1,    46,
      47,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    -1,    73,    74,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    -1,    44,    -1,    46,    47,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,   106,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   116,
     117,   118,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      73,    74,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    -1,    46,
      47,    48,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,   105,   106,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,   117,   118,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    -1,    44,    -1,    46,    47,    -1,
      49,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,   118,    -1,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    73,    74,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    44,    -1,    46,    47,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,   104,   105,   106,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   116,   117,    -1,
      -1,    73,    74,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    73,    74,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    34,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,   117,   101,   102,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    95,    -1,
      -1,    15,    -1,    -1,   101,   102,   103,   104,   105,   106,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,   116,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    73,
      74,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,   101,   102,   103,   104,   105,   106,    95,    96,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,   101,   102,   103,   104,   105,   106,
      34,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,   101,   102,   103,
     104,   105,   106,    73,    74,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,   105,   106,    95,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,    73,
      74,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    15,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,    34,    26,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    44,    -1,    46,    47,    48,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    73,    74,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    95,     3,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,   118,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    95,    96,    97,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    95,    -1,    29,    -1,    -1,    32,    -1,
     102,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    26,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    26,
      -1,    -1,    29,   102,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    94,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   120,   121,     0,    12,   122,   123,     3,     3,    14,
      15,    26,    29,    32,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    95,   102,
     124,   125,   152,   155,   156,   157,   163,   166,   167,   168,
     169,     3,   117,   167,   166,   169,   170,     3,   125,   152,
     167,   152,     3,   117,   152,   117,   151,   152,   181,   182,
      95,    97,   168,   117,     3,   164,   165,    96,   166,   169,
      53,   181,   182,   117,   125,   158,   159,   160,   166,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    17,    18,
      19,    20,    21,    22,    23,    25,    30,    31,    33,    34,
      73,    74,    95,   101,   102,   103,   104,   105,   106,   116,
     118,   125,   127,   128,   129,   130,   131,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   149,   180,   181,   182,   183,   184,   185,   186,
     187,   116,   153,   154,   167,   151,   181,     3,    96,   152,
     171,   172,   173,   174,     3,    98,   133,   146,   150,   164,
     115,   100,   118,    54,   181,   158,   160,   118,   159,   114,
     161,   162,   167,   160,   114,   116,   150,   116,     3,   125,
     127,   114,    95,    95,    95,    95,     4,    58,   116,   149,
      95,   133,    95,   133,   133,   149,   160,   175,     3,    73,
      74,    93,    95,    97,    99,    81,    82,    83,    84,    85,
      86,    87,    88,    90,    92,   115,   148,   135,   102,   107,
     108,   103,   104,    89,    91,    79,    80,   109,   110,    77,
      78,   101,   111,   112,    75,    76,   113,   100,   116,   118,
     183,   118,   127,   100,   116,   115,    95,    97,   167,   169,
     176,   177,    96,   100,    96,   100,    98,   118,   150,   165,
      50,   118,   150,   100,   116,   114,   127,   114,   116,    31,
     127,   149,   184,   149,   149,    58,   116,   175,    96,    95,
     169,   176,    96,    69,     3,    96,   132,   147,   149,     3,
     147,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     138,   138,   139,   139,   140,   141,   142,   143,   144,   149,
     147,   118,   154,   117,   147,   178,    96,   171,   176,    98,
     150,   177,    95,    97,    94,   173,     3,   126,   162,   150,
     127,    95,    96,   184,    96,    96,    96,   135,    10,   129,
      96,   100,    98,   114,   178,   179,    96,    96,    98,    96,
     171,    98,   150,    49,   127,   149,   127,    96,   149,   127,
     127,    58,   147,   146,   100,   118,    96,    98,    96,    24,
     127,    96,   118,   178,   116,   127,   127
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   121,   121,   122,   122,   123,   123,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   135,   135,   136,   136,
     136,   136,   137,   137,   137,   138,   138,   138,   139,   139,
     139,   139,   139,   140,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   153,   153,   154,   154,   155,   155,   155,   155,
     155,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   156,   156,   156,   157,   157,   158,   158,   159,
     160,   160,   160,   160,   161,   161,   162,   162,   162,   163,
     163,   163,   164,   164,   165,   165,   166,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   169,   169,   169,
     169,   170,   170,   171,   171,   172,   172,   173,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   178,   179,
     179,   127,   127,   127,   127,   127,   127,   180,   180,   180,
     181,   181,   181,   181,   182,   182,   183,   183,   184,   184,
     185,   185,   185,   186,   186,   186,   186,   187,   187,   187,
     187,   187,   124,   124,   124,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     2,     0,     7,
       1,     1,     1,     1,     1,     2,     0,     3,     2,     1,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
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
       2,     3,     3,     4,     1,     2,     1,     2,     1,     2,
       5,     7,     5,     5,     7,     6,     7,     3,     2,     2,
       2,     3,     4,     3,     3,     2
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
  case 5: /* include_statement: INCLUDE  */
#line 114 "parser.y"
            { printf("This is an include statement: %s\n", (yyvsp[0].str)); }
#line 1916 "parser.tab.c"
    break;

  case 6: /* include_statement: INCLUDE ID  */
#line 115 "parser.y"
                 { printf("This is an include statement: %s\n", (yyvsp[-1].str)); }
#line 1922 "parser.tab.c"
    break;

  case 9: /* function_definition: type_specifier ID LPARENTHESES RPARENTHESES LBRACE statements RBRACE  */
#line 125 "parser.y"
    { printf("This is a function: %s\n", (yyvsp[-5].str));
      char type_str[10];
      get_type_string(type_str,(yyvsp[-6].str));
      assign_type(type_str);
      insert_symtab('F',(yyvsp[-5].str)); }
#line 1932 "parser.tab.c"
    break;

  case 17: /* statement: RETURN DECIMAL_LITERAL SEMICOLON  */
#line 146 "parser.y"
                                     { printf("Return statement with value %s\n", (yyvsp[-1].str)); }
#line 1938 "parser.tab.c"
    break;

  case 18: /* statement: RETURN SEMICOLON  */
#line 147 "parser.y"
                       { printf("Return statement without value\n"); }
#line 1944 "parser.tab.c"
    break;

  case 21: /* variable_declaration: type_specifier ID EQUALS constant SEMICOLON  */
#line 153 "parser.y"
                                                { 
        char type_str[10];
        get_type_string(type_str, (yyvsp[-4].str));
        printf("Variable declaration: %s = %s\n", (yyvsp[-4].str), (yyvsp[-3].str)); 
        assign_type(type_str);
        insert_symtab('V', (yyvsp[-3].str)); 
    }
#line 1956 "parser.tab.c"
    break;

  case 32: /* primary_expression: STRING_LITERAL  */
#line 176 "parser.y"
                         {
        printf("This is a string literal: %s",(yyvsp[0].str));
    }
#line 1964 "parser.tab.c"
    break;


#line 1968 "parser.tab.c"

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

#line 574 "parser.y"


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
