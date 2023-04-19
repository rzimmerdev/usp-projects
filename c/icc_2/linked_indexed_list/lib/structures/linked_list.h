#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct Node_t node;

// List type for storing total elements, starting and ending pointers
typedef struct LinkedList_t {
    node *start;
    int size;

} linked_list;

// Allocate memory for linked list variable, initializing size to 0 and elements to NULL
linked_list *create_list();

// Returns total size of list
int get_size(linked_list *list);

node *search_node(linked_list *list, void *value, int (is_equal)(void *first, void *second));

// Frees list node values, node pointers and list pointer
void free_list(linked_list *list, void (free_value)(void *));

// Adds node to end of list, inserting value into node value pointer (First in is also first access)
void add_node(linked_list *list, void *value, int (compare)(void *first, void *second));

// Returns pointer to node value
void *get_value(node *node);

node *get_next(node *current_node);

#endif //WORD_FREQUENCY_LIST_H