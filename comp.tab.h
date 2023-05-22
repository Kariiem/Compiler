/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_COMP_TAB_H_INCLUDED
# define YY_YY_COMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_MODULE = 258,
    TOKEN_IMPORT = 259,
    TOKEN_FUN = 260,
    TOKEN_VAL = 261,
    TOKEN_VAR = 262,
    TOKEN_TYPE = 263,
    TOKEN_DO = 264,
    TOKEN_IF = 265,
    TOKEN_ELSE = 266,
    TOKEN_FOR = 267,
    TOKEN_WHILE = 268,
    TOKEN_UNTIL = 269,
    TOKEN_SWITCH = 270,
    TOKEN_NOT = 271,
    TOKEN_AND = 272,
    TOKEN_OR = 273,
    TOKEN_PLUS = 274,
    TOKEN_MINUS = 275,
    TOKEN_MULT = 276,
    TOKEN_DIV = 277,
    TOKEN_EXP = 278,
    TOKEN_MOD = 279,
    TOKEN_LT = 280,
    TOKEN_GT = 281,
    TOKEN_LEQ = 282,
    TOKEN_GEQ = 283,
    TOKEN_EQ = 284,
    TOKEN_NEQ = 285,
    TOKEN_EQUAL = 286,
    TOKEN_COLON = 287,
    TOKEN_QUALIFY = 288,
    TOKEN_COMMA = 289,
    TOKEN_SEMICOLON = 290,
    TOKEN_PIPE = 291,
    TOKEN_AMP = 292,
    TOKEN_LPAREN = 293,
    TOKEN_RPAREN = 294,
    TOKEN_LBRACE = 295,
    TOKEN_RBRACE = 296,
    TOKEN_NEWLINE = 297,
    TOKEN_WS = 298,
    TOKEN_EOF = 299,
    TOKEN_UNKNOWN = 300,
    IDENTIFIER = 301,
    INTEGER = 302,
    REAL = 303,
    STRING = 304,
    BOOL = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "comp.y"

    char* id;
    int integer;
    double real;
    char* string;
    int boolean;
    void* voidVal;
    void* symbolval;

#line 118 "comp.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMP_TAB_H_INCLUDED  */
