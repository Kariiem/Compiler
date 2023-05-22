#ifndef __AST_NODE_RANGE__
#define __AST_NODE_RANGE__

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_range_t ast_range_t;
typedef struct symbol_table_t symbol_table_t;
struct ast_range_t {
  ast_expr_t *start;
  ast_expr_t *end;
  ast_expr_t *step; // null means 1 (default)
};

ast_range_t *create_ast_range_t(ast_expr_t *start, ast_expr_t *end,
                                ast_expr_t *step);
void free_ast_range_t(ast_range_t **range_ptr);
void print_ast_range_t(ast_range_t const *range, int indent);
void walk_ast_range_t(ast_range_t const *range, symbol_table_t *sym_tab, int id);
#endif // __AST_NODE_RANGE__