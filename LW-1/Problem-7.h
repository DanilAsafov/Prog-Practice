#ifndef PROBLEM_7_H
#define PROBLEM_7_H

#include <stddef.h>

typedef struct {
  int *data;
  int top;
  size_t capacity;
} Stack;

Stack *stack_init(size_t capacity);
int is_empty(Stack *s);
int push(Stack *s, int value);
int pop(Stack *s, int *top);
void stack_free(Stack *s);

#endif // !PROBLEM_7_H
