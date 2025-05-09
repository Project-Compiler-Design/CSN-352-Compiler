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


#line 113 "parser.tab.c"

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
  YYSYMBOL_159_1 = 159,                    /* $@1  */
  YYSYMBOL_160_2 = 160,                    /* $@2  */
  YYSYMBOL_161_3 = 161,                    /* $@3  */
  YYSYMBOL_162_4 = 162,                    /* $@4  */
  YYSYMBOL_statement_declaration_list = 163, /* statement_declaration_list  */
  YYSYMBOL_declaration_list = 164,         /* declaration_list  */
  YYSYMBOL_statement_list = 165,           /* statement_list  */
  YYSYMBOL_expression_statement = 166,     /* expression_statement  */
  YYSYMBOL_selection_statement = 167,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 168,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 169,           /* jump_statement  */
  YYSYMBOL_start_symbol = 170,             /* start_symbol  */
  YYSYMBOL_translation_unit = 171,         /* translation_unit  */
  YYSYMBOL_external_declaration = 172,     /* external_declaration  */
  YYSYMBOL_function_definition = 173,      /* function_definition  */
  YYSYMBOL_174_5 = 174                     /* $@5  */
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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2037

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

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
       0,    85,    85,    91,    97,    98,    99,   100,   101,   102,
     114,   136,   141,   142,   146,   151,   179,   183,   217,   259,
     260,   266,   274,   299,   331,   337,   338,   339,   363,   364,
     368,   376,   383,   390,   397,   404,   415,   422,   431,   432,
     442,   450,   464,   465,   473,   484,   485,   496,   510,   511,
     519,   527,   536,   547,   548,   557,   569,   570,   581,   582,
     596,   597,   611,   612,   624,   625,   636,   637,   641,   652,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     768,   772,   780,   785,   789,   790,   851,   852,   853,   854,
     855,   856,   860,   864,   872,   887,   935,   936,   937,   938,
     939,   943,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   957,   969,   970,   987,   988,   992,   993,  1005,
    1025,  1026,  1027,  1028,  1032,  1037,  1045,  1046,  1047,  1051,
    1052,  1057,  1061,  1062,  1066,  1067,  1071,  1072,  1076,  1081,
    1088,  1097,  1101,  1113,  1114,  1135,  1136,  1145,  1146,  1147,
    1148,  1152,  1153,  1158,  1173,  1177,  1184,  1197,  1206,  1213,
    1223,  1224,  1228,  1229,  1233,  1234,  1235,  1239,  1240,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1251,  1256,  1257,  1261,
    1262,  1274,  1279,  1285,  1286,  1287,  1288,  1293,  1301,  1304,
    1305,  1306,  1310,  1312,  1311,  1339,  1339,  1343,  1343,  1347,
    1347,  1353,  1366,  1378,  1389,  1398,  1405,  1411,  1415,  1420,
    1428,  1432,  1433,  1437,  1444,  1452,  1456,  1466,  1476,  1487,
    1505,  1512,  1519,  1526,  1534,  1544,  1550,  1555,  1560,  1564,
    1568,  1572,  1574,  1573,  1627,  1628
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
  "compound_statement", "$@1", "$@2", "$@3", "$@4",
  "statement_declaration_list", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "start_symbol", "translation_unit",
  "external_declaration", "function_definition", "$@5", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-246)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-233)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1645,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,    35,  -246,  -246,  -246,  -246,  -246,
    -246,    30,    -4,  -246,    12,  1989,  1989,  -246,    53,  -246,
    1989,  1693,   -11,     9,    47,  1645,  -246,  -246,    -2,    85,
      22,  -246,  -246,    -4,  -246,   107,  -246,  1561,  -246,  -246,
      43,   642,  -246,    64,    79,  -246,    12,  -246,  1885,  1113,
    1766,   -11,  -246,  -246,    85,    84,   -26,  -246,  -246,  -246,
    -246,    30,  -246,  1149,  1885,   108,   642,   642,   210,  -246,
      58,   642,  -246,  -246,   469,   633,  1850,  1850,    95,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    1433,  -246,   793,  -246,  -246,  -246,  -246,  -246,  -246,  1469,
    1469,  -246,  -246,   547,  -246,  1513,  -246,   -37,   115,    78,
     124,   -24,   104,   127,   116,   111,     6,  -246,   145,  -246,
    -246,    74,   146,   153,  -246,   142,     2,  1513,  -246,    85,
    -246,  1149,   820,  -246,  -246,  -246,  -246,  -246,  1954,  -246,
    -246,  -246,  1513,   122,  -246,   161,  -246,   165,   169,   174,
    1513,   189,   233,  1033,   242,   256,   260,   268,   271,  1193,
    -246,  -246,   158,  -246,  -246,  -246,   276,   305,   387,  -246,
    -246,  -246,  -246,   295,   873,  1920,   551,   793,  -246,   168,
      -6,   302,  1513,  -246,  -246,  1513,  1229,   354,  -246,  -246,
     356,  -246,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,
    1513,  -246,  1273,  1607,  -246,   120,  -246,   178,  -246,   257,
    -246,   357,  -246,  -246,  -246,  -246,    50,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  1513,  -246,
    -246,    58,  -246,  1513,  -246,   713,  -246,   304,  -246,   309,
     339,  1033,  1513,  1309,  1513,  1513,  -246,   177,  1513,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,   953,
     314,  -246,  1728,   209,  -246,  1513,    68,  -246,   211,  -246,
    -246,  -246,  -246,  -246,  -246,   -37,   -37,   115,   115,    78,
      78,    78,    78,   124,   124,   -24,   104,   127,   116,    56,
     111,  -246,   318,  -246,   317,   320,   178,  1353,  1801,  -246,
    -246,  -246,  -246,  1069,  -246,  -246,  -246,  -246,  -246,  1033,
    -246,   322,  -246,   214,  1309,   215,   292,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  1513,  1513,  -246,  -246,  -246,  -246,
     324,  -246,   323,  -246,  -246,  -246,  1513,  1033,  1389,  1033,
    1033,  -246,  -246,  -246,  -246,   293,   365,  1033,   296,  -246,
    -246,   333,  1033,  -246,  1033,  -246,  -246,  -246
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     228,   140,    99,   115,   136,    98,   101,   106,   104,   107,
      97,   103,   105,   102,     0,   100,   108,    96,   116,   109,
     137,     0,   147,   230,     0,    86,    88,   110,     0,   111,
      90,     0,   139,     0,     0,   225,   226,   229,   131,     0,
       0,   151,   149,   148,    84,     0,    92,     0,    87,    89,
     114,     0,    91,     0,   193,   205,     0,   235,     0,     0,
       0,   138,     1,   227,     0,   134,     0,   132,   141,   152,
     150,     0,    85,     0,     0,     0,     0,   121,     0,   117,
       0,   123,   207,   192,     0,     0,     0,     0,    94,   206,
     234,     2,     5,     8,     4,     6,     3,     7,     9,    10,
       0,   143,     0,    32,    33,    31,    30,    35,    34,     0,
       0,    11,    14,    24,    36,     0,    38,    42,    45,    48,
      53,    56,    58,    60,    62,    64,    66,    83,     0,   160,
     146,   159,     0,   153,   155,     0,     0,     0,   129,     0,
      93,     0,    36,    68,   176,    95,   231,   233,     0,   120,
     113,   118,     0,     0,   124,   126,   122,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,    81,     0,   208,   181,   182,     0,     0,     0,   183,
     184,   185,   186,     0,     0,     0,     0,     0,    28,     0,
     162,     0,     0,    25,    26,     0,     0,     0,    20,    21,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,   157,   164,   158,   165,   144,     0,
     145,     0,   130,   135,   133,   179,     0,    70,    74,    75,
      71,    72,    73,    78,    80,    79,    76,    77,     0,   112,
     127,     0,   119,     0,   207,   189,   222,     0,   221,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   212,
     194,   205,   202,   208,   201,   210,   196,   209,   198,     0,
       0,    13,     0,   164,   163,     0,     0,    16,     0,    22,
      18,    19,    39,    40,    41,    43,    44,    46,    47,    49,
      50,    51,    52,    54,    55,    57,    59,    61,    63,     0,
      65,   168,     0,   172,     0,     0,   166,     0,     0,   154,
     156,   161,   177,     0,    69,   125,   128,   188,   187,     0,
     220,     0,   191,     0,     0,     0,     0,   224,    82,   200,
      29,    37,    15,    17,     0,     0,   169,   173,   167,   170,
       0,   174,     0,   178,   180,   190,     0,     0,     0,     0,
       0,    23,    67,   171,   175,     0,   213,     0,     0,   215,
     216,     0,     0,   218,     0,   217,   214,   219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,  -246,  -246,  -246,   -58,  -246,   -98,    59,    73,
       4,    71,   185,   187,   194,   196,   195,  -246,   -57,   -70,
    -246,   -95,  -124,    14,     0,  -246,   366,  -246,    61,  -246,
    -246,   360,   -66,   -62,  -246,   188,  -246,   374,   301,    32,
     -13,   -28,   -16,  -246,   -56,  -246,   212,  -246,   255,  -122,
    -196,  -131,  -246,  -139,  -246,   110,  -246,  -246,  -246,  -246,
     113,   -10,   -69,  -245,  -246,  -246,  -246,  -246,  -246,   408,
    -246,  -246
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   111,   112,   113,   288,   142,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   143,   171,
     248,   172,   128,    55,    56,    45,    46,    25,    26,    27,
      28,    78,    79,    80,   153,   154,    29,    66,    67,    30,
      31,    32,    33,    43,   314,   133,   134,   135,   191,   315,
     227,   145,   236,   173,   174,   175,    84,    85,    86,    87,
     176,   177,   178,   179,   180,   181,   182,    34,    35,    36,
      37,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   114,   127,   144,   132,    61,    42,   189,    40,   226,
     235,    47,   151,   233,    23,   149,   184,   201,   334,   156,
       1,    58,     4,     1,   260,    48,    49,    70,   250,   316,
      52,   138,   202,   203,   204,    24,   257,    74,   139,   273,
     190,     1,   188,    88,    20,   277,    38,    62,    59,    23,
      60,   193,   194,   222,    41,   282,    64,   114,    88,   232,
     131,   213,   214,    22,    50,    22,   139,   155,   284,     1,
      21,   144,    89,    21,   267,    69,   185,   186,    44,   114,
     127,    22,   151,    81,    68,     1,   219,   316,    89,   358,
     220,    21,   189,    39,   114,   127,    65,   189,   312,    22,
     286,    76,   114,   127,   292,   293,   294,   322,    81,    81,
      81,    51,    77,    81,   323,   225,   328,   279,   224,    21,
     268,   345,   332,   152,   309,   190,   289,    22,   342,   326,
      82,     1,   268,   222,    81,   223,    83,    77,    77,    77,
     277,    57,    77,    22,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   137,   114,    77,   114,   127,    54,   333,    90,   335,
     336,    71,    73,    72,   283,   207,   215,   208,   324,   222,
      81,   223,   205,   206,   146,   147,   251,   341,   252,   217,
     355,   271,   354,   350,   218,   114,   127,    61,   338,    89,
      89,   216,   209,   210,   230,   221,   231,   225,   228,    77,
      40,   211,   212,   299,   300,   301,   302,   229,   366,    81,
     369,   370,   268,   131,   269,     3,   253,   114,   373,   131,
     281,   254,   268,   376,   255,   377,     4,   317,   155,   318,
     256,   268,     6,   337,   259,     7,     8,     9,    77,    11,
      12,    13,    14,   144,    16,   258,    18,    19,    20,   114,
     127,   365,   352,   368,   295,   296,   283,   150,   222,   327,
     282,     2,     3,   343,   361,   344,   357,   359,   268,   268,
     297,   298,   131,     4,   303,   304,     5,   114,   362,     6,
     272,   274,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   157,   261,    91,    92,
      93,    94,    95,    96,    97,    98,   158,   262,   131,     2,
       3,   263,   159,   160,   161,   162,   163,   164,   165,   264,
     166,     4,   265,   270,     5,   167,   168,     6,   169,   100,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   360,   371,   268,   268,   374,   319,
     268,   275,  -204,    54,   285,   290,   102,   291,   321,   329,
     331,   170,   103,   104,   105,   330,   340,   106,   346,   347,
     107,   108,   348,   356,   363,   364,   109,   110,   157,   372,
      91,    92,    93,    94,    95,    96,    97,    98,   158,   375,
     305,     2,     3,   306,   159,   160,   161,   162,   163,   164,
     165,   307,   166,     4,   308,   310,     5,   167,   168,     6,
     169,   100,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   148,   140,   136,   325,
     234,   320,   280,    63,  -203,    54,     0,     0,   102,     0,
       0,     0,     0,   170,   103,   104,   105,     0,     0,   106,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     157,     0,    91,    92,    93,    94,    95,    96,    97,    98,
     158,     0,     0,     2,     3,     0,   159,   160,   161,   162,
     163,   164,   165,     0,   166,     4,     0,     0,     5,   167,
     168,     6,   169,   100,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
     102,     0,     0,     0,     0,   170,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   183,     0,    91,    92,    93,    94,    95,    96,
      97,    98,   158,     0,     0,     2,     3,     0,   159,   160,
     161,   162,   163,   164,   165,     0,   166,     4,     0,     0,
       5,   167,   168,     6,   169,   100,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,   195,     0,   196,    54,
     197,     0,   102,     0,     0,     0,     0,   170,   103,   104,
     105,     0,     0,   106,     0,     0,   107,   108,   198,   199,
       0,     0,   109,   110,   183,     0,    91,    92,    93,    94,
      95,    96,    97,    98,   158,     0,     0,     0,   200,     0,
     159,   160,   161,   162,   163,   164,   165,     3,   166,     0,
       0,     0,     0,   167,   168,     0,   169,   100,     4,     0,
       0,     0,     0,     0,     6,     0,     0,     7,     8,     9,
       0,    11,    12,    13,    14,     0,    16,     0,    18,    19,
      20,    54,     0,     0,   102,     0,     0,     0,     0,   170,
     103,   104,   105,     0,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,   158,     0,     0,     2,     3,     0,
     159,   160,   161,   162,   163,   164,   165,     0,   166,     4,
       0,     0,     5,   167,   168,     6,   169,   100,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,   102,     0,     0,     0,     0,   170,
     103,   104,   105,     0,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     6,     0,   100,     7,     8,
       9,     0,    11,    12,    13,    14,     0,    16,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,   158,     0,     0,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   237,   166,     0,
       0,     0,     0,   167,   168,     0,   169,   100,     0,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   246,     0,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,    54,     0,     0,   102,     0,     0,     0,     0,   170,
     103,   104,   105,     0,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,   158,     0,     0,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,     0,   166,     0,
       0,     0,     0,   167,   168,     0,   169,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     339,    54,     0,     0,   102,     0,     0,     0,     0,   170,
     103,   104,   105,     0,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,   158,     0,     0,     0,     0,     0,
     159,   160,   161,   162,   163,   164,   165,     0,   166,     0,
       0,     0,     0,   167,   168,     0,   169,   100,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,   102,     0,     0,     0,     0,   170,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   353,   141,     0,     0,
     102,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,     0,     0,     0,     0,     0,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,   141,     0,     0,
     102,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,     0,     0,   266,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     102,   287,     0,     0,     0,     0,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   311,   102,     0,     0,     0,     0,     0,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,   170,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,   102,     0,     0,     0,     0,     0,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     102,   367,     0,     0,     0,     0,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
     103,   104,   105,   100,     0,   106,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     192,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,   106,     0,     0,   107,   108,     0,   100,     0,     0,
     109,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     2,     3,     0,     0,     0,
     103,   104,   105,     0,     0,   106,     0,     4,   107,   108,
       5,     0,     0,     6,   109,   110,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     1,  -232,
       0,     2,     3,     0,     0,   -94,     0,   -94,     0,     0,
       0,     0,     0,     4,     0,     0,     5,     0,    73,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     1,     0,     0,     2,
       3,     0,     0,     0,     0,     0,   222,     0,   223,   313,
       0,     4,     0,     0,     5,     0,    22,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     2,     3,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     2,     3,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   129,     0,     0,
       2,     3,     0,     0,     0,     0,     0,   222,     0,   282,
     313,     0,     4,     0,     0,     5,     0,    22,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,   130,     0,
       5,     0,     0,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     2,     3,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     4,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     3,
       0,     0,     0,     0,     0,     0,     0,   278,     0,     0,
       4,     0,     0,     0,     0,     0,     6,     0,     0,     7,
       8,     9,     0,    11,    12,    13,    14,     0,    16,     0,
      18,    19,    20,     2,     3,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    59,    59,    73,    60,    33,    22,   102,    21,   131,
     141,    24,    78,   137,     0,    77,    85,   115,   263,    81,
      11,    31,    26,    11,   163,    25,    26,    43,   152,   225,
      30,    57,    69,    70,    71,    35,   160,    47,    64,   178,
     102,    11,   100,    56,    48,   184,    11,     0,    59,    35,
      61,   109,   110,    59,    22,    61,    58,   115,    71,    57,
      60,    85,    86,    69,    11,    69,    64,    80,   190,    11,
      61,   141,    58,    61,   169,    43,    86,    87,    66,   137,
     137,    69,   148,    51,    62,    11,    80,   283,    74,   334,
      84,    61,   187,    58,   152,   152,    11,   192,   222,    69,
     195,    58,   160,   160,   202,   203,   204,    57,    76,    77,
      78,    58,    51,    81,    64,   131,   255,   186,   131,    61,
      64,    65,   261,    65,   219,   187,   196,    69,    60,   253,
      66,    11,    64,    59,   102,    61,    57,    76,    77,    78,
     279,    31,    81,    69,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    77,   220,   102,   222,   222,    58,   262,    58,   264,
     265,    64,    77,    66,   190,    97,    72,    99,   248,    59,
     148,    61,    67,    68,    74,    75,    64,   285,    66,    73,
     329,   177,   323,   317,    83,   253,   253,   225,   268,   185,
     186,    74,    78,    79,    62,    60,    64,   223,    62,   148,
     223,    87,    88,   209,   210,   211,   212,    64,   357,   187,
     359,   360,    64,   223,    66,    15,    65,   285,   367,   229,
      62,    66,    64,   372,    65,   374,    26,    59,   251,    61,
      66,    64,    32,    66,    11,    35,    36,    37,   187,    39,
      40,    41,    42,   323,    44,    66,    46,    47,    48,   317,
     317,   356,   318,   358,   205,   206,   282,    57,    59,   255,
      61,    14,    15,    62,   344,    64,    62,    62,    64,    64,
     207,   208,   282,    26,   213,   214,    29,   345,   345,    32,
     177,   178,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     1,    65,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    61,   318,    14,
      15,    61,    17,    18,    19,    20,    21,    22,    23,    61,
      25,    26,    61,    57,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    62,    62,    64,    64,    62,   102,
      64,    66,    57,    58,    62,    11,    61,    11,    11,    65,
      31,    66,    67,    68,    69,    66,    62,    72,    60,    62,
      75,    76,    62,    61,    60,    62,    81,    82,     1,    24,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    66,
     215,    14,    15,   216,    17,    18,    19,    20,    21,    22,
      23,   217,    25,    26,   218,   220,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    76,    71,    64,   251,
     139,   229,   187,    35,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    82,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      81,    82,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    58,
      63,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    81,    82,
      -1,    -1,    81,    82,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,   101,    -1,
      17,    18,    19,    20,    21,    22,    23,    15,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    26,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      -1,    39,    40,    41,    42,    -1,    44,    -1,    46,    47,
      48,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    77,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    34,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    14,    15,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    26,    75,    76,
      29,    -1,    -1,    32,    81,    82,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    58,
      -1,    14,    15,    -1,    -1,    64,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    77,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,
      -1,    26,    -1,    -1,    29,    -1,    69,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    14,    15,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    11,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    -1,    26,    -1,    -1,    29,    -1,    69,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    62,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    61,    69,   126,   127,   130,   131,   132,   133,   139,
     142,   143,   144,   145,   170,   171,   172,   173,    11,    58,
     143,   142,   145,   146,    66,   128,   129,   143,   127,   127,
      11,    58,   127,     1,    58,   126,   127,   158,   164,    59,
      61,   144,     0,   172,    58,    11,   140,   141,    62,   142,
     145,    64,    66,    77,   164,   174,    58,   131,   134,   135,
     136,   142,    66,    57,   159,   160,   161,   162,   143,   126,
     158,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      34,    60,    61,    67,    68,    69,    72,    75,    76,    81,
      82,   104,   105,   106,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   125,    11,
      62,   127,   147,   148,   149,   150,   140,    77,    57,    64,
     129,    58,   108,   121,   122,   154,   158,   158,   134,   136,
      57,   135,    65,   137,   138,   143,   136,     1,    11,    17,
      18,    19,    20,    21,    22,    23,    25,    30,    31,    33,
      66,   122,   124,   156,   157,   158,   163,   164,   165,   166,
     167,   168,   169,     1,   165,   164,   164,    61,   108,   124,
     136,   151,    61,   108,   108,    59,    61,    63,    81,    82,
     101,   110,    69,    70,    71,    67,    68,    97,    99,    78,
      79,    87,    88,    85,    86,    72,    74,    73,    83,    80,
      84,    60,    59,    61,   143,   145,   152,   153,    62,    64,
      62,    64,    57,   125,   141,   154,   155,    77,    89,    90,
      91,    92,    93,    94,    95,    96,    98,   100,   123,    57,
     125,    64,    66,    65,    66,    65,    66,   125,    66,    11,
     156,    65,    61,    61,    61,    61,    66,   124,    64,    66,
      57,   126,   163,   156,   163,    66,    57,   156,    57,   165,
     151,    62,    61,   145,   152,    62,   124,    62,   107,   122,
      11,    11,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   114,   115,   116,   117,   118,   124,
     119,    60,   125,    62,   147,   152,   153,    59,    61,   102,
     149,    11,    57,    64,   122,   138,   125,   126,   156,    65,
      66,    31,   156,   124,   166,   124,   124,    66,   122,    57,
      62,   110,    60,    62,    64,    65,    60,    62,    62,    60,
     125,    62,   147,    57,   154,   156,    61,    62,   166,    62,
      62,   122,   121,    60,    62,   124,   156,    62,   124,   156,
     156,    62,    24,   156,    62,    66,   156,   156
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
     157,   157,   158,   159,   158,   160,   158,   161,   158,   162,
     158,   163,   163,   163,   163,   164,   164,   164,   165,   165,
     165,   166,   166,   167,   167,   167,   168,   168,   168,   168,
     169,   169,   169,   169,   169,   170,   171,   171,   171,   172,
     172,   173,   174,   173,   173,   173
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
       3,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       4,     3,     2,     0,     4,     0,     4,     0,     4,     0,
       5,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     2,     0,     1,
       1,     4,     0,     4,     3,     2
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
#line 86 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "int", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1913 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 92 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "float", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1923 "parser.tab.c"
    break;

  case 4: /* constant: EXP_LITERAL  */
