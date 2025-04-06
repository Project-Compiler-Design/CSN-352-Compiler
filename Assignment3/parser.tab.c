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

	#include "functions.h"
    using namespace std;

	#define MAX_ARGS 100

    void yyerror(const char *s);

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


#line 104 "parser.tab.c"

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
#define YYLAST   2124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  382

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
       0,    74,    74,    80,    86,    87,    88,    89,    96,    97,
     109,   126,   130,   131,   142,   146,   178,   200,   231,   270,
     271,   280,   291,   322,   358,   362,   363,   364,   385,   386,
     390,   397,   404,   411,   418,   425,   435,   439,   447,   448,
     456,   464,   478,   479,   487,   498,   499,   510,   524,   525,
     533,   541,   550,   561,   562,   570,   581,   582,   593,   594,
     608,   609,   623,   624,   636,   637,   648,   649,   653,   654,
     785,   786,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   799,   803,   810,   814,   815,   876,   877,   887,   888,
     889,   893,   896,   903,   931,   979,   980,   981,   982,   983,
     987,   988,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,  1009,  1017,  1018,  1035,  1036,  1040,  1041,  1053,
    1072,  1073,  1074,  1075,  1079,  1084,  1092,  1093,  1094,  1098,
    1099,  1100,  1104,  1105,  1109,  1110,  1114,  1115,  1119,  1123,
    1129,  1136,  1137,  1148,  1152,  1165,  1166,  1181,  1182,  1183,
    1184,  1188,  1189,  1194,  1204,  1208,  1215,  1226,  1234,  1240,
    1249,  1250,  1254,  1255,  1259,  1260,  1261,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1277,  1281,  1282,  1286,
    1287,  1299,  1304,  1308,  1312,  1313,  1314,  1319,  1346,  1374,
    1375,  1382,  1392,  1394,  1393,  1414,  1414,  1418,  1418,  1422,
    1422,  1428,  1440,  1451,  1460,  1467,  1474,  1478,  1482,  1485,
    1493,  1497,  1498,  1502,  1508,  1515,  1515,  1538,  1548,  1558,
    1568,  1584,  1607,  1614,  1621,  1629,  1640,  1646,  1650,  1654,
    1658,  1662,  1666,  1668,  1667,  1702,  1703
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

