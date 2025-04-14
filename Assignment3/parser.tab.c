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
    void print_scope_table();

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


#line 106 "parser.tab.c"

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
  YYSYMBOL_133_1 = 133,                    /* $@1  */
  YYSYMBOL_134_2 = 134,                    /* $@2  */
  YYSYMBOL_struct_or_union = 135,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 136,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 137,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 138, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 139,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 140,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 141,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 142,          /* enumerator_list  */
  YYSYMBOL_enumerator = 143,               /* enumerator  */
  YYSYMBOL_type_qualifier = 144,           /* type_qualifier  */
  YYSYMBOL_declarator = 145,               /* declarator  */
  YYSYMBOL_direct_declarator = 146,        /* direct_declarator  */
  YYSYMBOL_pointer = 147,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 148,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 149,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 150,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 151,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 152,          /* identifier_list  */
  YYSYMBOL_type_name = 153,                /* type_name  */
  YYSYMBOL_abstract_declarator = 154,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 155, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 156,              /* initializer  */
  YYSYMBOL_initializer_list = 157,         /* initializer_list  */
  YYSYMBOL_statement = 158,                /* statement  */
  YYSYMBOL_labeled_statement = 159,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 160,       /* compound_statement  */
  YYSYMBOL_161_3 = 161,                    /* $@3  */
  YYSYMBOL_162_4 = 162,                    /* $@4  */
  YYSYMBOL_163_5 = 163,                    /* $@5  */
  YYSYMBOL_164_6 = 164,                    /* $@6  */
  YYSYMBOL_statement_declaration_list = 165, /* statement_declaration_list  */
  YYSYMBOL_declaration_list = 166,         /* declaration_list  */
  YYSYMBOL_statement_list = 167,           /* statement_list  */
  YYSYMBOL_expression_statement = 168,     /* expression_statement  */
  YYSYMBOL_selection_statement = 169,      /* selection_statement  */
  YYSYMBOL_170_7 = 170,                    /* $@7  */
  YYSYMBOL_iteration_statement = 171,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 172,           /* jump_statement  */
  YYSYMBOL_start_symbol = 173,             /* start_symbol  */
  YYSYMBOL_translation_unit = 174,         /* translation_unit  */
  YYSYMBOL_external_declaration = 175,     /* external_declaration  */
  YYSYMBOL_function_definition = 176,      /* function_definition  */
  YYSYMBOL_177_8 = 177                     /* $@8  */
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
#define YYLAST   2115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
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
       0,    76,    76,    82,    88,    89,    90,    91,    98,    99,
     111,   128,   132,   133,   145,   149,   181,   211,   250,   321,
     322,   331,   342,   374,   410,   414,   423,   432,   461,   462,
     466,   473,   480,   487,   494,   501,   511,   516,   524,   525,
     533,   541,   555,   556,   569,   580,   581,   592,   606,   607,
     615,   623,   632,   643,   644,   652,   663,   664,   675,   676,
     690,   691,   705,   706,   718,   719,   730,   731,   735,   742,
     863,   864,   865,   866,   867,   868,   869,   870,   871,   872,
     873,   877,   881,   888,   892,   893,  1007,  1008,  1018,  1019,
    1020,  1024,  1027,  1034,  1063,  1112,  1113,  1114,  1115,  1116,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1143,  1156,  1142,  1169,  1170,  1190,  1191,  1195,
    1196,  1208,  1227,  1228,  1232,  1237,  1245,  1246,  1247,  1251,
    1252,  1253,  1257,  1258,  1262,  1263,  1267,  1268,  1272,  1276,
    1282,  1290,  1291,  1302,  1306,  1319,  1320,  1335,  1336,  1337,
    1338,  1342,  1343,  1348,  1358,  1362,  1369,  1380,  1388,  1394,
    1403,  1404,  1408,  1409,  1413,  1414,  1415,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,  1427,  1431,  1436,  1437,  1441,
    1442,  1454,  1459,  1463,  1467,  1468,  1469,  1474,  1501,  1529,
    1530,  1537,  1547,  1549,  1548,  1569,  1569,  1573,  1573,  1577,
    1577,  1583,  1595,  1606,  1615,  1622,  1629,  1633,  1637,  1640,
    1648,  1652,  1653,  1657,  1663,  1670,  1670,  1693,  1703,  1713,
    1723,  1739,  1762,  1769,  1776,  1784,  1795,  1804,  1808,  1812,
    1816,  1820,  1824,  1826,  1825,  1861,  1862
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
  "$@1", "$@2", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "compound_statement", "$@3", "$@4",
  "$@5", "$@6", "statement_declaration_list", "declaration_list",
  "statement_list", "expression_statement", "selection_statement", "$@7",
  "iteration_statement", "jump_statement", "start_symbol",
  "translation_unit", "external_declaration", "function_definition", "$@8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-248)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-234)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1724,    57,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,     8,  -248,  -248,  -248,  -248,  -248,
    -248,    39,   146,  -248,    25,  2067,  -248,  -248,    16,  -248,
    2067,  1772,    34,    29,    48,  1724,  -248,  -248,   -29,    40,
    -248,    -2,  -248,  -248,   146,  -248,    80,  -248,  1602,  -248,
    -248,    -4,  1558,  -248,     5,    19,  -248,    25,  -248,  1886,
    1154,  1810,    34,  -248,  -248,    40,    30,   -36,  -248,  -248,
    -248,  -248,    39,  -248,  1190,  1886,    76,    87,  -248,  2010,
    -248,    27,  -248,  -248,  -248,   510,   674,  1934,  1934,    33,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  1474,  -248,   834,  -248,  -248,  -248,  -248,  -248,  -248,
    1510,  1510,  -248,  -248,   158,  -248,  1554,  -248,    71,   155,
      77,   -45,   119,    59,    64,    97,    92,    52,  -248,   123,
    -248,  -248,    61,   136,   144,  -248,   128,   -20,  1554,  -248,
      40,  -248,  1190,   208,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  1554,   127,  -248,   149,   176,    44,   194,  1554,
     196,   239,  1074,   206,   211,   212,  -248,   214,  1234,  -248,
    -248,   137,  -248,  -248,  -248,   219,   346,   428,  -248,  -248,
    -248,  -248,   213,   216,   914,  1972,   592,   834,  -248,  -248,
     147,     6,   215,  1554,  -248,  -248,  1554,  1270,   273,  -248,
    -248,   276,  -248,  1554,  1554,  1554,  1554,  1554,  1554,  1554,
    1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,
    1554,  1554,  -248,  1314,  1648,  -248,    68,  -248,   159,  -248,
     298,  -248,   277,  -248,  -248,  -248,  -248,    -5,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  1554,
    1558,  -248,    27,  -248,  1554,  -248,   754,  -248,   224,  -248,
     225,   259,  1074,  1554,  1350,   233,  1554,  -248,   161,  1554,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
     994,   234,  -248,  1686,   167,  -248,  1554,    73,  -248,   171,
    -248,  -248,  -248,  -248,  -248,  -248,    71,    71,   155,   155,
      77,    77,    77,    77,   -45,   -45,   119,    59,    64,    97,
     173,    92,  -248,   235,  -248,   245,   248,   159,  1394,  1848,
    -248,  -248,  -248,  -248,  1110,  -248,  2029,  -248,  -248,  -248,
    -248,  1074,  -248,   254,  -248,   172,  1350,  1554,   179,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  1554,  1554,  -248,  -248,
    -248,  -248,   256,  -248,   255,  -248,  -248,  -248,  -248,  1554,
    1074,  1430,   183,  1074,  -248,  -248,  -248,  -248,   184,   294,
    1074,   187,  1074,  -248,   263,  1074,  -248,  1074,  -248,  -248,
    -248,  -248
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     229,   140,    98,   117,   136,    97,   100,   105,   103,   106,
      96,   102,   104,   101,     0,    99,   107,    95,   118,   108,
     137,     0,   147,   231,     0,    86,    88,   109,     0,   110,
      89,     0,   139,     0,     0,   226,   227,   230,   131,     0,
     140,     0,   151,   149,   148,    84,     0,    91,     0,   111,
      87,   116,     0,    90,     0,   193,   205,     0,   236,     0,
       0,     0,   138,     1,   228,     0,   134,     0,   132,   141,
     152,   150,     0,    85,     0,     0,     0,     0,   122,     0,
     119,     0,   123,   207,   192,     0,     0,     0,     0,    93,
     206,   235,     2,     5,     8,     4,     6,     3,     7,     9,
      10,     0,   143,     0,    32,    33,    31,    30,    35,    34,
       0,     0,    11,    14,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    83,     0,
     111,   146,   159,     0,   153,   155,     0,     0,     0,   129,
       0,    92,     0,    36,    68,   176,    94,   232,   234,   113,
     115,   120,     0,     0,   124,   126,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,   211,
      81,     0,   208,   181,   182,     0,     0,     0,   183,   184,
     185,   186,     0,    10,     0,     0,     0,     0,    28,    10,
       0,   162,     0,     0,    25,    26,     0,     0,     0,    20,
      21,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,   157,   164,   158,   165,   144,
       0,   145,     0,   130,   135,   133,   179,     0,    70,    74,
      75,    71,    72,    73,    78,    80,    79,    76,    77,     0,
       0,   127,     0,   121,     0,   207,   189,   223,     0,   222,
       0,     0,     0,     0,     0,     0,     0,   224,     0,     0,
     212,   194,   205,   202,   208,   201,   210,   196,   209,   198,
       0,     0,    13,     0,   164,   163,     0,     0,    16,     0,
      22,    18,    19,    39,    40,    41,    43,    44,    46,    47,
      49,    50,    51,    52,    54,    55,    57,    59,    61,    63,
       0,    65,   168,     0,   172,     0,     0,   166,     0,     0,
     154,   156,   161,   177,     0,    69,     0,   125,   128,   188,
     187,     0,   221,     0,   191,     0,     0,     0,     0,   225,
      82,   200,    29,    37,    15,    17,     0,     0,   169,   173,
     167,   170,     0,   174,     0,   178,   180,   114,   190,     0,
       0,     0,     0,     0,    23,    67,   171,   175,     0,   213,
       0,     0,     0,   217,     0,     0,   219,     0,   216,   218,
     214,   220
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,  -248,  -248,   -54,  -248,  -102,    47,    49,
     -32,    53,   104,   105,   107,   113,   110,  -248,   -55,   -72,
    -248,   -81,  -106,    10,     0,  -248,   286,  -248,   -40,  -248,
    -248,  -248,  -248,    98,   -71,   -88,  -248,   118,  -248,   297,
     257,   -21,    -8,   -24,   -18,  -248,   -58,  -248,   129,  -248,
     186,  -114,  -206,  -135,  -248,   -49,  -248,   112,  -248,  -248,
    -248,  -248,    93,    -7,   -75,  -247,  -248,  -248,  -248,  -248,
    -248,  -248,   339,  -248,  -248
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   112,   113,   114,   289,   143,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   144,   170,
     249,   171,   129,    56,    57,    46,    47,    25,    26,    27,
      77,   250,    28,    79,    80,    81,   153,   154,    29,    67,
      68,    30,    31,    32,    33,    44,   315,   134,   135,   136,
     192,   316,   228,   146,   237,   172,   173,   174,    85,    86,
      87,    88,   175,   176,   177,   178,   179,   265,   180,   181,
      34,    35,    36,    37,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    42,   145,   133,    43,   128,   115,   236,   151,    62,
      23,   184,    78,    41,   202,   191,    48,   336,   227,    38,
     317,   139,   190,    70,    59,    50,    71,    51,   140,    65,
      53,    82,   234,   210,   211,    24,    40,   233,    40,    78,
      40,    75,   212,   213,   140,    23,   251,   188,    63,    89,
      40,    66,   323,   258,  -112,  -111,   194,   195,    82,   324,
      69,   132,   115,    78,    89,   223,    39,   283,  -111,    90,
     145,    83,    40,   155,    52,    22,    84,   285,   317,    40,
     185,   186,    82,   128,   115,    90,    21,   268,    21,   361,
      21,    45,   152,    60,    22,    61,    22,   128,   115,   191,
      21,   293,   294,   295,   128,   115,   190,   138,    22,   256,
      74,   280,   190,   261,   226,   287,  -111,   313,  -111,  -111,
     223,  -111,   224,  -111,   225,   290,  -111,   223,   274,   224,
      22,   216,   220,   344,    55,   278,   221,   269,   217,   310,
     203,   204,   205,    58,    72,   149,    73,    78,   328,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,    82,   115,   128,   115,
     218,    91,     4,   284,   208,   219,   209,   325,   300,   301,
     302,   303,   335,   222,   343,   338,   272,   147,   148,   356,
     231,   252,   232,   253,    20,    90,    90,   340,   229,   128,
     115,   269,    62,   270,   214,   215,   226,   330,   230,   282,
      78,   269,   352,   334,   254,    22,    41,   196,   318,   197,
     319,   198,   206,   207,   132,   269,   223,   339,   283,    82,
     132,   278,   115,   345,   360,   346,   269,   269,   347,   199,
     200,   363,   255,   269,   155,   372,   374,   269,   269,   377,
     260,   269,   145,   296,   297,   151,   362,   298,   299,   201,
     257,   354,   259,   128,   115,   284,   329,   304,   305,   273,
     275,   262,   263,   264,   364,   266,   271,   286,   368,   276,
     371,   256,   358,   132,   291,   238,    78,   292,   322,   331,
     333,   332,   365,   115,   337,   348,   342,   239,   240,   241,
     242,   243,   244,   245,   246,    82,   247,   349,   248,    49,
     350,   369,     2,     3,   373,   359,   366,   367,   375,   132,
     306,   376,   307,   378,     4,   308,   380,     5,   381,   379,
       6,   311,   309,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   156,   326,    92,
      93,    94,    95,    96,    97,    98,    99,   157,   141,   321,
       2,     3,   137,   158,   159,   160,   161,   162,   163,   164,
     327,   165,     4,   281,    64,     5,   166,   167,     6,   168,
     101,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,   235,     0,     0,
     320,     0,     0,  -204,    55,     0,     0,   103,     0,     0,
       0,     0,   169,   104,   105,   106,     0,     0,   107,     0,
       0,   108,   109,     0,     0,     0,     0,   110,   111,   156,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   157,
       0,     0,     2,     3,     0,   158,   159,   160,   161,   162,
     163,   164,     0,   165,     4,     0,     0,     5,   166,   167,
       6,   168,   101,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,  -203,    55,     0,     0,   103,
       0,     0,     0,     0,   169,   104,   105,   106,     0,     0,
     107,     0,     0,   108,   109,     0,     0,     0,     0,   110,
     111,   156,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   157,     0,     0,     2,     3,     0,   158,   159,   160,
     161,   162,   163,   164,     0,   165,     4,     0,     0,     5,
     166,   167,     6,   168,   101,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,   103,     0,     0,     0,     0,   169,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,     0,     0,
       0,   110,   111,   182,     0,    92,    93,    94,    95,    96,
      97,    98,    99,   157,     0,     0,     2,     3,     0,   158,
     159,   160,   161,   162,   163,   164,     0,   165,     4,     0,
       0,     5,   166,   167,     6,   168,   101,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,   103,     0,     0,     0,     0,   169,   104,
     105,   106,     0,     0,   107,     0,     0,   108,   109,     0,
       0,     0,     0,   110,   111,   182,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   183,     0,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   163,   164,     0,   165,
       0,     0,     0,     0,   166,   167,     0,   168,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,   103,     0,     0,     0,     0,
     169,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   157,     0,     0,     2,     3,
       0,   158,   159,   160,   161,   162,   163,   164,     0,   165,
       4,     0,     0,     5,   166,   167,     6,   168,   101,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,   103,     0,     0,     0,     0,
     169,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   189,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     6,     0,   101,     7,
       8,     9,     0,    11,    12,    13,    14,     0,    16,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   183,     0,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   163,   164,     0,   165,
       0,     0,     0,     0,   166,   167,     0,   168,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,    55,     0,     0,   103,     0,     0,     0,     0,
     169,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   183,     0,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   163,   164,     0,   165,
       0,     0,     0,     0,   166,   167,     0,   168,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   341,    55,     0,     0,   103,     0,     0,     0,     0,
     169,   104,   105,   106,     0,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   183,     0,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   163,   164,     0,   165,
       0,     0,     0,     0,   166,   167,     0,   168,   101,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,   103,     0,     0,     0,     0,
     169,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,   355,   142,     0,
       0,   103,     0,     0,     0,     0,     0,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,   101,     0,
       0,   110,   111,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,   142,     0,
       0,   103,     0,     0,     0,     0,     0,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,   101,     0,
       0,   110,   111,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
     267,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   288,     0,     0,     0,     0,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,   101,     0,
       0,   110,   111,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   169,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,   101,     0,
       0,   110,   111,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,   103,     0,     0,     0,     0,
       0,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,   103,   370,     0,     0,     0,     0,   104,   105,   106,
       0,     0,   107,     0,     0,   108,   109,     0,   101,     0,
       0,   110,   111,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,   104,   105,   106,   101,     0,   107,     0,     0,   108,
     109,     0,     0,     0,     0,   110,   111,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,    49,
       0,   193,     0,     3,     0,     0,     0,   104,   105,   106,
       0,     0,   107,     0,     4,   108,   109,     0,   101,     0,
       6,   110,   111,     7,     8,     9,     0,    11,    12,    13,
      14,     0,    16,    54,    18,    19,    20,     0,     0,     0,
       0,     0,     0,    49,     0,   103,     2,     3,     0,     0,
       0,   104,   105,   106,     0,     0,   107,     0,     4,   108,
     109,     5,     0,     0,     6,   110,   111,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     1,
    -233,     0,     2,     3,     0,     0,   -93,     0,   -93,     0,
       0,     0,     0,     0,     4,     0,     0,     5,     0,    74,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    49,     0,     0,
       2,     3,     0,     0,     0,     0,     0,   223,     0,   224,
     314,     0,     4,     0,     0,     5,     0,    22,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     1,     0,     0,     2,     3,
       0,     0,     0,     0,     0,   223,     0,   283,   314,     0,
       4,     0,     0,     5,     0,    22,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    21,     2,     3,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   130,     0,     0,     2,     3,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     4,     0,     0,     5,
       0,     0,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    49,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    49,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,     0,
     353,     0,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    49,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    49,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    49,     0,     0,     0,     3,     0,     0,     0,   279,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
      49,     0,     6,     0,     3,     7,     8,     9,     0,    11,
      12,    13,    14,     0,    16,     4,    18,    19,    20,     0,
       0,     6,     0,     0,     7,     8,     9,   150,    11,    12,
      13,    14,     0,    16,     0,    18,    19,    20,    49,     0,
       0,     2,     3,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     5,     0,     0,     6,
       0,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    22,    74,    61,    22,    60,    60,   142,    79,    33,
       0,    86,    52,    21,   116,   103,    24,   264,   132,    11,
     226,    57,   103,    44,    31,    25,    44,    11,    64,    58,
      30,    52,   138,    78,    79,    35,    11,    57,    11,    79,
      11,    48,    87,    88,    64,    35,   152,   101,     0,    57,
      11,    11,    57,   159,    58,    11,   110,   111,    79,    64,
      62,    61,   116,   103,    72,    59,    58,    61,    11,    59,
     142,    66,    11,    81,    58,    69,    57,   191,   284,    11,
      87,    88,   103,   138,   138,    75,    61,   168,    61,   336,
      61,    66,    65,    59,    69,    61,    69,   152,   152,   187,
      61,   203,   204,   205,   159,   159,   187,    77,    69,    65,
      77,   186,   193,   162,   132,   196,    59,   223,    61,    62,
      59,    64,    61,    66,   132,   197,    69,    59,   177,    61,
      69,    72,    80,    60,    58,   184,    84,    64,    74,   220,
      69,    70,    71,    31,    64,    58,    66,   187,   254,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   187,   221,   223,   223,
      73,    59,    26,   191,    97,    83,    99,   249,   210,   211,
     212,   213,   263,    60,   286,   266,   176,    75,    76,   324,
      62,    64,    64,    66,    48,   185,   186,   269,    62,   254,
     254,    64,   226,    66,    85,    86,   224,   256,    64,    62,
     250,    64,   318,   262,    65,    69,   224,    59,    59,    61,
      61,    63,    67,    68,   224,    64,    59,    66,    61,   250,
     230,   280,   286,    62,    62,    64,    64,    64,    65,    81,
      82,    62,    66,    64,   252,    62,    62,    64,    64,    62,
      11,    64,   324,   206,   207,   326,   337,   208,   209,   101,
      66,   319,    66,   318,   318,   283,   256,   214,   215,   176,
     177,    65,    61,    61,   346,    61,    57,    62,   359,    66,
     361,    65,   331,   283,    11,    77,   326,    11,    11,    65,
      31,    66,   347,   347,    61,    60,    62,    89,    90,    91,
      92,    93,    94,    95,    96,   326,    98,    62,   100,    11,
      62,   360,    14,    15,   363,    61,    60,    62,    24,   319,
     216,   370,   217,   372,    26,   218,   375,    29,   377,    66,
      32,   221,   219,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     1,   250,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    72,   230,
      14,    15,    65,    17,    18,    19,    20,    21,    22,    23,
     252,    25,    26,   187,    35,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,   140,    -1,    -1,
     102,    -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    82,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    -1,    75,    76,    -1,    34,    -1,
      -1,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    34,    -1,    72,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    82,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    11,
      -1,    61,    -1,    15,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    26,    75,    76,    -1,    34,    -1,
      32,    81,    82,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    44,     1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    61,    14,    15,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    26,    75,
      76,    29,    -1,    -1,    32,    81,    82,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      58,    -1,    14,    15,    -1,    -1,    64,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    77,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    11,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,
      62,    -1,    26,    -1,    -1,    29,    -1,    69,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    11,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,    -1,
      26,    -1,    -1,    29,    -1,    69,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    61,    14,    15,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    11,
      -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    11,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    11,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    11,    -1,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      11,    -1,    32,    -1,    15,    35,    36,    37,    -1,    39,
      40,    41,    42,    -1,    44,    26,    46,    47,    48,    -1,
      -1,    32,    -1,    -1,    35,    36,    37,    57,    39,    40,
      41,    42,    -1,    44,    -1,    46,    47,    48,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    15,    26,    29,    32,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    61,    69,   126,   127,   130,   131,   132,   135,   141,
     144,   145,   146,   147,   173,   174,   175,   176,    11,    58,
      11,   145,   144,   147,   148,    66,   128,   129,   145,    11,
     127,    11,    58,   127,     1,    58,   126,   127,   160,   166,
      59,    61,   146,     0,   175,    58,    11,   142,   143,    62,
     144,   147,    64,    66,    77,   166,   177,   133,   131,   136,
     137,   138,   144,    66,    57,   161,   162,   163,   164,   145,
     126,   160,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    34,    60,    61,    67,    68,    69,    72,    75,    76,
      81,    82,   104,   105,   106,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   125,
      11,    62,   127,   149,   150,   151,   152,   142,    77,    57,
      64,   129,    58,   108,   121,   122,   156,   160,   160,    58,
      57,   137,    65,   139,   140,   145,     1,    11,    17,    18,
      19,    20,    21,    22,    23,    25,    30,    31,    33,    66,
     122,   124,   158,   159,   160,   165,   166,   167,   168,   169,
     171,   172,     1,    11,   167,   166,   166,    61,   108,    11,
     124,   138,   153,    61,   108,   108,    59,    61,    63,    81,
      82,   101,   110,    69,    70,    71,    67,    68,    97,    99,
      78,    79,    87,    88,    85,    86,    72,    74,    73,    83,
      80,    84,    60,    59,    61,   145,   147,   154,   155,    62,
      64,    62,    64,    57,   125,   143,   156,   157,    77,    89,
      90,    91,    92,    93,    94,    95,    96,    98,   100,   123,
     134,   125,    64,    66,    65,    66,    65,    66,   125,    66,
      11,   158,    65,    61,    61,   170,    61,    66,   124,    64,
      66,    57,   126,   165,   158,   165,    66,    57,   158,    57,
     167,   153,    62,    61,   147,   154,    62,   124,    62,   107,
     122,    11,    11,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   116,   117,   118,
     124,   119,    60,   125,    62,   149,   154,   155,    59,    61,
     102,   151,    11,    57,    64,   122,   136,   140,   125,   126,
     158,    65,    66,    31,   158,   124,   168,    61,   124,    66,
     122,    57,    62,   110,    60,    62,    64,    65,    60,    62,
      62,    60,   125,    62,   149,    57,   156,    57,   158,    61,
      62,   168,   124,    62,   122,   121,    60,    62,   124,   158,
      62,   124,    62,   158,    62,    24,   158,    62,   158,    66,
     158,   158
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
     131,   131,   133,   134,   132,   132,   132,   135,   135,   136,
     136,   137,   138,   138,   139,   139,   140,   140,   140,   141,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   151,
     152,   152,   153,   153,   154,   154,   154,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   156,   156,   156,   157,
     157,   158,   158,   158,   158,   158,   158,   159,   159,   159,
     159,   159,   160,   161,   160,   162,   160,   163,   160,   164,
     160,   165,   165,   165,   165,   166,   166,   166,   167,   167,
     167,   168,   168,   169,   169,   170,   169,   171,   171,   171,
     171,   172,   172,   172,   172,   172,   173,   174,   174,   174,
     175,   175,   176,   177,   176,   176,   176
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
       1,     1,     0,     0,     7,     4,     2,     1,     1,     1,
       2,     3,     1,     1,     1,     3,     1,     2,     3,     4,
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
#line 77 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "int", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(int*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1928 "parser.tab.c"
    break;

  case 3: /* constant: FLOAT_LITERAL  */
