#ifndef __AST_NODE_CASE__
#define __AST_NODE_CASE__
#include "../datastructures/cvector.h"
#include "block.h"
#include <stdbool.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_case_t ast_case_t;
typedef struct symbol_table_t symbol_table_t;
struct ast_case_t {
  ast_expr_t *case_expr; // null means the else branch (default)
  ast_block_t *body;
};
ast_case_t *create_ast_case_t(ast_expr_t *expr, ast_block_t *body);
void free_ast_case_t(ast_case_t **case_ptr);
void print_ast_case_t(ast_case_t const *case_, int indent);
void walk_ast_case_t(ast_case_t const *case_, symbol_table_t *sym_tab, int id);
#endif // __AST_NODE_CASE__
