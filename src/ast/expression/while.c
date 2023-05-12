#include "while.h"
#include "../utils.h"
#include "block.h"
#include "expr.h"

ast_while_t *create_ast_while_t(ast_expr_t *cond, ast_block_t *body) {
  ast_while_t *while_ = calloc(1, sizeof(ast_while_t));
  while_->cond = cond;
  while_->body = body;
  return while_;
}
bool free_ast_while_t(ast_while_t **while_ptr) {
  DEBUG_EPRINTF("free ast_while_t");
  ast_while_t *while_ = *while_ptr;
  if (while_ == NULL)
    return false;
  DEBUG_ASSERT(free_ast_expr_t(&while_->cond), "while->cond == NULL");
  DEBUG_ASSERT(free_ast_block_t(&while_->body), "while->body == NULL");
  free(while_);
  *while_ptr = NULL;
  return true;
}