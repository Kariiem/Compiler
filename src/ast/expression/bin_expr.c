#include "bin_expr.h"
#include "../utils.h"
#include "expr.h"
ast_bin_expr_t *create_ast_bin_expr_t(ast_expr_t *left, ast_expr_t *right,
                                      int64_t op) {
  ast_bin_expr_t *bin_expr = calloc(1, sizeof(ast_bin_expr_t));
  bin_expr->left = left;
  bin_expr->right = right;
  bin_expr->op = op;
  return bin_expr;
}
void free_ast_bin_expr_t(ast_bin_expr_t **bin_expr_ptr) {
  DEBUG_EPRINTF("free ast_bin_expr_t\n");
  ast_bin_expr_t *bin_expr = *bin_expr_ptr;
  DEBUG_ASSERT(bin_expr,"bin_expr is NULL");
  free_ast_expr_t(&bin_expr->left);
  free_ast_expr_t(&bin_expr->right);
  free(bin_expr);
  *bin_expr_ptr = NULL;
}

void print_ast_bin_expr_t(ast_bin_expr_t const *bin_expr, int indent){
  INDENT(indent);
  printf("ast_bin_expr_t\n");
  INDENT(indent+1);
  printf("op: %ld\n", bin_expr->op);
  print_ast_expr_t(bin_expr->left, indent+1);
  print_ast_expr_t(bin_expr->right, indent+1);
}

void walk_ast_bin_expr_t(ast_bin_expr_t const *bin_expr, symbol_table_t *sym_tab, int id){
  DEBUG_EPRINTF("walk ast_bin_expr_t\n");
  walk_ast_expr_t(bin_expr->left, sym_tab,id);
  walk_ast_expr_t(bin_expr->right, sym_tab,id);
}