#define YYPACT_NINF (-256)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-234)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1733,   158,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,    39,  -256,  -256,  -256,  -256,  -256,
    -256,    35,   142,  -256,     9,  2038,  -256,  -256,    43,  -256,
    2038,  1781,    46,     2,    34,  1733,  -256,  -256,   -30,    26,
    -256,    -6,  -256,  -256,   142,  -256,    70,  -256,  1611,  -256,
    -256,     7,  1567,  -256,    20,    11,  -256,     9,  -256,  1857,
    1163,   305,    46,  -256,  -256,    26,    13,   -35,  -256,  -256,
    -256,  -256,    35,  -256,  1199,  1857,    52,  1567,  1567,  1981,
    -256,    76,  1567,  -256,  -256,   519,   683,  1905,  1905,    16,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  1483,  -256,   843,  -256,  -256,  -256,  -256,  -256,  -256,
    1519,  1519,  -256,  -256,   172,  -256,  1563,  -256,    61,    75,
      41,    94,    85,   102,   109,    40,   116,   -31,  -256,   146,
    -256,  -256,    30,    56,   151,  -256,    63,   -33,  1563,  -256,
      26,  -256,  1199,   630,  -256,  -256,  -256,  -256,  -256,  2000,
    -256,  -256,  -256,  1563,    99,  -256,   147,  -256,   174,    27,
     185,  1563,   194,   257,  1083,   206,   222,   226,  -256,   236,
    1243,  -256,  -256,   123,  -256,  -256,  -256,   242,   355,   437,
    -256,  -256,  -256,  -256,   234,   252,   923,  1943,   601,   843,
    -256,  2076,   130,    60,   256,  1563,  -256,  -256,  1563,  1279,
     311,  -256,  -256,   312,  -256,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  -256,  1323,  1657,  -256,     5,  -256,
     143,  -256,   266,  -256,   313,  -256,  -256,  -256,  -256,    -9,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  1563,  -256,  -256,    76,  -256,  1563,  -256,   763,  -256,
     260,  -256,   261,   295,  1083,  1563,  1359,   267,  1563,  -256,
     170,  1563,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  1003,   268,  -256,  1695,   148,  -256,  1563,    -2,
    -256,   177,  -256,  -256,  -256,  -256,  -256,  -256,    61,    61,
      75,    75,    41,    41,    41,    41,    94,    94,    85,   102,
     109,    40,   113,   116,  -256,   269,  -256,   270,   271,   143,
    1403,  1819,  -256,  -256,  -256,  -256,  1119,  -256,  -256,  -256,
    -256,  -256,  1083,  -256,   274,  -256,   188,  1359,  1563,   220,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  1563,  1563,  -256,
    -256,  -256,  -256,   276,  -256,   277,  -256,  -256,  -256,  1563,
    1083,  1439,   224,  1083,  -256,  -256,  -256,  -256,   229,   314,
    1083,   232,  1083,  -256,   288,  1083,  -256,  1083,  -256,  -256,
    -256,  -256
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     229,   140,    98,   115,   136,    97,   100,   105,   103,   106,
      96,   102,   104,   101,     0,    99,   107,    95,   116,   108,
     137,     0,   147,   231,     0,    86,    88,   109,     0,   110,
      89,     0,   139,     0,     0,   226,   227,   230,   131,     0,
     140,     0,   151,   149,   148,    84,     0,    91,     0,   111,
      87,   114,     0,    90,     0,   193,   205,     0,   236,     0,
       0,     0,   138,     1,   228,     0,   134,     0,   132,   141,
     152,   150,     0,    85,     0,     0,     0,     0,   121,     0,
     117,     0,   123,   207,   192,     0,     0,     0,     0,    93,
     206,   235,     2,     5,     8,     4,     6,     3,     7,     9,
      10,     0,   143,     0,    32,    33,    31,    30,    35,    34,
       0,     0,    11,    14,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    83,     0,
     111,   146,   159,     0,   153,   155,     0,     0,     0,   129,
       0,    92,     0,    36,    68,   176,    94,   232,   234,     0,
     120,   113,   118,     0,     0,   124,   126,   122,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,   215,     0,
       0,   211,    81,     0,   208,   181,   182,     0,     0,     0,
     183,   184,   185,   186,     0,    10,     0,     0,     0,     0,
      28,    10,     0,   162,     0,     0,    25,    26,     0,     0,
       0,    20,    21,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,   157,   164,   158,
     165,   144,     0,   145,     0,   130,   135,   133,   179,     0,
      70,    74,    75,    71,    72,    73,    78,    80,    79,    76,
      77,     0,   112,   127,     0,   119,     0,   207,   189,   223,
       0,   222,     0,     0,     0,     0,     0,     0,     0,   224,
       0,     0,   212,   194,   205,   202,   208,   201,   210,   196,
     209,   198,     0,     0,    13,     0,   164,   163,     0,     0,
      16,     0,    22,    18,    19,    39,    40,    41,    43,    44,
      46,    47,    49,    50,    51,    52,    54,    55,    57,    59,
      61,    63,     0,    65,   168,     0,   172,     0,     0,   166,
       0,     0,   154,   156,   161,   177,     0,    69,   125,   128,
     188,   187,     0,   221,     0,   191,     0,     0,     0,     0,
     225,    82,   200,    29,    37,    15,    17,     0,     0,   169,
     173,   167,   170,     0,   174,     0,   178,   180,   190,     0,
       0,     0,     0,     0,    23,    67,   171,   175,     0,   213,
       0,     0,     0,   217,     0,     0,   219,     0,   216,   218,
     214,   220
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,  -256,  -256,  -256,   -59,  -256,   -83,    38,    53,
      44,    58,   139,   152,   159,   161,   160,  -256,   -58,   -71,
    -256,   -89,  -117,     8,     0,  -256,   332,  -256,    -5,  -256,
    -256,   328,   -61,   -63,  -256,   153,  -256,   341,   275,   166,
     -12,   -27,   -18,  -256,   -56,  -256,   176,  -256,   221,  -109,
    -201,  -135,  -256,  -147,  -256,   162,  -256,  -256,  -256,  -256,
     100,    28,   -76,  -255,  -256,  -256,  -256,  -256,  -256,  -256,
     374,  -256,  -256
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   112,   113,   114,   291,   143,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   144,   172,
     251,   173,   129,    56,    57,    46,    47,    25,    26,    27,
      28,    79,    80,    81,   154,   155,    29,    67,    68,    30,
      31,    32,    33,    44,   317,   134,   135,   136,   194,   318,
     230,   146,   239,   174,   175,   176,    85,    86,    87,    88,
     177,   178,   179,   180,   181,   267,   182,   183,    34,    35,
      36,    37,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   115,   128,   145,    43,   133,    62,   238,    23,    41,
     186,   337,    48,    40,   192,   150,    40,   263,   152,   157,
      40,   236,   139,   229,   235,    50,    71,   319,    65,   140,
      53,   140,   276,   204,    63,    24,   253,    66,  -111,   280,
     193,    40,   190,    23,   260,    89,    40,    78,   325,   222,
      38,   196,   197,   223,    51,   326,    69,   115,   345,    59,
      89,   132,   271,    21,   225,    77,   226,    90,    84,   156,
      21,   145,    78,    78,    78,    45,    75,    78,    22,   115,
     128,   270,   361,    90,   287,   319,    83,    40,   152,   225,
     138,   226,   258,    74,   115,   128,    21,    39,    78,    22,
     192,    52,   115,   128,    22,    60,   192,    61,   315,   289,
      55,   331,   282,   220,   228,   187,   188,   335,   231,   225,
     227,   285,   295,   296,   297,   233,   193,   234,   292,    22,
     205,   206,   207,   312,    72,   280,    73,    21,   210,   329,
     211,   153,   208,   209,    78,    22,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   254,   115,   255,   115,   128,     4,  -111,
     216,   217,   212,   213,   218,   286,   336,   271,   348,   339,
     327,   214,   215,   219,    78,   358,   274,   271,    42,   272,
      20,   357,   284,    58,   271,    90,    90,   115,   128,   221,
     341,    62,   320,   353,   321,   344,   224,   225,   228,   285,
      70,    22,   256,   369,    41,   232,   373,  -111,    82,  -111,
    -111,    91,  -111,   376,  -111,   378,   132,  -111,   380,   115,
     381,   198,   132,   199,   271,   200,   340,   147,   148,   346,
     257,   347,   156,    82,    82,    82,   298,   299,    82,   362,
     360,   259,   271,   201,   202,   145,   302,   303,   304,   305,
     261,   115,   128,   300,   301,   355,   330,   286,   262,    82,
     368,   264,   371,   203,   306,   307,   364,    49,   275,   277,
       2,     3,   363,   265,   271,   132,   372,   266,   271,   115,
     365,   374,     4,   271,   377,     5,   271,   268,     6,   273,
     278,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    82,   130,   258,   288,     2,
       3,   132,   293,   294,   324,   332,   334,   333,   338,   349,
     343,     4,   350,   351,     5,   359,   366,     6,   375,   367,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   379,    82,   158,   308,    92,    93,
      94,    95,    96,    97,    98,    99,   159,   131,   322,     2,
       3,   309,   160,   161,   162,   163,   164,   165,   166,   310,
     167,     4,   311,   313,     5,   168,   169,     6,   170,   101,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   141,   149,   137,   328,   323,    64,
     283,     0,  -204,    55,     0,   237,   103,     0,     0,     0,
       0,   171,   104,   105,   106,     0,     0,   107,     0,     0,
     108,   109,     0,     0,     0,     0,   110,   111,   158,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   159,     0,
       0,     2,     3,     0,   160,   161,   162,   163,   164,   165,
     166,     0,   167,     4,     0,     0,     5,   168,   169,     6,
     170,   101,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,  -203,    55,     0,     0,   103,     0,
       0,     0,     0,   171,   104,   105,   106,     0,     0,   107,
       0,     0,   108,   109,     0,     0,     0,     0,   110,   111,
     158,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     159,     0,     0,     2,     3,     0,   160,   161,   162,   163,
     164,   165,   166,     0,   167,     4,     0,     0,     5,   168,
     169,     6,   170,   101,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
     103,     0,     0,     0,     0,   171,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,     0,     0,     0,
     110,   111,   184,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   159,     0,     0,     2,     3,     0,   160,   161,
     162,   163,   164,   165,   166,     0,   167,     4,     0,     0,
       5,   168,   169,     6,   170,   101,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,   103,     0,     0,     0,     0,   171,   104,   105,
     106,     0,     0,   107,     0,     0,   108,   109,     0,     0,
       0,     0,   110,   111,   184,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   185,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,   240,   167,     0,
       0,     0,     0,   168,   169,     0,   170,   101,     0,   241,
     242,   243,   244,   245,   246,   247,   248,     0,   249,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,   103,     0,     0,     0,     0,   171,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   159,     0,     0,     2,     3,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   167,     4,
       0,     0,     5,   168,   169,     6,   170,   101,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,   103,     0,     0,     0,     0,   171,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   191,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     6,     0,   101,     7,     8,
       9,     0,    11,    12,    13,    14,     0,    16,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   185,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   167,     0,
       0,     0,     0,   168,   169,     0,   170,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,    55,     0,     0,   103,     0,     0,     0,     0,   171,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   185,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   167,     0,
       0,     0,     0,   168,   169,     0,   170,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     342,    55,     0,     0,   103,     0,     0,     0,     0,   171,
     104,   105,   106,     0,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   185,     0,     0,     0,     0,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   167,     0,
       0,     0,     0,   168,   169,     0,   170,   101,     0,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,   103,     0,     0,     0,     0,   171,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,   356,   142,     0,     0,
     103,     0,     0,     0,     0,     0,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,   101,     0,     0,
     110,   111,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   142,     0,     0,
     103,     0,     0,     0,     0,     0,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,   101,     0,     0,
     110,   111,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   269,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
     103,   290,     0,     0,     0,     0,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,   101,     0,     0,
     110,   111,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   314,   103,     0,     0,     0,     0,     0,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,   171,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,   101,     0,     0,
     110,   111,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   103,     0,     0,     0,     0,     0,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
     103,   370,     0,     0,     0,     0,   104,   105,   106,     0,
       0,   107,     0,     0,   108,   109,     0,   101,     0,     0,
     110,   111,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,     0,     0,
     104,   105,   106,   101,     0,   107,     0,     0,   108,   109,
       0,     0,     0,     0,   110,   111,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,    49,     0,
     195,     0,     3,     0,     0,     0,   104,   105,   106,     0,
       0,   107,     0,     4,   108,   109,     0,   101,     0,     6,
     110,   111,     7,     8,     9,     0,    11,    12,    13,    14,
       0,    16,    54,    18,    19,    20,     0,     0,     0,     0,
       0,     0,    49,     0,   103,     2,     3,     0,     0,     0,
     104,   105,   106,     0,     0,   107,     0,     4,   108,   109,
       5,     0,     0,     6,   110,   111,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     1,  -233,
       0,     2,     3,     0,     0,   -93,     0,   -93,     0,     0,
       0,     0,     0,     4,     0,     0,     5,     0,    74,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    49,     0,     0,     2,
       3,     0,     0,     0,     0,     0,   225,     0,   226,   316,
       0,     4,     0,     0,     5,     0,    22,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     1,     0,     0,     2,     3,     0,
       0,     0,     0,     0,   225,     0,   285,   316,     0,     4,
       0,     0,     5,     0,    22,     6,     0,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,    21,     2,     3,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      49,     0,     0,     2,     3,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    49,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,   354,     0,     4,     0,     0,     5,     0,     0,     6,
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
     281,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,    49,     0,     6,     0,     3,     7,     8,     9,     0,
      11,    12,    13,    14,     0,    16,     4,    18,    19,    20,
       0,     0,     6,     0,     0,     7,     8,     9,   151,    11,
      12,    13,    14,     0,    16,     0,    18,    19,    20,    49,
       0,     0,     2,     3,     0,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,  -111,     0,     0,
       0,  -111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -111,     0,     0,     0,     0,     0,  -111,     0,
       0,  -111,  -111,  -111,     0,  -111,  -111,  -111,  -111,     0,
    -111,     0,  -111,  -111,  -111
};

