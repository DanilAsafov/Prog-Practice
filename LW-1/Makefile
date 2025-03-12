TASKS = Problem-7
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# Problem 7

Problem-7.o: Problem-7.h Problem-7.c
	gcc -g -c Problem-7.c -o Problem-7.o

Problem-7.a: Problem-7.o
	ar rc Problem-7.a Problem-7.o

Problem-7_test.o: Problem-7_test.c
	gcc -g -c Problem-7_test.c -o Problem-7_test.o

Problem-7_test: Problem-7_test.o Problem-7.a
	gcc -g -static -o Problem-7_test Problem-7_test.o Problem-7.a

test_Problem-7: Problem-7_test
	./Problem-7_test
