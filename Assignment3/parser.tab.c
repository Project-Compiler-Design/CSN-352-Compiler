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

	#include "include/functions.h"
    using namespace std;

	#define MAX_ARGS 100

    void yyerror(const char *s);
	void print_errors();

    extern int yylex();
    extern int yylineno;
    extern char *yytext; 

	std::stack<std::string> parsing_stack;
    std::stack<int> pointer_info;
	std::map<std::string,std::string> type_def_mapping;

    scoped_symtab* curr_scope = new scoped_symtab();
    std::vector<scoped_symtab*> all_scopes={curr_scope};

    std::vector<std::string> error_list;
		
    vector<string> type_list = {};
	vector<string> var_name={};
	map<string,string> goto_list;
    stack<queue<pair<string,string>>> case_list;

	struct ArgList {
        char *args[MAX_ARGS];
        int count_arg;
    } argList;


#line 105 "parser.tab.c"

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
  YYSYMBOL_168_5 = 168,                    /* $@5  */
  YYSYMBOL_iteration_statement = 169,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 170,           /* jump_statement  */
  YYSYMBOL_start_symbol = 171,             /* start_symbol  */
  YYSYMBOL_translation_unit = 172,         /* translation_unit  */
  YYSYMBOL_external_declaration = 173,     /* external_declaration  */
  YYSYMBOL_function_definition = 174,      /* function_definition  */
  YYSYMBOL_175_6 = 175                     /* $@6  */
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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2086

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

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
       0,    75,    75,    81,    87,    88,    89,    90,    97,    98,
     110,   127,   131,   132,   144,   148,   180,   210,   249,   320,
     321,   330,   341,   372,   408,   412,   413,   414,   435,   436,
     440,   447,   454,   461,   468,   475,   485,   489,   497,   498,
     506,   514,   528,   529,   537,   548,   549,   560,   574,   575,
     583,   591,   600,   611,   612,   620,   631,   632,   643,   644,
     658,   659,   673,   674,   686,   687,   698,   699,   703,   704,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   835,   839,   846,   850,   851,   942,   943,   953,   954,
     955,   959,   962,   969,   997,  1045,  1046,  1047,  1048,  1049,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1075,  1083,  1084,  1101,  1102,  1106,  1107,  1119,
    1138,  1139,  1143,  1148,  1156,  1157,  1158,  1162,  1163,  1164,
    1168,  1169,  1173,  1174,  1178,  1179,  1183,  1187,  1193,  1200,
    1201,  1212,  1216,  1229,  1230,  1245,  1246,  1247,  1248,  1252,
    1253,  1258,  1268,  1272,  1279,  1290,  1298,  1304,  1313,  1314,
    1318,  1319,  1323,  1324,  1325,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1337,  1341,  1345,  1346,  1350,  1351,  1363,
    1368,  1372,  1376,  1377,  1378,  1383,  1410,  1438,  1439,  1446,
    1456,  1458,  1457,  1478,  1478,  1482,  1482,  1486,  1486,  1492,
    1504,  1515,  1524,  1531,  1538,  1542,  1546,  1549,  1557,  1561,
    1562,  1566,  1572,  1579,  1579,  1602,  1612,  1622,  1632,  1648,
    1671,  1678,  1685,  1693,  1704,  1713,  1717,  1721,  1725,  1729,
    1733,  1735,  1734,  1770,  1771
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
  "expression_statement", "selection_statement", "$@5",
  "iteration_statement", "jump_statement", "start_symbol",
  "translation_unit", "external_declaration", "function_definition", "$@6", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-250)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-232)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1695,   150,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,     5,  -250,  -250,  -250,  -250,  -250,
    -250,    23,    69,  -250,     7,  2038,  -250,  -250,    11,  -250,
    2038,  1743,   -11,    27,    59,  1695,  -250,  -250,     4,    95,
    -250,    60,  -250,  -250,    69,  -250,   -19,  -250,  1573,  -250,
    -250,   125,  1529,  -250,    97,   119,  -250,     7,  -250,  1857,
    1125,  1781,   -11,  -250,  -250,    95,    89,   -36,  -250,  -250,
    -250,  -250,    23,  -250,  1161,  1857,   128,  1529,  -250,  1981,
    -250,     9,  -250,  -250,  -250,   481,   645,  1905,  1905,   117,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  1445,  -250,   805,  -250,  -250,  -250,  -250,  -250,  -250,
    1481,  1481,  -250,  -250,   170,  -250,  1525,  -250,    72,   103,
      34,    37,   118,   135,   123,   127,   130,   -24,  -250,   165,
    -250,  -250,    38,   174,   179,  -250,   105,   -28,  1525,  -250,
      95,  -250,  1161,   592,  -250,  -250,  -250,  -250,  -250,  2000,
    -250,  -250,  1525,   115,  -250,   196,   198,    26,   201,  1525,
     214,   247,  1045,   221,   228,   230,  -250,   231,  1205,  -250,
    -250,   157,  -250,  -250,  -250,   237,   317,   399,  -250,  -250,
    -250,  -250,   229,   232,   885,  1943,   563,   805,  -250,  -250,
     164,   -15,   236,  1525,  -250,  -250,  1525,  1241,   302,  -250,
    -250,   303,  -250,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  -250,  1285,  1619,  -250,    78,  -250,   173,  -250,
     264,  -250,   304,  -250,  -250,  -250,  -250,    66,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  1525,
    -250,  -250,     9,  -250,  1525,  -250,   725,  -250,   251,  -250,
     263,   286,  1045,  1525,  1321,   269,  1525,  -250,   171,  1525,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
     965,   271,  -250,  1657,   180,  -250,  1525,    68,  -250,   178,
    -250,  -250,  -250,  -250,  -250,  -250,    72,    72,   103,   103,
      34,    34,    34,    34,    37,    37,   118,   135,   123,   127,
     205,   130,  -250,   281,  -250,   282,   283,   173,  1365,  1819,
    -250,  -250,  -250,  -250,  1081,  -250,  -250,  -250,  -250,  -250,
    1045,  -250,   306,  -250,   182,  1321,  1525,   185,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  1525,  1525,  -250,  -250,  -250,
    -250,   308,  -250,   307,  -250,  -250,  -250,  1525,  1045,  1401,
     186,  1045,  -250,  -250,  -250,  -250,   192,   346,  1045,   193,
    1045,  -250,   305,  1045,  -250,  1045,  -250,  -250,  -250,  -250
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     227,   138,    98,   115,   134,    97,   100,   105,   103,   106,
      96,   102,   104,   101,     0,    99,   107,    95,   116,   108,
     135,     0,   145,   229,     0,    86,    88,   109,     0,   110,
      89,     0,   137,     0,     0,   224,   225,   228,   129,     0,
     138,     0,   149,   147,   146,    84,     0,    91,     0,   111,
      87,   114,     0,    90,     0,   191,   203,     0,   234,     0,
       0,     0,   136,     1,   226,     0,   132,     0,   130,   139,
     150,   148,     0,    85,     0,     0,     0,     0,   120,     0,
     117,     0,   121,   205,   190,     0,     0,     0,     0,    93,
     204,   233,     2,     5,     8,     4,     6,     3,     7,     9,
      10,     0,   141,     0,    32,    33,    31,    30,    35,    34,
       0,     0,    11,    14,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    83,     0,
     111,   144,   157,     0,   151,   153,     0,     0,     0,   127,
       0,    92,     0,    36,    68,   174,    94,   230,   232,     0,
     113,   118,     0,     0,   122,   124,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,   209,
      81,     0,   206,   179,   180,     0,     0,     0,   181,   182,
     183,   184,     0,    10,     0,     0,     0,     0,    28,    10,
       0,   160,     0,     0,    25,    26,     0,     0,     0,    20,
      21,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,   155,   162,   156,   163,   142,
       0,   143,     0,   128,   133,   131,   177,     0,    70,    74,
      75,    71,    72,    73,    78,    80,    79,    76,    77,     0,
     112,   125,     0,   119,     0,   205,   187,   221,     0,   220,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
     210,   192,   203,   200,   206,   199,   208,   194,   207,   196,
       0,     0,    13,     0,   162,   161,     0,     0,    16,     0,
      22,    18,    19,    39,    40,    41,    43,    44,    46,    47,
      49,    50,    51,    52,    54,    55,    57,    59,    61,    63,
       0,    65,   166,     0,   170,     0,     0,   164,     0,     0,
     152,   154,   159,   175,     0,    69,   123,   126,   186,   185,
       0,   219,     0,   189,     0,     0,     0,     0,   223,    82,
     198,    29,    37,    15,    17,     0,     0,   167,   171,   165,
     168,     0,   172,     0,   176,   178,   188,     0,     0,     0,
       0,     0,    23,    67,   169,   173,     0,   211,     0,     0,
       0,   215,     0,     0,   217,     0,   214,   216,   212,   218
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,  -250,  -250,  -250,   -59,  -250,   -84,    70,    64,
     -23,    67,   156,   159,   155,   158,   160,  -250,   -58,   -71,
    -250,   -91,  -119,     6,     0,  -250,   310,  -250,   -13,  -250,
    -250,   311,   -62,   -89,  -250,   138,  -250,   314,   240,    31,
     -14,   -25,   -18,  -250,   -56,  -250,   161,  -250,   200,  -109,
    -199,  -131,  -250,  -153,  -250,   109,  -250,  -250,  -250,  -250,
     108,    24,   -73,  -249,  -250,  -250,  -250,  -250,  -250,  -250,
     359,  -250,  -250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   112,   113,   114,   289,   143,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   144,   170,
     249,   171,   129,    56,    57,    46,    47,    25,    26,    27,
      28,    79,    80,    81,   153,   154,    29,    67,    68,    30,
      31,    32,    33,    44,   315,   134,   135,   136,   192,   316,
     228,   146,   237,   172,   173,   174,    85,    86,    87,    88,
     175,   176,   177,   178,   179,   265,   180,   181,    34,    35,
      36,    37,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   115,   128,   145,    43,   133,    23,    41,    62,   261,
      48,   236,   190,   184,   191,   335,    38,   151,    40,   234,
      40,   139,    51,   227,   274,    50,    71,   317,   140,   233,
      53,   278,   202,   251,    40,    24,   140,  -111,    40,    78,
     258,    23,   188,    89,   223,    72,   283,    73,    60,    40,
      61,   194,   195,    42,    22,    59,   220,   115,    89,    63,
     221,   132,    65,    39,    78,    90,    78,   155,    21,    52,
      21,   145,    75,    45,   152,    70,    22,   268,    22,   115,
     128,    90,   285,    82,    21,   317,   359,   151,    21,    40,
      78,   256,    22,   115,   128,     4,   190,   223,   191,   224,
     115,   128,   190,   329,   313,   287,    66,    22,    82,   333,
      82,   185,   186,   280,   226,   210,   211,    20,   225,   293,
     294,   295,    69,   323,   212,   213,   290,   278,   343,   310,
     324,   208,   269,   209,    82,   327,    78,   223,    22,   224,
      58,   203,   204,   205,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,  -111,   115,    83,   115,   128,   138,   231,    91,   232,
     206,   207,   334,   284,    78,   337,    84,   356,   325,   252,
      82,   253,   272,    77,   147,   148,    55,   300,   301,   302,
     303,    90,    90,   355,    74,   115,   128,   217,   339,   351,
     218,    62,   342,   214,   215,   367,   226,   216,   371,  -111,
      41,  -111,  -111,   219,  -111,   374,  -111,   376,    82,  -111,
     378,   269,   379,   270,   132,   222,   282,   115,   269,   196,
     132,   197,   318,   198,   319,   269,   229,   338,   155,   223,
     344,   283,   345,   230,   358,   360,   269,   361,   370,   269,
     269,   199,   200,   145,   372,   375,   269,   269,   260,   115,
     128,   254,   328,   353,   255,   284,   366,   257,   369,   269,
     346,   201,   298,   299,   362,    49,   296,   297,     2,     3,
     259,   304,   305,   132,   273,   275,   262,   115,   363,   263,
       4,   264,   266,     5,   271,   276,     6,   256,   286,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   291,   292,   322,   330,   332,   156,   132,
      92,    93,    94,    95,    96,    97,    98,    99,   157,   331,
     336,     2,     3,   341,   158,   159,   160,   161,   162,   163,
     164,   347,   165,     4,   348,   349,     5,   166,   167,     6,
     168,   101,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   320,   357,   364,   365,
     373,   377,   306,   308,  -202,    55,   307,   309,   103,   137,
     235,   311,   141,   169,   104,   105,   106,   281,   149,   107,
     326,   321,   108,   109,    64,     0,     0,     0,   110,   111,
     156,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     157,     0,     0,     2,     3,     0,   158,   159,   160,   161,
     162,   163,   164,     0,   165,     4,     0,     0,     5,   166,
     167,     6,   168,   101,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,  -201,    55,     0,     0,
     103,     0,     0,     0,     0,   169,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,     0,     0,     0,
     110,   111,   156,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   157,     0,     0,     2,     3,     0,   158,   159,
     160,   161,   162,   163,   164,     0,   165,     4,     0,     0,
       5,   166,   167,     6,   168,   101,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,   103,     0,     0,     0,     0,   169,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,     0,
       0,     0,   110,   111,   182,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   157,     0,     0,     2,     3,     0,
     158,   159,   160,   161,   162,   163,   164,     0,   165,     4,
       0,     0,     5,   166,   167,     6,   168,   101,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,   103,     0,     0,     0,     0,   169,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,   182,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   183,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   238,
     165,     0,     0,     0,     0,   166,   167,     0,   168,   101,
       0,   239,   240,   241,   242,   243,   244,   245,   246,     0,
     247,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   103,     0,     0,     0,
       0,   169,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   157,     0,     0,     2,
       3,     0,   158,   159,   160,   161,   162,   163,   164,     0,
     165,     4,     0,     0,     5,   166,   167,     6,   168,   101,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   103,     0,     0,     0,
       0,   169,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   189,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     6,     0,   101,
       7,     8,     9,     0,    11,    12,    13,    14,     0,    16,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,     0,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   183,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,     0,
     165,     0,     0,     0,     0,   166,   167,     0,   168,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,    55,     0,     0,   103,     0,     0,     0,
       0,   169,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   183,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,     0,
     165,     0,     0,     0,     0,   166,   167,     0,   168,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,    55,     0,     0,   103,     0,     0,     0,
       0,   169,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   183,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,   164,     0,
     165,     0,     0,     0,     0,   166,   167,     0,   168,   101,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   103,     0,     0,     0,
       0,   169,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,   354,   142,
       0,     0,   103,     0,     0,     0,     0,     0,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,   101,
       0,     0,   110,   111,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,     0,     0,     0,
       0,     0,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,   142,
       0,     0,   103,     0,     0,     0,     0,     0,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,   101,
       0,     0,   110,   111,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   267,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   103,   288,     0,     0,     0,     0,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,   101,
       0,     0,   110,   111,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   312,   103,     0,     0,     0,
       0,     0,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,   169,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,   101,
       0,     0,   110,   111,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   350,   103,     0,     0,     0,
       0,     0,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   103,   368,     0,     0,     0,     0,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,   101,
       0,     0,   110,   111,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,   104,   105,   106,   101,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
      49,     0,   193,     0,     3,     0,     0,     0,   104,   105,
     106,     0,     0,   107,     0,     4,   108,   109,     0,   101,
       0,     6,   110,   111,     7,     8,     9,     0,    11,    12,
      13,    14,     0,    16,    54,    18,    19,    20,     0,     0,
       0,     0,     0,     0,    49,     0,   103,     2,     3,     0,
       0,     0,   104,   105,   106,     0,     0,   107,     0,     4,
     108,   109,     5,     0,     0,     6,   110,   111,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       1,  -231,     0,     2,     3,     0,     0,   -93,     0,   -93,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
      74,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    49,     0,
       0,     2,     3,     0,     0,     0,     0,     0,   223,     0,
     224,   314,     0,     4,     0,     0,     5,     0,    22,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     1,     0,     0,     2,
       3,     0,     0,     0,     0,     0,   223,     0,   283,   314,
       0,     4,     0,     0,     5,     0,    22,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,    21,     2,     3,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   130,     0,     0,     2,     3,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      49,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    49,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,   352,     0,     4,     0,     0,     5,     0,     0,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    49,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    49,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    49,     0,     0,     0,     3,     0,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,    49,     0,     6,     0,     3,     7,     8,     9,     0,
      11,    12,    13,    14,     0,    16,     4,    18,    19,    20,
       0,     0,     6,     0,     0,     7,     8,     9,   150,    11,
      12,    13,    14,     0,    16,     0,    18,    19,    20,    49,
       0,     0,     2,     3,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    60,    60,    74,    22,    61,     0,    21,    33,   162,
      24,   142,   103,    86,   103,   264,    11,    79,    11,   138,
      11,    57,    11,   132,   177,    25,    44,   226,    64,    57,
      30,   184,   116,   152,    11,    35,    64,    11,    11,    52,
     159,    35,   101,    57,    59,    64,    61,    66,    59,    11,
      61,   110,   111,    22,    69,    31,    80,   116,    72,     0,
      84,    61,    58,    58,    77,    59,    79,    81,    61,    58,
      61,   142,    48,    66,    65,    44,    69,   168,    69,   138,
     138,    75,   191,    52,    61,   284,   335,   149,    61,    11,
     103,    65,    69,   152,   152,    26,   187,    59,   187,    61,
     159,   159,   193,   256,   223,   196,    11,    69,    77,   262,
      79,    87,    88,   186,   132,    78,    79,    48,   132,   203,
     204,   205,    62,    57,    87,    88,   197,   280,    60,   220,
      64,    97,    64,    99,   103,   254,   149,    59,    69,    61,
      31,    69,    70,    71,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    11,   221,    66,   223,   223,    77,    62,    59,    64,
      67,    68,   263,   191,   187,   266,    57,   330,   249,    64,
     149,    66,   176,    58,    75,    76,    58,   210,   211,   212,
     213,   185,   186,   324,    77,   254,   254,    74,   269,   318,
      73,   226,   286,    85,    86,   358,   224,    72,   361,    59,
     224,    61,    62,    83,    64,   368,    66,   370,   187,    69,
     373,    64,   375,    66,   224,    60,    62,   286,    64,    59,
     230,    61,    59,    63,    61,    64,    62,    66,   252,    59,
      62,    61,    64,    64,    62,   336,    64,    62,    62,    64,
      64,    81,    82,   324,    62,    62,    64,    64,    11,   318,
     318,    65,   256,   319,    66,   283,   357,    66,   359,    64,
      65,   101,   208,   209,   345,    11,   206,   207,    14,    15,
      66,   214,   215,   283,   176,   177,    65,   346,   346,    61,
      26,    61,    61,    29,    57,    66,    32,    65,    62,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    11,    11,    11,    65,    31,     1,   319,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    66,
      61,    14,    15,    62,    17,    18,    19,    20,    21,    22,
      23,    60,    25,    26,    62,    62,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   102,    61,    60,    62,
      24,    66,   216,   218,    57,    58,   217,   219,    61,    65,
     140,   221,    72,    66,    67,    68,    69,   187,    77,    72,
     252,   230,    75,    76,    35,    -1,    -1,    -1,    81,    82,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      81,    82,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    82,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    77,
      25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    -1,    44,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,
      -1,    -1,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      11,    -1,    61,    -1,    15,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    26,    75,    76,    -1,    34,
      -1,    32,    81,    82,    35,    36,    37,    -1,    39,    40,
      41,    42,    -1,    44,     1,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    61,    14,    15,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    26,
      75,    76,    29,    -1,    -1,    32,    81,    82,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    58,    -1,    14,    15,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      77,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      61,    62,    -1,    26,    -1,    -1,    29,    -1,    69,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,
      -1,    26,    -1,    -1,    29,    -1,    69,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    61,    14,    15,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    26,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    11,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    11,    -1,    32,    -1,    15,    35,    36,    37,    -1,
      39,    40,    41,    42,    -1,    44,    26,    46,    47,    48,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    57,    39,
      40,    41,    42,    -1,    44,    -1,    46,    47,    48,    11,
      -1,    -1,    14,    15,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
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
     142,   143,   144,   145,   171,   172,   173,   174,    11,    58,
      11,   143,   142,   145,   146,    66,   128,   129,   143,    11,
     127,    11,    58,   127,     1,    58,   126,   127,   158,   164,
      59,    61,   144,     0,   173,    58,    11,   140,   141,    62,
     142,   145,    64,    66,    77,   164,   175,    58,   131,   134,
     135,   136,   142,    66,    57,   159,   160,   161,   162,   143,
     126,   158,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    34,    60,    61,    67,    68,    69,    72,    75,    76,
      81,    82,   104,   105,   106,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   125,
      11,    62,   127,   147,   148,   149,   150,   140,    77,    57,
      64,   129,    58,   108,   121,   122,   154,   158,   158,   134,
      57,   135,    65,   137,   138,   143,     1,    11,    17,    18,
      19,    20,    21,    22,    23,    25,    30,    31,    33,    66,
     122,   124,   156,   157,   158,   163,   164,   165,   166,   167,
     169,   170,     1,    11,   165,   164,   164,    61,   108,    11,
     124,   136,   151,    61,   108,   108,    59,    61,    63,    81,
      82,   101,   110,    69,    70,    71,    67,    68,    97,    99,
      78,    79,    87,    88,    85,    86,    72,    74,    73,    83,
      80,    84,    60,    59,    61,   143,   145,   152,   153,    62,
      64,    62,    64,    57,   125,   141,   154,   155,    77,    89,
      90,    91,    92,    93,    94,    95,    96,    98,   100,   123,
      57,   125,    64,    66,    65,    66,    65,    66,   125,    66,
      11,   156,    65,    61,    61,   168,    61,    66,   124,    64,
      66,    57,   126,   163,   156,   163,    66,    57,   156,    57,
     165,   151,    62,    61,   145,   152,    62,   124,    62,   107,
     122,    11,    11,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   116,   117,   118,
     124,   119,    60,   125,    62,   147,   152,   153,    59,    61,
     102,   149,    11,    57,    64,   122,   138,   125,   126,   156,
      65,    66,    31,   156,   124,   166,    61,   124,    66,   122,
      57,    62,   110,    60,    62,    64,    65,    60,    62,    62,
      60,   125,    62,   147,    57,   154,   156,    61,    62,   166,
     124,    62,   122,   121,    60,    62,   124,   156,    62,   124,
      62,   156,    62,    24,   156,    62,   156,    66,   156,   156
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
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   135,
     136,   136,   137,   137,   138,   138,   138,   139,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   144,   144,   144,   144,   145,   145,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   154,   155,   155,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   157,
     158,   159,   158,   160,   158,   161,   158,   162,   158,   163,
     163,   163,   163,   164,   164,   164,   165,   165,   165,   166,
     166,   167,   167,   168,   167,   169,   169,   169,   169,   170,
     170,   170,   170,   170,   171,   172,   172,   172,   173,   173,
     174,   175,   174,   174,   174
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
       1,     1,     3,     1,     2,     3,     1,     2,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       1,     1,     1,     3,     1,     2,     3,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     1,     2,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     4,     3,
       2,     0,     4,     0,     4,     0,     4,     0,     5,     2,
       2,     1,     1,     1,     2,     2,     1,     2,     2,     1,
       2,     5,     7,     0,     6,     5,     7,     6,     7,     3,
       2,     2,     2,     3,     1,     1,     2,     0,     1,     1,
       4,     0,     4,     3,     2
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
#line 76 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "int", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1916 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 82 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "float", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1926 "parser.tab.c"
    break;

  case 4: /* constant: EXP_LITERAL  */
