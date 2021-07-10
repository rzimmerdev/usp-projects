// Rafael Zimmer, n 12542612

#include <stdio.h>

int main() {

	// Initialize counters for lines, words and characters
	int n_linhas = 0, n_palavras = 0, n_chars = 0;

	// Scan current character, keep track of previous character for detecting words
	char current_char;
	char prev_char = ' ';

	// Scan while not EOF
	while (scanf("%c", &current_char) != -1) {

		// If read new line character, and previous character is not '\r', (In Windows OS, line feed character is \r\n,
		// meaning that two characters in sequence only skip one line, only one count should be added, for first skip.
		if ((current_char == '\n' && prev_char != '\r') || (current_char == '\r')) n_linhas++;

		n_chars++;

		if
		(!(( prev_char == '\r' ) || ( prev_char == '\n' ) || (( prev_char == ' ' ) || ( prev_char == '\t' ))) &&
		(( current_char == '\r' ) || ( current_char == '\n' ) || (( current_char == ' ' ) || ( current_char == '\t' ))))
		{ n_palavras++; }

		prev_char = current_char;
	};

	if (!((prev_char == '\r') || (prev_char == '\n') || (prev_char == ' '))) n_palavras++;

	printf("Linhas\tPalav.\tCarac.\n");
	printf("%d\t%d\t%d", n_linhas, n_palavras, n_chars);

	return 0;

}