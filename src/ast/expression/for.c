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