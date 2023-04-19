// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Adding Padding to Centered Image
// 25/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *read_line(int *line_size, int *total_spaces);
bool is_palindrome_direct(const char *line, int start, int end);

int main() {

	int line_size = 0, total_spaces = 0;
	char *line = read_line(&line_size, &total_spaces);

	// Set same values for spaceless line as in original line, besides blank spaces, so to detect if palindrome exists
	// and is valid for any specific order of spaces in line
	char line_spaceless[line_size - total_spaces];

	int current_space_count = 0;

	for (int i = 0; i < line_size; i++) {

		if (line[i] != ' ' &&  line[i] != '/') line_spaceless[i - current_space_count] = line[i];
		else current_space_count++;

	}

	if (is_palindrome_direct(line, 0, line_size - 1)) {

		printf("Palindromo direto");

	} else {

		if (is_palindrome_direct(line_spaceless, 0, line_size - current_space_count - 1)) {

			printf("Palindromo indireto");

		} else {

			printf("Nao eh um palindromo");

		}
	}

	free(line);

	return 0;

}

// Function to return read word, ignoring non desired characters, and setting values for total line size, as well
// as count for all spaces in line
//
// Parameters: pointer to line size counter, pointer to total spaces counter
// Returns: pointer to dynamically allocated line
char *read_line(int *line_size, int *total_spaces) {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is EOF or \n, then stop reading line
		if (!scanf("%c", &current_char) || current_char == '\n') {
			current_char = 0;
		}

		// Increment size only if increment does not overflow current indexing of characters,
		// and current character is valid for specific exercise
		// else, ignore and keep reading line until end
		if (isalnum(current_char) || current_char == ' ' || current_char == '/') {

			if (string_size++ <= index) {
				line = ( char* ) realloc(line, string_size);

			}

			*(line + index++) = (char) tolower(current_char);
			(*line_size)++;

			// If character is to be counted as blank, increment total_spaces count
			if (current_char == ' ' || current_char == '/') (*total_spaces)++;

		}
	}

	// Return pointer to dynamically allocated string
	return line;
}

// Recursive fucntion to analyze if line is a palindrome
//
// Parameters: array of chars containing line characters, int header for start of line, int header for end of line
// Returns: true if is palindrome, false if not
bool is_palindrome_direct(const char *line, int start, int end) {

	// Defining base cases for recursive function
	if (start == end) return true;
	if (line[start] != line[end]) return false;

	// Detect if is palindrome by analyzing if start of line is same as end, by recurring towards center of line
	// thus incrementing start header and decrementing end header, and if is palindrome start header - 1 will be bigger
	// than end header, and base case for false palindrome hasn't been reached, thus should return true
	if (start - 1 < end) {

		return is_palindrome_direct(line, start + 1, end - 1);

	}

	return true;

}