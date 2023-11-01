#include <stdlib.h>

#include "memory.h"

// reallocate会调用realloc重新分配空间
void *reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  // realloc失败返回NULL
  if (result == NULL) {
    exit(1);
  }
  return result;
}