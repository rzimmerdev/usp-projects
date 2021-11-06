dependencies = main.o libraries/tools/string_tools.o libraries/structures/skip_list.o dictionary.o
case = test_cases/2.in

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main < $(case) > out.txt

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main