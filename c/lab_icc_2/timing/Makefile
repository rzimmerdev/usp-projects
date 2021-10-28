program = timing_specific
dependencies = $(program).o sorting.o

all: $(dependencies)
	gcc -o $(program) $(dependencies)

run: timing.c
	./$(program)

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./timing