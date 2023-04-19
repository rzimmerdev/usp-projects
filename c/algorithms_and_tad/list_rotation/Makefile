dependencies = main.o structures/circular_linked_list.o

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main