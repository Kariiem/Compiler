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

#ifndef YY_YY_COMP_TAB_H_INCLUDED
# define YY_YY_COMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "comp.y"

  typedef void* yyscan_t;
  #include "src/ast/ast.h"

#line 54 "comp.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_MODULE = 258,            /* TOKEN_MODULE  */
    TOKEN_IMPORT = 259,            /* TOKEN_IMPORT  */
    TOKEN_FUN = 260,               /* TOKEN_FUN  */
    TOKEN_VAL = 261,               /* TOKEN_VAL  */
    TOKEN_VAR = 262,               /* TOKEN_VAR  */
    TOKEN_TYPE = 263,              /* TOKEN_TYPE  */
    TOKEN_DO = 264,                /* TOKEN_DO  */
    TOKEN_IF = 265,                /* TOKEN_IF  */
    TOKEN_ELSE = 266,              /* TOKEN_ELSE  */
    TOKEN_FOR = 267,               /* TOKEN_FOR  */
    TOKEN_WHILE = 268,             /* TOKEN_WHILE  */
    TOKEN_UNTIL = 269,             /* TOKEN_UNTIL  */
    TOKEN_SWITCH = 270,            /* TOKEN_SWITCH  */
    TOKEN_NOT = 271,               /* TOKEN_NOT  */
    TOKEN_AND = 272,               /* TOKEN_AND  */
    TOKEN_OR = 273,                /* TOKEN_OR  */
    TOKEN_PLUS = 274,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 275,             /* TOKEN_MINUS  */
    TOKEN_MULT = 276,              /* TOKEN_MULT  */
    TOKEN_DIV = 277,               /* TOKEN_DIV  */
    TOKEN_EXP = 278,               /* TOKEN_EXP  */
    TOKEN_MOD = 279,               /* TOKEN_MOD  */
    TOKEN_LT = 280,                /* TOKEN_LT  */
    TOKEN_GT = 281,                /* TOKEN_GT  */
    TOKEN_LEQ = 282,               /* TOKEN_LEQ  */
    TOKEN_GEQ = 283,               /* TOKEN_GEQ  */
    TOKEN_EQ = 284,                /* TOKEN_EQ  */
    TOKEN_NEQ = 285,               /* TOKEN_NEQ  */
    TOKEN_EQUAL = 286,             /* TOKEN_EQUAL  */
    TOKEN_COLON = 287,             /* TOKEN_COLON  */
    TOKEN_QUALIFY = 288,           /* TOKEN_QUALIFY  */
    TOKEN_COMMA = 289,             /* TOKEN_COMMA  */
    TOKEN_SEMICOLON = 290,         /* TOKEN_SEMICOLON  */
    TOKEN_PIPE = 291,              /* TOKEN_PIPE  */
    TOKEN_AMP = 292,               /* TOKEN_AMP  */
    TOKEN_LPAREN = 293,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 294,            /* TOKEN_RPAREN  */
    TOKEN_LBRACE = 295,            /* TOKEN_LBRACE  */
    TOKEN_RBRACE = 296,            /* TOKEN_RBRACE  */
    TOKEN_NEWLINE = 297,           /* TOKEN_NEWLINE  */
    TOKEN_WS = 298,                /* TOKEN_WS  */
    TOKEN_EOF = 299,               /* TOKEN_EOF  */
    TOKEN_UNKNOWN = 300,           /* TOKEN_UNKNOWN  */
    IDENTIFIER = 301,              /* IDENTIFIER  */
    INTEGER = 302,                 /* INTEGER  */
    REAL = 303,                    /* REAL  */
    STRING = 304,                  /* STRING  */
    BOOL = 305                     /* BOOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
  ast_module_decl_t* module_decl;          /* module_decl  */
  ast_top_level_decl_t* top_level_decl_list; /* top_level_decl_list  */
  vtype(ast_expr_t*) arg_list;
  char const* IDENTIFIER;                  /* IDENTIFIER  */
  char const* INTEGER;                     /* INTEGER  */
  char const* REAL;                        /* REAL  */
  char const* STRING;                      /* STRING  */
  int64_t BOOL;                            /* BOOL  */

#line 129 "comp.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (yyscan_t scanner, ast_source_t** source_module);


#endif /* !YY_YY_COMP_TAB_H_INCLUDED  */