#line 87 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "exp", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1932 "parser.tab.c"
    break;

  case 5: /* constant: HEXA_LITERAL  */
#line 88 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "hexa", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1938 "parser.tab.c"
    break;

  case 6: /* constant: REAL_LITERAL  */
#line 89 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "real", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1944 "parser.tab.c"
    break;

  case 7: /* constant: STRING_LITERAL  */
#line 91 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char*", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        (yyval.symbol_info)->str_val=(yyvsp[0].symbol_info)->str_val;
        (yyval.symbol_info)->place=qid((yyvsp[0].symbol_info)->str_val,nullptr);
        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->str_val;
	}
#line 1955 "parser.tab.c"
    break;

  case 8: /* constant: OCTAL_LITERAL  */
#line 97 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "octal", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1961 "parser.tab.c"
    break;

  case 9: /* constant: CHARACTER_LITERAL  */
#line 99 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        string tempp = "'";
        tempp+=(*(char*)((yyvsp[0].symbol_info)->ptr));
        tempp+='\'';
		(yyval.symbol_info)->place=qid(tempp,nullptr);
		(yyval.symbol_info)->code=tempp;
	}
#line 1974 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 111 "src/parser.y"
        {
            symbol_info* new_symbol = new symbol_info((yyvsp[0].str));
            (yyval.symbol_info) = new_symbol;
            
			//3AC code
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].str), curr_scope);
			if(find_symbol==nullptr){
                error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+(yyvsp[0].str));
			}
			else{
				(yyval.symbol_info)->place=qid((yyvsp[0].str),find_symbol);
				(yyval.symbol_info)->code="";
				(yyval.symbol_info)->type=find_symbol->type;
				(yyval.symbol_info)->is_array=find_symbol->is_array;
			}
        }
