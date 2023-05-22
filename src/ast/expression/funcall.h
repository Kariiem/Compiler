#ifndef __AST_NODE_FUNCALL__
#define __AST_NODE_FUNCALL__
#include "../datastructures/cvector.h"
#include <stdbool.h>
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_funcall_t ast_funcall_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_funcall_t {
  char const *fun_name;
  vtype(ast_expr_t *) args;
};
ast_funcall_t *create_ast_funcall_t(char const *fun_name,
                                    vtype(ast_expr_t *) args);
void free_ast_funcall_t(ast_funcall_t **funcall_ptr);
void print_ast_funcall_t(ast_funcall_t const *funcall, int indent);
void walk_ast_funcall_t(ast_funcall_t const *funcall, symbol_table_t *sym_tab, int* id);
#endif // __AST_NODE_FUNCALL__