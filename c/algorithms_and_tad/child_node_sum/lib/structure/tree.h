//
// Created by rzimmerdev on 28/11/2021.
//

#ifndef USP_PROJECTS_TREE_H
#define USP_PROJECTS_TREE_H

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
node *create_tree();

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
node *create_node(void *value);

/*
 *  Sets rightmost child of parent node to given child node, inserting into parent child pointer,
 *  or child sibling pointer
 *
 *  @Input:
 *           parent node, with child reference to set or iterate over: node *,
 *           child node to substitute NULL reference: node *
*/
void append_child(node *parent, void *value);

#endif //USP_PROJECTS_TREE_H