static const yytype_int16 yycheck[] =
{
       0,    60,    60,    74,    22,    61,    33,   142,     0,    21,
      86,   266,    24,    11,   103,    78,    11,   164,    79,    82,
      11,   138,    57,   132,    57,    25,    44,   228,    58,    64,
      30,    64,   179,   116,     0,    35,   153,    11,    11,   186,
     103,    11,   101,    35,   161,    57,    11,    52,    57,    80,
      11,   110,   111,    84,    11,    64,    62,   116,    60,    31,
      72,    61,    64,    61,    59,    58,    61,    59,    57,    81,
      61,   142,    77,    78,    79,    66,    48,    82,    69,   138,
     138,   170,   337,    75,   193,   286,    66,    11,   149,    59,
      77,    61,    65,    77,   153,   153,    61,    58,   103,    69,
     189,    58,   161,   161,    69,    59,   195,    61,   225,   198,
      58,   258,   188,    73,   132,    87,    88,   264,    62,    59,
     132,    61,   205,   206,   207,    62,   189,    64,   199,    69,
      69,    70,    71,   222,    64,   282,    66,    61,    97,   256,
      99,    65,    67,    68,   149,    69,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    64,   223,    66,   225,   225,    26,    11,
      85,    86,    78,    79,    72,   193,   265,    64,    65,   268,
     251,    87,    88,    74,   189,   332,   178,    64,    22,    66,
      48,   326,    62,    31,    64,   187,   188,   256,   256,    83,
     271,   228,    59,   320,    61,   288,    60,    59,   226,    61,
      44,    69,    65,   360,   226,    64,   363,    59,    52,    61,
      62,    59,    64,   370,    66,   372,   226,    69,   375,   288,
     377,    59,   232,    61,    64,    63,    66,    75,    76,    62,
      66,    64,   254,    77,    78,    79,   208,   209,    82,   338,
      62,    66,    64,    81,    82,   326,   212,   213,   214,   215,
      66,   320,   320,   210,   211,   321,   258,   285,    11,   103,
     359,    65,   361,   101,   216,   217,   347,    11,   178,   179,
      14,    15,    62,    61,    64,   285,    62,    61,    64,   348,
     348,    62,    26,    64,    62,    29,    64,    61,    32,    57,
      66,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   149,    11,    65,    62,    14,
      15,   321,    11,    11,    11,    65,    31,    66,    61,    60,
      62,    26,    62,    62,    29,    61,    60,    32,    24,    62,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    66,   189,     1,   218,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    62,   102,    14,
      15,   219,    17,    18,    19,    20,    21,    22,    23,   220,
      25,    26,   221,   223,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    72,    77,    65,   254,   232,    35,
     189,    -1,    57,    58,    -1,   140,    61,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    81,    82,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    77,    25,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,
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
       7,     8,     9,    10,    11,    -1,    -1,    -1,    11,    -1,
      61,    -1,    15,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    26,    75,    76,    -1,    34,    -1,    32,
      81,    82,    35,    36,    37,    -1,    39,    40,    41,    42,
      -1,    44,     1,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    61,    14,    15,    -1,    -1,    -1,
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
      45,    46,    47,    48,    11,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,    26,
      -1,    -1,    29,    -1,    69,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    61,    14,    15,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
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
      42,    43,    44,    45,    46,    47,    48,    11,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    -1,    46,    47,    48
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
     136,    57,   135,    65,   137,   138,   143,   136,     1,    11,
      17,    18,    19,    20,    21,    22,    23,    25,    30,    31,
      33,    66,   122,   124,   156,   157,   158,   163,   164,   165,
     166,   167,   169,   170,     1,    11,   165,   164,   164,    61,
     108,    11,   124,   136,   151,    61,   108,   108,    59,    61,
      63,    81,    82,   101,   110,    69,    70,    71,    67,    68,
      97,    99,    78,    79,    87,    88,    85,    86,    72,    74,
      73,    83,    80,    84,    60,    59,    61,   143,   145,   152,
     153,    62,    64,    62,    64,    57,   125,   141,   154,   155,
      77,    89,    90,    91,    92,    93,    94,    95,    96,    98,
     100,   123,    57,   125,    64,    66,    65,    66,    65,    66,
     125,    66,    11,   156,    65,    61,    61,   168,    61,    66,
     124,    64,    66,    57,   126,   163,   156,   163,    66,    57,
     156,    57,   165,   151,    62,    61,   145,   152,    62,   124,
      62,   107,   122,    11,    11,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   114,   114,   115,   116,
     117,   118,   124,   119,    60,   125,    62,   147,   152,   153,
      59,    61,   102,   149,    11,    57,    64,   122,   138,   125,
     126,   156,    65,    66,    31,   156,   124,   166,    61,   124,
      66,   122,    57,    62,   110,    60,    62,    64,    65,    60,
      62,    62,    60,   125,    62,   147,    57,   154,   156,    61,
      62,   166,   124,    62,   122,   121,    60,    62,   124,   156,
      62,   124,    62,   156,    62,    24,   156,    62,   156,    66,
     156,   156
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
     136,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   149,
     150,   150,   151,   151,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   155,
     155,   156,   156,   156,   156,   156,   156,   157,   157,   157,
     157,   157,   158,   159,   158,   160,   158,   161,   158,   162,
     158,   163,   163,   163,   163,   164,   164,   164,   165,   165,
     165,   166,   166,   167,   167,   168,   167,   169,   169,   169,
     169,   170,   170,   170,   170,   170,   171,   172,   172,   172,
     173,   173,   174,   175,   174,   174,   174
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
       2,     1,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     2,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     3,     4,     3,     4,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     2,     3,     3,     4,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       4,     3,     2,     0,     4,     0,     4,     0,     4,     0,
       5,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     5,     7,     0,     6,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     1,     2,     0,
       1,     1,     4,     0,     4,     3,     2
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
#line 75 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "int", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1926 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 81 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "float", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1936 "parser.tab.c"
    break;

  case 4: /* constant: EXP_LITERAL  */
#line 86 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "exp", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1942 "parser.tab.c"
    break;

  case 5: /* constant: HEXA_LITERAL  */
#line 87 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "hexa", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1948 "parser.tab.c"
    break;

  case 6: /* constant: REAL_LITERAL  */
#line 88 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "real", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1954 "parser.tab.c"
    break;

  case 7: /* constant: STRING_LITERAL  */
#line 90 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char*", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        (yyval.symbol_info)->str_val=(yyvsp[0].symbol_info)->str_val;
        (yyval.symbol_info)->place=qid((yyvsp[0].symbol_info)->str_val,nullptr);
        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->str_val;
	}
