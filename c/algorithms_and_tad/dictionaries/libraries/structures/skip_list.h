/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 02/10/2021
 *  Advanced Data Structure library for creating Skip Lists with generic attributes
*/

#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

typedef struct QuadNode quad_node;
typedef struct SkipList skip_list;

/*
 *  Allocates and defines starting values for skip list
 *
 *  @Input:
 *         value to represent minus infinity character: void *,
 *         generic function to compare two values: int *,
 *         generic function to free value: void *
 *  @Returns:
 *         pointer to skip_list
*/
skip_list *create_sl(void *minus_infinity, int (*compare)(void *, void *), void (*remove)(void *));

/*
 *  Frees each column values and quad_nodes inside skip list
 *
 *  @Input:
 *         skip_list *
*/
void free_list(skip_list *list);

/*
 *  Uses skip_list higher levels to compare placeholder value with list values
 *  and return value or most close (rounded down) value
 *
 *  @Input:
 *         skip_list *,
 *         pointer to value to search for: void *
 *  @Returns:
 *         quad node containing value searched for
*/
quad_node *find_node(skip_list *list, void *value);

/*
 *  Returns vertical path followed to find specific placeholder value or most close (rounded down) value
 *
 *  @Input:
 *         skip_list *,
 *         pointer to value to search for: void *
 *  @Returns:
 *         pointer to quad node array containing all vertically traversed nodes
*/
quad_node **find_levels(skip_list *list, void *value);

// Get functions for quad_node values
void *get_value(quad_node *node);
quad_node *get_next(quad_node *node);
quad_node *get_previous(quad_node *node);

/*
 *  Inserts new quad_node with input value into ordered position in skip_list,
 *  and creates nodes on top according to defined 0.5 probability, to avoid
 *  worst case search scenario
 *
 *  @Input:
 *         skip_list *,
 *         pointer to value to insert: void *
 *  @Returns:
 *         operation output: 1 if success, -1 if error
*/
int add_node(skip_list *list, void *value);

/*
 *  Removes node and nodes on top with given value, as well as connecting neighbours
 *  in skip list, using node_find function
 *
 *  @Input:
 *         skip_list *,
 *         pointer to placeholder value to remove: void *
 *  @Returns:
 *         operation output: 1 if success, -1 if error
*/
int remove_node(skip_list *list, void *value);

#endif //WORD_FREQUENCY_LIST_H