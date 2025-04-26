TASKS = Problem-6
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# Problem 6

Problem-6.o: Problem-6.h Problem-6.c
	gcc -g -c Problem-6.c -o Problem-6.o

Problem-6.a: Problem-6.o
	ar rc Problem-6.a Problem-6.o

Problem-6_test.o: Problem-6_test.c
	gcc -g -c Problem-6_test.c -o Problem-6_test.o

Problem-6_test: Problem-6_test.o Problem-6.a
	gcc -g -static -o Problem-6_test Problem-6_test.o Problem-6.a

test_Problem-6: Problem-6_test
	./Problem-6_test
