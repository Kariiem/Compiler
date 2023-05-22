#include "fun_decl.h"
#include "../utils.h"
#include "../../symbol.h"
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

void print_ast_fundecl_t(ast_fundecl_t const *fundecl, int indent){
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

void walk_ast_fundecl_t(ast_fundecl_t const *fundecl, symbol_table_t *sym_tab,int id){
  DEBUG_EPRINTF("walk ast_fundecl_t\n");

}
