#include "switch.h"
#include "../utils.h"
#include "case.h"
#include "expr.h"
ast_switch_t *create_ast_switch_t(ast_expr_t *expr, vtype(ast_case_t *) cases) {
  ast_switch_t *switch_ = calloc(1, sizeof(ast_switch_t));
  switch_->enum_expr = expr;
  switch_->cases = cases;
  return switch_;
}
void free_ast_switch_t(ast_switch_t **switch_ptr) {
  DEBUG_EPRINTF("free ast_switch_t");
  ast_switch_t *switch_ = *switch_ptr;
  DEBUG_ASSERT(switch_, "switch is NULL");
  free_ast_expr_t(&switch_->enum_expr);
  CVECTOR_FREE(switch_->cases, free_ast_case_t);
  free(switch_);
  *switch_ptr = NULL;
}