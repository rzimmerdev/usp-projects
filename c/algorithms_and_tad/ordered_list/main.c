// Rafael Zimmer, nUsp 12542612
// Project for Algorithms and Data Structures - SCC0202, "Atividade 07: Lista Ordenada"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures/ordered_linked_list.h"
#include "tools/string_tools.h"
#include "persons_database.h"

int main() {

	OrderedLinkedList_t *person_database = create_list();

	char current_operation[10];

	while (scanf("%s", current_operation) == 1) {
		if (strcmp(current_operation, "INSERE") == 0) {

			person *new_person = create_person();

			int current_id;
			scanf("%d", &current_id); getchar();

			set_id(new_person, current_id);
			set_name(new_person, scan_line());

			if (get_person_index(person_database, get_id(new_person)) == -1) {
				add_node(person_database, new_person, compare_persons);
			} else {
				free(get_name(new_person));
				free(new_person);
				printf("INVALIDO\n");
			}
		}

		else if (strcmp(current_operation, "REMOVE") == 0) {

			int current_id;
			scanf("%d ", &current_id);

			if (remove_person(person_database, current_id) == -1) printf("INVALIDO\n");
		}

		else if (strcmp(current_operation, "IMPRIMIR") == 0) {
			if (get_size(person_database) == 0) { printf("VAZIA\n"); }
			else { print_database(person_database); }
		}
	}

	free_list(person_database, free_person);

	return 0;
}