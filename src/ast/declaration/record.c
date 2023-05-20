#include "record.h"
#include "../utils.h"
#include <stdlib.h>
ast_record_field_t *create_ast_record_field_t(char const *field_name,
                                              char const *field_type) {
  ast_record_field_t *record_field = calloc(1, sizeof(ast_record_field_t));
  record_field->field_type = field_type;
  record_field->field_name = field_name;
  return record_field;
}
void free_ast_record_field_t(ast_record_field_t **record_field_ptr) {
  DEBUG_EPRINTF("free ast_record_field_t\n");
  ast_record_field_t *record_field = *record_field_ptr;
  DEBUG_ASSERT(record_field, "record_field is NULL");
  FREE_ATOM(record_field->field_name);
  FREE_ATOM(record_field->field_type);
  free(record_field);
  *record_field_ptr = NULL;
}