#line 83 "src/parser.y"
        {
		(yyval.symbol_info)= new symbol_info("", "float", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
		(yyval.symbol_info)->place=qid(std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr)),nullptr);
		(yyval.symbol_info)->code=std::to_string(*(float*)((yyvsp[0].symbol_info)->ptr));
	}
#line 1938 "parser.tab.c"
    break;

  case 4: /* constant: EXP_LITERAL  */
#line 88 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "exp", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1944 "parser.tab.c"
    break;

  case 5: /* constant: HEXA_LITERAL  */
#line 89 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "hexa", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1950 "parser.tab.c"
    break;

  case 6: /* constant: REAL_LITERAL  */
#line 90 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "real", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1956 "parser.tab.c"
    break;

  case 7: /* constant: STRING_LITERAL  */
#line 92 "src/parser.y"
        {
		(yyval.symbol_info) = new symbol_info("", "char*", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);
        (yyval.symbol_info)->str_val=(yyvsp[0].symbol_info)->str_val;
        (yyval.symbol_info)->place=qid((yyvsp[0].symbol_info)->str_val,nullptr);
        (yyval.symbol_info)->code=(yyvsp[0].symbol_info)->str_val;
	}
#line 1967 "parser.tab.c"
    break;

  case 8: /* constant: OCTAL_LITERAL  */
