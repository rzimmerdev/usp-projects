/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021
 *
 *  String tools library, contains functions for scanning and operating on specific string formats
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *  Scans and stores characters in string until '\n' or '\r' character from STDIN,
 *  and returns allocated string
 *
 *  @Returns:
 *           string array pointer: char*;
*/
char *scan_line() {

    int size = 0;
    char *str = malloc(size * sizeof(char));

    char current_char;

    while (scanf("%c", &current_char) == 1 && current_char != '\n') {
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

/*
 *  Replaces all occurrences of substring in string with substitute value
 *
 *  @Input:
 *         destination string: char* string,
 *         substring to replace: char *substring,
 *         value to insert in place: char *substitute
*/
void replace_string(char *string, char *substring, char *substitute) {

	int string_size = strlen(string);
	int substring_size = strlen(substring);
	int substitute_size = strlen(substitute);

	char *pointer = strstr(string, substring);

	while (pointer != NULL) {

		// If substring size is bigger then substitute size, text should be left-shifted to
		// match final substitute position, as well as reducing string size and inserting content into position
		if (substring_size > substitute_size) {

			int offset = string_size - substring_size  - (int) (pointer - string);
			memmove(pointer + substitute_size, pointer + substring_size, offset);
			memcpy(pointer, substitute, substitute_size);
			string_size -= (substring_size - substitute_size);
			string = realloc(string, (string_size + 1) * sizeof(char));
			string[string_size] = '\0';

		}

		// If substring is bigger, should first expand string, then reset pointer, and right-shift content to match
		// final position of substitute string, and finally copy content to pointer position
		else if (substring_size < substitute_size) {

			int offset = string_size - substring_size  - (int) (pointer - string);
			string_size += substitute_size - substring_size;
			string = realloc(string, (string_size + 1) * sizeof(char));
			string[string_size] = '\0';
			char *pointer = strstr(string, substring);
			memmove(pointer + substitute_size, pointer + substring_size, offset);
			memcpy(pointer, substitute, substitute_size);

		}

		// If both sizes are equall, simply copying content of substitute into pointer position is enough
		else { memcpy(pointer, substitute, substitute_size); }

		pointer = strstr(string, substring);
	}
}
