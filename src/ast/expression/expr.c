#include "expr.h"
#include "../../symbol.h"
#include "../utils.h"
#include "bin_expr.h"
#include "block.h"
#include "block_expr.h"
#include "do.h"
#include "funcall.h"
#include "if.h"
#include "switch.h"
#include "while.h"
// #include <gmp.h>

ast_expr_t *create_ast_expr_t(int const type, void *value) {
  ast_expr_t *expr = calloc(1, sizeof(ast_expr_t));
  expr->type = type;

  switch (type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d\n", type);
    break;
  case EXPR_IDENTIFIER:
    expr->value.identifier = value;
    break;
  case EXPR_INTEGER:
    // TODO("EXPR_INTEGER UNIMPLEMENTED");
  case EXPR_INT:
    // TODO("EXPR_INT UNIMPLEMENTED");
  case EXPR_REAL:
    // TODO("EXPR_REAL UNIMPLEMENTED");
  case EXPR_DOUBLE:
    // TODO("EXPR_DOUBLE UNIMPLEMENTED");
  case EXPR_BOOL:
    // TODO("EXPR_BOOL UNIMPLEMENTED");
  case EXPR_STRING:
    expr->value.string = value;
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    expr->value.binary_expr = value;
    break;
  case EXPR_NOT:
    expr->value.not_ = value;
    break;
  // function call
  case EXPR_FUNCALL:
    expr->value.funcall = value;
    break;
  // compound expressions
  case EXPR_IF:
    expr->value.if_ = value;
    break;
  case EXPR_FOR:
    expr->value.for_ = value;
    break;
  case EXPR_WHILE:
  case EXPR_UNTIL:
    expr->value.while_ = value;
    break;
  case EXPR_DO:
    expr->value.do_ = value;
    break;
  case EXPR_SWITCH:
    expr->value.switch_ = value;
    break;
  }
  return expr;
}

void free_ast_expr_t(ast_expr_t **expr_ptr) {
  DEBUG_EPRINTF("free ast_expr_t\n");
  ast_expr_t *expr = *expr_ptr;
  if(expr==NULL) return;
  // DEBUG_ASSERT(expr, "expr is NULL\n");

  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d\n", expr->type);

  case EXPR_IDENTIFIER:
    FREE_ATOM(expr->value.identifier);
    break;
  case EXPR_INTEGER:
    // mpz_clear(expr->value.arb_integer);
  case EXPR_INT:
  case EXPR_REAL:
    // mpfr_clear(expr->value.real);
  case EXPR_DOUBLE:
  case EXPR_BOOL:
  case EXPR_STRING:
    FREE_ATOM(expr->value.string);
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    free_ast_bin_expr_t(&expr->value.binary_expr);
    break;
  case EXPR_NOT:
    free_ast_expr_t(&expr->value.not_);
    break;
  // function call
  case EXPR_FUNCALL:
    free_ast_funcall_t(&expr->value.funcall);
    break;
  // compound expressions
  case EXPR_IF:
    free_ast_if_t(&expr->value.if_);
    break;
  case EXPR_FOR:
    free_ast_for_t(&expr->value.for_);
    break;
  case EXPR_WHILE:
  case EXPR_UNTIL:
    free_ast_while_t(&expr->value.while_);
    break;
  case EXPR_DO:
    free_ast_do_t(&expr->value.do_);
    break;
  case EXPR_SWITCH:
    free_ast_switch_t(&expr->value.switch_);
    break;
  }
  free(expr);
  *expr_ptr = NULL;
}

