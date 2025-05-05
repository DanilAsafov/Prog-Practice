TASKS = pool_allocator hashtable
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# Pool Allocator

pool_allocator.o: pool_allocator.h pool_allocator.c
	gcc -g -c pool_allocator.c -o pool_allocator.o

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

pool_allocator_test.o: pool_allocator_test.c
	gcc -g -c pool_allocator_test.c -o pool_allocator_test.o

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	gcc -g -static -o pool_allocator_test pool_allocator_test.o pool_allocator.a -lm

test_pool_allocator: pool_allocator_test
	./pool_allocator_test

# HashTable with Pool Allocator

hashtable.o: hashtable.h hashtable.c
	gcc -g -c hashtable.c -o hashtable.o

hashtable.a: hashtable.o
	ar rc hashtable.a hashtable.o

hashtable_test.o: hashtable_test.c
	gcc -g -c hashtable_test.c -o hashtable_test.o

hashtable_test: hashtable_test.o hashtable.a pool_allocator.a
	gcc -g -static -o hashtable_test hashtable_test.o hashtable.a pool_allocator.a -lm

test_hashtable: hashtable_test
	./hashtable_test
