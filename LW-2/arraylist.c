#include "arraylist.h"
#include "linear_allocator.h"
#include <string.h>

void arraylist_init(ArrayList *list, LinearAllocator *allocator,
                    size_t initial_capacity) {
  list->data = initial_capacity > 0
                   ? (void **)linear_allocator_alloc(
                         allocator, initial_capacity * sizeof(void *))
                   : NULL;
  list->size = 0;
  list->capacity = initial_capacity;
  list->allocator = allocator;
}

void arraylist_add(ArrayList *list, void *element) {
  if (list->size >= list->capacity) {
    size_t new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
    void **new_data = (void **)linear_allocator_alloc(
        list->allocator, new_capacity * sizeof(void *));
    if (list->data) {
      memcpy(new_data, list->data, list->size * sizeof(void *));
      linear_allocator_reset(list->allocator);
    }
    list->data = new_data;
    list->capacity = new_capacity;
  }
  list->data[list->size++] = element;
}

void *arraylist_get(const ArrayList *list, size_t index) {
  return (index < list->size) ? list->data[index] : NULL;
}

void arraylist_remove(ArrayList *list, size_t index) {
  if (index >= list->size)
    return;

  memmove(&list->data[index], &list->data[index + 1],
          (list->size - index - 1) * sizeof(void *));
  list->size--;
}

void arraylist_free(ArrayList *list) {
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;
}