void print_ast_expr_t(ast_expr_t const *expr, int indent) {
  INDENT(indent);
  printf("ast_expr_t\n");
  INDENT(indent + 1);
  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);

  case EXPR_IDENTIFIER:
    printf("identifier: %s\n", expr->value.identifier);
    break;
  case EXPR_INTEGER:
    printf("integer: %s\n", expr->value.string);
    break;
  case EXPR_INT:
    printf("int: %s\n", expr->value.string);
    break;
  case EXPR_REAL:
    printf("real: %s\n", expr->value.string);
    break;
  case EXPR_DOUBLE:
    printf("double: %s\n", expr->value.string);
    break;
  case EXPR_BOOL:
    printf("bool: %s\n", expr->value.string);
    break;
  case EXPR_STRING:
    printf("string: %s\n", expr->value.string);
    break;
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ:
    print_ast_bin_expr_t(expr->value.binary_expr, indent + 1);
    break;
  case EXPR_NOT:
    print_ast_expr_t(expr->value.not_, indent);
    break;
  // function call
  case EXPR_FUNCALL:
    print_ast_funcall_t(expr->value.funcall, indent);
    break;
  // compound expressions
  case EXPR_IF:
    print_ast_if_t(expr->value.if_, indent);
    break;
  case EXPR_FOR:
    print_ast_for_t(expr->value.for_, indent);
    break;
  case EXPR_WHILE:
    print_ast_while_t(expr->value.while_, indent);
    break;
  case EXPR_UNTIL:
    print_ast_while_t(expr->value.while_, indent);
    break;
  case EXPR_DO:
    print_ast_do_t(expr->value.do_, indent);
    break;
  case EXPR_SWITCH:
    print_ast_switch_t(expr->value.switch_, indent);
    break;
  }
}

void walk_ast_expr_t(ast_expr_t const *expr,  int *id) {
  DEBUG_EPRINTF("walk ast_expr_t\n");
  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);

  case EXPR_IDENTIFIER: {
    if(is_symbol_in_scope(global_symbol_table, expr->value.identifier)){
      printf(BLU"symbol %s found in the top symbol table\n"RESET, expr->value.identifier);
    }
    symbol_t *sym = get_symbol(global_symbol_table, expr->value.identifier);
    if (sym == NULL || sym->type != SYM_TY_TERM) {
      REPORT_ERROR("Symbol %s not found\n", expr->value.identifier);
      exit(1);
    }

    GEN_INSTRUCTIONS("\tLOAD $%d\n", sym->id);
    break;
  }
  case EXPR_INTEGER:
  case EXPR_INT:
  case EXPR_REAL:
  case EXPR_DOUBLE:
  case EXPR_BOOL:
  case EXPR_STRING: {
    GEN_INSTRUCTIONS("\tPUSH %s\n", expr->value.string);
    break;
  }
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP:
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ: {
    walk_ast_bin_expr_t(expr->value.binary_expr,  id);
    break;
  }
  case EXPR_NOT: {
    char const *expr_type = get_ast_expr_type(expr->value.not_, global_symbol_table);
    if (strcmp(expr_type, "bool")) {
      REPORT_ERROR("Expected bool, got %s\n", expr_type);
      exit(1);
    }
    walk_ast_expr_t(expr->value.not_,  id);
    GEN_INSTRUCTIONS("%s\n", map_int_to_operators(expr->type));
    break;
  }
  // function call
  case EXPR_FUNCALL:
    walk_ast_funcall_t(expr->value.funcall,  id);
    break;
  // compound expressions
  case EXPR_IF: {
    ++(*id);
    walk_ast_if_t(expr->value.if_,  id);
    break;
  }
  case EXPR_FOR:
    ++(*id);
    walk_ast_for_t(expr->value.for_,  id);
    break;
  case EXPR_WHILE:
  case EXPR_UNTIL:
    ++(*id);
    walk_ast_while_t(expr->value.while_,  id);
    break;
  case EXPR_DO:
    ++(*id);
    walk_ast_do_t(expr->value.do_,  id);
    break;
  case EXPR_SWITCH:
    ++(*id);
    walk_ast_switch_t(expr->value.switch_,  id);
    break;
  }
}

