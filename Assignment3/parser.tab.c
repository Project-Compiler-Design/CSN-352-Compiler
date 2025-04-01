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

    scoped_symtab* curr_scope = new scoped_symtab();
    vector<scoped_symtab*> all_scopes={curr_scope};
	
	std::ofstream file("output.txt");

    
    


	struct ArgList {
        char *args[MAX_ARGS];
        int count_arg;
    } argList;


#line 110 "parser.tab.c"

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
  YYSYMBOL_translation_unit = 170,         /* translation_unit  */
  YYSYMBOL_external_declaration = 171,     /* external_declaration  */
  YYSYMBOL_function_definition = 172       /* function_definition  */
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
#define YYLAST   2150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  376

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
       0,    82,    82,    88,    94,    95,    96,    97,    98,    99,
     111,   132,   137,   138,   142,   147,   148,   149,   176,   218,
     219,   220,   224,   247,   277,   282,   283,   284,   285,   286,
     290,   291,   292,   293,   294,   295,   299,   304,   313,   314,
     324,   332,   346,   347,   355,   366,   367,   378,   392,   393,
     401,   409,   418,   429,   430,   439,   451,   452,   463,   464,
     478,   479,   493,   494,   506,   507,   518,   519,   523,   532,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   615,   621,   626,   630,   631,   680,   681,   682,   683,
     684,   685,   689,   693,   701,   716,   752,   753,   754,   755,
     756,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   774,   786,   787,   804,   805,   809,   810,   822,
     842,   843,   844,   845,   849,   854,   862,   863,   864,   868,
     869,   874,   878,   879,   883,   884,   888,   889,   893,   896,
     903,   912,   916,   925,   926,   936,   937,   941,   942,   943,
     944,   948,   949,   954,   963,   967,   971,   982,   990,   996,
    1005,  1006,  1010,  1011,  1015,  1016,  1017,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1033,  1037,  1038,  1042,
    1043,  1055,  1056,  1062,  1063,  1064,  1065,  1069,  1070,  1071,
    1072,  1073,  1077,  1078,  1078,  1085,  1085,  1089,  1089,  1093,
    1093,  1099,  1104,  1110,  1115,  1124,  1129,  1135,  1139,  1143,
    1148,  1152,  1153,  1157,  1164,  1172,  1176,  1177,  1178,  1179,
    1183,  1188,  1189,  1190,  1191,  1195,  1200,  1201,  1205,  1210,
    1214,  1215,  1223,  1224
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
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-247)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-205)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1739,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,    33,  -247,  -247,  -247,  -247,  -247,
    -247,    21,    20,  -247,     6,  2102,  2102,  -247,    51,  -247,
    2102,  1787,   110,    12,  1663,  -247,  -247,   -36,    17,   -29,
    -247,  -247,    20,  -247,   108,  -247,  1609,  -247,  -247,   -22,
     690,  -247,   -19,    -7,  -247,     6,  -247,  1979,  1161,  1860,
     110,  -247,  -247,    17,   -11,     1,  -247,  -247,  -247,  -247,
      21,  -247,  1197,  -247,  1979,   690,   690,  2048,  -247,     9,
     690,  -247,  -247,   517,   681,  1944,  1944,    11,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  1481,
    -247,   841,  -247,  -247,  -247,  -247,  -247,  -247,  1517,  1517,
    -247,  -247,    59,  -247,  1561,  -247,    63,   183,    76,    50,
     168,   -17,   -13,     4,    24,   -31,  -247,    32,  -247,  -247,
      58,    22,    75,  -247,   121,    66,  1561,  -247,    17,  -247,
    1197,   868,  -247,  -247,  -247,  -247,  2067,  -247,  -247,  -247,
    1561,   120,  -247,    77,  -247,    49,    97,    60,  1561,   123,
     187,  1081,   136,   155,   158,   163,   205,  1241,  -247,  -247,
     142,  -247,  -247,  -247,   175,   353,   435,  -247,  -247,  -247,
    -247,   211,   921,  2014,   599,   841,  -247,   145,   -21,   186,
    1561,  -247,  -247,  1561,  1277,   260,  -247,  -247,   267,  -247,
    1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,
    1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,  -247,
    1321,  1701,  -247,    45,  -247,   151,  -247,   305,  -247,   268,
    -247,  -247,  -247,  -247,    67,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  1561,  -247,  -247,     9,
    -247,  1561,  -247,   761,  -247,   216,  -247,   217,   251,  1081,
    1561,  1357,  1561,  1561,  -247,   156,  1561,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  1001,   223,  -247,
    1822,   164,  -247,  1561,   -33,  -247,   173,  -247,  -247,  -247,
    -247,  -247,  -247,    63,    63,   183,   183,    76,    76,    76,
      76,    50,    50,   168,   -17,   -13,     4,   192,    24,  -247,
     228,  -247,   231,   232,   151,  1401,  1895,  -247,  -247,  -247,
    -247,  1117,  -247,  -247,  -247,  -247,  -247,  1081,  -247,   229,
    -247,   174,  1357,   178,   179,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  1561,  1561,  -247,  -247,  -247,  -247,   235,  -247,
     234,  -247,  -247,  -247,  1561,  1081,  1437,  1081,  1081,  -247,
    -247,  -247,  -247,   182,   273,  1081,   185,  -247,  -247,   236,
    1081,  -247,  1081,  -247,  -247,  -247
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     227,   140,    99,   115,   136,    98,   101,   106,   104,   107,
      97,   103,   105,   102,     0,   100,   108,    96,   116,   109,
     137,     0,   147,   229,     0,    86,    88,   110,     0,   111,
      90,     0,   139,     0,     0,   225,   228,   131,     0,     0,
     151,   149,   148,    84,     0,    92,     0,    87,    89,   114,
       0,    91,     0,   193,   205,     0,   233,     0,     0,     0,
     138,     1,   226,     0,   134,     0,   132,   141,   152,   150,
       0,    85,     0,   231,     0,     0,   121,     0,   117,     0,
     123,   207,   192,     0,     0,     0,     0,    94,   206,   232,
       2,     5,     8,     4,     6,     3,     7,     9,    10,     0,
     143,     0,    32,    33,    31,    30,    35,    34,     0,     0,
      11,    14,    24,    36,     0,    38,    42,    45,    48,    53,
      56,    58,    60,    62,    64,    66,    83,     0,   160,   146,
     159,     0,   153,   155,     0,     0,     0,   129,     0,    93,
       0,    36,    68,   176,    95,   230,     0,   120,   113,   118,
       0,     0,   124,   126,   122,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,    81,
       0,   208,   181,   182,     0,     0,     0,   183,   184,   185,
     186,     0,     0,     0,     0,     0,    28,     0,   162,     0,
       0,    25,    26,     0,     0,     0,    20,    21,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,   157,   164,   158,   165,   144,     0,   145,     0,
     130,   135,   133,   179,     0,    70,    74,    75,    71,    72,
      73,    78,    80,    79,    76,    77,     0,   112,   127,     0,
     119,     0,   207,   189,   222,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,   212,   194,   205,
     202,   208,   201,   210,   196,   209,   198,     0,     0,    13,
       0,   164,   163,     0,     0,    16,     0,    22,    18,    19,
      39,    40,    41,    43,    44,    46,    47,    49,    50,    51,
      52,    54,    55,    57,    59,    61,    63,     0,    65,   168,
       0,   172,     0,     0,   166,     0,     0,   154,   156,   161,
     177,     0,    69,   125,   128,   188,   187,     0,   220,     0,
     191,     0,     0,     0,     0,   224,    82,   200,    29,    37,
      15,    17,     0,     0,   169,   173,   167,   170,     0,   174,
       0,   178,   180,   190,     0,     0,     0,     0,     0,    23,
      67,   171,   175,     0,   213,     0,     0,   215,   216,     0,
       0,   218,     0,   217,   214,   219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,  -247,  -247,  -247,   -57,  -247,  -104,    61,    62,
     -42,    64,    85,    87,    88,    89,    90,  -247,   -56,   -69,
    -247,   -82,  -115,     7,     0,  -247,   237,  -247,   138,  -247,
    -247,   238,   -63,   -64,  -247,    65,  -247,   246,   172,   154,
     -16,   -24,   -18,  -247,   -53,  -247,    84,  -247,   127,  -112,
    -194,  -129,  -247,   -66,  -247,   171,  -247,  -247,  -247,  -247,
      94,    14,   -71,  -246,  -247,  -247,  -247,  -247,   281,  -247
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   110,   111,   112,   286,   141,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   142,   169,
     246,   170,   127,    54,    55,    44,    45,    25,    26,    27,
      28,    77,    78,    79,   151,   152,    29,    65,    66,    30,
      31,    32,    33,    42,   312,   132,   133,   134,   189,   313,
     225,   144,   234,   171,   172,   173,    83,    84,    85,    86,
     174,   175,   176,   177,   178,   179,   180,    34,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   113,   126,   143,    41,    39,   131,    23,    46,    60,
     199,   233,   147,   182,   149,   332,   154,     1,   224,   187,
       1,   231,    63,     1,    69,    47,    48,   340,    64,   314,
      51,   266,     1,    67,    24,   248,    75,   188,   220,    87,
     280,    23,   186,   255,    37,    57,     4,    81,    22,   217,
      82,   191,   192,   218,    87,   213,     1,   113,   137,   130,
      74,   214,    49,   153,    88,   138,   136,    21,    20,     1,
      21,   143,    43,    21,   150,    22,   282,   215,    22,   113,
     126,    88,    21,   149,   226,   265,   356,   314,    72,    22,
      22,    38,   219,   113,   126,   258,   290,   291,   292,   183,
     184,   113,   126,   187,   220,   310,   221,   216,   187,    50,
     271,   284,   223,   277,   222,   252,   275,   220,   193,   221,
     194,   188,   195,   230,   320,   287,   254,    22,   207,   208,
     138,   321,   200,   201,   202,   307,   324,   209,   210,   227,
     196,   197,   251,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     198,   113,   253,   113,   126,   297,   298,   299,   300,    58,
     281,    59,    70,   205,    71,   206,    40,   322,   331,   339,
     333,   334,   269,   228,   249,   229,   250,   326,    76,   256,
      88,    88,   352,   330,   113,   126,    68,   336,   257,    60,
     348,   259,    56,   223,    80,    39,   266,   279,   267,   266,
     315,   275,   316,    76,    76,    76,   260,    73,    76,   261,
     266,   130,   335,   220,   262,   280,   113,   130,    89,    80,
      80,    80,   268,   153,    80,   341,   355,   342,   266,    76,
     357,   358,   266,   266,   369,   145,   266,   372,   283,   266,
     203,   204,   143,   211,   212,    80,   266,   343,   113,   126,
     325,   353,   281,   350,   293,   294,   263,   295,   296,   270,
     272,   288,   363,   359,   366,   301,   302,   273,   289,   319,
     130,   327,   329,   328,    76,   338,   113,   360,   344,   364,
     354,   367,   368,   345,   346,   361,   362,   370,   303,   371,
      80,   304,   373,   305,   374,   306,   375,   139,   308,   135,
     232,   318,   278,   146,   323,    62,   130,     0,     0,     2,
       3,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     5,     0,     0,     6,     0,    80,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   155,     0,    90,    91,    92,    93,
      94,    95,    96,    97,   156,     0,     0,     2,     3,     0,
     157,   158,   159,   160,   161,   162,   163,     0,   164,     4,
       0,     0,     5,   165,   166,     6,   167,    99,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,   317,     0,     0,
    -204,    53,     0,     0,   101,     0,     0,     0,     0,   168,
     102,   103,   104,     0,     0,   105,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   155,     0,    90,    91,
      92,    93,    94,    95,    96,    97,   156,     0,     0,     2,
       3,     0,   157,   158,   159,   160,   161,   162,   163,     0,
     164,     4,     0,     0,     5,   165,   166,     6,   167,    99,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,  -203,    53,     0,     0,   101,     0,     0,     0,
       0,   168,   102,   103,   104,     0,     0,   105,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   155,     0,
      90,    91,    92,    93,    94,    95,    96,    97,   156,     0,
       0,     2,     3,     0,   157,   158,   159,   160,   161,   162,
     163,     0,   164,     4,     0,     0,     5,   165,   166,     6,
     167,    99,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,   101,     0,
       0,     0,     0,   168,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     181,     0,    90,    91,    92,    93,    94,    95,    96,    97,
     156,     0,     0,     2,     3,     0,   157,   158,   159,   160,
     161,   162,   163,     0,   164,     4,     0,     0,     5,   165,
     166,     6,   167,    99,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
     101,     0,     0,     0,     0,   168,   102,   103,   104,     0,
       0,   105,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   181,     0,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,     3,   164,     0,     0,     0,
       0,   165,   166,     0,   167,    99,     4,     0,     0,     0,
       0,     0,     6,     0,     0,     7,     8,     9,     0,    11,
      12,    13,    14,     0,    16,     0,    18,    19,    20,    53,
       0,     0,   101,     0,     0,     0,     0,   168,   102,   103,
     104,     0,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     2,     3,     0,   157,   158,
     159,   160,   161,   162,   163,     0,   164,     4,     0,     0,
       5,   165,   166,     6,   167,    99,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   101,     0,     0,     0,     0,   168,   102,   103,
     104,     0,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     6,     0,    99,     7,     8,     9,     0,
      11,    12,    13,    14,     0,    16,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,   102,   103,
     104,     0,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   235,   164,     0,     0,     0,
       0,   165,   166,     0,   167,    99,     0,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,    53,
       0,     0,   101,     0,     0,     0,     0,   168,   102,   103,
     104,     0,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,     0,   164,     0,     0,     0,
       0,   165,   166,     0,   167,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   337,    53,
       0,     0,   101,     0,     0,     0,     0,   168,   102,   103,
     104,     0,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,     0,   164,     0,     0,     0,
       0,   165,   166,     0,   167,    99,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   101,     0,     0,     0,     0,   168,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,   351,   140,     0,     0,   101,     0,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,   140,     0,     0,   101,     0,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,   264,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,   101,   285,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,   101,     0,     0,     0,     0,     0,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,   168,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,   101,     0,     0,     0,     0,     0,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,   101,   365,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,   102,   103,
     104,    99,     0,   105,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,   102,   103,   104,     0,     0,   105,
       0,     0,   106,   107,     0,    99,     0,     0,   108,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     2,     3,     0,     0,     0,   102,   103,
     104,     0,     0,   105,     0,     4,   106,   107,     5,     0,
       0,     6,   108,   109,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    61,     0,     0,     0,    53,     0,     0,
       0,     0,     0,   -94,     1,   -94,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     1,     0,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     4,     0,     0,
       5,     0,    22,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       1,     0,     0,     2,     3,     0,     0,     0,     0,     0,
     220,     0,   221,   311,     0,     4,     0,     0,     5,     0,
      22,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     2,     3,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     4,     0,     0,     5,     0,     0,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     2,     3,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   128,     0,     0,     2,     3,     0,     0,     0,     0,
       0,   220,     0,   280,   311,     0,     4,     0,     0,     5,
       0,    22,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,   129,     0,     5,     0,     0,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     2,     3,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     3,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     4,     0,     0,     0,     0,     0,
       6,     0,     3,     7,     8,     9,     0,    11,    12,    13,
      14,     0,    16,     4,    18,    19,    20,     0,     0,     6,
       0,     0,     7,     8,     9,   148,    11,    12,    13,    14,
       0,    16,     0,    18,    19,    20,     2,     3,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20
};

