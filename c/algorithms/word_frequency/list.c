#include <stdlib.h>

typedef struct node {
	void *value;
	struct node *next;
} Node_t;

typedef struct linked_list {

	int node_size;
	Node_t *end;
	int size;

} LinkedList_t;

LinkedList_t *create_list(int node_size) {

	LinkedList_t *list = (LinkedList_t *) malloc(0 * sizeof(LinkedList_t));

	list->node_size = node_size;
	list->end = NULL;
	list->size = 0;

	return list;
}

int get_size(LinkedList_t *list) {
	return list->size;
}

void add_node(LinkedList_t *list, void *value) {
	list->size++;
	Node_t *node = (Node_t *) malloc(sizeof(Node_t));
	node->value = value;

	node->next = list->end;
	list->end = node;

}

void remove_node(LinkedList_t *list, int depth) {
	Node_t *parent_node = list->end;
	Node_t *current_node = list->end;

	if (depth < list->size) {
		for (int i = 0; i < depth; i++) {
			parent_node = current_node;
			current_node = current_node->next;
		}

		if (depth == 0) {
			list->end = current_node->next;
			free(current_node);
		} else {
			Node_t *next_node = current_node->next;
			parent_node->next = next_node;
			free(current_node);
		}
	}
}

void *get_node_value(Node_t *node) {
	return node->value;
}

Node_t *get_node_next(Node_t *node) {
	return node->next;
}

Node_t *search_node(LinkedList_t *list, int depth) {

	Node_t *current_node = list->end;

	if (depth < list->size) {
		for (int i = 0; i < depth; i++) {
			current_node = current_node->next;
		}
	} else return NULL;

	return current_node;
}

void swap_nodes(Node_t *first, Node_t *second) {
	void *temporary_value = first->value;
	first->value = second->value;
	second->value = temporary_value;
}

void free_nodes(Node_t *node) {

	if (node != NULL) {
		free(node->value);
		free_nodes(node->next);
	}

}