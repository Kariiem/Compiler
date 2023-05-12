#include "funcall.h"
#include "../utils.h"
#include "expr.h"
ast_funcall_t *create_ast_funcall_t(char const *fun_name,
                                    cvector_vector_type(ast_expr_t *) args) {
  ast_funcall_t *funcall = calloc(1, sizeof(ast_funcall_t));
  funcall->fun_name = fun_name;
  funcall->args = args;
  return funcall;
}
bool free_ast_funcall_t(ast_funcall_t **funcall_ptr) {
  DEBUG_EPRINTF("free ast_funcall_t");
  ast_funcall_t *funcall = *funcall_ptr;
  if (funcall == NULL)
    return false;
  free(funcall->fun_name);
  
  CVECTOR_FREE(funcall->args, free_ast_expr_t);
  free(funcall);
  *funcall_ptr = NULL;
  return true;
}