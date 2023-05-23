#include "switch.h"
#include "../../symbol.h"
#include "../utils.h"
#include "bin_expr.h"
#include "block.h"
#include "case.h"
#include "expr.h"
#include <stdlib.h>
#include <string.h>

ast_switch_t *create_ast_switch_t(ast_expr_t *expr, vtype(ast_case_t *) cases) {
  ast_switch_t *switch_ = calloc(1, sizeof(ast_switch_t));
  switch_->enum_expr = expr;
  switch_->cases = cases;
  return switch_;
}

void free_ast_switch_t(ast_switch_t **switch_ptr) {
  DEBUG_EPRINTF("free ast_switch_t\n");
  ast_switch_t *switch_ = *switch_ptr;
  if (switch_ == NULL)
    return;
  // DEBUG_ASSERT(switch_, "switch is NULL");
  free_ast_expr_t(&switch_->enum_expr);
  CVECTOR_FREE(switch_->cases, free_ast_case_t);
  free(switch_);
  *switch_ptr = NULL;
}

void print_ast_switch_t(ast_switch_t const *switch_, int indent) {
  INDENT(indent);
  printf("ast_switch_t\n");
  print_ast_expr_t(switch_->enum_expr, indent + 1);
  ast_case_t **it;
  cvector_for_each_in(it, switch_->cases) { print_ast_case_t(*it, indent + 1); }
}

void walk_ast_switch_t(ast_switch_t const *switch_, int *id) {
  DEBUG_EPRINTF("walk ast_switch_t\n");
  // if (switch_->enum_expr->type == EXPR_INTEGER ||
  // (switch_->enum_expr->type == EXPR_IDENTIFIER &&
  //  !strcmp(get_ast_expr_type(switch_->enum_expr, global_symbol_table),
  //  "int")))
  char const *switch_expr_type =
      get_ast_expr_type(switch_->enum_expr, global_symbol_table);
  if (strcmp(switch_expr_type, "int") == 0 ||
      get_symbol(global_symbol_table, switch_expr_type)->type == SYM_TY_TYPE) {

    int label_id = *id;
    // SWITCH prologue
    GEN_INSTRUCTIONS("_switch_start_%d_:\n", label_id);
    // walk_ast_expr_t(switch_->enum_expr, id);

    ast_bin_expr_t *case_expr =
        create_ast_bin_expr_t(switch_->enum_expr, NULL, EXPR_EQ);
    for (int i = 0; i < cvector_size(switch_->cases); ++i) {
      if (switch_->cases[i]->case_expr) {
        case_expr->right = switch_->cases[i]->case_expr;
        walk_ast_bin_expr_t(case_expr, id);
        GEN_INSTRUCTIONS("\tJMPT _switch_case_%d_\n", label_id + i + 1);
      }
    }
    //--------------------------------------------
    ast_expr_t *last_expr = get_last_block_expr(switch_->cases[0]->body);
    char const *switch_return_type =
        get_ast_expr_type(last_expr, global_symbol_table);
    //--------------------------------------------
    for (int i = 0; i < cvector_size(switch_->cases); ++i) {

      GEN_INSTRUCTIONS("_switch_case_%d_:\n", label_id + i + 1);
      push_scope(&global_symbol_table);
      walk_ast_block_t(switch_->cases[i]->body, id);
      last_expr = get_last_block_expr(switch_->cases[i]->body);
      if (last_expr == NULL ||
          strcmp(switch_return_type,
                 get_ast_expr_type(last_expr, child_scope))) {
        REPORT_ERROR("Error: Switch case return-type mismatch.\n");
        exit(1);
      }
      // CASE epilogue
      child_scope = global_symbol_table;
      pop_scope(&global_symbol_table);
      GEN_INSTRUCTIONS("\tJMP _switch_end_%d_\n", label_id);
    }
    GEN_INSTRUCTIONS("_switch_end_%d_:\n", label_id);
  } else {
    REPORT_ERROR(
        "Error: Switch expression must be int or user-defined enum, found %s\n",
        switch_expr_type);
    exit(1);
  }
}