#ifndef __AST_NODE_FUNCALL__
#define __AST_NODE_FUNCALL__
#include "../datastructres/cvector.h"

typedef struct ast_expr_t ast_expr_t;
typedef struct ast_fun_call_t ast_fun_call_t;

struct ast_funcall_t {
  char const *fun_name;
  cvector_vector_type(ast_expr_t *) args;
};

#endif // __AST_NODE_FUNCALL__