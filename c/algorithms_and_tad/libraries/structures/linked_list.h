#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct Node_t node;

// List type for storing total elements, starting and ending pointers
typedef struct LinkedList_t linked_list;

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
linked_list *create_list();

// Returns total size of list
int get_size(linked_list *list);

// Frees list node values, node pointers and list pointer
void free_list(linked_list *list);

// Adds node to end of list, inserting value into node value pointer (First in is also first access)
void add_node(linked_list *list, void *value);

// Returns pointer to node value
void *get_node_value(node *node);

// Searches node starting from list start until depth is reached or depth exceeds total list size (First in is also first access)
node *search_node(linked_list *list, int depth);

#endif //WORD_FREQUENCY_LIST_H