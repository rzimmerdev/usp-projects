/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 15/12/2021
 *
 *  Linked list structure for storing generic elements,
 *  specifically built to store in first-in, last-position order.
*/

#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// Node type for storing next pointer, as well as void type values
typedef struct Node_t {
    void *value;
    struct Node_t *next;
} node;


typedef struct LinkedList_t {

    node *start;
    int size;

    int (*compare)(void *first, void *second);

} linked_list;


/*
 *  Allocates memory for linked list pointer, as well as populating NULL values into
 *  struct values. Saves element comparison function for operations on list.
 *
 *  @Input:
 *           function to return comparison between two void values: int (void *, void *)
 *
 *  @Return:
 *           pointer to allocated list: linked_list *
*/
linked_list *create_list(int (compare)(void *first, void *second));


/*
 *  Returns node element with given value inside linked list.
 *
 *  @Input:
 *           linked list to search value in: linked_list *,
 *           value to compare to node values: void *
 *
 *  @Return:
 *           node pointer with given value or NULL if value was not found: node *
*/
node *find_node(linked_list *list, void *value);


/*
 *  Allocates memory for new node with given value and inserts into start of linked list.
 *
 *  @Input:
 *           linked list to insert new value into: linked_list *,
 *           value to insert into new node: void *
*/
void add_node(linked_list *list, void *value);


/*
 *  Frees node value and pointer, setting parent next as removed node next (reconnecting linked list).
 *
 *  @Input:
 *           linked list to remove node with value from: linked_list *,
 *           value to search node for: void *
*/
void remove_node(linked_list *list, void *value);


/*
 *  Frees all node values and node pointers from linked list, as well as linked list pointer as well.
 *
 *  @Input:
 *           pointer to list being freed: linked_list *
*/
void free_list(linked_list *list);

#endif