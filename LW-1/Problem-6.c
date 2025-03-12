#include "Problem-6.h"
#include <stdio.h>
#include <stdlib.h>

void init_list(LinkedList *list) {
  list->head = NULL;
  list->size = 0;
}

void add_front(LinkedList *list, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void add_back(LinkedList *list, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    perror("malloc failed");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;

  if (!list->head) {
    list->head = new_node;
  } else {
    Node *current = list->head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }
  list->size++;
}

void add_at(LinkedList *list, int index, int data) {
  if (index < 0 || index > list->size) {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  if (index == 0) {
    add_front(list, data);
  } else if (index == list->size) {
    add_back(list, data);
  } else {
    Node *prev = list->head;
    for (int i = 0; i < index - 1; i++) {
      prev = prev->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
      perror("malloc failed");
      exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    list->size++;
  }
}

void delete_at(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  Node *to_delete;
  if (index == 0) {
    to_delete = list->head;
    list->head = list->head->next;
  } else {
    Node *prev = list->head;
    for (int i = 0; i < index - 1; i++) {
      prev = prev->next;
    }
    to_delete = prev->next;
    prev->next = to_delete->next;
  }
  free(to_delete);
  list->size--;
}

int get_at(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  Node *current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->data;
}

int get_size(LinkedList *list) { return list->size; }

void free_list(LinkedList *list) {
  Node *current = list->head;
  while (current) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  list->head = NULL;
  list->size = 0;
}
