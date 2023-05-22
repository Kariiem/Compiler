#ifndef __AST_NODE_FOR__
#define __AST_NODE_FOR__
#include "block.h"
#include "range.h"
#include <stdbool.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_for_t ast_for_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_for_t {
  char const *loop_var;
  ast_range_t *range;
  ast_block_t *body;
};
ast_for_t *create_ast_for_t(char const *loop_var, ast_range_t *range,
                            ast_block_t *body);
void free_ast_for_t(ast_for_t **for_ptr);
void print_ast_for_t(ast_for_t const *for_loop, int indent);
void walk_ast_for_t(ast_for_t const *for_loop, symbol_table_t *sym_tab, int id);
#endif // __AST_NODE_FOR__