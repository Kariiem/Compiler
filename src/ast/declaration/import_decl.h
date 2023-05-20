#ifndef __AST_NODE_IMPORT_DECL__
#define __AST_NODE_IMPORT_DECL__

typedef struct ast_import_decl_t ast_import_decl_t;
struct ast_import_decl_t {
  char const *import_name;
};

ast_import_decl_t *create_ast_import_decl_t(char const *import_name);
void free_ast_import_decl_t(ast_import_decl_t **import_ptr);
void print_ast_import_decl_t(ast_import_decl_t const *import, int indent);
#endif // __AST_NODE_IMPORT_DECL__