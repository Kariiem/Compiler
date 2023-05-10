#ifndef __AST_NODE_RANGE__
#define __AST_NODE_RANGE__

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_range_t ast_range_t;

struct ast_range_t {
    ast_expr_t * start;
    ast_expr_t * end;
    ast_expr_t * step; // null means 1 (default)
};

#endif // __AST_NODE_RANGE__