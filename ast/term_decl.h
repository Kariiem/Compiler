#ifndef __AST_NODE_TERM_DECL__
#define __AST_NODE_TERM_DECL__

#include "expr.h"

typedef struct ast_term_decl_t ast_term_decl_t;
struct ast_term_decl_t {
  enum { VAR, VAL } decl_qualifier;
  char const *decl_name;
  char const *dev_type;
  ast_expr_t * value; //nullable: equals null when a declaration is not initialized
};
#endif // __AST_NODE_TERM_DECL__