#line 1995 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 128 "src/parser.y"
        {
		(yyval.symbol_info) = (yyvsp[0].symbol_info);
	}
#line 2003 "parser.tab.c"
    break;

  case 13: /* primary_expression: LPARENTHESES expression RPARENTHESES  */
#line 133 "src/parser.y"
        {
		symbol_info* new_symbol = new symbol_info();
		new_symbol->place=newtemp((yyvsp[-1].symbol_info)->type,curr_scope);
		new_symbol->type=(yyvsp[-1].symbol_info)->type;
		// debug("here ",new_symbol->place.first);
		new_symbol->code=(yyvsp[-1].symbol_info)->code+"\n"+new_symbol->place.first+":= ("+(yyvsp[-1].symbol_info)->place.first+")";
		(yyval.symbol_info)=new_symbol;
	}
#line 2016 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 145 "src/parser.y"
        {
            (yyval.symbol_info)=(yyvsp[0].symbol_info);
        }
#line 2024 "parser.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 149 "src/parser.y"
        {
		string array_name=(yyvsp[-3].symbol_info)->name;
		symbol_info* find_symbol = lookup_symbol_global(array_name, curr_scope);
		if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+array_name);
		}
		else{
			if(find_symbol->is_array==false){
                error_list.push_back("Line "+to_string(yylineno)+" : Not an array "+array_name);
			}
			else{
                string code=(yyvsp[-1].symbol_info)->code;
                qid temp=newtemp(find_symbol->type,curr_scope);
                if(find_symbol->type=="int"){
					code=code+"\n"+temp.first+":= "+"4 * "+(yyvsp[-1].symbol_info)->place.first;
				}
				else if(find_symbol->type=="float"){
					code=code+"\n"+temp.first+":= "+"4 * "+(yyvsp[-1].symbol_info)->place.first;
				}
				else if(find_symbol->type=="char"){
					code=code+"\n"+temp.first+":= "+"2 * "+(yyvsp[-1].symbol_info)->place.first;
				}

                qid temp2=newtemp(find_symbol->type,curr_scope);
                code=code+"\n"+temp2.first+":= *("+(yyvsp[-3].symbol_info)->place.first+" + "+temp.first+")";
                (yyval.symbol_info)->code=code;
                (yyval.symbol_info)->place.first=temp2.first;
			}
			
		}
	}
