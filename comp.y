%define api.pure full
%locations
%param {yyscan_t scanner}
%param {ast_source_t** source_module}

%code top {
  #include <stdio.h>
} 
%code requires {
  typedef void* yyscan_t;
  #include "src/ast/ast.h"
}
%code {
  int yylex(YYSTYPE* yylvalp, YYLTYPE* yyllocp, yyscan_t scanner,ast_source_t** source_module);
  void yyerror(YYLTYPE* yyllocp, yyscan_t unused, ast_source_t **source_module, const char* msg);
}

/* Generate YYSTYPE from these types: */
%define api.value.type union

/*-----------------------------------*/
/* -:- keywords -:- */
/*-----------------------------------*/
%token TOKEN_MODULE
%token TOKEN_IMPORT
%token TOKEN_FUN
%token TOKEN_VAL
%token TOKEN_VAR 
%token TOKEN_TYPE
%token TOKEN_DO 
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_FOR  
%token TOKEN_WHILE
%token TOKEN_UNTIL
%token TOKEN_SWITCH
%token TOKEN_NOT
%token TOKEN_AND
%token TOKEN_OR

/*-----------------------------------*/
/* -:- arithmetic operators -:- */
/*-----------------------------------*/
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_EXP
%token TOKEN_MOD

/*-----------------------------------*/
/* -:- comparison operators -:- */
/*-----------------------------------*/
%token TOKEN_LT 
%token TOKEN_GT 
%token TOKEN_LEQ
%token TOKEN_GEQ
%token TOKEN_EQ 
%token TOKEN_NEQ

/*-----------------------------------*/
/* -:- other tokens -:- */
/*-----------------------------------*/
%token TOKEN_EQUAL
%token TOKEN_COLON
%token TOKEN_QUALIFY
%token TOKEN_COMMA 
%token TOKEN_SEMICOLON
%token TOKEN_PIPE
%token TOKEN_AMP
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACE
%token TOKEN_RBRACE

/*-----------------------------------*/
/* -:- non-char/whitespace -:- */
/*-----------------------------------*/
%token TOKEN_NEWLINE
%token TOKEN_WS
%token TOKEN_EOF 
%token TOKEN_UNKNOWN

/*-----------------------------------*/
/* -:- atoms -:- */
/*-----------------------------------*/
%token <char const*> IDENTIFIER
%token <char const*> INTEGER
%token <char const*> REAL
%token <char const*> STRING
%token <int64_t>     BOOL
/*-----------------------------------*/

/* module Main */
%nterm <ast_module_decl_t*>    module_decl
%nterm <ast_top_level_decl_t*> top_level_decl_list

%left TOKEN_PLUS TOKEN_MINUS TOKEN_MULT TOKEN_DIV TOKEN_MOD
%left TOKEN_AND TOKEN_OR
%left TOKEN_EQ TOKEN_NEQ TOKEN_GT TOKEN_GEQ TOKEN_LT TOKEN_LEQ
%left TOKEN_COMMA
%right TOKEN_NOT TOKEN_EXP TOKEN_EQUAL
%%
source: 
    module_decl top_level_decl_list
    ;

module_decl: 
    TOKEN_MODULE IDENTIFIER TOKEN_NEWLINE   {$$=create_ast_module_decl_t($2);}
    ;

top_level_decl_list: 
    %empty
|   top_level_decl_list top_level_decl
    ;

top_level_decl:
    import_decl
|   type_decl
|   term_decl  
|   fun_decl
    ;

import_decl:
    TOKEN_IMPORT IDENTIFIER TOKEN_NEWLINE
    ;

term_decl: 
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER optional_assignment
|   IDENTIFIER TOKEN_EQUAL expr TOKEN_SEMICOLON
    ;

val_or_var: 
    TOKEN_VAL
|   TOKEN_VAR
    ;

optional_assignment:
    TOKEN_EQUAL expr TOKEN_SEMICOLON
|   TOKEN_SEMICOLON
    ;

expr:
    atomic_value
|   arithmetic_expr
|   logical_expr
|   funcall
|   compound_expr
|   TOKEN_LPAREN expr TOKEN_RPAREN
    ;

atomic_value:
    IDENTIFIER
|   INTEGER
|   REAL
|   BOOL
|   STRING
    ;

arithmetic_expr:
    expr TOKEN_PLUS expr
|   expr TOKEN_MINUS expr
|   expr TOKEN_MULT expr
|   expr TOKEN_DIV expr
|   expr TOKEN_MOD expr
|   expr TOKEN_EXP expr
    ;

logical_expr:
    TOKEN_NOT expr
|   expr TOKEN_AND expr
|   expr TOKEN_OR expr
|   expr TOKEN_LT expr 
|   expr TOKEN_GT expr 
|   expr TOKEN_LEQ expr 
|   expr TOKEN_GEQ expr 
|   expr TOKEN_EQ expr 
|   expr TOKEN_NEQ expr 
    ;

compound_expr:
    if_then_else_expr
|   for_loop_expr
|   while_loop_expr
|   until_loop_expr
|   do_block_expr
|   switch_expr
    ;

if_then_else_expr:
    TOKEN_IF expr block TOKEN_ELSE block
    ;

for_loop_expr:
    TOKEN_FOR IDENTIFIER TOKEN_COLON range block
    ;

range:
    TOKEN_LPAREN expr TOKEN_COMMA expr optional_step TOKEN_RPAREN
    ;

optional_step:
    %empty
|   TOKEN_COMMA expr
    ;

while_loop_expr:
    TOKEN_WHILE expr block
    ;

until_loop_expr:
    TOKEN_UNTIL expr block
    ;

do_block_expr:
    TOKEN_DO block 
    ;

switch_expr:
    TOKEN_SWITCH expr TOKEN_LBRACE case_expr_list TOKEN_RBRACE
    ;

case_expr_list:
    %empty
|   case_expr_list case_expr
    ;

case_expr:
    TOKEN_ELSE TOKEN_COLON block
|   expr TOKEN_COLON block
    ;

block:  
    TOKEN_LBRACE block_expression_list TOKEN_RBRACE
    ;

block_expression_list:
    %empty
|   block_expression_list block_expression
    ;

block_expression:
    expr TOKEN_SEMICOLON
|   term_decl
    ;

fun_decl:
    TOKEN_FUN IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN IDENTIFIER block
    ;

param_list:
    %empty
|   param
|   param_list TOKEN_COMMA param
    ;

param:
    val_or_var IDENTIFIER TOKEN_COLON IDENTIFIER
    ;

funcall:
    IDENTIFIER TOKEN_LPAREN arg_list TOKEN_RPAREN
    ;

arg_list:
    %empty
|   expr
|   arg_list TOKEN_COMMA expr
    ;
    
type_decl:
    TOKEN_TYPE IDENTIFIER TOKEN_EQUAL constructor_list TOKEN_SEMICOLON
    ;

constructor_list:
    constructor_field
|   constructor_list TOKEN_PIPE constructor_field
    ;

constructor_field: 
    IDENTIFIER record
    ;

record:
    %empty
|   TOKEN_LBRACE record_field_list TOKEN_RBRACE
    ;

record_field_list:
    record_field
|   record_field_list TOKEN_COMMA record_field 
    ;
    
record_field:
    IDENTIFIER TOKEN_COLON IDENTIFIER
    
%%

void yyerror(YYLTYPE* yyllocp, yyscan_t unused,ast_source_t **source_module, const char* msg) {
  
  char token_name[255];
  
  fprintf(stderr, "[%d:%d]: %s\n",
                  yyllocp->first_line, yyllocp->first_column, msg);
}
