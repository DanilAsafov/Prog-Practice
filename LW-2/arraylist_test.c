#include "arraylist.h"
#include "linear_allocator.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  linear_allocator_t *allocator = linear_allocator_create(1024);
  ArrayList list;
  arraylist_init(&list, allocator, 2, sizeof(int));

  int x = 10, y = 20, z = 30;
  arraylist_add(&list, &x);
  arraylist_add(&list, &y);
  arraylist_add(&list, &z);

  assert(list.size == 3);
  assert(*(int *)arraylist_get(&list, 0) == 10);

  arraylist_del(&list, 1);
  assert(list.size == 2);

  arraylist_free(&list);
  linear_allocator_destroy(allocator);

  linear_allocator_t *alloc1 = linear_allocator_create(256);
  ArrayList list1;
  arraylist_init(&list1, alloc1, 3, sizeof(int));

  int a = 1, b = 2, c = 3;
  arraylist_add(&list1, &a);
  arraylist_del(&list1, 0);
  arraylist_add(&list1, &b);
  arraylist_add(&list1, &c);

  assert(list1.size == 2);
  assert(*(int *)arraylist_get(&list1, 0) == 2);
  assert(*(int *)arraylist_get(&list1, 1) == 3);
  linear_allocator_destroy(alloc1);

  linear_allocator_t *alloc2 = linear_allocator_create(64);
  ArrayList list2;
  arraylist_init(&list2, alloc2, 2, sizeof(int));

  arraylist_del(&list2, 100);
  arraylist_add(&list2, &a);
  arraylist_del(&list2, 1);
  assert(list2.size == 1);
  linear_allocator_destroy(alloc2);

  linear_allocator_t *alloc3 = linear_allocator_create(128);
  ArrayList list3;
  arraylist_init(&list3, alloc3, 2, sizeof(int));

  arraylist_add(&list3, &a);
  arraylist_free(&list3);

  arraylist_init(&list3, alloc3, 1, sizeof(int));
  arraylist_add(&list3, &b);
  assert(*(int *)arraylist_get(&list3, 0) == 2);
  linear_allocator_destroy(alloc3);

  return 0;
}
