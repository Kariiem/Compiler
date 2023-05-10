#ifndef __AST_NODE_SOURCE__
#define __AST_NODE_SOURCE__
#include "datastructres/cvector.h"
#include "declarations/top_level_decl.h"
#include "module_decl.h"

typedef struct ast_source_t ast_source_t;
struct ast_source_t {
  ast_module_decl_t *module;
  cvector_vector_type(ast_top_level_decl_t *) decl_list;
};

#endif // __AST_NODE_SOURCE__
