#include "source.h"
#include "datastructures/cvector_utils.h"
#include "datastructures/utils.h"
#include "declaration/top_level_decl.h"
#include "utils.h"
ast_source_t *create_ast_source_t(ast_module_decl_t *module,
                                  vtype(ast_top_level_decl_t *) decl_list) {
  ast_source_t *source = calloc(1, sizeof(ast_source_t));
  source->module = module;
  source->decl_list = decl_list;
  return source;
}

void free_ast_source_t(ast_source_t **source) {
  DEBUG_EPRINTF("free ast_source_t\n");
  ast_source_t *source_ptr = *source;
  DEBUG_ASSERT(source_ptr, "source is NULL");
  free_ast_module_decl_t(&source_ptr->module);
  CVECTOR_FREE(source_ptr->decl_list, free_ast_top_level_decl_t);
  free(source_ptr);
  *source = NULL;
}

void print_ast_source_t(ast_source_t const *source,int indent) {
  printf("ast_source_t\n");
  print_ast_module_decl_t(source->module,indent+1);

  ast_top_level_decl_t **it;
  cvector_for_each_in(it, source->decl_list) {
    print_ast_top_level_decl_t(*it,indent+1);
  }
}
