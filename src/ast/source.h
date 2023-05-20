#ifndef __AST_NODE_SOURCE__
#define __AST_NODE_SOURCE__
#include "datastructures/cvector.h"
#include "declaration/top_level_decl.h"
#include "module_decl.h"
#include <stdbool.h>

typedef struct ast_source_t ast_source_t;
struct ast_source_t {
  ast_module_decl_t *module;
  vtype(ast_top_level_decl_t *) decl_list;
};

ast_source_t *create_ast_source_t(ast_module_decl_t *module,
                                  vtype(ast_top_level_decl_t *)
                                      decl_list);

void free_ast_source_t(ast_source_t**source);

void print_ast_source_t(ast_source_t const *source, int indent);
#endif // __AST_NODE_SOURCE__
