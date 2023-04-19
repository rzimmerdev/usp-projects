dependencies = main.o structures/ordered_linked_list.o tools/string_tools.o persons_database.o

all: main.o $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main