#line 98 "src/parser.y"
                         {(yyval.symbol_info) = new symbol_info("", "octal", (yyvsp[0].symbol_info)->ptr, (yyvsp[0].symbol_info)->symbol_size);}
#line 1973 "parser.tab.c"
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
#line 1986 "parser.tab.c"
    break;

  case 10: /* primary_expression: ID  */
#line 112 "src/parser.y"
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
#line 2007 "parser.tab.c"
    break;

  case 11: /* primary_expression: constant  */
#line 129 "src/parser.y"
        {
		(yyval.symbol_info) = (yyvsp[0].symbol_info);
	}
#line 2015 "parser.tab.c"
    break;

  case 13: /* primary_expression: LPARENTHESES expression RPARENTHESES  */
#line 134 "src/parser.y"
        {
		symbol_info* new_symbol = new symbol_info();
		new_symbol->place=newtemp((yyvsp[-1].symbol_info)->type,curr_scope);
		new_symbol->type=(yyvsp[-1].symbol_info)->type;
		// debug("here ",new_symbol->place.first);
		new_symbol->code=(yyvsp[-1].symbol_info)->code+"\n"+new_symbol->place.first+":= ("+(yyvsp[-1].symbol_info)->place.first+")";
		(yyval.symbol_info)=new_symbol;
	}