#line 97 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "exp", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1929 "parser.tab.c"
    break;

  case 5: /* constant: HEXA_LITERAL  */
#line 98 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "hexa", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1935 "parser.tab.c"
    break;

  case 6: /* constant: REAL_LITERAL  */
#line 99 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "real", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1941 "parser.tab.c"
    break;

  case 7: /* constant: STRING_LITERAL  */
#line 100 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "string", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1947 "parser.tab.c"
    break;

  case 8: /* constant: OCTAL_LITERAL  */
#line 101 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "octal", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1953 "parser.tab.c"
    break;

  case 9: /* constant: CHARACTER_LITERAL  */
#line 103 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        string tempp = "'";
        tempp+=(*(char*)((yyvsp[0].symbol_info)->ptr));
        tempp+='\'';
		(yyval.symbol_info)->place=qid(tempp,nullptr);
		(yyval.symbol_info)->code=tempp;
	}
#line 1966 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 115 "src/parser.y"
        {
            cerr<<"ID found: "<<(yyvsp[0].str)<<endl;
            printf("ID %s\n",(yyvsp[0].str));
            symbol_info* new_symbol = new symbol_info((yyvsp[0].str));
            (yyval.symbol_info) = new_symbol;
            printf("ID2 %s\n",(yyval.symbol_info)->name.c_str());
            cerr<<"check"<<endl;
            
			//3AC code
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].str), curr_scope);
			if(find_symbol==nullptr){
				cerr<<"Error: Undeclared variable "<<(yyvsp[0].str)<<endl;
			}
			else{
				(yyval.symbol_info)->place=qid((yyvsp[0].str),find_symbol);
				(yyval.symbol_info)->code="";
				(yyval.symbol_info)->type=find_symbol->type;
				cerr<<"Symbol found "<<(yyval.symbol_info)->place.second->name<<endl;
				cerr<<"Code "<<(yyval.symbol_info)->code<<endl;
			}
        }
