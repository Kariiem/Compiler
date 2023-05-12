#ifndef __AST_NODE_IMPORT_DECL__
#define __AST_NODE_IMPORT_DECL__

typedef struct ast_import_decl_t ast_import_decl_t;
struct ast_import_decl_t {
  char const * module_name;
};
#endif // __AST_NODE_IMPORT_DECL__