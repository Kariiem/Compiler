#include "fun_decl.h"
#include "../utils.h"
ast_fundecl_t *create_ast_fundecl_t(char const *fun_name,
                                    vtype(ast_fun_param_t *) param_list,
                                    char const *return_type_name,
                                    ast_block_t *body) {
  ast_fundecl_t *fundecl = calloc(1, sizeof(ast_fundecl_t));
  fundecl->fun_name = fun_name;
  fundecl->return_type_name = return_type_name;
  fundecl->param_list = param_list;
  fundecl->body = body;
  return fundecl;
}
void free_ast_fundecl_t(ast_fundecl_t **fundecl_ptr) {
  DEBUG_EPRINTF("free ast_fundecl_t\n");
  ast_fundecl_t *fundecl = *fundecl_ptr;
  DEBUG_ASSERT(fundecl, "fundecl is NULL");
  FREE_ATOM(fundecl->fun_name);
  CVECTOR_FREE(fundecl->param_list, free_ast_fun_param_t);
  FREE_ATOM(fundecl->return_type_name);
  free_ast_block_t(&fundecl->body);
  free(fundecl);
  *fundecl_ptr = NULL;
}
