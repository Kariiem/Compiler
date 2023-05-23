#ifndef __CVECTOR_UTILS__
#define __CVECTOR_UTILS__
#define CVECTOR_FREE(vec, free_func)                                           \
  do {                                                                         \
    size_t i;                                                                  \
    for (i = 0; i < cvector_size((vec)); i++) {                                \
      free_func(&vec[i]);                                                      \
    }                                                                          \
    cvector_free((vec));                                                       \
    (vec) = NULL;                                                              \
  } while (0)

#define vtype(type) cvector_vector_type(type)
#endif // __CVECTOR_UTILS__