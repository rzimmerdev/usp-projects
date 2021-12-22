#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// List type for storing total elements, starting and ending pointers
typedef struct LinkedList_t linked_list;

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
linked_list *create_list();

// Returns current value at circular header node pointer->value
void *view_header(linked_list *list);

// Sets current header node to next in list
void increment_header(linked_list *list);

// Frees header value and node, reconnecting list at created gap
void remove_header(linked_list *list, void (free_value)(void *value));

// Frees list node values, node pointers and list pointer
void free_list(linked_list *list, void (free_value)(void *value));

// Adds node to end of list, inserting value into node value pointer (First in is also first access)
void add_node(linked_list *list, void *value, int (compare)(void *first, void *second));

#endif //WORD_FREQUENCY_LIST_H