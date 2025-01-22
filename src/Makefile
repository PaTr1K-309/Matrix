CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
GFLAGS=
LFLAGS=-lm -lcheck -lsubunit

LIB=s21_matrix.a

EXEC=main

SOURCES=$(wildcard s21_matrix/*.c)
OBJECTS=$(SOURCES:.c=.o)

TEST_SOURCES=$(wildcard s21_test/*.c)
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)

.PHONY: clean test gcov_report

all: s21_matrix.a

$(EXEC): clean $(TEST_OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -o $(EXEC) -L. $(LIB) $(LFLAGS)

test: LFLAGS+=-lgcov
test: GFLAGS+=--coverage
test: $(EXEC)
	./$(EXEC)

s21_test/%.o: s21_test/%.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_matrix/%.o: s21_matrix/%.c
	$(CC) $(CFLAGS) $(GFLAGS) -c $< -o $@

s21_matrix.a: $(OBJECTS)
	ar -rcs $(LIB) $(OBJECTS)

gcov_report: test
	mkdir s21_report
	gcovr -r . --html --html-details -o s21_report/s21_matrix.html

clean:
	rm -f $(EXEC)
	rm -f *.a **/*.o
	rm -f **/*.gcno **/*.gcda **/*.gcov
	rm -rf s21_report
	rm -rf nohup.out
	clear

check:
	clang-format -n **/*.c **/*.h

val: $(EXEC)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(EXEC)


open:
	xdg-open s21_report/s21_matrix.html
