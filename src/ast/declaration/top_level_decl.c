#include "top_level_decl.h"
#include "../utils.h"
#include "fun_decl.h"
#include "import_decl.h"
#include "term_decl.h"
#include "type_decl.h"
#include <stdlib.h>

ast_top_level_decl_t *create_ast_top_level_decl_t(int type, void *value) {
  ast_top_level_decl_t *top_decl = calloc(1, sizeof(ast_top_level_decl_t));
  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", type);
  case DECL_IMPORT:
    top_decl->value.import = value;
    break;
  case DECL_TYPE:
    top_decl->value.type_name = value;
    break;
  case DECL_TERM:
    top_decl->value.term = value;
    break;
  case DECL_FUN:
    top_decl->value.fun = value;
    break;
  }
  return top_decl;
}
void free_ast_top_level_decl_t(ast_top_level_decl_t **top_level_decl_ptr) {
  DEBUG_EPRINTF("free ast_top_level_decl_t");
  ast_top_level_decl_t *top_decl = *top_level_decl_ptr;
  DEBUG_ASSERT(top_decl, "top_decl is NULL");
  switch (top_decl->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", top_decl->type);
  case DECL_IMPORT:
    free_ast_import_decl_t(&top_decl->value.import);
    break;
  case DECL_TYPE:
    free_ast_type_decl_t(&top_decl->value.type_name);
    break;
  case DECL_TERM:
    free_ast_term_decl_t(&top_decl->value.term);
    break;
  case DECL_FUN:
    free_ast_fundecl_t(&top_decl->value.fun);
    break;
  }
  free(top_decl);
  *top_level_decl_ptr = NULL;
}