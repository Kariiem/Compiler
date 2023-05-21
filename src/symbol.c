#include "symbol.h"
#include <stdio.h>
// Symbol

symbol_t *create_symbol_t(char *name, int type, void *value, int id) {
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
  case SYM_TY_FUNC_PARAM:
    symbol->value.func_param_val = value;
    break;
  case SYM_TY_ENUM_CONS:
    symbol->value.enum_cons_val = value;
    break;
  }
  symbol->id = id;
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
  case SYM_TY_FUNC_PARAM:
    free_ast_fun_param_t(&symbol->value.func_param_val);
    break;
  case SYM_TY_ENUM_CONS:
    free_ast_constructors_t(&symbol->value.enum_cons_val);
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
                   int id) {
  if (get_symbol(head, name) != NULL) {
    fprintf(stderr, "Error: line %d, Symbol %s already exists in this scope\n",
            id, name);
    exit(1);
  }
  symbol_t *symbol = create_symbol_t(name, type, val, id);
  cvector_push_back(head->entries, symbol);
}

symbol_t *get_symbol(sym_tab_t *head, const char *name) {
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

sym_tab_t * push_scope(sym_tab_t const * head) {
  sym_tab_t *new_scope = create_sym_tab_t();
  new_scope->parent = head;
  return new_scope;
}

sym_tab_t * pop_scope(sym_tab_t const *head) {
  sym_tab_t *parent = head->parent;
  free_sym_tab_t(head);
  return parent;
}



// Define a function that will traverse the AST with inorder traversal
// The function will take two arguments
// The arguemnts are the root of the AST (ast_source_t *) and the symbol table which is initially empty (sym_tab_t *)
// The function will open a file and create the assembly code for the program in the file
// It will create a symbol entry for each type declaration, function declaration and variable declaration node in the AST
// For each function call node, it will check if the function is defined in the symbol table
// If the function is not defined, it will print an error message and exit
// If the function is defined, it will check if the number of arguments passed to the function is equal to the number of parameters in the function declaration
// If the number of arguments is not equal to the number of parameters, it will print an error message and exit
// If the number of arguments is equal to the number of parameters, it will check if the type of each argument is equal to the type of the corresponding parameter
// If the type of any argument is not equal to the type of the corresponding parameter, it will print an error message and exit
// If the type of each argument is equal to the type of the corresponding parameter, it will create assembly code for the function call
// For each variable declaration node, it will check if the variable is already defined in the symbol table
// If the variable is already defined, it will print an error message and exit
// If the variable is not defined, it will create a new symbol entry for the variable in the symbol table
// For each variable reference node, it will check if the variable is defined in the symbol table
// If the variable is not defined, it will print an error message and exit
// If the variable is defined, it will check if the type of the variable is equal to the type of the expression
// If the type of the variable is not equal to the type of the expression, it will print an error message and exit
// If the type of the variable is equal to the type of the expression, it will create a new assembly code for the variable reference
// For each type declaration node, it will check if the type is already defined in the symbol table
// If the type is already defined, it will print an error message and exit
// If the type is not defined, it will create a new symbol entry for the type in the symbol table
// For each type reference node, it will check if the type is defined in the symbol table
// If the type is not defined, it will print an error message and exit
// If the type is defined, it will create a new assembly code for the type reference
// For each function declaration node, it will check if the function is already defined in the symbol table
// If the function is already defined, it will print an error message and exit
// If the function is not defined, it will create a new symbol entry for the function in the symbol table and create assembly code for the function declaration


void traverse_ast(ast_source_t *root, sym_tab_t *sym_tab) {
  if (root == NULL) {
    return;
  }

  int id = 0;
  // ast_source_t *root contains decl_list vtype of ast_top_level_decl_t *

  for (int i = 0; i < cvector_size(root->decl_list); i++) {
    ast_top_level_decl_t *decl = root->decl_list[i];
    switch (decl->type) {
    case DECL_FUN:
      {
        ast_fundecl_t *fundecl = decl->value.fun;
        if (get_symbol(sym_tab, fundecl->fun_name) != NULL) {
          fprintf(stderr, "Error: Function %s already exists in this scope\n",
                  , fundecl->name);
          exit(1);
        }
        id++;
        symbol_t *symbol = create_symbol_t(fundecl->fun_name, SYM_TY_FUNC, fundecl, id);
        cvector_push_back(sym_tab->entries, symbol);
        break;
      }
    case DECL_TYPE:
      {
        ast_type_decl_t *type_decl = decl->value.type_decl;
        if (get_symbol(sym_tab, type_decl->name) != NULL) {
          fprintf(stderr, "Error: line %d, Type %s already exists in this scope\n",
                  type_decl->line_num, type_decl->name);
          exit(1);
        }
        symbol_t *symbol = create_symbol_t(type_decl->name, SYM_TY_TYPE, type_decl, type_decl->line_num);
        cvector_push_back(sym_tab->entries, symbol);
        break;
      }
    case DECL_TERM:
      {
        ast_term_decl_t *term_decl = decl->value.term_decl;
        if (get_symbol(sym_tab, term_decl->name) != NULL) {
          fprintf(stderr, "Error: line %d, Variable %s already exists in this scope\n",
                  term_decl->line_num, term_decl->name);
          exit(1);
        }
        symbol_t *symbol = create_symbol_t(term_decl->name, SYM_TY_TERM, term_decl, term_decl->line_num);
        cvector_push_back(sym_tab->entries, symbol);
        break;
      }
    case DECL_IMPORT:
    break;
    case DECL_ASSIGN:
    break;
    default:
    DEBUG_ASSERT(false, "Unkonwn decl type %d\n", decl->type);
    break;
    }
  }


}








void traverse_ast_func_decl(ast_fundecl_t* func_decl, sym_tab_t *parent, int* id )
{
  sym_tab_t *sym_tab = push_scope(parent);

  // add parameters to symbol table
  for (int i = 0; i < cvector_size(func_decl->param_list); i++) {
    ast_fun_param_t *param = func_decl->param_list[i];
    if (get_symbol(sym_tab, param->param_name) != NULL) {
      fprintf(stderr, "Error: Variable %s already defined in the list of params\n",
              param->param_name);
      exit(1);
    }
    *id = *id + 1;
    symbol_t *symbol = create_symbol_t(param->param_name, SYM_TY_FUNC_PARAM, param, *id);
    cvector_push_back(sym_tab->entries, symbol);
  }

  //iterate through the body of the function (type ast_block_t*)
  for (int i = 0; i < cvector_size(func_decl->body->block_expr_list); i++) {
    ast_block_expr_t *stmt = func_decl->body->block_expr_list[i];
    switch (stmt->type) {
    case ASSIGN:
      {
        ast_assignment_t *assign = stmt->value.assign;
        symbol_t *symbol = get_symbol(sym_tab, assign->identifier);
        if (symbol == NULL || symbol->type != SYM_TY_TERM) {
          fprintf(stderr, "Error: Variable %s is not present in this scope\n",
                  assign->identifier);
          exit(1);
        }
        while (assign->value->type == EXPR_IDENTIFIER ) {
          
        }
        symbol->value.term_val->value = assign->value;
        break;
      }
  }

}


}
