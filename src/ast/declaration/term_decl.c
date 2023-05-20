#include "term_decl.h"
#include "../utils.h"
#include <stdlib.h>

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
  DEBUG_EPRINTF("free ast_term_decl_t");
  ast_term_decl_t *term = *term_decl_ptr;
  DEBUG_ASSERT(term, "term is NULL");
  FREE_ATOM(term->decl_name);
  FREE_ATOM(term->decl_type);
  if (term->value)
    free_ast_expr_t(&term->value);
  free(term);
  *term_decl_ptr = NULL;
}