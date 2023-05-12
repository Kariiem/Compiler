#ifndef __AST_NODE_BLOCK__
#define __AST_NODE_BLOCK__

#include "../datastructures/cvector.h"
#include "block_expr.h"
#include <stdbool.h>

typedef struct ast_block_t ast_block_t;

struct ast_block_t {
  cvector_vector_type(ast_block_expr_t *) block_expr_list;
};

ast_block_t *create_ast_block_t(cvector_vector_type(ast_block_expr_t *)
                                    block_expr_list);
bool free_ast_block_t(ast_block_t **block_ptr);

#endif // __AST_NODE_BLOCK__