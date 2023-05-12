// This is Mostafa Kamal's idea
#ifndef __PARSR_INVOKER__
#define __PARSR_INVOKER__

#include "source.h"
#include <stdbool.h>

typedef struct ParserInvoker ParserInvoker;
struct ParserInvoker {
  char const *filename;
  ast_source_t* source;
};

bool is_valid_filename(char const*filename);

ParserInvoker * create_PraserInvoker(char const* filename);
 
#endif // __PARSR_INVOKER__