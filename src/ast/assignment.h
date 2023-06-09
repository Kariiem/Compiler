#ifndef __AST_NODE_ASSIGNMENT__
#define __AST_NODE_ASSIGNMENT__
#include "expression/expr.h"

typedef struct ast_assignment_t ast_assignment_t;
struct ast_assignment_t {
  char const *identifier;
  ast_expr_t *value;
};

ast_assignment_t *create_ast_assignment_t(char const *identifier,
                                          ast_expr_t *value);

void free_ast_assignment_t(ast_assignment_t **assignment_ptr);
#endif // __AST_NODE_ASSIGNMENT__
