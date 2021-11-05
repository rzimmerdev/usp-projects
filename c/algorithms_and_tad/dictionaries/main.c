/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021, 13:18
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraries/tools/string_tools.h"
#include "libraries/structures/skip_list.h"
#include "dictionary.h"

int main() {
    srand(42);

    skip_list *dictionary = create_dictionary();

    char *operation;

    while ((operation = scan_word())[0] != '\0') {

        /*printf("%s\n", operation);*/

        if (strcmp(operation, "insercao") == 0) {

            char *word = scan_word();
            char *description = scan_line();

            int out = add_entry(dictionary, word, description);

            if (out == -1) {
                printf("OPERACAO INVALIDA\n");
            }
        }

        else if (strcmp(operation, "alteracao") == 0) {

            scan_word(); scan_line();
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
            if (description != NULL) {
                printf("%s %s\n", word, description);
            } else {
                printf("OPERACAO INVALIDA\n");
            }
            free(word);
        }

        else if (strcmp(operation, "impressao") == 0) {

            scan_word();
        }

        else { printf("OPERACAO INVALIDA\n"); }

        free(operation);
    }

    return 0;
}