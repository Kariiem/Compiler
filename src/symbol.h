#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "ast/ast.h"
#include "ast/utils.h"

typedef struct symbol_t symbol_t;
typedef struct symbol_table_t symbol_table_t;

extern FILE *instructions;
extern FILE *functions;
extern FILE *types;
extern FILE *symbol_table;
extern symbol_table_t *global_symbol_table;
extern symbol_table_t *child_scope;

#include "bytecode.h"

// Struct of a single entry in the symbol table
struct symbol_t {
  enum {
    SYM_TY_TERM,
    SYM_TY_FUNC,
    SYM_TY_TYPE,
    SYM_TY_FUNC_PARAM,
    SYM_TY_ENUM_CONS,
  } type;
  union {
    ast_fundecl_t *func_val;
    ast_term_decl_t *term_val;
    ast_type_decl_t *type_val;
    ast_fun_param_t *func_param_val;
    ast_constructors_t *enum_cons_val;
  } value;
  char *name; // Name of the symbol
  int id;     // id of the symbol for code generation
};

// Struct of the symbol table itself
struct symbol_table_t {
  vtype(symbol_t *) entries;
  int index;
  symbol_table_t *parent;
};

// create and free , for a symbol
symbol_t *create_symbol_t(char const *name, int type, void *value, int id);
void free_symbol_t(symbol_t **symbol_ptr);

// create and free , for a symbol table
symbol_table_t *create_symbol_table_t();
void free_symbol_table_t(symbol_table_t **sym_tab_ptr);

// insert symbol into the current symbol table (scope)
void insert_symbol(symbol_table_t *head, symbol_t *symbol);
symbol_t *get_symbol(symbol_table_t *head, char const *name);
int is_symbol_in_scope(symbol_table_t *head, char const *name);

// create new local scope
void push_scope(symbol_table_t **head);
void pop_scope(symbol_table_t **head);
void print_symbol_t(symbol_t *symbol, int indent);
#endif // __SYMBOL_H__