#ifndef __AST_NODE_BLOCK_EXPR__
#define __AST_NODE_BLOCK_EXPR__

#include <stdbool.h>

typedef struct ast_term_decl_t ast_term_decl_t;
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_block_expr_t ast_block_expr_t;

struct ast_block_expr_t {
  enum { EXPR, DECL } type;
  union {
    ast_term_decl_t *decl;
    ast_expr_t *expr;
  } value;
};

ast_block_expr_t *create_ast_block_expr_t(int type, void *value);
bool free_ast_block_expr_t(ast_block_expr_t **block_expr_ptr);

#endif // __AST_NODE_BLOCK_EXPR__