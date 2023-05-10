#ifndef __AST_NODE_CONSTRUCTOR__
#define __AST_NODE_CONSTRUCTOR__

#include "record.h"
typedef struct ast_constructors_t ast_constructors_t;

struct ast_constructors_t {
  // a name is sufficient to represent an enum value
  char const *constructor_name;
  ast_record_t *record; //ignore it now, maybe in the future work
};

#endif // __AST_NODE_CONSTRUCTOR__