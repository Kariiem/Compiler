#ifndef __UTILS__
#define __UTILS__
#include "tbassert.h"
#include <stdio.h>
//
// source: https://stackoverflow.com/a/23657072
#define RED "\x1B[7;40;31m"
#define GRN "\x1B[7;40;32m"
#define YEL "\x1B[7;40;33m"
#define BLU "\x1B[7;40;34m"
#define MAG "\x1B[7;40;35m"
#define CYN "\x1B[7;40;36m"
#define WHT "\x1B[7;40;37m"
#define RESET "\x1B[0m"

#define UNIMPLEMENTED(x)                                                       \
  while (0) {                                                                  \
    (void)(x);                                                                 \
  }

#define TODO(x)                                                                \
  do {                                                                         \
    fprintf(stderr,                                                            \
            RED "TODO" RESET ": %s,\n" BLU "function" RESET ": %s,\n" YEL      \
                "filename" RESET ": %s,\n" GRN "line" RESET ": %d\n",          \
            (x), __func__, __FILE__, __LINE__);                                \
    exit(1);                                                                   \
  } while (0)
#define FREE_ATOM(ptr)                                                         \
  do {                                                                         \
    DEBUG_ASSERT(ptr, #ptr " is NULL\n");                                      \
    free((void *)ptr);                                                         \
    (ptr) = NULL;                                                              \
  } while (0)
// #undef FREE_ATOM
// #define FREE_ATOM(ptr)
#define INDENT(indent)                                                         \
  do {                                                                         \
    for (int i = 0; i < indent; i++) {                                         \
      printf("  ");                                                            \
    }                                                                          \
  } while (0)

#endif //__UTILS__