#line 1965 "parser.tab.c"
    break;

  case 8: /* constant: OCTAL_LITERAL  */
#line 96 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "octal", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1971 "parser.tab.c"
    break;

  case 9: /* constant: CHARACTER_LITERAL  */
#line 98 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        string tempp = "'";
        tempp+=(*(char*)((yyvsp[0].symbol_info)->ptr));
        tempp+='\'';
		(yyval.symbol_info)->place=qid(tempp,nullptr);
		(yyval.symbol_info)->code=tempp;
	}
#line 1984 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 110 "src/parser.y"
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
#line 2005 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 127 "src/parser.y"
        {
		(yyval.symbol_info) = (yyvsp[0].symbol_info);
	}
#line 2013 "parser.tab.c"
    break;

  case 13: /* primary_expression: LPARENTHESES expression RPARENTHESES  */
#line 132 "src/parser.y"
        {
		symbol_info* new_symbol = new symbol_info();
		new_symbol->place=newtemp((yyvsp[-1].symbol_info)->type,curr_scope);
		// debug("here ",new_symbol->place.first);
		new_symbol->code=(yyvsp[-1].symbol_info)->code+"\n"+new_symbol->place.first+":= ("+(yyvsp[-1].symbol_info)->place.first+")";
		(yyval.symbol_info)=new_symbol;
	}
#line 2025 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 143 "src/parser.y"
        {
            (yyval.symbol_info)=(yyvsp[0].symbol_info);
        }
#line 2033 "parser.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 147 "src/parser.y"
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
#line 2069 "parser.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression LPARENTHESES RPARENTHESES  */
#line 179 "src/parser.y"
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
			(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code  + temp.first+":= CALL "+(yyvsp[-2].symbol_info)->place.first + "\n";
			(yyval.symbol_info)->place=temp;
    }
#line 2095 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 201 "src/parser.y"
            {
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
			(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code +"\n"+(yyvsp[-1].symbol_info)->code+ "\n"+ middle + temp.first+":= CALL "+(yyvsp[-3].symbol_info)->place.first + ","+to_string((yyvsp[-1].symbol_info)->param_list.size()) + "\n";
			(yyval.symbol_info)->place=temp;
        }
#line 2130 "parser.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DOT ID  */
#line 232 "src/parser.y"
        {
		symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
		if(find_symbol == nullptr) {
            error_list.push_back("Line "+to_string(yylineno)+" : Undeclared variable "+(yyvsp[-2].symbol_info)->name);
		}
		else{
			if((find_symbol->type).substr(0,6)=="struct" || (find_symbol->type).substr(0,5)=="union"){
				symbol_info* find_struct;
				if((find_symbol->type).substr(0,6)=="struct") find_struct=lookup_symbol_global((find_symbol->type).substr(7), curr_scope);
				else find_struct=lookup_symbol_global((find_symbol->type).substr(6), curr_scope);
				int flag=0;
				string var_type="";

				for(int i=0;i<find_struct->param_list.size();i++){
					if(find_struct->param_list[i]==(yyvsp[0].str)){
						var_type=find_struct->param_types[i];
						flag=1;
						break;
					}
				}
				if(flag==0){
                    error_list.push_back("Line "+to_string(yylineno)+" : No such attribute found in struct or union "+(yyvsp[-2].symbol_info)->name);
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
                error_list.push_back("Line "+to_string(yylineno)+" : Not a struct or union "+(yyvsp[-2].symbol_info)->name);
			}
			
		}
	}
#line 2173 "parser.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression INCREMENT  */
#line 272 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"+1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"+1";
		
	}
#line 2186 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression DECREMENT  */
#line 281 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"-1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"-1";
	}
#line 2198 "parser.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 292 "src/parser.y"
    { 
		if((yyvsp[0].symbol_info)->place.first!=""){
			// debug("herrrr ", $1->code);
			(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->place.first);
		}
		else{
			if((yyvsp[0].symbol_info)->name==""){
				(yyval.symbol_info)=(yyvsp[0].symbol_info);
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
					(yyval.symbol_info)=find_symbol;
					(yyval.symbol_info)->param_types.push_back(find_symbol->type);
					(yyval.symbol_info)->param_list.push_back(find_symbol->name);
				}
			} 
		}
        
      }
#line 2233 "parser.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 324 "src/parser.y"
        { 
			if((yyvsp[0].symbol_info)->place.first!=""){
				(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
				debug("herrrrrrrrrrr ", (yyvsp[0].symbol_info)->place.first);
				(yyval.symbol_info)->param_types.push_back((yyvsp[-2].symbol_info)->type);
				(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->place.first);
			}
			else{
				if((yyvsp[0].symbol_info)->name==""){
                (yyval.symbol_info)=(yyvsp[-2].symbol_info);
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
                    (yyval.symbol_info)=(yyvsp[-2].symbol_info);
                    (yyval.symbol_info)->param_types.push_back(find_symbol->type);
                    (yyval.symbol_info)->param_list.push_back(find_symbol->name);
                }
            } 
			}
                      
        }
