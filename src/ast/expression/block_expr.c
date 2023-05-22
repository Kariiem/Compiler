#include "block_expr.h"
#include "../../symbol.h"
#include "../assignment.h"
#include "../declaration/term_decl.h"
#include "../utils.h"
#include "expr.h"

ast_block_expr_t *create_ast_block_expr_t(int type, void *value) {
  ast_block_expr_t *block_expr = calloc(1, sizeof(ast_block_expr_t));
  block_expr->type = type;
  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", type);
  case EXPR:
    block_expr->value.expr = value;
    break;

  case DECL:
    block_expr->value.decl = value;
    break;

  case ASSIGN:
    block_expr->value.assign = value;
    break;
  }
  return block_expr;
}

void free_ast_block_expr_t(ast_block_expr_t **block_expr_ptr) {
  DEBUG_EPRINTF("free block_expr_t\n");
  ast_block_expr_t *block_expr = *block_expr_ptr;
  DEBUG_ASSERT(block_expr, "block_expr is NULL");
  switch (block_expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", block_expr->type);

  case EXPR:
    free_ast_expr_t(&block_expr->value.expr);
    break;
  case DECL:
    free_ast_term_decl_t(&block_expr->value.decl);
    break;
  case ASSIGN:
    free_ast_assignment_t(&block_expr->value.assign);
    break;
  }
  free(block_expr);
  *block_expr_ptr = NULL;
}

void print_ast_block_expr_t(ast_block_expr_t const *block_expr, int indent) {
  
  switch (block_expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", block_expr->type);

  case EXPR:
    print_ast_expr_t(block_expr->value.expr, indent);
    break;
  case DECL:
    print_ast_term_decl_t(block_expr->value.decl, indent);
    break;
  case ASSIGN:
    print_ast_assignment_t(block_expr->value.assign, indent);
    break;
  }
}

void walk_ast_block_expr_t(ast_block_expr_t const *block_expr,
                           symbol_table_t *sym_tab) {
  DEBUG_EPRINTF("walk ast_block_expr_t\n");
}
