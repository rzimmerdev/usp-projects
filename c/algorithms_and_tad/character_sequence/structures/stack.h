#ifndef CHARACTER_SEQUENCE_STACK_H
#define CHARACTER_SEQUENCE_STACK_H

// Stack ADT for storing statical characters (problem specific ADT,
// so as to not have to dynamically allocate single characters)
typedef struct stack Stack_t;

// Dynamically allocate memory space for Stack type variable and initiate top node to null
Stack_t *create_stack();

// Insert static character into top of stack, and appoint new top
void insert_stack(Stack_t *stack, char value);

// Removes stack top node and return its value
char pop_stack(Stack_t *stack);

// Returns stack total count of elements
int get_size(Stack_t *stack);

// Returns stack top node value (character)
char view_top(Stack_t *stack);

// Frees every node inside stack, as well as the stack variable itself
void free_stack(Stack_t *stack);

#endif
