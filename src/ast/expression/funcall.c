#include "funcall.h"
#include "../utils.h"
#include "expr.h"
ast_funcall_t *create_ast_funcall_t(char const *fun_name,
                                    vtype(ast_expr_t *) args) {
  ast_funcall_t *funcall = calloc(1, sizeof(ast_funcall_t));
  funcall->fun_name = fun_name;
  funcall->args = args;
  return funcall;
}
void free_ast_funcall_t(ast_funcall_t **funcall_ptr) {
  DEBUG_EPRINTF("free ast_funcall_t\n");
  ast_funcall_t *funcall = *funcall_ptr;
  if(funcall==NULL) return;
  // DEBUG_ASSERT(funcall, "funcall is NULL");
  FREE_ATOM(funcall->fun_name);
  CVECTOR_FREE(funcall->args, free_ast_expr_t);
  free(funcall);
  *funcall_ptr = NULL;
}

void print_ast_funcall_t(ast_funcall_t const *funcall, int indent) {
  INDENT(indent);
  printf("ast_funcall_t\n");
  INDENT(indent + 1);
  printf("fun_name: %s\n", funcall->fun_name);
  INDENT(indent + 1);
  printf("args:\n");
  ast_expr_t **it;
  cvector_for_each_in(it, funcall->args) { print_ast_expr_t(*it, indent + 2); }
}

void walk_ast_funcall_t(ast_funcall_t const *funcall, int* id) {
  DEBUG_EPRINTF("walk ast_funcall_t\n");
  
}