#include "assignment.h"
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
    DEBUG_ASSERT(assignment,"assignment is NULL");
    free_ast_expr_t(&assignment->value);
    FREE_ATOM(assignment->identifier);
    free(assignment);
    *assignment_ptr = NULL;
}