dependencies = main.o lib/structures/linked_list.o lib/tools/string_tools.o
case = test_cases/1.in

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	make all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main < $(case)
