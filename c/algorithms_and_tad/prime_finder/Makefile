all: main.o list.o
	gcc -o main main.o list.o

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main