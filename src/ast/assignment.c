#include "assignment.h"
#include "../symbol.h"
#include "expression/expr.h"
#include "tbassert.h"
#include "utils.h"

ast_assignment_t *create_ast_assignment_t(char const *identifier,
                                          ast_expr_t *value) {
  ast_assignment_t *assignment = calloc(1, sizeof(ast_assignment_t));
  assignment->identifier = identifier;
  assignment->value = value;
  return assignment;
}

void free_ast_assignment_t(ast_assignment_t **assignment_ptr) {
  DEBUG_EPRINTF("free ast_assignment_t\n");
  ast_assignment_t *assignment = *assignment_ptr;
  DEBUG_ASSERT(assignment, "assignment is NULL");
  // assignment->value will be pointed to by the assignment->identifier
  // term, so we don't need to free it here.
  // if the term does not exist, then we would have already exited with an
  // error.
  // free_ast_expr_t(&assignment->value);
  FREE_ATOM(assignment->identifier);
  free(assignment);
  *assignment_ptr = NULL;
}

void print_ast_assignment_t(ast_assignment_t const *assignment, int indent) {
  INDENT(indent);
  printf("ast_assignment_t\n");
  INDENT(indent + 1);
  printf("identifier: %s\n", assignment->identifier);
  if (assignment->value) {
    print_ast_expr_t(assignment->value, indent + 1);
  } else {
    INDENT(indent);
    printf("value: NULL\n");
  }
}
void walk_ast_assignment_t(ast_assignment_t const *assignment,
                           symbol_table_t *sym_tab, int *id) {
  DEBUG_EPRINTF("walk ast_assignment_t\n");
  symbol_t *sym = get_symbol(sym_tab, assignment->identifier);
  if (sym == NULL) {
    REPORT_ERROR(RED "Error: Assignment to undeclared identifier\n" RESET);
    exit(1);
  }
  if (sym->type != SYM_TY_TERM) {
    REPORT_ERROR(RED "Error: Assignment to non-term identifier\n" RESET);
    exit(1);
  }
  char const *term_type = sym->value.term_val->decl_type;
  char const *expr_type = get_ast_expr_type(assignment->value, sym_tab);
  if (strcmp(term_type, expr_type) != 0) {
    REPORT_ERROR(RED "Error: Assignment to identifier with wrong type\n" RESET);
    exit(1);
  }
  if (sym->value.term_val->type == TERM_VAL) {

    if (sym->value.term_val->value == NULL) {
      sym->value.term_val->value = assignment->value;
    } else {
      REPORT_ERROR(RED "Error: Assignment to val identifier\n" RESET);
      exit(1);
    }
  } else {
    sym->value.term_val->value = assignment->value;
  }
  walk_ast_expr_t(assignment->value, sym_tab, id);
  GEN_INSTRUCTIONS("\tPUSH_MEM $%d\n", sym->id);
}