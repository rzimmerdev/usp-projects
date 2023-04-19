/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 15/12/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Trabalho 04: Tabela Hash"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/structures/hash_table.h"
#include "lib/tools/string_scan.h"

// Function to insert into linked lists structs to compare two generic void pointers cast to strings
int compare(void *first, void *second) {

    if (!second)
        return 1;

    return strcmp((char *) first, (char *) second);
}


int main() {


    int hash_table_size, total_instructions;
    scanf("%d\n%d ", &hash_table_size, &total_instructions);

    hash_table *table = create_table(hash_table_size, compare);

    while (total_instructions-- > 0) {

        int current_size;
        char *current_operation = scan_word(&current_size);

        if (strcmp(current_operation, "add") == 0) {

            char *to_add = (char *) scan_word();
            add_value(table, to_add);
        }

        else if (strcmp(current_operation, "del") == 0) {

            char *to_remove = (char *) scan_word();

            remove_value(table, to_remove);
            free(to_remove);
        }

        else if (strcmp(current_operation, "get") == 0) {

            int index;
            scanf("%d ", &index);

            node *current_node = table->lists[index]->start;

            while (current_node) {
                printf("%s ", (char *) current_node->value);
                current_node = current_node->next;
            } printf("\n");
        }

        else if (strcmp(current_operation, "check") == 0) {

            char *to_find = (char *) scan_word();

            printf("%s\n", find_value(table, to_find) ? "sim" : "não");
            free(to_find);
       }

        free(current_operation);
    }

    free_table(table);

    return 0;
}