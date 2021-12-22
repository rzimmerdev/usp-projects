/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021
 *
 *  String tool library, contains functions for scanning and operating on specific string formats
*/

#include <stdio.h>
#include <stdlib.h>

/*
 *  Scans and stores a single word in string from STDIN,
 *  separated by ' ' (space) or new-line characters
 *
 *  @Returns:
 *            string array pointer: char*;
*/
char *scan_word() {

    int size = 0;
    char *str = malloc(size * sizeof(char));

    char current_char;

    while (scanf("%c", &current_char) == 1 && current_char != ' ' && current_char != '\n') {
        if (current_char != '\r') {
            str = realloc(str, ++size * sizeof(char));
            str[size - 1] = current_char;
        }
    }

    if (size != 0) {

        str = realloc(str, (size + 1) * sizeof(char));
        str[size] = '\0';
        return str;
    }

    free(str);
    return "\0";
}