#ifndef __AST_NODE_FUNCALL__
#define __AST_NODE_FUNCALL__
#include "../datastructures/cvector.h"
#include <stdbool.h>
typedef struct ast_expr_t ast_expr_t;
typedef struct ast_funcall_t ast_funcall_t;

struct ast_funcall_t {
  char const *fun_name;
  vtype(ast_expr_t *) args;
};
ast_funcall_t *create_ast_funcall_t(char const *fun_name,
                                    vtype(ast_expr_t *) args);
bool free_ast_funcall_t(ast_funcall_t **funcall_ptr);

#endif // __AST_NODE_FUNCALL__