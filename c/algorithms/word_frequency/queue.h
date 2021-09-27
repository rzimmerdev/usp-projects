#ifndef WORD_FREQUENCY_QUEUE_H
#define WORD_FREQUENCY_QUEUE_H

typedef struct queue QueueConstructor_t;

QueueConstructor_t *create_queue();
void free_queue(QueueConstructor_t *queue);

void insert_queue(QueueConstructor_t *queue, void *value);
void *pop_queue(QueueConstructor_t *queue);

int get_size(QueueConstructor_t *queue);

#endif //WORD_FREQUENCY_QUEUE_H