char const *map_int_to_operators(int i) {
  switch (i) {
  case EXPR_ADD:
    return "ADD";
  case EXPR_SUB:
    return "SUB";
  case EXPR_MUL:
    return "MUL";
  case EXPR_DIV:
    return "DIV";
  case EXPR_MOD:
    return "MOD";
  case EXPR_EXP:
    return "EXP";
  case EXPR_AND:
    return "AND";
  case EXPR_OR:
    return "OR";
  case EXPR_LT:
    return "LT";
  case EXPR_GT:
    return "GT";
  case EXPR_LEQ:
    return "LEQ";
  case EXPR_GEQ:
    return "GEQ";
  case EXPR_EQ:
    return "EQ";
  case EXPR_NEQ:
    return "NEQ";
  case EXPR_NOT:
    return "NOT";
  }
  return NULL;
}

char const *get_ast_expr_type(ast_expr_t *expr, symbol_table_t *sym_tab) {
  if (expr == NULL) {

    REPORT_ERROR(RED
                 "The last statement in a block must be an expression\n" RESET);
    exit(1);
  }
  switch (expr->type) {
  default:
    DEBUG_ASSERT(false, "Unkown type %d", expr->type);
  case EXPR_IDENTIFIER: {
    symbol_t *sym = get_symbol(sym_tab, expr->value.identifier);
    if (sym == NULL ) {
      REPORT_ERROR("Error: Symbol %s not found\n", expr->value.identifier);
      exit(1);
    }
    if (sym->type != SYM_TY_TERM){
      REPORT_ERROR("Error: Cannot Assign a non-term %s not found\n", expr->value.identifier);
      exit(1);
    }
    printf("%s has type %s\n",expr->value.identifier,sym->value.term_val->decl_type);
    return sym->value.term_val->decl_type;
  }
  case EXPR_INTEGER:
  case EXPR_INT: {
    return "int";
  }
  case EXPR_REAL:
  case EXPR_DOUBLE: {
    return "double";
  }
  case EXPR_BOOL: {
    return "bool";
  }
  case EXPR_STRING: {
    return "string";
  }
  // binary expressions
  case EXPR_ADD:
  case EXPR_SUB:
  case EXPR_MUL:
  case EXPR_DIV:
  case EXPR_MOD:
  case EXPR_EXP: {
    return get_ast_expr_type(expr->value.binary_expr->left, sym_tab);
  }
  case EXPR_AND:
  case EXPR_OR:
  case EXPR_LT:
  case EXPR_GT:
  case EXPR_LEQ:
  case EXPR_GEQ:
  case EXPR_EQ:
  case EXPR_NEQ: {
    return "bool";
  }

  case EXPR_NOT: {
    return "bool";
  }

  // function call
  case EXPR_FUNCALL: {
    symbol_t *function_sym = get_symbol(sym_tab, expr->value.funcall->fun_name);
    return function_sym->value.func_val->return_type_name;
  }
  // compound expressions
  case EXPR_IF: {
    ast_expr_t *last_expr = get_last_block_expr(expr->value.if_->then_branch);
    return get_ast_expr_type(last_expr, sym_tab);
  }
  case EXPR_FOR: {
    ast_expr_t *last_expr = get_last_block_expr(expr->value.for_->body);
    return get_ast_expr_type(last_expr, sym_tab);
  }
  case EXPR_WHILE:
  case EXPR_UNTIL: {
    ast_expr_t *last_expr = get_last_block_expr(expr->value.while_->body);
    return get_ast_expr_type(last_expr, sym_tab);
  }
  case EXPR_DO: {
    ast_expr_t *last_expr = get_last_block_expr(expr->value.do_->body);
    return get_ast_expr_type(last_expr, sym_tab);
  }
  case EXPR_SWITCH: {
    ast_expr_t *last_expr =
        get_last_block_expr(expr->value.switch_->cases[0]->body);
    return get_ast_expr_type(last_expr, sym_tab);
  }
  }
}