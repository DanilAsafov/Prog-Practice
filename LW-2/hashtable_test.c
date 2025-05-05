#include "hashtable.h"
#include "pool_allocator.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_hashtable() {
  PoolAllocator pool;
  const size_t block_size = sizeof(Node);
  const size_t num_blocks = 5;
  pool_init(&pool, block_size, num_blocks);

  HashTable table;
  hashtable_init(&table, 8, &pool);

  int a = 10, b = 20, c = 30;

  assert(!hashtable_insert(&table, "key1", &a));
  assert(*(int *)hashtable_get(&table, "key1") == 10);

  assert(hashtable_insert(&table, "key1", &b));
  assert(*(int *)hashtable_get(&table, "key1") == 20);

  assert(!hashtable_del(&table, "key1"));
  assert(hashtable_del(&table, "key1"));

  for (size_t i = 0; i < 5; ++i) {
    char key[10];
    hashtable_insert(&table, key, &a);
  }
  assert(!hashtable_insert(&table, "overflow", &a));

  hashtable_free(&table);
  free(pool.memory_start);
}

int main() {
  test_hashtable();
  return 0;
}
