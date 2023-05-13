#ifndef __AST_NODE_IF__
#define __AST_NODE_IF__

#include "block.h"
#include <stdbool.h>
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_if_t ast_if_t;

struct ast_if_t {
  ast_expr_t *cond;
  ast_block_t *then_branch;
  ast_block_t *else_branch;
};
ast_if_t *create_ast_if_t(ast_expr_t *cond, ast_block_t *then_branch,
                          ast_block_t *else_branch);
void free_ast_if_t(ast_if_t **if_ptr);
#endif // __AST_NODE_IF__
