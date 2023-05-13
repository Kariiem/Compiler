#include "fun_param.h"
#include "../utils.h"
ast_fun_param_t *create_ast_fun_param_t(int type, char const *param_name,
                                        char const *param_type) {
  ast_fun_param_t *fun_param = calloc(1, sizeof(ast_fun_param_t));
  fun_param->type = type;
  fun_param->param_name = param_name;
  fun_param->param_type = param_type;
  return fun_param;
}
void free_ast_fun_param_t(ast_fun_param_t **fun_param_ptr) {
  DEBUG_EPRINTF("free ast_fun_param_t");
  ast_fun_param_t *fun_param = *fun_param_ptr;
  DEBUG_ASSERT(fun_param, "fun_param is NULL");
  FREE_ATOM(fun_param->param_name);
  FREE_ATOM(fun_param->param_type);
  free(fun_param);
  *fun_param_ptr = NULL;
}