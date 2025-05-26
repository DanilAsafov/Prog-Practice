TASKS = arraylist
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# ArrayList

linear_allocator.o: linear_allocator.h linear_allocator.c
	gcc -g -c linear_allocator.c -o linear_allocator.o

arraylist.o: arraylist.h arraylist.c linear_allocator.h
	gcc -g -c arraylist.c -o arraylist.o

arraylist.a: arraylist.o linear_allocator.o
	ar rc arraylist.a arraylist.o linear_allocator.o

arraylist_test.o: arraylist_test.c arraylist.h linear_allocator.h
	gcc -g -c arraylist_test.c -o arraylist_test.o

arraylist_test: arraylist_test.o arraylist.a
	gcc -g -static -o arraylist_test arraylist_test.o arraylist.a -lm

test_arraylist: arraylist_test
	./arraylist_test