#line 2028 "parser.tab.c"
    break;

  case 14: /* postfix_expression: primary_expression  */
#line 146 "src/parser.y"
        {
            (yyval.symbol_info)=(yyvsp[0].symbol_info);
        }
#line 2036 "parser.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 150 "src/parser.y"
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
#line 2072 "parser.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression LPARENTHESES RPARENTHESES  */
#line 182 "src/parser.y"
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
#line 2106 "parser.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression LPARENTHESES argument_expression_list RPARENTHESES  */
#line 212 "src/parser.y"
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
#line 2149 "parser.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression DOT ID  */
#line 251 "src/parser.y"
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
#line 2224 "parser.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression INCREMENT  */
#line 323 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"+1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"+1";
		
	}
#line 2237 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression DECREMENT  */
#line 332 "src/parser.y"
        {
		if((yyvsp[-1].symbol_info)->is_array==true){
			string code = get_last_line((yyvsp[-1].symbol_info)->code);
			(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + code + ":= "+code+"-1\n";
		}
		else  (yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[-1].symbol_info)->place.first+":=  "+(yyvsp[-1].symbol_info)->place.first+"-1";
	}
#line 2249 "parser.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 343 "src/parser.y"
    { 
		if((yyvsp[0].symbol_info)->place.first!=""){
			
			(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->place.first);
		}
		else{
			// debug("gggggggggggggg ", $1->code);
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
#line 2285 "parser.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 376 "src/parser.y"
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
#line 2321 "parser.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 411 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);        
	}
#line 2329 "parser.tab.c"
    break;

  case 25: /* unary_expression: INCREMENT unary_expression  */
#line 415 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->place=(yyvsp[0].symbol_info)->place;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->place.first+":=  "+(yyvsp[0].symbol_info)->place.first+"+1";
		
	}
#line 2342 "parser.tab.c"
    break;

  case 26: /* unary_expression: DECREMENT unary_expression  */
#line 424 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->place=(yyvsp[0].symbol_info)->place;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->place.first+":=  "+(yyvsp[0].symbol_info)->place.first+"-1";
		
	}
#line 2355 "parser.tab.c"
    break;

  case 27: /* unary_expression: unary_operator cast_expression  */
#line 433 "src/parser.y"
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
        // if($1->code=="-"){
        //     debug("ddddd",$2->name);
        //     qid var=newtemp($2->type,curr_scope);
			
        //     if($2->name!="") $$->code=$2->code+"\n"+var.first+":= -"+$2->name;
        //     else if($2->place.first!="") $$->code=$2->code+"\n"+var.first+":= -"+$2->place.first;
        //     $$->place=var;
		// }
		
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place.first=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->place.first;
	}
#line 2388 "parser.tab.c"
    break;

  case 30: /* unary_operator: AMPERSAND  */
#line 466 "src/parser.y"
                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="ampersand";
		(yyval.symbol_info)->code="&";
        (yyval.symbol_info)->pointer_depth++;
	}
#line 2400 "parser.tab.c"
    break;

  case 31: /* unary_operator: STAR  */
#line 474 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="star";
		(yyval.symbol_info)->code="*";
	}
#line 2411 "parser.tab.c"
    break;

  case 32: /* unary_operator: PLUS  */
#line 481 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="plus";
		(yyval.symbol_info)->code="+";
	}
#line 2422 "parser.tab.c"
    break;

  case 33: /* unary_operator: MINUS  */
#line 488 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="minus";
		(yyval.symbol_info)->code="-";
	}
#line 2433 "parser.tab.c"
    break;

  case 34: /* unary_operator: TILDE  */
#line 495 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="tilde";
		(yyval.symbol_info)->code="~";
	}
#line 2444 "parser.tab.c"
    break;

  case 35: /* unary_operator: EXCLAMATION  */
#line 502 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->name="exclamation";
		(yyval.symbol_info)->code="!";
	}
#line 2455 "parser.tab.c"
    break;

  case 36: /* cast_expression: unary_expression  */
#line 512 "src/parser.y"
        {
		
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2464 "parser.tab.c"
    break;

  case 37: /* cast_expression: LPARENTHESES type_name RPARENTHESES cast_expression  */
#line 517 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[0].symbol_info);
        (yyval.symbol_info)->type = (yyvsp[-2].symbol_info)->type;
    }
#line 2473 "parser.tab.c"
    break;

  case 38: /* multiplicative_expression: cast_expression  */
#line 524 "src/parser.y"
                          {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2479 "parser.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 526 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"*"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2491 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression DIVIDE cast_expression  */
#line 534 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
        (yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"/"+(yyvsp[0].symbol_info)->place.first;
        (yyval.symbol_info)->place=var;
    }
#line 2503 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 542 "src/parser.y"
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
#line 2518 "parser.tab.c"
    break;

  case 42: /* additive_expression: multiplicative_expression  */
#line 555 "src/parser.y"
                                    {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2524 "parser.tab.c"
    break;

  case 43: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 557 "src/parser.y"
        {
        // cerr<<$1->type<<endl;
        // cerr<<$3->type<<endl;
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        if(count_star((yyvsp[-2].symbol_info)->type)>count_star((yyvsp[0].symbol_info)->type)) (yyval.symbol_info)->type=(yyvsp[-2].symbol_info)->type;
        else if(count_star((yyvsp[-2].symbol_info)->type)<count_star((yyvsp[0].symbol_info)->type)) (yyval.symbol_info)->type=(yyvsp[0].symbol_info)->type;
        else (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        // cerr<<$$->type<<endl;
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"+"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2541 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 570 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"-"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2553 "parser.tab.c"
    break;

  case 45: /* shift_expression: additive_expression  */
#line 580 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2559 "parser.tab.c"
    break;

  case 46: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 582 "src/parser.y"
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
#line 2574 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 593 "src/parser.y"
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
#line 2589 "parser.tab.c"
    break;

  case 48: /* relational_expression: shift_expression  */
#line 606 "src/parser.y"
                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2595 "parser.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LESS_THAN shift_expression  */
#line 608 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2607 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GREATER_THAN shift_expression  */
#line 616 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];        
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">"+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2619 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression LESS_EQUALS shift_expression  */
#line 624 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"<="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	
	}
#line 2632 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER_EQUALS shift_expression  */
#line 633 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+">="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2644 "parser.tab.c"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 643 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2650 "parser.tab.c"
    break;

  case 54: /* equality_expression: equality_expression REL_EQUALS relational_expression  */
#line 645 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"=="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2662 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression REL_NOT_EQ relational_expression  */
#line 653 "src/parser.y"
        {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
		qid var=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code +"\n" + var.first+":=  "+(yyvsp[-2].symbol_info)->place.first+"!="+(yyvsp[0].symbol_info)->place.first;
		(yyval.symbol_info)->place=var;
	}
#line 2674 "parser.tab.c"
    break;

  case 56: /* and_expression: equality_expression  */
#line 663 "src/parser.y"
                              {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2680 "parser.tab.c"
    break;

  case 57: /* and_expression: and_expression AMPERSAND equality_expression  */
#line 665 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : And operator can only be used with int type");
        }
    }
#line 2692 "parser.tab.c"
    break;

  case 58: /* exclusive_or_expression: and_expression  */
#line 675 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2698 "parser.tab.c"
    break;

  case 59: /* exclusive_or_expression: exclusive_or_expression XOR and_expression  */
#line 677 "src/parser.y"
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
#line 2713 "parser.tab.c"
    break;

  case 60: /* inclusive_or_expression: exclusive_or_expression  */
#line 690 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2719 "parser.tab.c"
    break;

  case 61: /* inclusive_or_expression: inclusive_or_expression OR exclusive_or_expression  */
#line 692 "src/parser.y"
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
#line 2734 "parser.tab.c"
    break;

  case 62: /* logical_and_expression: inclusive_or_expression  */
#line 705 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2740 "parser.tab.c"
    break;

  case 63: /* logical_and_expression: logical_and_expression REL_AND inclusive_or_expression  */
#line 707 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : AND operator can only be used with int type");
        }
        
    }
