#ifndef __UTILS__
#define __UTILS__

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
    (void)(x);                                                                       \
  }

#define TODO(x)                                                                \
  do {                                                                         \
    fprintf(stderr,                                                            \
            RED "TODO" RESET ": %s,\n" BLU "function" RESET ": %s,\n" YEL      \
                "filename" RESET ": %s,\n" GRN "line" RESET ": %d\n",          \
            (x), __func__, __FILE__, __LINE__);                                \
    exit(1);                                                                   \
  } while (0)

#ifdef DEBUG
  #define DEBUG_PRINT(x, fmt)                                                    \
    do {                                                                         \
      printf(x, fmt);                                                            \
    } while (0)
#else
  #define DEBUG_PRINT(x) UNIMPLEMENTED(x)
#endif

#define die(x)
#endif //__UTILS__
