#include "linear_allocator.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#define ALIGNMENT 8

static size_t align_forward(size_t size) {
  return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

linear_allocator_t *linear_allocator_create(size_t size) {
  linear_allocator_t *allocator = malloc(sizeof(linear_allocator_t));
  if (!allocator)
    return NULL;

  allocator->start = malloc(size);
  if (!allocator->start) {
    free(allocator);
    return NULL;
  }

  allocator->used = 0;
  allocator->size = size;
  return allocator;
}

void linear_allocator_destroy(linear_allocator_t *allocator) {
  if (allocator) {
    free(allocator->start);
    free(allocator);
  }
}

void *linear_allocator_alloc(linear_allocator_t *allocator, size_t size) {
  if (!allocator || size == 0)
    return NULL;

  size_t aligned_size = align_forward(size);
  if (allocator->used + aligned_size > allocator->size) {
    return NULL;
  }

  void *ptr = (char *)allocator->start + allocator->used;
  allocator->used += aligned_size;
  return ptr;
}

void linear_allocator_reset(linear_allocator_t *allocator) {
  if (allocator) {
    allocator->used = 0;
  }
}