#line 2753 "parser.tab.c"
    break;

  case 64: /* logical_or_expression: logical_and_expression  */
#line 718 "src/parser.y"
                                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2759 "parser.tab.c"
    break;

  case 65: /* logical_or_expression: logical_or_expression REL_OR logical_and_expression  */
#line 720 "src/parser.y"
    {
        (yyval.symbol_info) = (yyvsp[-2].symbol_info);
        (yyval.symbol_info)->type = priority_to_type[max(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[(yyvsp[0].symbol_info)->type])];
        if((yyval.symbol_info)->type!="int"){
            error_list.push_back("Line "+to_string(yylineno)+" : OR operator can only be used with int type");
        }
    }
#line 2771 "parser.tab.c"
    break;

  case 66: /* conditional_expression: logical_or_expression  */
#line 730 "src/parser.y"
                                                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2777 "parser.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 736 "src/parser.y"
        {
		
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		// cerr<<"hereeeeee "<<$$->name<<endl;
		// cerr<<"hereeeeee "<<$$->type<<endl;
	}
#line 2788 "parser.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 743 "src/parser.y"
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
                    if((yyvsp[0].symbol_info)->type!="int" && (yyvsp[-2].symbol_info)->type!="int") error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment");
                }
                else if(type_priority[(yyvsp[-2].symbol_info)->type]<type_priority[(yyvsp[0].symbol_info)->type]){
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in assignment3");
                }
                string third_code=(yyvsp[0].symbol_info)->code;
                string first_code=(yyvsp[-2].symbol_info)->code;
                if(min(type_priority[(yyvsp[-2].symbol_info)->type],type_priority[find_symbol->type])>0) find_symbol->type=priority_to_type[max(type_priority[find_symbol->type],type_priority[(yyvsp[0].symbol_info)->type])];
			
                find_symbol->name=(yyvsp[-2].symbol_info)->name;
                find_symbol->place=(yyvsp[-2].symbol_info)->place;
                find_symbol->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code + "\n" + (yyvsp[-2].symbol_info)->place.first + ":=  " + (yyvsp[0].symbol_info)->place.first;
                find_symbol->pointer_depth=max((yyvsp[-2].symbol_info)->pointer_depth, (yyvsp[0].symbol_info)->pointer_depth);
                // cerr<<$1->name<<"  ||||  "<<$1->pointer_depth<<endl;
                // cerr<<$3->name<<"  ||||  "<<$3->pointer_depth<<endl;
                // cerr<<"find symbol name "<<find_symbol->name<<endl;
                // cerr<<"find symbol pointer depth "<<find_symbol->pointer_depth<<endl;
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
#line 2910 "parser.tab.c"
    break;

  case 70: /* assignment_operator: EQUALS  */
#line 863 "src/parser.y"
                 {(yyval.symbol_info)=new symbol_info("","equals",nullptr,0); (yyval.symbol_info)->code="=";}
#line 2916 "parser.tab.c"
    break;

  case 71: /* assignment_operator: ASSIGN_STAR  */
#line 864 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_star",nullptr,0); (yyval.symbol_info)->code="*=";}
#line 2922 "parser.tab.c"
    break;

  case 72: /* assignment_operator: ASSIGN_DIV  */
#line 865 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_div",nullptr,0); (yyval.symbol_info)->code="/=";}
#line 2928 "parser.tab.c"
    break;

  case 73: /* assignment_operator: ASSIGN_MOD  */
#line 866 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_mod",nullptr,0); (yyval.symbol_info)->code="%=";}
#line 2934 "parser.tab.c"
    break;

  case 74: /* assignment_operator: ASSIGN_PLUS  */
#line 867 "src/parser.y"
                      {(yyval.symbol_info)=new symbol_info("","assign_plus",nullptr,0); (yyval.symbol_info)->code="+=";}
#line 2940 "parser.tab.c"
    break;

  case 75: /* assignment_operator: ASSIGN_MINUS  */
#line 868 "src/parser.y"
                       {(yyval.symbol_info)=new symbol_info("","assign_minus",nullptr,0); (yyval.symbol_info)->code="-=";}
#line 2946 "parser.tab.c"
    break;

  case 76: /* assignment_operator: LEFT_SHIFT_EQ  */
#line 869 "src/parser.y"
                        {(yyval.symbol_info)=new symbol_info("","left_shift_eq",nullptr,0); (yyval.symbol_info)->code="<<=";}
#line 2952 "parser.tab.c"
    break;

  case 77: /* assignment_operator: RIGHT_SHIFT_EQ  */
#line 870 "src/parser.y"
                         {(yyval.symbol_info)=new symbol_info("","right_shift_eq",nullptr,0); (yyval.symbol_info)->code=">>=";}
#line 2958 "parser.tab.c"
    break;

  case 78: /* assignment_operator: ASSIGN_AND  */
#line 871 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_and",nullptr,0); (yyval.symbol_info)->code="&=";}
#line 2964 "parser.tab.c"
    break;

  case 79: /* assignment_operator: ASSIGN_XOR  */
#line 872 "src/parser.y"
                     {(yyval.symbol_info)=new symbol_info("","assign_xor",nullptr,0); (yyval.symbol_info)->code="^=";}
#line 2970 "parser.tab.c"
    break;

  case 80: /* assignment_operator: ASSIGN_OR  */
#line 873 "src/parser.y"
                    {(yyval.symbol_info)=new symbol_info("","assign_or",nullptr,0); (yyval.symbol_info)->code="|=";}
#line 2976 "parser.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 878 "src/parser.y"
        {
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 2984 "parser.tab.c"
    break;

  case 82: /* expression: expression COMMA assignment_expression  */
#line 882 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 2992 "parser.tab.c"
    break;

  case 83: /* constant_expression: conditional_expression  */
#line 888 "src/parser.y"
                                {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 2998 "parser.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 894 "src/parser.y"
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
                if(depth!=count_star(curr_scope->symbol_map[top_symbol]->type) && !curr_scope->symbol_map[top_symbol]->is_array){
                    error_list.push_back("Line "+to_string(yylineno)+" : Pointer depth mismatch");
                    flag = 1;
                }

				if (type_priority[(yyvsp[-2].str)] < type_priority[curr_scope->symbol_map[top_symbol]->type]) {
					
                    error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in declaration");
					flag = 1;
				}
				
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                if(type_priority[(yyvsp[-2].str)]>0 && type_priority[curr_scope->symbol_map[top_symbol]->type]>0) curr_scope->symbol_map[top_symbol]->type = priority_to_type[max(type_priority[(yyvsp[-2].str)], type_priority[curr_scope->symbol_map[top_symbol]->type])];
                if(std::string((yyvsp[-2].str)).substr(0,6) == "static"){
                    curr_scope->symbol_map[top_symbol]->is_static = true;
                }
				// debug("declaration specifiers121 ", $2->code);
				
				code+=(yyvsp[-1].symbol_info)->code;

			} else {
				
				curr_scope->symbol_map[top_symbol]->type = (yyvsp[-2].str);
                for(int i=0;i<depth;i++){
                    curr_scope->symbol_map[top_symbol]->type+="*";
                }
				if(curr_scope->symbol_map[top_symbol]->is_array) curr_scope->symbol_map[top_symbol]->type+="*";
                curr_scope->symbol_map[top_symbol]->name = top_symbol;
                curr_scope->symbol_map[top_symbol]->pointer_depth = depth;
				if((curr_scope->symbol_map[top_symbol]->type).substr(0,6)=="struct")
				{
					// cerr<<"gggggghjjj "<<$1<<endl;
					string struct_name=(curr_scope->symbol_map[top_symbol]->type).substr(7);
					if(struct_name.back()=='*') struct_name.pop_back();
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
                if(curr_scope->symbol_map[top_symbol]->is_array){
                    // debug("in the arr",curr_scope->symbol_map[top_symbol]->type.substr(0,3));
                    if(curr_scope->symbol_map[top_symbol]->type.substr(0,3)=="int"){
                        code=code+top_symbol+":= alloc " +to_string(4*curr_scope->symbol_map[top_symbol]->array_length)+"\n";
                    }
                    if(curr_scope->symbol_map[top_symbol]->type.substr(0,5)=="float"){
                        code=code+top_symbol+":= alloc " +to_string(4*curr_scope->symbol_map[top_symbol]->array_length)+"\n";
                    }
                    if(curr_scope->symbol_map[top_symbol]->type.substr(0,4)=="char"){
                        code=code+top_symbol+":= alloc " +to_string(2*curr_scope->symbol_map[top_symbol]->array_length)+"\n";
                    }
                    // debug("in the arr",code);
                    
                }
				
				symbol_info* new_symbol = new symbol_info();
				new_symbol = new symbol_info((yyvsp[-1].symbol_info));
				(yyval.symbol_info)=new_symbol;
				
			}
			
		}
		// debug("declaration specifiers ", to_string(parsing_stack.size()));
		(yyval.symbol_info)->code=code;
        // debug("in the arr11",$$->code);
		
		//debug("Declaration: ",curr_scope->symbol_map["p"]->code);
    }