#line 1992 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 137 "src/parser.y"
        {
		cerr << "con\n";(yyval.symbol_info) = (yyvsp[0].symbol_info);
		
	}
#line 2001 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 147 "src/parser.y"
        {
            (yyval.symbol_info)=(yyvsp[0].symbol_info);
            cerr << "Primary expression found: " << (yyvsp[0].symbol_info)->type << endl;
        }
#line 2010 "parser.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 152 "src/parser.y"
        {
		string array_name=(yyvsp[-3].symbol_info)->name;
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
                string code=(yyvsp[-1].symbol_info)->code;
                qid temp=newtemp(find_symbol->type,curr_scope);
                code=code+"\n"+temp.first+":= "+"4 * "+(yyvsp[-1].symbol_info)->place.first;
                qid temp2=newtemp(find_symbol->type,curr_scope);
                code=code+"\n"+temp2.first+":= *("+(yyvsp[-3].symbol_info)->place.first+" + "+temp.first+")";
                (yyval.symbol_info)->code=code;
                (yyval.symbol_info)->place.first=temp2.first;
                
                
				
			}
			
		}
		cerr<<"here is array access "<<endl;
	}
#line 2042 "parser.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression LPARENTHESES RPARENTHESES  */
#line 180 "src/parser.y"
        {
		
	}
