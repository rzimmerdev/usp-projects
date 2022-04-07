/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 28/11/2021
 *  Project for Algorithms and Data Structures I - SCC0202, "Exercício 10"
*/

#include <stdlib.h>

typedef struct Node_t {

    void *value;
    struct Node_t *child;
    struct Node_t *sibling_r;

} node;

/*
 *  Allocates tree node to store child as tree root.
 *
 *  @Return:
 *           empty node, with placeholder child (tree root): node *
*/
node *create_tree() {
    node *tree = malloc(sizeof(node));
    tree->value = NULL;
    tree->child = NULL; //Tree Root
    tree->sibling_r = NULL;
    return tree;
}

/*
 *  Allocates memory for new node, setting node value to input value,
 *  and sets empty values to reference pointers.
 *
 *  @Input:
 *           value to insert into node: void *
 *
 *  @Return:
 *           node pointer with defined values: node *
*/
node *create_node(void *value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->child = NULL;
    new_node->sibling_r = NULL;

    return new_node;
}

/*
 *  Sets rightmost child of parent node to given child node, inserting into parent child pointer,
 *  or child sibling pointer
 *
 *  @Input:
 *           parent node, with child reference to set or iterate over: node *,
 *           child node to substitute NULL reference: node *
*/
void append_child(node *parent, node *child) {

    if (parent->child) {

        node *current_sibling = parent->child;

        while (current_sibling->sibling_r)
            current_sibling = current_sibling->sibling_r;

        current_sibling->sibling_r = child;

    }

    else
        parent->child = child;
}