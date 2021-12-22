dependencies = main.o libraries/algorithms/sorting.o
case = test_cases/5.in

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main