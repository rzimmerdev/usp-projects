/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 02/11/2021
 *  Data structure for maintaining ordered list of numbers using linked nodes
*/

#include <stdlib.h>

typedef struct Node_t {
	void *value;
	struct Node_t *next;
    struct Node_t *previous;
} node;

typedef struct LinkedList_t {

	node *start;
	node *end;
	int size;

} linked_list;

/*
 *  Function to allocate and instantiate linked list struct variables
 *
 *  @Returns:
 *           linked_list type pointer
 */
linked_list *create_list() {

	linked_list *list = (linked_list *) malloc(sizeof(linked_list));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;

	return list;
}

/*
 *  Frees list node values using free_function, node pointers and list pointer
 *
 *  @Input:
 *          linked list pointer
 *          function to free node value: void *free_function
 */
void add_node(linked_list *list, void *value) {

	list->size++;
	node *node = malloc(sizeof(struct Node_t));

	node->value = value;
	node->next = NULL;
    node->previous = list->end;

    if (list->end == NULL) {
		list->end = node;
		list->start = node;

	} else {
		list->end->next = node;
		list->end = node;
	}
}

/*
 *  Frees list node values using free_function, node pointers and list pointer
 *
 *  @Input:
 *          linked list pointer
 *          function to free node value: void *free_function
 */
void free_list(linked_list *list, void (*free_function)(void *)) {
    for (int i = 0; i < list->size; i++) {

        free_function(list->start->value);

        node *next = list->start->next;
        free(list->start);
        list->start = next;
    }

    free(list);
}

/*
 *  Remove linked list last node and return its value
 *
 *  @Input:
 *          linked list pointer
 *  @Return:
 *          pointer to value used to initialize node: void *
 */
void *pop_end(linked_list *list) {

    node *value = list->end->value;

    node *temp = list->end->previous;
    free(list->end);

    list->end = temp;


    if (list->end) {
        list->end->next = NULL;
        list->size--;
    } else {
        list->start = NULL;
    }

    return value;
}

node *get_node_next(node *node) {
    return node->next;
}

node *get_node_previous(node *node) {
    return node->previous;
}

void *get_node_value(node *node) {
	return node->value;
}