#line 2269 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 359 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);        
	}
#line 2277 "parser.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 365 "src/parser.y"
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
#line 2302 "parser.tab.c"
    break;

  case 30: /* unary_operator: AMPERSAND  */
#line 390 "src/parser.y"
                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="ampersand";
		(yyval.symbol_info)->code="&";
        (yyval.symbol_info)->pointer_depth++;
	}
#line 2314 "parser.tab.c"
    break;

  case 31: /* unary_operator: STAR  */
#line 398 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="star";
		(yyval.symbol_info)->code="*";
	}
#line 2325 "parser.tab.c"
    break;

  case 32: /* unary_operator: PLUS  */
#line 405 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="plus";
		(yyval.symbol_info)->code="+";
	}
#line 2336 "parser.tab.c"
    break;

  case 33: /* unary_operator: MINUS  */
#line 412 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="minus";
		(yyval.symbol_info)->code="-";
	}
#line 2347 "parser.tab.c"
    break;

  case 34: /* unary_operator: TILDE  */
#line 419 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="tilde";
		(yyval.symbol_info)->code="~";
	}
#line 2358 "parser.tab.c"
    break;

  case 35: /* unary_operator: EXCLAMATION  */
#line 426 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="exclamation";
		(yyval.symbol_info)->code="!";
	}
#line 2369 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 436 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2377 "parser.tab.c"
    break;

  case 37: /* cast_expression: LPARENTHESES type_name RPARENTHESES cast_expression  */
#line 440 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[0].symbol_info);
        (yyval.symbol_info)->type = (yyvsp[-2].symbol_info)->type;
    }
#line 2386 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 447 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2392 "parser.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 449 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2404 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 457 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2416 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 465 "src/parser.y"
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
#line 2431 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 478 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2437 "parser.tab.c"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 480 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2449 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 488 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2461 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 498 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2467 "parser.tab.c"
    break;

  case 46: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 500 "src/parser.y"
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
#line 2482 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 511 "src/parser.y"
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
#line 2497 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 524 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2503 "parser.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 526 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2515 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 534 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];        
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2527 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression LESS_EQUALS shift_expression  */
#line 542 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	
	}
#line 2540 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER_EQUALS shift_expression  */
#line 551 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2552 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 561 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2558 "parser.tab.c"
    break;

  case 54: /* equality_expression: equality_expression REL_EQUALS relational_expression  */
#line 563 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"=="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2570 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression REL_NOT_EQ relational_expression  */
#line 571 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"!="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2582 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 581 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2588 "parser.tab.c"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 583 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : And operator can only be used with int type");
        }
    }
#line 2600 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 593 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2606 "parser.tab.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression XOR and_expression  */
#line 595 "src/parser.y"
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
#line 2621 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 608 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2627 "parser.tab.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression OR exclusive_or_expression  */
#line 610 "src/parser.y"
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
#line 2642 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 623 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2648 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression REL_AND inclusive_or_expression  */
#line 625 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : AND operator can only be used with int type");
        }
        
    }
#line 2661 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 636 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2667 "parser.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression REL_OR logical_and_expression  */
#line 638 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
    }
#line 2679 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 648 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2685 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 653 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2691 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 655 "src/parser.y"
        {
        symbol_info* find_symbol = lookup_symbol_global((yyvsp[-2].symbol_info)->name, curr_scope);
        if(find_symbol != nullptr) {
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
                    //checkerror
					//3AC code kabhi toh karenge
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
                        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+code+":= "+(yyvsp[0].symbol_info)->place.first+"\n";
                    }
                    else{
                        string op=(yyvsp[-1].symbol_info)->code;
                        string tcode="";
                        if(op=="=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="*=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="/=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="%=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"%"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="+=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="-=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="<<=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"<<"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op==">>=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+">>"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="&=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"&"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="^=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"^"+(yyvsp[0].symbol_info)->place.first;
                        }
                        else if(op=="|=")
                        {
                            tcode=(yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[-2].symbol_info)->place.first+"|"+(yyvsp[0].symbol_info)->place.first;
                        }   
                        else{
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
#line 2823 "parser.tab.c"
    break;

  case 70: /* assignment_operator: EQUALS  */
#line 785 "src/parser.y"
                 {(yyval.symbol_info)=new symbol_info("","equals",nullptr,0); (yyval.symbol_info)->code="=";}
#line 2829 "parser.tab.c"
    break;

  case 71: /* assignment_operator: ASSIGN_STAR  */
#line 786 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_star",nullptr,0); (yyval.symbol_info)->code="*=";}
#line 2835 "parser.tab.c"
    break;

  case 72: /* assignment_operator: ASSIGN_DIV  */
#line 787 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_div",nullptr,0); (yyval.symbol_info)->code="/=";}
#line 2841 "parser.tab.c"
    break;

  case 73: /* assignment_operator: ASSIGN_MOD  */
#line 788 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_mod",nullptr,0); (yyval.symbol_info)->code="%=";}
#line 2847 "parser.tab.c"
    break;

  case 74: /* assignment_operator: ASSIGN_PLUS  */
#line 789 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_plus",nullptr,0); (yyval.symbol_info)->code="+=";}
#line 2853 "parser.tab.c"
    break;

  case 75: /* assignment_operator: ASSIGN_MINUS  */
#line 790 "src/parser.y"
                       {(yyval.symbol_info)=new symbol_info("","assign_minus",nullptr,0); (yyval.symbol_info)->code="-=";}
#line 2859 "parser.tab.c"
    break;

  case 76: /* assignment_operator: LEFT_SHIFT_EQ  */
#line 791 "src/parser.y"
                        {(yyval.symbol_info)=new symbol_info("","left_shift_eq",nullptr,0); (yyval.symbol_info)->code="<<=";}
#line 2865 "parser.tab.c"
    break;

  case 77: /* assignment_operator: RIGHT_SHIFT_EQ  */
#line 792 "src/parser.y"
                         {(yyval.symbol_info)=new symbol_info("","right_shift_eq",nullptr,0); (yyval.symbol_info)->code=">>=";}
#line 2871 "parser.tab.c"
    break;

  case 78: /* assignment_operator: ASSIGN_AND  */
#line 793 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_and",nullptr,0); (yyval.symbol_info)->code="&=";}
#line 2877 "parser.tab.c"
    break;

  case 79: /* assignment_operator: ASSIGN_XOR  */
#line 794 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_xor",nullptr,0); (yyval.symbol_info)->code="^=";}
#line 2883 "parser.tab.c"
    break;

  case 80: /* assignment_operator: ASSIGN_OR  */
#line 795 "src/parser.y"
                    {(yyval.symbol_info)=new symbol_info("","assign_or",nullptr,0); (yyval.symbol_info)->code="|=";}
#line 2889 "parser.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 800 "src/parser.y"
        {
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2897 "parser.tab.c"
    break;

  case 82: /* expression: expression COMMA assignment_expression  */
#line 804 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 2905 "parser.tab.c"
    break;

  case 83: /* constant_expression: conditional_expression  */
#line 810 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2911 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 816 "src/parser.y"
    {
		if(std::string((yyvsp[-2].str)).substr(0, 7) == "typedef"){
			string new_type=parsing_stack.top();
			parsing_stack.pop();
			string old_type=std::string((yyvsp[-2].str)).substr(8);
			type_def_mapping[new_type]=old_type;
		}
		
		
		int flag=0;
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
                else{
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in declaration");
                    flag=1;
                }
				// debug("declaration specifiers121 ", $2->code);

				
				symbol_info* new_symbol = new symbol_info();
				new_symbol->code = (yyvsp[-1].symbol_info)->code;
				(yyval.symbol_info)=new_symbol;

			} else {
				curr_scope->symbol_map[top_symbol]->type = (yyvsp[-2].str);
                for(int i=0;i<depth;i++){
                    curr_scope->symbol_map[top_symbol]->type+="*";
                }
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                curr_scope->symbol_map[top_symbol]->pointer_depth = depth;

				symbol_info* new_symbol = new symbol_info();
				new_symbol = (yyvsp[-1].symbol_info);
				(yyval.symbol_info)=new_symbol;
			}
			
		}
    }
#line 2972 "parser.tab.c"
    break;

  case 87: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 878 "src/parser.y"
        {
		debug("storage class specifier ", (yyvsp[-1].str));
		debug("storage class specifier ", (yyvsp[0].str));
		char* buf = (char*)malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 2); // 1 for comma, 1 for null terminator
		sprintf(buf, "%s,%s", (yyvsp[-1].str), (yyvsp[0].str));
		(yyval.str) = buf;
		debug("storage class specifier ", (yyval.str));

	}
#line 2986 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 887 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 2992 "parser.tab.c"
    break;

  case 91: /* init_declarator_list: init_declarator  */
#line 893 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
    }
