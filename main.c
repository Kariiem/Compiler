#include "comp.h"
#include "src/ast/ast.h"
#include "src/ast/datastructures/cvector.h"
#include "src/ast/declaration/fun_decl.h"
#include "src/ast/declaration/fun_param.h"
#include "src/ast/declaration/type_decl.h"
#include "src/ast/expression/block_expr.h"
#include "src/ast/source.h"
#include "src/symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if !YYDEBUG
static int yydebug;
#endif

FILE *instructions;
FILE *functions;
FILE *types;
FILE *symbol_table;
symbol_table_t *global_symbol_table;
symbol_table_t *child_scope;

#define NUM_BUILTIN_TYPES 5
#define NUM_BUILTIN_FUNCS 2

void insert_builtin_types(symbol_table_t *global_symbol_table) {
  char *builtin_types[] = {"unit", "int", "double", "bool", "string"};
  for (int i = 0; i < NUM_BUILTIN_TYPES; i++) {
    symbol_t *type_sym =
        create_symbol_t(builtin_types[i], SYM_TY_TYPE, NULL, i);
    insert_symbol(global_symbol_table, type_sym);
  }
}

void free_builtin_types(symbol_table_t *global_symbol_table) {
  char *builtin_types[] = {"int", "float", "bool", "string", "unit"};
  for (int i = 0; i < NUM_BUILTIN_TYPES; i++) {
    symbol_t *type_sym = get_symbol(global_symbol_table, builtin_types[i]);
    free_symbol_t(&type_sym);
  }
}

void insert_builtin_functions(symbol_table_t *global_symbol_table) {
  char *builtin_fun_names[] = {"int_to_double", "double_to_int"};
  vtype(ast_fun_param_t *) param_lists_i2d = NULL;
  vtype(ast_fun_param_t *) param_lists_d2i = NULL;
  cvector_push_back(param_lists_i2d,
                    create_ast_fun_param_t(PARAM_VAL, "x", "int"));
  cvector_push_back(param_lists_d2i,
                    create_ast_fun_param_t(PARAM_VAL, "x", "double"));

  ast_fundecl_t *builtin_funs[2] = {
      create_ast_fundecl_t(builtin_fun_names[0], param_lists_i2d, "double", NULL),
      create_ast_fundecl_t(builtin_fun_names[1], param_lists_d2i, "int",    NULL)
  };


  symbol_t *fun_sym =
      create_symbol_t(builtin_fun_names[0], SYM_TY_FUNC, builtin_funs[0], 0);
  insert_symbol(global_symbol_table, fun_sym);
  fun_sym =
      create_symbol_t(builtin_fun_names[1], SYM_TY_FUNC, builtin_funs[1], 1);
  insert_symbol(global_symbol_table, fun_sym);
}

void free_builtin_functions(symbol_table_t *global_symbol_table) {
  char *builtin_funs[] = {"int_to_float", "float_to_int"};

  for (int i = 0; i < NUM_BUILTIN_FUNCS; i++) {
    symbol_t *fun_sym = get_symbol(global_symbol_table, builtin_funs[i]);
    free_symbol_t(&fun_sym);
  }
}

int main(int argc, char *argv[]) {
  yyscan_t scanner;
  yylex_init(&scanner);
  ast_source_t *source_module;
  global_symbol_table = create_symbol_table_t();
  child_scope = global_symbol_table;
  /*insert the builtin types into the symbol table*/
  insert_builtin_types(global_symbol_table);
  /*insert the builtin functions into the symbol table*/
  insert_builtin_functions(global_symbol_table);

  FILE *fptr;

  --argc, ++argv;
  if (argc > 0) {
    fptr = fopen(argv[0], "r");
    yyset_in(fptr, scanner);
  } else
    yyset_in(stdin, scanner);

  do {
    switch (getopt(argc, argv, "sp")) {
    case -1:
      break;
    case 's':
      yyset_debug(1, scanner);
      continue;
    case 'p':
      yydebug = 1;
      continue;
    default:
      exit(1);
    }
    break;
  } while (1);

  int parser_exit_status = yyparse(scanner, &source_module);
  if (parser_exit_status != 0) {
    fprintf(stderr, "");
    // free_symbol_table_t(&global_symbol_table);
    yylex_destroy(scanner);
    exit(1);
  }
  // print_ast_source_t(source_module, 0);
  instructions = fopen("codegen/instructions.txt", "w");
  functions = fopen("codegen/functions.txt", "w");
  types = fopen("codegen/types.txt", "w");
  symbol_table = fopen("codegen/symbol_table.txt", "w");
  int intial_symbol_id = NUM_BUILTIN_TYPES + 1;

  walk_ast_source_t(source_module, &intial_symbol_id);
  pop_scope(&global_symbol_table);
  // free_symbol_table_t(&global_symbol_table);
  yylex_destroy(scanner);
  return 0;
}
