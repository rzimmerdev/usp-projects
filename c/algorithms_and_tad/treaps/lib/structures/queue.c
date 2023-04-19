#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node_t {
	void *value;
	struct Node_t *next;
} node;

typedef struct Queue_t {
	node *end;
	node *start;
	int size;
} queue;

queue *create_queue() {

	queue *new_queue = malloc(sizeof(queue));

    new_queue->size = 0;
    new_queue->end = NULL;
    new_queue->start = NULL;

	return new_queue;
}

void insert_queue(queue *queue, void *value) {

	node *new_node = malloc(sizeof(node));

	new_node->next = NULL;
	new_node->value = value;

	if (queue->start == NULL) {
		queue->end = new_node;
		queue->start = new_node;
	} else {
		queue->end->next = new_node;
		queue->end = queue->end->next;
	}

	queue->size++;
}

void *view_head(queue *current_queue) {

    return current_queue->start;
}

void *pop_queue(queue *current_queue) {

	void *result = NULL;

	if (current_queue->start) {

		node *current_query;

        current_query = current_queue->start;
        current_queue->start = current_queue->start->next;
		result = current_query->value;
		free(current_query);
	}

    current_queue->size--;

	return result;

}

int get_size(queue *queue) {
	return queue->size;
}