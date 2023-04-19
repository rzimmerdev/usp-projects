// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Adding Surnames to Next Line
// 08/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_word();

int main() {

	// Define dynamic file, as pointer to pointers to words, to assist in freeing dynamic allocated memory
	int file_size = 1;
	char **file = calloc(file_size, sizeof (int));

	// Define initial read word, for iterating through
	char *word = read_word();
	file[0] = word;

	// Count lines and last words in lines, as to print in next odd line
	int line_number = 0;
	char *last_word;
	char *last_name;

	while (word[0] != '$') {

		// If read word is end of line, and line is odd, print last surname in last line, and assign last surname
		// to last surname variable
		if (word[0] == '\n') {

			if (line_number % 2 != 0) {
				printf(" %s", last_name);
			}

			last_name = last_word;
			line_number++;

		}

		// Print currently scanned word
		printf("%s", word);
		last_word = word;

		// Read next word, and decide if file variable should be resized
		word = read_word();

		if (word[0] != ' ' && word[0] != '\n' && word[0] != '$') {
			file_size++;
			file = realloc(file, sizeof (*file) * file_size);
			file[file_size - 1] = word;
		}
	}

	// Edge case, if last read word is ending character '$', but ending line should also print last line surname
	if (line_number % 2 != 0) {
		printf(" %s", last_name);
	}

	// Free pointers through assisting file variable, and free file as well
	for (int i = 0; i < file_size; i++) {
		free((file[i]));
	} free(file);

	return 0;
}

// Function for reading stdin, separating return statements by specific characters => { ' ', '\n', '$' } and returning
// separated words
char *read_word() {

	char current_char = 1;
	char *word = NULL;
	int index = 0, word_size = 0;

	while (current_char != 0) {

		scanf("%c", &current_char);

		// Verify if read character should result in returning word, or if read word is result of previous ungetc, and is
		// therefore empty (!word); in the later case, function should return read character as string
		if (current_char == '\n' || current_char == ' ' || current_char == '$') {

			if (word) {

				ungetc(current_char, stdin);
				current_char = 0;

			}

			if (!word) {
				switch (current_char) {

					case '\n':
						current_char = 0;
						return "\n";
					case ' ':
						current_char = 0;
						return " ";
					case '$':
						current_char = 0;
						return "$";

				}
			}

			// In case read character is not returning character, keep adding to word dynamic array
		} else {

			if (word_size++ <= index) {
				word = ( char* ) realloc(word, word_size);
			}

			*(word + index++) = current_char;
		}
	}

	return word;
}