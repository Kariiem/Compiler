#include "symbol.h"
#include "ast/datastructures/cvector_utils.h"
#include "ast/declaration/term_decl.h"
#include "ast/utils.h"
#include "bytecode.h"
#include <stdio.h>

// Symbol
symbol_t *create_symbol_t(char const *name, int type, void *value, int id) {
  symbol_t *symbol = (symbol_t *)calloc(1, sizeof(symbol_t));
  symbol->name = name;
  symbol->type = type;
  switch (type) {
  case SYM_TY_TERM:
    symbol->value.term_val = value;
    break;
  case SYM_TY_FUNC:
    symbol->value.func_val = value;
    break;
  case SYM_TY_TYPE:
    symbol->value.type_val = value;
    break;
  }
  symbol->id = id;
  return symbol;
}

void free_symbol_t(symbol_t **symbol_ptr) {
  DEBUG_EPRINTF("free symbol_t\n");
  symbol_t *symbol = *symbol_ptr;
  DEBUG_ASSERT(symbol, "symbol is NULL");
  // switch (symbol->type) {
  // case SYM_TY_TERM:
  //   free_ast_term_decl_t(&symbol->value.term_val);
  //   break;
  // case SYM_TY_FUNC:
  //   free_ast_fundecl_t(&symbol->value.func_val);
  //   break;
  // case SYM_TY_TYPE:
  //   free_ast_type_decl_t(&symbol->value.type_val);
  //   break;
  // case SYM_TY_FUNC_PARAM:
  //   free_ast_fun_param_t(&symbol->value.func_param_val);
  //   break;
  // case SYM_TY_ENUM_CONS:
  //   free_ast_constructors_t(&symbol->value.enum_cons_val);
  //   break;
  // }
  free(symbol);
  *symbol_ptr = NULL;
}

// Symbol table functions
symbol_table_t *create_symbol_table_t() {
  symbol_table_t *sym_tab = (symbol_table_t *)calloc(1, sizeof(symbol_table_t));
  sym_tab->entries = NULL;
  sym_tab->index = -1;
  sym_tab->parent = NULL;
  return sym_tab;
}

void free_symbol_table_t(symbol_table_t **sym_tab_ptr) {
  DEBUG_EPRINTF("free ast_fundecl_t\n");
  symbol_table_t *sym_tab = *sym_tab_ptr;
  DEBUG_ASSERT(sym_tab, "sym_tab is NULL");
  CVECTOR_FREE(sym_tab->entries, free_symbol_t);
  free(sym_tab);
  *sym_tab_ptr = NULL;
}

void insert_symbol(symbol_table_t *head, symbol_t *symbol) {
  DEBUG_ASSERT(head, "head is NULL\n");
  cvector_push_back(head->entries, symbol);
}

symbol_t *get_symbol(symbol_table_t *head, char const *name) {
  symbol_table_t *iterator = head;
  while (iterator != NULL) {
    for (int i = 0; i < cvector_size(iterator->entries); i++) {
      if (strcmp(iterator->entries[i]->name, name) == 0) {
        return iterator->entries[i];
      }
    }
    iterator = iterator->parent;
  }
  return NULL;
}
int is_symbol_in_scope(symbol_table_t *head, char const *name) {
  for (int i = 0; i < cvector_size(head->entries); i++) {
    if (strcmp(head->entries[i]->name, name) == 0) {
      return 1;
    }
  }
  return 0;
}
static int distance_top_parent(symbol_table_t **head) {
  int distance = 0;
  symbol_table_t *iterator = *head;
  while (iterator != NULL) {
    ++distance;
    iterator = iterator->parent;
  }
  return distance;
}
void push_scope(symbol_table_t **head) {
  symbol_table_t *new_scope = create_symbol_table_t();
  new_scope->parent = *head;
  *head = new_scope;
}

void pop_scope(symbol_table_t **head) {
  symbol_table_t *temp = *head;
  *head = (*head)->parent;
  int distance = distance_top_parent(head);
  for (int i = ((int)cvector_size(temp->entries)) - 1; i >= 0; --i) {
    print_symbol_t(temp->entries[i], distance);
  }
  // free_symbol_table_t(&temp);
}

void print_symbol_t(symbol_t *symbol, int indent) {
  GEN_SYMBOL_TABLE("%*s",4*indent,"");
  switch (symbol->type) {
  case SYM_TY_TERM:
    // print_ast_term_decl_t(symbol->value.term_val, 0);
    GEN_SYMBOL_TABLE("symbol name: %s, type: SYM_TY_TERM, id: %d\n",
                     symbol->name, symbol->id);
    break;
  case SYM_TY_FUNC:
    // print_ast_fundecl_t(symbol->value.func_val, 0);
    GEN_SYMBOL_TABLE("symbol name: %s, type: SYM_TY_FUNC, id: %d\n",
                     symbol->name, symbol->id);
    break;
  case SYM_TY_TYPE:
    // print_ast_type_decl_t(symbol->value.type_val, 0);
    GEN_SYMBOL_TABLE("symbol name: %s, type: SYM_TY_TYPE, id: %d\n",
                     symbol->name, symbol->id);
    break;
  }
}