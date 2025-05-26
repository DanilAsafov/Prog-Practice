#include "arraylist.h"
#include "linear_allocator.h"
#include <string.h>

void arraylist_init(ArrayList *list, linear_allocator_t *allocator,
                    size_t initial_capacity, size_t element_size) {
  list->data = initial_capacity > 0
                   ? (void **)linear_allocator_alloc(
                         allocator, initial_capacity * sizeof(void *))
                   : NULL;
  list->size = 0;
  list->capacity = initial_capacity;
  list->allocator = allocator;
  list->element_size = element_size;
}

void arraylist_add(ArrayList *list, const void *element) {
  if (list->size >= list->capacity) {
    size_t new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
    void **new_data = (void **)linear_allocator_alloc(
        list->allocator, new_capacity * sizeof(void *));
    if (list->data) {
      memcpy(new_data, list->data, list->size * sizeof(void *));
    }
    list->data = new_data;
    list->capacity = new_capacity;
  }
  void *element_copy =
      linear_allocator_alloc(list->allocator, list->element_size);
  memcpy(element_copy, element, list->element_size);
  list->data[list->size++] = element_copy;
}

void *arraylist_get(const ArrayList *list, size_t index) {
  return (index < list->size) ? list->data[index] : NULL;
}

void arraylist_del(ArrayList *list, size_t index) {
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
