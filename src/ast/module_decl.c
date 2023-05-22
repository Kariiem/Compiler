#include "module_decl.h"
#include "../symbol.h"
#include "tbassert.h"
#include "utils.h"

ast_module_decl_t *create_ast_module_decl_t(char const *module_name) {
  ast_module_decl_t *module = calloc(1, sizeof(ast_module_decl_t));
  module->module_name = module_name;
  return module;
}

void free_ast_module_decl_t(ast_module_decl_t **module_ptr) {
  DEBUG_EPRINTF("free ast_module_decl_t\n");
  ast_module_decl_t *module_decl = *module_ptr;
  DEBUG_ASSERT(module_decl, "module_decl is NULL");
  FREE_ATOM(module_decl->module_name);
  free(module_decl);
  *module_ptr = NULL;
}

void print_ast_module_decl_t(ast_module_decl_t const *module, int indent) {
  INDENT(indent);
  printf("ast_module_decl_t\n");
  INDENT(indent + 1);
  printf("module_name: %s\n", module->module_name);
}

void walk_ast_module_decl_t(ast_module_decl_t const *module,
                            symbol_table_t *sym_tab,int id) {
  DEBUG_EPRINTF("walk ast_module_decl_t\n");
}
