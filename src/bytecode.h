#ifndef __BYTECODE_GEN_H__
#define __BYTECODE_GEN_H__

#include <stdio.h>
typedef struct {
  enum {
    OP_CODE_LABEL,
    OP_CODE_FUNCTION,
    OP_CODE_PUSH,
    OP_CODE_POP,
    OP_CODE_ADD,
    OP_CODE_MUL,
    OP_CODE_SUB,
    OP_CODE_DIV,
    OP_CODE_MOD,
    OP_CODE_NEG,
    OP_CODE_NOT,
    OP_CODE_AND,
    OP_CODE_OR,
    OP_CODE_EQ,
    OP_CODE_NEQ,
    OP_CODE_GT,
    OP_CODE_LT,
    OP_CODE_GTE,
    OP_CODE_LTE,
    OP_CODE_JMP,
    OP_CODE_JZ,
    OP_CODE_JNZ,
    OP_CODE_CALL,
    OP_CODE_RET,
    OP_CODE_EXIT,
  } type;
  int unique_id;
  char *anottation;
} Bytecode;

#define GEN_INSTRUCTIONS(str)                                                  \
  do {                                                                         \
    fprintf(instructions, "%s\n", str);                                        \
  } while (0)
#define GEN_FUNCTIONS(str)                                                     \
  do {                                                                         \
    fprintf(functions, "%s\n", str);                                           \
  } while (0)
#define GEN_CALL_STACK(str)                                                    \
  do {                                                                         \
    fprintf(call_stack, "%s\n", str);                                          \
  } while (0)
#define GEN_TYPES(str)                                                         \
  do {                                                                         \
    fprintf(types, "%s\n", str);                                               \
  } while (0)

#endif // __BYTECODE_GEN_H__