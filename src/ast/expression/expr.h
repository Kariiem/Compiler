#ifndef __AST_NODE_EXPR__
#define __AST_NODE_EXPR__

#include "../datastructures/cvector.h"
#include "bin_expr.h"
#include "block.h"
#include "do.h"
#include "for.h"
#include "funcall.h"
#include "if.h"
#include "switch.h"
#include "while.h"
#include <gmp.h>
#include <mpfr.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct symbol_table_t symbol_table_t; // forward declaration

struct ast_expr_t {
  enum {
    // atomic expressions
    EXPR_IDENTIFIER,
    EXPR_INTEGER,
    EXPR_DOUBLE,
    EXPR_REAL,
    EXPR_INT,
    EXPR_BOOL,
    EXPR_STRING,
    // binary expressions
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_MOD,
    EXPR_EXP,
    EXPR_AND,
    EXPR_OR,
    EXPR_LT,
    EXPR_GT,
    EXPR_LEQ,
    EXPR_GEQ,
    EXPR_EQ,
    EXPR_NEQ,
    EXPR_NOT,
    // function call
    EXPR_FUNCALL,
    // compound expressions
    EXPR_IF,
    EXPR_FOR,
    EXPR_WHILE,
    EXPR_UNTIL,
    EXPR_DO,
    EXPR_SWITCH,
  } type;
  union {
    char const *identifier;
    char const *string;
    // int64_t fixed_integer;
    // double fixed_double;
    // mpz_t arb_integer;
    // mpfr_t real;
    // int64_t boolean;
    ast_bin_expr_t *binary_expr;
    ast_funcall_t *funcall;
    ast_if_t *if_;
    ast_for_t *for_;
    ast_while_t *while_;
    ast_switch_t *switch_;
    ast_do_t *do_;
    ast_expr_t *not_;
  } value;
};

ast_expr_t *create_ast_expr_t(int const type, void *value);
void free_ast_expr_t(ast_expr_t **expr_ptr);
void print_ast_expr_t(ast_expr_t const *expr, int indent);
void walk_ast_expr_t(ast_expr_t const *expr, symbol_table_t *sym_tab, int id);
#endif // __AST_NODE_EXPR__