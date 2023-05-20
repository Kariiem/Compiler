#ifndef __AST_NODE_WHILE__
#define __AST_NODE_WHILE__
#include "block.h"
#include "stdbool.h"
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_while_t ast_while_t; // for while and until

struct ast_while_t {
  ast_expr_t *cond;
  ast_block_t *body;
};

ast_while_t *create_ast_while_t(ast_expr_t *cond, ast_block_t *body);
void free_ast_while_t(ast_while_t **while_ptr);
#endif // __AST_NODE_WHILE__