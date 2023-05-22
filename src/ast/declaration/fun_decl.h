#ifndef __AST_NODE_FUN_DECL__
#define __AST_NODE_FUN_DECL__
#include "../expression/block.h"
#include "fun_param.h"

typedef struct ast_fundecl_t ast_fundecl_t;
typedef struct symbol_table_t symbol_table_t;
struct ast_fundecl_t {
  char const *fun_name;
  vtype(ast_fun_param_t *) param_list;
  char const *return_type_name;
  ast_block_t *body;
};

ast_fundecl_t *create_ast_fundecl_t(char const *fun_name,
                                    vtype(ast_fun_param_t *) param_list,
                                    char const *return_type_name,
                                    ast_block_t *body);
void free_ast_fundecl_t(ast_fundecl_t ** fundecl_ptr);
void print_ast_fundecl_t(ast_fundecl_t const *fundecl, int indent);
void walk_ast_fundecl_t(ast_fundecl_t const *fundecl, symbol_table_t *sym_tab,int* id);
#endif // __AST_NODE_FUN_DECL__