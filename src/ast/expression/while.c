#include "while.h"
#include "../../symbol.h"
#include "../utils.h"
#include "block.h"
#include "expr.h"

ast_while_t *create_ast_while_t(ast_expr_t *cond, ast_block_t *body) {
  ast_while_t *while_ = calloc(1, sizeof(ast_while_t));
  while_->cond = cond;
  while_->body = body;
  return while_;
}

void free_ast_while_t(ast_while_t **while_ptr) {
  DEBUG_EPRINTF("free ast_while_t\n");
  ast_while_t *while_ = *while_ptr;
  if (while_ == NULL)
    return;
  // DEBUG_ASSERT(while_, "while is NULL");
  free_ast_expr_t(&while_->cond);
  free_ast_block_t(&while_->body);
  free(while_);
  *while_ptr = NULL;
}

void print_ast_while_t(ast_while_t const *while_, int indent) {
  INDENT(indent);
  printf("ast_while_t\n");
  print_ast_expr_t(while_->cond, indent + 1);
  print_ast_block_t(while_->body, indent + 1);
}

void walk_ast_while_t(ast_while_t const *while_, int *id) {
  DEBUG_EPRINTF("walk ast_while_t\n");
  char const *cond_type = get_ast_expr_type(while_->cond, global_symbol_table);
  if (strcmp(cond_type, "bool")) {
    REPORT_ERROR("Error: While/Until condition must have type bool, got %s\n",
                 cond_type);
    exit(1);
  }
  int label_id = *id;
  // WHILE prolouge
  push_scope(&global_symbol_table);
  GEN_INSTRUCTIONS("_while_%d_:\n", label_id);
  walk_ast_expr_t(while_->cond, id);
  GEN_INSTRUCTIONS("\tJMPF _while_end_%d_\n", label_id);
  // body
  walk_ast_block_t(while_->body, id);

  // free_symbol_table_t(&sym_tab_nested_scope);

  GEN_INSTRUCTIONS("\tJMP _while_%d_\n", label_id);

  // WHILE epilouge
  child_scope = global_symbol_table;
  pop_scope(&global_symbol_table);
  GEN_INSTRUCTIONS("_while_end_%d_:\n", label_id);
}