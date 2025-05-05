#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stddef.h>

typedef struct PoolAllocator {
  size_t block_size;
  size_t num_blocks;
  void *memory_start;
  void *free_list;
} PoolAllocator;

int pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks);
void *pool_alloc(PoolAllocator *allocator);
int pool_free(PoolAllocator *allocator, void *ptr);

#endif // POOL_ALLOCATOR_H
