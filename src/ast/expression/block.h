#ifndef __AST_NODE_BLOCK__
#define __AST_NODE_BLOCK__

#include "../datastructures/cvector.h"
#include "block_expr.h"
#include <stdbool.h>

typedef struct ast_block_t ast_block_t;
typedef struct symbol_table_t symbol_table_t;
struct ast_block_t {
  vtype(ast_block_expr_t *) block_expr_list;
};

ast_block_t *create_ast_block_t(vtype(ast_block_expr_t *)
                                    block_expr_list);
void free_ast_block_t(ast_block_t **block_ptr);
void print_ast_block_t(ast_block_t const *block, int indent);
void walk_ast_block_t(ast_block_t const *block, symbol_table_t *sym_tab,int id);
#endif // __AST_NODE_BLOCK__