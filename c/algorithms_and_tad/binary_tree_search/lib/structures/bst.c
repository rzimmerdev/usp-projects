/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 28/11/2021
 *  Project for Algorithms and Data Structures I - SCC0202, "Exercício 10"
*/

#include <stdlib.h>

typedef struct Node_t {

    void *value;
    struct Node_t *child_l;
    struct Node_t *child_r;

} node;

/*
 *  Allocates memory for first node in tree (root)
 *
 *  @Return:
 *           empty node, with placeholder value
*/
node *create_tree() {
    node *tree = malloc(sizeof(node));
    tree->value = NULL;
    tree->child_l = NULL;
    tree->child_r = NULL;
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
    new_node->child_l = NULL;
    new_node->child_r = NULL;

    return new_node;
}

/*
 *  Inserts new node with input value into position in parent subtree, given
 *  binary search tree insertion logic, and using input comparison function:
 *  If value is bigger, insert into right subtree, if smaller, insert into left subtree.
 *  Recursive calls are made until position node is NULL, in which case new node is created
 *  containing value pointer.
 *
 *  @Input:
 *           subtree root to insert new value into: node *
 *           value to insert into new node: void *
 *           function to compare two node`s values: int (void *, void *)
 *
*/
void insert_node(node *parent, void *value, int (compare)(void *first, void *second)) {

    if (!parent->value) {
        parent->value = value;
    }

    else if (compare(value, parent->value)) {

        if (parent->child_l)
            insert_node(parent->child_l, value, compare);
        else
            parent->child_l = create_node(value);

    }

    else {

        if (parent->child_r)
            insert_node(parent->child_r, value, compare);
        else
            parent->child_r = create_node(value);
    }
}

/*
 *  Traverses parent subtree in order, corresponding to traversing left subtree, traversing
 *  parent, and traversing right subtree, recursively.
 *  Traversed node values are saved in order array, as well as setting current_step according
 *  to total nodes traversed.
 *
 *  @Input:
 *           subtree to traverse: node *,
 *           pointer to ordered array, containing value pointers: void ***,
 *           pointer to total_steps: int *
 *
*/
void in_order_traverse(node *parent, void ***order, int *current_step) {

    if (parent->child_l)
        in_order_traverse(parent->child_l, order, current_step);

    *current_step = *current_step + 1;
    *order = realloc(*order, *(current_step) * sizeof(void *));
    *(*order + *current_step - 1) = parent->value;

    if (parent->child_r)
        in_order_traverse(parent->child_r, order, current_step);
}

/*
 *  Traverses parent subtree in pre-order, corresponding to traversing current parent, then
 *  traversing left subtree and then right subtree recursively.
 *  Traversed node values are saved in order array, as well as setting current_step according
 *  to total nodes traversed.
 *
 *  @Input:
 *           subtree to traverse: node *,
 *           pointer to ordered array, containing value pointers: void ***,
 *           pointer to total_steps: int *
 *
*/
void pre_order_traverse(node *parent, void ***order, int *current_step) {

    *current_step = *current_step + 1;
    *order = realloc(*order, *(current_step) * sizeof(void *));
    *(*order + *current_step - 1) = parent->value;

    if (parent->child_l)
        pre_order_traverse(parent->child_l, order, current_step);

    if (parent->child_r)
        pre_order_traverse(parent->child_r, order, current_step);
}

/*
 *  Traverses parent subtree in post-order, corresponding to traversing left subtree,
 *  then right subtree and finally current parent recursively.
 *  Traversed node values are saved in order array, as well as setting current_step according
 *  to total nodes traversed.
 *
 *  @Input:
 *           subtree to traverse: node *,
 *           pointer to ordered array, containing value pointers: void ***,
 *           pointer to total_steps: int *
 *
*/
void post_order_traverse(node *parent, void ***order, int *current_step) {

    if (parent->child_l)
        post_order_traverse(parent->child_l, order, current_step);

    if (parent->child_r)
        post_order_traverse(parent->child_r, order, current_step);

    *current_step = *current_step + 1;
    *order = realloc(*order, *(current_step) * sizeof(void *));
    *(*order + *current_step - 1) = parent->value;
}
