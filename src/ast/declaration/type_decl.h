#ifndef __AST_NODE_TYPE_DECL__
#define __AST_NODE_TYPE_DECL__

#include "../datastructures/cvector.h"
#include "constructors.h"

typedef struct ast_type_decl_t ast_type_decl_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_type_decl_t {
  char const *type_name;
  vtype(ast_constructors_t *) constructor_list;
};

ast_type_decl_t *create_ast_type_decl_t(char const *type_name,
                                        vtype(ast_constructors_t *)
                                            constructor_list);
void free_ast_type_decl_t(ast_type_decl_t **type_decl_ptr);
void print_ast_type_decl_t(ast_type_decl_t const *type_decl, int indent);
void walk_ast_type_decl_t(ast_type_decl_t const *type_decl, int *id);
#endif // __AST_NODE_TYPE_DECL__