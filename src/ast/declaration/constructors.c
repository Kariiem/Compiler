#include "constructors.h"
#include "../utils.h"
#include "record.h"
ast_constructors_t *create_ast_constructors_t(char const *con_name,
                                              vtype(ast_record_field_t *)
                                                  fields) {
  ast_constructors_t *con = calloc(1, sizeof(ast_constructors_t));
  con->con_name = con_name;
  con->fields = fields;
  return con;
}
void free_ast_constructors_t(ast_constructors_t **con_ptr) {
  DEBUG_EPRINTF("free ast_constructors_t");
  ast_constructors_t *con = *con_ptr;
  DEBUG_ASSERT(con, "con is NULL");
  FREE_ATOM(con->con_name);
  CVECTOR_FREE(con->fields, free_ast_record_field_t);
  free(con);
  *con_ptr = NULL;
}
