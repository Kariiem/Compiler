#include "type_decl.h"
#include "../utils.h"
#include "constructors.h"
#include <stdlib.h>

ast_type_decl_t *create_ast_type_decl_t(char const *type_name,
                                        vtype(ast_constructors_t *)
                                            constructor_list) {
  ast_type_decl_t *type = calloc(1, sizeof(ast_type_decl_t));
  type->type_name = type_name;
  type->constructor_list = constructor_list;
  return type;
}
void free_ast_type_decl_t(ast_type_decl_t **type_decl_ptr) {
  DEBUG_EPRINTF("free ast_type_decl_t");
  ast_type_decl_t *type = *type_decl_ptr;
  DEBUG_ASSERT(type, "type is NULL");
  FREE_ATOM(type->type_name);
  CVECTOR_FREE(type->constructor_list, free_ast_constructors_t);
  free(type);
  *type_decl_ptr = NULL;
}