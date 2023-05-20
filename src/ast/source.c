#include "source.h"
#include "utils.h"
ast_source_t *create_ast_source_t(ast_module_decl_t *module,
                                  vtype(ast_top_level_decl_t *)
                                      decl_list) {
  ast_source_t *source = calloc(1, sizeof(ast_source_t));
  source->module = module;
  source->decl_list = decl_list;
  return source;
}

bool free_ast_source_t(ast_source_t *source){
    TODO("free ast_source_t");
}
