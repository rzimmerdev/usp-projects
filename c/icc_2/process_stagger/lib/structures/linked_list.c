#include <stdlib.h>

typedef struct Node_t {
	void *value;
	struct Node_t *next;
} node;

typedef struct LinkedList_t {

	node *start;
	node *header;
	int size;

} linked_list;

linked_list *create_list() {

	linked_list *list = (linked_list *) malloc(sizeof(linked_list));
	list->size = 0;
	list->start = NULL;
    list->header = NULL;

	return list;
}

void *view_header(linked_list *list) {

    return list->header ? list->header->value : NULL;
}

void increment_header(linked_list *list) {
    if (list->header)
        list->header = list->header->next;
}

void reset_header(linked_list *list) {
    list->header = list->start;
}

int get_size(linked_list *list) {
	return list->size;
}

void add_node(linked_list *list, void *value, int (compare)(void *first, void *second)) {
    list->size++;
	node *new_node = malloc(sizeof(node));
    new_node->value = value;

    node *parent = list->start;
    node *next;

    if (parent) {
        next = parent->next;

        if (!compare(value, parent->value)) {

            new_node->next = parent;

            while (next != new_node->next) {
                parent = parent->next;
                next = parent->next;
            }
            parent->next = new_node;

            list->start = new_node;
            list->header = new_node;
        }
        else {
            while (next != list->start && compare(value, next->value)) {
                parent = next;
                next = parent->next;
            }

            new_node->next = next;
            parent->next = new_node;
        }
    } else {
        new_node->next = new_node;
        list->start = new_node;
        list->header = new_node;
    }
}

void remove_header(linked_list *list, void (free_value)(void *value)) {

    node *parent = list->start;

    // Verify if list is empty
    if (list->start) {

        list->size--;

        // If not empty, verify if list has only one node
        if (parent->next == list->start) {
            free_value(parent->value);
            free(parent);
            list->header = NULL;
            list->start = NULL;
        } else {

            // Find header parent, and connect previous and next elements, saving header in temporary variable
            // to free after reconnecting list
            while (parent->next != list->header) {
                parent = parent->next;
            }

            if (list->header == list->start) {
                list->start = parent;
            }

            node *temp = parent->next;
            parent->next = list->header->next;
            list->header = parent;

            free_value(temp->value);
            free(temp);
        }
    }

}

void free_list(linked_list *list, void (free_value)(void *value)) {

    node *current = list->start;

    // Since list is round, to free all elements, iterating through list size is necessary
    int i = get_size(list);
    while (i-- > 0) {
        free_value(current->value);
        node *temp = current;
        current = temp->next;
        free(temp);
    }

    free(list);
}