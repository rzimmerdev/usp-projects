/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 28/11/2021
 *  Project for Algorithms and Data Structures I - SCC0202, "Exercício 10"
*/

#include <stdlib.h>
#include "queue.h"

typedef struct Node_t {

    void *value;
    void *priority;
    struct Node_t *child_l;
    struct Node_t *child_r;

} node;

/*
 *  Allocates memory for first node in tree (tree)
 *
 *  @Return:
 *           empty node, with placeholder value
*/
node *create_tree() {
    node *tree = malloc(sizeof(node));
    tree->value = NULL;
    tree->priority = NULL;
    tree->child_l = NULL;
    tree->child_r = NULL;
    return tree;
}

void free_tree(node *tree) {
    if (tree->child_l) {
        free_tree(tree->child_l);
    }

    if (tree->child_r) {
        free_tree(tree->child_r);
    }

    free(tree->value);
    free(tree->priority);
    free(tree);
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
node *create_node(void *value, void *priority) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->priority = priority;
    new_node->child_l = NULL;
    new_node->child_r = NULL;

    return new_node;
}


void free_node(node *parent, int left_child) {

    if (left_child) {
        free(parent->child_l->value);
        free(parent->child_l->priority);

        free(parent->child_l);
        parent->child_l = NULL;
    }
    else {
        free(parent->child_r->value);
        free(parent->child_r->priority);
        free(parent->child_r);
        parent->child_r = NULL;
    }
}

// Rotates parent element to right, preserving reference and changing next root (right child) and previous
// values, instead of changing all reference pointers
void rotate_right(node *parent) {

    node *new_parent = parent->child_l;

    void *temp_value = new_parent->value;
    void *temp_priority = new_parent->priority;

    parent->child_l = new_parent->child_l;

    new_parent->child_l = new_parent->child_r;
    new_parent->child_r = parent->child_r;

    parent->child_r = new_parent;

    new_parent->value = parent->value;
    new_parent->priority = parent->priority;

    parent->value = temp_value;
    parent->priority = temp_priority;
}

// Rotates parent element to left, preserving reference and changing next root (left child) and previous
// values, instead of changing all reference pointers
void rotate_left(node *parent) {

    node *new_parent = parent->child_r;

    void *temp_value = new_parent->value;
    void *temp_priority = new_parent->priority;

    parent->child_r = new_parent->child_r;

    new_parent->child_r = new_parent->child_l;
    new_parent->child_l = parent->child_l;

    parent->child_l = new_parent;

    new_parent->value = parent->value;
    new_parent->priority = parent->priority;

    parent->value = temp_value;
    parent->priority = temp_priority;
}

// Returns existing or new node correct parent, as to allow for new insertions or already
// existing node deletions
node *find_parent(node *parent, void *value, int (compare)(void *first, void *second)) {
    if (compare(value, parent->value) == 0)
        return parent;

    else if (compare(value, parent->value) < 0) {

        if (!parent->child_l) {
            return parent;
        }
        else {
            if (compare(value, parent->child_l->value) == 0) {
                return parent;
            } else {
                return find_parent(parent->child_l, value, compare);
            }
        }
    }

    else {

        if (!parent->child_r) {
            return parent;
        } else {
            if (compare(value, parent->child_r->value) == 0) {
                return parent;
            } else {
                return find_parent(parent->child_r, value, compare);
            }
        }
    }
}

// Returns 1 if value is already in tree, or 0 if not
// traversing tree in O(log(n))
int is_in_tree(node *tree, void *value, int (compare)(void *, void *)) {

    node *parent = find_parent(tree, value, compare);

    if (compare(value, parent->value) == 0)
        return 1;
    else {
        if (parent->child_l && compare(value, parent->child_l->value) == 0)
            return 1;
        else if (parent->child_r && compare(value, parent->child_r->value) == 0)
            return 1;
    }

    return 0;
}


/*
 *  Inserts new node with input value into position in parent subtree, given
 *  binary search tree insertion logic, and using input comparison function:
 *  If value is bigger, insert into right subtree, if smaller, insert into left subtree.
 *  Recursive calls are made until position node is NULL or repeated, in which case new node is created
 *  containing value pointer or -1, error, is returned.
 *
 *  @Input:
 *           tree to insert new value into: node *
 *           value to insert into new node: void *
 *           function to compare two node`s values: int (void *, void *)
 *
*/
int insert_node(node *parent, void *value, void *priority, int (compare)(void *first, void *second)) {

    int status = 1;

    if (!parent || !parent->value) {
        parent->value = value;
        parent->priority = priority;
        status = 0;
    }

    if (compare(value, parent->value) < 0) {

        if (parent->child_l)
            status = insert_node(parent->child_l, value, priority, compare);
        else {
            parent->child_l = create_node(value, priority);
            status = 0;
        }

        if (compare(parent->priority, parent->child_l->priority) < 0)
            rotate_right(parent);
    }
    else if (compare(value, parent->value) > 0) {

        if (parent->child_r)
            status = insert_node(parent->child_r, value, priority, compare);
        else {
            parent->child_r = create_node(value, priority);
            status = 0;
        }

        if (compare(parent->priority, parent->child_r->priority) < 0)
            rotate_left(parent);
    }

    return status;
}

// Removes node from tree, using max-heap property to move node to end of tree, without nesting leaves,
// then delete and null reference.
int remove_node(node *parent, void *value, int (compare)(void *first, void *second), void (set_min)(void *)) {

    int status = 1;
    node *current_node = NULL;

    if (compare(value, parent->value) == 0) {
        current_node = parent;

    }
    else {
        parent = find_parent(parent, value, compare);

        status = 0;
        if (parent->child_l && compare(value, parent->child_l->value) == 0)
            current_node = parent->child_l;
        else if (parent->child_r && compare(value, parent->child_r->value) == 0)
            current_node = parent->child_r;
        else return 1;
    }

    if (current_node)
        set_min(current_node->priority);

    while (current_node && (current_node->child_l || current_node->child_r)) {

        if (current_node->child_r) {
            rotate_left(current_node);
            parent = current_node;
            current_node = current_node->child_l;
        }
        else {
            rotate_right(current_node);
            parent = current_node;
            current_node = current_node->child_r;
        }
    }

    if (current_node) {
        free_node(parent, parent->child_l == current_node);
        return 0;
    }


    return status;

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
void in_order_traverse(node *parent, node ***order, int *current_step) {

    if (parent->child_l)
        in_order_traverse(parent->child_l, order, current_step);

    *current_step = *current_step + 1;
    *order = realloc(*order, *(current_step) * sizeof(node *));
    (*order)[*current_step - 1] = parent;

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
    *order = realloc(*order, *(current_step) * sizeof(node *));
    (*order)[*current_step - 1] = parent;

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
    *order = realloc(*order, *(current_step) * sizeof(node *));
    (*order)[*current_step - 1] = parent;
}


void breadth_first_traverse(node *parent, void ***order, int *current_step) {

    queue *levels = create_queue();

    if (parent)
        insert_queue(levels, parent);

    while(get_size(levels)) {

        node *current_node = pop_queue(levels);

        *current_step = *current_step + 1;
        *order = realloc(*order, *(current_step) * sizeof(node *));
        (*order)[*current_step - 1] = current_node;


        if (current_node->child_l)
            insert_queue(levels, current_node->child_l);
        if (current_node->child_r)
            insert_queue(levels, current_node->child_r);
    }

    free(levels);
}