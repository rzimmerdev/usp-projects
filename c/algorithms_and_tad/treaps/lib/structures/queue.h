#ifndef WORD_FREQUENCY_QUEUE_H
#define WORD_FREQUENCY_QUEUE_H

typedef struct Queue_t queue;

queue *create_queue();

void *view_head(queue *queue);

void insert_queue(queue *queue, void *value);
void *pop_queue(queue *queue);

int get_size(queue *queue);

void free_queue(queue *queue);

#endif //WORD_FREQUENCY_QUEUE_H
