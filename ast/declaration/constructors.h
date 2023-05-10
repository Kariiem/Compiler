#ifndef __AST_NODE_CONSTRUCTOR__
#define __AST_NODE_CONSTRUCTOR__

#include "record.h"
typedef struct ast_constructors_t ast_constructors_t;

struct ast_constructors_t {
  // a name is sufficient to represent an enum value
  char const *constructor_name;
   cvector_vector_type(ast_record_field_t *) fields; //ignore it now, maybe in the future work
};

#endif // __AST_NODE_CONSTRUCTOR__