#line 3112 "parser.tab.c"
    break;

  case 87: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 1009 "src/parser.y"
        {
		// debug("storage class specifier ", $1);
		// debug("storage class specifier ", $2);
		char* buf = (char*)malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 2); // 1 for comma, 1 for null terminator
		sprintf(buf, "%s,%s", (yyvsp[-1].str), (yyvsp[0].str));
		(yyval.str) = buf;
		// debug("storage class specifier ", $$);

	}
#line 3126 "parser.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier  */
#line 1018 "src/parser.y"
                         {(yyval.str)=(yyvsp[0].str);}
#line 3132 "parser.tab.c"
    break;

  case 91: /* init_declarator_list: init_declarator  */
#line 1024 "src/parser.y"
                      { 
        (yyval.symbol_info) = (yyvsp[0].symbol_info); 
    }
#line 3140 "parser.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 1027 "src/parser.y"
                                                 { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->code = (yyvsp[-2].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
    }
#line 3149 "parser.tab.c"
    break;

  case 93: /* init_declarator: declarator  */
#line 1034 "src/parser.y"
                 { 
		if(lookup_symbol_local((yyvsp[0].symbol_info)->name, curr_scope)!=nullptr){
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
                 // cerr<<"gggg"<<$1->type<<endl;
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
#line 3183 "parser.tab.c"
    break;

  case 94: /* init_declarator: declarator EQUALS initializer  */
#line 1063 "src/parser.y"
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
				(yyvsp[-2].symbol_info)->type=(yyvsp[-2].symbol_info)->type+"*";
				curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]->is_array=true;
				curr_scope->symbol_map[(yyvsp[-2].symbol_info)->name]->type=(yyvsp[-2].symbol_info)->type;
				 string code=(yyvsp[-2].symbol_info)->name+":= alloc ";
				if((yyvsp[-2].symbol_info)->type=="int*" || (yyvsp[-2].symbol_info)->type=="float*"){
					code=code+to_string(4*(yyvsp[-2].symbol_info)->array_length);
				}
				else if((yyvsp[-2].symbol_info)->type=="char*"){
					code=code+to_string(2*(yyvsp[-2].symbol_info)->array_length);
				}
				for(int i=0;i<(yyvsp[-2].symbol_info)->array_length;i++){
					qid temp=newtemp((yyvsp[-2].symbol_info)->type,curr_scope);
					code=code+"\n"+temp.first+":= "+to_string(i)+"*";
					if((yyvsp[-2].symbol_info)->type=="int*") code=code+"4\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+to_string(*(int*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="float*") code=code+"4\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+to_string(*(float*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="char*") code=code+"2\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+char(*(char*)((yyvsp[-2].symbol_info)->int_array[i]->ptr));
					else if((yyvsp[-2].symbol_info)->type=="char**") code=code+"2\n"+"*( "+(yyvsp[-2].symbol_info)->name+" + "+temp.first+" ):= "+(yyvsp[-2].symbol_info)->int_array[i]->str_val;
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
#line 3234 "parser.tab.c"
    break;

  case 100: /* type_specifier: VOID  */
#line 1120 "src/parser.y"
                                        {(yyval.str)=strdup("void");}
#line 3240 "parser.tab.c"
    break;

  case 101: /* type_specifier: CHAR  */
#line 1121 "src/parser.y"
                                        {(yyval.str)=strdup("char");}
#line 3246 "parser.tab.c"
    break;

  case 102: /* type_specifier: SHORT  */
#line 1122 "src/parser.y"
                                        {(yyval.str)=strdup("short");}
#line 3252 "parser.tab.c"
    break;

  case 103: /* type_specifier: INT  */
#line 1123 "src/parser.y"
                                        {(yyval.str)=strdup("int");}
#line 3258 "parser.tab.c"
    break;

  case 104: /* type_specifier: LONG  */
#line 1124 "src/parser.y"
                                        {(yyval.str)=strdup("long");}
#line 3264 "parser.tab.c"
    break;

  case 105: /* type_specifier: FLOAT  */
#line 1125 "src/parser.y"
                                        {(yyval.str)=strdup("float");}
#line 3270 "parser.tab.c"
    break;

  case 106: /* type_specifier: DOUBLE  */
#line 1126 "src/parser.y"
                                        {(yyval.str)=strdup("double");}
#line 3276 "parser.tab.c"
    break;

  case 107: /* type_specifier: SIGNED  */
#line 1127 "src/parser.y"
                                        {(yyval.str)=strdup("signed");}
#line 3282 "parser.tab.c"
    break;

  case 108: /* type_specifier: UNSIGNED  */
#line 1128 "src/parser.y"
                                        {(yyval.str)=strdup("unsigned");}
#line 3288 "parser.tab.c"
    break;

  case 109: /* type_specifier: struct_or_union_specifier  */
#line 1129 "src/parser.y"
                                    {(yyval.str)=(yyvsp[0].str);}
#line 3294 "parser.tab.c"
    break;

  case 111: /* type_specifier: ID  */
#line 1131 "src/parser.y"
             {
		if(type_def_mapping.find((yyvsp[0].str)) != type_def_mapping.end()){
			(yyval.str)=strdup(type_def_mapping[(yyvsp[0].str)].c_str());
		}
		else{
			error_list.push_back("Line "+to_string(yylineno)+" : Typedef error "+(yyvsp[0].str));
		}
	}
#line 3307 "parser.tab.c"
    break;

  case 112: /* $@1: %empty  */
#line 1143 "src/parser.y"
        {
		symbol_info* find_symbol=lookup_symbol_local((yyvsp[0].str),curr_scope);
		if(find_symbol==nullptr){
			symbol_info* new_symbol=new symbol_info();
			curr_scope->symbol_map[(yyvsp[0].str)]=new_symbol;
			curr_scope->symbol_map[(yyvsp[0].str)]->name = (yyvsp[0].str);
			curr_scope->symbol_map[(yyvsp[0].str)]->type = (yyvsp[-1].str);
		}
		else{
			error_list.push_back("Line "+to_string(yylineno)+" : Struct redeclaration error "+(yyvsp[-1].str));
		}
	}
#line 3324 "parser.tab.c"
    break;

  case 113: /* $@2: %empty  */
#line 1156 "src/parser.y"
        {
		curr_scope = new scoped_symtab(curr_scope);
		
	}
#line 3333 "parser.tab.c"
    break;

  case 114: /* struct_or_union_specifier: struct_or_union ID $@1 LBRACE $@2 struct_declaration_list RBRACE  */
#line 1161 "src/parser.y"
        {
		
		
		curr_scope->parent->symbol_map[(yyvsp[-5].str)]->param_list = (yyvsp[-1].symbol_info)->param_list;
		curr_scope->parent->symbol_map[(yyvsp[-5].str)]->param_types = (yyvsp[-1].symbol_info)->param_types;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;
		
	}
#line 3346 "parser.tab.c"
    break;

  case 116: /* struct_or_union_specifier: struct_or_union ID  */
#line 1171 "src/parser.y"
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
#line 3367 "parser.tab.c"
    break;

  case 117: /* struct_or_union: STRUCT  */
#line 1190 "src/parser.y"
                 {(yyval.str)=strdup("struct");}
#line 3373 "parser.tab.c"
    break;

  case 118: /* struct_or_union: UNION  */
#line 1191 "src/parser.y"
                {(yyval.str)=strdup("union");}
#line 3379 "parser.tab.c"
    break;

  case 119: /* struct_declaration_list: struct_declaration  */
#line 1195 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3385 "parser.tab.c"
    break;

  case 120: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1197 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-1].symbol_info);
		for(int i=0;i<(yyvsp[0].symbol_info)->param_list.size();i++){
			(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->param_list[i]);
			(yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->param_types[i]);
		}
		
	}
#line 3398 "parser.tab.c"
    break;

  case 121: /* struct_declaration: specifier_qualifier_list struct_declarator_list SEMICOLON  */
#line 1209 "src/parser.y"
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
#line 3418 "parser.tab.c"
    break;

  case 124: /* struct_declarator_list: struct_declarator  */
#line 1233 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3427 "parser.tab.c"
    break;

  case 125: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 1238 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[-2].symbol_info);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
	}
