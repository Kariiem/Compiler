#include "for.h"
#include "../utils.h"
#include "range.h"
#include "../../symbol.h"

ast_for_t *create_ast_for_t(char const *loop_var, ast_range_t *range,
                            ast_block_t *body) {
  ast_for_t *for_ = calloc(1, sizeof(ast_for_t));
  for_->loop_var = loop_var;
  for_->range = range;
  for_->body = body;
  return for_;
}

void free_ast_for_t(ast_for_t **for_ptr) {
  DEBUG_EPRINTF("free ast_for_t\n");
  ast_for_t *for_ = *for_ptr;
  DEBUG_ASSERT(for_, "for is NULL");
  FREE_ATOM(for_->loop_var);
  free_ast_range_t(&for_->range);
  free_ast_block_t(&for_->body);
  free(for_);
  *for_ptr = NULL;
}

void print_ast_for_t(ast_for_t const *for_loop, int indent){
  INDENT(indent);
  printf("ast_for_t\n");
  INDENT(indent + 1);
  printf("loop_var: %s\n", for_loop->loop_var);
  if (for_loop->range) {
    print_ast_range_t(for_loop->range, indent + 1);
  } else {
    INDENT(indent);
    printf("range: NULL\n");
  }
  if (for_loop->body) {
    print_ast_block_t(for_loop->body, indent + 1);
  } else {
    INDENT(indent);
    printf("body: NULL\n");
  }
}

void walk_ast_for_t(ast_for_t const *for_loop, symbol_table_t *sym_tab, int* id){
  DEBUG_EPRINTF("walk ast_for_t\n");
  walk_ast_range_t(for_loop->range, sym_tab,id);
  walk_ast_block_t(for_loop->body, sym_tab, id);
}