#line 2060 "parser.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression LPARENTHESES RPARENTHESES  */
#line 181 "src/parser.y"
    {
        symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
        if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared function "+(yyvsp[-2].symbol_info)->name);
        }
        else{
            std::vector<std::string> original_list=find_symbol->param_types;
            if((yyvsp[-2].symbol_info)->name=="printf"){
                    error_list.push_back("Line "+to_string(yylineno)+" : Empty printf statement");
				}
                else if( (yyvsp[-2].symbol_info)->name=="scanf"){error_list.push_back("Line "+to_string(yylineno)+" : Empty scanf statement");}
                else if((yyvsp[-2].symbol_info)->name=="sizeof"){error_list.push_back("Line "+to_string(yylineno)+" : Sizeof operator cannot be used with function call");}
                else if(original_list.size()>0)
                {
                    error_list.push_back("Line "+to_string(yylineno)+" : Size of actual and formal parameter list does not match");
                }
        }
            qid temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
            if(find_symbol->type!="void"){
                (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + temp.first+":= CALL "+(yyvsp[-2].symbol_info)->place.first + "\n";
                (yyval.symbol_info)->place=temp;
                (yyval.symbol_info)->type=find_symbol->type;
            }
            else{
                (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "CALL "+(yyvsp[-2].symbol_info)->place.first + "\n";
                (yyval.symbol_info)->type=find_symbol->type;
            }
			
    }
#line 2094 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 211 "src/parser.y"
            {
            (yyval.symbol_info) = new symbol_info();
			symbol_info* find_symbol = lookup_symbol_global((yyvsp[-3].symbol_info)->name, curr_scope);
			if(find_symbol == nullptr) {
                error_list.push_back("Line "+to_string(yylineno)+" : Undeclared function "+(yyvsp[-3].symbol_info)->name);
			}
			else{
		  		std::vector<std::string> original_list=find_symbol->param_types;
				std::vector<std::string> new_list=(yyvsp[-1].symbol_info)->param_types;

				if((yyvsp[-3].symbol_info)->name!="printf" && (yyvsp[-3].symbol_info)->name!="scanf" && original_list.size()!=new_list.size()){
                    error_list.push_back("Line "+to_string(yylineno)+" : Size of actual and formal parameter list does not match");
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
            if(find_symbol->type!="void"){
                // debug("idhar",$1->code);   
                (yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code + "\n"+ (yyvsp[-1].symbol_info)->code + "\n"+ middle + temp.first+":= CALL "+(yyvsp[-3].symbol_info)->place.first + ","+to_string((yyvsp[-1].symbol_info)->param_list.size()) + "\n";
                (yyval.symbol_info)->place=temp;
                (yyval.symbol_info)->type=find_symbol->type;
            }else{
                (yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code + "\n"+ (yyvsp[-1].symbol_info)->code + "\n"+middle + "CALL "+(yyvsp[-3].symbol_info)->place.first + ","+to_string((yyvsp[-1].symbol_info)->param_list.size()) + "\n";
                (yyval.symbol_info)->type=find_symbol->type;
            }
        }
#line 2137 "parser.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DOT ID  */
#line 250 "src/parser.y"
        {
		symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
		if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+(yyvsp[-2].symbol_info)->name);
		}
		else{
			if((find_symbol->type).substr(0,6)=="struct"){
				symbol_info* find_struct;
				if((find_symbol->type).substr(0,6)=="struct") find_struct=lookup_symbol_global((find_symbol->type).substr(7), curr_scope);
				int flag=0;
				string var_type="";
				int offset=0;
				for(int i=0;i<find_struct->param_list.size();i++){
					if(find_struct->param_list[i]==(yyvsp[0].str)){
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
					offset+=get_size(find_struct->param_types[i]);

				}
				if(flag==0){
                    error_list.push_back("Line "+to_string(yylineno)+" : No such attribute found in struct or union "+(yyvsp[-2].symbol_info)->name);
				}
				else{
					parsing_stack.push((yyvsp[-2].symbol_info)->name);
					parsing_stack.push((yyvsp[0].str));
					parsing_stack.push(to_string(offset));
					parsing_stack.push(var_type);
					
					find_symbol->name=(yyvsp[-2].symbol_info)->name;
					(yyval.symbol_info)=find_symbol;
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
					if(find_struct->param_list[i]==(yyvsp[0].str)){
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
					// offset=max(offset,get_size(find_struct->param_types[i]));

				}
				if(flag==0){
                    error_list.push_back("Line "+to_string(yylineno)+" : No such attribute found in struct or union "+(yyvsp[-2].symbol_info)->name);
				}
				else{
					parsing_stack.push((yyvsp[-2].symbol_info)->name);
					parsing_stack.push((yyvsp[0].str));
					parsing_stack.push(to_string(offset));
					parsing_stack.push(var_type);
					
					find_symbol->name=(yyvsp[-2].symbol_info)->name;
					(yyval.symbol_info)=find_symbol;
				}
			}
			else{
                error_list.push_back("Line "+to_string(yylineno)+" : Not a struct or union "+(yyvsp[-2].symbol_info)->name);
			}
			
		}
	}
#line 2212 "parser.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression INCREMENT  */
#line 322 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"+1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"+1";
		
	}
#line 2225 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression DECREMENT  */
#line 331 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"-1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"-1";
	}
#line 2237 "parser.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 342 "src/parser.y"
    { 
		if((yyvsp[0].symbol_info)->place.first!=""){
			// debug("herrrr ", $1->code);
			(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->place.first);
		}
		else{
			if((yyvsp[0].symbol_info)->name==""){
				(yyval.symbol_info)=new symbol_info((yyvsp[0].symbol_info));
				(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
				if((yyvsp[0].symbol_info)->type=="int")(yyval.symbol_info)->param_list.push_back(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)));
				else if((yyvsp[0].symbol_info)->type=="float")(yyval.symbol_info)->param_list.push_back(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)));
				else if((yyvsp[0].symbol_info)->type=="char")(yyval.symbol_info)->param_list.push_back(std::to_string(*(char*)((yyvsp[0].symbol_info)->ptr)));
				else if((yyvsp[0].symbol_info)->type=="char*")(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->str_val);
			}
			else{
				symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope);
				if(find_symbol == nullptr) {
					error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+(yyvsp[0].symbol_info)->name);
				}
				else{
					(yyval.symbol_info)=new symbol_info(find_symbol);
					(yyval.symbol_info)->param_types.push_back(find_symbol->type);
					(yyval.symbol_info)->param_list.push_back(find_symbol->name);
				}
			} 
		}
        
      }
#line 2272 "parser.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 374 "src/parser.y"
        { 
			if((yyvsp[0].symbol_info)->place.first!=""){
				(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
				//debug("herrrrrrrrrrr ", $3->place.first);
				(yyval.symbol_info)->param_types.push_back((yyvsp[-2].symbol_info)->type);
				(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->place.first);
			}
			else{
				if((yyvsp[0].symbol_info)->name==""){
                (yyval.symbol_info)=new symbol_info((yyvsp[-2].symbol_info));
                //check 1 or 3
                (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
                if((yyvsp[0].symbol_info)->type=="int")(yyval.symbol_info)->param_list.push_back(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)));
                else if((yyvsp[0].symbol_info)->type=="float")(yyval.symbol_info)->param_list.push_back(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)));
                else if((yyvsp[0].symbol_info)->type=="char")(yyval.symbol_info)->param_list.push_back(std::to_string(*(char*)((yyvsp[0].symbol_info)->ptr)));
                else if((yyvsp[0].symbol_info)->type=="char*")(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->str_val);
            }
            else{
                symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope);
                if(find_symbol == nullptr) {
                    error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+(yyvsp[0].symbol_info)->name);
                }
                else{
                    (yyval.symbol_info)=new symbol_info((yyvsp[-2].symbol_info));
                    (yyval.symbol_info)->param_types.push_back(find_symbol->type);
                    (yyval.symbol_info)->param_list.push_back(find_symbol->name);
                }
            } 
			}
                      
        }
#line 2308 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 409 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);        
	}
#line 2316 "parser.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 415 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		string original_type=(yyvsp[0].symbol_info)->type;
		(yyval.symbol_info)=new_symbol;

		if((yyvsp[-1].symbol_info)->code=="&"){
			(yyval.symbol_info)->type=original_type+"*";
		}
        if((yyvsp[-1].symbol_info)->code=="*"){
            if(original_type.back()!='*') error_list.push_back("Line "+to_string(yylineno)+" : Trying to dereference non pointer "+(yyvsp[0].symbol_info)->name);
            else{
				(yyval.symbol_info)->type=original_type;
				(yyval.symbol_info)->type.pop_back();
			}
        }
		
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place.first=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
	}
#line 2341 "parser.tab.c"
    break;

  case 30: /* unary_operator: AMPERSAND  */
#line 440 "src/parser.y"
                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="ampersand";
		(yyval.symbol_info)->code="&";
        (yyval.symbol_info)->pointer_depth++;
	}
#line 2353 "parser.tab.c"
    break;

  case 31: /* unary_operator: STAR  */
#line 448 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="star";
		(yyval.symbol_info)->code="*";
	}
#line 2364 "parser.tab.c"
    break;

  case 32: /* unary_operator: PLUS  */
#line 455 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="plus";
		(yyval.symbol_info)->code="+";
	}
#line 2375 "parser.tab.c"
    break;

  case 33: /* unary_operator: MINUS  */
#line 462 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="minus";
		(yyval.symbol_info)->code="-";
	}
#line 2386 "parser.tab.c"
    break;

  case 34: /* unary_operator: TILDE  */
#line 469 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="tilde";
		(yyval.symbol_info)->code="~";
	}
#line 2397 "parser.tab.c"
    break;

  case 35: /* unary_operator: EXCLAMATION  */
#line 476 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="exclamation";
		(yyval.symbol_info)->code="!";
	}
#line 2408 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 486 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2416 "parser.tab.c"
    break;

  case 37: /* cast_expression: LPARENTHESES type_name RPARENTHESES cast_expression  */
