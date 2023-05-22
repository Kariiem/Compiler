#include "block.h"
#include "../utils.h"
#include "block_expr.h"
#include "../../symbol.h"
ast_block_t *create_ast_block_t(vtype(ast_block_expr_t *)
                                    block_expr_list) {
  ast_block_t *block = calloc(1, sizeof(ast_block_t));
  block->block_expr_list = block_expr_list;
  return block;
}

void free_ast_block_t(ast_block_t **block_ptr) {
  DEBUG_EPRINTF("free ast_block_t\n");
  ast_block_t *block = *block_ptr;
  DEBUG_ASSERT(block,"block is NULL");    
  CVECTOR_FREE(block->block_expr_list, free_ast_block_expr_t);
  free(block);
  *block_ptr = NULL;
}

void print_ast_block_t(ast_block_t const *block, int indent){
  INDENT(indent);
  printf("ast_block_t\n");
  ast_block_expr_t **it;
  cvector_for_each_in(it, block->block_expr_list) {
    print_ast_block_expr_t(*it, indent + 1);
  }
}
void walk_ast_block_t(ast_block_t const *block, symbol_table_t *sym_tab,int* id){
  DEBUG_EPRINTF("walk ast_block_t\n");
  ast_block_expr_t **it;
  cvector_for_each_in(it, block->block_expr_list) {
    walk_ast_block_expr_t(*it, sym_tab,id);
  }
}
