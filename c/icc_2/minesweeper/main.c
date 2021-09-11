// Rafael Zimmer, nUsp 12542612
// Project for Introduction to Computer Science - SCC0201, "Trabalho 01: Campo Minado"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *fscan_line(FILE *file_pointer, int *line_size);

char **read_board(char *file_name, int *height, int *width);
void print_board(char **board, int height, int width);
void free_board(char **board, int height);

void clear_mines(char ***board, int height, int width);
void clear_3x3(char ***board, int height, int width, int position_y, int position_x);

void fill_board(char ***board, int height, int width, char to_fill);
void clear_nearest_empty(char ***board, int height, int width, int position_y, int position_x);
void hide_mines(char ***board, int height, int width);

int main() {

	int operation;
	scanf("%d ", &operation);

	char file_name[20];
	scanf("%s ", file_name);

	int height = 0, width = 0;
	char **board = read_board(file_name, &height, &width);

	switch (operation) {

		case (1): {
			print_board(board, height, width);
			break;
		}

		case (2): {
			clear_mines(&board, height, width);
			print_board(board, height, width);
			break;
		}

		case (3): {
			// When selecting position to click, decide whether to end game, expand clicked area, or show nearby mines count.
			int position_y, position_x;
			scanf("%d %d", &position_y, &position_x);

			if (board[position_y][position_x] == '*') {
				clear_mines(&board, height, width);
				print_board(board, height, width);
			} else {
				fill_board(&board, height, width, 'X');
				clear_nearest_empty(&board, height, width, position_y, position_x);
				hide_mines(&board, height, width);
				print_board(board, height, width);
			}

			break;
		}

		default:
			break;
	}

	free_board(board, height);

	return 0;
}

// Scans a single line in a file pointer, assigning value to line_size pointer.
//
// Return:
// char *line - dynamically allocated string
char *fscan_line(FILE *file_pointer, int *line_size) {

	// Declare line array, with dynamic size
	char *line = NULL;
	char current_char = -1;

	int index = 0, string_size = 0;

	// Keep reading until current character is NULL character (set by program)
	while (current_char) {

		// Scan character and see if is \n, then stop reading line and add null character to end of string
		if (!fscanf(file_pointer, "%c", &current_char) || current_char == '\n') {
			current_char = 0;
		}

		if (current_char == -1) {
			return "\0";
		}

		// Increment size only if increment does not overflow current indexing of characters
		if (string_size++ <= index) {
			line = ( char* ) realloc(line, string_size);

			// Change pointer to line size to current line size, as to tell function caller total size of dynamically
			// allocated string
			if (line_size != NULL) {
				*line_size = string_size - 1;
			}
		}

		*(line + index++) = current_char;

	}

	// Return pointer to dynamically allocated string
	return line;
}

// Read board matrix, from file, setting values for height and width pointers after reading file
//
// Return:
// char **board - dynamically allocated board matrix.
char **read_board(char *file_name, int *height, int *width) {

	FILE *file_pointer = fopen(file_name, "r");
	char **board = malloc(0);

	char *line = fscan_line(file_pointer, width);

	while (line[0] != '\0') {
		(*height)++;
		board = realloc(board, (*height) * sizeof(char *));
		board[(*height) - 1] = line;
		line = fscan_line(file_pointer, NULL);
	}

	fclose(file_pointer);

	return board;

}

// Iterates over lines in board, and frees each line, as well as freeing board pointer at end
void free_board(char **board, int height) {
	for (int i = 0; i < height; i++) {
		free(board[i]);
	} free(board);
}

// Iterate over board height and width, printing respective character at index
void print_board(char **board, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", board[i][j]);
		} printf("\n");
	}
}

// Iterate over board height and width, counting mines around each (i, j) point in a 3x3 area
void clear_mines(char ***board, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (((*board)[i][j]) != '*') {
				clear_3x3(board, height, width, i, j);
			}
		}
	}
}

bool in_range(int index, int min, int max) {
	return min <= index && index < max;
}

// Function for detecting how many mines are in a 3x3 range around point (i, j) in the board matrix
// as well as setting the (i, j) character value to the respective amount of nearby mines
void clear_3x3(char ***board, int height, int width, int position_y, int position_x) {
	for (int current_y = -1; current_y < 2; current_y++) {
		for (int current_x = -1; current_x < 2; current_x++) {

			bool in_height = in_range(current_y + position_y, 0, height);
			bool in_width = in_range(current_x + position_x, 0, width);

			bool is_mine = (in_height && in_width) && ((*board)[position_y + current_y][position_x + current_x] == '*');

			// If currently viewed character is mine, increment (i, j) count
			if (is_mine) {

				// In range of decimal characters
				if (in_range((*board)[position_y][position_x] - '0', 0, 10)) {
					(*board)[position_y][position_x] += 1;
				} else {
					(*board)[position_y][position_x] = '1';
				}
			}
		}
	}
}

void fill_board(char ***board, int height, int width, char to_fill) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (((*board)[i][j]) != '*') {
				(*board)[i][j] = to_fill;
			}
		}
	}
}

// Expand visible area, in case clicked position does not have surrounding mines (char in position is 'X')
void clear_nearest_empty(char ***board, int height, int width, int position_y, int position_x) {

	// First, clear surrounding area, counting mines, and set counter to position if any nearby mines,
	// if no mines are nearby, the current position char will still be 'X', and thus nearby positions
	// can be cleared out as well, initiating recursive chain
	clear_3x3(board, height, width, position_y, position_x);
	if ((*board)[position_y][position_x] == 'X') {
		(*board)[position_y][position_x] = '.';

		for (int current_y = -1; current_y < 2; current_y++) {
			for (int current_x = -1; current_x < 2; current_x++) {

				bool in_height = in_range(current_y + position_y, 0, height);
				bool in_width = in_range(current_x + position_x, 0, width);

				bool is_empty = (in_height && in_width) && (*board)[current_y + position_y][current_x + position_x] == 'X';

				if (is_empty) {
					clear_nearest_empty(board, height, width, position_y + current_y, position_x + current_x);
				}

			}
		}
	}
}

// After any operation that does not result in end game, mines should be hidden from user when displaying current field state.
void hide_mines(char ***board, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (((*board)[i][j]) == '*') {
				(*board)[i][j] = 'X';
			}
		}
	}
}