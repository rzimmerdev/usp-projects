#include <stdlib.h>
typedef struct node {
	void *value;
	struct node *next;
} Node_t;

typedef struct linked_list {

	int node_size;
	Node_t *start;
	Node_t *end;
	int size;

} LinkedList_t;

LinkedList_t *create_linked_list() {

	LinkedList_t *list = (LinkedList_t *) malloc(sizeof(LinkedList_t));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;

	return list;
}

int linked_list_size(LinkedList_t *list) {
	return list->size;
}

void add_node(LinkedList_t *list, void *value) {
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

Node_t *next_node(Node_t *node) {
	return node->next;
}

Node_t *search_node(LinkedList_t *list, int depth) {

	Node_t *current_node = list->start;

	if (depth < list->size) {
		for (int i = 0; i < depth; i++) {
			current_node = current_node->next;
		}
	} else return NULL;

	return current_node;
}

void free_list(LinkedList_t *list) {
	for (int i = 0; i < list->size; i++) {

		free(list->start->value);

		Node_t *next = list->start->next;
		free(list->start);
		list->start = next;
	}

	free(list);
}