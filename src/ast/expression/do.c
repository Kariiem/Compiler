#include "do.h"
#include "../../symbol.h"
#include "../utils.h"

ast_do_t *create_ast_do_t(ast_block_t *body) {
  ast_do_t *do_ = calloc(1, sizeof(ast_do_t));
  do_->body = body;
  return do_;
}

void free_ast_do_t(ast_do_t **do_ptr) {
  DEBUG_EPRINTF("free ast_do_t\n");
  ast_do_t *do_ = *do_ptr;
  if (do_ == NULL)
    return;
  // DEBUG_ASSERT(do_, "do is NULL");
  free_ast_block_t(&do_->body);
  free(do_);
  *do_ptr = NULL;
}

void print_ast_do_t(ast_do_t const *do_, int indent) {
  INDENT(indent);
  printf("ast_do_t\n");
  print_ast_block_t(do_->body, indent + 1);
}

void walk_ast_do_t(ast_do_t const *do_, int *id) {
  DEBUG_EPRINTF("walk ast_do_t\n");
  int label_id = *id;
  // DO prolouge
  push_scope(&global_symbol_table);
  // body
  symbol_table_t *sym_tab_nested_scope = create_symbol_table_t();
  sym_tab_nested_scope->parent = global_symbol_table;
  walk_ast_block_t(do_->body, id);

  // free_symbol_table_t(&sym_tab_nested_scope);
  // DO epilouge
  child_scope = global_symbol_table;
  pop_scope(&global_symbol_table);
}