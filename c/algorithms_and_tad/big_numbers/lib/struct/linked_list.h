/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 02/11/2021
 *  Data structure for maintaining ordered list of numbers using linked nodes
*/

#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next node pointer, as well as void type value
typedef struct Node_t node;

// Linked List type for storing total elements, starting and ending pointers
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
linked_list *create_list();

/*
 *  Adds node with given value to end of linked list, incrementing node count
 *
 *  @Input:
 *          linked list pointer
 *          pointer to set as node value: void *value
 */
void add_node(linked_list *list, void *value);

/*
 *  Frees list node values using free_function, node pointers and list pointer
 *
 *  @Input:
 *          linked list pointer
 *          function to free node value: void *free_function
 */
void free_list(linked_list *list, void (*free_function)(void *));

/*
 *  Remove linked list last node and return its value
 *
 *  @Input:
 *          linked list pointer
 *  @Return:
 *          pointer to value used to initialize node: void *
 */
void *pop_end(linked_list *list);

// Basic get functions to return struct value pointers without direct access to struct typedef
void *get_node_value(node *node);
node *get_node_next(node *node);
node *get_node_previous(node *node);

#endif //WORD_FREQUENCY_LIST_H