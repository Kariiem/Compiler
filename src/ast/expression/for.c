#include "for.h"
#include "../utils.h"
#include "range.h"

ast_for_t *create_ast_for_t(char const *loop_var, ast_range_t *range,
                            ast_block_t *body) {
  ast_for_t *for_ = calloc(1, sizeof(ast_for_t));
  for_->loop_var = loop_var;
  for_->range = range;
  for_->body = body;
  return for_;
}
bool free_ast_for_t(ast_for_t **for_ptr) {
  DEBUG_EPRINTF("free ast_for_t");
  ast_for_t *for_ = *for_ptr;
  if (for_ == NULL)
    return false;
  free(for_->loop_var);
  DEBUG_ASSERT(free_ast_range_t(&for_->range), "for->range == NULL");
  DEBUG_ASSERT(free_ast_block_t(&for_->body), "for->body == NULL");
  free(for_);
  *for_ptr = NULL;
  return true;
}