static const yytype_int16 yycheck[] =
{
       0,    58,    58,    72,    22,    21,    59,     0,    24,    33,
     114,   140,    76,    84,    77,   261,    80,    11,   130,   101,
      11,   136,    58,    11,    42,    25,    26,    60,    11,   223,
      30,    64,    11,    62,    34,   150,    58,   101,    59,    55,
      61,    34,    99,   158,    11,    31,    26,    66,    69,    80,
      57,   108,   109,    84,    70,    72,    11,   114,    57,    59,
      46,    74,    11,    79,    57,    64,    77,    61,    48,    11,
      61,   140,    66,    61,    65,    69,   188,    73,    69,   136,
     136,    74,    61,   146,    62,   167,   332,   281,    77,    69,
      69,    58,    60,   150,   150,   161,   200,   201,   202,    85,
      86,   158,   158,   185,    59,   220,    61,    83,   190,    58,
     176,   193,   130,   184,   130,    66,   182,    59,    59,    61,
      61,   185,    63,    57,    57,   194,    66,    69,    78,    79,
      64,    64,    69,    70,    71,   217,   251,    87,    88,    64,
      81,    82,    65,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     101,   218,    65,   220,   220,   207,   208,   209,   210,    59,
     188,    61,    64,    97,    66,    99,    22,   246,   260,   283,
     262,   263,   175,    62,    64,    64,    66,   253,    50,    66,
     183,   184,   321,   259,   251,   251,    42,   266,    11,   223,
     315,    65,    31,   221,    50,   221,    64,    62,    66,    64,
      59,   277,    61,    75,    76,    77,    61,    46,    80,    61,
      64,   221,    66,    59,    61,    61,   283,   227,    57,    75,
      76,    77,    57,   249,    80,    62,    62,    64,    64,   101,
      62,    62,    64,    64,    62,    74,    64,    62,    62,    64,
      67,    68,   321,    85,    86,   101,    64,    65,   315,   315,
     253,   327,   280,   316,   203,   204,    61,   205,   206,   175,
     176,    11,   354,   342,   356,   211,   212,    66,    11,    11,
     280,    65,    31,    66,   146,    62,   343,   343,    60,   355,
      61,   357,   358,    62,    62,    60,    62,    24,   213,   365,
     146,   214,    66,   215,   370,   216,   372,    70,   218,    63,
     138,   227,   185,    75,   249,    34,   316,    -1,    -1,    14,
      15,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,   185,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,
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
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    15,    25,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    26,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,
      40,    41,    42,    -1,    44,    -1,    46,    47,    48,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    35,    36,    37,    -1,
      39,    40,    41,    42,    -1,    44,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    77,    25,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    34,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    75,    76,    -1,    34,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    14,    15,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    26,    75,    76,    29,    -1,
      -1,    32,    81,    82,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    64,    11,    66,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    26,    -1,    -1,
      29,    -1,    69,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    62,    -1,    26,    -1,    -1,    29,    -1,
      69,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    14,    15,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    62,    -1,    26,    -1,    -1,    29,
      -1,    69,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    62,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    15,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    44,    26,    46,    47,    48,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    57,    39,    40,    41,    42,
      -1,    44,    -1,    46,    47,    48,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    61,    69,   126,   127,   130,   131,   132,   133,   139,
     142,   143,   144,   145,   170,   171,   172,    11,    58,   143,
     142,   145,   146,    66,   128,   129,   143,   127,   127,    11,
      58,   127,     1,    58,   126,   127,   158,   164,    59,    61,
     144,     0,   171,    58,    11,   140,   141,    62,   142,   145,
      64,    66,    77,   158,   164,    58,   131,   134,   135,   136,
     142,    66,    57,   159,   160,   161,   162,   143,   126,   158,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    34,
      60,    61,    67,    68,    69,    72,    75,    76,    81,    82,
     104,   105,   106,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   125,    11,    62,
     127,   147,   148,   149,   150,   140,    77,    57,    64,   129,
      58,   108,   121,   122,   154,   158,   134,   136,    57,   135,
      65,   137,   138,   143,   136,     1,    11,    17,    18,    19,
      20,    21,    22,    23,    25,    30,    31,    33,    66,   122,
     124,   156,   157,   158,   163,   164,   165,   166,   167,   168,
     169,     1,   165,   164,   164,    61,   108,   124,   136,   151,
      61,   108,   108,    59,    61,    63,    81,    82,   101,   110,
      69,    70,    71,    67,    68,    97,    99,    78,    79,    87,
      88,    85,    86,    72,    74,    73,    83,    80,    84,    60,
      59,    61,   143,   145,   152,   153,    62,    64,    62,    64,
      57,   125,   141,   154,   155,    77,    89,    90,    91,    92,
      93,    94,    95,    96,    98,   100,   123,    57,   125,    64,
      66,    65,    66,    65,    66,   125,    66,    11,   156,    65,
      61,    61,    61,    61,    66,   124,    64,    66,    57,   126,
     163,   156,   163,    66,    57,   156,    57,   165,   151,    62,
      61,   145,   152,    62,   124,    62,   107,   122,    11,    11,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     113,   114,   114,   115,   116,   117,   118,   124,   119,    60,
     125,    62,   147,   152,   153,    59,    61,   102,   149,    11,
      57,    64,   122,   138,   125,   126,   156,    65,    66,    31,
     156,   124,   166,   124,   124,    66,   122,    57,    62,   110,
      60,    62,    64,    65,    60,    62,    62,    60,   125,    62,
     147,    57,   154,   156,    61,    62,   166,    62,    62,   122,
     121,    60,    62,   124,   156,    62,   124,   156,   156,    62,
      24,   156,    62,    66,   156,   156
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
     169,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     172,   172,   172,   172
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
       3,     2,     2,     2,     3,     1,     2,     0,     1,     1,
       4,     3,     3,     2
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
#line 83 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "int", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1930 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 89 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "float", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1940 "parser.tab.c"
    break;

  case 4: /* constant: EXP_LITERAL  */
#line 94 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "exp", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1946 "parser.tab.c"
    break;

  case 5: /* constant: HEXA_LITERAL  */
#line 95 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "hexa", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1952 "parser.tab.c"
    break;

  case 6: /* constant: REAL_LITERAL  */
#line 96 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "real", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1958 "parser.tab.c"
    break;

  case 7: /* constant: STRING_LITERAL  */
#line 97 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "string", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1964 "parser.tab.c"
    break;

  case 8: /* constant: OCTAL_LITERAL  */
#line 98 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "octal", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1970 "parser.tab.c"
    break;

  case 9: /* constant: CHARACTER_LITERAL  */
#line 100 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        string tempp = "'";
        tempp+=(*(char*)((yyvsp[0].symbol_info)->ptr));
        tempp+='\'';
		(yyval.symbol_info)->place=qid(tempp,nullptr);
		(yyval.symbol_info)->code=tempp;
	}
