#include <stdlib.h>

typedef struct node {
	void *value;
	struct node *next;
} Node_t;

typedef struct linked_list {

	int node_size;
	Node_t *start;
	int size;

} OrderedLinkedList_t;

OrderedLinkedList_t *create_list() {

	OrderedLinkedList_t *list = (OrderedLinkedList_t *) malloc(sizeof(OrderedLinkedList_t));
	list->size = 0;
	list->start = NULL;

	return list;
}

int get_size(OrderedLinkedList_t *list) {
	return list->size;
}

void add_node(OrderedLinkedList_t *list, void *value, int (*get_order)(Node_t *next, Node_t *to_insert)) {
	list->size++;
	Node_t *node = (Node_t *) malloc(sizeof(Node_t));
	node->value = value;
	Node_t *current_node = list->start;

	// First verify if list is empty or if value to insert should be ordered before list start
	if (current_node == NULL || (*get_order)(current_node, node)) {
		list->start = node;
		node->next = current_node;
	}

	// Else iterate through list to find right ordered position of new node respective to node value
	else {
		while (current_node->next != NULL && !(*get_order)(current_node->next, node)) {
			current_node = current_node->next;
		} if (current_node->next != NULL) {
			Node_t *next = current_node->next;
			current_node->next = node;
			node->next = next;
		} else {
			node->next = NULL;
			current_node->next = node;
		}
	}
}

void remove_node(OrderedLinkedList_t *list, int index) {
	if (index < get_size(list)) {

		// Verify if the index to be removed is at start of list, which would require a list start shift
		if (index == 0) {
			Node_t *current_node = list->start;
			list->start = list->start->next;
			free(current_node->value);
			free(current_node);
		}

		// Else, find index of parent node, remove next value and skip removed node
		else {
			Node_t *current_node = list->start;
			for (int i = 0; i < index - 1; i++) {
				current_node = current_node->next;
			}
			Node_t *to_delete = current_node->next;
			current_node->next = to_delete->next;
			free(to_delete->value);
			free(to_delete);
		} list->size--;
	}
}

Node_t *get_list_start(OrderedLinkedList_t *list) {
	return list->start;
}

void *get_node_value(Node_t *node) {
	return node->value;
}

Node_t *get_node_next(Node_t *node) {
	return node->next;
}

void free_list(OrderedLinkedList_t *list, void (*free_node)(Node_t *to_free)) {
	for (int i = 0; i < list->size; i++) {
		(*free_node)(list->start);
		free(list->start->value);

		Node_t *next = list->start->next;
		free(list->start);
		list->start = next;
	}

	free(list);
}