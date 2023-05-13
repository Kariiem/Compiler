#ifndef __AST_NODE_CONSTRUCTOR__
#define __AST_NODE_CONSTRUCTOR__

#include "record.h"
#include <stdbool.h>

typedef struct ast_constructors_t ast_constructors_t;

struct ast_constructors_t {
  // a name is sufficient to represent an enum value
  char const *con_name;
  vtype(ast_record_field_t *) fields; // ignore it now, maybe in the future work
};

ast_constructors_t *create_ast_constructors_t(char const *con_name,
                                              vtype(ast_record_field_t *)
                                                  fields);
void free_ast_constructors_t(ast_constructors_t **con_ptr);

#endif // __AST_NODE_CONSTRUCTOR__