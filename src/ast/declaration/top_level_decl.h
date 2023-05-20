#ifndef __AST_NODE_TOP_LEVEL_DECL__
#define __AST_NODE_TOP_LEVEL_DECL__
#include "fun_decl.h"
#include "import_decl.h"
#include "term_decl.h"
#include "type_decl.h"
#include "../assignment.h"

typedef struct ast_top_level_decl_t ast_top_level_decl_t;
struct ast_top_level_decl_t {
  enum { DECL_IMPORT, DECL_TYPE, DECL_TERM, DECL_FUN,DECL_ASSIGN } type;
  union {
    ast_import_decl_t *import;
    ast_type_decl_t *type_name;
    ast_term_decl_t *term;
    ast_fundecl_t *fun;
    ast_assignment_t *assign;
  } value;
};

ast_top_level_decl_t *create_ast_top_level_decl_t(int type, void *value);
void free_ast_top_level_decl_t(ast_top_level_decl_t **top_level_decl_ptr);

void print_ast_top_level_decl_t(ast_top_level_decl_t const *top_level_decl,
                                int indent);
#endif // __AST_NODE_TOP_LEVEL_DECL__