dependencies = main.o tools/string_tools.o tools/shell_tools.o

all: $(dependencies)
	gcc -o main $(dependencies)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main