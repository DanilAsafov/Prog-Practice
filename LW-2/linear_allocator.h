#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include <stddef.h>

typedef struct {
  void *start;
  size_t used;
  size_t size;
} LinearAllocator;

LinearAllocator *linear_allocator_create(size_t size);
void linear_allocator_destroy(LinearAllocator *allocator);
void *linear_allocator_alloc(LinearAllocator *allocator, size_t size);
void linear_allocator_reset(LinearAllocator *allocator);

#endif