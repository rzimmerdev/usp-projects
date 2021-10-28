// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 05: Sequência Balanceada"
#include <stdio.h>
#include <stdbool.h>
#include "structures/stack.h"

int is_matching(char open_char, char end_char);
int is_open(char test_char);

int main() {

	// Keep track of current stack of characters, as to view last added character first, when searching top of stack
	Stack_t *current_stack = create_stack();
	bool is_balanced = true;

	char current_char;
	int is_eof;

	do {

		is_eof = scanf("%c", &current_char);

		// If end of line has been reached, evaluate if stack is empty (all characters have matching closing tags)
		// and have been matched in the right order
		if (current_char == '\n' || is_eof == -1) {

			if (get_size(current_stack) != 0 || !is_balanced) printf("NÃO BALANCEADO\n");
			else printf("BALANCEADO\n");

			is_balanced = true;

			// After evaluating, free stack and keep reading new characters until EOF
			free_stack(current_stack);
			if (current_char != -1) current_stack = create_stack();

		}

		// If character is meaningful (not empty space nor carriage return character)
		else if (current_char != ' ' && current_char != '\r') {

			// If character is quote, specific behaviour should follow, as opening and ending quotes
			// cannot be differentiated
			if (current_char == '"') {

				if (is_matching(view_top(current_stack), current_char)) {

					pop_stack(current_stack);

				} else {

					insert_stack(current_stack, current_char);

				}
			}

			else {
				// If current character is a opening tag character, simply insert into stack and read next character
				if (is_open(current_char)) {

					insert_stack(current_stack, current_char);

				}
				// If character is not tag opening, it should be closing character, thus should verify if last added
				// character is matching opening character
				else if (is_matching(view_top(current_stack), current_char)) {

					pop_stack(current_stack);

				}
				// Else, characters are not in matching order, and sequence is therefore unbalanced
				else {
					is_balanced = false;
				}
			}
		}
	} while (is_eof != -1);

	free_stack(current_stack);

	return 0;
}

// Verify if two sequential characters are closing and opening respective characters, ex: ( and ), or { and }
int is_matching(char open_char, char end_char) {

	switch (open_char) {

		case '(':
			return end_char == ')';
		case '[':
			return end_char == ']';
		case '{':
			return end_char == '}';
		case '"':
			return end_char == '"';
		default:
			return false;
	}

}

// Verify if character is one of the three possible restrict opening characters
int is_open(char read_char) {
	return read_char == '(' || read_char == '[' || read_char == '{';
}