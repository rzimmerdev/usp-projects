/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 28/11/2021
 *  Project for Algorithms and Data Structures I - SCC0202, "Exercício 10"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/structure/tree.h"

/*
 *  Scans tree from stdin and appends all scanned sub nodes to input parent.
 *  Recursive iteration allows construction of full binary tree
 *
 *  @Input:
 *            node to append subtree to: node *
 *
*/
void scan_subtree(node *parent);

/*
 *  Iterate recursively over child nodes, comparing sum of child values with parent value
 *  Compares each parent value to the sum of values from all children
 *
 *  @Input:
 *            tree node to start recursive chain: node *,
 *
 *  @Return:
 *            1 if all parent values are equal to sum of children values
 *            0 if any is not equal
*/
bool compare_tree_nodes(node *root);

int main() {

    int total_nodes = 0;

    scanf("%d ", &total_nodes);

    node *tree = create_tree();
    scan_subtree(tree);

    node *root = tree->child;
    printf("%s\n", compare_tree_nodes(root) ? "VERDADEIRO" : "FALSO");
}

void scan_subtree(node *parent) {

    int current_id, child_l_id, child_r_id;
    int *current_value = malloc(sizeof(int));

    scanf("%d %d %d %d ", &current_id, current_value, &child_l_id, &child_r_id);

    node *current_node = create_node(current_value);

    // See if current node has left or right children, and if true
    // scan next line, corresponding to left and/or right child in order
    if (child_l_id != -1) {
        scan_subtree(current_node);
    }
    if (child_r_id != -1) {
        scan_subtree(current_node);
    }

    // At end of recursive chain, add current node as child of input parent node
    append_child(parent, current_node);
}

bool compare_tree_nodes(node *current_node) {

    bool result = false;

    node *current_child = current_node->child;

    // If current node has children, calculate sum of values
    if (current_child) {

        result = compare_tree_nodes(current_child);

        if (current_child->sibling_r)
            result = result && compare_tree_nodes(current_child->sibling_r);

        // If recursive call to children is false, no need to calculate further, as result should
        // definitely be 0
        if (result) {
            int sum = 0;
            while (current_child) {
                sum += *(int *) current_child->value;
                current_child = current_child->sibling_r;
            }

            if (sum != *(int *) current_node->value) {
                return false;
            }
        }
    }

    // Else, return true, as current node has no children to compare to
    else
        return true;

    return result;
}
