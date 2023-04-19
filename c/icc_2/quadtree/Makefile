dependencies = main.o image_tools/quad_tree.o
libraries += -lm
case = test_cases/3.in

all: $(dependencies)
	gcc -o main $(dependencies) $(libraries)

run: main.c
	./main

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main