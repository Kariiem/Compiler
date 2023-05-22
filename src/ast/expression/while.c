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
  DEBUG_ASSERT(while_, "while is NULL");
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

void walk_ast_while_t(ast_while_t const *while_, symbol_table_t *sym_tab, int* id) {
  DEBUG_EPRINTF("walk ast_while_t\n");
  walk_ast_expr_t(while_->cond, sym_tab,id);
  walk_ast_block_t(while_->body, sym_tab,id);
}