#line 3436 "parser.tab.c"
    break;

  case 126: /* struct_declarator: declarator  */
#line 1245 "src/parser.y"
                         {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3442 "parser.tab.c"
    break;

  case 138: /* declarator: pointer direct_declarator  */
#line 1272 "src/parser.y"
                                { 
        (yyval.symbol_info)=(yyvsp[0].symbol_info);
        (yyval.symbol_info)->pointer_depth=(yyvsp[-1].symbol_info)->pointer_depth;
    }
#line 3451 "parser.tab.c"
    break;

  case 139: /* declarator: direct_declarator  */
#line 1276 "src/parser.y"
                        { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info); 
    }
#line 3459 "parser.tab.c"
    break;

  case 140: /* direct_declarator: ID  */
#line 1283 "src/parser.y"
        {
		symbol_info* x=new symbol_info();
		x->name = (yyvsp[0].str);
		x->place.first=(yyvsp[0].str);
		(yyval.symbol_info)=x;
		
	}
#line 3471 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator LBRACKET constant_expression RBRACKET  */
#line 1292 "src/parser.y"
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
#line 3486 "parser.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 1303 "src/parser.y"
    {
        (yyval.symbol_info)->is_array = true, (yyval.symbol_info)->array_length = 100;
    }
#line 3494 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator LPARENTHESES parameter_type_list RPARENTHESES  */
#line 1307 "src/parser.y"
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
#line 3511 "parser.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator LPARENTHESES RPARENTHESES  */
#line 1321 "src/parser.y"
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
#line 3527 "parser.tab.c"
    break;

  case 147: /* pointer: STAR  */
#line 1335 "src/parser.y"
               {(yyval.symbol_info)=new symbol_info(); (yyval.symbol_info)->pointer_depth=1;}
#line 3533 "parser.tab.c"
    break;

  case 149: /* pointer: STAR pointer  */
#line 1337 "src/parser.y"
                       {(yyval.symbol_info)=(yyvsp[0].symbol_info); (yyval.symbol_info)->pointer_depth++;}
#line 3539 "parser.tab.c"
    break;

  case 153: /* parameter_type_list: parameter_list  */
#line 1349 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)->parameter_no=(yyvsp[0].symbol_info)->parameter_no;
		(yyval.symbol_info)->is_param_list=(yyvsp[0].symbol_info)->is_param_list;
		(yyval.symbol_info)->param_types=(yyvsp[0].symbol_info)->param_types;
		(yyval.symbol_info)->param_list=(yyvsp[0].symbol_info)->param_list;
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
		
	}
#line 3553 "parser.tab.c"
    break;

  case 155: /* parameter_list: parameter_declaration  */
#line 1363 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=1;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3564 "parser.tab.c"
    break;

  case 156: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1370 "src/parser.y"
    {
        (yyval.symbol_info)->is_param_list=true;
        (yyval.symbol_info)->parameter_no=(yyvsp[-2].symbol_info)->parameter_no+(yyvsp[0].symbol_info)->parameter_no;
        (yyval.symbol_info)->param_types.push_back((yyvsp[0].symbol_info)->type);
		(yyval.symbol_info)->param_list.push_back((yyvsp[0].symbol_info)->name);
    }
#line 3575 "parser.tab.c"
    break;

  case 157: /* parameter_declaration: declaration_specifiers declarator  */
#line 1381 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
		(yyval.symbol_info)->parameter_no=1;
	}
#line 3587 "parser.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1388 "src/parser.y"
                                                    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[-1].str);
		(yyval.symbol_info)->name=(yyvsp[0].symbol_info)->name;
	}
#line 3598 "parser.tab.c"
    break;

  case 159: /* parameter_declaration: declaration_specifiers  */
#line 1394 "src/parser.y"
                                {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->type=(yyvsp[0].str);
		(yyval.symbol_info)->name="";
	}
#line 3609 "parser.tab.c"
    break;

  case 176: /* initializer: assignment_expression  */
#line 1431 "src/parser.y"
                                {
		(yyvsp[0].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
        // cerr<<$1->name<<"  "<<$1->pointer_depth<<endl;
	}
#line 3619 "parser.tab.c"
    break;

  case 177: /* initializer: LBRACE initializer_list RBRACE  */
#line 1436 "src/parser.y"
                                         {(yyval.symbol_info) = (yyvsp[-1].symbol_info);}
#line 3625 "parser.tab.c"
    break;

  case 178: /* initializer: LBRACE initializer_list COMMA RBRACE  */
#line 1437 "src/parser.y"
                                               {(yyval.symbol_info) = (yyvsp[-2].symbol_info);}
#line 3631 "parser.tab.c"
    break;

  case 179: /* initializer_list: initializer  */
#line 1441 "src/parser.y"
                      {(yyval.symbol_info) = (yyvsp[0].symbol_info);}
#line 3637 "parser.tab.c"
    break;

  case 180: /* initializer_list: initializer_list COMMA initializer  */
#line 1442 "src/parser.y"
                                             {
		if((yyvsp[-2].symbol_info)->type != (yyvsp[0].symbol_info)->type){
            error_list.push_back("Line "+to_string(yylineno)+" : Type mismatch in initializer list");
		}
		else{
			(yyvsp[-2].symbol_info)->int_array.push_back((yyvsp[0].symbol_info));
		}
		(yyval.symbol_info) = (yyvsp[-2].symbol_info);
	}
#line 3651 "parser.tab.c"
    break;

  case 181: /* statement: labeled_statement  */
#line 1455 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);

	}
#line 3660 "parser.tab.c"
    break;

  case 182: /* statement: compound_statement  */
#line 1460 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3668 "parser.tab.c"
    break;

  case 183: /* statement: expression_statement  */
#line 1464 "src/parser.y"
    {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3676 "parser.tab.c"
    break;

  case 184: /* statement: selection_statement  */
#line 1467 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3682 "parser.tab.c"
    break;

  case 185: /* statement: iteration_statement  */
#line 1468 "src/parser.y"
                             {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3688 "parser.tab.c"
    break;

  case 186: /* statement: jump_statement  */
#line 1469 "src/parser.y"
                        {(yyval.symbol_info)=(yyvsp[0].symbol_info);}
#line 3694 "parser.tab.c"
    break;

  case 187: /* labeled_statement: ID COLON statement  */
#line 1475 "src/parser.y"
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
#line 3725 "parser.tab.c"
    break;

  case 188: /* labeled_statement: ID COLON declaration  */
#line 1502 "src/parser.y"
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
#line 3757 "parser.tab.c"
    break;

  case 190: /* labeled_statement: CASE constant_expression COLON statement  */
#line 1531 "src/parser.y"
        {
		string label=newlabel();
		(yyval.symbol_info)->code = label +":\n"+ (yyvsp[0].symbol_info)->code;
		case_list.top().push({(yyvsp[-2].symbol_info)->code,label});
		
	}
#line 3768 "parser.tab.c"
    break;

  case 191: /* labeled_statement: DEFAULT COLON statement  */
#line 1538 "src/parser.y"
        {
		string label=newlabel();
		case_list.top().push({"default",label});
		(yyval.symbol_info)->code = label+":\n"+ (yyvsp[0].symbol_info)->code;

	}
#line 3779 "parser.tab.c"
    break;

  case 193: /* $@3: %empty  */
#line 1549 "src/parser.y"
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
#line 3794 "parser.tab.c"
    break;

  case 194: /* compound_statement: LBRACE $@3 statement_declaration_list RBRACE  */
#line 1561 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[-1].symbol_info)->is_return;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->return_type;
		all_scopes.push_back(curr_scope);curr_scope = curr_scope->parent;
	}
#line 3807 "parser.tab.c"
    break;

  case 195: /* $@4: %empty  */
#line 1569 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3813 "parser.tab.c"
    break;

  case 196: /* compound_statement: LBRACE $@4 statement_list RBRACE  */
#line 1569 "src/parser.y"
                                                                                     {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3822 "parser.tab.c"
    break;

  case 197: /* $@5: %empty  */
#line 1573 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3828 "parser.tab.c"
    break;

  case 198: /* compound_statement: LBRACE $@5 declaration_list RBRACE  */
#line 1573 "src/parser.y"
                                                                                       {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code;
		all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3837 "parser.tab.c"
    break;

  case 199: /* $@6: %empty  */
#line 1577 "src/parser.y"
                 {curr_scope = new scoped_symtab(curr_scope);}
#line 3843 "parser.tab.c"
    break;

  case 200: /* compound_statement: LBRACE $@6 declaration_list statement_list RBRACE  */
#line 1577 "src/parser.y"
                                                                                                      {symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+(yyvsp[-1].symbol_info)->code;all_scopes.push_back(curr_scope); curr_scope = curr_scope->parent;}
#line 3851 "parser.tab.c"
    break;

  case 201: /* statement_declaration_list: statement_list statement_declaration_list  */
#line 1584 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		
        

	}
#line 3867 "parser.tab.c"
    break;

  case 202: /* statement_declaration_list: declaration_list statement_declaration_list  */
#line 1596 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		// $$->return_type=$2->return_type;
		
        
		
	}
#line 3882 "parser.tab.c"
    break;

  case 203: /* statement_declaration_list: statement_list  */
#line 1607 "src/parser.y"
    {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		(yyval.symbol_info)->is_return=(yyvsp[0].symbol_info)->is_return;
		//dikkat badi hai
		// $$->return_type=$1->return_type;
	}
#line 3895 "parser.tab.c"
    break;

  case 204: /* statement_declaration_list: declaration_list  */
#line 1616 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3903 "parser.tab.c"
    break;

  case 205: /* declaration_list: declaration  */
#line 1623 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
		//debug("declaration_list", $$->code);
	}
