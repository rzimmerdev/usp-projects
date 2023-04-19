// Rafael Zimmer, nUsp 12542612

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Maze {
    int height;
    int width;
    char **matrix;
    int x_position;
    int y_position;
} Maze;

char *read_line();

int scan_maze(FILE *file, Maze *maze, int *total_people);
void print_matrix(Maze *maze);
void free_matrix(Maze *maze);

int traverse_maze(Maze *maze, bool *atEnd);

int main() {

    char *file_name = read_line();
    FILE *file = fopen(file_name, "r");

    Maze maze;

    int total_people = 0;
    int valid_paths = scan_maze(file, &maze, &total_people);

    fclose(file);

	bool atEnd = false;
    int traversed_paths = traverse_maze(&maze, &atEnd);

    print_matrix(&maze);

    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n", total_people);
    printf("----Numero total de caminhos validos:   %d\n", valid_paths);
    printf("----Numero total de caminhos visitados: %d\n", traversed_paths);
    double percentage = ((double) traversed_paths/valid_paths * 100);
    printf("----Exploracao total do labirinto: %.1lf%%\n", (double) (int) percentage);

    free_matrix(&maze);

    return 0;

}

char *read_line() {

    // Declare line array, with dynamic size
    char *line = NULL;
    char current_char = -1;

    int index = 0, string_size = 0;

    // Keep reading until current character is NULL character (set by program)
    while (current_char) {

        // Scan character and see if is EOF or \n, then stop reading line and add null character to end of string
        if ((scanf("%c", &current_char) == -1) || current_char == '\n' || current_char == '\r') {
            current_char = 0;
        }

        // Increment size only if increment does not overflow current indexing of characters
        if (string_size++ <= index) {
            line = (char *) realloc(line, string_size);

        }

        *(line + index++) = current_char;

    }

    // Return pointer to dynamically allocated string
    return line;
}

void print_matrix(Maze *maze) {

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {

            printf("%c", (maze->matrix)[i][j]);

        }
        printf("\n");
    }
}

// Function for scanning maze from file pointer, as well as setting pointer value for total_peole ('#') in maze matrix
// Returns total of valid paths in maze ('.')
int scan_maze(FILE *file, Maze *maze, int *total_people) {

    fscanf(file, "%d %d ", &(maze->height), &(maze->width));
    fscanf(file, "%d %d ", &(maze->y_position), &(maze->x_position));

    maze->matrix = calloc(maze->height, sizeof(int *));

    for (int i = 0; i < maze->height; i++) {
        (maze->matrix)[i] = calloc(maze->width, sizeof(int));
    }

    int traversable = 0;

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {

            fscanf(file, "%c ", &(maze->matrix[i][j]));

            if ((maze->matrix[i][j]) == '.') {
                traversable++;
            } else {
				(*total_people)++;
            }

        }
    }
    return traversable;
}

// Function for freeing dynamically allocated matrix rows and matrix pointer inside maze struct
void free_matrix(Maze *maze) {

    for (int i = 0; i < maze->height; i++) {

        free((maze->matrix)[i]);

    }
    free(maze->matrix);
}

// Recursive function for counting total paths traveled and replacing traversed matrix values
// Returns total amount of traversed paths during maze path finding
int traverse_maze(Maze *maze, bool *atEnd) {

    int total_traversed = 0;

    int current_x_position = maze->x_position;
    int current_y_position = maze->y_position;

    (maze->matrix)[maze->y_position][maze->x_position] = '*';

    // If at exit, which means it is also at border of matrix, return last path increment (1) and set end pointer to true

    for (int j = -1; j < 2; j++) {

        if ((maze->x_position + j >= maze->width || maze->x_position + j < 0) ||
            (maze->y_position + j >= maze->height || maze->y_position + j < 0)
        ) {
        	*atEnd = true;
            return 1;
        }
    }

    // If another path is available, traverse in that direction, according to proposed traverse order,
    // as well as account for current path counter increase at end of recursive chain

	// When done traversing through one path, set position in maze to current index position

	if (((maze->matrix)[current_y_position - 1][current_x_position] == '.') && !(*atEnd)) {
		maze->y_position--;
		total_traversed += traverse_maze(maze, atEnd);
		maze->x_position = current_x_position;
		maze->y_position = current_y_position;
	}

	if (((maze->matrix)[current_y_position][current_x_position + 1] == '.') && !(*atEnd)) {
		maze->x_position++;
		total_traversed += traverse_maze(maze, atEnd);
		maze->x_position = current_x_position;
		maze->y_position = current_y_position;
	}

	if (((maze->matrix)[current_y_position + 1][current_x_position] == '.') && !(*atEnd)) {
		maze->y_position++;
		total_traversed += traverse_maze(maze, atEnd);
		maze->x_position = current_x_position;
		maze->y_position = current_y_position;
	}

	if (((maze->matrix)[current_y_position][current_x_position - 1] == '.') && !(*atEnd)) {
		maze->x_position--;
		total_traversed += traverse_maze(maze, atEnd);
		maze->x_position = current_x_position;
		maze->y_position = current_y_position;
	}

    return 1 + total_traversed;

}
