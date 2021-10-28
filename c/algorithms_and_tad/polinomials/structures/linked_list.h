#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct node Node_t;

// List type for storing total elements, starting and ending pointers
typedef struct LinkedList_t {

	int node_size;
	Node_t *start;
	Node_t *end;
	int size;

} linked_list;

// Returns size of defined struct
int sizeof_node();
int sizeof_linked_list();

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
linked_list *create_list();

// Returns total size of list
int get_size(linked_list *list);

// Frees list node values, node pointers and list pointer
void free_list(linked_list *list);

// Adds node to end of list, inserting value into node value pointer (First in is also first access)
void add_node(linked_list *list, void *value);

// Returns pointer to node value
void *get_node_value(Node_t *node);

// Returns pointer to next node
Node_t *get_node_next(Node_t *node);

// Returns starting node pointer in list
Node_t *get_start(linked_list *list);

#endif //WORD_FREQUENCY_LIST_H