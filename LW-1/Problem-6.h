#ifndef PROBLEM_6_H
#define PROBLEM_6_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

void init_list(LinkedList *list);
int add_front(LinkedList *list, int data);
int add_back(LinkedList *list, int data);
int add_at(LinkedList *list, int index, int data);
int delete_at(LinkedList *list, int index);
int get_at(LinkedList *list, int index, int *out);
int get_size(LinkedList *list);
void free_list(LinkedList *list);

#endif // !PROBLEM_6_H