#line 3000 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 896 "src/parser.y"
                                                 { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->code = (yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
    }
#line 3009 "parser.tab.c"
    break;

  case 93: /* init_declarator: declarator  */
#line 903 "src/parser.y"
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
			else if((yyvsp[0].symbol_info)->type=="char[]"){
				string code=(yyvsp[0].symbol_info)->name+":= alloc " +to_string(2*(yyvsp[0].symbol_info)->array_length);
				(yyval.symbol_info)->code=code;
			} 
		}
		
		curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->type=(yyvsp[0].symbol_info)->type;
		
        (yyval.symbol_info) =new_symbol;
		
		parsing_stack.push((yyvsp[0].symbol_info)->name.c_str());
        pointer_info.push((yyvsp[0].symbol_info)->pointer_depth);
    }
#line 3042 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator EQUALS initializer  */
#line 931 "src/parser.y"
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
#line 3092 "parser.tab.c"
    break;

  case 100: /* type_specifier: VOID  */
#line 987 "src/parser.y"
                                        {(yyval.str)=strdup("void");}
#line 3098 "parser.tab.c"
    break;

  case 101: /* type_specifier: CHAR  */
#line 988 "src/parser.y"
                                        {(yyval.str)=strdup("char");}
#line 3104 "parser.tab.c"
    break;

  case 102: /* type_specifier: SHORT  */
#line 989 "src/parser.y"
                                        {(yyval.str)=strdup("short");}
#line 3110 "parser.tab.c"
    break;

  case 103: /* type_specifier: INT  */
#line 990 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 3116 "parser.tab.c"
    break;

  case 104: /* type_specifier: LONG  */
#line 991 "src/parser.y"
                                        {(yyval.str)=strdup("long");}
#line 3122 "parser.tab.c"
    break;

  case 105: /* type_specifier: FLOAT  */
#line 992 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 3128 "parser.tab.c"
    break;

  case 106: /* type_specifier: DOUBLE  */
#line 993 "src/parser.y"
                                        {(yyval.str)=strdup("double");}
#line 3134 "parser.tab.c"
    break;

  case 107: /* type_specifier: SIGNED  */
#line 994 "src/parser.y"
                                        {(yyval.str)=strdup("signed");}
#line 3140 "parser.tab.c"
    break;

  case 108: /* type_specifier: UNSIGNED  */
#line 995 "src/parser.y"
                                        {(yyval.str)=strdup("unsigned");}
#line 3146 "parser.tab.c"
    break;

  case 109: /* type_specifier: struct_or_union_specifier  */
#line 996 "src/parser.y"
                                    {(yyval.str)=(yyvsp[0].str);}
#line 3152 "parser.tab.c"
    break;

  case 111: /* type_specifier: ID  */
#line 998 "src/parser.y"
             {
		if(type_def_mapping.find((yyvsp[0].str)) != type_def_mapping.end()){
			(yyval.str)=strdup(type_def_mapping[(yyvsp[0].str)].c_str());
		}
		else{
			error_list.push_back("Line "+to_string(yylineno)+" : Typedef error "+(yyvsp[0].str));
		}
	}
#line 3165 "parser.tab.c"
    break;

  case 112: /* struct_or_union_specifier: struct_or_union ID LBRACE struct_declaration_list RBRACE  */
#line 1010 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		new_symbol->type = (yyvsp[-4].str);
		new_symbol->param_list = (yyvsp[-1].symbol_info)->param_list;
		new_symbol->param_types = (yyvsp[-1].symbol_info)->param_types;
		curr_scope->symbol_map[(yyvsp[-3].str)]=new_symbol;
	}
#line 3177 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID  */
#line 1019 "src/parser.y"
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
#line 3195 "parser.tab.c"
    break;

  case 115: /* struct_or_union: STRUCT  */
#line 1035 "src/parser.y"
                 {(yyval.str)=strdup("struct");}
#line 3201 "parser.tab.c"
    break;

  case 116: /* struct_or_union: UNION  */
#line 1036 "src/parser.y"
                {(yyval.str)=strdup("union");}
#line 3207 "parser.tab.c"
    break;

  case 117: /* struct_declaration_list: struct_declaration  */
#line 1040 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3213 "parser.tab.c"
    break;

  case 118: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1042 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(int i=0;i<(yyvsp[0].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->param_list[i]);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->param_types[i]);
		}
		
	}
