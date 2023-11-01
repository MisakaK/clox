#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity * 2))
// GROW_ARRAY调用reallocate，并且将把生成的void*的指针转为type*类型
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  ((type*)reallocate(pointer, sizeof(type) * (oldCount), \
    sizeof(type) * (newCount)))

// FREE_ARRAY通过传入0来释放内存
#define FREE_ARRAY(type, pointer, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif //CLOX_MEMORY_H
