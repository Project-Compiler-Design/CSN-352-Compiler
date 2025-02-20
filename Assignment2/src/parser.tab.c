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
  YYSYMBOL_YYACCEPT = 95,                  /* $accept  */
  YYSYMBOL_constant = 96,                  /* constant  */
  YYSYMBOL_primary_expression = 97,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 98,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 99,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 100,         /* unary_expression  */
  YYSYMBOL_unary_operator = 101,           /* unary_operator  */
  YYSYMBOL_cast_expression = 102,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 103, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 104,      /* additive_expression  */
  YYSYMBOL_shift_expression = 105,         /* shift_expression  */
  YYSYMBOL_relational_expression = 106,    /* relational_expression  */
  YYSYMBOL_equality_expression = 107,      /* equality_expression  */
  YYSYMBOL_and_expression = 108,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 109,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 110,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 111,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 112,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 113,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 114,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 115,      /* assignment_operator  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_constant_expression = 117,      /* constant_expression  */
  YYSYMBOL_declaration = 118,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 119,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 120,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 121,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 122,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 123,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 124, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 125,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 126,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 127,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 128, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 129,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 130,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 131,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 132,          /* enumerator_list  */
  YYSYMBOL_enumerator = 133,               /* enumerator  */
  YYSYMBOL_type_qualifier = 134,           /* type_qualifier  */
  YYSYMBOL_declarator = 135,               /* declarator  */
  YYSYMBOL_direct_declarator = 136,        /* direct_declarator  */
  YYSYMBOL_pointer = 137,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 138,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 139,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 140,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 141,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 142,          /* identifier_list  */
  YYSYMBOL_type_name = 143,                /* type_name  */
  YYSYMBOL_abstract_declarator = 144,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 145, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 146,              /* initializer  */
  YYSYMBOL_initializer_list = 147,         /* initializer_list  */
  YYSYMBOL_statement = 148,                /* statement  */
  YYSYMBOL_labeled_statement = 149,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 150,       /* compound_statement  */
  YYSYMBOL_declaration_list = 151,         /* declaration_list  */
  YYSYMBOL_statement_list = 152,           /* statement_list  */
  YYSYMBOL_expression_statement = 153,     /* expression_statement  */
  YYSYMBOL_selection_statement = 154,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 155,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 156,           /* jump_statement  */
  YYSYMBOL_translation_unit = 157,         /* translation_unit  */
  YYSYMBOL_external_declaration = 158,     /* external_declaration  */
  YYSYMBOL_function_definition = 159       /* function_definition  */
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
#define YYLAST   1652

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   178,   178,   179,   180,   181,   182,   183,   184,   185,
     189,   190,   191,   194,   198,   199,   200,   201,   202,   203,
     204,   205,   209,   210,   214,   215,   216,   217,   218,   219,
     223,   224,   225,   226,   227,   228,   232,   233,   237,   238,
     239,   240,   244,   245,   246,   250,   251,   252,   256,   257,
     258,   259,   260,   264,   265,   266,   270,   271,   275,   276,
     280,   281,   285,   286,   290,   291,   295,   296,   300,   301,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   319,   320,   324,   328,   329,   349,   350,   351,   352,
     353,   354,   358,   362,   371,   372,   379,   380,   381,   382,
     383,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   402,   403,   404,   407,   408,   412,   413,   417,
     421,   422,   423,   424,   428,   429,   433,   434,   435,   439,
     440,   441,   445,   446,   450,   451,   455,   456,   460,   461,
     465,   466,   467,   468,   469,   470,   471,   475,   476,   477,
     478,   482,   483,   488,   489,   493,   494,   498,   499,   500,
     504,   505,   509,   510,   514,   515,   516,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   532,   533,   534,   538,
     539,   543,   544,   545,   546,   547,   548,   552,   553,   554,
     558,   559,   560,   561,   565,   566,   570,   571,   575,   576,
     580,   581,   582,   586,   587,   588,   589,   593,   594,   595,
     596,   597,   601,   602,   606,   607,   611,   612,   613,   614
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
  "RIGHT_SHIFT_EQ", "LAMBDA_ARROW", "VARIABLE_ARGS", "$accept", "constant",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1302,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,     3,  -221,  -221,  -221,  -221,  -221,
    -221,    26,    14,  -221,     6,  1532,  1532,  -221,    16,  -221,
    1532,  1495,    72,     7,  1205,  -221,  -221,   -39,    25,   -23,
    -221,  -221,    14,  -221,    81,  -221,  1338,  -221,  -221,    -7,
    1604,  -221,   310,  -221,     6,  -221,  1495,   774,  1384,    72,
    -221,  -221,    25,   -18,    27,  -221,  -221,  -221,  -221,    26,
    -221,   790,  -221,  1495,  1604,  1604,  1566,  -221,    20,  1604,
      85,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,    -1,
    1077,    38,    68,   670,   123,   133,   152,   183,   190,   812,
    1093,  -221,   454,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    1165,  1165,  -221,  -221,   138,   481,  1077,  -221,   135,    97,
      57,    41,   131,   153,   179,   184,   176,    33,  -221,  -221,
      93,  -221,  -221,  -221,   382,   526,  -221,  -221,  -221,  -221,
     191,  -221,  -221,  -221,  -221,  -221,  -221,   200,  -221,  -221,
      17,   210,   213,  -221,   127,    35,  1077,  -221,    25,  -221,
     790,  -221,  -221,  -221,  1585,  -221,  -221,  -221,  1077,   134,
    -221,   215,  -221,   670,  -221,   220,  -221,   235,   247,   670,
    1077,   884,  1077,  1077,  -221,   143,   454,  -221,   146,   -37,
     240,  1077,  -221,  -221,  1077,   900,   292,  -221,  -221,   293,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  1077,  -221,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  -221,  -221,   598,  -221,  -221,  -221,   972,
    1253,  -221,    39,  -221,   163,  -221,   244,  -221,   294,  -221,
    -221,  -221,  -221,    59,  -221,  -221,    20,  -221,  1077,  -221,
     670,  -221,   246,  -221,   164,   884,   167,   168,  -221,   248,
    -221,  1419,   174,  -221,  1077,    54,  -221,   172,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,   135,   135,    97,    97,    57,
      57,    57,    57,    41,    41,   131,   153,   179,   184,    75,
     176,  -221,  -221,  -221,   249,  -221,   250,   251,   163,   989,
    1460,  -221,  -221,  -221,  -221,   702,  -221,  -221,  -221,  1077,
     670,  1061,   670,   670,  -221,  -221,  -221,  -221,  1077,  1077,
    -221,  -221,  -221,  -221,   254,  -221,   253,  -221,  -221,   185,
     276,   670,   188,  -221,  -221,  -221,  -221,  -221,  -221,   245,
     670,  -221,   670,  -221,  -221,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   140,    99,   115,   136,    98,   101,   106,   104,   107,
      97,   103,   105,   102,     0,   100,   108,    96,   116,   109,
     137,     0,   147,   215,     0,    86,    88,   110,     0,   111,
      90,     0,   139,     0,     0,   212,   214,   131,     0,     0,
     151,   149,   148,    84,     0,    92,    94,    87,    89,   114,
       0,    91,     0,   194,     0,   219,     0,     0,     0,   138,
       1,   213,     0,   134,     0,   132,   141,   152,   150,     0,
      85,     0,   217,     0,     0,   121,     0,   117,     0,   123,
      10,     2,     5,     8,     4,     6,     3,     7,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,     0,   198,    32,    33,    31,    30,    35,    34,
       0,     0,    11,    14,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    68,    81,
       0,   196,   181,   182,     0,     0,   183,   184,   185,   186,
      94,   195,   218,    10,   143,    36,    83,     0,   160,   146,
     159,     0,   153,   155,     0,     0,     0,   129,     0,    93,
       0,   176,    95,   216,     0,   120,   113,   118,     0,     0,
     124,   126,   122,     0,   209,     0,   208,     0,     0,     0,
       0,     0,     0,     0,   210,     0,     0,    28,     0,   162,
       0,     0,    25,    26,     0,     0,     0,    20,    21,     0,
      70,    74,    75,    71,    72,    73,    78,    80,    79,    76,
      77,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   192,     0,   191,   197,   142,     0,
       0,   157,   164,   158,   165,   144,     0,   145,     0,   130,
     135,   133,   179,     0,   112,   127,     0,   119,     0,   187,
       0,   207,     0,   189,     0,     0,     0,     0,   211,     0,
      13,     0,   164,   163,     0,     0,    16,     0,    22,    18,
      19,    69,    39,    40,    41,    43,    44,    46,    47,    49,
      50,    51,    52,    54,    55,    57,    59,    61,    63,     0,
      65,    82,   193,   168,     0,   172,     0,     0,   166,     0,
       0,   154,   156,   161,   177,     0,   125,   128,   188,     0,
       0,     0,     0,     0,    29,    37,    15,    17,     0,     0,
     169,   173,   167,   170,     0,   174,     0,   178,   180,     0,
     200,     0,     0,   202,   203,    23,    67,   171,   175,     0,
       0,   205,     0,   204,   201,   206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,   -55,  -221,   -79,    31,    44,
     -68,     8,    82,    95,    84,    80,    92,  -221,   -54,   -17,
    -221,   -53,   -52,    13,     0,  -221,   257,  -221,    24,  -221,
    -221,   260,   -69,   -58,  -221,   105,  -221,   275,   204,    43,
      -6,   -29,   -10,  -221,   -57,  -221,   118,  -221,   180,  -109,
    -220,  -133,  -221,   -85,  -221,    51,   -13,   231,  -176,  -221,
    -221,  -221,  -221,   333,  -221
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   112,   113,   114,   277,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     211,   130,   147,    53,    54,    44,    45,    25,    26,    27,
      28,    76,    77,    78,   169,   170,    29,    64,    65,    30,
      31,    32,    33,    42,   306,   152,   153,   154,   190,   307,
     244,   162,   253,   131,   132,   133,    56,   135,   136,   137,
     138,   139,    34,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   151,   145,   146,    59,   265,    37,   167,   178,     1,
       1,    62,    41,    23,   239,    39,   271,   165,    46,    49,
       1,   172,   308,     1,    22,    47,    48,   252,    63,     1,
      51,    66,    68,    73,    24,   145,   146,   212,   175,   134,
       4,   243,     1,    74,   189,   187,   185,    23,   140,   188,
     237,   156,   308,    38,   161,   192,   193,   174,   150,    21,
      21,   145,    20,   140,    43,    40,    50,    22,   239,   141,
     240,   177,   171,    21,    75,    22,   157,   168,    22,    21,
     273,    22,    55,   158,   249,    67,   141,    22,   259,   321,
     239,   158,   240,    79,   263,   167,   176,    72,    75,    75,
      75,   145,   146,    75,   250,   230,   326,   142,   314,   231,
     232,   220,   221,   145,   146,   315,   255,    79,    79,    79,
     222,   223,    79,    57,   163,    58,    75,   264,   189,   266,
     267,   232,   329,   188,   282,   283,   284,    69,   188,    70,
     242,   275,   173,   161,   241,    79,   218,   141,   219,   232,
     237,   233,   289,   290,   291,   292,   216,   217,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   318,   145,   299,   278,   272,
     179,   247,   338,   248,   145,   146,   180,   304,    75,   194,
     256,   195,   257,   196,   281,   325,   213,   214,   215,   232,
     270,   268,   232,   145,   146,   181,   317,    79,   224,   225,
      75,   197,   198,    59,   309,   301,   310,   226,   320,   145,
     232,   322,   323,   232,   232,   239,   327,   271,   328,    79,
     242,   199,   293,   294,    39,   340,   182,   343,   344,   349,
     150,   232,   352,   183,   232,   227,   150,   285,   286,   228,
     171,   229,   238,   336,   145,   146,   351,   334,     2,     3,
      71,   272,   287,   288,   245,   354,   339,   355,   342,   246,
       4,   150,   258,     5,   145,   346,     6,   260,   262,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   261,   274,   279,   280,   313,   161,   319,
     350,   330,   324,   353,   331,   332,   347,   348,   295,   298,
     150,   345,   297,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   296,   300,     2,     3,   159,    89,    90,    91,
      92,    93,    94,    95,   164,    96,     4,   155,   311,     5,
      97,    98,     6,    99,   100,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   101,
      52,   316,   251,   102,   312,   235,   269,    61,   103,   104,
     105,   106,     0,     0,   107,     0,     0,   108,   109,     0,
       0,     0,     0,   110,   111,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     2,     3,     0,    89,
      90,    91,    92,    93,    94,    95,     0,    96,     4,     0,
       0,     5,    97,    98,     6,    99,   100,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   234,    52,     0,     0,   102,     0,     0,     0,     0,
     103,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,   143,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     6,     0,   100,     7,
       8,     9,     0,    11,    12,    13,    14,     0,    16,     0,
      18,    19,    20,     0,     0,     0,     0,   102,     0,     0,
       0,     0,     0,   104,   105,   106,     0,     0,   107,     0,
       0,   108,   109,     0,     0,     0,     0,   110,   111,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
     200,    96,     0,     0,     0,     0,    97,    98,     0,    99,
     100,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,     0,   210,     0,   236,    52,     0,     0,   102,
       0,     0,     0,     0,   103,   104,   105,   106,     0,     0,
     107,     0,     0,   108,   109,     0,     0,     0,     0,   110,
     111,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    95,     0,    96,     0,     0,     0,     0,    97,    98,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,    52,     0,
       0,   102,     0,     0,     0,     0,   103,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,     0,     0,
       0,   110,   111,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,     0,    96,     0,     0,     0,     0,
      97,    98,     0,    99,   100,   143,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
      52,     0,     0,   102,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,   107,     0,   100,   108,   109,     0,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
       0,   337,   160,     0,     0,   102,     0,     0,     0,     0,
       0,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,   143,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,   143,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,     0,   143,    81,    82,    83,    84,
      85,    86,    87,    88,   100,     0,   144,   102,     0,     0,
       0,     0,     0,   104,   105,   106,     0,     0,   107,     0,
     160,   108,   109,   102,     0,     0,   100,   110,   111,   104,
     105,   106,     0,     0,   107,     0,     0,   108,   109,     0,
       0,     0,     0,   110,   111,   102,     0,     0,     0,     0,
     184,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,   143,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,   143,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,   102,     0,     0,
       0,     0,   103,   104,   105,   106,     0,     0,   107,     0,
       0,   108,   109,   102,   276,     0,     0,   110,   111,   104,
     105,   106,     0,     0,   107,     0,     0,   108,   109,     0,
       0,     0,     0,   110,   111,   143,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,   143,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   303,   102,     0,     0,     0,     0,
       0,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,   333,   102,     0,     0,   110,   111,     0,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,     0,
       0,     0,   110,   111,   143,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
     143,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,   100,   143,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,   100,     0,     0,   102,   341,     0,     0,     0,     0,
     104,   105,   106,     0,     0,   107,     0,   100,   108,   109,
     102,     0,     0,     0,   110,   111,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,   186,     0,     0,     0,
     110,   111,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,   143,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,     0,     0,    60,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,     2,
       3,     0,     0,     0,   104,   105,   106,     0,     0,   107,
       0,     4,   108,   109,     5,     0,     0,     6,   110,   111,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     1,     0,    21,     0,
       0,     0,     0,     0,     0,     0,    22,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,   239,     1,   240,   305,     0,     0,
       0,     0,     0,     0,    22,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     2,     3,     0,    21,     0,     0,     0,     0,
       0,     0,     0,    22,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   148,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     2,     3,     0,     0,     0,   149,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
     239,     0,   271,   305,     2,     3,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     4,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     2,
       3,     0,     0,     0,   335,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    52,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,     6,     0,
       3,     7,     8,     9,     0,    11,    12,    13,    14,     0,
      16,     4,    18,    19,    20,   166,     0,     6,     0,     3,
       7,     8,     9,     0,    11,    12,    13,    14,     0,    16,
       4,    18,    19,    20,   254,     0,     6,     0,     0,     7,
       8,     9,     0,    11,    12,    13,    14,     0,    16,     0,
      18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    58,    57,    57,    33,   181,     3,    76,    93,     3,
       3,    50,    22,     0,    51,    21,    53,    75,    24,     3,
       3,    79,   242,     3,    61,    25,    26,   160,     3,     3,
      30,    54,    42,    46,    34,    90,    90,   116,    90,    52,
      26,   150,     3,    50,   102,   100,    99,    34,    54,   102,
     135,    69,   272,    50,    71,   110,   111,    58,    58,    53,
      53,   116,    48,    69,    58,    22,    50,    61,    51,    56,
      53,     3,    78,    53,    50,    61,    49,    57,    61,    53,
     189,    61,    31,    56,    49,    42,    73,    61,   173,   265,
      51,    56,    53,    50,   179,   164,    58,    46,    74,    75,
      76,   156,   156,    79,   156,    72,    52,    56,    49,    76,
      56,    70,    71,   168,   168,    56,   168,    74,    75,    76,
      79,    80,    79,    51,    73,    53,   102,   180,   186,   182,
     183,    56,    57,   186,   213,   214,   215,    56,   191,    58,
     150,   194,    57,   160,   150,   102,    89,   134,    91,    56,
     235,    58,   220,   221,   222,   223,    59,    60,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   260,   231,   230,   195,   189,
      57,    54,   315,    56,   239,   239,    53,   239,   164,    51,
      56,    53,    58,    55,   211,   274,    61,    62,    63,    56,
      54,    58,    56,   258,   258,    53,   258,   164,    77,    78,
     186,    73,    74,   242,    51,   232,    53,    64,    54,   274,
      56,    54,    54,    56,    56,    51,    54,    53,    56,   186,
     240,    93,   224,   225,   240,   320,    53,   322,   323,    54,
     240,    56,    54,    53,    56,    66,   246,   216,   217,    65,
     256,    75,    52,   310,   309,   309,   341,   309,    14,    15,
      69,   271,   218,   219,    54,   350,   319,   352,   321,    56,
      26,   271,    57,    29,   329,   329,    32,    57,    31,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    58,    54,     3,     3,     3,   315,    53,
      24,    52,    54,    58,    54,    54,    52,    54,   226,   229,
     310,   328,   228,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   227,   231,    14,    15,    69,    17,    18,    19,
      20,    21,    22,    23,    74,    25,    26,    62,    94,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   256,   158,    53,   246,   134,   186,    34,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    73,    74,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      69,    25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    -1,    92,    -1,    49,    50,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    73,
      74,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    73,    74,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    34,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    34,    -1,    52,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      50,    67,    68,    53,    -1,    -1,    34,    73,    74,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    73,    74,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    67,    68,    53,    54,    -1,    -1,    73,    74,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    73,    74,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    52,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    67,
      68,    52,    53,    -1,    -1,    73,    74,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    73,    74,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    34,    67,    68,
      53,    -1,    -1,    -1,    73,    74,    59,    60,    61,    -1,
      -1,    64,    -1,    -1,    67,    68,    53,    -1,    -1,    -1,
      73,    74,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    73,    74,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    14,
      15,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    26,    67,    68,    29,    -1,    -1,    32,    73,    74,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,     3,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    51,     3,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    14,    15,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     3,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    14,    15,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    -1,    53,    54,    14,    15,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    14,
      15,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      15,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    26,    46,    47,    48,    49,    -1,    32,    -1,    15,
      35,    36,    37,    -1,    39,    40,    41,    42,    -1,    44,
      26,    46,    47,    48,    49,    -1,    32,    -1,    -1,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    53,    61,   118,   119,   122,   123,   124,   125,   131,
     134,   135,   136,   137,   157,   158,   159,     3,    50,   135,
     134,   137,   138,    58,   120,   121,   135,   119,   119,     3,
      50,   119,    50,   118,   119,   150,   151,    51,    53,   136,
       0,   158,    50,     3,   132,   133,    54,   134,   137,    56,
      58,    69,   150,   151,    50,   123,   126,   127,   128,   134,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    17,
      18,    19,    20,    21,    22,    23,    25,    30,    31,    33,
      34,    49,    53,    58,    59,    60,    61,    64,    67,    68,
      73,    74,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     135,   118,   150,     3,    52,   100,   113,   117,     3,    54,
     119,   139,   140,   141,   142,   132,    69,    49,    56,   121,
      50,   114,   146,   150,   126,   128,    49,   127,    57,   129,
     130,   135,   128,    57,    58,   117,    58,     3,   148,    57,
      53,    53,    53,    53,    58,   116,    53,   100,   116,   128,
     143,    53,   100,   100,    51,    53,    55,    73,    74,    93,
      69,    81,    82,    83,    84,    85,    86,    87,    88,    90,
      92,   115,   102,    61,    62,    63,    59,    60,    89,    91,
      70,    71,    79,    80,    77,    78,    64,    66,    65,    75,
      72,    76,    56,    58,    49,   152,    49,   148,    52,    51,
      53,   135,   137,   144,   145,    54,    56,    54,    56,    49,
     117,   133,   146,   147,    49,   117,    56,    58,    57,   148,
      57,    58,    31,   148,   116,   153,   116,   116,    58,   143,
      54,    53,   137,   144,    54,   116,    54,    99,   114,     3,
       3,   114,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   106,   106,   107,   108,   109,   110,   116,
     111,   114,    49,    52,   117,    54,   139,   144,   145,    51,
      53,    94,   141,     3,    49,    56,   130,   117,   148,    53,
      54,   153,    54,    54,    54,   102,    52,    54,    56,    57,
      52,    54,    54,    52,   117,    54,   139,    49,   146,   116,
     148,    54,   116,   148,   148,   114,   113,    52,    54,    54,
      24,   148,    54,    58,   148,   148
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   125,   125,   126,   126,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   130,   131,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   146,   146,   146,   147,
     147,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     150,   150,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   155,   155,   155,   155,   156,   156,   156,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159
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
       2,     3,     3,     4,     1,     2,     1,     2,     1,     2,
       5,     7,     5,     5,     7,     6,     7,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     3,     2
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
  case 12: /* primary_expression: STRING_LITERAL  */
