#include <stdlib.h>
#include <stdio.h>
#include "string_tools.h"

typedef struct shell {
	char *color;
	char *texture;
	double diameter;
} Shell_t;


Shell_t *scan_shell() {

	Shell_t *new_shell = malloc(sizeof(Shell_t));

	scanf("%lf ", &(new_shell->diameter));
	new_shell->color = scan_word();
	new_shell->texture = scan_word();

	return new_shell;

}

void print_shell(Shell_t *shell) {

	printf("%.3f %s %s\n", shell->diameter, shell->color, shell->texture);

}

void free_shell(Shell_t *shell) {

	free(shell->color); free(shell->texture);
	free(shell);

}

void shell_sort(Shell_t **shell_list, int total_shells) {

	// Separate list into n / 2 smaller lists and attribute l (total lists) to l / 2
	for (int l = total_shells / 2; l >= 1; l /= 2) {

		// Pointer to start of separated list, since elements different lists have a distance increment of 1, but
		// individual elements of the same virtual list have a distance of l ( n / 2^current_subdivision )
		for (int p = 0; p < l; p++) {

			// Perform insertion sort on elements in the same virtual list, with indexes incrementing at a rate l,
			// and starting from a pointer p pointing to starting position in original list
			for (int i = l; i + p < total_shells; i += l) {

				Shell_t *current_shell = shell_list[p + i];

				int j = i - l;

				while (j >= 0 && current_shell->diameter < shell_list[p + j]->diameter) {
					shell_list[p + j + l] = shell_list[p + j];
					j -= l;
				}
				shell_list[p + j + l] = current_shell;

			}
		}
	}
}