#line 2050 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 184 "src/parser.y"
            {
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[-3].symbol_info)->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared function "<<(yyvsp[-3].symbol_info)->name<<endl;
				
			}
			else{
				cout<<"Function type "<<find_symbol->type<<endl;
		  		std::vector<std::string> original_list=find_symbol->param_types;
				std::vector<std::string> new_list=(yyvsp[-1].symbol_info)->param_types;
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
			qid temp=newtemp((yyvsp[-3].symbol_info)->type,curr_scope);
			string middle="";
			for(int i=0;i<(yyvsp[-1].symbol_info)->param_list.size();i++){
				middle=middle+"PARAM "+(yyvsp[-1].symbol_info)->param_list[i]+"\n";
			}
			(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code + middle + temp.first+":= CALL "+(yyvsp[-3].symbol_info)->place.first;
			(yyval.symbol_info)->place=temp;
			cerr<<"ppfffix exp"<<(yyval.symbol_info)->code<<endl;
            //printf("Function call= %s\n",$1);
        }
#line 2088 "parser.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DOT ID  */
#line 218 "src/parser.y"
        {
		symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
		if(find_symbol == nullptr) {
			cerr<<"Error: Undeclared variable "<<(yyvsp[-2].symbol_info)->name<<endl;
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
					if(find_struct->param_list[i]==(yyvsp[0].str)){
						cerr<<"Found "<<(yyvsp[0].str)<<" with type "<<find_struct->param_types[i]<<endl;
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
				}
				if(flag==0){
					cerr<<"Error: no such attribute found in struct or union"<<endl;
				}
				else{
					parsing_stack.push((yyvsp[-2].symbol_info)->name);
					parsing_stack.push((yyvsp[0].str));
					parsing_stack.push(var_type);
					find_symbol->name=(yyvsp[-2].symbol_info)->name;
					(yyval.symbol_info)=find_symbol;
				}
				
			}
			else{
				cerr<<"Error: Not a struct or union"<<endl;
			}
			
		}
	}
#line 2134 "parser.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression INCREMENT  */
#line 261 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"+1";
		
	}
#line 2144 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression DECREMENT  */
#line 267 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"-1";
	}
#line 2153 "parser.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 275 "src/parser.y"
      { 
			cout<<"$1 ka name "<<(yyvsp[0].symbol_info)->name<<endl;
		  if((yyvsp[0].symbol_info)->name==""){

			cout<<"is a number "<<(yyvsp[0].symbol_info)->type<<endl;
			(yyval.symbol_info)=(yyvsp[0].symbol_info);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
			(yyval.symbol_info)->param_list.push_back(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)));
		  }
		  else{
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared variable "<<(yyvsp[0].symbol_info)->name<<endl;
			}
			else{
				cout<<"Ass exp "<<find_symbol->type<<endl;
		  		(yyval.symbol_info)=find_symbol;
		  		(yyval.symbol_info)->param_types.push_back(find_symbol->type);
				(yyval.symbol_info)->param_list.push_back(find_symbol->name);
			}
		  }
		  
          
      }
#line 2182 "parser.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 301 "src/parser.y"
       { 
			cout<<"$3 ka name "<<(yyvsp[0].symbol_info)->name<<endl;
		  if((yyvsp[0].symbol_info)->name==""){

			cout<<"is a number "<<(yyvsp[0].symbol_info)->type<<endl;
			(yyval.symbol_info)=(yyvsp[-2].symbol_info);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
			(yyval.symbol_info)->param_list.push_back(std::to_string(*(int*)((yyvsp[-2].symbol_info)->ptr)));
		  }
		  else{
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope);
			if(find_symbol == nullptr) {
				cout<<"Error: Undeclared variable "<<(yyvsp[0].symbol_info)->name<<endl;
				
			}
			else{
				cout<<"Ass exp222 "<<find_symbol->type<<endl;
		  		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		  		(yyval.symbol_info)->param_types.push_back(find_symbol->type);
				(yyval.symbol_info)->param_list.push_back(find_symbol->name);
			}
			
			cout<<"Ass exp111 "<<(yyvsp[-2].symbol_info)->type<<endl;
		  }
			
           
       }
#line 2214 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 332 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		// cerr << "postfix expression found: " << $1->type << endl;
        
	}
#line 2224 "parser.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 339 "src/parser.y"
                                         {
		symbol_info* new_symbol=new symbol_info();
		
		// file<<"cast ka place "<<$2->place.first<<endl;
		string original_type=(yyvsp[0].symbol_info)->type;
		(yyval.symbol_info)=new_symbol;
		if((yyvsp[-1].symbol_info)->code=="&"){
			(yyval.symbol_info)->type=original_type+"*";
			
		}
        if((yyvsp[-1].symbol_info)->code=="*"){
            if(original_type.back()!='*') cerr<<"ERROR!!!!!! star applied to non pointer"<<endl;
            else{
				(yyval.symbol_info)->type=original_type;
				(yyval.symbol_info)->type.pop_back();
			}
        }
		
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place.first=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
		// file<<"cast ka code ffff"<<$$->code<<endl;
		cerr<<"Found unary_operator "<<endl;
	}
#line 2253 "parser.tab.c"
    break;

  case 30: /* unary_operator: AMPERSAND  */
#line 368 "src/parser.y"
                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="ampersand";
		(yyval.symbol_info)->code="&";
        (yyval.symbol_info)->pointer_depth++;
		cerr<<"ampersand "<<endl;
	}
#line 2266 "parser.tab.c"
    break;

  case 31: /* unary_operator: STAR  */
#line 377 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="star";
		(yyval.symbol_info)->code="*";
	}
#line 2277 "parser.tab.c"
    break;

  case 32: /* unary_operator: PLUS  */
#line 384 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="plus";
		(yyval.symbol_info)->code="+";
	}
#line 2288 "parser.tab.c"
    break;

  case 33: /* unary_operator: MINUS  */
#line 391 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="minus";
		(yyval.symbol_info)->code="-";
	}
#line 2299 "parser.tab.c"
    break;

  case 34: /* unary_operator: TILDE  */
#line 398 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="tilde";
		(yyval.symbol_info)->code="~";
	}
#line 2310 "parser.tab.c"
    break;

  case 35: /* unary_operator: EXCLAMATION  */
#line 405 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="exclamation";
		(yyval.symbol_info)->code="!";

	}
#line 2322 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 416 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"found unnnnary expree"<<endl;
		// printf("Unary expression %s\n",$$->name.c_str());
		
	}
#line 2333 "parser.tab.c"
    break;

  case 37: /* cast_expression: LPARENTHESES type_name RPARENTHESES cast_expression  */
#line 423 "src/parser.y"
    {
        cout<<"casting"<<endl;
        (yyval.symbol_info) = (yyvsp[0].symbol_info);
        (yyval.symbol_info)->type = (yyvsp[-2].symbol_info)->type;
    }
#line 2343 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 431 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2349 "parser.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 433 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
		

	}
#line 2363 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 443 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2375 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 451 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: Modulo operator can only be used with int type\n");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"%"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2390 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 464 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2396 "parser.tab.c"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 466 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2408 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 474 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2420 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 484 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2426 "parser.tab.c"
    break;

  case 46: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 486 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: Left shift operator can only be used with int type\n");
        }
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2441 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 497 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: Right shift operator can only be used with int type\n");
        }
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">>"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2456 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 510 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2462 "parser.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 512 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2474 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 520 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];        
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2486 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression LESS_EQUALS shift_expression  */
#line 528 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	
	}
#line 2499 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER_EQUALS shift_expression  */
#line 537 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2511 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 547 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2517 "parser.tab.c"
    break;

  case 54: /* equality_expression: equality_expression REL_EQUALS relational_expression  */
#line 549 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"=="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
		// file<<$$->code<<endl;
	}
#line 2530 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression REL_NOT_EQ relational_expression  */
#line 558 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"!="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2542 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 569 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2548 "parser.tab.c"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 571 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: And operator can only be used with int type\n");
        }
    }
#line 2560 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 581 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2566 "parser.tab.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression XOR and_expression  */
#line 583 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: XOR operator can only be used with int type\n");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"^"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2581 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 596 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2587 "parser.tab.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression OR exclusive_or_expression  */
#line 598 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: OR operator can only be used with int type\n");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"|"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2602 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 611 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2608 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression REL_AND inclusive_or_expression  */
#line 613 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: AND operator can only be used with int type\n");
        }
        
    }
