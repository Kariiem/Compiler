#include "module_decl.h"
#include "tbassert.h"
#include "utils.h"

ast_module_decl_t *create_ast_module_decl_t(char const *module_name) {
  ast_module_decl_t *module = calloc(1, sizeof(ast_module_decl_t));
  module->module_name = module_name;
  return module;
}

bool free_ast_module_decl_t(ast_module_decl_t *module) {
  DEBUG_EPRINTF("free ast_module_decl_t");
}