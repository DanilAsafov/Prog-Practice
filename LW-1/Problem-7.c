#include "Problem-7.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_init(int capacity) {
  Stack *s = malloc(sizeof(Stack));
  if (!s) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  s->data = malloc(capacity * sizeof(int));
  if (!s->data) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  s->top = -1;
  s->capacity = capacity;
  return s;
}

int is_empty(Stack *s) { return s->top == -1; }

int push(Stack *s, int value) {
  if (s->top >= s->capacity - 1) {
    return 0;
  }
  s->data[++s->top] = value;
  return 1;
}

int pop(Stack *s) {
  if (is_empty(s)) {
    fprintf(stderr, "Error: Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  return s->data[s->top--];
}

void stack_free(Stack *s) {
  free(s->data);
  free(s);
}
