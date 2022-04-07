#include <stdlib.h>

typedef struct Stack_t {
	int *elements;
	int size;

} stack;

stack *create_stack() {

	stack *stack = (stack *) malloc(sizeof(stack));
	stack->elements = malloc(0 * sizeof(int *));
	stack->size = 0;

	return stack;
}

int get_size(stack *stack) {
	return stack->size;
}

void insert_stack(stack *stack, int value) {
	stack->elements = realloc(stack->elements, ++(stack->size) * sizeof(int));
	stack->elements[stack->size - 1] = value;
}

int search_stack(stack *stack, int index) {
	return stack->elements[index > stack->size ? stack->size : index];
}

void free_stack(stack *stack) {
	stack->elements;
	free(stack);
}