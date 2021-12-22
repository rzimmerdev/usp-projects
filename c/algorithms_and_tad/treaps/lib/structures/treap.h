//
// Created by rzimmerdev on 28/11/2021.
//

#ifndef USP_PROJECTS_TREAP_H
#define USP_PROJECTS_TREAP_H


typedef struct Node_t {

    void *value;
    void *priority;
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


void free_tree(node *tree);


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
node *create_node(void *value, void *priority);


int is_in_tree(node *tree, void *value, int (compare)(void *, void *));


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
int insert_node(node *tree, void *value, void *priority, int (compare)(void *first, void *second));


int remove_node(node *tree, void *value, int (compare)(void *first, void *second), void (set_min)(void *));

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
void in_order_traverse(node *parent, node ***order, int *current_step);


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
void pre_order_traverse(node *parent, node ***order, int *current_step);


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
void post_order_traverse(node *parent, node ***order, int *current_step);


void breadth_first_traverse(node *parent, node ***order, int *current_step);

#endif //USP_PROJECTS_TREAP_H
