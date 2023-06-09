#include "if.h"
#include "../utils.h"
#include "block.h"
#include "expr.h"

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
  DEBUG_ASSERT(if_, "if is NULL");
  free_ast_expr_t(&if_->cond);
  free_ast_block_t(&if_->then_branch);
  free_ast_block_t(&if_->else_branch);
  free(if_);
  *if_ptr = NULL;
}