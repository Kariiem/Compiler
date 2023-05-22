#ifndef __AST_NODE_DO__
#define __AST_NODE_DO__
#include "block.h"

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_do_t ast_do_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_do_t {
  ast_block_t *body;
};

ast_do_t *create_ast_do_t(ast_block_t *body);
void free_ast_do_t(ast_do_t **do_ptr);
void print_ast_do_t(ast_do_t const *do_, int indent);
void walk_ast_do_t(ast_do_t const *do_, symbol_table_t *sym_tab, int id);
#endif // __AST_NODE_DO__