#line 490 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[0].symbol_info);
        (yyval.symbol_info)->type = (yyvsp[-2].symbol_info)->type;
    }
#line 2425 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 497 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2431 "parser.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 499 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2443 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 507 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2455 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 515 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : Modulo operator can only be used with int type");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"%"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2470 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 528 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2476 "parser.tab.c"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 530 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2488 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 538 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2500 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 548 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2506 "parser.tab.c"
    break;

  case 46: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 550 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : Left shift operator can only be used with int type");
        }
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2521 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 561 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : Right shift operator can only be used with int type");
        }
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">>"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2536 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 574 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2542 "parser.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 576 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2554 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 584 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];        
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2566 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression LESS_EQUALS shift_expression  */
#line 592 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	
	}
#line 2579 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER_EQUALS shift_expression  */
#line 601 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2591 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 611 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2597 "parser.tab.c"
    break;

  case 54: /* equality_expression: equality_expression REL_EQUALS relational_expression  */
#line 613 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"=="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2609 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression REL_NOT_EQ relational_expression  */
#line 621 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"!="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2621 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 631 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2627 "parser.tab.c"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 633 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : And operator can only be used with int type");
        }
    }
#line 2639 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 643 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2645 "parser.tab.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression XOR and_expression  */
#line 645 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : XOR operator can only be used with int type");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"^"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2660 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 658 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2666 "parser.tab.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression OR exclusive_or_expression  */
#line 660 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"|"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2681 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 673 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2687 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression REL_AND inclusive_or_expression  */
#line 675 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : AND operator can only be used with int type");
        }
        
    }
#line 2700 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 686 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2706 "parser.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression REL_OR logical_and_expression  */
#line 688 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
    }
#line 2718 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 698 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2724 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 703 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2730 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 705 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info();
        symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
        if(find_symbol != nullptr) {
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				if(parsing_stack.top()==(yyvsp[0].symbol_info)->type){
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
					find_struct->struct_attr_values.push_back((yyvsp[0].symbol_info));
                    //checkerror
					//3AC code kabhi toh karenge
					qid var=newtemp(find_symbol->type,curr_scope);
					string tempo="";
					tempo=tempo+(yyvsp[-2].symbol_info)->code;
					tempo=tempo+"\n"+(yyvsp[0].symbol_info)->code;
					tempo=tempo+"\n"+var.first+":= "+(yyvsp[-2].symbol_info)->place.first+"+"+offset;
					tempo=tempo+"\n*"+var.first+":= "+(yyvsp[0].symbol_info)->place.first;
					(yyval.symbol_info)->code=(yyval.symbol_info)->code + tempo;
					(yyval.symbol_info)->place=var;	
				}
				else{
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment of struct or union attributes");
				}
			}
			else{
                if(find_symbol->type=="char*"){
                    error_list.push_back("Line "+to_string(yylineno)+" : char* is not modifiable");
                }
                if(min(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])==0 && (yyvsp[-2].symbol_info)->type!=(yyvsp[0].symbol_info)->type){
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment");
                }
                if(type_priority[(yyvsp[-2].symbol_info)->type]<type_priority[(yyvsp[0].symbol_info)->type]){
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment");
                }
                string third_code=(yyvsp[0].symbol_info)->code;
                string first_code=(yyvsp[-2].symbol_info)->code;
                if(min(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[find_symbol->type])>0) find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[(yyvsp[0].symbol_info)->type])];
				
                find_symbol->name=(yyvsp[-2].symbol_info)->name;
                find_symbol->place=(yyvsp[-2].symbol_info)->place;
                find_symbol->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;

                //3AC code
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
						for(int i=0;i<count_init_starr-1;i++){
							code=code+"\n"+temp.first+":= *"+prev;
							prev=temp.first;
							temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
						}
						code=code+"\n"+"*"+prev+":= "+(yyvsp[0].symbol_info)->place.first;
						(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[0].symbol_info)->code+"\n"+code;
						(yyval.symbol_info)->place=temp;
					}
				}
				if((yyvsp[0].symbol_info)->place.first[0]=='*'){
					int count_init_starr=count_init_star((yyvsp[0].symbol_info)->place.first);
					if(count_init_starr>1){
						flag=1;
						string code="";
						qid temp=newtemp((yyvsp[0].symbol_info)->type,curr_scope);
						string prev=((yyvsp[0].symbol_info)->place.first).erase(0,count_init_starr);
						for(int i=0;i<count_init_starr-1;i++){
							code=code+"\n"+temp.first+":= *"+prev;
							prev=temp.first;
							temp=newtemp((yyvsp[0].symbol_info)->type,curr_scope);
						}
						code=code+"\n"+(yyvsp[-2].symbol_info)->place.first+":= *"+temp.first;
						(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[0].symbol_info)->code+"\n"+code;
						(yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
					}
				}
                if(flag==0){
                    if(find_symbol->is_array==true){
                        string code=remove_equal(first_code);
                        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+code+":= "+(yyvsp[0].symbol_info)->place.first+"\n";
                    }
                    else{
                        string op=(yyvsp[-1].symbol_info)->code;
                        string tcode=get_assignment_statement((yyvsp[-2].symbol_info)->place.first,op,(yyvsp[0].symbol_info)->place.first);
                        
                        if(tcode=="error"){
                            error_list.push_back("Line "+to_string(yylineno)+" : Invalid assignment operator");
                        }
                        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + third_code + "\n" + tcode+"\n";
                        (yyval.symbol_info)->place=(yyvsp[-2].symbol_info)->place;
                    }                   
				} 				
			}
			
		}
        else{
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared symbol "+(yyvsp[-2].symbol_info)->name);
		}             
    }
#line 2848 "parser.tab.c"
    break;

  case 70: /* assignment_operator: EQUALS  */
#line 821 "src/parser.y"
                 {(yyval.symbol_info)=new symbol_info("","equals",nullptr,0); (yyval.symbol_info)->code="=";}
#line 2854 "parser.tab.c"
    break;

  case 71: /* assignment_operator: ASSIGN_STAR  */
#line 822 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_star",nullptr,0); (yyval.symbol_info)->code="*=";}
#line 2860 "parser.tab.c"
    break;

  case 72: /* assignment_operator: ASSIGN_DIV  */
#line 823 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_div",nullptr,0); (yyval.symbol_info)->code="/=";}
#line 2866 "parser.tab.c"
    break;

  case 73: /* assignment_operator: ASSIGN_MOD  */
#line 824 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_mod",nullptr,0); (yyval.symbol_info)->code="%=";}
#line 2872 "parser.tab.c"
    break;

  case 74: /* assignment_operator: ASSIGN_PLUS  */
#line 825 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_plus",nullptr,0); (yyval.symbol_info)->code="+=";}
#line 2878 "parser.tab.c"
    break;

  case 75: /* assignment_operator: ASSIGN_MINUS  */
#line 826 "src/parser.y"
                       {(yyval.symbol_info)=new symbol_info("","assign_minus",nullptr,0); (yyval.symbol_info)->code="-=";}
#line 2884 "parser.tab.c"
    break;

  case 76: /* assignment_operator: LEFT_SHIFT_EQ  */
#line 827 "src/parser.y"
                        {(yyval.symbol_info)=new symbol_info("","left_shift_eq",nullptr,0); (yyval.symbol_info)->code="<<=";}
#line 2890 "parser.tab.c"
    break;

  case 77: /* assignment_operator: RIGHT_SHIFT_EQ  */
#line 828 "src/parser.y"
                         {(yyval.symbol_info)=new symbol_info("","right_shift_eq",nullptr,0); (yyval.symbol_info)->code=">>=";}
#line 2896 "parser.tab.c"
    break;

  case 78: /* assignment_operator: ASSIGN_AND  */
#line 829 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_and",nullptr,0); (yyval.symbol_info)->code="&=";}
#line 2902 "parser.tab.c"
    break;

  case 79: /* assignment_operator: ASSIGN_XOR  */
#line 830 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_xor",nullptr,0); (yyval.symbol_info)->code="^=";}
#line 2908 "parser.tab.c"
    break;

  case 80: /* assignment_operator: ASSIGN_OR  */
#line 831 "src/parser.y"
                    {(yyval.symbol_info)=new symbol_info("","assign_or",nullptr,0); (yyval.symbol_info)->code="|=";}
#line 2914 "parser.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 836 "src/parser.y"
        {
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2922 "parser.tab.c"
    break;

  case 82: /* expression: expression COMMA assignment_expression  */
#line 840 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 2930 "parser.tab.c"
    break;

  case 83: /* constant_expression: conditional_expression  */
#line 846 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2936 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 852 "src/parser.y"
    {
		if(std::string((yyvsp[-2].str)).substr(0, 7) == "typedef"){
			string new_type=parsing_stack.top();
			parsing_stack.pop();
			string old_type=std::string((yyvsp[-2].str)).substr(8);
			type_def_mapping[new_type]=old_type;
		}
		
		
		int flag=0;
		string code="";
		symbol_info* nsss=new symbol_info();
		(yyval.symbol_info)=nsss;
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

				if (type_priority[(yyvsp[-2].str)] < type_priority[curr_scope->symbol_map[top_symbol]->type]) {
					
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in declaration");
					flag = 1;
				}
				
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                if(type_priority[(yyvsp[-2].str)]>0 && type_priority[curr_scope->symbol_map[top_symbol]->type]>0) curr_scope->symbol_map[top_symbol]->type = priority_to_type[max(type_priority[(yyvsp[-2].str)], type_priority[curr_scope->symbol_map[top_symbol]->type])];
                
				// debug("declaration specifiers121 ", $2->code);

				
				code=(yyvsp[-1].symbol_info)->code;

			} else {
				curr_scope->symbol_map[top_symbol]->type = (yyvsp[-2].str);
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
				new_symbol = new symbol_info((yyvsp[-1].symbol_info));
				(yyval.symbol_info)=new_symbol;

			}
			
		}
		// debug("declaration specifiers ", to_string(parsing_stack.size()));
		(yyval.symbol_info)->code=code;
		
		//debug("Declaration: ",curr_scope->symbol_map["p"]->code);
    }
