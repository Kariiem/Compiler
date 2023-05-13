#ifndef __AST_NODE_TYPE_DECL__
#define __AST_NODE_TYPE_DECL__

#include "../datastructures/cvector.h"
#include "constructors.h"

typedef struct ast_type_decl_t ast_type_decl_t;
struct ast_type_decl_t {
  char const *type_name;
  vtype(ast_constructors_t *) constructor_list;
};
#endif // __AST_NODE_TYPE_DECL__