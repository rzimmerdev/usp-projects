dependencies = main.o structures/linked_list.o
case = test_cases/1.in

all: main.o $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main