#line 3027 "parser.tab.c"
    break;

  case 87: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 944 "src/parser.y"
        {
		// debug("storage class specifier ", $1);
		// debug("storage class specifier ", $2);
		char* buf = (char*)malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 2); // 1 for comma, 1 for null terminator
		sprintf(buf, "%s,%s", (yyvsp[-1].str), (yyvsp[0].str));
		(yyval.str) = buf;
		// debug("storage class specifier ", $$);

	}
#line 3041 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 953 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 3047 "parser.tab.c"
    break;

  case 91: /* init_declarator_list: init_declarator  */
#line 959 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
    }
#line 3055 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 962 "src/parser.y"
                                                 { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->code = (yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
    }
#line 3064 "parser.tab.c"
    break;

  case 93: /* init_declarator: declarator  */
#line 969 "src/parser.y"
                 { 
		if(lookup_symbol_global((yyvsp[0].symbol_info)->name, curr_scope)!=nullptr){
            error_list.push_back("Line "+to_string(yylineno)+" : Redeclaration error "+(yyvsp[0].symbol_info)->name);
		}
        symbol_info* new_symbol = new symbol_info();
        new_symbol=(yyvsp[0].symbol_info);
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]=new_symbol;
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->name=(yyvsp[0].symbol_info)->name;
		if((yyvsp[0].symbol_info)->is_array==true){
			curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->is_array=true;
			curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->array_length=(yyvsp[0].symbol_info)->array_length;
			 if((yyvsp[0].symbol_info)->type=="int" || (yyvsp[0].symbol_info)->type=="float"){
				string code=(yyvsp[0].symbol_info)->name+":= alloc " +to_string(4*(yyvsp[0].symbol_info)->array_length);
				(yyval.symbol_info)->code=code;
			}
			else if((yyvsp[0].symbol_info)->type=="char"){
				string code=(yyvsp[0].symbol_info)->name+":= alloc " +to_string(2*(yyvsp[0].symbol_info)->array_length);
				(yyval.symbol_info)->code=code;
			} 
		}
		
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->type=(yyvsp[0].symbol_info)->type;
		
        (yyval.symbol_info) =new_symbol;
		
		parsing_stack.push((yyvsp[0].symbol_info)->name.c_str());
        pointer_info.push((yyvsp[0].symbol_info)->pointer_depth);
    }
#line 3097 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator EQUALS initializer  */
#line 997 "src/parser.y"
                                    { 
		if(lookup_symbol_local((yyvsp[-2].symbol_info)->name, curr_scope)!=nullptr){
            error_list.push_back("Line "+to_string(yylineno)+" : Redeclaration error "+(yyvsp[-2].symbol_info)->name);
		}
		
		curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=(yyvsp[0].symbol_info);
		parsing_stack.push((yyvsp[-2].symbol_info)->name.c_str());
        pointer_info.push((yyvsp[-2].symbol_info)->pointer_depth);

		if((yyvsp[-2].symbol_info)->is_array){
			if((yyvsp[0].symbol_info)->int_array.size() > (yyvsp[-2].symbol_info)->array_length){
                error_list.push_back("Line "+to_string(yylineno)+" : Array size mismatch "+(yyvsp[-2].symbol_info)->name);
			}
			else{
				(yyvsp[-2].symbol_info)->int_array = (yyvsp[0].symbol_info)->int_array;
				(yyvsp[-2].symbol_info)->type = (yyvsp[0].symbol_info)->type;
				curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]->is_array=true;
				 string code=(yyvsp[-2].symbol_info)->name+":= alloc ";
				if((yyvsp[-2].symbol_info)->type=="int" || (yyvsp[-2].symbol_info)->type=="float"){
					code=code+to_string(4*(yyvsp[-2].symbol_info)->array_length);
				}
				else if((yyvsp[-2].symbol_info)->type=="char"){
					code=code+to_string(2*(yyvsp[-2].symbol_info)->array_length);
				}
				for(int i=0;i<(yyvsp[-2].symbol_info)->array_length;i++){
					qid temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
					code=code+"\n"+temp.first+":= "+to_string(i)+"*";
					if((yyvsp[-2].symbol_info)->type=="int") code=code+"4\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+to_string(*(int*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="float") code=code+"4\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+to_string(*(float*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="char") code=code+"2\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+char(*(char*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="char*") code=code+"2\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+(yyvsp[-2].symbol_info)->int_array[i]->str_val;
				} 
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
		}
    }
#line 3147 "parser.tab.c"
    break;

  case 100: /* type_specifier: VOID  */
#line 1053 "src/parser.y"
                                        {(yyval.str)=strdup("void");}
#line 3153 "parser.tab.c"
    break;

  case 101: /* type_specifier: CHAR  */
#line 1054 "src/parser.y"
                                        {(yyval.str)=strdup("char");}
#line 3159 "parser.tab.c"
    break;

  case 102: /* type_specifier: SHORT  */
#line 1055 "src/parser.y"
                                        {(yyval.str)=strdup("short");}
#line 3165 "parser.tab.c"
    break;

  case 103: /* type_specifier: INT  */
#line 1056 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 3171 "parser.tab.c"
    break;

  case 104: /* type_specifier: LONG  */
#line 1057 "src/parser.y"
                                        {(yyval.str)=strdup("long");}
#line 3177 "parser.tab.c"
    break;

  case 105: /* type_specifier: FLOAT  */
#line 1058 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 3183 "parser.tab.c"
    break;

  case 106: /* type_specifier: DOUBLE  */
#line 1059 "src/parser.y"
                                        {(yyval.str)=strdup("double");}
#line 3189 "parser.tab.c"
    break;

  case 107: /* type_specifier: SIGNED  */
#line 1060 "src/parser.y"
                                        {(yyval.str)=strdup("signed");}
#line 3195 "parser.tab.c"
    break;

  case 108: /* type_specifier: UNSIGNED  */
#line 1061 "src/parser.y"
                                        {(yyval.str)=strdup("unsigned");}
#line 3201 "parser.tab.c"
    break;

  case 109: /* type_specifier: struct_or_union_specifier  */
#line 1062 "src/parser.y"
                                    {(yyval.str)=(yyvsp[0].str);}
#line 3207 "parser.tab.c"
    break;

  case 111: /* type_specifier: ID  */
#line 1064 "src/parser.y"
             {
		if(type_def_mapping.find((yyvsp[0].str)) != type_def_mapping.end()){
			(yyval.str)=strdup(type_def_mapping[(yyvsp[0].str)].c_str());
		}
		else{
			error_list.push_back("Line "+to_string(yylineno)+" : Typedef error "+(yyvsp[0].str));
		}
	}
#line 3220 "parser.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 1076 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type = (yyvsp[-4].str);
		new_symbol->param_list = (yyvsp[-1].symbol_info)->param_list;
		new_symbol->param_types = (yyvsp[-1].symbol_info)->param_types;
		curr_scope->symbol_map[(yyvsp[-3].str)]=new_symbol;
	}
#line 3232 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID  */
#line 1085 "src/parser.y"
        {
		symbol_info* find_symbol = lookup_symbol_global((yyvsp[0].str), curr_scope);
		if (find_symbol != nullptr) {
			if (find_symbol->type == "struct" || find_symbol->type == "union") {
				std::string temp = std::string((yyvsp[-1].str)) + " " + std::string((yyvsp[0].str));
				(yyval.str) = strdup(temp.c_str());
			} else {
                error_list.push_back("Line "+to_string(yylineno)+" : Variable not of type struct or union");
			}
		} else {
            error_list.push_back("Line "+to_string(yylineno)+" : Struct or Union not declared "+(yyvsp[0].str));
		}
	}
#line 3250 "parser.tab.c"
    break;

  case 115: /* struct_or_union: STRUCT  */
#line 1101 "src/parser.y"
                 {(yyval.str)=strdup("struct");}
#line 3256 "parser.tab.c"
    break;

  case 116: /* struct_or_union: UNION  */
#line 1102 "src/parser.y"
                {(yyval.str)=strdup("union");}
#line 3262 "parser.tab.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration  */
#line 1106 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3268 "parser.tab.c"
    break;

  case 118: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1108 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(int i=0;i<(yyvsp[0].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->param_list[i]);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->param_types[i]);
		}
		
	}
#line 3281 "parser.tab.c"
    break;

  case 119: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 1120 "src/parser.y"
        { 
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(auto it: (yyvsp[-1].symbol_info)->param_list)
					{
						//cerr<<it<<endl;
						symbol_info* x=new symbol_info();
						x->type = (yyvsp[-2].str);
						
						curr_scope->symbol_map[it]=x;
						(yyval.symbol_info)->param_types.push_back((yyvsp[-2].str));
					}
		
		

	}
#line 3301 "parser.tab.c"
    break;

  case 122: /* struct_declarator_list: struct_declarator  */
