#include "expr.h"
#include "../utils.h"
#include "bin_expr.h"
#include "do.h"
#include "funcall.h"
#include "if.h"
#include "switch.h"
#include "while.h"
#include "../../symbol.h"
// #include <gmp.h>

ast_expr_t *create_ast_expr_t(int const type, void *value) {
  ast_expr_t *expr = calloc(1, sizeof(ast_expr_t));
  expr->type = type;

  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d\n", type);
    break;
  case EXPR_IDENTIFIER:
    expr->value.identifier = value;
    break;
  case EXPR_INTEGER:
    // TODO("EXPR_INTEGER UNIMPLEMENTED");
  case EXPR_INT:
    // TODO("EXPR_INT UNIMPLEMENTED");
  case EXPR_REAL:
    // TODO("EXPR_REAL UNIMPLEMENTED");
  case EXPR_DOUBLE:
    // TODO("EXPR_DOUBLE UNIMPLEMENTED");
  case EXPR_BOOL:
    // TODO("EXPR_BOOL UNIMPLEMENTED");
  case EXPR_STRING:
    expr->value.string = value;
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    expr->value.binary_expr = value;
    break;
  case EXPR_NOT:
    expr->value.not_ = value;
    break;
  // function call
  case EXPR_FUNCALL:
    expr->value.funcall = value;
    break;
  // compound expressions
  case EXPR_IF:
    expr->value.if_ = value;
    break;
  case EXPR_FOR:
    expr->value.for_ = value;
    break;
  case EXPR_WHILE:
  case EXPR_UNTIL:
    expr->value.while_ = value;
    break;
  case EXPR_DO:
    expr->value.do_ = value;
    break;
  case EXPR_SWITCH:
    expr->value.switch_ = value;
    break;
  }
  return expr;
}
void free_ast_expr_t(ast_expr_t **expr_ptr) {
  DEBUG_EPRINTF("free ast_expr_t\n");
  ast_expr_t *expr = *expr_ptr;
  DEBUG_ASSERT(expr, "expr is NULL\n");

  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d\n", expr->type);

  case EXPR_IDENTIFIER:
    FREE_ATOM(expr->value.identifier);
    break;
  case EXPR_INTEGER:
    // mpz_clear(expr->value.arb_integer);
  case EXPR_INT:
  case EXPR_REAL:
    // mpfr_clear(expr->value.real);
  case EXPR_DOUBLE:
  case EXPR_BOOL:
  case EXPR_STRING:
    FREE_ATOM(expr->value.string);
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    free_ast_bin_expr_t(&expr->value.binary_expr);
    break;
  case EXPR_NOT:
    free_ast_expr_t(&expr->value.not_);
    break;
  // function call
  case EXPR_FUNCALL:
    free_ast_funcall_t(&expr->value.funcall);
    break;
  // compound expressions
  case EXPR_IF:
    free_ast_if_t(&expr->value.if_);
    break;
  case EXPR_FOR:
    free_ast_for_t(&expr->value.for_);
    break;
  case EXPR_WHILE:
  case EXPR_UNTIL:
    free_ast_while_t(&expr->value.while_);
    break;
  case EXPR_DO:
    free_ast_do_t(&expr->value.do_);
    break;
  case EXPR_SWITCH:
    free_ast_switch_t(&expr->value.switch_);
    break;
  }
  free(expr);
  *expr_ptr = NULL;
}

void print_ast_expr_t(ast_expr_t const *expr, int indent) {
  INDENT(indent);
  printf("ast_expr_t\n");
  INDENT(indent+1);
  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);

  case EXPR_IDENTIFIER:
    printf("identifier: %s\n", expr->value.identifier);
    break;
  case EXPR_INTEGER:
    printf("integer: %s\n", expr->value.string);
    break;
  case EXPR_INT:
    printf("int: %s\n", expr->value.string);
    break;
  case EXPR_REAL:
    printf("real: %s\n", expr->value.string);
    break;
  case EXPR_DOUBLE:
    printf("double: %s\n", expr->value.string);
    break;
  case EXPR_BOOL:
    printf("bool: %s\n", expr->value.string);
    break;
  case EXPR_STRING:
    printf("string: %s\n", expr->value.string);
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    print_ast_bin_expr_t(expr->value.binary_expr, indent+1);
    break;
  case EXPR_NOT:
    print_ast_expr_t(expr->value.not_, indent);
    break;
  // function call
  case EXPR_FUNCALL:
    print_ast_funcall_t(expr->value.funcall, indent);
    break;
  // compound expressions
  case EXPR_IF:
    print_ast_if_t(expr->value.if_, indent);
    break;
  case EXPR_FOR:
    print_ast_for_t(expr->value.for_, indent);
    break;
  case EXPR_WHILE:
    print_ast_while_t(expr->value.while_, indent);
    break;
  case EXPR_UNTIL:
    print_ast_while_t(expr->value.while_, indent);
    break;
  case EXPR_DO:
    print_ast_do_t(expr->value.do_, indent);
    break;
  case EXPR_SWITCH:
    print_ast_switch_t(expr->value.switch_, indent);
    break;
  }
}

void walk_ast_expr_t(ast_expr_t const *expr, symbol_table_t *sym_tab){
  DEBUG_EPRINTF("walk ast_expr_t\n");
  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);
  case EXPR_IDENTIFIER:
    break;
  case EXPR_INTEGER:
  case EXPR_INT:
  case EXPR_REAL:
  case EXPR_DOUBLE:
  case EXPR_BOOL:
  case EXPR_STRING:
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    walk_ast_bin_expr_t(expr->value.binary_expr, sym_tab);
    break;
  case EXPR_NOT:
    walk_ast_expr_t(expr->value.not_, sym_tab);
    break;
  // function call
  case EXPR_FUNCALL:
    walk_ast_funcall_t(expr->value.funcall, sym_tab);
    break;
  // compound expressions
  case EXPR_IF:
    walk_ast_if_t(expr->value.if_, sym_tab);
    break;
  case EXPR_FOR:
    walk_ast_for_t(expr->value.for_, sym_tab);
    break;
  case EXPR_WHILE:
    walk_ast_while_t(expr->value.while_, sym_tab);
    break;
  case EXPR_UNTIL:
    walk_ast_while_t(expr->value.while_, sym_tab);
    break;
  case EXPR_DO:
    walk_ast_do_t(expr->value.do_, sym_tab);
    break;
  case EXPR_SWITCH:
    walk_ast_switch_t(expr->value.switch_, sym_tab);
    break;
  }
}