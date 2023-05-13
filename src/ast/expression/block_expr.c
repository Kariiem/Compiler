#include "block_expr.h"
#include "../utils.h"
#include "expr.h"

ast_block_expr_t *create_ast_block_expr_t(int type, void *value) {
  ast_block_expr_t *block_expr = calloc(1, sizeof(ast_block_expr_t));
  block_expr->type = type;
  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", type);
  case EXPR: {
    block_expr->value.expr = value;
    break;
  };
  case DECL: {
    block_expr->value.decl = value;
    break;
  };
  }
  return block_expr;
}

void free_ast_block_expr_t(ast_block_expr_t **block_expr_ptr) {
  DEBUG_EPRINTF("free block_expr_t");
  ast_block_expr_t *block_expr = *block_expr_ptr;
  DEBUG_ASSERT(block_expr, "block_expr is NULL");
  switch (block_expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", block_expr->type);

  EXPR:
    free_ast_expr_t(&block_expr->value.expr);
    break;
  DECL:
    TODO("free_ast_term_decl_t UNIMPLEMENTED");
    break;
  }
  free(block_expr);
  *block_expr_ptr = NULL;
}
