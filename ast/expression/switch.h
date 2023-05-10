#ifndef __AST_NODE_SWITCH__
#define __AST_NODE_SWITCH__

#include "../datastructures/cvector.h"
#include "block.h"
#include "case.h"
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_switch_t ast_switch_t;

struct ast_switch_t {
  ast_expr_t *enum_expr;
  cvector_vector_type(ast_case_t *) cases; // null mean empty switch
};

#endif // __AST_NODE_SWITCH__