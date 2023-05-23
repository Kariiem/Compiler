#include "fun_decl.h"
#include "../../symbol.h"
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
  if (fundecl == NULL)
    return;
  // DEBUG_ASSERT(fundecl, "fundecl is NULL");
  FREE_ATOM(fundecl->fun_name);
  CVECTOR_FREE(fundecl->param_list, free_ast_fun_param_t);
  FREE_ATOM(fundecl->return_type_name);
  free_ast_block_t(&fundecl->body);
  free(fundecl);
  *fundecl_ptr = NULL;
}

void print_ast_fundecl_t(ast_fundecl_t const *fundecl, int indent) {
  INDENT(indent);
  printf("ast_fundecl_t\n");
  INDENT(indent + 1);
  printf("fun_name: %s\n", fundecl->fun_name);
  INDENT(indent + 1);
  printf("return_type_name: %s\n", fundecl->return_type_name);
  INDENT(indent + 1);
  printf("param_list:\n");
  // cvector_for_each(fundecl->param_list, print_ast_fun_param_t, indent + 2);
  INDENT(indent + 1);
  printf("body:\n");
  print_ast_block_t(fundecl->body, indent + 2);
}

void walk_ast_fundecl_t(ast_fundecl_t const *fundecl, int *id) {
  DEBUG_EPRINTF("walk ast_fundecl_t\n");
  if (get_symbol(global_symbol_table, fundecl->fun_name) != NULL) {
    DEBUG_EPRINTF("Error: Function  %s re-definition.\n", fundecl->fun_name);
    exit(1);
  }
  symbol_t *fun_sym =
      create_symbol_t(fundecl->fun_name, SYM_TY_FUNC, fundecl, *id);
  insert_symbol(global_symbol_table, fun_sym);
  ++(*id);
  // SWAP the two files handles, to use walk_ast_block_t normally
  FILE *tmp = instructions;
  instructions = functions;
  // FUNCTION prologue
  GEN_INSTRUCTIONS("_FUNCTION_%s_:\n", fundecl->fun_name);
  push_scope(&global_symbol_table);
  // FUNCTION params
  for (int i = 0; i < cvector_size(fundecl->param_list); i++) {
    ast_fun_param_t *param = fundecl->param_list[i];
    symbol_t *param_symbol =
        create_symbol_t(param->param_name, SYM_TY_FUNC_PARAM, param, *id);
    insert_symbol(global_symbol_table, param_symbol);
    // DEBUG_EPRINTF("param %s, type %s\n", param->param_name, param->param_type);
    ++(*id);
  }
  for (int i = ((int)cvector_size(fundecl->param_list)) - 1; i >= 0; --i) {
    ast_fun_param_t *param = fundecl->param_list[i];
    int address = get_symbol(global_symbol_table, param->param_name)->id;
    GEN_INSTRUCTIONS("\tSTORE $%d\n", address);
  }
  // FUNCTION body
  walk_ast_block_t(fundecl->body, id);
  ast_expr_t *last_expr = get_last_block_expr(fundecl->body);
  char const *last_expr_type = get_ast_expr_type(last_expr, child_scope);
  if (strcmp(fundecl->return_type_name, last_expr_type)) {
    REPORT_ERROR("Error: Function %s return type mismatch.\n",
                  fundecl->fun_name);
    exit(1);
  }
  // FUNCTION epilogue
  GEN_INSTRUCTIONS("\tRETURN\n");
  pop_scope(&global_symbol_table);
  instructions = tmp;
}