#line 1144 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3310 "parser.tab.c"
    break;

  case 123: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 1149 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3319 "parser.tab.c"
    break;

  case 124: /* struct_declarator: declarator  */
#line 1156 "src/parser.y"
                         {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3325 "parser.tab.c"
    break;

  case 136: /* declarator: pointer direct_declarator  */
#line 1183 "src/parser.y"
                                { 
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
        (yyval.symbol_info)->pointer_depth=(yyvsp[-1].symbol_info)->pointer_depth;
    }
#line 3334 "parser.tab.c"
    break;

  case 137: /* declarator: direct_declarator  */
#line 1187 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info); 
    }
#line 3342 "parser.tab.c"
    break;

  case 138: /* direct_declarator: ID  */
#line 1194 "src/parser.y"
        {
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);
		x->place.first=(yyvsp[0].str);
		(yyval.symbol_info)=x;
	}
#line 3353 "parser.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator LBRACKET constant_expression RBRACKET  */
#line 1202 "src/parser.y"
    {
        (yyval.symbol_info)->is_array = true;
        if((yyvsp[-1].symbol_info)->type=="int"){
            (yyval.symbol_info)->array_length = *(int*)((yyvsp[-1].symbol_info)->ptr);
        }
        else{
            error_list.push_back("Line "+to_string(yylineno)+" : Array size not an integer "+(yyvsp[-3].symbol_info)->name);
            (yyval.symbol_info)->array_length=100;
        }
    }
#line 3368 "parser.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 1213 "src/parser.y"
    {
        (yyval.symbol_info)->is_array = true, (yyval.symbol_info)->array_length = 100;
    }
#line 3376 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LPARENTHESES parameter_type_list RPARENTHESES  */
#line 1217 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type=(yyvsp[-3].symbol_info)->type;
		new_symbol->parameter_no=(yyvsp[-1].symbol_info)->parameter_no;
		new_symbol->param_types=(yyvsp[-1].symbol_info)->param_types;
		new_symbol->param_list=(yyvsp[-1].symbol_info)->param_list;
		new_symbol->is_param_list=(yyvsp[-1].symbol_info)->is_param_list;
		new_symbol->name=(yyvsp[-3].symbol_info)->name;
		curr_scope->symbol_map[(yyvsp[-3].symbol_info)->name]=new_symbol;

		(yyval.symbol_info)=new_symbol;
	}
#line 3393 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LPARENTHESES RPARENTHESES  */
#line 1231 "src/parser.y"
        {
        symbol_info* new_symbol=new symbol_info();      
        new_symbol->type=(yyvsp[-2].symbol_info)->type;
        new_symbol->parameter_no=0;
        new_symbol->param_types={}; 
        new_symbol->param_list={};
        new_symbol->name=(yyvsp[-2].symbol_info)->name;
        new_symbol->is_param_list=false;
        curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]=new_symbol;
        (yyval.symbol_info)=new_symbol;
	}
#line 3409 "parser.tab.c"
    break;

  case 145: /* pointer: STAR  */
#line 1245 "src/parser.y"
               {(yyval.symbol_info)=new symbol_info(); (yyval.symbol_info)->pointer_depth=1;}
#line 3415 "parser.tab.c"
    break;

  case 147: /* pointer: STAR pointer  */
#line 1247 "src/parser.y"
                       {(yyval.symbol_info)=(yyvsp[0].symbol_info); (yyval.symbol_info)->pointer_depth++;}
#line 3421 "parser.tab.c"
    break;

  case 151: /* parameter_type_list: parameter_list  */
#line 1259 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)->parameter_no=(yyvsp[0].symbol_info)->parameter_no;
		(yyval.symbol_info)->is_param_list=(yyvsp[0].symbol_info)->is_param_list;
		(yyval.symbol_info)->param_types=(yyvsp[0].symbol_info)->param_types;
		(yyval.symbol_info)->param_list=(yyvsp[0].symbol_info)->param_list;
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		
	}
#line 3435 "parser.tab.c"
    break;

  case 153: /* parameter_list: parameter_declaration  */
#line 1273 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=1;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3446 "parser.tab.c"
    break;

  case 154: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1280 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=(yyvsp[-2].symbol_info)->parameter_no+(yyvsp[0].symbol_info)->parameter_no;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3457 "parser.tab.c"
    break;

  case 155: /* parameter_declaration: declaration_specifiers declarator  */
#line 1291 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->parameter_no=1;
	}
#line 3469 "parser.tab.c"
    break;

  case 156: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1298 "src/parser.y"
                                                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
	}
#line 3480 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers  */
#line 1304 "src/parser.y"
                                {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[0].str);
		(yyval.symbol_info)->name="";
	}
#line 3491 "parser.tab.c"
    break;

  case 174: /* initializer: assignment_expression  */
#line 1341 "src/parser.y"
                                {
		(yyvsp[0].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3500 "parser.tab.c"
    break;

  case 175: /* initializer: LBRACE initializer_list RBRACE  */
#line 1345 "src/parser.y"
                                         {(yyval.symbol_info) = (yyvsp[-1].symbol_info);}
#line 3506 "parser.tab.c"
    break;

  case 176: /* initializer: LBRACE initializer_list COMMA RBRACE  */
#line 1346 "src/parser.y"
                                               {(yyval.symbol_info) = (yyvsp[-2].symbol_info);}
#line 3512 "parser.tab.c"
    break;

  case 177: /* initializer_list: initializer  */
#line 1350 "src/parser.y"
                      {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 3518 "parser.tab.c"
    break;

  case 178: /* initializer_list: initializer_list COMMA initializer  */
#line 1351 "src/parser.y"
                                             {
		if((yyvsp[-2].symbol_info)->type != (yyvsp[0].symbol_info)->type){
            error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in initializer list");
		}
		else{
			(yyvsp[-2].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		}
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
	}
#line 3532 "parser.tab.c"
    break;

  case 179: /* statement: labeled_statement  */
#line 1364 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);

	}
#line 3541 "parser.tab.c"
    break;

  case 180: /* statement: compound_statement  */
#line 1369 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3549 "parser.tab.c"
    break;

  case 181: /* statement: expression_statement  */
#line 1373 "src/parser.y"
    {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3557 "parser.tab.c"
    break;

  case 182: /* statement: selection_statement  */
#line 1376 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3563 "parser.tab.c"
    break;

  case 183: /* statement: iteration_statement  */
#line 1377 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3569 "parser.tab.c"
    break;

  case 184: /* statement: jump_statement  */
#line 1378 "src/parser.y"
                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3575 "parser.tab.c"
    break;

  case 185: /* labeled_statement: ID COLON statement  */
#line 1384 "src/parser.y"
        {
		if(lookup_symbol_global((yyvsp[-2].str), curr_scope)!=nullptr){
			error_list.push_back("Line "+to_string(yylineno)+" : Label Redeclaration error "+(yyvsp[-2].str));
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			(yyval.symbol_info)=new_symbol;
			if(goto_list.find((yyvsp[-2].str))!=goto_list.end()){
				
				string label=goto_list[(yyvsp[-2].str)];
				// debug("labellllll", $3->code);
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				// debug("label", $$->code);
			}
			else{
				//debug("labellllll", $3->code);
				string label=newlabel();
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				
				goto_list[(yyvsp[-2].str)]=label;
			}
			curr_scope->symbol_map[(yyvsp[-2].str)]=new symbol_info();
			curr_scope->symbol_map[(yyvsp[-2].str)]->name=(yyvsp[-2].str);
			curr_scope->symbol_map[(yyvsp[-2].str)]->type="label";
		}
	}
#line 3606 "parser.tab.c"
    break;

  case 186: /* labeled_statement: ID COLON declaration  */
#line 1411 "src/parser.y"
        {
		
		if(lookup_symbol_global((yyvsp[-2].str), curr_scope)!=nullptr){
			error_list.push_back("Line "+to_string(yylineno)+" : Label Redeclaration error "+(yyvsp[-2].str));
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			(yyval.symbol_info)=new_symbol;
			if(goto_list.find((yyvsp[-2].str))!=goto_list.end()){
				
				string label=goto_list[(yyvsp[-2].str)];
				// debug("labellllll", $3->code);
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				// debug("label", $$->code);
			}
			else{
				//debug("labellllll", $3->code);
				string label=newlabel();
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				
				goto_list[(yyvsp[-2].str)]=label;
			}
			curr_scope->symbol_map[(yyvsp[-2].str)]=new symbol_info();
			curr_scope->symbol_map[(yyvsp[-2].str)]->name=(yyvsp[-2].str);
			curr_scope->symbol_map[(yyvsp[-2].str)]->type="label";
		}
	}
#line 3638 "parser.tab.c"
    break;

  case 188: /* labeled_statement: CASE constant_expression COLON statement  */
#line 1440 "src/parser.y"
        {
		string label=newlabel();
		(yyval.symbol_info)->code = label +":\n"+ (yyvsp[0].symbol_info)->code;
		case_list.top().push({(yyvsp[-2].symbol_info)->code,label});
		
	}
#line 3649 "parser.tab.c"
    break;

  case 189: /* labeled_statement: DEFAULT COLON statement  */
#line 1447 "src/parser.y"
        {
		string label=newlabel();
		case_list.top().push({"default",label});
		(yyval.symbol_info)->code = label+":\n"+ (yyvsp[0].symbol_info)->code;

	}
#line 3660 "parser.tab.c"
    break;

  case 191: /* $@1: %empty  */
#line 1458 "src/parser.y"
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
#line 3675 "parser.tab.c"
    break;

  case 192: /* compound_statement: LBRACE $@1 statement_declaration_list RBRACE  */
#line 1470 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[-1].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
	}
#line 3688 "parser.tab.c"
    break;

  case 193: /* $@2: %empty  */
#line 1478 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3694 "parser.tab.c"
    break;

  case 194: /* compound_statement: LBRACE $@2 statement_list RBRACE  */
#line 1478 "src/parser.y"
                                                                                     {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3703 "parser.tab.c"
    break;

  case 195: /* $@3: %empty  */
#line 1482 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3709 "parser.tab.c"
    break;

  case 196: /* compound_statement: LBRACE $@3 declaration_list RBRACE  */
#line 1482 "src/parser.y"
                                                                                       {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3718 "parser.tab.c"
    break;

  case 197: /* $@4: %empty  */
#line 1486 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3724 "parser.tab.c"
    break;

  case 198: /* compound_statement: LBRACE $@4 declaration_list statement_list RBRACE  */
#line 1486 "src/parser.y"
                                                                                                      {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3732 "parser.tab.c"
    break;

  case 199: /* statement_declaration_list: statement_list statement_declaration_list  */
#line 1493 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		
        

	}
#line 3748 "parser.tab.c"
    break;

  case 200: /* statement_declaration_list: declaration_list statement_declaration_list  */
#line 1505 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		// $$->return_type=$2->return_type;
		
        
		
	}
#line 3763 "parser.tab.c"
    break;

  case 201: /* statement_declaration_list: statement_list  */
#line 1516 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		//dikkat badi hai
		// $$->return_type=$1->return_type;
	}
#line 3776 "parser.tab.c"
    break;

  case 202: /* statement_declaration_list: declaration_list  */
#line 1525 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3784 "parser.tab.c"
    break;

  case 203: /* declaration_list: declaration  */
#line 1532 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		//debug("declaration_list", $$->code);
	}
#line 3795 "parser.tab.c"
    break;

  case 204: /* declaration_list: declaration_list declaration  */
#line 1539 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 3803 "parser.tab.c"
    break;

  case 205: /* declaration_list: error SEMICOLON  */
#line 1542 "src/parser.y"
                          {yyerrok;}
#line 3809 "parser.tab.c"
    break;

  case 206: /* statement_list: statement  */
#line 1546 "src/parser.y"
                    { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3817 "parser.tab.c"
    break;

  case 207: /* statement_list: statement_list statement  */
#line 1550 "src/parser.y"
        {
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		
	}
#line 3829 "parser.tab.c"
    break;

  case 208: /* statement_list: error SEMICOLON  */
#line 1557 "src/parser.y"
                          {yyerrok;}
#line 3835 "parser.tab.c"
    break;

  case 210: /* expression_statement: expression SEMICOLON  */
#line 1562 "src/parser.y"
                                 {(yyval.symbol_info)=(yyvsp[-1].symbol_info);}
#line 3841 "parser.tab.c"
    break;

  case 211: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement  */
#line 1567 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+"if("+ (yyvsp[-2].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+falselabel+":\n";
	}
#line 3851 "parser.tab.c"
    break;

  case 212: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement ELSE statement  */
#line 1573 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+"if("+ (yyvsp[-4].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
	}
#line 3862 "parser.tab.c"
    break;

  case 213: /* $@5: %empty  */
#line 1579 "src/parser.y"
                {queue<std::pair<std::string, std::string>> q;
		case_list.push(q);
		}
#line 3870 "parser.tab.c"
    break;

  case 214: /* selection_statement: SWITCH $@5 LPARENTHESES expression RPARENTHESES statement  */
#line 1582 "src/parser.y"
        {
		string str="";
		while(!case_list.top().empty()){
			string label=case_list.top().front().second;
			string case_value=case_list.top().front().first;
			case_list.top().pop();
			if(case_value=="default")
			{
				str+="goto "+label+"\n";
			}
			else str+="if("+(yyvsp[-2].symbol_info)->place.first+"=="+case_value+") goto "+label+"\n";
		}
		string endlabel=newlabel();
		(yyval.symbol_info)->code= (yyvsp[-2].symbol_info)->code+"\n"+str+"\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel," ",1);
		case_list.pop();
	}
#line 3892 "parser.tab.c"
    break;

  case 215: /* iteration_statement: WHILE LPARENTHESES expression RPARENTHESES statement  */
#line 1603 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3906 "parser.tab.c"
    break;

  case 216: /* iteration_statement: DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON  */
#line 1613 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-5].symbol_info)->code+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3920 "parser.tab.c"
    break;

  case 217: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement  */
#line 1623 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3934 "parser.tab.c"
    break;

  case 218: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement  */
#line 1633 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		string updatelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-3].symbol_info)->code+"\n"+"if("+(yyvsp[-3].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+updatelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,updatelabel,0);

		}
