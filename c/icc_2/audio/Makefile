dependencies = main.o tools/audio_tools.o tools/io_tools.o algorithms/sorting.o
libraries += -lm

all: $(dependencies)
	gcc -o main $(dependencies) $(libraries)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main