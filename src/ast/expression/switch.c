#include "switch.h"
#include "../utils.h"
#include "case.h"
#include "expr.h"
#include "../../symbol.h"

ast_switch_t *create_ast_switch_t(ast_expr_t *expr, vtype(ast_case_t *) cases) {
  ast_switch_t *switch_ = calloc(1, sizeof(ast_switch_t));
  switch_->enum_expr = expr;
  switch_->cases = cases;
  return switch_;
}

void free_ast_switch_t(ast_switch_t **switch_ptr) {
  DEBUG_EPRINTF("free ast_switch_t\n");
  ast_switch_t *switch_ = *switch_ptr;
  DEBUG_ASSERT(switch_, "switch is NULL");
  free_ast_expr_t(&switch_->enum_expr);
  CVECTOR_FREE(switch_->cases, free_ast_case_t);
  free(switch_);
  *switch_ptr = NULL;
}

void print_ast_switch_t(ast_switch_t const *switch_, int indent){
  INDENT(indent);
  printf("ast_switch_t\n");
  print_ast_expr_t(switch_->enum_expr, indent+1);
  ast_case_t **it;
  cvector_for_each_in(it,switch_->cases) {
    print_ast_case_t(*it, indent+1);
  }
}

void walk_ast_switch_t(ast_switch_t const *switch_, symbol_table_t *sym_tab, int* id){
  DEBUG_EPRINTF("walk ast_switch_t\n");
  walk_ast_expr_t(switch_->enum_expr, sym_tab,id);
  ast_case_t **it;
  cvector_for_each_in(it,switch_->cases) {
    walk_ast_case_t(*it, sym_tab,id);
  }
}