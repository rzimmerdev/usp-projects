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

int main() {

    char *operation;

    while ((operation = scan_word())[0] != '\0') {
        printf("%s\n", operation);

        if (strcmp(operation, "insercao") == 0) {

            char *word = scan_word();
            char *description = scan_line();

            printf(": %s", word);
            printf(" - %s", description);
        }

        else if (strcmp(operation, "alteracao")) {

            scan_word(); scan_line();
        }

        else if (strcmp(operation, "remocao")) {

            scan_word();
        }

        else if (strcmp(operation, "busca")) {

            scan_word();
        }

        else if (strcmp(operation, "impressao")) {

            scan_word();
        }

        else { printf("operação inválida\n"); }

        free(operation);
    }

    return 0;
}