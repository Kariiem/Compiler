#ifndef __AST_NODE_EXPR__
#define __AST_NODE_EXPR__

#include "datastructres/cvector.h"
#include "expression/bin_expr.h"
#include "expression/block.h"
#include "expression/do.h"
#include "expression/for.h"
#include "expression/funcall.h"
#include "expression/if.h"
#include "expression/switch.h"
#include "expression/while.h"
#include <gmp.h>
#include <mpfr.h>
#include <stdint.h>

typedef struct ast_expr_t ast_expr_t;



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
    EXPR_EXPR,
    EXPR_NOT,
    EXPR_AND,
    EXPR_OR,
    EXPR_LT,
    EXPR_GT,
    EXPR_LEQ,
    EXPR_GEQ,
    EXPR_EQ,
    EXPR_NEQ,
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
    int64_t fixed_integer;
    double fixed_double;
    mpz_t arb_integer;
    mpfr_t real;
    int64_t boolean;
    ast_bin_expr_t *binary_expr;
    ast_fun_call_t *funcall;
    ast_if_t *if_;
    ast_for_t *for_;
    ast_while_t *while_;
    ast_switch_t *switch_;

  } value;
};


#endif // __AST_NODE_EXPR__