#line 3951 "parser.tab.c"
    break;

  case 219: /* jump_statement: GOTO ID SEMICOLON  */
#line 1649 "src/parser.y"
        { 
		//idhar ID ko symtab me insert karna he
		if(goto_list.find((yyvsp[-1].str))==goto_list.end()){
			string label=newlabel();
			goto_list[(yyvsp[-1].str)]=label;
			symbol_info* new_symbol=new symbol_info();
			new_symbol->code="goto "+label+"\n";
			(yyval.symbol_info)=new_symbol;
		}
		else{
			symbol_info* new_symbol=new symbol_info();
			(yyval.symbol_info)=new_symbol;
			string label=goto_list[(yyvsp[-1].str)];
			(yyval.symbol_info)->code="goto "+label+"\n";
			// debug("goto", $$->code);
		}
		
		// debug("goto1111 ",new_symbol->code);
		
		
		// cerr << "goto\n";
	}
#line 3978 "parser.tab.c"
    break;

  case 220: /* jump_statement: CONTINUE SEMICOLON  */
#line 1672 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_continue=true;
		(yyval.symbol_info)->code="\n continue \n";
	}
#line 3989 "parser.tab.c"
    break;

  case 221: /* jump_statement: BREAK SEMICOLON  */
#line 1679 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_break=true;
		(yyval.symbol_info)->code="\n break \n";
	}
#line 4000 "parser.tab.c"
    break;

  case 222: /* jump_statement: RETURN SEMICOLON  */
#line 1686 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type="void";
		(yyval.symbol_info)->code="\nRETURN\n";
	}
#line 4012 "parser.tab.c"
    break;

  case 223: /* jump_statement: RETURN expression SEMICOLON  */
#line 1694 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\nRETURN "+(yyvsp[-1].symbol_info)->place.first+"\n";
		//debug("return ",$$->code);
	}
#line 4025 "parser.tab.c"
    break;

  case 224: /* start_symbol: translation_unit  */
#line 1705 "src/parser.y"
{
	//cerr<<"-----------------"<<endl<<$1->code<<"----------------"<<endl;
    
	print_errors();
	cleanTAC((yyvsp[0].symbol_info)->code);
}
#line 4036 "parser.tab.c"
    break;

  case 225: /* translation_unit: external_declaration  */
#line 1714 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
	}
#line 4044 "parser.tab.c"
    break;

  case 226: /* translation_unit: translation_unit external_declaration  */
#line 1718 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->code;
	}
#line 4052 "parser.tab.c"
    break;

  case 228: /* external_declaration: function_definition  */
#line 1726 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 4060 "parser.tab.c"
    break;

  case 231: /* $@6: %empty  */
#line 1735 "src/parser.y"
        {
		var_name=(yyvsp[0].symbol_info)->param_list;
		type_list=(yyvsp[0].symbol_info)->param_types;
        curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->type=(yyvsp[-1].str);
	}
#line 4070 "parser.tab.c"
    break;

  case 232: /* function_definition: declaration_specifiers declarator $@6 compound_statement  */
#line 1741 "src/parser.y"
        {
        if(strcmp((yyvsp[-3].str),"void")==0){
		
			// if($4->return_type!="void"){
            //     error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
			// }
		}
		else{
			if((yyvsp[0].symbol_info)->is_return==0){
                error_list.push_back("Line "+to_string(yylineno)+" : Missing return statement");
			}
			else{
				// if($4->return_type!=$1){
                //     error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
				// }
			}
		}
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code="\nFUNC_BEGIN "+(yyvsp[-2].symbol_info)->name+"\n";
		for(int i=0;i<(yyvsp[-2].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->code=(yyval.symbol_info)->code+"param"+std::to_string(i)+" := PARAM\n";
		}
		for(int i=0;i<(yyvsp[-2].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->code=(yyval.symbol_info)->code+(yyvsp[-2].symbol_info)->param_list[i]+" := param"+std::to_string(i)+"\n";
		}
		(yyval.symbol_info)->code=(yyval.symbol_info)->code+(yyvsp[0].symbol_info)->code+"\nFUNC_END "+(yyvsp[-2].symbol_info)->name+"\n";

	}
#line 4104 "parser.tab.c"
    break;


#line 4108 "parser.tab.c"

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

#line 1773 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

void print_errors() {
    if(error_list.size()==0){
        cerr<<"======================================================================"<<endl;
        cerr<<"No Errors in the code"<<endl;
        cerr<<"Intermediate code generated successfully"<<endl;
        cerr<<"======================================================================"<<endl;
    }
    else{
        cerr<<"=====================LIST OF ERRORS==================================="<<endl;
    for(auto it:error_list){
        cerr<<it<<endl;
    }
    cerr<<"======================================================================"<<endl;
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
	// print_scope_table();
}
