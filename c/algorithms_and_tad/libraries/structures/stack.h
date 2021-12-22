#ifndef WORD_FREQUENCY_stack_H
#define WORD_FREQUENCY_stack_H

// stack type for storing total elements, starting and ending pointers
typedef struct Stack_t stack;

// Allocate memory for stack type, as well as initialize stack elements array and stack size to 0
stack_t *create_stack();

// Returns total size of stack
int get_size(stack_t *stack);

// Reallocates stack and inserts value into end
void insert_stack(stack_t *stack, int value);

// Returns value at stack->elements[index]
int search_stack(stack_t *stack, int index);

// Frees allocated stack elements and stack type
void free_stack(stack_t *stack);

#endif //WORD_FREQUENCY_stack_H