#line 2621 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 624 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2627 "parser.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression REL_OR logical_and_expression  */
#line 626 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: OR operator can only be used with int type\n");
        }
    }
#line 2639 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 636 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2645 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 642 "src/parser.y"
        { 
		cerr<<"condiiiiiii"<<endl;
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		// printf("cond expression = %s\n",$1->type.c_str());
		// printf("cond expression2 = %s\n",$1->name.c_str());
		cerr << "condi expression found: " << (yyvsp[0].symbol_info)->type << endl;
        
	}
#line 2660 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 653 "src/parser.y"
        {
		printf("unary inside assignment = %s\n",(yyvsp[-2].symbol_info)->name.c_str());
		printf("Assignment expression = %s\n",(yyvsp[-2].symbol_info)->type.c_str());
        symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
        if(find_symbol != nullptr) {
			cerr<<"find symbol type: "<<(find_symbol->type).substr(0,6)<<endl;
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				if(parsing_stack.top()==(yyvsp[0].symbol_info)->type){
					//Semantic Analysis
					parsing_stack.pop();
					string attr=parsing_stack.top();
					parsing_stack.pop();
					string struct_inst_name=parsing_stack.top();
					parsing_stack.pop();
					symbol_info* find_struct=lookup_symbol_global(struct_inst_name, curr_scope);
					find_struct->param_list.push_back(attr);
					find_struct->struct_attr_values.push_back((yyvsp[0].symbol_info));
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
                cerr<<(yyvsp[0].symbol_info)->type<<endl;
                if(min(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])==0 && (yyvsp[-2].symbol_info)->type!=(yyvsp[0].symbol_info)->type){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }
                if(type_priority[(yyvsp[-2].symbol_info)->type]<type_priority[(yyvsp[0].symbol_info)->type]){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }else{
                    printf("Correct type assignment\n");
                }
                string third_code=(yyvsp[0].symbol_info)->code;
                string first_code=(yyvsp[-2].symbol_info)->code;
                cerr<<(yyvsp[0].symbol_info)->type<<endl;
                if(min(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[find_symbol->type])>0) find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[(yyvsp[0].symbol_info)->type])];
				
                find_symbol->name=(yyvsp[-2].symbol_info)->name;
                find_symbol->place=(yyvsp[-2].symbol_info)->place;
                find_symbol->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                //file<<find_symbol->code<<endl;
                
                

                //3AC code
                cerr<<"3AC code for assignment"<<endl;
				if((yyvsp[0].symbol_info)->place.first[0]!='t' && (yyvsp[0].symbol_info)->place.first[0]!='&' && (yyvsp[0].symbol_info)->place.first[0]!='*' && (yyvsp[0].symbol_info)->place.first[0]!='+' && (yyvsp[0].symbol_info)->place.first[0]!='-' && (yyvsp[0].symbol_info)->place.first[0]!='~' && (yyvsp[0].symbol_info)->place.first[0]!='!')
				{
					(yyvsp[0].symbol_info)->code="";
				}
				int flag=0;
				if((yyvsp[-2].symbol_info)->place.first[0]=='*'){
					int count_init_starr=count_init_star((yyvsp[-2].symbol_info)->place.first);
					if(count_init_starr>1){
						flag=1;
						string code="";
						qid temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
						string prev=((yyvsp[-2].symbol_info)->place.first).erase(0,count_init_starr);
						for(int i=0;i<count_init_starr;i++){
							code=code+"\n"+temp.first+":= *"+prev;
							prev=temp.first;
							temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
						}
						(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[0].symbol_info)->code+"\n"+code;
						(yyval.symbol_info)->place=temp;
					}
				}
                if(flag==0){
                    if(find_symbol->is_array==true){
                        string code=remove_equal(first_code);

                        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+code+":= "+(yyvsp[0].symbol_info)->place.first;
                    }
                    else{
                         // file<<"find symbol ka codeeee "<<third_code<<endl;
                        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + third_code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                        (yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
                    }
                   
				} 
                // file<<"hiiiiiiiiiiiii "<<$$->code<<endl;
				
			}
			
		}
			
           else{
			printf("Symbol not found\n");
		} 
            
        }
#line 2763 "parser.tab.c"
    break;

  case 70: /* assignment_operator: EQUALS  */
#line 758 "src/parser.y"
                 {(yyval.symbol_info)=new symbol_info("","equals",nullptr,0); (yyval.symbol_info)->code="=";}
#line 2769 "parser.tab.c"
    break;

  case 71: /* assignment_operator: ASSIGN_STAR  */
#line 759 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_star",nullptr,0); (yyval.symbol_info)->code="*=";}
#line 2775 "parser.tab.c"
    break;

  case 72: /* assignment_operator: ASSIGN_DIV  */
#line 760 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_div",nullptr,0); (yyval.symbol_info)->code="/=";}
#line 2781 "parser.tab.c"
    break;

  case 73: /* assignment_operator: ASSIGN_MOD  */
#line 761 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_mod",nullptr,0); (yyval.symbol_info)->code="%=";}
#line 2787 "parser.tab.c"
    break;

  case 74: /* assignment_operator: ASSIGN_PLUS  */
#line 762 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_plus",nullptr,0); (yyval.symbol_info)->code="+=";}
#line 2793 "parser.tab.c"
    break;

  case 75: /* assignment_operator: ASSIGN_MINUS  */
#line 763 "src/parser.y"
                       {(yyval.symbol_info)=new symbol_info("","assign_minus",nullptr,0); (yyval.symbol_info)->code="-=";}
#line 2799 "parser.tab.c"
    break;

  case 76: /* assignment_operator: LEFT_SHIFT_EQ  */
#line 764 "src/parser.y"
                        {(yyval.symbol_info)=new symbol_info("","left_shift_eq",nullptr,0); (yyval.symbol_info)->code="<<=";}
#line 2805 "parser.tab.c"
    break;

  case 77: /* assignment_operator: RIGHT_SHIFT_EQ  */
#line 765 "src/parser.y"
                         {(yyval.symbol_info)=new symbol_info("","right_shift_eq",nullptr,0); (yyval.symbol_info)->code=">>=";}
#line 2811 "parser.tab.c"
    break;

  case 78: /* assignment_operator: ASSIGN_AND  */
#line 766 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_and",nullptr,0); (yyval.symbol_info)->code="&=";}
#line 2817 "parser.tab.c"
    break;

  case 79: /* assignment_operator: ASSIGN_XOR  */
#line 767 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_xor",nullptr,0); (yyval.symbol_info)->code="^=";}
#line 2823 "parser.tab.c"
    break;

  case 80: /* assignment_operator: ASSIGN_OR  */
#line 768 "src/parser.y"
                    {(yyval.symbol_info)=new symbol_info("","assign_or",nullptr,0); (yyval.symbol_info)->code="|=";}
#line 2829 "parser.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 773 "src/parser.y"
        {
        cerr<<"IDHAR HU MAIIII2"<<endl;
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
        // file<<"Assignment expression = "<<$1->code<<endl;
		// cout<<"Assignment expression = "<<$1->code<<endl;
		// file<<$1->code<<endl;
	}
#line 2841 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 791 "src/parser.y"
    {
		cerr<<"hi"<<endl;
		cerr<<"parsing stack top = "<<parsing_stack.top().c_str()<<endl;
		cerr<<"Declaration specifiers = "<<(yyvsp[-2].str)<<endl;
		cerr<<"Init declarator list = "<<(yyvsp[-1].symbol_info)->name.c_str()<<endl;
		cerr<<"dollar 3 type = "<<(yyvsp[-1].symbol_info)->type<<endl;
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

				if (type_priority[(yyvsp[-2].str)] < type_priority[curr_scope->symbol_map[top_symbol]->type]) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
				// file<<"decl ka code "<<$2->code<<endl;
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                if(type_priority[(yyvsp[-2].str)]>0 && type_priority[curr_scope->symbol_map[top_symbol]->type]>0) curr_scope->symbol_map[top_symbol]->type = priority_to_type[max(type_priority[(yyvsp[-2].str)], type_priority[curr_scope->symbol_map[top_symbol]->type])];
                else{
                    cout<<"ERROR!!!!!!: Type mismatch in declaration\n";
                }
				(yyval.symbol_info)->code = (yyvsp[-1].symbol_info)->code;

			} else {
				// Create new symbol_info and assign type = $1
				curr_scope->symbol_map[top_symbol]->type = (yyvsp[-2].str);
                for(int i=0;i<depth;i++){
                    curr_scope->symbol_map[top_symbol]->type+="*";
                }
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                curr_scope->symbol_map[top_symbol]->pointer_depth = depth;
				cerr<<"Created new symbol: "<<top_symbol.c_str()<<" with type "<<((yyvsp[-2].str))<<endl;
				symbol_info* new_symbol = new symbol_info();
				new_symbol = (yyvsp[-1].symbol_info);
				(yyval.symbol_info)=new_symbol;
			}
		}
		
		// $$->code = $2->code;
		if(flag==0) printf("Correct type declaration\n");
		
		
    }
