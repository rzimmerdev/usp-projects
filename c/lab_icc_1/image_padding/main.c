// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Adding Padding to Centered Image
// 23/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_array(int **array, int size, int padding);
void shift_line(int ***array, int size, int line_size, int padding);

int main() {

	int width, height, padding;

	scanf("%d\n%d", &width, &height);

	// Allocating memory for image value matrix
	int **image = malloc( height * sizeof(int * ) );
	for (int i = 0; i < height; i++) image[i] = (int *) malloc( width * sizeof(int) );

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			int color;
			scanf("%d ", &color);
			image[i][j] = color;

		}
	}

	scanf("%d", &padding);

	image = realloc(image, sizeof(int * ) * (height + padding * 2));
	for (int i = 0; i < height; i++) {

		image[i] = realloc(image[i], sizeof(int) * (width + padding * 2));
		shift_array(&(image[i]), width, padding);

	}

	shift_line(&image, height, width, padding);

	for (int i = 0; i < height + 2 * padding; i++) {
		for (int j = 0; j < width + 2 * padding; j++) {

			printf("%d ", image[i][j]);

		} printf("\n");
	}

	printf("\n");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			printf("%d ", image[i + padding][j + padding]);

		} printf("\n");
	}

	return 0;

}

// Function for shifting line values in a matrix, to the centered position, by including padding lines on end and start
// of the matrix
//
// Parameters: Pointer to 2D matrix, vertical size of matrix, horizontal size of matrix, padding to add to top and bottom
// Returns: None (Void)
void shift_line(int ***array, int size, int line_size, int padding) {

	int *temp[size];

	for (int i = 0; i < size; i++) {

		temp[i] = (*array)[i];

	}

	for (int i = 0; i < size + 2 * padding; i++) {

		if (i < padding || i >= size + padding) {

			(*array)[i] = calloc(line_size + 2 * padding, sizeof(int));

		} else (*array)[i] = temp[i - padding];

	}
}

// Function for shifting line values in an array, to the centered position, by including padding values on end and start
//
// Parameters: Pointer to 1D array, size of array, padding to add to start and end
// Returns: None (Void)
void shift_array(int **array, int size, int padding) {

	int temp[size];

	for (int i = 0; i < size; i++) {

		temp[i] = (*array)[i];

	}

	for (int i = 0; i < size + 2 * padding; i++) {

		if (i < padding || i >= size + padding) (*array)[i] = 0;

		else (*array)[i] = temp[i - padding];

	}
}