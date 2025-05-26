#include "linear_allocator.h"
#include <assert.h>
#include <stdio.h>

#define ALIGNMENT 8

int main() {
  linear_allocator_t *allocator = linear_allocator_create(1024);
  assert(allocator != NULL);
  assert(allocator->size == 1024);

  int *num = linear_allocator_alloc(allocator, sizeof(int));
  *num = 42;
  assert(*num == 42);

  void *large_block = linear_allocator_alloc(allocator, 1024);
  assert(large_block == NULL);

  linear_allocator_reset(allocator);
  char *str = linear_allocator_alloc(allocator, 100);
  assert(str != NULL);

  size_t prev_used = allocator->used;
  void *aligned_ptr = linear_allocator_alloc(allocator, 3);
  assert((size_t)aligned_ptr % ALIGNMENT == 0);
  assert(allocator->used - prev_used == ALIGNMENT);

  linear_allocator_destroy(allocator);
  return 0;
}
