#include "pool_allocator.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_pool_allocation() {
  PoolAllocator allocator;
  const size_t block_size = 16;
  const size_t num_blocks = 4;
  pool_init(&allocator, block_size, num_blocks);

  void *blocks[num_blocks];
  for (size_t i = 0; i < num_blocks; ++i) {
    blocks[i] = pool_alloc(&allocator);
    assert(blocks[i] != NULL && "Allocation failed");
  }

  assert(pool_alloc(&allocator) == NULL && "Over-allocation should fail");

  pool_free(&allocator, blocks[1]);
  void *new_block = pool_alloc(&allocator);
  assert(new_block == blocks[1] && "Reuse after free failed");

  for (size_t i = 0; i < num_blocks; ++i) {
    pool_free(&allocator, blocks[i]);
  }

  for (size_t i = 0; i < num_blocks; ++i) {
    assert(pool_alloc(&allocator) != NULL && "Re-allocation failed");
  }

  free(allocator.memory_start);
}

int main() {
  test_pool_allocation();
  return 0;
}
