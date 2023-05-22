#include "import_decl.h"
#include "../utils.h"
#include <stdlib.h>
ast_import_decl_t *create_ast_import_decl_t(char const *import_name) {
  ast_import_decl_t *import = calloc(1, sizeof(ast_import_decl_t));
  import->import_name = import_name;
  return import;
}
void free_ast_import_decl_t(ast_import_decl_t **import_ptr) {
  DEBUG_EPRINTF("free ast_import_decl_t\n");
  ast_import_decl_t *import = *import_ptr;
  DEBUG_ASSERT(import, "import is NULL");
  FREE_ATOM(import->import_name);
  free(import);
  *import_ptr = NULL;
}

void print_ast_import_decl_t(ast_import_decl_t const *import, int indent) {
  INDENT(indent);
  printf("ast_import_decl_t\n");
  INDENT(indent+1);
  printf("import_name: %s\n", import->import_name);
}

void walk_ast_import_decl_t(ast_import_decl_t const *import, symbol_table_t *sym_tab,int id){
  DEBUG_EPRINTF("walk ast_import_decl_t\n");
}