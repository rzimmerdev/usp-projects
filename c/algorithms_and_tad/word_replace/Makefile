all: main.o queue.o string_tools.o
	gcc -o main main.o queue.o string_tools.o

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main