#line 1983 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 112 "src/parser.y"
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
				cerr<<"Symbol found "<<(yyval.symbol_info)->place.second->name<<endl;
				cerr<<"Code "<<(yyval.symbol_info)->code<<endl;
			}
        }
#line 2008 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 133 "src/parser.y"
        {
		cerr << "con\n";(yyval.symbol_info) = (yyvsp[0].symbol_info);
		
	}
#line 2017 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 143 "src/parser.y"
        {
            (yyval.symbol_info)=(yyvsp[0].symbol_info);
            cerr << "Primary expression found: " << (yyvsp[0].symbol_info)->type << endl;
        }
#line 2026 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 150 "src/parser.y"
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

            //printf("Function call= %s\n",$1);
        }
#line 2057 "parser.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DOT ID  */
#line 177 "src/parser.y"
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
#line 2103 "parser.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 225 "src/parser.y"
      { 
			cout<<"$1 ka name "<<(yyvsp[0].symbol_info)->name<<endl;
		  if((yyvsp[0].symbol_info)->name==""){

			cout<<"is a number "<<(yyvsp[0].symbol_info)->type<<endl;
			(yyval.symbol_info)=(yyvsp[0].symbol_info);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
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
			}
		  }
		  
          
      }
#line 2130 "parser.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 249 "src/parser.y"
       { 
			cout<<"$3 ka name "<<(yyvsp[0].symbol_info)->name<<endl;
		  if((yyvsp[0].symbol_info)->name==""){

			cout<<"is a number "<<(yyvsp[0].symbol_info)->type<<endl;
			(yyval.symbol_info)=(yyvsp[-2].symbol_info);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
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
			}
			
			cout<<"Ass exp111 "<<(yyvsp[-2].symbol_info)->type<<endl;
		  }
			
           
       }
