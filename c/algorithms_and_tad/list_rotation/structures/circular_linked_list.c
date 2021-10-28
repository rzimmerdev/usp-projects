#include <stdlib.h>
typedef struct node {
	void *value;
	struct node *previous;
	struct node *next;
} Node_t;

typedef struct linked_list {

	int node_size;
	Node_t *start;
	Node_t *end;
	int size;

} CircularLinkedList_t;

CircularLinkedList_t *create_list() {

	CircularLinkedList_t *list = (CircularLinkedList_t *) malloc(sizeof(CircularLinkedList_t));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;

	return list;
}

int get_size(CircularLinkedList_t *list) {
	return list->size;
}

void add_node(CircularLinkedList_t *list, void *value) {
	list->size++;
	Node_t *node = (Node_t *) malloc(sizeof(Node_t));
	node->value = value;
	if (list->end == NULL) {
		list->start = node;

	} else {
		list->start->previous = node;
		list->end->next = node;
	}
	node->next = list->start;
	node->previous = list->end;
	list->end = node;
}

void shift_list(CircularLinkedList_t *list) {
	if (list->end != NULL) {
		list->start = list->start->previous;
		list->end = list->end->previous;
	}
}

Node_t *get_list_start(CircularLinkedList_t *list) {
	return list->start;
}

Node_t *get_next_node(Node_t *node) {
	return node->next;
}

void *get_node_value(Node_t *node) {
	return node->value;
}

void free_list(CircularLinkedList_t *list) {
	for (int i = 0; i < list->size; i++) {

		free(list->start->value);

		Node_t *next = list->start->next;
		free(list->start);
		list->start = next;
	}

	free(list);
}