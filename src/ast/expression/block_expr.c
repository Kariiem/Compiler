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
  if(block_expr==NULL) return;
  // DEBUG_ASSERT(block_expr, "block_expr is NULL");
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
                           symbol_table_t *sym_tab, int *id) {
  DEBUG_EPRINTF("walk ast_block_expr_t\n");
  switch (block_expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", block_expr->type);
  case EXPR:
    walk_ast_expr_t(block_expr->value.expr, sym_tab, id);
    break;
  case DECL: {
    ++(*id);
    ast_term_decl_t *term_decl = block_expr->value.decl;

    if (get_symbol(sym_tab, term_decl->decl_type) == NULL) {
      REPORT_ERROR("Error: %s does not name a type\n", term_decl->decl_type);
    }

    symbol_t *term_sym =
        create_symbol_t(term_decl->decl_name, SYM_TY_TERM, term_decl, *id);
    if (term_decl->value) {
      char const *term_sym_value_type =
          get_ast_expr_type(term_sym->value.term_val->value, sym_tab);

      if (strcmp(term_sym_value_type, term_decl->decl_type)) {
        REPORT_ERROR(RED "type mismatch:" GRN "can not assign %s to %s\n" RESET,
                     term_sym_value_type, term_decl->decl_type);
        exit(1);
      }

      walk_ast_expr_t(term_decl->value, sym_tab, id);
      GEN_INSTRUCTIONS("\tPUSH_MEM $%d\n", *id);
    }
    insert_symbol(sym_tab, term_sym);
    break;
  }
  case ASSIGN:
    ++(*id);
    walk_ast_assignment_t(block_expr->value.assign, sym_tab, id);
    break;
  }
}
