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
bool free_ast_bin_expr_t(ast_bin_expr_t **bin_expr_ptr) {
  DEBUG_EPRINTF("free free_ast_bin_expr_t");
  ast_bin_expr_t *bin_expr = *bin_expr_ptr;
  if (bin_expr == NULL)
    return false;
  DEBUG_ASSERT(free_ast_expr_t(&bin_expr->left), "bin_expr->left == NULL");
  DEBUG_ASSERT(free_ast_expr_t(&bin_expr->right), "bin_expr->right == NULL");
  free(bin_expr);
  *bin_expr_ptr = NULL;
  return true;
}