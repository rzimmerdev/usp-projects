#ifndef WORD_FREQUENCY_QUEUE_H
#define WORD_FREQUENCY_QUEUE_H

typedef struct queue Queue_t;

Queue_t *create_queue();
void free_queue(Queue_t *queue);

void insert_queue(Queue_t *queue, void *value);
void *pop_queue(Queue_t *queue);

int get_size(Queue_t *queue);

#endif //WORD_FREQUENCY_QUEUE_H
