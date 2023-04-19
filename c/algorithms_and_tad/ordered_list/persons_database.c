#include <stdio.h>
#include <stdlib.h>
#include "structures/ordered_linked_list.h"

typedef struct _Person {
	int id;
	char *name;
} person;

person *create_person() {
	person *new_person = malloc(sizeof(person));
	new_person->id = -1;
	new_person->name = NULL;
	return new_person;
}

char *get_name(person *person) { return person->name; }
int get_id(person *person) { return person->id; }

void set_id(person *person, int id) {
	person->id = id;
}

void set_name(person *person, char *name) {
	person->name = name;
}

int compare_persons(Node_t *next, Node_t *to_insert) {
	return ((person *) get_node_value(next))->id > ((person *) get_node_value(to_insert))->id;
}

void free_person(Node_t *to_free) {
	free(((person *) get_node_value(to_free))->name);
}

int get_person_index(OrderedLinkedList_t *person_database, int person_id) {
	Node_t *current_node = get_list_start(person_database);
	int i = 0;

	while (current_node != NULL && ((person *) get_node_value(current_node))->id != person_id) {
		current_node = get_node_next(current_node);
		i++;
	}

	if (i == get_size(person_database)) { return -1; }
	return i;
}

int remove_person(OrderedLinkedList_t *person_database, int person_id) {

	Node_t *parent_node = get_list_start(person_database);
	if (parent_node == NULL) { return -1; }

	// First verify if person is not at start of ordered linked list, if it is the case
	// remove person and return success code
	if (((person *) get_node_value(parent_node))->id == person_id) {
		free(((person *) get_node_value(parent_node))->name);
		remove_node(person_database, 0);
		return 1;
	}

	// Else, start iterating based on parent node and verifying if next node has required id,
	// thus allowing to save parent node index to send to remove node function
	int i = 0;
	while (get_node_next(parent_node) != NULL && ((person *) get_node_value(get_node_next(parent_node)))->id != person_id) {
		parent_node = get_node_next(parent_node);
		i++;
	}

	if (get_node_next(parent_node) == NULL) {
		return -1;
	} else {
		free(((person *) get_node_value(get_node_next(parent_node)))->name);
		remove_node(person_database, i + 1);
		return 1;
	}
}

void print_database(OrderedLinkedList_t *person_database) {
	Node_t *current_node = get_list_start(person_database);
	while (current_node != NULL) {
		person *current_person = (person *) get_node_value(current_node);
		printf("%d, %s; ", current_person->id, current_person->name);
		current_node = get_node_next(current_node);
	} printf("\n");
}