#line 3226 "parser.tab.c"
    break;

  case 119: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 1054 "src/parser.y"
        { 
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
#line 3246 "parser.tab.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator  */
#line 1080 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3255 "parser.tab.c"
    break;

  case 125: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 1085 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3264 "parser.tab.c"
    break;

  case 126: /* struct_declarator: declarator  */
#line 1092 "src/parser.y"
                         {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3270 "parser.tab.c"
    break;

  case 138: /* declarator: pointer direct_declarator  */
#line 1119 "src/parser.y"
                                { 
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
        (yyval.symbol_info)->pointer_depth=(yyvsp[-1].symbol_info)->pointer_depth;
    }
#line 3279 "parser.tab.c"
    break;

  case 139: /* declarator: direct_declarator  */
#line 1123 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info); 
    }
#line 3287 "parser.tab.c"
    break;

  case 140: /* direct_declarator: ID  */
#line 1130 "src/parser.y"
        {
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);
		x->place.first=(yyvsp[0].str);
		(yyval.symbol_info)=x;
	}
#line 3298 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LBRACKET constant_expression RBRACKET  */
#line 1138 "src/parser.y"
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
#line 3313 "parser.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 1149 "src/parser.y"
    {
        (yyval.symbol_info)->is_array = true, (yyval.symbol_info)->array_length = 100;
    }
#line 3321 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LPARENTHESES parameter_type_list RPARENTHESES  */
#line 1153 "src/parser.y"
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
#line 3338 "parser.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator LPARENTHESES RPARENTHESES  */
#line 1167 "src/parser.y"
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
#line 3354 "parser.tab.c"
    break;

  case 147: /* pointer: STAR  */
#line 1181 "src/parser.y"
               {(yyval.symbol_info)=new symbol_info(); (yyval.symbol_info)->pointer_depth=1;}
#line 3360 "parser.tab.c"
    break;

  case 149: /* pointer: STAR pointer  */
#line 1183 "src/parser.y"
                       {(yyval.symbol_info)=(yyvsp[0].symbol_info); (yyval.symbol_info)->pointer_depth++;}
#line 3366 "parser.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 1195 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)->parameter_no=(yyvsp[0].symbol_info)->parameter_no;
		(yyval.symbol_info)->is_param_list=(yyvsp[0].symbol_info)->is_param_list;
		(yyval.symbol_info)->param_types=(yyvsp[0].symbol_info)->param_types;
		(yyval.symbol_info)->param_list=(yyvsp[0].symbol_info)->param_list;
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		
	}
#line 3380 "parser.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 1209 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=1;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3391 "parser.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1216 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=(yyvsp[-2].symbol_info)->parameter_no+(yyvsp[0].symbol_info)->parameter_no;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3402 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 1227 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->parameter_no=1;
	}
#line 3414 "parser.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1234 "src/parser.y"
                                                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
	}
#line 3425 "parser.tab.c"
    break;

  case 159: /* parameter_declaration: declaration_specifiers  */
#line 1240 "src/parser.y"
                                {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[0].str);
		(yyval.symbol_info)->name="";
	}
#line 3436 "parser.tab.c"
    break;

  case 176: /* initializer: assignment_expression  */
#line 1277 "src/parser.y"
                                {
		(yyvsp[0].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3445 "parser.tab.c"
    break;

  case 177: /* initializer: LBRACE initializer_list RBRACE  */
#line 1281 "src/parser.y"
                                         {(yyval.symbol_info) = (yyvsp[-1].symbol_info);}
#line 3451 "parser.tab.c"
    break;

  case 178: /* initializer: LBRACE initializer_list COMMA RBRACE  */
#line 1282 "src/parser.y"
                                               {(yyval.symbol_info) = (yyvsp[-2].symbol_info);}
#line 3457 "parser.tab.c"
    break;

  case 179: /* initializer_list: initializer  */
#line 1286 "src/parser.y"
                      {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 3463 "parser.tab.c"
    break;

  case 180: /* initializer_list: initializer_list COMMA initializer  */
#line 1287 "src/parser.y"
                                             {
		if((yyvsp[-2].symbol_info)->type != (yyvsp[0].symbol_info)->type){
            error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in initializer list");
		}
		else{
			(yyvsp[-2].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		}
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
	}
#line 3477 "parser.tab.c"
    break;

  case 181: /* statement: labeled_statement  */
#line 1300 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);

	}
#line 3486 "parser.tab.c"
    break;

  case 182: /* statement: compound_statement  */
#line 1305 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3494 "parser.tab.c"
    break;

  case 183: /* statement: expression_statement  */
#line 1309 "src/parser.y"
    {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3502 "parser.tab.c"
    break;

  case 184: /* statement: selection_statement  */
#line 1312 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3508 "parser.tab.c"
    break;

  case 185: /* statement: iteration_statement  */
#line 1313 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3514 "parser.tab.c"
    break;

  case 186: /* statement: jump_statement  */
#line 1314 "src/parser.y"
                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3520 "parser.tab.c"
    break;

  case 187: /* labeled_statement: ID COLON statement  */
#line 1320 "src/parser.y"
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
				debug("labellllll", (yyvsp[0].symbol_info)->code);
				string label=newlabel();
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				
				goto_list[(yyvsp[-2].str)]=label;
			}
			curr_scope->symbol_map[(yyvsp[-2].str)]=new symbol_info();
			curr_scope->symbol_map[(yyvsp[-2].str)]->name=(yyvsp[-2].str);
			curr_scope->symbol_map[(yyvsp[-2].str)]->type="label";
		}
	}
#line 3551 "parser.tab.c"
    break;

  case 188: /* labeled_statement: ID COLON declaration  */
#line 1347 "src/parser.y"
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
				debug("labellllll", (yyvsp[0].symbol_info)->code);
				string label=newlabel();
				(yyval.symbol_info)->code=label+":\n"+(yyvsp[0].symbol_info)->code;
				
				goto_list[(yyvsp[-2].str)]=label;
			}
			curr_scope->symbol_map[(yyvsp[-2].str)]=new symbol_info();
			curr_scope->symbol_map[(yyvsp[-2].str)]->name=(yyvsp[-2].str);
			curr_scope->symbol_map[(yyvsp[-2].str)]->type="label";
		}
	}
#line 3583 "parser.tab.c"
    break;

  case 190: /* labeled_statement: CASE constant_expression COLON statement  */
#line 1376 "src/parser.y"
        {
		string label=newlabel();
		(yyval.symbol_info)->code = label +":\n"+ (yyvsp[0].symbol_info)->code;
		case_list.top().push({(yyvsp[-2].symbol_info)->code,label});
		
	}
#line 3594 "parser.tab.c"
    break;

  case 191: /* labeled_statement: DEFAULT COLON statement  */
#line 1383 "src/parser.y"
        {
		string label=newlabel();
		case_list.top().push({"default",label});
		(yyval.symbol_info)->code = label+":\n"+ (yyvsp[0].symbol_info)->code;

	}
#line 3605 "parser.tab.c"
    break;

  case 193: /* $@1: %empty  */
#line 1394 "src/parser.y"
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
#line 3620 "parser.tab.c"
    break;

  case 194: /* compound_statement: LBRACE $@1 statement_declaration_list RBRACE  */
#line 1406 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[-1].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
	}
#line 3633 "parser.tab.c"
    break;

  case 195: /* $@2: %empty  */
#line 1414 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3639 "parser.tab.c"
    break;

  case 196: /* compound_statement: LBRACE $@2 statement_list RBRACE  */
