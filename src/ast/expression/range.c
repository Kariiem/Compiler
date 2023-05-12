#include "range.h"
#include "../utils.h"
#include "expr.h"
ast_range_t *create_ast_range_t(ast_expr_t *start, ast_expr_t *end,
                                ast_expr_t *step) {
  ast_range_t *range = calloc(1, sizeof(ast_range_t));
  range->start = start;
  range->end = end;
  range->step = step;
  return range;
}
bool free_ast_range_t(ast_range_t **range_ptr) {
  DEBUG_EPRINTF("free ast_range_t");
  ast_range_t *range = *range_ptr;
  if (range == NULL)
    return false;
  DEBUG_ASSERT(free_ast_expr_t(&range->start), "");
  DEBUG_ASSERT(free_ast_expr_t(&range->end), "");
  if (range->step)
    DEBUG_ASSERT(free_ast_expr_t(&range->step), "");
  free(range);
  *range_ptr = NULL;
  return true;
}