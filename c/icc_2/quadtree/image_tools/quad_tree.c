#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Tree {

	int value;
	struct _Tree **children;

} tree;

tree *create_tree(int value, int total_children) {
	tree *new_tree = malloc(sizeof(tree));
	new_tree->value = value;
	if (total_children == 0) { new_tree->children = NULL; }
	else {
		new_tree->children = malloc(sizeof(tree *) * total_children);
	}

	return new_tree;
}

void free_tree(tree *quadtree) {
	if (quadtree->children != NULL) {
		for (int i = 0; i < 4; i++) { free_tree(quadtree->children[i]); }
	}
	free(quadtree->children);
	free(quadtree);
}

bool are_values_equal(int **matrix, int height, int width, int y_offset, int x_offset) {
	int last = matrix[y_offset][x_offset];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[y_offset + i][x_offset + j] != last) {
				return false;
			} else {
				last = matrix[y_offset + i][x_offset + j];
			}
		}
	}

	return true;
}

tree *grayscale_to_tree(int **greyscale, int height, int width, int y_offset, int x_offset) {
	tree *current_tree;

	// If all values inside quadrant are equall compress into single leaf
	if (are_values_equal(greyscale, height, width, y_offset, x_offset)) {

		current_tree = (tree *) create_tree(greyscale[y_offset][x_offset], 0);
	}

	// If current quadrant doesn't have enough width or height to fit inside a new quadtree, simply insert four new
	// leaves storing current pixel value
	else if (height / 2 > 1.0 && width / 2 > 1.0) {

		current_tree = create_tree(-1, 4);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				current_tree->children[i * 2 + j] = (tree *) grayscale_to_tree(greyscale, height / 2, width / 2, y_offset + (height * i) / 2.0, x_offset + (width * j) / 2);
			}
		}
	}

	// Else, separate current quadrant into four new subdivided quadrants, and return trees from each subdivision
	// to append to parent tree
	else {

		current_tree = create_tree(-1, height * width);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				current_tree->children[i * 2 + j] = create_tree(greyscale[y_offset + i][x_offset + j], 0);
			}
		}
	}

	return current_tree;
}

void print_tree(tree *quad_tree) {
	printf("%d ", quad_tree->value);
	if (quad_tree->children != NULL) {
		for (int i = 0; i < 4; i++) {
			print_tree(quad_tree->children[i]);
		}
	}
}