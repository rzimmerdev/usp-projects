// Rafael Zimmer, nUsp 12542612
// Project for Introduction to Computer Science - SCC0201, "Exercício 02: Quad-Tree"

#include <stdio.h>
#include <stdlib.h>
#include "image_tools/quad_tree.h"

int main() {

	int height, width;
	scanf("%d %d ", &height, &width);

	// Allocate space for and scan greyscale image pixels value from console input
	int **image_greyscale = malloc(sizeof(int *) * height);
	for (int i = 0; i < height; i++) {
		int *line = malloc(sizeof(int) * width);
		image_greyscale[i] = line;
		for (int j = 0; j < width; j++) {
			scanf("%d ", &(line[j]));
		}
	}

	// Create compressed grayscale image tree
	tree *compressed_tree = grayscale_to_tree(image_greyscale, height, width, 0, 0);

	// Free original allocated image
	for (int i = 0; i < height; i++) {
		free(image_greyscale[i]);
	} free(image_greyscale);

	// Print and free compressed tree values in added order
	print_tree(compressed_tree);
	free_tree(compressed_tree);
	return 0;

}