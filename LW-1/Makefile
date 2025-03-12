TASKS = Problem-5
TEST_EXECUTABLES = $(addprefix test_, $(TASKS))

clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

tests: $(TEST_EXECUTABLES)

.PHONY: tests clear

# Problem 5

Problem-5.o: Problem-5.h Problem-5.c
	gcc -g -c Problem-5.c -o Problem-5.o

Problem-5.a: Problem-5.o
	ar rc Problem-5.a Problem-5.o

Problem-5_test.o: Problem-5_test.c
	gcc -g -c Problem-5_test.c -o Problem-5_test.o

Problem-5_test: Problem-5_test.o Problem-5.a
	gcc -g -static -o Problem-5_test Problem-5_test.o Problem-5.a -lm

test_Problem-5: Problem-5_test
	./Problem-5_test
