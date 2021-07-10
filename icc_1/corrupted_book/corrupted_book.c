// Rafael Zimmer, n 12542612

#include <stdlib.h>

#include <stdio.h>
#include <string.h>

char *read_line() {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is EOF or \n, then stop reading line and add null character to end of string
		if (!scanf("%c", &current_char) || current_char == '\n') {
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

int main() {

	int num_lines;
	scanf("%d\n", &num_lines);

	// Define array of strings to read, based on number of lines
	char *lines[num_lines];

	for (int i = 0; i < num_lines; i++) {
		// Call to read_line function, to add to array of strings
		*(lines + i) = read_line();

	}

	int num_valid;
	scanf("%d", &num_valid);

	for (int i = 0; i < num_valid; i++) {
		// Print only strings that are not corrupted
		int valid_line_index;
		scanf(" %d", &valid_line_index);
		printf("%s\n", lines[valid_line_index]);

	}

	// Free dynamic allocated strings
	for (int i = 0; i < num_lines; i++) {
		free(lines[i]);
	}

	return 0;
}