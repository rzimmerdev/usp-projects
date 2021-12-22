/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 10/11/2021
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libraries/tools/string_tools.h"
#include "libraries/structures/skip_list.h"
#include "dictionary.h"

int main() {
    srand(time(NULL));

    skip_list *dictionary = create_dictionary();

    char *operation;

    // Scan operation per line and execute respective dictionary function, as
    // well as scanning each required values for each operation
    while ((operation = scan_word())[0] != '\0') {

        if (strcmp(operation, "insercao") == 0) {

            char *word = scan_word();
            char *description = scan_line();

            int out = add_entry(dictionary, word, description);

            if (out == -1) {
                free(word);
                free(description);
                printf("OPERACAO INVALIDA\n");
            }
        }

        else if (strcmp(operation, "alteracao") == 0) {

            char *word = scan_word();
            char *new_description = scan_line();

            int out = replace_description(dictionary, word, new_description);
            if (out == -1) {
                free(new_description);
                printf("OPERACAO INVALIDA\n");
            }
            free(word);

        }

        else if (strcmp(operation, "remocao") == 0) {

            char *word = scan_word();
            int out = remove_entry(dictionary, word);

            if (out == -1) {
                printf("OPERACAO INVALIDA\n");
            }
            free(word);

        }

        else if (strcmp(operation, "busca") == 0) {

            char *word = scan_word();
            char *description = get_description(dictionary, word);
            if (description) {
                printf("%s %s\n", word, description);
            } else {
                printf("OPERACAO INVALIDA\n");
            }
            free(word);
        }

        else if (strcmp(operation, "impressao") == 0) {

            char *prefix = scan_word();

            int out = print_entries(dictionary, prefix);

            if (out == -1) {
                printf("NAO HA PALAVRAS INICIADAS POR %s\n", prefix);
            }

            free(prefix);
        }

        else { printf("OPERACAO INVALIDA\n"); }

        free(operation);
    }

    free_list(dictionary);

    return 0;
}