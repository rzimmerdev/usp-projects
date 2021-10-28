#ifndef QUADTREE_QUAD_TREE_H
#define QUADTREE_QUAD_TREE_H

typedef struct _Tree tree;

// Function to create empty tree, that stores node value instead of id (thus, no need for adjacency list)
tree *create_tree(int value, int total_children);

// Frees each tree children recursively, then frees tree children array and current tree
void free_tree(tree *quadtree);

// Compresses greyscale matrix containing image pixels recursively, subdividing each image quadrant
// into a quadtree child branch if possible, and setting compressible values (each value in quadrant is repeated) to
// a new simple leaf
tree *grayscale_to_tree(int **greyscale, int height, int width, int y_offset, int x_offset);

// Prints tree node values and child node values in added order
void print_tree(tree *quad_tree);
#endif
