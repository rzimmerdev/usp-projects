/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 21/11/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Trabalho 03: Simulador de Escalonador"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/structures/treap.h"
#include "lib/tools/string_scan.h"

// Set INT_MIN to delete node using max heap property.
int INT_MIN = -2147483647;


void set_min(void *value) {
    *(int *) value = INT_MIN;
}


int compare(void *first, void *second);


int main() {

    int total_operations;
    scanf("%d ", &total_operations);

    char *current_operation;

    node *tree = create_tree();

    while (total_operations-- > 0) {

        current_operation = scan_word();

        if (strcmp(current_operation, "insercao") == 0) {

            int *value = malloc( sizeof(int) );
            int *priority = malloc( sizeof(int) );

            scanf("%d %d ", value, priority);
            int status = insert_node(tree, value, priority, compare);
            if (status == 1) {
                printf("Elemento ja existente\n");
                free(value);
                free(priority);
            }
        }

        else if (strcmp(current_operation, "impressao") == 0) {

            // Save ordered tree traversal in node array, as to print in correct order
            char *order_type = scan_word();

            int total_values = 0;
            node **order = malloc(0 * sizeof(node *));

            if (strcmp(order_type, "ordem") == 0) {
                in_order_traverse(tree, &order, &total_values);
            }

            else if (strcmp(order_type, "posordem") == 0) {
                post_order_traverse(tree, &order, &total_values);
            }

            else if (strcmp(order_type, "preordem") == 0) {
                pre_order_traverse(tree, &order, &total_values);
            }

            else if (strcmp(order_type, "largura") == 0) {
                breadth_first_traverse(tree, &order, &total_values);
            }

            for (int i = 0; i < total_values; i++) {
                printf("(%d, %d) ", *(int *) order[i]->value, *(int *) order[i]->priority);
            } printf("\n");

            free(order);
            free(order_type);
        }

        else if (strcmp(current_operation, "remocao") == 0) {
            int *value = malloc(sizeof(int));
            scanf("%d ", value);

            int status = remove_node(tree, value, compare, set_min);

            if (status == 1)
                printf("Chave nao localizada\n");

            free(value);
        }

        else if (strcmp(current_operation, "buscar") == 0) {
            int *value = malloc(sizeof(int));
            scanf("%d ", value);

            printf("%d\n", is_in_tree(tree, value, compare));

            free(value);
        }

        free(current_operation);
    }

    free_tree(tree);

    return 0;
}


int compare(void *first, void *second) {
    if (*(int *) first == *(int *) second)
        return 0;
    return (*(int *) first > *(int *) second) * 2 -1;
}
