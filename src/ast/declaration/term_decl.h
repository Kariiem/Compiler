#ifndef __AST_NODE_TERM_DECL__
#define __AST_NODE_TERM_DECL__

#include "../expression/expr.h"

typedef struct ast_term_decl_t ast_term_decl_t;
struct ast_term_decl_t {
  enum { TERM_VAR, TERM_VAL } type;
  char const *decl_name;
  char const *decl_type;
  ast_expr_t *value; // null means var/val is not initialized
};

ast_term_decl_t *create_ast_term_decl_t(int type, char const *decl_name,
                                        char const *dev_type,
                                        ast_expr_t *value);
void free_ast_term_decl_t(ast_term_decl_t **term_decl_ptr);

#endif // __AST_NODE_TERM_DECL__