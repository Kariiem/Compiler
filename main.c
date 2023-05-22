#include "comp.h"
#include "src/ast/ast.h"
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
FILE *call_stack;
FILE *types;


int main(int argc, char *argv[]) {
  yyscan_t scanner;
  yylex_init(&scanner);
  ast_source_t *source_module;
  symbol_table_t *global_symbol_table = create_symbol_table_t();
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

  yyparse(scanner, &source_module);

  // print_ast_source_t(source_module, 0);
  instructions = fopen("codegen/instructions.txt", "w");
  functions = fopen("codegen/functions.txt", "w");
  call_stack = fopen("codegen/call_stack.txt", "w");
  types = fopen("codegen/types.txt", "w");

  walk_ast_source_t(source_module, global_symbol_table, 0);

  free_ast_source_t(&source_module);
  free_symbol_table_t(&global_symbol_table);
  yylex_destroy(scanner);
  return 0;
}
