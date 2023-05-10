#ifndef __AST_NODE_BLOCK__
#define __AST_NODE_BLOCK__

#include "../datastructures/cvector.h"

typedef struct ast_term_decl_t ast_term_decl_t;
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_block_t ast_block_t;
typedef struct ast_block_expr_t ast_block_expr_t;

struct ast_block_t {
  cvector_vector_type(ast_block_expr_t *) block_expr_list;
};

struct ast_block_expr_t {
  enum { EXPR, DECL };
  union {
    ast_term_decl_t *decl;
    ast_expr_t *expr;
  } value;
};
#endif // __AST_NODE_BLOCK__