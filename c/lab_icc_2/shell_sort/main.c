// Rafael Zimmer, nUsp 12542612
// Project for Introduction to Computer Science 2 - Lab - SCC0220, "Módulo 1 - Ordenação Aconhegante"

#include <stdio.h>
#include <stdlib.h>
#include "tools/shell_tools.h"

int main() {

	int total_shells;
	scanf("%d ", &total_shells);

	Shell_t **shell_list = malloc(total_shells * sizeof(Shell_t *));

	// Scan shell object (diameter, color and texture) and insert
	for (int i = 0; i < total_shells; i++) {
		shell_list[i] = scan_shell();
	}

	// Call shell sorting from shell tool, to sort using insertion sort on virtual sublist
	shell_sort(shell_list, total_shells);

	// Print shells in ascending diameter order
	for (int i = 0; i < total_shells; i++) {
		print_shell(shell_list[i]);
		free_shell(shell_list[i]);
	} free(shell_list);
	return 0;
}