#line 2160 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 278 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr << "postfix expression found: " << (yyvsp[0].symbol_info)->type << endl;
	}
#line 2169 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 300 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("Unary expression %s\n",(yyval.symbol_info)->name.c_str());
	}
#line 2178 "parser.tab.c"
    break;

  case 37: /* cast_expression: LPARENTHESES type_name RPARENTHESES cast_expression  */
#line 305 "src/parser.y"
    {
        cout<<"casting"<<endl;
        (yyval.symbol_info) = (yyvsp[0].symbol_info);
        (yyval.symbol_info)->type = (yyvsp[-2].symbol_info)->type;
    }
#line 2188 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 313 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2194 "parser.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 315 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
		

	}
#line 2208 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 325 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2220 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 333 "src/parser.y"
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
#line 2235 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 346 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2241 "parser.tab.c"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 348 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2253 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 356 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2265 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 366 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2271 "parser.tab.c"
    break;

  case 46: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 368 "src/parser.y"
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
#line 2286 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 379 "src/parser.y"
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
#line 2301 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 392 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2307 "parser.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 394 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2319 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 402 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];        
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2331 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression LESS_EQUALS shift_expression  */
#line 410 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	
	}
#line 2344 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER_EQUALS shift_expression  */
#line 419 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2356 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 429 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2362 "parser.tab.c"
    break;

  case 54: /* equality_expression: equality_expression REL_EQUALS relational_expression  */
