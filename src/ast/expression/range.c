#include "range.h"
#include "../utils.h"
#include "expr.h"
#include "../../symbol.h"

ast_range_t *create_ast_range_t(ast_expr_t *start, ast_expr_t *end,
                                ast_expr_t *step) {
  ast_range_t *range = calloc(1, sizeof(ast_range_t));
  range->start = start;
  range->end = end;
  range->step = step;
  return range;
}

void free_ast_range_t(ast_range_t **range_ptr) {
  DEBUG_EPRINTF("free ast_range_t\n");
  ast_range_t *range = *range_ptr;
  DEBUG_ASSERT(range, "range is NULL");
  free_ast_expr_t(&range->start);
  free_ast_expr_t(&range->end);
  if (range->step)
    free_ast_expr_t(&range->step);
  free(range);
  *range_ptr = NULL;
}

void print_ast_range_t(ast_range_t const *range, int indent){
  INDENT(indent);
  printf("ast_range_t\n");
  print_ast_expr_t(range->start, indent+1);
  print_ast_expr_t(range->end, indent+1);
  if (range->step)
    print_ast_expr_t(range->step, indent+1);
}

void walk_ast_range_t(ast_range_t const *range, symbol_table_t *sym_tab){
  DEBUG_EPRINTF("walk ast_range_t\n");
  walk_ast_expr_t(range->start, sym_tab);
  walk_ast_expr_t(range->end, sym_tab);
  if (range->step)
    walk_ast_expr_t(range->step, sym_tab);
}