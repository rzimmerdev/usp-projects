#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	void *value;
	struct node *next;
} Node_t;

typedef struct queue {
	Node_t *end;
	Node_t *start;
	int size;
} Queue_t;

Queue_t *create_queue() {

	Queue_t *queue = malloc(sizeof(Queue_t));

	queue->size = 0;
	queue->end = NULL;
	queue->start = NULL;

	return queue;
}

void insert_queue(Queue_t *queue, void *value) {

	Node_t *new_node = malloc(sizeof(Node_t));

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

void *pop_queue(Queue_t *queue) {

	void *result = NULL;

	if (queue->start != NULL) {

		Node_t *query;

		query = queue->start;
		queue->start = queue->start->next;
		result = query->value;
		free(query);
	}

	queue->size--;

	return result;

}

int get_size(Queue_t *queue) {
	return queue->size;
}

void free_queue(Queue_t *queue) {
	for (int i = 0; i < get_size(queue); i++) {
		Node_t *node = queue->start;
		free(node->value);

		queue->start = node->next;
		free(node);
	}
	free(queue);
}