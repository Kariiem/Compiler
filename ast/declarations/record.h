#ifndef __AST_NODE_RECORD__
#define __AST_NODE_RECORD__

#include "../datastructres/cvector.h"

typedef struct ast_record_t ast_record_t;
typedef struct ast_record_field_t ast_record_field_t;

struct ast_record_t {
  cvector_vector_type(ast_record_field_t *) fields;
};

struct ast_record_field_t {
  char const *field_name;
  char const *field_type;
};

#endif // __AST_NODE_RECORD__