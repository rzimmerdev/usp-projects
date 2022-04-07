/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 02/11/2021
 *  Project for Algorithms and Data Structures - SCC0202, "Atividade 09: Grandes Números"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/struct/linked_list.h"
#include "big_numbers.h"

int main() {

    int total_cases;
    scanf("%d ", &total_cases);

    for (int i = 0; i < total_cases; i++) {

        // Scan operator and decide which big number operation to perform
        char current_operation[4];
        scanf("%3s", current_operation);
        current_operation[3] = '\0'; getchar();

        // Scan big numbers and store into linked_list from stdin
        linked_list *first_number = scan_big_number();
        linked_list *second_number = scan_big_number();

        if (strcmp(current_operation, "SUM") == 0) {
            linked_list *result = sum_numbers(first_number, second_number);
            print_number(result);
            free_list(result, free);
        }

        else if (strcmp(current_operation, "BIG") == 0) {
            printf("%d\n", (compare_big_number(first_number, second_number) + 1)/2);

        }

        else if (strcmp(current_operation, "SML") == 0) {
            printf("%d\n", (compare_big_number(second_number, first_number) + 1)/2);

        }

        else if (strcmp(current_operation, "EQL") == 0) {

            printf("%d\n", compare_big_number(first_number, second_number) == 0);
        }

        free_list(first_number, free);
        free_list(second_number, free);

    }

    return 0;
}