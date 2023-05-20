#include "symbol.h"
#include <stdio.h>
#include "ast/utils.h"
// Symbol

symbol_t *create_symbol_t(char *name, int type, void *value, int line_num) {
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
  symbol->line_num = line_num;
  return symbol;
}

void free_symbol_t(symbol_t *symbol) {
  switch (symbol->type) {
  case SYM_TY_TERM:
    free_ast_term_decl_t(&symbol->value.term_val);
    break;
  case SYM_TY_FUNC:
    free_ast_fundecl_t(&symbol->value.func_val);
    break;
  case SYM_TY_TYPE:
    free_ast_type_decl_t(&symbol->value.type_val);
    break;
  }
  free(symbol);
}

// Symbol table functions
sym_tab_t *create_sym_tab_t() {
  sym_tab_t *sym_tab = (sym_tab_t *)calloc(1, sizeof(sym_tab_t));
  sym_tab->entries = NULL;
  sym_tab->index = -1;
  sym_tab->parent = NULL;
  return sym_tab;
}

void free_sym_tab_t(sym_tab_t *sym_tab) {
  DEBUG_EPRINTF("free ast_fundecl_t\n");
  CVECTOR_FREE(sym_tab->entries, free_symbol_t);
  free(sym_tab);
}

void insert_symbol(sym_tab_t *head, int type, void *val, char *name,
                   int line_num) {
  if (get_symbol(head, name) != NULL) {
    fprintf(stderr, "Error: line %d, Symbol %s already exists in this scope\n",
            line_num, name);
    exit(1);
  }
  symbol_t *symbol = create_symbol_t(name, type, val, line_num);
  cvector_push_back(head->entries, symbol);
}

symbol_t *get_symbol(sym_tab_t *head, char *name) {
  sym_tab_t *iterator = head;
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

void push_scope(sym_tab_t **head) {
  sym_tab_t *new_scope = create_sym_tab_t();
  new_scope->parent = *head;
  *head = new_scope;
}

void pop_scope(sym_tab_t **head) {
  sym_tab_t *temp = *head;
  *head = (*head)->parent;
  free_sym_tab_t(temp);
}