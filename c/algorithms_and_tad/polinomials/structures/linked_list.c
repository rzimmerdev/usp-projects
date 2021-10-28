#include <stdlib.h>
#include "linked_list.h"

typedef struct node {
	void *value;
	struct node *next;
} Node_t;

int sizeof_node() { return sizeof(Node_t); }
int sizeof_linked_list() { return sizeof(linked_list); }

linked_list *create_list() {

	linked_list *list = (linked_list *) malloc(sizeof(linked_list));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;

	return list;
}

int get_size(linked_list *list) {
	return list->size;
}

void add_node(linked_list *list, void *value) {
	list->size++;
	Node_t *node = (Node_t *) malloc(sizeof(Node_t));
	node->value = value;
	node->next = NULL;
	if (list->end == NULL) {
		list->end = node;
		list->start = node;

	} else {
		list->end->next = node;
		list->end = node;
	}
}

void *get_node_value(Node_t *node) {
	return node->value;
}

Node_t *get_node_next(Node_t *node) {
	return node->next;
}

Node_t *get_start(linked_list *list) {
	return list->start;
}

void free_list(linked_list *list) {
	for (int i = 0; i < list->size; i++) {

		free(list->start->value);

		Node_t *next = list->start->next;
		free(list->start);
		list->start = next;
	}

	free(list);
}