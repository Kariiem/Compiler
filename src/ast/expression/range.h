#ifndef __AST_NODE_RANGE__
#define __AST_NODE_RANGE__

#include <stdbool.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_range_t ast_range_t;

struct ast_range_t {
  ast_expr_t *start;
  ast_expr_t *end;
  ast_expr_t *step; // null means 1 (default)
};

ast_range_t *create_ast_range_t(ast_expr_t *start, ast_expr_t *end,
                                ast_expr_t *step);
bool free_ast_range_t(ast_range_t **range_ptr);

#endif // __AST_NODE_RANGE__