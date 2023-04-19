// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 04: Fila de Prioridade"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures/queue.h"
#include "structures/linked_list.h"
#include "tools/string_tools.h"

typedef struct Person {

	char *name;
	int age;
	int conditioned;

} person_c;

person_c *pop_next_person(LinkedList_t *priority_queue);
void print_person_info(person_c *person);

int main() {

	// Create linked list for ordering four types of different priorities ->
	// conditioned and older than 60, only conditioned, only older than 60 and none
	LinkedList_t *priority_queue = create_linked_list();

	// Add first-in, first-out queue into each priority queue
	for (int i = 0; i < 4; i++) {
		Queue_t *queue = create_queue();
		add_node(priority_queue, queue);
	}

	int total_actions;
	scanf("%d ", &total_actions);

	for (int i = 0; i < total_actions; i++) {
		char *current_operation = scan_word();

		// If current type of operation is to insert person, allocate space for new person and insert
		// into specific category according to status
		if (strcmp(current_operation, "ENTRA") == 0) {

			person_c *current_person = malloc(sizeof(person_c));
			current_person->name = scan_word();
			scanf("%d %d ", &(current_person->age), &(current_person->conditioned));
			if (current_person->age >= 60 && current_person->conditioned) {

				insert_queue((Queue_t *) get_node_value(search_node(priority_queue, 0)), current_person);

			} else if (current_person->conditioned) {

				insert_queue((Queue_t *) get_node_value(search_node(priority_queue, 1)), current_person);

			} else if (current_person->age >= 60) {

				insert_queue((Queue_t *) get_node_value(search_node(priority_queue, 2)), current_person);

			} else {

				insert_queue((Queue_t *) get_node_value(search_node(priority_queue, 3)), current_person);

			}
		}
		// If operation is to print, pop user using created function or declare empty array
		// No method for printing in case of full list since list is dynamically allocated
		else {
			getchar();
			person_c *next_person = pop_next_person(priority_queue);
			if (next_person == NULL) {
				printf("FILA VAZIA\n");

			} else {
				print_person_info(next_person);
				free(next_person->name);
				free(next_person);

			}
		}

		free(current_operation);
	}

	int priority_size = linked_list_size(priority_queue);

	// After all operations have been performed, clear priority_list and respective queues, as well as
	// any remaining person
	for (int i = 0; i < priority_size; i++) {

		Queue_t *current_queue = (Queue_t *) get_node_value(search_node(priority_queue, i));
		int current_queue_size = queue_size(current_queue);

		for (int i = 0; i < current_queue_size; i++) {

			person_c *current_person = pop_queue(current_queue);
			free(current_person->name);
			free(current_person);

		}
	} free_list(priority_queue);

	return 0;
}

// Function to print formatted user data
void print_person_info(person_c *person) {

	printf("%s %d %d\n", person->name, person->age, person->conditioned);

}

// Iterate over priority options and find most important non-empty queue, then return popped value
person_c *pop_next_person(LinkedList_t *priority_queue) {
	Node_t *current_node = search_node(priority_queue, 0);

	int found_next_person = 0;

	do {
		if (queue_size(get_node_value(current_node)) > 0) {
			found_next_person = 1;
			return (person_c *) pop_queue(get_node_value(current_node));
		}
		current_node = next_node(current_node);
	} while (current_node != NULL && !found_next_person);

	return NULL;
}