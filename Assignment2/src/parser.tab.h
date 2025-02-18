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
    ID = 258,                      /* ID  */
    DECIMAL_LITERAL = 259,         /* DECIMAL_LITERAL  */
    HEXA_LITERAL = 260,            /* HEXA_LITERAL  */
    OCTAL_LITERAL = 261,           /* OCTAL_LITERAL  */
    EXP_LITERAL = 262,             /* EXP_LITERAL  */
    REAL_LITERAL = 263,            /* REAL_LITERAL  */
    FLOAT_LITERAL = 264,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 265,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 266,       /* CHARACTER_LITERAL  */
    INCLUDE = 267,                 /* INCLUDE  */
    INVALID_ID = 268,              /* INVALID_ID  */
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
    RBRACE = 304,                  /* RBRACE  */
    LBRACE = 305,                  /* LBRACE  */
    LBRACKET = 306,                /* LBRACKET  */
    RBRACKET = 307,                /* RBRACKET  */
    LPARENTHESES = 308,            /* LPARENTHESES  */
    RPARENTHESES = 309,            /* RPARENTHESES  */
    DOT = 310,                     /* DOT  */
    COMMA = 311,                   /* COMMA  */
    COLON = 312,                   /* COLON  */
    SEMICOLON = 313,               /* SEMICOLON  */
    PLUS = 314,                    /* PLUS  */
    MINUS = 315,                   /* MINUS  */
    STAR = 316,                    /* STAR  */
    DIVIDE = 317,                  /* DIVIDE  */
    MODULO = 318,                  /* MODULO  */
    AMPERSAND = 319,               /* AMPERSAND  */
    OR = 320,                      /* OR  */
    XOR = 321,                     /* XOR  */
    EXCLAMATION = 322,             /* EXCLAMATION  */
    TILDE = 323,                   /* TILDE  */
    EQUALS = 324,                  /* EQUALS  */
    LESS_THAN = 325,               /* LESS_THAN  */
    GREATER_THAN = 326,            /* GREATER_THAN  */
    QUESTION_MARK = 327,           /* QUESTION_MARK  */
    INCREMENT = 328,               /* INCREMENT  */
    DECREMENT = 329,               /* DECREMENT  */
    REL_AND = 330,                 /* REL_AND  */
    REL_OR = 331,                  /* REL_OR  */
    REL_EQUALS = 332,              /* REL_EQUALS  */
    REL_NOT_EQ = 333,              /* REL_NOT_EQ  */
    LESS_EQUALS = 334,             /* LESS_EQUALS  */
    GREATER_EQUALS = 335,          /* GREATER_EQUALS  */
    ASSIGN_PLUS = 336,             /* ASSIGN_PLUS  */
    ASSIGN_MINUS = 337,            /* ASSIGN_MINUS  */
    ASSIGN_STAR = 338,             /* ASSIGN_STAR  */
    ASSIGN_DIV = 339,              /* ASSIGN_DIV  */
    ASSIGN_MOD = 340,              /* ASSIGN_MOD  */
    ASSIGN_AND = 341,              /* ASSIGN_AND  */
    ASSIGN_OR = 342,               /* ASSIGN_OR  */
    ASSIGN_XOR = 343,              /* ASSIGN_XOR  */
    LEFT_SHIFT = 344,              /* LEFT_SHIFT  */
    LEFT_SHIFT_EQ = 345,           /* LEFT_SHIFT_EQ  */
    RIGHT_SHIFT = 346,             /* RIGHT_SHIFT  */
    RIGHT_SHIFT_EQ = 347,          /* RIGHT_SHIFT_EQ  */
    LAMBDA_ARROW = 348,            /* LAMBDA_ARROW  */
    VARIABLE_ARGS = 349            /* VARIABLE_ARGS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

    char *str;

#line 162 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
