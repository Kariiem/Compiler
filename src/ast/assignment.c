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
  if (assignment == NULL)
    return;
  // DEBUG_ASSERT(assignment, "assignment is NULL");
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
void walk_ast_assignment_t(ast_assignment_t const *assignment, int *id) {
  DEBUG_EPRINTF("walk ast_assignment_t\n");
  symbol_t *sym = get_symbol(global_symbol_table, assignment->identifier);
  if (sym == NULL) {
    ERROR("Error: Assignment to undeclared identifier\n");
    exit(1);
  }
  if (sym->type != SYM_TY_TERM && sym->type != SYM_TY_FUNC_PARAM) {
    ERROR("Error: Assignment to non-term identifier\n");
    exit(1);
  }
  char const *term_type = sym->value.term_val->decl_type;
  printf("term_type: %s\n", term_type);
  char const *expr_type =
      get_ast_expr_type(assignment->value, global_symbol_table);
  if (strcmp(term_type, expr_type)) {
    ERROR("Error: Assignment to identifier with wrong type\n");
    exit(1);
  }
  if (sym->value.term_val->type == TERM_VAL) {

    if (sym->value.term_val->value == NULL) {
      sym->value.term_val->value = assignment->value;
    } else {
      ERROR("Error: Assignment to val identifier\n");
      exit(1);
    }
  } else {
    sym->value.term_val->value = assignment->value;
  }
  walk_ast_expr_t(assignment->value, id);
  GEN_INSTRUCTIONS("\tSTORE $%d\n", sym->id);
}