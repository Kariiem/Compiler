#include "type_decl.h"
#include "../utils.h"
#include "constructors.h"
#include "../../symbol.h"
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
  DEBUG_EPRINTF("free ast_type_decl_t\n");
  ast_type_decl_t *type = *type_decl_ptr;
  DEBUG_ASSERT(type, "type is NULL");
  FREE_ATOM(type->type_name);
  CVECTOR_FREE(type->constructor_list, free_ast_constructors_t);
  free(type);
  *type_decl_ptr = NULL;
}

void print_ast_type_decl_t(ast_type_decl_t const *type_decl, int indent) {
  INDENT(indent);
  printf("ast_type_decl_t\n");
  INDENT(indent + 1);
  printf("type_name: %s\n", type_decl->type_name);
  INDENT(indent + 1);
  printf("constructor_list:\n");
  // cvector_for_each(type_decl->constructor_list, print_ast_constructors_t,
  //                  indent + 2);
}
void walk_ast_type_decl_t(ast_type_decl_t const *type_decl,
                          symbol_table_t *sym_tab, int id) {
  DEBUG_EPRINTF("walk ast_type_decl_t\n");
  symbol_t* type_sym = create_symbol_t(type_decl->type_name, SYM_TY_TYPE,type_decl,0);
  insert_symbol(sym_tab, type_sym);
  GEN_TYPES(type_decl->type_name);
}
