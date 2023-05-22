#include "bin_expr.h"
#include "../../symbol.h"
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
  DEBUG_ASSERT(bin_expr, "bin_expr is NULL");
  free_ast_expr_t(&bin_expr->left);
  free_ast_expr_t(&bin_expr->right);
  free(bin_expr);
  *bin_expr_ptr = NULL;
}

void print_ast_bin_expr_t(ast_bin_expr_t const *bin_expr, int indent) {
  INDENT(indent);
  printf("ast_bin_expr_t\n");
  INDENT(indent + 1);
  printf("op: %ld\n", bin_expr->op);
  print_ast_expr_t(bin_expr->left, indent + 1);
  print_ast_expr_t(bin_expr->right, indent + 1);
}

void walk_ast_bin_expr_t(ast_bin_expr_t const *bin_expr,
                         symbol_table_t *sym_tab, int *id) {
  DEBUG_EPRINTF("walk ast_bin_expr_t\n");
  ast_expr_t *left = bin_expr->left;
  ast_expr_t *right = bin_expr->right;
  walk_ast_expr_t(left, sym_tab, id);
  walk_ast_expr_t(right, sym_tab, id);
  char const *left_type = get_ast_expr_type(left, sym_tab);
  char const *right_type = get_ast_expr_type(right, sym_tab);
  if (strcmp(left_type, right_type)) {
    REPORT_ERROR(RED "Type mismatch:" GRN
                     "operator %s cannot operate on %s and %s, \n" RESET,
                 map_int_to_operators(bin_expr->op), left_type, right_type);
    exit(1);
  }
  if (bin_expr->op == EXPR_ADD || bin_expr->op == EXPR_SUB ||
      bin_expr->op == EXPR_MUL || bin_expr->op == EXPR_DIV ||
      bin_expr->op == EXPR_MOD || bin_expr->op == EXPR_EXP ||
      bin_expr->op == EXPR_EQ || bin_expr->op == EXPR_NEQ ||
      bin_expr->op == EXPR_LT || bin_expr->op == EXPR_LEQ ||
      bin_expr->op == EXPR_GT || bin_expr->op == EXPR_GEQ) {
    if (strcmp(left_type, "int") && strcmp(left_type, "double")) {
      REPORT_ERROR(RED "Type mismatch:" GRN
                       "operator %s cannot operate on %s and %s, \n" RESET,
                   map_int_to_operators(bin_expr->op), left_type, right_type);
      exit(1);
    }
  }
  if (bin_expr->op == EXPR_AND || bin_expr->op == EXPR_OR ||
      bin_expr->op == EXPR_EQ || bin_expr->op == EXPR_NEQ) {
    if (strcmp(left_type, "bool")) {
      REPORT_ERROR(RED "Type mismatch:" GRN
                       "operator %s cannot operate on %s and %s, \n" RESET,
                   map_int_to_operators(bin_expr->op), left_type, right_type);
      exit(1);
    }
  }

  GEN_INSTRUCTIONS("%s\n", map_int_to_operators(bin_expr->op));
}