#line 191 "parser.y"
                         {
        printf("This is a string literal: %s",(yyvsp[0].str));
    }
#line 1851 "parser.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression LPARENTHESES RPARENTHESES  */
#line 200 "parser.y"
                                                                                        {printf("Brackets found\n");}
#line 1857 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 330 "parser.y"
        {
        printf("declaration  = %s\n", (yyvsp[-1].str));
        char type_str[10];
        get_type_string(type_str, (yyvsp[-2].str));

        // Tokenize the init_declarator_list to extract variable names
        char *token = strtok((yyvsp[-1].str), ",");
		
        while (token != NULL) {
            printf("Variable declaration: %s = %s\n", type_str, token); 
			assign_type(type_str);
            insert_symtab('V', token);
            token = strtok(NULL, ",");
        }
		free((yyvsp[-1].str));
	}
#line 1878 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 358 "parser.y"
                          { 
        (yyval.str) = strdup((yyvsp[0].str));  // Store the first variable
        printf("init_declarator = %s\n", (yyval.str));
    }
#line 1887 "parser.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 362 "parser.y"
                                                     { 
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2); // Allocate space for "a,b"
        sprintf((yyval.str), "%s,%s", (yyvsp[-2].str), (yyvsp[0].str));  // Concatenate "a,b"
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        printf("init_declarator_list = %s\n", (yyval.str));
    }
