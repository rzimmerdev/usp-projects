#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char value;
	struct node *bottom;
} Node_t;

typedef struct stack {
	Node_t *top;
	int size;
} Stack_t;

Stack_t *create_stack() {

	Stack_t *stack = malloc(sizeof(Stack_t));

	stack->size = 0;
	stack->top = NULL;

	return stack;
}

void insert_stack(Stack_t *stack, char value) {

	Node_t *new_node = malloc(sizeof(Node_t));
	new_node->value = value;

	new_node->bottom = stack->top;
	stack->top = new_node;

	stack->size++;
}

char pop_stack(Stack_t *stack) {

	char result = '\0';

	if (stack->top != NULL) {

		Node_t *top = stack->top;

		stack->top = stack->top->bottom;

		result = top->value;
		free(top);
		stack->size--;
	}

	return result;

}

char view_top(Stack_t *stack) {

	if (stack->top == NULL) return '\0';
	return stack->top->value;

}

int get_size(Stack_t *stack) {
	return stack->size;
}

void free_stack(Stack_t *stack) {

	Node_t *current_node = stack->top;

	while (current_node != NULL) {
		current_node = stack->top;
		pop_stack(stack);
	}

	free(stack);

}