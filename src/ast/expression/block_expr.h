#ifndef __AST_NODE_BLOCK_EXPR__
#define __AST_NODE_BLOCK_EXPR__

typedef struct ast_term_decl_t ast_term_decl_t;
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_block_expr_t ast_block_expr_t;
typedef struct ast_assignment_t ast_assignment_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_block_expr_t {
  enum { EXPR, ASSIGN, DECL } type;
  union {
    ast_term_decl_t *decl;
    ast_expr_t *expr;
    ast_assignment_t *assign;
  } value;
};

ast_block_expr_t *create_ast_block_expr_t(int type, void *value);
void free_ast_block_expr_t(ast_block_expr_t **block_expr_ptr);
void print_ast_block_expr_t(ast_block_expr_t const *block_expr, int indent);
void walk_ast_block_expr_t(ast_block_expr_t const *block_expr,
                          int *id);

#endif // __AST_NODE_BLOCK_EXPR__