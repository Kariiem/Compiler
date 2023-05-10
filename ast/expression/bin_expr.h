#ifndef __AST_NODE_BIN_EXP__
#define __AST_NODE_BIN_EXP__

#include <stdint.h>
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_bin_expr_t ast_bin_expr_t;

struct ast_bin_expr_t {
  ast_expr_t *left;
  ast_expr_t *right;
  int64_t op;
};

#endif // __AST_NODE_BIN_EXP__