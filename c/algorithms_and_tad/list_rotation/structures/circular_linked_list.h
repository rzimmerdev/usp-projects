#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

// Node type for storing next and previous node pointers, as well as void pointer value
typedef struct node Node_t;

// List type for storing total elements, starting and ending pointers
typedef struct linked_list CircularLinkedList_t;

// Allocate memory for linked list variable, initializing size to 0 and start and end elements to NULL
CircularLinkedList_t *create_list();

// Returns total size of list
int get_size(CircularLinkedList_t *list);

// Adds node to end of list, inserting value into node value pointer, as well as setting
// node previous value to list end and node next value to list start (thus creating a bidirectional circular linked list)
void add_node(CircularLinkedList_t *list, void *value);

// Right shift list, setting values of node start and end to respective previous nodes
void shift_list(CircularLinkedList_t *list);

// Returns list start pointer
Node_t *get_list_start(CircularLinkedList_t *list);

// Returns node next pointer
Node_t *get_next_node(Node_t *node);

// Returns pointer to node value
void *get_node_value(Node_t *node);

// Frees list node values, node pointers and list pointer
void free_list(CircularLinkedList_t *list);

#endif