#line 431 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"=="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
		// file<<$$->code<<endl;
	}
#line 2375 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression REL_NOT_EQ relational_expression  */
#line 440 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"!="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2387 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 451 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2393 "parser.tab.c"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 453 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: And operator can only be used with int type\n");
        }
    }
#line 2405 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 463 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2411 "parser.tab.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression XOR and_expression  */
#line 465 "src/parser.y"
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
#line 2426 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 478 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2432 "parser.tab.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression OR exclusive_or_expression  */
#line 480 "src/parser.y"
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
#line 2447 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 493 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2453 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression REL_AND inclusive_or_expression  */
#line 495 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: AND operator can only be used with int type\n");
        }
        
    }
#line 2466 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 506 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2472 "parser.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression REL_OR logical_and_expression  */
#line 508 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            printf("ERROR!!!!!!: OR operator can only be used with int type\n");
        }
    }
#line 2484 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 518 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2490 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 524 "src/parser.y"
        { 
		//printf("conditional inside assignment = %s\n",$$);
		// $$ = strdup($1);
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		printf("cond expression = %s\n",(yyvsp[0].symbol_info)->type.c_str());
		printf("cond expression2 = %s\n",(yyvsp[0].symbol_info)->name.c_str());
		cerr << "condi expression found: " << (yyvsp[0].symbol_info)->code << endl;
	}
#line 2503 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 533 "src/parser.y"
        {
		printf("unary inside assignment = %s\n",(yyvsp[-2].symbol_info)->name.c_str());
		printf("Assignment expression = %s\n",(yyvsp[0].symbol_info)->type.c_str());
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
                if(type_priority[find_symbol->type]<type_priority[(yyvsp[0].symbol_info)->type]){
                    printf("ERROR!!!!!!: Type mismatch in assignment\n");
                }else{
                    printf("Correct type assignment\n");
                }
                
                find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[(yyvsp[0].symbol_info)->type])];
                find_symbol->name=(yyvsp[-2].symbol_info)->name;
                find_symbol->place=(yyvsp[-2].symbol_info)->place;
                find_symbol->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                //file<<find_symbol->code<<endl;
                
                cerr<<"Correct type assignment"<<endl;

                //3AC code
                cerr<<"3AC code for assignment"<<endl;
				if((yyvsp[0].symbol_info)->place.first[0]!='t')
				{
					(yyvsp[0].symbol_info)->code="";
				}
                (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                (yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
                //file<<$$->code<<endl;
				
			}
			
		}
			
           else{
			printf("Symbol not found\n");
		} 
            
        }
#line 2569 "parser.tab.c"
    break;

  case 70: /* assignment_operator: EQUALS  */
#line 601 "src/parser.y"
                 {(yyval.symbol_info)=new symbol_info("","equals",nullptr,0); (yyval.symbol_info)->code="=";}
#line 2575 "parser.tab.c"
    break;

  case 71: /* assignment_operator: ASSIGN_STAR  */
#line 602 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_star",nullptr,0); (yyval.symbol_info)->code="*=";}
#line 2581 "parser.tab.c"
    break;

  case 72: /* assignment_operator: ASSIGN_DIV  */
#line 603 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_div",nullptr,0); (yyval.symbol_info)->code="/=";}
#line 2587 "parser.tab.c"
    break;

  case 73: /* assignment_operator: ASSIGN_MOD  */
#line 604 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_mod",nullptr,0); (yyval.symbol_info)->code="%=";}
#line 2593 "parser.tab.c"
    break;

  case 74: /* assignment_operator: ASSIGN_PLUS  */
#line 605 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_plus",nullptr,0); (yyval.symbol_info)->code="+=";}
#line 2599 "parser.tab.c"
    break;

  case 75: /* assignment_operator: ASSIGN_MINUS  */
#line 606 "src/parser.y"
                       {(yyval.symbol_info)=new symbol_info("","assign_minus",nullptr,0); (yyval.symbol_info)->code="-=";}
#line 2605 "parser.tab.c"
    break;

  case 76: /* assignment_operator: LEFT_SHIFT_EQ  */
#line 607 "src/parser.y"
                        {(yyval.symbol_info)=new symbol_info("","left_shift_eq",nullptr,0); (yyval.symbol_info)->code="<<=";}
#line 2611 "parser.tab.c"
    break;

  case 77: /* assignment_operator: RIGHT_SHIFT_EQ  */
#line 608 "src/parser.y"
                         {(yyval.symbol_info)=new symbol_info("","right_shift_eq",nullptr,0); (yyval.symbol_info)->code=">>=";}
#line 2617 "parser.tab.c"
    break;

  case 78: /* assignment_operator: ASSIGN_AND  */
#line 609 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_and",nullptr,0); (yyval.symbol_info)->code="&=";}
#line 2623 "parser.tab.c"
    break;

  case 79: /* assignment_operator: ASSIGN_XOR  */
