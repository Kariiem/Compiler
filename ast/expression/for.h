#ifndef __AST_NODE_FOR__
#define __AST_NODE_FOR__
#include "block.h"
#include "range.h"

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_for_t ast_for_t;

struct ast_for_t {
  char const *loop_var;
  ast_range_t *range;
  ast_block_t *body;
};

#endif // __AST_NODE_FOR__