#line 2902 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 853 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 2908 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 860 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
		cerr<<("init_d %s\n",(yyval.symbol_info)->name.c_str())<<endl;  
    }
#line 2917 "parser.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 864 "src/parser.y"
                                                 { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->code = (yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		printf("init_D %s\n",(yyval.symbol_info)->name.c_str()); 
    }
#line 2927 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator  */
#line 872 "src/parser.y"
                 { 
		cerr<<("declarator11 %s\n",(yyvsp[0].symbol_info)->name.c_str())<<endl;
		if(lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope)!=nullptr){
			printf("Redeclaration error \n"); 
			exit(1);
		}
        cerr<<"hiiii"<<endl;
        symbol_info* new_symbol = new symbol_info();
        new_symbol=(yyvsp[0].symbol_info);
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]=new_symbol;
        (yyval.symbol_info) =new_symbol;
		cerr<<"declarator "<<(yyval.symbol_info)->name.c_str()<<endl; 
		parsing_stack.push((yyvsp[0].symbol_info)->name.c_str());
        pointer_info.push((yyvsp[0].symbol_info)->pointer_depth);
    }
#line 2947 "parser.tab.c"
    break;

  case 95: /* init_declarator: declarator EQUALS initializer  */
#line 887 "src/parser.y"
                                    { 
		printf("declaratoreiii %s\n",(yyvsp[-2].symbol_info)->name.c_str());
		if(lookup_symbol_local((yyvsp[-2].symbol_info)->name, curr_scope)!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=(yyvsp[0].symbol_info);
		if((yyvsp[0].symbol_info)->type=="float") printf("Yes float found\n");
		if((yyvsp[0].symbol_info)->type=="int") printf("Yes int found\n");
		if((yyvsp[0].symbol_info)->type=="char") printf("Yes char found %s\n",(yyvsp[0].symbol_info)->str_val.c_str());
		parsing_stack.push((yyvsp[-2].symbol_info)->name.c_str());
        pointer_info.push((yyvsp[-2].symbol_info)->pointer_depth);
		if((yyvsp[-2].symbol_info)->is_array){
			if((yyvsp[0].symbol_info)->int_array.size() > (yyvsp[-2].symbol_info)->array_length){
				printf("Error: Elements Greater than Declared\n");
			}
			else{
				(yyvsp[-2].symbol_info)->int_array = (yyvsp[0].symbol_info)->int_array;
				(yyvsp[-2].symbol_info)->type = (yyvsp[0].symbol_info)->type;
				curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]->is_array=true;
				string code=(yyvsp[-2].symbol_info)->name+":= alloc " +to_string(4*(yyvsp[-2].symbol_info)->array_length);
				for(int i=0;i<(yyvsp[-2].symbol_info)->array_length;i++){
					qid temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
					code=code+"\n"+temp.first+":= "+to_string(i)+"*4";
					code=code+"\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+to_string(*(int*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
				}
				// file<<code<<endl;
				(yyval.symbol_info)->code=code;
			}
		}
        if((yyvsp[-2].symbol_info)->is_array==false){
			(yyval.symbol_info) = (yyvsp[-2].symbol_info);
		if((yyvsp[0].symbol_info)->place.first[0]!='t' && (yyvsp[0].symbol_info)->place.first[0]!='&' && (yyvsp[0].symbol_info)->place.first[0]!='*' && (yyvsp[0].symbol_info)->place.first[0]!='-' && (yyvsp[0].symbol_info)->place.first[0]!='!'){
			(yyvsp[0].symbol_info)->code="";
		}
		
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+(yyvsp[-2].symbol_info)->place.first+":= "+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
		
		printf("declarator equals initializer %s\n",(yyval.symbol_info)->name.c_str()); 
		}
		
		
    }
#line 2997 "parser.tab.c"
    break;

  case 101: /* type_specifier: VOID  */
#line 943 "src/parser.y"
                                        {(yyval.str)=strdup("void");}
#line 3003 "parser.tab.c"
    break;

  case 102: /* type_specifier: CHAR  */
#line 944 "src/parser.y"
                                        {(yyval.str)=strdup("char");}
#line 3009 "parser.tab.c"
    break;

  case 103: /* type_specifier: SHORT  */
#line 945 "src/parser.y"
                                        {(yyval.str)=strdup("short");}
#line 3015 "parser.tab.c"
    break;

  case 104: /* type_specifier: INT  */
#line 946 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 3021 "parser.tab.c"
    break;

  case 105: /* type_specifier: LONG  */
#line 947 "src/parser.y"
                                        {(yyval.str)=strdup("long");}
#line 3027 "parser.tab.c"
    break;

  case 106: /* type_specifier: FLOAT  */
#line 948 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 3033 "parser.tab.c"
    break;

  case 107: /* type_specifier: DOUBLE  */
#line 949 "src/parser.y"
                                        {(yyval.str)=strdup("double");}
#line 3039 "parser.tab.c"
    break;

  case 108: /* type_specifier: SIGNED  */
#line 950 "src/parser.y"
                                        {(yyval.str)=strdup("signed");}
#line 3045 "parser.tab.c"
    break;

  case 109: /* type_specifier: UNSIGNED  */
#line 951 "src/parser.y"
                                        {(yyval.str)=strdup("unsigned");}
#line 3051 "parser.tab.c"
    break;

  case 110: /* type_specifier: struct_or_union_specifier  */
#line 952 "src/parser.y"
                                    {(yyval.str)=(yyvsp[0].str);}
#line 3057 "parser.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 958 "src/parser.y"
        {
		
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type = (yyvsp[-4].str);
		new_symbol->param_list = (yyvsp[-1].symbol_info)->param_list;
		new_symbol->param_types = (yyvsp[-1].symbol_info)->param_types;
		curr_scope->symbol_map[(yyvsp[-3].str)]=new_symbol;
		for(int i=0;i<curr_scope->symbol_map[(yyvsp[-3].str)]->param_list.size();i++){
			printf("Struct or union declaration %s = %s\n",curr_scope->symbol_map[(yyvsp[-3].str)]->param_types[i].c_str(),curr_scope->symbol_map[(yyvsp[-3].str)]->param_list[i].c_str());
		}
	}
#line 3073 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID  */
#line 971 "src/parser.y"
        {
		symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].str), curr_scope);
		if (find_symbol != nullptr) {
			if (find_symbol->type == "struct" || find_symbol->type == "union") {
				std::string temp = std::string((yyvsp[-1].str)) + " " + std::string((yyvsp[0].str));
				(yyval.str) = strdup(temp.c_str());  // strdup allocates new memory for the concatenated string
			} else {
				std::cerr << "Error: Variable not of type struct or union" << std::endl;
			}
		} else {
			std::cerr << "Error: Struct or Union not declared" << std::endl;
		}
	}
#line 3091 "parser.tab.c"
    break;

  case 115: /* struct_or_union: STRUCT  */
#line 987 "src/parser.y"
                 {(yyval.str)=strdup("struct");}
#line 3097 "parser.tab.c"
    break;

  case 116: /* struct_or_union: UNION  */
#line 988 "src/parser.y"
                {(yyval.str)=strdup("union");}
#line 3103 "parser.tab.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration  */
#line 992 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3109 "parser.tab.c"
    break;

  case 118: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 994 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(int i=0;i<(yyvsp[0].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->param_list[i]);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->param_types[i]);
		}
		
	}
#line 3122 "parser.tab.c"
    break;

  case 119: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 1006 "src/parser.y"
        { 
		//printf("Struct declaration %s = %s\n",$1,$2);
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(auto it: (yyvsp[-1].symbol_info)->param_list)
					{
						cerr<<it<<endl;
						symbol_info* x=new symbol_info();
						x->type = (yyvsp[-2].str);
						
						curr_scope->symbol_map[it]=x;
						(yyval.symbol_info)->param_types.push_back((yyvsp[-2].str));
					}
		
		

	}
#line 3143 "parser.tab.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator  */
#line 1033 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3152 "parser.tab.c"
    break;

  case 125: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 1038 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3161 "parser.tab.c"
    break;

  case 126: /* struct_declarator: declarator  */