#line 610 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_xor",nullptr,0); (yyval.symbol_info)->code="^=";}
#line 2629 "parser.tab.c"
    break;

  case 80: /* assignment_operator: ASSIGN_OR  */
#line 611 "src/parser.y"
                    {(yyval.symbol_info)=new symbol_info("","assign_or",nullptr,0); (yyval.symbol_info)->code="|=";}
#line 2635 "parser.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 616 "src/parser.y"
        {
		// cout<<"Assignment expression = "<<$1->code<<endl;
		// file<<$1->code<<endl;
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2645 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 632 "src/parser.y"
    {
		
		printf("parsing stack top = %s\n",parsing_stack.top().c_str());
		printf("Declaration specifiers = %s\n", (yyvsp[-2].str));
		printf("Init declarator list = %f\n", (yyvsp[-1].symbol_info)->name.c_str());
		printf("dollar 3 type = %s\n",(yyvsp[-1].symbol_info)->type);
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

				if ((yyvsp[-2].str) != curr_scope->symbol_map[top_symbol]->type) {
					printf("Error: Type mismatch in declaration\n");
					flag = 1;
				}
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
				(yyval.symbol_info)->code = (yyvsp[-1].symbol_info)->code;

			} else {
				// Create new symbol_info and assign type = $1
				curr_scope->symbol_map[top_symbol]->type = (yyvsp[-2].str);
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
				printf("Created new symbol: %s with type %s\n", top_symbol.c_str(), ((yyvsp[-2].str)));
				symbol_info* new_symbol = new symbol_info();
				new_symbol = (yyvsp[-1].symbol_info);
				(yyval.symbol_info)=new_symbol;
			}
		}
		cerr<<"dollar 3 type = "<<(yyvsp[-1].symbol_info)->type<<endl;
		cerr<<"bbbbbbbbbbbbbbbbbbb"<<(yyvsp[-1].symbol_info)->code<<endl;
		// $$->code = $2->code;
		cerr<<"tttttttttttttttttttt "<<(yyvsp[-1].symbol_info)->type<<endl;
		if(flag==0) printf("Correct type declaration\n");
		
		
    }
#line 2694 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 682 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 2700 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 689 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
		printf("init_d %s\n",(yyval.symbol_info)->name.c_str());  
    }
#line 2709 "parser.tab.c"
    break;

  case 93: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 693 "src/parser.y"
                                                 { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->code = (yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		printf("init_D %s\n",(yyval.symbol_info)->name.c_str()); 
    }
#line 2719 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator  */
#line 701 "src/parser.y"
                 { 
		printf("declarator11 %s\n",(yyvsp[0].symbol_info)->name.c_str());
		cerr<<"declarator11 "<<(yyvsp[0].symbol_info)->name<<endl;
		if(curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		symbol_info* new_symbol=new symbol_info();

		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]=new_symbol;
        (yyval.symbol_info) =(yyvsp[0].symbol_info);
		printf("declarator %s\n",(yyval.symbol_info)->name.c_str()); 
		parsing_stack.push((yyvsp[0].symbol_info)->name.c_str());
    }
#line 2739 "parser.tab.c"
    break;

  case 95: /* init_declarator: declarator EQUALS initializer  */
#line 716 "src/parser.y"
                                    { 
		printf("declaratoreiii %s\n",(yyvsp[-2].symbol_info)->name.c_str());
		if(curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]!=nullptr){
			printf("Redeclaration error \n");
			exit(1);
		}
		
		curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=(yyvsp[0].symbol_info);
		if((yyvsp[0].symbol_info)->type=="float") printf("Yes float found\n");
		if((yyvsp[0].symbol_info)->type=="int") printf("Yes int found\n");
		if((yyvsp[0].symbol_info)->type=="char") printf("Yes char found %s\n",(yyvsp[0].symbol_info)->str_val.c_str());
		parsing_stack.push((yyvsp[-2].symbol_info)->name.c_str());
		if((yyvsp[-2].symbol_info)->is_array){
			if((yyvsp[0].symbol_info)->int_array.size() > (yyvsp[-2].symbol_info)->array_length){
				printf("Error: Elements Greater than Declared\n");
			}
			else{
				(yyvsp[-2].symbol_info)->int_array = (yyvsp[0].symbol_info)->int_array;
				(yyvsp[-2].symbol_info)->type = (yyvsp[0].symbol_info)->type;
			}
		}
		
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
		if((yyvsp[0].symbol_info)->place.first[0]!='t')
		{
			(yyvsp[0].symbol_info)->code="";
		}
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+(yyvsp[-2].symbol_info)->place.first+":= "+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
		// file<<$$->code<<endl;
		printf("declarator equals initializer %s\n",(yyval.symbol_info)->name.c_str()); 
		
    }
#line 2777 "parser.tab.c"
    break;

  case 101: /* type_specifier: VOID  */
#line 760 "src/parser.y"
                                        {(yyval.str)=strdup("void");}
#line 2783 "parser.tab.c"
    break;

  case 102: /* type_specifier: CHAR  */
#line 761 "src/parser.y"
                                        {(yyval.str)=strdup("char");}
#line 2789 "parser.tab.c"
    break;

  case 103: /* type_specifier: SHORT  */
#line 762 "src/parser.y"
                                        {(yyval.str)=strdup("short");}
#line 2795 "parser.tab.c"
    break;

  case 104: /* type_specifier: INT  */
#line 763 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 2801 "parser.tab.c"
    break;

  case 105: /* type_specifier: LONG  */
#line 764 "src/parser.y"
                                        {(yyval.str)=strdup("long");}
#line 2807 "parser.tab.c"
    break;

  case 106: /* type_specifier: FLOAT  */
#line 765 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 2813 "parser.tab.c"
    break;

  case 107: /* type_specifier: DOUBLE  */
#line 766 "src/parser.y"
                                        {(yyval.str)=strdup("double");}
#line 2819 "parser.tab.c"
    break;

  case 108: /* type_specifier: SIGNED  */
#line 767 "src/parser.y"
                                        {(yyval.str)=strdup("signed");}
