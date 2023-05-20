#ifndef __AST_NODE_RECORD__
#define __AST_NODE_RECORD__

#include "../datastructures/cvector.h"

typedef struct ast_record_field_t ast_record_field_t;

struct ast_record_field_t {
  char const *field_name;
  char const *field_type;
};

ast_record_field_t *create_ast_record_field_t(char const *field_name,
                                              char const *field_type);
void free_ast_record_field_t(ast_record_field_t **record_field_ptr);
#endif // __AST_NODE_RECORD__