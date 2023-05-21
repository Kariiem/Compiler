#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "ast/ast.h"
#include "ast/utils.h"


typedef struct symbol_t symbol_t;
typedef struct sym_tab_t sym_tab_t;

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
  char *name;   // Name of the symbol
  int id; // id of the symbol for code generation
};

// Struct of the symbol table itself
struct sym_tab_t {
  vtype(symbol_t *) entries;
  int index;
  sym_tab_t *parent;
};

// create and free , for a symbol
symbol_t *create_symbol_t(char *name, int type, void *value, int id);
void free_symbol_t(symbol_t *symbol);

// create and free , for a symbol table
sym_tab_t *create_sym_tab_t();
void free_sym_tab_t(sym_tab_t *sym_tab);

// insert symbol into the current symbol table (scope)
void insert_symbol(sym_tab_t *head, int type, void *val, char *name,
                   int id);
symbol_t *get_symbol(sym_tab_t *head, const char *name);

// create new local scope
sym_tab_t * push_scope(sym_tab_t const * head);
sym_tab_t * pop_scope(sym_tab_t const *head);

#endif // __SYMBOL_H__