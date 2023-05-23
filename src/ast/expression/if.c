#include "if.h"
#include "../../symbol.h"
#include "../utils.h"
#include "block.h"
#include "block_expr.h"
#include "expr.h"
#include <string.h>

ast_if_t *create_ast_if_t(ast_expr_t *cond, ast_block_t *then_branch,
                          ast_block_t *else_branch) {
  ast_if_t *if_ = calloc(1, sizeof(ast_if_t));
  if_->cond = cond;
  if_->then_branch = then_branch;
  if_->else_branch = else_branch;
  return if_;
}

void free_ast_if_t(ast_if_t **if_ptr) {
  DEBUG_EPRINTF("free ast_if_t\n");
  ast_if_t *if_ = *if_ptr;
  if (if_ == NULL)
    return;
  // DEBUG_ASSERT(if_, "if is NULL");
  free_ast_expr_t(&if_->cond);
  free_ast_block_t(&if_->then_branch);
  free_ast_block_t(&if_->else_branch);
  free(if_);
  *if_ptr = NULL;
}

void print_ast_if_t(ast_if_t const *if_, int indent) {
  INDENT(indent);
  printf("ast_if_t\n");
  print_ast_expr_t(if_->cond, indent + 1);
  print_ast_block_t(if_->then_branch, indent + 1);
  print_ast_block_t(if_->else_branch, indent + 1);
}

void walk_ast_if_t(ast_if_t const *if_, int *id) {
  DEBUG_EPRINTF("walk ast_if_t\n");
  // the nested scope symbol table
  char const *cond_type = get_ast_expr_type(if_->cond, global_symbol_table);
  if (strcmp(cond_type, "bool")) {
    ERROR("Error: If condition expects a bool expression, got %s.\n",
          cond_type);
    exit(1);
  }
  walk_ast_expr_t(if_->cond, id);
  if (is_bool_expr_always_false(if_->cond, global_symbol_table)) {
    WARNING("Warning: If condition is always false.\n");
    print_ast_expr_t(if_->cond, 4);
  }
  int label_id = *id;
  // IF prolouge
  GEN_INSTRUCTIONS("\tJMPF _if_%d_\n", label_id);
  // Then branch
  push_scope(&global_symbol_table);
  walk_ast_block_t(if_->then_branch, id);
  GEN_INSTRUCTIONS("\tJMP _if_end_%d_\n", label_id);
  GEN_INSTRUCTIONS("_if_%d_:\n", label_id);
  child_scope = global_symbol_table;
  pop_scope(&global_symbol_table);
  // Else branch
  push_scope(&global_symbol_table);
  walk_ast_block_t(if_->else_branch, id);
  pop_scope(&global_symbol_table);
  // IF epilouge
  GEN_INSTRUCTIONS("_if_end_%d_:\n", label_id);
}