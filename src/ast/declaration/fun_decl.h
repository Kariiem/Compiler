#ifndef __AST_NODE_FUN_DECL__
#define __AST_NODE_FUN_DECL__
#include "../expression/block.h"
#include "fun_param.h"
typedef struct ast_fundecl_t ast_fundecl_t;
struct ast_fundecl_t {
  char const *fun_name;
  vtype(ast_fun_param_t *) param_list;
  char const *return_type_name;
  ast_block_t *body;
};
#endif // __AST_NODE_FUN_DECL__