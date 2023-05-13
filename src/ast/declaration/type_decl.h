#ifndef __AST_NODE_TYPE_DECL__
#define __AST_NODE_TYPE_DECL__

#include "../datastructures/cvector.h"
#include "constructors.h"

typedef struct ast_type_decl_t ast_type_decl_t;
struct ast_type_decl_t {
  char const *type_name;
  vtype(ast_constructors_t *) constructor_list;
};

ast_type_decl_t *create_ast_type_decl_t(char const *type_name,
                                        vtype(ast_constructors_t *)
                                            constructor_list);
void free_ast_type_decl_t(ast_type_decl_t **type_decl_ptr);

#endif // __AST_NODE_TYPE_DECL__