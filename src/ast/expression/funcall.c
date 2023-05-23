#include "funcall.h"
#include "../../symbol.h"
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
  if (funcall == NULL)
    return;
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

void walk_ast_funcall_t(ast_funcall_t const *funcall, int *id) {
  DEBUG_EPRINTF("walk ast_funcall_t\n");
  symbol_t *sym = get_symbol(global_symbol_table, funcall->fun_name);
  // name checking
  if (sym == NULL || sym->type != SYM_TY_FUNC) {
    REPORT_ERROR("Error: %s is not a known function name.\n",
                 funcall->fun_name);
    exit(1);
  }
  // arg count checking
  if (cvector_size(funcall->args) >
      cvector_size(sym->value.func_val->param_list)) {
    REPORT_ERROR("Error: Function %s passed extra arguments.\n",
                 funcall->fun_name);
    exit(1);
  }
  // arg count checking
  if (cvector_size(funcall->args) <
      cvector_size(sym->value.func_val->param_list)) {
    REPORT_ERROR("Error: Function %s passed few arguments.\n",
                 funcall->fun_name);
    exit(1);
  }
  // type checking
  for (int i = 0; i < cvector_size(funcall->args); i++) {
    if (strcmp(get_ast_expr_type(funcall->args[i], global_symbol_table),
               sym->value.func_val->param_list[i]->param_type)) {
      REPORT_ERROR(
          "Error: Function %s passed argument of wrong type,for argument `%s`.\n",
          funcall->fun_name, sym->value.func_val->param_list[i]->param_name);
      exit(1);
    }
  }
  // Function call prologue
  for (int i = 0; i < cvector_size(funcall->args); i++) {
    walk_ast_expr_t(funcall->args[i], id);
  }
  GEN_INSTRUCTIONS("\tCALL _FUNCTION_%s_\n", funcall->fun_name);
}