#line 1045 "src/parser.y"
                         {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3167 "parser.tab.c"
    break;

  case 130: /* enum_specifier: ENUM ID LBRACE enumerator_list RBRACE  */
#line 1053 "src/parser.y"
        {
		
		//printf("enum is here = %s\n",$$);
	}
#line 3176 "parser.tab.c"
    break;

  case 138: /* declarator: pointer direct_declarator  */
#line 1076 "src/parser.y"
                                { 
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
        (yyval.symbol_info)->pointer_depth=(yyvsp[-1].symbol_info)->pointer_depth;
		cerr<<"Pointer direct declarator with depth "<<(yyval.symbol_info)->pointer_depth<<endl;
    }
#line 3186 "parser.tab.c"
    break;

  case 139: /* declarator: direct_declarator  */
#line 1081 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info); 
		printf("Direct declarator %s\n",(yyval.symbol_info)->name.c_str());
    }
#line 3195 "parser.tab.c"
    break;

  case 140: /* direct_declarator: ID  */
#line 1089 "src/parser.y"
        {
		printf("%s\n",(yyvsp[0].str));
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);
		x->place.first=(yyvsp[0].str);
		(yyval.symbol_info)=x;
		printf("ID %s\n",(yyval.symbol_info)->name.c_str());
	}
#line 3208 "parser.tab.c"
    break;

  case 141: /* direct_declarator: LPARENTHESES declarator RPARENTHESES  */
#line 1098 "src/parser.y"
        { 
		//printf("LPar declarator RPar= %s\n",$2);
	}
#line 3216 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LBRACKET constant_expression RBRACKET  */
#line 1102 "src/parser.y"
    {
        (yyval.symbol_info)->is_array = true;
        if((yyvsp[-1].symbol_info)->type=="int"){
            (yyval.symbol_info)->array_length = *(int*)((yyvsp[-1].symbol_info)->ptr);
            printf("Array length = %d\n",(yyval.symbol_info)->array_length);
        }
        else{
            printf("Error: Array size not an integer\n");
            (yyval.symbol_info)->array_length=100;
        }
    }
#line 3232 "parser.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 1113 "src/parser.y"
                                                                                                        {printf("Array Size not declared\n"), (yyval.symbol_info)->is_array = true, (yyval.symbol_info)->array_length = 100;}
#line 3238 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LPARENTHESES parameter_type_list RPARENTHESES  */
#line 1115 "src/parser.y"
        {
		printf("Brackets found with parameter= %s\n",(yyvsp[-3].symbol_info)->name.c_str());
		printf("Par list %d\n",(yyvsp[-1].symbol_info)->parameter_no);
		cerr<<"param list size "<<(yyvsp[-1].symbol_info)->param_list.size()<<endl;
		for(auto it: (yyvsp[-1].symbol_info)->param_types)
					{
						cout<<it<<endl;
					}
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type=(yyvsp[-3].symbol_info)->type;
		new_symbol->parameter_no=(yyvsp[-1].symbol_info)->parameter_no;
		new_symbol->param_types=(yyvsp[-1].symbol_info)->param_types;
		new_symbol->param_list=(yyvsp[-1].symbol_info)->param_list;
		new_symbol->is_param_list=(yyvsp[-1].symbol_info)->is_param_list;
		new_symbol->name=(yyvsp[-3].symbol_info)->name;
		curr_scope->symbol_map[(yyvsp[-3].symbol_info)->name]=new_symbol;

		(yyval.symbol_info)=new_symbol;
		cerr<<"has a parameter or not "<<(yyval.symbol_info)->param_list.size()<<endl;
	}
#line 3263 "parser.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator LPARENTHESES RPARENTHESES  */
#line 1137 "src/parser.y"
        {
		(yyval.symbol_info)->is_param_list=false;
		cerr<<"It is function without params "<<endl;
		cerr<<"has a parameter or not "<<(yyval.symbol_info)->is_param_list<<endl;
	}
#line 3273 "parser.tab.c"
    break;

  case 147: /* pointer: STAR  */
#line 1145 "src/parser.y"
               {(yyval.symbol_info)=new symbol_info(); (yyval.symbol_info)->pointer_depth=1;}
#line 3279 "parser.tab.c"
    break;

  case 149: /* pointer: STAR pointer  */
#line 1147 "src/parser.y"
                       {(yyval.symbol_info)=(yyvsp[0].symbol_info); (yyval.symbol_info)->pointer_depth++;}
#line 3285 "parser.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 1158 "src/parser.y"
                        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)->parameter_no=(yyvsp[0].symbol_info)->parameter_no;
		(yyval.symbol_info)->is_param_list=(yyvsp[0].symbol_info)->is_param_list;
		(yyval.symbol_info)->param_types=(yyvsp[0].symbol_info)->param_types;
		(yyval.symbol_info)->param_list=(yyvsp[0].symbol_info)->param_list;
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		for(auto it: (yyvsp[0].symbol_info)->param_types)
					{
						cout<<it<<endl;
					}
		cout<<"par num"<<(yyval.symbol_info)->parameter_no<<endl;
		
				}
#line 3304 "parser.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 1178 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=1;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3315 "parser.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1185 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        cout<<"par num $1 "<<(yyvsp[-2].symbol_info)->parameter_no<<endl;
        cout<<"par num $3 "<<(yyvsp[0].symbol_info)->parameter_no<<endl;
        (yyval.symbol_info)->parameter_no=(yyvsp[-2].symbol_info)->parameter_no+(yyvsp[0].symbol_info)->parameter_no;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3328 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 1198 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->parameter_no=1;
		// printf("%s",$$->type);
	}
#line 3341 "parser.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1206 "src/parser.y"
                                                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		// printf("%s",$$->type);
	}
#line 3353 "parser.tab.c"
    break;

  case 159: /* parameter_declaration: declaration_specifiers  */
#line 1213 "src/parser.y"
                                {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[0].str);
		(yyval.symbol_info)->name="";
		// printf("%s",$$->type);
	}
#line 3365 "parser.tab.c"
    break;

  case 176: /* initializer: assignment_expression  */
#line 1251 "src/parser.y"
                                {
        cerr<<"IDHAR HU MAIIII"<<endl;
		(yyvsp[0].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3375 "parser.tab.c"
    break;

  case 177: /* initializer: LBRACE initializer_list RBRACE  */
#line 1256 "src/parser.y"
                                         {(yyval.symbol_info) = (yyvsp[-1].symbol_info);}
#line 3381 "parser.tab.c"
    break;

  case 178: /* initializer: LBRACE initializer_list COMMA RBRACE  */
#line 1257 "src/parser.y"
                                               {(yyval.symbol_info) = (yyvsp[-2].symbol_info);}
#line 3387 "parser.tab.c"
    break;

  case 179: /* initializer_list: initializer  */
#line 1261 "src/parser.y"
                      {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 3393 "parser.tab.c"
    break;

  case 180: /* initializer_list: initializer_list COMMA initializer  */
#line 1262 "src/parser.y"
                                             {
		if((yyvsp[-2].symbol_info)->type != (yyvsp[0].symbol_info)->type){
			printf("Error: Type mismatch in initializer list\n");
		}
		else{
			(yyvsp[-2].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		}
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
	}
#line 3407 "parser.tab.c"
    break;

  case 181: /* statement: labeled_statement  */
#line 1275 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);cerr<<"label\n";

	}
#line 3416 "parser.tab.c"
    break;

  case 182: /* statement: compound_statement  */
#line 1280 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);

		//file<<$$->code<<endl;
	}
#line 3426 "parser.tab.c"
    break;

  case 184: /* statement: selection_statement  */
#line 1286 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3432 "parser.tab.c"
    break;

  case 185: /* statement: iteration_statement  */
#line 1287 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3438 "parser.tab.c"
    break;

  case 186: /* statement: jump_statement  */
#line 1288 "src/parser.y"
                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);
	cout<<(yyval.symbol_info)->is_break<<"break check in statement"<<endl;}
#line 3445 "parser.tab.c"
    break;

  case 187: /* labeled_statement: ID COLON statement  */
#line 1294 "src/parser.y"
        {

		// curr-scope->symbol_map[$1]=new symbol_info();
		// curr_scope->symbol_map[$1]->name=$1;
		// curr_scope->symbol_map[$1]->type="label";
		cerr<<"ID COLON statement"<<(yyvsp[-2].str)<<endl;
	}
#line 3457 "parser.tab.c"
    break;

  case 188: /* labeled_statement: ID COLON declaration  */
#line 1301 "src/parser.y"
                              {
		cerr<<"ID COLON declaration"<<(yyvsp[-2].str)<<endl;
	}
#line 3465 "parser.tab.c"
    break;

  case 193: /* $@1: %empty  */
#line 1312 "src/parser.y"
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
#line 3483 "parser.tab.c"
    break;

  case 194: /* compound_statement: LBRACE $@1 statement_declaration_list RBRACE  */
#line 1327 "src/parser.y"
        {
		cerr<<"inside compound sttttttttttttt"<<endl;
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[-1].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
        
		//file<<$$->code<<endl; 
	}
#line 3500 "parser.tab.c"
    break;

  case 195: /* $@2: %empty  */