#line 3914 "parser.tab.c"
    break;

  case 206: /* declaration_list: declaration_list declaration  */
#line 1630 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
	}
#line 3922 "parser.tab.c"
    break;

  case 207: /* declaration_list: error SEMICOLON  */
#line 1633 "src/parser.y"
                          {yyerrok;}
#line 3928 "parser.tab.c"
    break;

  case 208: /* statement_list: statement  */
#line 1637 "src/parser.y"
                    { 
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 3936 "parser.tab.c"
    break;

  case 209: /* statement_list: statement_list statement  */
#line 1641 "src/parser.y"
        {
		(yyval.symbol_info)->is_return=((yyvsp[-1].symbol_info)->is_return)|((yyvsp[0].symbol_info)->is_return);
		// if($1->return_type!="") $$->return_type=$1->return_type;
		// else $$->return_type=$2->return_type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\n" + (yyvsp[0].symbol_info)->code;
		
	}
#line 3948 "parser.tab.c"
    break;

  case 210: /* statement_list: error SEMICOLON  */
#line 1648 "src/parser.y"
                          {yyerrok;}
#line 3954 "parser.tab.c"
    break;

  case 212: /* expression_statement: expression SEMICOLON  */
#line 1653 "src/parser.y"
                                 {(yyval.symbol_info)=(yyvsp[-1].symbol_info);}
#line 3960 "parser.tab.c"
    break;

  case 213: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement  */
#line 1658 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-2].symbol_info)->code+"\n"+"if("+ (yyvsp[-2].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+falselabel+":\n";
	}
#line 3970 "parser.tab.c"
    break;

  case 214: /* selection_statement: IF LPARENTHESES expression RPARENTHESES statement ELSE statement  */
#line 1664 "src/parser.y"
        {
		string truelabel=newlabel();	
		string falselabel=newlabel();
		string endlabel=newlabel();
		(yyval.symbol_info)->code=(yyvsp[-4].symbol_info)->code+"\n"+"if("+ (yyvsp[-4].symbol_info)->place.first +") goto "+truelabel+"\n"+"goto "+falselabel+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"goto "+endlabel+"\n"+falselabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+endlabel+":\n";
	}
#line 3981 "parser.tab.c"
    break;

  case 215: /* $@7: %empty  */
#line 1670 "src/parser.y"
                {queue<std::pair<std::string, std::string>> q;
		case_list.push(q);
		}
#line 3989 "parser.tab.c"
    break;

  case 216: /* selection_statement: SWITCH $@7 LPARENTHESES expression RPARENTHESES statement  */
#line 1673 "src/parser.y"
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
#line 4011 "parser.tab.c"
    break;

  case 217: /* iteration_statement: WHILE LPARENTHESES expression RPARENTHESES statement  */
#line 1694 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 4025 "parser.tab.c"
    break;

  case 218: /* iteration_statement: DO statement WHILE LPARENTHESES expression RPARENTHESES SEMICOLON  */
#line 1704 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=startlabel+":\n"+(yyvsp[-5].symbol_info)->code+"\n"+truelabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+startlabel+"\n"+"goto "+endlabel+"\n"+endlabel+":\n";
		(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 4039 "parser.tab.c"
    break;

  case 219: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement RPARENTHESES statement  */
#line 1714 "src/parser.y"
        {
		string startlabel=newlabel();
		string endlabel=newlabel();
		string truelabel=newlabel();
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->code=(yyvsp[-3].symbol_info)->code+"\n"+startlabel+":\n"+(yyvsp[-2].symbol_info)->code+"\n"+"if("+(yyvsp[-2].symbol_info)->place.first+") goto "+truelabel+"\n"+"goto "+endlabel+"\n"+truelabel+":\n"+(yyvsp[0].symbol_info)->code+"\n"+"\n"+"goto "+startlabel+"\n"+endlabel+":\n";
			(yyval.symbol_info)->code=replace_break_continue((yyval.symbol_info)->code,endlabel,startlabel,1);
	}
#line 4053 "parser.tab.c"
    break;

  case 220: /* iteration_statement: FOR LPARENTHESES expression_statement expression_statement expression RPARENTHESES statement  */
#line 1724 "src/parser.y"
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
#line 4070 "parser.tab.c"
    break;

  case 221: /* jump_statement: GOTO ID SEMICOLON  */
#line 1740 "src/parser.y"
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
#line 4097 "parser.tab.c"
    break;

  case 222: /* jump_statement: CONTINUE SEMICOLON  */
#line 1763 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_continue=true;
		(yyval.symbol_info)->code="\n continue \n";
	}
#line 4108 "parser.tab.c"
    break;

  case 223: /* jump_statement: BREAK SEMICOLON  */
#line 1770 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_break=true;
		(yyval.symbol_info)->code="\n break \n";
	}
#line 4119 "parser.tab.c"
    break;

  case 224: /* jump_statement: RETURN SEMICOLON  */
#line 1777 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type="void";
		(yyval.symbol_info)->code="\nRETURN\n";
	}
#line 4131 "parser.tab.c"
    break;

  case 225: /* jump_statement: RETURN expression SEMICOLON  */
#line 1785 "src/parser.y"
        {
		symbol_info* new_symbol=new symbol_info();
		(yyval.symbol_info)=new_symbol;
		(yyval.symbol_info)->is_return=true;
		(yyval.symbol_info)->return_type=(yyvsp[-1].symbol_info)->type;
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code + "\nRETURN "+(yyvsp[-1].symbol_info)->place.first+"\n";
		//debug("return ",$$->code);
	}
#line 4144 "parser.tab.c"
    break;

  case 226: /* start_symbol: translation_unit  */
#line 1796 "src/parser.y"
{
	//cerr<<"-----------------"<<endl<<$1->code<<"----------------"<<endl;
    // print_scope_table();
	print_errors();
	cleanTAC((yyvsp[0].symbol_info)->code);
}
#line 4155 "parser.tab.c"
    break;

  case 227: /* translation_unit: external_declaration  */
#line 1805 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[0].symbol_info)->code;
	}
#line 4163 "parser.tab.c"
    break;

  case 228: /* translation_unit: translation_unit external_declaration  */
#line 1809 "src/parser.y"
        {
		(yyval.symbol_info)->code=(yyvsp[-1].symbol_info)->code+(yyvsp[0].symbol_info)->code;
	}
#line 4171 "parser.tab.c"
    break;

  case 230: /* external_declaration: function_definition  */
#line 1817 "src/parser.y"
        {
		(yyval.symbol_info)=(yyvsp[0].symbol_info);
	}
#line 4179 "parser.tab.c"
    break;

  case 233: /* $@8: %empty  */
#line 1826 "src/parser.y"
        {
		var_name=(yyvsp[0].symbol_info)->param_list;
		type_list=(yyvsp[0].symbol_info)->param_types;
        curr_scope->symbol_map[(yyvsp[0].symbol_info)->name]->type=(yyvsp[-1].str);
	}
#line 4189 "parser.tab.c"
    break;

  case 234: /* function_definition: declaration_specifiers declarator $@8 compound_statement  */
#line 1832 "src/parser.y"
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
#line 4223 "parser.tab.c"
    break;


#line 4227 "parser.tab.c"

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

#line 1864 "src/parser.y"


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
        if(it.second->is_static){
            it.second->type = "static "+it.second->type;
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
}
