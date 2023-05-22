#include "for.h"
#include "../../symbol.h"
#include "../utils.h"
#include "bin_expr.h"
#include "block_expr.h"
#include "expr.h"
#include "range.h"

ast_for_t *create_ast_for_t(char const *loop_var, ast_range_t *range,
                            ast_block_t *body) {
  ast_for_t *for_ = calloc(1, sizeof(ast_for_t));
  for_->loop_var = loop_var;
  for_->range = range;
  for_->body = body;
  return for_;
}

void free_ast_for_t(ast_for_t **for_ptr) {
  DEBUG_EPRINTF("free ast_for_t\n");
  ast_for_t *for_ = *for_ptr;
  if (for_ == NULL)
    return;
  // DEBUG_ASSERT(for_, "for is NULL");
  FREE_ATOM(for_->loop_var);
  free_ast_range_t(&for_->range);
  free_ast_block_t(&for_->body);
  free(for_);
  *for_ptr = NULL;
}

void print_ast_for_t(ast_for_t const *for_loop, int indent) {
  INDENT(indent);
  printf("ast_for_t\n");
  INDENT(indent + 1);
  printf("loop_var: %s\n", for_loop->loop_var);
  if (for_loop->range) {
    print_ast_range_t(for_loop->range, indent + 1);
  } else {
    INDENT(indent);
    printf("range: NULL\n");
  }
  if (for_loop->body) {
    print_ast_block_t(for_loop->body, indent + 1);
  } else {
    INDENT(indent);
    printf("body: NULL\n");
  }
}

void walk_ast_for_t(ast_for_t const *for_loop, int *id) {
  DEBUG_EPRINTF("walk ast_for_t\n");
  // walk_ast_range_t(for_loop->range, id);
  int label_id = *id;
  push_scope(&global_symbol_table);
  ast_term_decl_t *loop_var_term = create_ast_term_decl_t(
      TERM_VAR, for_loop->loop_var, "int", for_loop->range->start);

  ast_expr_t *loop_var_reference =
      create_ast_expr_t(EXPR_IDENTIFIER, loop_var_term->decl_name);
  ast_bin_expr_t *cmp_expr =
      create_ast_bin_expr_t(loop_var_reference, for_loop->range->end, EXPR_LEQ);

  ast_bin_expr_t *step_expr = create_ast_bin_expr_t(
      loop_var_reference, for_loop->range->step, EXPR_ADD);

  ast_assignment_t *update_expr = create_ast_assignment_t(
      loop_var_term->decl_name, create_ast_expr_t(EXPR_ADD, step_expr));

  walk_ast_term_decl_t(loop_var_term, id);
  GEN_INSTRUCTIONS("_for_start_%d_:\n", label_id);
  walk_ast_bin_expr_t(cmp_expr, id);
  GEN_INSTRUCTIONS("\tJMPF _for_end_%d_:\n", label_id);
  walk_ast_block_t(for_loop->body, id);
  walk_ast_assignment_t(update_expr, id);
  GEN_INSTRUCTIONS("\tJMP _for_start_%d_\n", label_id);
  // FOR epilogue
  child_scope = global_symbol_table;
  pop_scope(&global_symbol_table);
  GEN_INSTRUCTIONS("_for_end_%d_:\n", label_id);
}