#line 1339 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3506 "parser.tab.c"
    break;

  case 196: /* compound_statement: LBRACE $@2 statement_list RBRACE  */
#line 1339 "src/parser.y"
                                                                                     {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3515 "parser.tab.c"
    break;

  case 197: /* $@3: %empty  */
#line 1343 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3521 "parser.tab.c"
    break;

  case 198: /* compound_statement: LBRACE $@3 declaration_list RBRACE  */
#line 1343 "src/parser.y"
                                                                                       {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3530 "parser.tab.c"
    break;

  case 199: /* $@4: %empty  */
#line 1347 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3536 "parser.tab.c"
    break;

  case 200: /* compound_statement: LBRACE $@4 declaration_list statement_list RBRACE  */
#line 1347 "src/parser.y"
                                                                                                      {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3544 "parser.tab.c"
    break;

  case 201: /* statement_declaration_list: statement_list statement_declaration_list  */
#line 1354 "src/parser.y"
        {
        cerr<<"statement lis222222 found"<<endl;
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		if((yyvsp[-1].symbol_info)->return_type!="") (yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		else (yyval.symbol_info)->return_type=(yyvsp[0].symbol_info)->return_type;
		
        

	}
#line 3561 "parser.tab.c"
    break;

  case 202: /* statement_declaration_list: declaration_list statement_declaration_list  */
#line 1367 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
        cerr<<"statement list11111 found"<<endl;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[0].symbol_info)->return_type;
		
        
		
	}
#line 3577 "parser.tab.c"
    break;

  case 203: /* statement_declaration_list: statement_list  */
#line 1378 "src/parser.y"
                        {
		
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[0].symbol_info)->return_type;
		cerr<<"statement list found"<<(yyval.symbol_info)->code<<endl;
		
		
	}
#line 3593 "parser.tab.c"
    break;

  case 204: /* statement_declaration_list: declaration_list  */
#line 1390 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"Hello?\n";
		//file<<$$->code<<endl;
	}
#line 3603 "parser.tab.c"
    break;

  case 205: /* declaration_list: declaration  */
#line 1399 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		//file<<$$->code<<endl;
	}
#line 3614 "parser.tab.c"
    break;

  case 206: /* declaration_list: declaration_list declaration  */
#line 1406 "src/parser.y"
        {
		cout<<"Maaaai yaha honnnn"<<endl;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		//file<<$$->code<<endl;
	}
#line 3624 "parser.tab.c"
    break;

  case 207: /* declaration_list: error SEMICOLON  */
#line 1411 "src/parser.y"
                          {yyerrok;}
#line 3630 "parser.tab.c"
    break;

  case 208: /* statement_list: statement  */
#line 1415 "src/parser.y"
                    { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"statement list\n";

	}
#line 3640 "parser.tab.c"
    break;

  case 209: /* statement_list: statement_list statement  */
#line 1421 "src/parser.y"
        {
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		if((yyvsp[-1].symbol_info)->return_type!="") (yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		else (yyval.symbol_info)->return_type=(yyvsp[0].symbol_info)->return_type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		
	}
#line 3652 "parser.tab.c"
    break;

  case 210: /* statement_list: error SEMICOLON  */
#line 1428 "src/parser.y"
                          {yyerrok;}
#line 3658 "parser.tab.c"
    break;

  case 213: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement  */
#line 1438 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+"if("+ (yyvsp[-2].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+falselabel+":\n";
		//file<<$$->code<<endl;
	}
#line 3669 "parser.tab.c"
    break;

  case 214: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement ELSE statement  */
#line 1445 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+"if("+ (yyvsp[-4].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
		//file<<$$->code<<endl;
	}
#line 3681 "parser.tab.c"
    break;

  case 216: /* iteration_statement: WHILE LPARENTHESES expression RPARENTHESES statement  */
#line 1457 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3695 "parser.tab.c"
    break;

  case 217: /* iteration_statement: DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON  */
#line 1467 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-5].symbol_info)->code+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3709 "parser.tab.c"
    break;

  case 218: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement  */
#line 1477 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
		// file<<$$->code<<endl;
	}
#line 3724 "parser.tab.c"
    break;

  case 219: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement  */
#line 1488 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		string updatelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-3].symbol_info)->code+"\n"+"if("+(yyvsp[-3].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+updatelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";

			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,updatelabel,0);
		
		// file<<$$->code<<endl;
		}
#line 3743 "parser.tab.c"
    break;

  case 220: /* jump_statement: GOTO ID SEMICOLON  */
#line 1506 "src/parser.y"
        { 
		//printf("Goto statement: %s\n",$2);
		//idhar ID ko symtab me insert karna he
		goto_list.push_back((yyvsp[-1].str));
		cerr << "goto\n";
	}
#line 3754 "parser.tab.c"
    break;

  case 221: /* jump_statement: CONTINUE SEMICOLON  */
#line 1513 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_continue=true;
		(yyval.symbol_info)->code="\n continue \n";
	}
#line 3765 "parser.tab.c"
    break;

  case 222: /* jump_statement: BREAK SEMICOLON  */
#line 1520 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_break=true;
		(yyval.symbol_info)->code="\n break \n";
	}
#line 3776 "parser.tab.c"
    break;

  case 223: /* jump_statement: RETURN SEMICOLON  */
#line 1527 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type="void";
		(yyval.symbol_info)->code="\nRETURN\n";
	}
#line 3788 "parser.tab.c"
    break;

  case 224: /* jump_statement: RETURN expression SEMICOLON  */
#line 1535 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\nRETURN "+(yyvsp[-1].symbol_info)->place.first+"\n";
	}
#line 3800 "parser.tab.c"
    break;

  case 225: /* start_symbol: translation_unit  */
#line 1545 "src/parser.y"
{
	file<<(yyvsp[0].symbol_info)->code<<endl;
}
#line 3808 "parser.tab.c"
    break;

  case 226: /* translation_unit: external_declaration  */
#line 1551 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		// file<<$$->code<<endl;
	}
#line 3817 "parser.tab.c"
    break;

  case 227: /* translation_unit: translation_unit external_declaration  */
#line 1556 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->code;
		// file<<$$->code<<endl;
	}
#line 3826 "parser.tab.c"
    break;

  case 229: /* external_declaration: function_definition  */
#line 1565 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3834 "parser.tab.c"
    break;

  case 232: /* $@5: %empty  */
#line 1574 "src/parser.y"
        {
		var_name=(yyvsp[0].symbol_info)->param_list;
		type_list=(yyvsp[0].symbol_info)->param_types;
	}
#line 3843 "parser.tab.c"
    break;

  case 233: /* function_definition: declaration_specifiers declarator $@5 compound_statement  */
#line 1579 "src/parser.y"
        {
		cerr<<"function definition ke right "<<(yyvsp[-2].symbol_info)->is_param_list<<endl;
		// for(auto it:$2->param_list){
		// 	cerr<<it<<endl;
		// }
		// cerr<<"function def endddd"<<endl;
		//abhi ke liye
		// cerr<<"decl spee "<<$1<<endl;
		
		// cerr<<"decl spee "<<$1<<"mmmm"<<endl;
        if(strcmp((yyvsp[-3].str),"void")==0){
		
			if((yyvsp[0].symbol_info)->return_type=="void"){
				cerr<<"Return type matched"<<endl;
			}
			else{
				cerr<<"Error: Return type not matched"<<endl;
			}
		}
		else{
			cerr<<"hellllo"<<endl;
			if((yyvsp[0].symbol_info)->is_return==0){
				cerr<<"Error: Missing return statement"<<endl;
			}
			else{
				if((yyvsp[0].symbol_info)->return_type!=(yyvsp[-3].str)){
					cerr<<"Error: Return type not matching"<<endl;
				}
				else{
					cerr<<"Return type matched"<<endl;
				}
			}
		}
		cout<<"ffffnnnnname"<<(yyvsp[-2].symbol_info)->name<<"fffffnnnnnn"<<endl;
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code="FUNC_BEGIN "+(yyvsp[-2].symbol_info)->name+"\n";
		for(int i=0;i<(yyvsp[-2].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->code=(yyval.symbol_info)->code+"param"+std::to_string(i)+" := PARAM\n";
		}
		for(int i=0;i<(yyvsp[-2].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->code=(yyval.symbol_info)->code+(yyvsp[-2].symbol_info)->param_list[i]+" := param"+std::to_string(i)+"\n";
		}
		(yyval.symbol_info)->code=(yyval.symbol_info)->code+(yyvsp[0].symbol_info)->code+"FUNC_END "+(yyvsp[-2].symbol_info)->name+"\n";


		// file<<$$->code<<endl;
	}
#line 3896 "parser.tab.c"
    break;


#line 3900 "parser.tab.c"

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

#line 1630 "src/parser.y"


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
