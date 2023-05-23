#include "type_decl.h"
#include "../../symbol.h"
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
  DEBUG_EPRINTF("free ast_type_decl_t\n");
  ast_type_decl_t *type = *type_decl_ptr;
  if (type == NULL)
    return;
  // DEBUG_ASSERT(type, "type is NULL");
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
static symbol_table_t *get_the_toplevel_symbol_table() {
  symbol_table_t *it;
  it = global_symbol_table;
  while (it->parent) {
    return it;
  }
  return it;
}
static char *int_to_string(int num) {
  int size = snprintf(NULL, 0, "%d", num); // get the size of the string
  char *str = malloc(size + 1);            // allocate memory for the string
  if (str == NULL) {
    return NULL; // error: unable to allocate memory
  }
  snprintf(str, size + 1, "%d", num); // convert integer to string
  return str;
}
void walk_ast_type_decl_t(ast_type_decl_t const *type_decl, int *id) {
  DEBUG_EPRINTF("walk ast_type_decl_t\n");
  if (get_symbol(global_symbol_table, type_decl->type_name) != NULL) {
    fprintf(stderr, "Error: type %s already defined\n", type_decl->type_name);
    exit(1);
  }

  symbol_t *type_sym =
      create_symbol_t(type_decl->type_name, SYM_TY_TYPE, type_decl, *id);
  insert_symbol(global_symbol_table, type_sym);
  // pre-condition, all typelevel declarations are allowed only in global
  // scope(toplevel symbol table)
  ++(*id);
  for (int i = 0; i < cvector_size(type_decl->constructor_list); ++i) {
    ast_constructors_t *constructor = type_decl->constructor_list[i];
    if (get_symbol(global_symbol_table, constructor->con_name) != NULL) {
      fprintf(stderr, "Error: constructor-symbol %s already defined\n",
              constructor->con_name);
      exit(1);
    }
    ast_term_decl_t *term = create_ast_term_decl_t(
        TERM_VAL, constructor->con_name, type_decl->type_name,
        create_ast_expr_t(EXPR_INTEGER, int_to_string(i)));
    symbol_t *constructor_sym =
        create_symbol_t(constructor->con_name, SYM_TY_TERM, term, *id);
    insert_symbol(global_symbol_table, constructor_sym);
    ++(*id);
  }
  GEN_TYPES("%s\n", type_decl->type_name);
}
