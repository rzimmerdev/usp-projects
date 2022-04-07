/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 21/11/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Exercício 03: Lista Indexada em Lista Encadeada"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lib/structures/linked_list.h"
#include "lib/tools/string_tools.h"

// Enumerator for switching current loop operation
enum Operations {
    EXIT,
    READ,
    CREATE_INDEXES,
    SEARCH,
};

/*
 *  Casts void pointer to string, as to compare first character in both strings.
 *
 *  @Input:
 *            pointer to first and second strings: void *
 *
 *  @Returns:
 *            1 if first char in first is smaller or equal to first char in second or if second is null
 *            0 if bigger
*/
int compare_first_char(void *first, void *second);

/*
 *  Returns position in alphabet (char - 'a') of first char from value casted to string.
 *
 *  @Input:
 *            void value containing string value: void *
 *
 *  @Returns:
 *            first char of value position in alphabet: int (0, 25)
*/
int get_string_index(void *value);

/*
 *  Reads multiple words from file, given input_file name, separated by '\n' or ' ' char`s.
 *  Inserts each read word into correct position in list.
 *
 *  @Input:
 *           pointer to list: linked_list *,
 *           input file name: char *
*/
void fread_linked_list(linked_list *list, char *input_file);

/*
 *  Returns node array with total_possible_indexes elements, referent to each index that
 *  can be returned from get_index function, given node value from linked list.
 *  Also counts total !null values in returned array using non_empty pointer.
 *
 *  @Input:
 *           pointer to list with elements to be indexed: linked_list *,
 *           pointer to count of valid indexes: int *,
 *           function to index value stored in linked_list nodes: int (void *),
 *           amount of nodes to allocate memory for: int
 *
 *  @Return:
 *           array of node pointers corresponding to firstly indexed values of list: node **
*/
node **get_index_pointers(linked_list *list, int *non_empty, int (get_index)(void *), int total_possible_indexes);

/*
 *  Return total steps taken to find string in linked_list, given firstly indexed values inside
 *  array of node pointers
 *
 *  @Input:
 *           indexed node pointers respective to nodes linked_list: node **
 *           string to find inside linked_list: char *
 *
 *  @Return:
 *           total steps taken until reaching node with value, starting at indexed node: int,
 *           -1 if value was not found
*/
int find_total_steps(node **indexes, char *value);

int main() {

    int current_operation;

    node **indexes;
    bool is_indexes_updated = false;
    linked_list *list = create_list();

    do {
        scanf("%d ", &current_operation);
        switch (current_operation) {
            case (READ): {

                char *input_file = scan_word();

                fread_linked_list(list, input_file);

                free(input_file);
                is_indexes_updated = false;

                break;
            }

            case (CREATE_INDEXES): {

                // Update indexed nodes array if any new values have been inserted
                int non_empty_indexes = 0;
                if (is_indexes_updated) {
                    free(indexes);
                }

                indexes = get_index_pointers(list, &non_empty_indexes, get_string_index, 26);
                printf("%d\n", non_empty_indexes);

                is_indexes_updated = true;
                break;
            }

            case (SEARCH): {

                char *to_find = scan_word();

                if (is_indexes_updated) {
                    int total_steps = find_total_steps(indexes, to_find);
                    if (total_steps == -1)
                        printf("Palavra nao existe na lista.\n");
                    else
                        printf("%d\n", total_steps);

                } else {
                    printf("Vetor de indices nao atualizado.\n");
                }

                free(to_find);

                break;
            }

            case (EXIT): {

                free(indexes);
                free_list(list, free);
            }
        }

    } while (current_operation != 0);

    return 0;
}

int compare_first_char(void *first, void *second) {
    return second ? ((char *) first)[0] <= ((char *) second)[0] : 1;
}

int get_string_index(void *value) {
    return (char) (((char *) value)[0] - 'a');
}

void fread_linked_list(linked_list *list, char *input_file) {
    FILE *file_pointer = fopen(input_file, "r");

    char *word;
    while ((word = file_scan_word(file_pointer)) && word[0] != '\0') {
        add_node(list, word, compare_first_char);
    }

    node *current = list->start;
    for (int i = 0; i < 3; i++) {
        if (current) {
            printf("%s\n", (char *) get_value(current));
            current = get_next(current);
        }
    }

    fclose(file_pointer);
}

node **get_index_pointers(linked_list *list, int *non_empty, int (get_index)(void *), int total_possible_indexes) {

    node **indexes = calloc(total_possible_indexes, sizeof(char *));

    node *current = list->start;

    // While next node value is not NULL (end of list), continue to decide if new index should be added
    while (current) {

        int current_index = get_index(get_value(current));

        // If index has not yet been filled, set value to node pointer
        // This makes it so, that each index in resulting node pointers array is the first apparition
        // of value in linked list
        if (indexes[current_index] == NULL) {
            indexes[current_index] = current;
            (*non_empty)++;
        }

        current = get_next(current);
    }

    return indexes;
}

int find_total_steps(node **indexes, char *value) {

    int value_index = get_string_index(value);

    if (indexes[value_index]) {

        int total_steps = 0;
        node *current = indexes[value_index];

        while (current && value[0] == ((char *) get_value(current))[0] && strcmp(value, (char *) get_value(current)) != 0) {
            total_steps++;
            current = get_next(current);
        }

        // If found value is not equal to value to be found,
        // list end has been reached, while value was not found,
        // thus returning -1
        if (strcmp(value, (char *) get_value(current)) == 0)
            return total_steps;

    }

    return -1;
}