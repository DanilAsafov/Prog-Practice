#include "Problem-7.h"
#include <assert.h>
#include <stdio.h>

void test() {
  Stack *s = stack_init(1);
  assert(s != NULL);
  assert(is_empty(s));
  assert(!push(s, 0));
  assert(!is_empty(s));
  assert(push(s, 1));
  int out;
  assert(!pop(s, &out) && out == 0);
  assert(pop(s, &out));
  stack_free(s);
}

int main() {
  test();

  return 0;
}
