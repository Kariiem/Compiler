#ifndef __AST_NODE_WHILE__
#define __AST_NODE_WHILE__

#include "block.h"
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_while_t ast_while_t; // for while and until

struct ast_while_t {
  ast_expr_t *cond;
  ast_block_t *body;
};

#endif // __AST_NODE_WHILE__