#ifndef __AST_NODE_MODULE__
#define __AST_NODE_MODULE__
#include <stdbool.h>
typedef struct ast_module_decl_t ast_module_decl_t;
struct ast_module_decl_t {
  char const *module_name;
};

ast_module_decl_t *create_ast_module_decl_t(char const *module_name);

void free_ast_module_decl_t(ast_module_decl_t**module_ptr);

void print_ast_module_decl_t(ast_module_decl_t const*module,int indent);
#endif // __AST_NODE_MODULE__
