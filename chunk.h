#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"

typedef enum {
  OP_RETURN,
} OpCode;
// 动态字节数组
typedef struct {
  // 已分配的元素数量
  int count;
  // 实际已经使用的元素数量
  int capacity;
  uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif //CLOX_CHUNK_H
