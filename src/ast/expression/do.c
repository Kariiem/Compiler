#include "do.h"
#include "../utils.h"

ast_do_t *create_ast_do_t(ast_block_t *body) {
  ast_do_t *do_ = calloc(1, sizeof(ast_do_t));
  do_->body = body;
  return do_;
}
bool free_ast_do_t(ast_do_t **do_ptr) {
  DEBUG_EPRINTF("free do_");
  ast_do_t *do_ = *do_ptr;
  if (do_ == NULL)
    return false;
  DEBUG_ASSERT(free_ast_block_t(&do_->body), "do->body == NULL");
  free(do_);
  *do_ptr = NULL;
  return true;
}