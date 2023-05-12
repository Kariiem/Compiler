#include "expr.h"
#include "../utils.h"
#include "bin_expr.h"
#include "do.h"
#include "funcall.h"
#include "if.h"
#include "switch.h"
#include "while.h"
#include <gmp.h>

ast_expr_t *create_ast_expr_t(int type, void *value) {
  ast_expr_t *expr = calloc(1, sizeof(ast_expr_t));
  expr->type = type;

  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", type);
    break;
  EXPR_IDENTIFIER:
    expr->value.identifier = value;
    break;
  EXPR_INTEGER:
    TODO("EXPR_INTEGER UNIMPLEMENTED");
    break;
  EXPR_INT:
    TODO("EXPR_INT UNIMPLEMENTED");
    break;
  EXPR_REAL:
    TODO("EXPR_REAL UNIMPLEMENTED");
    break;
  EXPR_DOUBLE:
    TODO("EXPR_DOUBLE UNIMPLEMENTED");
    break;
  EXPR_BOOL:
    TODO("EXPR_BOOL UNIMPLEMENTED");
    break;
  EXPR_STRING:
    expr->value.string = value;
    break;
  // binary expressions
  EXPR_ADD:
  EXPR_SUB:
  EXPR_MUL:
  EXPR_DIV:
  EXPR_MOD:
  EXPR_EXP:
  EXPR_AND:
  EXPR_OR:
  EXPR_LT:
  EXPR_GT:
  EXPR_LEQ:
  EXPR_GEQ:
  EXPR_EQ:
  EXPR_NEQ:
    expr->value.binary_expr = value;
    // This maybe redundant
    expr->value.binary_expr->op = type;
    break;
  EXPR_NOT:
    expr->value.not_ = value;
    break;
  // function call
  EXPR_FUNCALL:
    expr->value.funcall = value;
    break;
  // compound expressions
  EXPR_IF:
    expr->value.if_ = value;
    break;
  EXPR_FOR:
    expr->value.for_ = value;
    break;
  EXPR_WHILE:
    expr->value.while_ = value;
    break;
  EXPR_UNTIL:
    expr->value.while_ = value;
    expr->value.while_->cond =
        create_ast_expr_t(EXPR_NOT, expr->value.while_->cond);
    break;
  EXPR_DO:
    expr->value.do_ = value;
    break;
  EXPR_SWITCH:
    expr->value.switch_ = value;
    break;
  }
}
bool free_ast_expr_t(ast_expr_t **expr_ptr) {
  DEBUG_EPRINTF("free ast_expr_t");
  ast_expr_t *expr = *expr_ptr;
  if (expr == NULL)
    return false;

  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);

  EXPR_IDENTIFIER:
    free(expr->value.identifier);
    break;
  EXPR_INTEGER:
    mpz_clear(expr->value.arb_integer);
    break;
  EXPR_INT:
    break;
  EXPR_REAL:
    mpfr_clear(expr->value.real);
    break;
  EXPR_DOUBLE:
    break;
  EXPR_BOOL:
    break;
  EXPR_STRING:
    free(expr->value.string);
    break;
  // binary expressions
  EXPR_ADD:
  EXPR_SUB:
  EXPR_MUL:
  EXPR_DIV:
  EXPR_MOD:
  EXPR_EXP:
  EXPR_AND:
  EXPR_OR:
  EXPR_LT:
  EXPR_GT:
  EXPR_LEQ:
  EXPR_GEQ:
  EXPR_EQ:
  EXPR_NEQ:
    free_ast_bin_expr_t(&expr->value.binary_expr);
    break;
  EXPR_NOT:
    free_ast_expr_t(&expr->value.not_);
    break;
  // function call
  EXPR_FUNCALL:
    free_ast_funcall_t(&expr->value.funcall);
    break;
  // compound expressions
  EXPR_IF:
    free_ast_if_t(&expr->value.if_);
    break;
  EXPR_FOR:
    free_ast_for_t(&expr->value.for_);
    break;
  EXPR_WHILE:
    free_ast_while_t(&expr->value.while_);
    break;
  EXPR_UNTIL:
    free_ast_while_t(&expr->value.while_);
    break;
  EXPR_DO:
    free_ast_do_t(&expr->value.do_);
    break;
  EXPR_SWITCH:
    free_ast_switch_t(&expr->value.switch_);
    break;
  }
  free(expr);
  *expr_ptr = NULL;
  return true;
}