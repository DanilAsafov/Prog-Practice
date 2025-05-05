#include "pool_allocator.h"
#include <stdint.h>
#include <stdlib.h>

#define MALLOC_UNSUCCESS 1;
#define PTR_NULL 2;
#define PTR_OUT_OF_BOUNDS 3;
#define PTR_MISALIGNED 4;

int pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks) {
  if (block_size < sizeof(void *)) {
    block_size = sizeof(void *);
  }
  allocator->block_size = block_size;
  allocator->num_blocks = num_blocks;
  allocator->memory_start = malloc(block_size * num_blocks);

  if (!allocator->memory_start)
    return MALLOC_UNSUCCESS;

  char *current = (char *)allocator->memory_start;
  for (size_t i = 0; i < num_blocks - 1; ++i) {
    void **next = (void **)(current + block_size);
    *((void **)current) = next;
    current += block_size;
  }
  *((void **)current) = NULL;
  allocator->free_list = allocator->memory_start;
  return 0;
}

void *pool_alloc(PoolAllocator *allocator) {
  if (!allocator->free_list)
    return NULL;

  void *block = allocator->free_list;
  allocator->free_list = *((void **)block);
  return block;
}

int pool_free(PoolAllocator *allocator, void *ptr) {
  if (!ptr)
    return PTR_NULL;

  char *start = (char *)allocator->memory_start;
  char *end = start + allocator->block_size * allocator->num_blocks;
  char *p = (char *)ptr;

  if (p < start || p >= end)
    return PTR_OUT_OF_BOUNDS;
  if ((p - start) % allocator->block_size != 0)
    return PTR_MISALIGNED;
  *((void **)ptr) = allocator->free_list;
  allocator->free_list = ptr;
  return 0;
}
