#ifndef __AST_NODE_FUN_PARAM__
#define __AST_NODE_FUN_PARAM__
#include "../expression/block.h"

typedef struct ast_fun_param_t ast_fun_param_t;
struct ast_fun_param_t {
  enum { PARAM_VAL, PARAM_VAR } type;
  char const *param_name;
  char const *param_type;
};

ast_fun_param_t *create_ast_fun_param_t(int type, char const *param_name,
                                        char const *param_type);
void free_ast_fun_param_t(ast_fun_param_t **fun_param_ptr);

#endif // __AST_NODE_FUN_PARAM__