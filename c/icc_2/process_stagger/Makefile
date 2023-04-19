dependencies = main.o lib/algorithms/sorting.o lib/algorithms/binary_search.o lib/structures/linked_list.o
case = test_cases/7.in

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	make all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main < $(case)
