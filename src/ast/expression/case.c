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
bool free_ast_case_t(ast_case_t **case_ptr) {
  DEBUG_EPRINTF("free ast_case_t");
  ast_case_t *case_ = *case_ptr;
  if (case_ == NULL)
    return false;
  DEBUG_ASSERT(free_ast_expr_t(&case_->case_expr), "case->case_expr == NULL");
  DEBUG_ASSERT(free_ast_block_t(&case_->body), "case->body == NULL");
  free(case_);
  *case_ptr = NULL;
  return true;
}