#line 2825 "parser.tab.c"
    break;

  case 109: /* type_specifier: UNSIGNED  */
#line 768 "src/parser.y"
                                        {(yyval.str)=strdup("unsigned");}
#line 2831 "parser.tab.c"
    break;

  case 110: /* type_specifier: struct_or_union_specifier  */
#line 769 "src/parser.y"
                                    {(yyval.str)=(yyvsp[0].str);}
#line 2837 "parser.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 775 "src/parser.y"
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
#line 2853 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID  */
#line 788 "src/parser.y"
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
#line 2871 "parser.tab.c"
    break;

  case 115: /* struct_or_union: STRUCT  */
#line 804 "src/parser.y"
                 {(yyval.str)=strdup("struct");}
#line 2877 "parser.tab.c"
    break;

  case 116: /* struct_or_union: UNION  */
#line 805 "src/parser.y"
                {(yyval.str)=strdup("union");}
#line 2883 "parser.tab.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration  */
#line 809 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2889 "parser.tab.c"
    break;

  case 118: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 811 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(int i=0;i<(yyvsp[0].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->param_list[i]);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->param_types[i]);
		}
		
	}
#line 2902 "parser.tab.c"
    break;

  case 119: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 823 "src/parser.y"
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
#line 2923 "parser.tab.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator  */
#line 850 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 2932 "parser.tab.c"
    break;

  case 125: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 855 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 2941 "parser.tab.c"
    break;

  case 126: /* struct_declarator: declarator  */
#line 862 "src/parser.y"
                         {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2947 "parser.tab.c"
    break;

  case 130: /* enum_specifier: ENUM ID LBRACE enumerator_list RBRACE  */
#line 870 "src/parser.y"
        {
		
		//printf("enum is here = %s\n",$$);
	}
#line 2956 "parser.tab.c"
    break;

  case 138: /* declarator: pointer direct_declarator  */
#line 893 "src/parser.y"
                                { 
		//printf("Pointer direct declarator\n");
    }
#line 2964 "parser.tab.c"
    break;

  case 139: /* declarator: direct_declarator  */
#line 896 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info); 
		printf("Direct declarator %s\n",(yyval.symbol_info)->name.c_str());
    }
#line 2973 "parser.tab.c"
    break;

  case 140: /* direct_declarator: ID  */
#line 904 "src/parser.y"
        {
		printf("%s\n",(yyvsp[0].str));
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);
		x->place.first=(yyvsp[0].str);
		(yyval.symbol_info)=x;
		printf("ID %s\n",(yyval.symbol_info)->name.c_str());
	}
#line 2986 "parser.tab.c"
    break;

  case 141: /* direct_declarator: LPARENTHESES declarator RPARENTHESES  */
#line 913 "src/parser.y"
        { 
		//printf("LPar declarator RPar= %s\n",$2);
	}
#line 2994 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LBRACKET constant_expression RBRACKET  */
#line 916 "src/parser.y"
                                                                                        {(yyval.symbol_info)->is_array = true;
																		if((yyvsp[-1].symbol_info)->type=="int"){
																			(yyval.symbol_info)->array_length = *(int*)((yyvsp[-1].symbol_info)->ptr);
																			printf("Array length = %d\n",(yyval.symbol_info)->array_length);
																		}
																		else{
																			printf("Error: Array size not an integer\n");
																			(yyval.symbol_info)->array_length=100;
																		}}
#line 3008 "parser.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 925 "src/parser.y"
                                                                                                        {printf("Array Size not declared\n"), (yyval.symbol_info)->is_array = true, (yyval.symbol_info)->array_length = 100;}
#line 3014 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LPARENTHESES parameter_type_list RPARENTHESES  */
#line 927 "src/parser.y"
        {
		printf("Brackets found with parameter= %s\n",(yyvsp[-3].symbol_info)->name.c_str());
		printf("Par list %d\n",(yyvsp[-1].symbol_info)->parameter_no);
		for(auto it: (yyvsp[-1].symbol_info)->param_types)
					{
						cout<<it<<endl;
					}
		curr_scope->symbol_map[(yyvsp[-3].symbol_info)->name]=(yyvsp[-1].symbol_info);
	}
#line 3028 "parser.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 954 "src/parser.y"
                        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		for(auto it: (yyvsp[0].symbol_info)->param_types)
					{
						cout<<it<<endl;
					}
		cout<<"par num"<<(yyval.symbol_info)->parameter_no<<endl;
				}
#line 3041 "parser.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 967 "src/parser.y"
                               {(yyval.symbol_info)->is_param_list=true;
	   						(yyval.symbol_info)->parameter_no=1;
							
	   						(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);}
#line 3050 "parser.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 971 "src/parser.y"
                                                     {(yyval.symbol_info)->is_param_list=true;
							cout<<"par num $1 "<<(yyvsp[-2].symbol_info)->parameter_no<<endl;
							cout<<"par num $3 "<<(yyvsp[0].symbol_info)->parameter_no<<endl;
	   						(yyval.symbol_info)->parameter_no=(yyvsp[-2].symbol_info)->parameter_no+(yyvsp[0].symbol_info)->parameter_no;
	   						(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
							
												}
#line 3062 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 983 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->parameter_no=1;
		// printf("%s",$$->type);
	}
#line 3074 "parser.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 990 "src/parser.y"
                                                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		// printf("%s",$$->type);
	}
#line 3085 "parser.tab.c"
    break;

  case 159: /* parameter_declaration: declaration_specifiers  */
#line 996 "src/parser.y"
                                {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[0].str);
		// printf("%s",$$->type);
	}
#line 3096 "parser.tab.c"
    break;

  case 176: /* initializer: assignment_expression  */
