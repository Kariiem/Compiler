#include "block.h"
#include "../utils.h"
#include "block_expr.h"

ast_block_t *create_ast_block_t(cvector_vector_type(ast_block_expr_t *)
                                    block_expr_list) {
  ast_block_t *block = calloc(1, sizeof(ast_block_t));
  block->block_expr_list = block_expr_list;
  return block;
}
bool free_ast_block_t(ast_block_t **block_ptr) {
  DEBUG_EPRINTF("free ast_block_t");
  ast_block_t *block = *block_ptr;
  if (block == NULL)
    return false;
    
  CVECTOR_FREE(block->block_expr_list, free_ast_block_expr_t);
  free(block);
  *block_ptr = NULL;
  return true;
}