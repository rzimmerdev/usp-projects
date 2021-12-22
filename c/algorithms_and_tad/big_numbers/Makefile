dependencies = main.o lib/struct/linked_list.o big_numbers.o

all: main.o $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	make all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main < test_cases/1.in