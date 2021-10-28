#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct node Node_t;

// List type for storing total elements, as well as total size and start pointer
typedef struct linked_list OrderedLinkedList_t;

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
OrderedLinkedList_t *create_list();

// Returns total size of list
int get_size(OrderedLinkedList_t *list);

// Frees list node values, node pointers, as well as applies function to free any node
// value variables stored inside value void pointer
// Also frees list pointer
void free_list(OrderedLinkedList_t *list, void (*free_node)(Node_t *to_free));

// Adds node to respective ordered position in list, based on input order function,
// by setting parent pointer to new node, as well as setting node value to input value
void add_node(OrderedLinkedList_t *list, void *value, int (*get_order)(Node_t *next, Node_t *to_insert));

// Removes node based on node index inside list, as well as refitting list to maintain order and
// to skip removed node
void remove_node(OrderedLinkedList_t *list, int index);

// Returns pointer to list start node
Node_t *get_list_start(OrderedLinkedList_t *list);

// Returns pointer to node value
void *get_node_value(Node_t *node);

// Returns node next pointer
Node_t *get_node_next(Node_t *node);

#endif //WORD_FREQUENCY_LIST_H