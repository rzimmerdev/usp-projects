// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Reverse Polonese Notation
// 21/07/2021

#include <stdio.h>
#include <stdlib.h>

// Struct for saving total amount of numbers, as well as the order in which where added
typedef struct {

    int height;
    double *values;

} Stack;

// List for checking and comparing values for mathematical operations
enum Operators {
    SUM = '+',
    SUB = '-',
    DIV = '/',
    MULT = '*',
};

void stack_insert(Stack *stack, double value);

double stack_pop(Stack *stack);

int main() {

    Stack stack = { .height = 0, .values = calloc(sizeof(int), 0) };

   	char current_input;

   	while (scanf("%c", &current_input) != EOF) {

		if ((current_input) == ' ') continue;

		switch (current_input) {

			// Perform read operation on last popped elements of number stack, in last to first order
			case SUM: {

				stack_insert(&stack, stack_pop(&stack) + stack_pop(&stack));

			} break;

			case SUB: {

				double last = stack_pop(&stack);
				double first = stack_pop(&stack);
				stack_insert(&stack, first - last);

			} break;

			case DIV: {

				double last = stack_pop(&stack);
				double first = stack_pop(&stack);
				stack_insert(&stack, first / last);

			} break;

			case MULT: {

				stack_insert(&stack, stack_pop(&stack) * stack_pop(&stack));

			} break;

			// If read character is not a operator, neither a space, should be a number
			default: {

				ungetc(current_input, stdin);
				double number;
				scanf("%lf ", &number);
				stack_insert(&stack, (double) number);

			} break;
		}
   	};

	// Print remaining value in stack, and free the array
   	printf("Resultado: %lf", stack.values[0]);
   	free(stack.values);

   	return 0;
}

// Given pointer to stack, insert new element to end of double array, and increase stack height count
//
// Parameters: Pointer to stack struct, (double) value to insert
// Returns: None (Void)
void stack_insert(Stack *stack, double value) {

    stack->values = realloc(stack->values, sizeof(double) * ++(stack->height));
    stack->values[stack->height - 1] = value;

}

// Given pointer to stack, return last element, and resize stack double array, as well as decrementing height count
//
// Parameters: Pointer to stack struct
// Returns: (double) last number added
double stack_pop(Stack *stack) {

    double pop = stack->values[--(stack->height)];
    stack->values = realloc(stack->values, sizeof(double) * stack->height);

    return pop;

}