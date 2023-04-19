dependencies = structures/stack.o

all: main.o $(dependencies)
	gcc -o main main.o $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main