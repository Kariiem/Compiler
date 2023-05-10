#ifndef __AST_NODE_TERM_DECL__
#define __AST_NODE_TERM_DECL__

#include "../expression/expr.h"

typedef struct ast_term_decl_t ast_term_decl_t;
struct ast_term_decl_t {
  enum { TERM_VAR, TERM_VAL } decl_qualifier;
  char const *decl_name;
  char const *dev_type;
  ast_expr_t *value; // null means var/val is not initialized
};
#endif // __AST_NODE_TERM_DECL__