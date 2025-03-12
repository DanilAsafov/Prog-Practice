#include "Problem-7.h"
#include <assert.h>
#include <stdio.h>

void test() {
  Stack *s = stack_init(3);
  assert(s != NULL);

  assert(is_empty(s));

  assert(push(s, 10));
  assert(!is_empty(s));

  assert(push(s, 20));
  assert(push(s, 30));

  assert(!push(s, 40));

  assert(pop(s) == 30);
  assert(pop(s) == 20);
  assert(pop(s) == 10);

  assert(is_empty(s));
  stack_free(s);
}

int main() {
  test();

  return 0;
}
