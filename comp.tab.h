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
/* "%code requires" blocks.  */
#line 9 "comp.y"

  typedef void* yyscan_t;
  #include "src/ast/ast.h"

#line 53 "comp.tab.h"

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

  /* block_expression  */
  ast_block_expr_t* block_expression;
  /* block  */
  ast_block_t* block;
  /* case_expr  */
  ast_case_t* case_expr;
  /* constructor_field  */
  ast_constructors_t* constructor_field;
  /* do_block_expr  */
  ast_do_t* do_block_expr;
  /* optional_step  */
  ast_expr_t optional_step;
  /* optional_assignment  */
  ast_expr_t* optional_assignment;
  /* expr  */
  ast_expr_t* expr;
  /* atomic_value  */
  ast_expr_t* atomic_value;
  /* arithmetic_expr  */
  ast_expr_t* arithmetic_expr;
  /* logical_expr  */
  ast_expr_t* logical_expr;
  /* compound_expr  */
  ast_expr_t* compound_expr;
  /* for_loop_expr  */
  ast_for_t* for_loop_expr;
  /* param  */
  ast_fun_param_t* param;
  /* funcall  */
  ast_funcall_t* funcall;
  /* fun_decl  */
  ast_fundecl_t* fun_decl;
  /* if_then_else_expr  */
  ast_if_t* if_then_else_expr;
  /* import_decl  */
  ast_import_decl_t* import_decl;
  /* module_decl  */
  ast_module_decl_t* module_decl;
  /* range  */
  ast_range_t* range;
  /* record_field  */
  ast_record_field_t* record_field;
  /* switch_expr  */
  ast_switch_t* switch_expr;
  /* term_decl  */
  ast_term_decl_t* term_decl;
  /* top_level_decl  */
  ast_top_level_decl_t* top_level_decl;
  /* type_decl  */
  ast_type_decl_t* type_decl;
  /* while_loop_expr  */
  ast_while_t* while_loop_expr;
  /* until_loop_expr  */
  ast_while_t* until_loop_expr;
  /* IDENTIFIER  */
  char const* IDENTIFIER;
  /* INTEGER  */
  char const* INTEGER;
  /* REAL  */
  char const* REAL;
  /* STRING  */
  char const* STRING;
  /* BOOL  */
  int64_t BOOL;
  /* val_or_var  */
  int64_t* val_or_var;
  /* block_expression_list  */
  vtype(ast_block_expr_t*) block_expression_list;
  /* case_expr_list  */
  vtype(ast_case_t*) case_expr_list;
  /* constructor_list  */
  vtype(ast_constructors_t*) constructor_list;
  /* arg_list  */
  vtype(ast_expr_t*) arg_list;
  /* param_list  */
  vtype(ast_fun_param_t*) param_list;
  /* record  */
  vtype(ast_record_field_t*) record;
  /* record_field_list  */
  vtype(ast_record_field_t*) record_field_list;
  /* top_level_decl_list  */
  vtype(ast_top_level_decl_t*) top_level_decl_list;
#line 198 "comp.tab.h"

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
