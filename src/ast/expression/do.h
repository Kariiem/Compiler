#ifndef __AST_NODE_DO__
#define __AST_NODE_DO__
#include "block.h"
#include <stdbool.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_do_t ast_do_t;

struct ast_do_t {
  ast_block_t *body;
};

ast_do_t *create_ast_do_t(ast_block_t *body);
void free_ast_do_t(ast_do_t **do_ptr);

#endif // __AST_NODE_DO__