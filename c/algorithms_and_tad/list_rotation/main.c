// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 06: Rotação de Lista"

#include <stdio.h>
#include <stdlib.h>
#include "structures/circular_linked_list.h"

// Print circular linked list values from start to end in order, given that list is bidirectional
void print_circular_list(CircularLinkedList_t *list);

int main() {

	int total_cases;
	scanf("%d ", &total_cases);

	for (int i = 0; i < total_cases; i++) {

		// Allocate circular linked list for each test_case
		CircularLinkedList_t *rotation_list = create_list();

		int list_size, total_rotations;
		scanf("%d ", &list_size);
		scanf("%d ", &total_rotations);

		for (int j = 0; j < list_size; j++) {
			int *current_value = malloc(sizeof(int));
			scanf("%d ", current_value);
			add_node(rotation_list, current_value);
		}

		// Perform to-right shift on top of circular linked list
		for (int r = 0; r < total_rotations; r++) shift_list(rotation_list);

		print_circular_list(rotation_list);
		free_list(rotation_list);
	}

	return 0;
}

void print_circular_list(CircularLinkedList_t *list) {

	int list_size = get_size(list);

	Node_t *current_node = get_list_start(list);

	for (int i = 0; i < list_size; i++) {

		printf("%d ", *(int *) get_node_value(current_node));
		current_node = get_next_node(current_node);

	} printf("\n");

}