// Rafael Zimmer, 12542612

#include <stdio.h>

// Macro for getting the opposite sign of A
#define inverse_sign(A) ((A) > 0 ? -1 : 1)

// Function to copy values of one field matrix to another
void transfer_field(int lines, int columns, char original_field[lines][columns], char copy_field[lines][columns]) {

	// Iterate over lines and columns, and copy respective value in original matrix to secondary matrix
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {

			copy_field[i][j] = original_field[i][j];

		}
	}
}

// Simple function for iterating over matrix and printing value to console, separating lines by new-line
void print_field(int lines, int columns, char field[lines][columns]) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {

			printf("%c", field[i][j]);

		} printf("\n");
	}
}

// Function for deciding next cell state, based on neighboring cells, according to Moore`s neighbors scheme
char get_cell_future_moore(int lines, int columns, char field[lines][columns], int y_position, int x_position) {

	// Get current state of cell
	char cell = field[y_position][x_position];
	int alive_neighbors = 0;

	// Calculate total number of alive neighboring cells, including current cell
	for (int i = y_position - 1; i <= y_position + 1; i++) {
		for (int j = x_position - 1; j <= x_position + 1; j++) {

			// If neighbor to verify overflows field size, skip to end or start of field, and get respective character
			// at y + overflow, x + overflow
			int y_overflow = lines * inverse_sign(i) * !(0 <= i && i < lines);
			int x_overflow = columns * inverse_sign(j) * !(0 <= j && j < columns);

			alive_neighbors += field[ i + y_overflow ][ j + x_overflow ] == 'x';

		}
	}

	// If cell is alive, remove 1 from neighbors count, as to
	// account for previous lines including current alive cell in total alive neighbors count
	if (cell == 'x') {
		if (alive_neighbors - 1 == 2 || alive_neighbors - 1 == 3) return 'x';
	}
	else {
		if (alive_neighbors == 3) return 'x';
	}

	return '.';
}

// Function for deciding next cell state, based on neighboring cells, according to Von Neumann`s neighbors scheme
char get_cell_future_neumann(int lines, int columns, char field[lines][columns], int y_position, int x_position) {

	char cell = field[y_position][x_position];
	int alive_neighbors = 0;

	// Count neighboring cells horizontally, accounting for overflow as well
	for (int j = x_position - 2; j <= x_position + 2; j++) {

		int x_overflow = columns * inverse_sign(j) * !(0 <= j && j < columns);
		alive_neighbors += field[ y_position ][ j + x_overflow ] == 'x';

	}

	// Count neighboring cells vertically, also accounting for overflow
	for (int i = y_position - 2; i <= y_position + 2; i++) {

		int y_overflow = lines * inverse_sign(i) * !(0 <= i && i < lines);
		alive_neighbors += field[ i + y_overflow ][ x_position ] == 'x';

	}

	// If cell is alive, remove 2 from neighbors count, as to
	// account for previous lines including current alive two times, when counting both vertically and horizontally for
	// alive cells near current cell
	if (cell == 'x') {

		if ( alive_neighbors - 2 == 2 || alive_neighbors - 2 == 3 ) return 'x';

	} else {

		if ( alive_neighbors == 3 ) return 'x';

	}

	return '.';

}

int main() {

	int lines, columns, total_generations;
	char model;
	scanf("%d %d", &lines, &columns);
	scanf("%d", &total_generations);
	scanf("\n%c\n", &model);

	// Verify if input variables are valid beforehand
	if ((model != 'N' && model != 'M') || lines < 1 || columns < 1 || total_generations < 1) {

		printf("Dados de entrada apresentam erro.\n");
		return 0;

	}

	// Declare field variable and initiate cell states based on console input
	char field[lines][columns];

	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {

			scanf("%c", &field[i][j]);

		} scanf("%*[\n]");
	}

	// Iterate field state throughout multiple generations
	for (int g = 0; g < total_generations; g++) {

		// Save current field state in temporary variable, as to execute cell evaluations on unaltered field first
		char temporary_field[lines][columns];
		transfer_field(lines, columns, field, temporary_field);

		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {

				if (model == 'M') {
					temporary_field[i][j] = get_cell_future_moore(lines, columns, field, i, j);
				} else {
					temporary_field[i][j] = get_cell_future_neumann(lines, columns, field, i, j);
				}

			}
		}

		// Only update field state after complete iteration over each cell
		transfer_field(lines, columns, temporary_field, field);

	}

	// Finally, call function to print final state of cells
	print_field(lines, columns, field);

	return 0;

}