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
  DEBUG_EPRINTF("free ast_case_t");
  ast_case_t *case_ = *case_ptr;
  DEBUG_ASSERT(case_, "case is NULL");
  free_ast_expr_t(&case_->case_expr);
  free_ast_block_t(&case_->body);
  free(case_);
  *case_ptr = NULL;
}
