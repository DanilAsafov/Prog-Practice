#ifndef PROBLEM_7_H
#define PROBLEM_7_H

typedef struct {
  int *data;
  int top;
  int capacity;
} Stack;

Stack *stack_init(int capacity);
int is_empty(Stack *s);
int push(Stack *s, int value);
int pop(Stack *s);
void stack_free(Stack *s);

#endif // !PROBLEM_7_H
