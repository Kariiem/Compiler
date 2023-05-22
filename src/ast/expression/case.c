#include "case.h"
#include "../utils.h"
#include "block.h"
#include "expr.h"

ast_case_t *create_ast_case_t(ast_expr_t *expr, ast_block_t *body) {
  ast_case_t *case_ = calloc(1, sizeof(ast_case_t));
  case_->case_expr = expr;
  case_->body = body;
  return case_;
}

void free_ast_case_t(ast_case_t **case_ptr) {
  DEBUG_EPRINTF("free ast_case_t\n");
  ast_case_t *case_ = *case_ptr;
  if(case_==NULL) return;
  // DEBUG_ASSERT(case_, "case is NULL");
  if (case_->case_expr)
    free_ast_expr_t(&case_->case_expr);
  free_ast_block_t(&case_->body);
  free(case_);
  *case_ptr = NULL;
}

void print_ast_case_t(ast_case_t const *case_, int indent) {
  INDENT(indent);
  printf("ast_case_t\n");
  if (case_->case_expr)
    print_ast_expr_t(case_->case_expr, indent + 1);
  print_ast_block_t(case_->body, indent + 1);
}

void walk_ast_case_t(ast_case_t const *case_, symbol_table_t *sym_tab, int *id) {
  DEBUG_EPRINTF("walk ast_case_t\n");
  if (case_->case_expr)
    walk_ast_expr_t(case_->case_expr, sym_tab,id);
  walk_ast_block_t(case_->body, sym_tab, id);
}