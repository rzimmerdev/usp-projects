#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct node Node_t;

// List type for storing total elements, starting and ending pointers
typedef struct linked_list LinkedList_t;

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
LinkedList_t *create_linked_list();

// Returns total size of list
int linked_list_size(LinkedList_t *list);

// Frees list node values, node pointers and list pointer
void free_list(LinkedList_t *list);

// Adds node to end of list, inserting value into node value pointer (First in is also first access)
void add_node(LinkedList_t *list, void *value);

// Returns pointer to node value
void *get_node_value(Node_t *node);

Node_t *next_node(Node_t *node);

// Searches node starting from list start until depth is reached or depth exceeds total list size (First in is also first access)
Node_t *search_node(LinkedList_t *list, int depth);

#endif //WORD_FREQUENCY_LIST_H