#ifndef __AST_NODE_SWITCH__
#define __AST_NODE_SWITCH__

#include "../datastructures/cvector.h"
#include "block.h"
#include "case.h"
#include <stdbool.h>

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_switch_t ast_switch_t;

struct ast_switch_t {
  ast_expr_t *enum_expr;
  vtype(ast_case_t *) cases; // null mean empty switch
};
ast_switch_t *create_ast_switch_t(ast_expr_t *expr,
                                  vtype(ast_case_t *) cases);
void free_ast_switch_t(ast_switch_t **switch_ptr);
#endif // __AST_NODE_SWITCH__