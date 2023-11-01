#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;
// 动态字节数组
typedef struct {
  // 已分配的元素数量
  int count;
  // 实际已经使用的元素数量
  int capacity;
  uint8_t* code;
  // 字节码中字节的行号
  int* lines;
  // 保存字节码块中的常量值
  ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif //CLOX_CHUNK_H
