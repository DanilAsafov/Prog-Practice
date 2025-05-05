#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "pool_allocator.h"
#include <stddef.h>

typedef struct Node Node;

struct Node {
  const char *key;
  void *value;
  struct Node *next;
};

typedef struct HashTable HashTable;

struct HashTable {
  size_t capacity;
  struct Node **buckets;
  PoolAllocator *allocator;
};

int hashtable_init(HashTable *table, size_t capacity, PoolAllocator *allocator);
int hashtable_insert(HashTable *table, const char *key, void *value);
void *hashtable_get(HashTable *table, const char *key);
int hashtable_del(HashTable *table, const char *key);
void hashtable_free(HashTable *table);

#endif // HASHTABLE_H
