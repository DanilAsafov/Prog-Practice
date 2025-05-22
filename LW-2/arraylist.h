#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "linear_allocator.h"
#include <stddef.h>

typedef struct {
  void **data;
  size_t size;
  size_t capacity;
  LinearAllocator *allocator;
  size_t element_size;
} ArrayList;

void arraylist_init(ArrayList *list, LinearAllocator *allocator,
                    size_t initial_capacity, size_t element_size);
void arraylist_add(ArrayList *list, const void *element);
void *arraylist_get(const ArrayList *list, size_t index);
void arraylist_del(ArrayList *list, size_t index);
void arraylist_free(ArrayList *list);

#endif
