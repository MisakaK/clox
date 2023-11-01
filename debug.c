#include <stdio.h>

#include "debug.h"
#include "value.h"

// 对字节码块反汇编
void disassembleChunk(Chunk *chunk, const char *name) {
  printf("== %s == \n", name);

  for (int offset = 0; offset < chunk->count; ) {
    // 返回下一条指令的偏移量
    offset = disassembleInstruction(chunk, offset);
  }
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

// 反汇编一条指令，返回下条指令的偏移量
int disassembleInstruction(Chunk *chunk, int offset) {
  // 打印偏移量
  printf("%04d ", offset);
  if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
    printf("   | ");
  }
  else {
    printf("%4d ", chunk->lines[offset]);
  }

  // 从字节码给定的偏移量中读取一个字节，这个字节是操作码
  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}
