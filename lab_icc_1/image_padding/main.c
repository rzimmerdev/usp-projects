// Rafael Zimmer, n12542612
// Project for Introduction Lab for CompSci - Reverse Polonese Notation
// 23/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_array(int **array, int size, int padding);

int main() {

	int width, height, padding;

	scanf("%d\n%d", &width, &height);

	// Allocating memory for image value matrix
	int **image = malloc( height * sizeof(int *) );
	for (int i = 0; i < height; i++) image[i] = (int *) malloc( width * sizeof(int) );

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			int color;
			scanf("%d ", &color);
			image[i][j] = color;

		}
	}

	scanf("%d", &padding);

	for (int i = 0; i < height; i++) {

		image[i] = realloc(image[i], (width + 2 * padding) * sizeof(int *));

		shift_array(&(image[i]), width, padding);

	}

	printf("\n");
	for (int i = 0; i < height + 2 * padding; i++) {
		for (int j = 0; j < width + 2 * padding; j++) {

			printf("%d ", image[i][j]);

		}
		printf("\n");
	}

}

void shift_array(int **array, int size, int padding) {

	int temp[size];

	for (int i = 0; i < size; i++) {

		temp[i] = (*array)[i];

	}

	for (int i = 0; i < size + 2 * padding; i++) {

		if (i < padding || i >= size + padding) {
			(*array)[i] = 0;
		} else (*array)[i + padding] = temp[i];

	}
}