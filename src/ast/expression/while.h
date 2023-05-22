#ifndef __AST_NODE_WHILE__
#define __AST_NODE_WHILE__
#include "block.h"

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_while_t ast_while_t; // for while and until
typedef struct symbol_table_t symbol_table_t;

struct ast_while_t {
  ast_expr_t *cond;
  ast_block_t *body;
};

ast_while_t *create_ast_while_t(ast_expr_t *cond, ast_block_t *body);
void free_ast_while_t(ast_while_t **while_ptr);
void print_ast_while_t(ast_while_t const *while_, int indent);
void walk_ast_while_t(ast_while_t const *while_, int *id);
#endif // __AST_NODE_WHILE__