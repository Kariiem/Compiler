#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "parser.tab.h"
#include "scanner.h"

int main() {
  yyscan_t scanner;
  yylex_init(&scanner);
  yylex_destroy(scanner);
  //TODO("this is a todo");
  return 0;
}
