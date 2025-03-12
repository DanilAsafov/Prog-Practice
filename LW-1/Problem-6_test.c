#include "Problem-6.h"
#include <assert.h>
#include <stdio.h>

void test_init_list() {
  LinkedList list;
  init_list(&list);
  assert(list.head == NULL);
  assert(list.size == 0);
}

void test_add_front() {
  LinkedList list;
  init_list(&list);

  add_front(&list, 10);
  assert(get_size(&list) == 1);
  assert(get_at(&list, 0) == 10);

  add_front(&list, 20);
  assert(get_size(&list) == 2);
  assert(get_at(&list, 0) == 20);
  assert(get_at(&list, 1) == 10);

  free_list(&list);
}

void test_add_back() {
  LinkedList list;
  init_list(&list);

  add_back(&list, 10);
  assert(get_size(&list) == 1);
  assert(get_at(&list, 0) == 10);

  add_back(&list, 20);
  assert(get_size(&list) == 2);
  assert(get_at(&list, 0) == 10);
  assert(get_at(&list, 1) == 20);

  free_list(&list);
}

void test_add_at() {
  LinkedList list;
  init_list(&list);

  add_at(&list, 0, 10);
  assert(get_size(&list) == 1);
  assert(get_at(&list, 0) == 10);

  add_at(&list, 1, 30);
  assert(get_size(&list) == 2);
  assert(get_at(&list, 1) == 30);

  add_at(&list, 1, 20);
  assert(get_size(&list) == 3);
  assert(get_at(&list, 1) == 20);
  assert(get_at(&list, 2) == 30);

  free_list(&list);
}

void test_delete_at() {
  LinkedList list;
  init_list(&list);

  add_back(&list, 10);
  add_back(&list, 20);
  add_back(&list, 30);

  delete_at(&list, 1);
  assert(get_size(&list) == 2);
  assert(get_at(&list, 0) == 10);
  assert(get_at(&list, 1) == 30);

  delete_at(&list, 0);
  assert(get_size(&list) == 1);
  assert(get_at(&list, 0) == 30);

  delete_at(&list, 0);
  assert(get_size(&list) == 0);

  free_list(&list);
}

void test_get_at() {
  LinkedList list;
  init_list(&list);

  add_back(&list, 10);
  add_back(&list, 20);
  add_back(&list, 30);

  assert(get_at(&list, 0) == 10);
  assert(get_at(&list, 1) == 20);
  assert(get_at(&list, 2) == 30);

  free_list(&list);
}

void test_get_size() {
  LinkedList list;
  init_list(&list);

  assert(get_size(&list) == 0);
  add_front(&list, 10);
  assert(get_size(&list) == 1);
  add_front(&list, 20);
  assert(get_size(&list) == 2);
  delete_at(&list, 0);
  assert(get_size(&list) == 1);

  free_list(&list);
}

int main() {
  test_init_list();
  test_add_front();
  test_add_back();
  test_add_at();
  test_delete_at();
  test_get_at();
  test_get_size();

  return 0;
}
