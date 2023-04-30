#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "comp.h"
#if !YYDEBUG
  static int yydebug;
#endif

int main(int argc, char* argv[]) {
  yyscan_t scanner;          
  yylex_init(&scanner);
  module_t module = {0};
  do {
    switch (getopt(argc, argv, "sp")) {
      case -1: break;
      case 's': yyset_debug(1, scanner); continue;
      case 'p': yydebug = 1; continue;
      default: exit(1);
    }
    break;
  } while(1);

  yyparse(scanner,module);          
  yylex_destroy(scanner);    
  return 0;
}