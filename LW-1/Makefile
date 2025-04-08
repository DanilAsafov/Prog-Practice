TASKS = Problem-4
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# Problem 4

Problem-4.o: Problem-4.h Problem-4.c
	gcc -g -c Problem-4.c -o Problem-4.o

Problem-4.a: Problem-4.o
	ar rc Problem-4.a Problem-4.o

Problem-4_test.o: Problem-4_test.c
	gcc -g -c Problem-4_test.c -o Problem-4_test.o

Problem-4_test: Problem-4_test.o Problem-4.a
	gcc -g -static -o Problem-4_test Problem-4_test.o Problem-4.a -lm

test_Problem-4: Problem-4_test
	./Problem-4_test
