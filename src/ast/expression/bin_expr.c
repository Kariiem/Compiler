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
  if (bin_expr == NULL)
    return;
  // DEBUG_ASSERT(bin_expr, "bin_expr is NULL");
  free_ast_expr_t(&bin_expr->left);
  free_ast_expr_t(&bin_expr->right);
  free(bin_expr);
  *bin_expr_ptr = NULL;
}

void print_ast_bin_expr_t(ast_bin_expr_t const *bin_expr, int indent) {
  INDENT(indent);
  printf("ast_bin_expr_t\n");
  INDENT(indent + 1);
  printf("op: %s\n", map_int_to_operators( bin_expr->op));
  print_ast_expr_t(bin_expr->left, indent + 1);
  print_ast_expr_t(bin_expr->right, indent + 1);
}

void walk_ast_bin_expr_t(ast_bin_expr_t const *bin_expr, int *id) {
  DEBUG_EPRINTF("walk ast_bin_expr_t\n");
  ast_expr_t *left = bin_expr->left;
  ast_expr_t *right = bin_expr->right;
  walk_ast_expr_t(left, id);
  walk_ast_expr_t(right, id);
  char const *left_type = get_ast_expr_type(left, global_symbol_table);
  char const *right_type = get_ast_expr_type(right, global_symbol_table);
  if (strcmp(left_type, right_type)) {
    ERROR(
        "Error: Type mismatch, operator %s cannot operate on %s and %s, \n",
        map_int_to_operators(bin_expr->op), left_type, right_type);
    exit(1);
  }

  switch (bin_expr->op) {
  default: {
    ERROR("Error: Unknown operator %ld\n", bin_expr->op);
    exit(1);
  }
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ: {
    if (strcmp(left_type, "int") && strcmp(left_type, "double")) {
      ERROR(
          "Error: Type mismatch, operator %s cannot operate on %s and %s, \n",
          map_int_to_operators(bin_expr->op), left_type, right_type);
      exit(1);
    }
    break;
  }
  case EXPR_AND:
  case EXPR_OR: {
    if (strcmp(left_type, "bool")) {
      ERROR(
          "Error: Type mismatch, operator %s cannot operate on %s and %s, \n",
          map_int_to_operators(bin_expr->op), left_type, right_type);
      exit(1);
    }
    break;
  }
  case EXPR_NEQ:
  case EXPR_EQ: {
    break;
  }
  }

  GEN_INSTRUCTIONS("\t%s\n", map_int_to_operators(bin_expr->op));
}