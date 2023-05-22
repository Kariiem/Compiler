#include "comp.h"
#include "src/ast/ast.h"
#include "src/ast/source.h"
#include "src/symbol.h"
#include "src/symbol.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#if !YYDEBUG
static int yydebug;
#endif


int main(int argc, char *argv[]) {
  yyscan_t scanner;
  yylex_init(&scanner);
  ast_source_t *source_module;
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
  yylex_destroy(scanner);

  print_ast_source_t(source_module, 0);
  free_ast_source_t(&source_module);

  return 0;
}
