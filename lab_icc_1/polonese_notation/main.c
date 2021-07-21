// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Reverse Polonese Notation
// 21/07/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int height;
    int *values;

} Stack;

enum Operators {
    SUM = '+',
    SUB = '-',
    DIV = '/',
    MULT = '*',
};

void stack_insert(Stack *stack, int value);

int stack_pop(Stack *stack);

int main() {

    Stack stack = { .height = 0, .values = calloc(sizeof(int), 0) };

    char current_char;

    while (scanf("%c", &current_char) != EOF) {

        if (current_char == ' ') continue;

        switch (current_char) {

            case SUM: {
                stack_insert(&stack, stack_pop(&stack) + stack_pop(&stack));
            }

            case SUB: {
                stack_insert(&stack, stack_pop(&stack) - stack_pop(&stack));
            }

            case DIV: {
                stack_insert(&stack, stack_pop(&stack) / stack_pop(&stack));
            }

            case MULT: {
                stack_insert(&stack, stack_pop(&stack) * stack_pop(&stack));
            }

            default: stack_insert(&stack, (int) current_char  - '0');

        }

    }

    printf("%d", stack.values[0]);

}

void stack_insert(Stack *stack, int value) {

    stack->values = realloc(stack->values, sizeof(int) * ++(stack->height));
    stack->values[stack->height - 1] = value;

}

int stack_pop(Stack *stack) {

    int pop = stack->values[--(stack->height)];
    stack->values = realloc(stack->values, sizeof(int) * stack->height);

    return pop;

}