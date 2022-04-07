program = timing
dependencies = $(program).o lib/sorting.o

all: $(dependencies)
	gcc -o $(program) $(dependencies)

run: timing.c
	make all
	./$(program)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./timing