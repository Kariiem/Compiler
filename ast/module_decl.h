#ifndef __AST_NODE_MODULE__
#define __AST_NODE_MODULE__
#include "datastructres/cvector.h"

typedef struct ast_module_decl_t ast_module_decl_t;
struct ast_module_decl_t {
  char const *module_name;
};

#endif // __AST_NODE_MODULE__
