/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 29/11/2021
 *  Project for Algorithms and Data Structures I - SCC0202, "Exercício 11"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/structures/bst.h"
#include "lib/tools/string_scan.h"

/*
 *  Compares two void pointers read from node values, casting values to int.
 *
 *  @Input:
 *           current value to compare: void *,
 *           second value to compare: void *
 *
 *  @Return:
 *           1 if first value is smaller,
 *           0 if first value is bigger or equal
*/
int compare_nodes(void *first, void *second);

int main() {

    int total_nodes = 0;

    scanf("%d ", &total_nodes);

    node *tree = create_tree();

    char *current_operation;

    int at_end = 0;

    do {
        current_operation = scan_word();

        if (strcmp(current_operation, "insercao") == 0) {
            int *value = malloc(sizeof(int));
            scanf("%d", value);
            insert_node(tree, value, compare_nodes);
        }
        else if (strcmp(current_operation, "impressao") == 0 && !tree->value) {


            char *order_type = scan_word();
            free(order_type);

            printf("VAZIA\n");
        }

        else {

            char *order_type = scan_word();

            int total_values = 0;
            void **order = malloc(0 * sizeof(node *));

            if (strcmp(order_type, "em-ordem") == 0) {

                in_order_traverse(tree, &order, &total_values);
            }

            else if (strcmp(order_type, "pre-ordem") == 0) {

                pre_order_traverse(tree, &order, &total_values);
            }

            else if (strcmp(order_type, "pos-ordem") == 0) {

                post_order_traverse(tree, &order, &total_values);
            }

            for (int i = 0; i < total_values; i++) {
                printf("%d ", *(int *) *(order + i));
            } printf("\n");

            free(order);
            free(order_type);
        }

        at_end = scanf("%*d");

    } while (at_end != -1);
}

int compare_nodes(void *first, void *second) {

    return *(int *) first < *(int *) second;
}
