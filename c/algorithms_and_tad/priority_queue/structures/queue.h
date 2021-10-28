#ifndef WORD_FREQUENCY_QUEUE_H
#define WORD_FREQUENCY_QUEUE_H

// Struct for storing queue start and end nodes, as well as total nodes count
typedef struct queue Queue_t;

// Initializes queue pointer, as well as sets initial node values to NULL
Queue_t *create_queue();

// Individually frees each node, if any, then frees Queue_t pointer
void free_queue(Queue_t *queue);

// Inserts a new node at end of queue, populating node values with input void pointer value
void insert_queue(Queue_t *queue, void *value);

// Returns value of node start pointer, as well as stepping queue position and freeing node
void *pop_queue(Queue_t *queue);

// Returns total count of queue elements
int queue_size(Queue_t *queue);

#endif //WORD_FREQUENCY_QUEUE_H
