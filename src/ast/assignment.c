#include "assignment.h"
#include "../symbol.h"
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
  free_ast_expr_t(&assignment->value);
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
                           symbol_table_t *sym_tab,int id) {
  DEBUG_EPRINTF("walk ast_assignment_t\n");
  walk_ast_expr_t(assignment->value, sym_tab,id);
}