#line 1898 "parser.tab.c"
    break;

  case 104: /* type_specifier: INT  */
#line 390 "parser.y"
                                        {printf("Integer\n");}
#line 1904 "parser.tab.c"
    break;

  case 140: /* direct_declarator: ID  */
#line 465 "parser.y"
                            {printf("Identifier in direct declarator = %s\n",(yyvsp[0].str));}
#line 1910 "parser.tab.c"
    break;

  case 145: /* direct_declarator: direct_declarator LPARENTHESES identifier_list RPARENTHESES  */
#line 470 "parser.y"
                                                                               {printf("Brackets found\n");}
#line 1916 "parser.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator LPARENTHESES RPARENTHESES  */
#line 471 "parser.y"
                                                                                                {printf("Brackets found\n");}
#line 1922 "parser.tab.c"
    break;

  case 160: /* identifier_list: ID  */
#line 504 "parser.y"
                                        {printf("Identifier in list = %s",(yyvsp[0].str));}
#line 1928 "parser.tab.c"
    break;

  case 172: /* direct_abstract_declarator: LPARENTHESES RPARENTHESES  */
#line 525 "parser.y"
                                                                                                                        {printf("Brackets found\n");}
#line 1934 "parser.tab.c"
    break;

  case 174: /* direct_abstract_declarator: direct_abstract_declarator LPARENTHESES RPARENTHESES  */
#line 527 "parser.y"
                                                                       {printf("Brackets found\n");}
#line 1940 "parser.tab.c"
    break;

  case 212: /* translation_unit: external_declaration  */
#line 601 "parser.y"
                                                        {printf("Reached the root node.\n");}
#line 1946 "parser.tab.c"
    break;


#line 1950 "parser.tab.c"

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

#line 616 "parser.y"


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
