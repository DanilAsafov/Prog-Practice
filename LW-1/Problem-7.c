#include "Problem-7.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 2

Stack *stack_init(size_t capacity) {
  Stack *s = malloc(sizeof(Stack));
  if (!s) {
    return NULL;
  }
  s->data = malloc(capacity * sizeof(int));
  if (!s->data) {
    free(s);
    return NULL;
  }
  s->top = -1;
  s->capacity = capacity;
  return s;
}

int is_empty(Stack *s) { return s->top == -1; }

int push(Stack *s, int value) {
  if (s->top + 1 == s->capacity) {
    return STACK_OVERFLOW;
  }
  s->data[++s->top] = value;
  return 0;
}

int pop(Stack *s, int *top) {
  if (is_empty(s)) {
    return STACK_UNDERFLOW;
  }
  *top = s->data[s->top--];
  return 0;
}

void stack_free(Stack *s) {
  free(s->data);
  free(s);
}
