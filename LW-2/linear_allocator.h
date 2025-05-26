#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include <stddef.h>

typedef struct {
  void *start;
  size_t used;
  size_t size;
} linear_allocator_t;

linear_allocator_t *linear_allocator_create(size_t size);
void linear_allocator_destroy(linear_allocator_t *allocator);
void *linear_allocator_alloc(linear_allocator_t *allocator, size_t size);
void linear_allocator_reset(linear_allocator_t *allocator);

#endif
