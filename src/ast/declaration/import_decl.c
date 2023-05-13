#include "import_decl.h"
#include "../utils.h"
#include <stdlib.h>
ast_import_decl_t *create_ast_import_decl_t(char const *import_name) {
  ast_import_decl_t *import = calloc(1, sizeof(ast_import_decl_t));
  import->import_name = import_name;
  return import;
}
void free_ast_import_decl_t(ast_import_decl_t **import_ptr) {
  DEBUG_EPRINTF("free ast_import_decl_t");
  ast_import_decl_t *import = *import_ptr;
  DEBUG_ASSERT(import, "import is NULL");
  FREE_ATOM(import->import_name);
  free(import);
  *import_ptr = NULL;
}