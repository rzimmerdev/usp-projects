#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct queue {
	void *queue;
	int size;
} QueueConstructor_t;

QueueConstructor_t *create_queue() {

	QueueConstructor_t *queue = malloc(sizeof(QueueConstructor_t));

	queue->size = 0;
	queue->queue = malloc(queue->size * sizeof(void *));

	return queue;
}

void insert_queue(QueueConstructor_t *queue, void *value) {

	queue->queue = realloc(queue->queue, ++(queue->size) * sizeof(void *));
	memcpy(queue->queue + (queue->size - 1) * sizeof(void *), value, sizeof(void *));
}

void *pop_queue(QueueConstructor_t *queue) {

	void *first = (void *) (queue->queue);

	queue->queue = memmove(queue->queue, queue->queue + sizeof(void *), --(queue->size) * sizeof(void *));
	return first;
}

int get_size(QueueConstructor_t *queue) {
	return queue->size;
}

void free_queue(QueueConstructor_t *queue) {
	for (int i = 0; i < queue->size; i++) {
		free(queue->queue);
	}
	free(queue);
}