#ifndef __AST_NODE_CASE__
#define __AST_NODE_CASE__

#include "../datastructres/cvector.h"
#include "block.h"
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_case_t ast_case_t;

struct ast_case_t {
  ast_expr_t *case_expr; // null means the else branch (default)
  ast_block_t *block;
};

#endif // __AST_NODE_CASE__
