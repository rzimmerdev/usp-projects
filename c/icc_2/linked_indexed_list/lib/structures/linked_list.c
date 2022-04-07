#include <stdlib.h>

typedef struct Node_t {
	void *value;
	struct Node_t *next;
} node;

typedef struct LinkedList_t {
	node *start;
	int size;

} linked_list;

linked_list *create_list() {

	linked_list *list = (linked_list *) malloc(sizeof(linked_list));
	list->size = 0;
	list->start = NULL;

	return list;
}

int get_size(linked_list *list) {
	return list->size;
}

void add_node(linked_list *list, void *value, int (compare)(void *first, void *second)) {
	list->size++;
	node *new_node = malloc(sizeof(node));
    new_node->value = value;

    // Decide if list has elements
	if (list->start) {

        node *parent = list->start;

        // Decide if current node comes before list start, in which case
        // list start is reset
        if (parent && compare(value, parent->value)) {
            list->start = new_node;
            new_node->next = parent;
        }

        // Else find righteous parent in linked list, based on input node values comparison function
        else {
            while (parent->next && !compare(value, parent->next->value)) {
                parent = parent->next;
            }
            new_node->next = parent->next;
            parent->next = new_node;
        }

    }

    // Else set list start
    else {
        new_node->next = NULL;
        list->start = new_node;
    }
}

void *get_value(node *node) {
	return node->value;
}

node *get_next(node *current_node) {
    return current_node->next;
}

void free_list(linked_list *list, void (free_value)(void *value)) {
    node *current = list->start;

    // While current pointer is not null (list end has not yet been reached)
    // set temporary node with current pointer, as to clear value and pointer
    // without losing next reference
    while (current) {
        node *temp = current;
        current = current->next;
        free_value(temp->value);
        free(temp);
    }

    free(list);
}