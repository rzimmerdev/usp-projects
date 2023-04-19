// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Taboo Word Removal
// 18/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for reading input phrase for removing taboo word occurrence
char *read_line();

int main () {

	// Scan taboo word to remove
	char taboo[21];
	scanf("%s\n", taboo);

	// Scan phrase to remove word from, as well as instantiate temporary phrase
	// which should be set to result of verifying if taboo is substring of previously iterated phrase
	// strstr returns original string, if substring exists in string, else returns NULL
	char *phrase = read_line();
	char *result_phrase = phrase;

	int taboo_occurrences = 0;

	while ( ( result_phrase = strstr(result_phrase, taboo) ) != NULL ) {

		// memmove is used while iterating through occurrences for removing substring if pointers (which means the string header)
		// are the same, meaning that clearing subsequent memory removes substring from original phrase
		memmove(result_phrase, result_phrase + strlen(taboo), strlen(result_phrase + strlen(taboo)) + 1);
		taboo_occurrences++;

	}

	// Print original phrase, which was being updated until the point that result_phrase became null, but not original phrase
	printf("A palavra tabu foi encontrada %d vezes\n", taboo_occurrences);
	printf("Frase: %s\n", phrase);

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