#line 1033 "src/parser.y"
                                {
		(yyvsp[0].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3105 "parser.tab.c"
    break;

  case 177: /* initializer: LBRACE initializer_list RBRACE  */
#line 1037 "src/parser.y"
                                         {(yyval.symbol_info) = (yyvsp[-1].symbol_info);}
#line 3111 "parser.tab.c"
    break;

  case 178: /* initializer: LBRACE initializer_list COMMA RBRACE  */
#line 1038 "src/parser.y"
                                               {(yyval.symbol_info) = (yyvsp[-2].symbol_info);}
#line 3117 "parser.tab.c"
    break;

  case 179: /* initializer_list: initializer  */
#line 1042 "src/parser.y"
                      {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 3123 "parser.tab.c"
    break;

  case 180: /* initializer_list: initializer_list COMMA initializer  */
#line 1043 "src/parser.y"
                                             {
		if((yyvsp[-2].symbol_info)->type != (yyvsp[0].symbol_info)->type){
			printf("Error: Type mismatch in initializer list\n");
		}
		else{
			(yyvsp[-2].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		}
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
	}
#line 3137 "parser.tab.c"
    break;

  case 181: /* statement: labeled_statement  */
#line 1055 "src/parser.y"
                           {(yyval.symbol_info)=(yyvsp[0].symbol_info);cerr<<"label\n";}
#line 3143 "parser.tab.c"
    break;

  case 182: /* statement: compound_statement  */
#line 1057 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);

		//file<<$$->code<<endl;
	}
#line 3153 "parser.tab.c"
    break;

  case 184: /* statement: selection_statement  */
#line 1063 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3159 "parser.tab.c"
    break;

  case 185: /* statement: iteration_statement  */
#line 1064 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3165 "parser.tab.c"
    break;

  case 186: /* statement: jump_statement  */
#line 1065 "src/parser.y"
                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3171 "parser.tab.c"
    break;

  case 187: /* labeled_statement: ID COLON statement  */
#line 1069 "src/parser.y"
                            {cerr << "2HERE\n";}
#line 3177 "parser.tab.c"
    break;

  case 193: /* $@1: %empty  */
#line 1078 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3183 "parser.tab.c"
    break;

  case 194: /* compound_statement: LBRACE $@1 statement_declaration_list RBRACE  */
#line 1078 "src/parser.y"
                                                                                                 {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
		//file<<$$->code<<endl; 
	}
#line 3195 "parser.tab.c"
    break;

  case 195: /* $@2: %empty  */
#line 1085 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3201 "parser.tab.c"
    break;

  case 196: /* compound_statement: LBRACE $@2 statement_list RBRACE  */
#line 1085 "src/parser.y"
                                                                                     {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3210 "parser.tab.c"
    break;

  case 197: /* $@3: %empty  */
#line 1089 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3216 "parser.tab.c"
    break;

  case 198: /* compound_statement: LBRACE $@3 declaration_list RBRACE  */
#line 1089 "src/parser.y"
                                                                                       {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3225 "parser.tab.c"
    break;

  case 199: /* $@4: %empty  */
#line 1093 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3231 "parser.tab.c"
    break;

  case 200: /* compound_statement: LBRACE $@4 declaration_list statement_list RBRACE  */
#line 1093 "src/parser.y"
                                                                                                      {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3239 "parser.tab.c"
    break;

  case 201: /* statement_declaration_list: statement_list statement_declaration_list  */
#line 1100 "src/parser.y"
        {
		// cerr<<"idhar to nahi hona chahiye\n";
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 3248 "parser.tab.c"
    break;

  case 202: /* statement_declaration_list: declaration_list statement_declaration_list  */
#line 1105 "src/parser.y"
        {

		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		//file<<"heloo"<<$$->code<<endl;
	}
#line 3258 "parser.tab.c"
    break;

  case 203: /* statement_declaration_list: statement_list  */
#line 1110 "src/parser.y"
                        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"statement list"<<endl;
		//file<<$$->code<<endl;
	}
#line 3268 "parser.tab.c"
    break;

  case 204: /* statement_declaration_list: declaration_list  */
#line 1116 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"Hello?\n";
		//file<<$$->code<<endl;
	}
#line 3278 "parser.tab.c"
    break;

  case 205: /* declaration_list: declaration  */
#line 1125 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		//file<<$$->code<<endl;
	}
#line 3287 "parser.tab.c"
    break;

  case 206: /* declaration_list: declaration_list declaration  */
#line 1130 "src/parser.y"
        {
		cout<<"Maaaai yaha honnnn"<<endl;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		//file<<$$->code<<endl;
	}
#line 3297 "parser.tab.c"
    break;

  case 207: /* declaration_list: error SEMICOLON  */
#line 1135 "src/parser.y"
                          {yyerrok;}
#line 3303 "parser.tab.c"
    break;

  case 208: /* statement_list: statement  */
#line 1139 "src/parser.y"
                    { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		cerr<<"Statement\n";
	}
#line 3312 "parser.tab.c"
    break;

  case 209: /* statement_list: statement_list statement  */
#line 1144 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		
	}
#line 3321 "parser.tab.c"
    break;

  case 210: /* statement_list: error SEMICOLON  */
#line 1148 "src/parser.y"
                          {yyerrok;}
#line 3327 "parser.tab.c"
    break;

  case 213: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement  */
#line 1158 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+"if("+ (yyvsp[-2].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+falselabel+":\n";
		//file<<$$->code<<endl;
	}
#line 3338 "parser.tab.c"
    break;

  case 214: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement ELSE statement  */
#line 1165 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+"if("+ (yyvsp[-4].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
		//file<<$$->code<<endl;
	}
#line 3350 "parser.tab.c"
    break;

  case 220: /* jump_statement: GOTO ID SEMICOLON  */
#line 1184 "src/parser.y"
        { 
		//printf("Goto statement: %s\n",$2);
		cerr << "goto\n";
	}
#line 3359 "parser.tab.c"
    break;

  case 225: /* translation_unit: external_declaration  */
#line 1196 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		file<<(yyval.symbol_info)->code<<endl;
	}
#line 3368 "parser.tab.c"
    break;

  case 228: /* external_declaration: function_definition  */
#line 1206 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		//file<<$$->code<<endl;
	}
#line 3377 "parser.tab.c"
    break;

  case 231: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 1216 "src/parser.y"
        {
		//abhi ke liye
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		// file<<$$->code<<endl;
	}
#line 3389 "parser.tab.c"
    break;


#line 3393 "parser.tab.c"

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

#line 1226 "src/parser.y"


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
