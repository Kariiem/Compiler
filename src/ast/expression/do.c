#include "do.h"
#include "../utils.h"

ast_do_t *create_ast_do_t(ast_block_t *body) {
  ast_do_t *do_ = calloc(1, sizeof(ast_do_t));
  do_->body = body;
  return do_;
}
void free_ast_do_t(ast_do_t **do_ptr) {
  DEBUG_EPRINTF("free ast_do_t\n");
  ast_do_t *do_ = *do_ptr;
  DEBUG_ASSERT(do_, "do is NULL");
  free_ast_block_t(&do_->body);
  free(do_);
  *do_ptr = NULL;
}