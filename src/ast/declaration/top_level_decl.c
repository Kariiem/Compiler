#include "top_level_decl.h"
#include "../utils.h"
#include "fun_decl.h"
#include "import_decl.h"
#include "term_decl.h"
#include "type_decl.h"
#include <stdlib.h>

ast_top_level_decl_t *create_ast_top_level_decl_t(int type, void *value) {
  ast_top_level_decl_t *top_decl = calloc(1, sizeof(ast_top_level_decl_t));
  top_decl->type = type;
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
  case DECL_ASSIGN:
    top_decl->value.assign = value;
    break;
  }
  return top_decl;
}

void free_ast_top_level_decl_t(ast_top_level_decl_t **top_level_decl_ptr) {
  DEBUG_EPRINTF("free ast_top_level_decl_t\n");
  ast_top_level_decl_t *top_decl = *top_level_decl_ptr;
  // DEBUG_ASSERT(top_decl, "top_decl is NULL");
  if(top_decl==NULL) return;
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
  case DECL_ASSIGN:
    free_ast_assignment_t(&top_decl->value.assign);
    break;
  }
  free(top_decl);
  *top_level_decl_ptr = NULL;
}

void print_ast_top_level_decl_t(ast_top_level_decl_t const *top_level_decl,
                                int indent) {
  INDENT(indent);
  printf("ast_top_level_decl_t\n");
  switch (top_level_decl->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", top_level_decl->type);
  case DECL_IMPORT:
    print_ast_import_decl_t(top_level_decl->value.import, indent + 1);
    break;
  case DECL_TYPE:
    print_ast_type_decl_t(top_level_decl->value.type_name, indent + 1);
    break;
  case DECL_TERM:
    print_ast_term_decl_t(top_level_decl->value.term, indent + 1);
    break;
  case DECL_FUN:
    print_ast_fundecl_t(top_level_decl->value.fun, indent + 1);
    break;
  case DECL_ASSIGN:
    print_ast_assignment_t(top_level_decl->value.assign, indent + 1);
    break;
  }
}

void walk_ast_top_level_decl_t(const ast_top_level_decl_t *top_level_decl,
                               symbol_table_t *sym_tab, int *id) {
  DEBUG_EPRINTF("walk ast_top_level_decl_t\n");
  switch (top_level_decl->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", top_level_decl->type);
  case DECL_IMPORT:
    walk_ast_import_decl_t(top_level_decl->value.import, sym_tab, id);
    break;
  case DECL_TYPE:
    walk_ast_type_decl_t(top_level_decl->value.type_name, sym_tab, id);
    break;
  case DECL_TERM:
    ++(*id);
    walk_ast_term_decl_t(top_level_decl->value.term, sym_tab, id);
    break;
  case DECL_FUN:
    walk_ast_fundecl_t(top_level_decl->value.fun, sym_tab, id);
    break;
  case DECL_ASSIGN:
    walk_ast_assignment_t(top_level_decl->value.assign, sym_tab, id);
    break;
  }
}