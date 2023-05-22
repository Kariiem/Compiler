#ifndef __AST_NODE_IMPORT_DECL__
#define __AST_NODE_IMPORT_DECL__

typedef struct ast_import_decl_t ast_import_decl_t;
typedef struct symbol_table_t symbol_table_t;

struct ast_import_decl_t {
  char const *import_name;
};

ast_import_decl_t *create_ast_import_decl_t(char const *import_name);
void free_ast_import_decl_t(ast_import_decl_t **import_ptr);
void print_ast_import_decl_t(ast_import_decl_t const *import, int indent);
void walk_ast_import_decl_t(ast_import_decl_t const *import, symbol_table_t *sym_tab);
#endif // __AST_NODE_IMPORT_DECL__