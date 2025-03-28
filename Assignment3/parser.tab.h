/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DECIMAL_LITERAL = 258,         /* DECIMAL_LITERAL  */
    HEXA_LITERAL = 259,            /* HEXA_LITERAL  */
    OCTAL_LITERAL = 260,           /* OCTAL_LITERAL  */
    EXP_LITERAL = 261,             /* EXP_LITERAL  */
    REAL_LITERAL = 262,            /* REAL_LITERAL  */
    FLOAT_LITERAL = 263,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 265,       /* CHARACTER_LITERAL  */
    ID = 266,                      /* ID  */
    INVALID_ID = 267,              /* INVALID_ID  */
    INCLUDE = 268,                 /* INCLUDE  */
    AUTO = 269,                    /* AUTO  */
    STRUCT = 270,                  /* STRUCT  */
    BOOL = 271,                    /* BOOL  */
    BREAK = 272,                   /* BREAK  */
    CASE = 273,                    /* CASE  */
    CONTINUE = 274,                /* CONTINUE  */
    GOTO = 275,                    /* GOTO  */
    DO = 276,                      /* DO  */
    DEFAULT = 277,                 /* DEFAULT  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    CONST = 281,                   /* CONST  */
    TRUE = 282,                    /* TRUE  */
    FALSE = 283,                   /* FALSE  */
    STATIC = 284,                  /* STATIC  */
    SWITCH = 285,                  /* SWITCH  */
    WHILE = 286,                   /* WHILE  */
    VOID = 287,                    /* VOID  */
    RETURN = 288,                  /* RETURN  */
    SIZEOF = 289,                  /* SIZEOF  */
    FLOAT = 290,                   /* FLOAT  */
    INT = 291,                     /* INT  */
    DOUBLE = 292,                  /* DOUBLE  */
    EXTERN = 293,                  /* EXTERN  */
    SHORT = 294,                   /* SHORT  */
    LONG = 295,                    /* LONG  */
    CHAR = 296,                    /* CHAR  */
    ENUM = 297,                    /* ENUM  */
    REGISTER = 298,                /* REGISTER  */
    SIGNED = 299,                  /* SIGNED  */
    TYPEDEF = 300,                 /* TYPEDEF  */
    UNION = 301,                   /* UNION  */
    UNSIGNED = 302,                /* UNSIGNED  */
    VOLATILE = 303,                /* VOLATILE  */
    CLASS = 304,                   /* CLASS  */
    PUBLIC = 305,                  /* PUBLIC  */
    PRIVATE = 306,                 /* PRIVATE  */
    PROTECTED = 307,               /* PROTECTED  */
    NULLPTR = 308,                 /* NULLPTR  */
    NAMESPACE = 309,               /* NAMESPACE  */
    VIRTUAL = 310,                 /* VIRTUAL  */
    CATCH = 311,                   /* CATCH  */
    RBRACE = 312,                  /* RBRACE  */
    LBRACE = 313,                  /* LBRACE  */
    LBRACKET = 314,                /* LBRACKET  */
    RBRACKET = 315,                /* RBRACKET  */
    LPARENTHESES = 316,            /* LPARENTHESES  */
    RPARENTHESES = 317,            /* RPARENTHESES  */
    DOT = 318,                     /* DOT  */
    COMMA = 319,                   /* COMMA  */
    COLON = 320,                   /* COLON  */
    SEMICOLON = 321,               /* SEMICOLON  */
    PLUS = 322,                    /* PLUS  */
    MINUS = 323,                   /* MINUS  */
    STAR = 324,                    /* STAR  */
    DIVIDE = 325,                  /* DIVIDE  */
    MODULO = 326,                  /* MODULO  */
    AMPERSAND = 327,               /* AMPERSAND  */
    OR = 328,                      /* OR  */
    XOR = 329,                     /* XOR  */
    EXCLAMATION = 330,             /* EXCLAMATION  */
    TILDE = 331,                   /* TILDE  */
    EQUALS = 332,                  /* EQUALS  */
    LESS_THAN = 333,               /* LESS_THAN  */
    GREATER_THAN = 334,            /* GREATER_THAN  */
    QUESTION_MARK = 335,           /* QUESTION_MARK  */
    INCREMENT = 336,               /* INCREMENT  */
    DECREMENT = 337,               /* DECREMENT  */
    REL_AND = 338,                 /* REL_AND  */
    REL_OR = 339,                  /* REL_OR  */
    REL_EQUALS = 340,              /* REL_EQUALS  */
    REL_NOT_EQ = 341,              /* REL_NOT_EQ  */
    LESS_EQUALS = 342,             /* LESS_EQUALS  */
    GREATER_EQUALS = 343,          /* GREATER_EQUALS  */
    ASSIGN_PLUS = 344,             /* ASSIGN_PLUS  */
    ASSIGN_MINUS = 345,            /* ASSIGN_MINUS  */
    ASSIGN_STAR = 346,             /* ASSIGN_STAR  */
    ASSIGN_DIV = 347,              /* ASSIGN_DIV  */
    ASSIGN_MOD = 348,              /* ASSIGN_MOD  */
    ASSIGN_AND = 349,              /* ASSIGN_AND  */
    ASSIGN_OR = 350,               /* ASSIGN_OR  */
    ASSIGN_XOR = 351,              /* ASSIGN_XOR  */
    LEFT_SHIFT = 352,              /* LEFT_SHIFT  */
    LEFT_SHIFT_EQ = 353,           /* LEFT_SHIFT_EQ  */
    RIGHT_SHIFT = 354,             /* RIGHT_SHIFT  */
    RIGHT_SHIFT_EQ = 355,          /* RIGHT_SHIFT_EQ  */
    LAMBDA_ARROW = 356,            /* LAMBDA_ARROW  */
    VARIABLE_ARGS = 357            /* VARIABLE_ARGS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "src/parser.y"

    char* str;  // For type_specifier, declarator
    struct symbol_info* symbol_info; // For expressions and constants

#line 171 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
