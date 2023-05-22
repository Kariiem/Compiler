#include "comp.h"
#include "src/ast/ast.h"
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

void insert_builtin_types(symbol_table_t *global_symbol_table) {
  char *builtin_types[] = {"unit", "int", "double", "bool", "string"};
  for (int i = 0; i < 5; i++) {
    symbol_t *type_sym =
        create_symbol_t(builtin_types[i], SYM_TY_TYPE, NULL, i);
    insert_symbol(global_symbol_table, type_sym);
  }
}

void free_builtin_types(symbol_table_t *global_symbol_table) {
  char *builtin_types[] = {"int", "float", "bool", "string", "unit"};
  for (int i = 0; i < 5; i++) {
    symbol_t *type_sym = get_symbol(global_symbol_table, builtin_types[i]);
    free_symbol_t(&type_sym);
  }
}

int main(int argc, char *argv[]) {
  yyscan_t scanner;
  yylex_init(&scanner);
  ast_source_t *source_module;
  symbol_table_t *global_symbol_table = create_symbol_table_t();
  insert_builtin_types(global_symbol_table);
  /*insert the builtin types into the symbol table*/
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
    free_ast_source_t(&source_module);
    free_symbol_table_t(&global_symbol_table);
    yylex_destroy(scanner);
    exit(1);
  }
  // print_ast_source_t(source_module, 0);
  instructions = fopen("codegen/instructions.txt", "w");
  functions = fopen("codegen/functions.txt", "w");
  types = fopen("codegen/types.txt", "w");
  int intial_memory_address = 0;

  walk_ast_source_t(source_module, global_symbol_table, &intial_memory_address);
  free_ast_source_t(&source_module);
  free_symbol_table_t(&global_symbol_table);
  yylex_destroy(scanner);
  return 0;
}
