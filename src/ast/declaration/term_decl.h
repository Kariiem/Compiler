#ifndef __AST_NODE_TERM_DECL__
#define __AST_NODE_TERM_DECL__

#include "../expression/expr.h"

typedef struct ast_term_decl_t ast_term_decl_t;
typedef struct symbol_table_t symbol_table_t;

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
void print_ast_term_decl_t(ast_term_decl_t const *term_decl, int indent);
void walk_ast_term_decl_t(ast_term_decl_t const *term_decl,
                          symbol_table_t *sym_tab,int id);
#endif // __AST_NODE_TERM_DECL__