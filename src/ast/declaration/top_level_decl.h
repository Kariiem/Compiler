#ifndef __AST_NODE_TOP_LEVEL_DECL__
#define __AST_NODE_TOP_LEVEL_DECL__
#include "fun_decl.h"
#include "import_decl.h"
#include "term_decl.h"
#include "type_decl.h"

typedef struct ast_top_level_decl_t ast_top_level_decl_t;
struct ast_top_level_decl_t {
  enum { DECL_IMPORT, DECL_TYPE, DECL_TERM, DECL_FUN } type;
  union {
    ast_import_decl_t *import;
    ast_type_decl_t *type_name;
    ast_term_decl_t *term;
    ast_fundecl_t *fun;
  } value;
};

ast_top_level_decl_t *create_ast_top_level_decl_t(int type, void *value);
void free_ast_top_level_decl_t(ast_top_level_decl_t **top_level_decl_ptr);
#endif // __AST_NODE_TOP_LEVEL_DECL__