#line 1414 "src/parser.y"
                                                                                     {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3648 "parser.tab.c"
    break;

  case 197: /* $@3: %empty  */
#line 1418 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3654 "parser.tab.c"
    break;

  case 198: /* compound_statement: LBRACE $@3 declaration_list RBRACE  */
#line 1418 "src/parser.y"
                                                                                       {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3663 "parser.tab.c"
    break;

  case 199: /* $@4: %empty  */
#line 1422 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3669 "parser.tab.c"
    break;

  case 200: /* compound_statement: LBRACE $@4 declaration_list statement_list RBRACE  */
#line 1422 "src/parser.y"
                                                                                                      {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3677 "parser.tab.c"
    break;

  case 201: /* statement_declaration_list: statement_list statement_declaration_list  */
#line 1429 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		
        

	}
#line 3693 "parser.tab.c"
    break;

  case 202: /* statement_declaration_list: declaration_list statement_declaration_list  */
#line 1441 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		// $$->return_type=$2->return_type;
		
        
		
	}
#line 3708 "parser.tab.c"
    break;

  case 203: /* statement_declaration_list: statement_list  */
#line 1452 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		//dikkat badi hai
		// $$->return_type=$1->return_type;
	}
#line 3721 "parser.tab.c"
    break;

  case 204: /* statement_declaration_list: declaration_list  */
#line 1461 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3729 "parser.tab.c"
    break;

  case 205: /* declaration_list: declaration  */
#line 1468 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		debug("declaration_list", (yyval.symbol_info)->code);
	}
#line 3740 "parser.tab.c"
    break;

  case 206: /* declaration_list: declaration_list declaration  */
#line 1475 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 3748 "parser.tab.c"
    break;

  case 207: /* declaration_list: error SEMICOLON  */
#line 1478 "src/parser.y"
                          {yyerrok;}
#line 3754 "parser.tab.c"
    break;

  case 208: /* statement_list: statement  */
#line 1482 "src/parser.y"
                    { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3762 "parser.tab.c"
    break;

  case 209: /* statement_list: statement_list statement  */
#line 1486 "src/parser.y"
        {
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		
	}
#line 3774 "parser.tab.c"
    break;

  case 210: /* statement_list: error SEMICOLON  */
#line 1493 "src/parser.y"
                          {yyerrok;}
#line 3780 "parser.tab.c"
    break;

  case 212: /* expression_statement: expression SEMICOLON  */
#line 1498 "src/parser.y"
                                 {(yyval.symbol_info)=(yyvsp[-1].symbol_info);}
#line 3786 "parser.tab.c"
    break;

  case 213: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement  */
#line 1503 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+"if("+ (yyvsp[-2].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+falselabel+":\n";
	}
#line 3796 "parser.tab.c"
    break;

  case 214: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement ELSE statement  */
#line 1509 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+"if("+ (yyvsp[-4].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
	}
#line 3807 "parser.tab.c"
    break;

  case 215: /* $@5: %empty  */
#line 1515 "src/parser.y"
                {queue<std::pair<std::string, std::string>> q;
		case_list.push(q);
		}
#line 3815 "parser.tab.c"
    break;

  case 216: /* selection_statement: SWITCH $@5 LPARENTHESES expression RPARENTHESES statement  */
#line 1518 "src/parser.y"
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
#line 3837 "parser.tab.c"
    break;

  case 217: /* iteration_statement: WHILE LPARENTHESES expression RPARENTHESES statement  */
#line 1539 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3851 "parser.tab.c"
    break;

  case 218: /* iteration_statement: DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON  */
#line 1549 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-5].symbol_info)->code+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3865 "parser.tab.c"
    break;

  case 219: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement  */
#line 1559 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 3879 "parser.tab.c"
    break;

  case 220: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement  */
#line 1569 "src/parser.y"
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
#line 3896 "parser.tab.c"
    break;

  case 221: /* jump_statement: GOTO ID SEMICOLON  */
#line 1585 "src/parser.y"
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
#line 3923 "parser.tab.c"
    break;

  case 222: /* jump_statement: CONTINUE SEMICOLON  */
#line 1608 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_continue=true;
		(yyval.symbol_info)->code="\n continue \n";
	}
#line 3934 "parser.tab.c"
    break;

  case 223: /* jump_statement: BREAK SEMICOLON  */
#line 1615 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_break=true;
		(yyval.symbol_info)->code="\n break \n";
	}
#line 3945 "parser.tab.c"
    break;

  case 224: /* jump_statement: RETURN SEMICOLON  */
#line 1622 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type="void";
		(yyval.symbol_info)->code="\nRETURN\n";
	}
#line 3957 "parser.tab.c"
    break;

  case 225: /* jump_statement: RETURN expression SEMICOLON  */
#line 1630 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\nRETURN "+(yyvsp[-1].symbol_info)->place.first+"\n";
		debug("return ",(yyval.symbol_info)->code);
	}
#line 3970 "parser.tab.c"
    break;

  case 226: /* start_symbol: translation_unit  */
#line 1641 "src/parser.y"
{
    cleanTAC((yyvsp[0].symbol_info)->code);
}
#line 3978 "parser.tab.c"
    break;

  case 227: /* translation_unit: external_declaration  */
#line 1647 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
	}
#line 3986 "parser.tab.c"
    break;

  case 228: /* translation_unit: translation_unit external_declaration  */
#line 1651 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->code;
	}
#line 3994 "parser.tab.c"
    break;

  case 230: /* external_declaration: function_definition  */
#line 1659 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 4002 "parser.tab.c"
    break;

  case 233: /* $@6: %empty  */
#line 1668 "src/parser.y"
        {
		var_name=(yyvsp[0].symbol_info)->param_list;
		type_list=(yyvsp[0].symbol_info)->param_types;
	}
#line 4011 "parser.tab.c"
    break;

  case 234: /* function_definition: declaration_specifiers declarator $@6 compound_statement  */
#line 1673 "src/parser.y"
        {
        if(strcmp((yyvsp[-3].str),"void")==0){
		
			if((yyvsp[0].symbol_info)->return_type!="void"){
                error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
			}
		}
		else{
			if((yyvsp[0].symbol_info)->is_return==0){
                error_list.push_back("Line "+to_string(yylineno)+" : Missing return statement");
			}
			else{
				if((yyvsp[0].symbol_info)->return_type!=(yyvsp[-3].str)){
                    error_list.push_back("Line "+to_string(yylineno)+" : Return type not matched");
				}
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
#line 4045 "parser.tab.c"
    break;


#line 4049 "parser.tab.c"

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

#line 1705 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

void print_scope_table() {
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
	cerr<<"Scope is here"<<endl;
    }
}

int main() {
	symbol_info* new_symbol=new symbol_info();
	curr_scope->symbol_map["printf"]=new_symbol;
	curr_scope->symbol_map["scanf"]=new_symbol;
	yyparse();
	print_scope_table();
}
