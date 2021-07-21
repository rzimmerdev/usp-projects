#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line();

int main () {

	char taboo[21];
	scanf("%s\n", taboo);

	char *phrase = read_line();
	char *result_phrase = phrase;

	while (result_phrase != NULL) {

		memmove(result_phrase, result_phrase + strlen(taboo), strlen(result_phrase + strlen(taboo)) + 1);
		result_phrase = strstr(result_phrase, phrase);
	}

	printf("The substring is: %s\n", result_phrase);

	return(0);
}

char *read_line() {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is EOF or \n, then stop reading line and add null character to end of string
		if (!scanf("%c", &current_char) || current_char == '$' || current_char == '\n') {
			current_char = 0;
		}

		// Increment size only if increment does not overflow current indexing of characters
		if (string_size++ <= index) {
			line = ( char* ) realloc(line, string_size);

		}

		*(line + index++) = current_char;

	}

	// Return pointer to dynamically allocated string
	return line;
}