#ifndef WORD_FREQUENCY_QUEUE_H
#define WORD_FREQUENCY_QUEUE_H

// Queue variable type, which contains starting node, ending node and total elements count variables
typedef struct queue Queue_t;

// Allocates a queue structure, setting total count to 0, as well as setting start and end nodes to NULL (initializing)
Queue_t *create_queue();

// Allocates and inserts new node at end of given queue, as well as setting value field
void insert_queue(Queue_t *queue, void *value);
// Frees first node, as well as returning node content and forwarding queue first node to previous first node next
void *pop_queue(Queue_t *queue);

// Returns queue total elements count
int get_size(Queue_t *queue);

#endif //WORD_FREQUENCY_QUEUE_H
