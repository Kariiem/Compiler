#ifndef __AST_NODE_MODULE__
#define __AST_NODE_MODULE__
#include <stdbool.h>
typedef struct ast_module_decl_t ast_module_decl_t;
typedef struct symbol_table_t symbol_table_t;
struct ast_module_decl_t {
  char const *module_name;
};

ast_module_decl_t *create_ast_module_decl_t(char const *module_name);

void free_ast_module_decl_t(ast_module_decl_t**module_ptr);

void print_ast_module_decl_t(ast_module_decl_t const*module,int indent);

void walk_ast_module_decl_t(ast_module_decl_t const*module,symbol_table_t*sym_tab,int* id);
#endif // __AST_NODE_MODULE__
