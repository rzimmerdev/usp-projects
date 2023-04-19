dependencies = lib/structures/queue.o lib/structures/treap.o lib/tools/string_scan.o
case = test_cases/4.in

all: main.o $(dependencies)
	gcc -o main main.o $(dependencies)

run: main.c
	./main

valgrind: all
	make all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main < $(case)
