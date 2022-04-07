/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 15/12/2021
 *
 *  Linked list structure for storing generic elements,
 *  specifically built to store in first-in, last-position order.
*/

#include <stdlib.h>

#include "linked_list.h"


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
linked_list *create_list(int (compare)(void *first, void *second)) {

	linked_list *list = (linked_list *) malloc(sizeof(linked_list));

	list->size    = 0;
	list->start   = NULL;
    list->compare = compare;

	return list;
}

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
node *find_node(linked_list *list, void *value) {

    node *current_node = list->start;

    while (current_node && list->compare(value, current_node->value) != 0) {

        current_node = current_node->next;
    }

    return current_node;
}

/*
 *  Allocates memory for new node with given value and inserts into start of linked list.
 *
 *  @Input:
 *           linked list to insert new value into: linked_list *,
 *           value to insert into new node: void *
*/
void add_node(linked_list *list, void *value) {

	list->size++;
	node *new_node  = (node *) malloc(sizeof(node));

    new_node->value = value;

    // If list is not empty, insert at start of list, connecting previous sequence to next pointer.
    if (list->start != NULL) {
        if (!find_node(list, value)) {

            new_node->next = list->start;
            list->start = new_node;
        } else {

            free(value);
            free(new_node);
        }
    }

    else {

        list->start = new_node;
        new_node->next = NULL;
    }
}

/*
 *  Frees node value and pointer, setting parent next as removed node next (reconnecting linked list).
 *
 *  @Input:
 *           linked list to remove node with value from: linked_list *,
 *           value to search node for: void *
*/
void remove_node(linked_list *list, void *value) {

    if (list->start == NULL)
        return;

    // If element to remove is at start, replace list start pointer.
    if (list->compare(value, list->start->value) == 0) {

        node *temp = list->start;
        list->start = list->start->next;

        free(temp->value);
        free(temp);

        list->size--;
    }

    // Else find correct parent of node to delete, as to maintain connection between next and previous elements
    // after removal of node.
    else {

        node *current = list->start;

        while (current->next && list->compare(value, current->next->value) != 0) {

            current = current->next;
        }

        node *temp = current->next;

        if (temp) {

            current->next = temp->next;
            free(temp->value);
            free(temp);
            list->size--;
        }
    }
}

/*
 *  Frees all node values and node pointers from linked list, as well as linked list pointer as well.
 *
 *  @Input:
 *           pointer to list being freed: linked_list *
*/
void free_list(linked_list *list) {

    node *current = list->start;

    // Free all nodes until end of list (NULL pointer).
    while (current) {

        node *temp = current;

        current = current->next;
        free(temp->value);
        free(temp);
    }

	free(list);
}