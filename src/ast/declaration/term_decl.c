#include "term_decl.h"
#include "../utils.h"
#include <stdlib.h>
#include "../../symbol.h"
ast_term_decl_t *create_ast_term_decl_t(int type, char const *decl_name,
                                        char const *decl_type,
                                        ast_expr_t *value) {
  ast_term_decl_t *term = calloc(1, sizeof(ast_term_decl_t));
  term->type = type;
  term->decl_name = decl_name;
  term->decl_type = decl_type;
  term->value = value;
  return term;
}
void free_ast_term_decl_t(ast_term_decl_t **term_decl_ptr) {
  DEBUG_EPRINTF("free ast_term_decl_t\n");
  ast_term_decl_t *term = *term_decl_ptr;
  DEBUG_ASSERT(term, "term is NULL");
  FREE_ATOM(term->decl_name);
  FREE_ATOM(term->decl_type);
  if (term->value)
    free_ast_expr_t(&term->value);
  free(term);
  *term_decl_ptr = NULL;
}

void print_ast_term_decl_t(ast_term_decl_t const *term_decl, int indent) {
  INDENT(indent);
  printf("ast_term_decl_t\n");
  INDENT(indent + 1);
  printf("decl_qualifier:%s\n", term_decl->type == TERM_VAR ? "var" : "val");
  INDENT(indent + 1);
  printf("decl_name: %s\n", term_decl->decl_name);
  INDENT(indent + 1);
  printf("decl_type: %s\n", term_decl->decl_type);
  if (term_decl->value) {
    print_ast_expr_t(term_decl->value, indent + 1);
  }
  else {
    INDENT(indent);
    printf("value: NULL\n");
  }
}

void walk_ast_term_decl_t(ast_term_decl_t const *term_decl,
                          symbol_table_t *sym_tab,int id) {
  DEBUG_EPRINTF("walk ast_term_decl_t\n");
  if (term_decl->value) {
    walk_ast_expr_t(term_decl->value, sym_tab,id);
  }
}