dependencies = main.o libraries/tools/string_tools.o libraries/structures/skip_list.o
case = test_cases/1.in

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main < $(case)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main