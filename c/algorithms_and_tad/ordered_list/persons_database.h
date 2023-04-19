#ifndef ORDERED_LIST_PERSONS_DATABASE_H
#define ORDERED_LIST_PERSONS_DATABASE_H

typedef struct _Person person;

// Allocates memory for person struct variable, as well as allows user to access struct variables and change
// the values based on a new input value
person *create_person();

char *get_name(person *person);
void set_name(person *person, char *name);

int get_id(person *person);
void set_id(person *person, int id);

// Function to compare two persons stored in nodes based on person id values
// Returns true if next id is bigger than to insert id
int compare_persons(Node_t *next, Node_t *to_insert);

// Function to free person's name stored in node
void free_person(Node_t *to_free);

// Returns person filtered by person_id index relative to position in Ordered Linked List
int get_person_index(OrderedLinkedList_t *person_database, int person_id);

// Removes single person from Ordered Linked List, filtered by person_id
int remove_person(OrderedLinkedList_t *person_database, int person_id);

// Prints entire person database, in ascending person id order
void print_database(OrderedLinkedList_t *person_database) ;

#endif //ORDERED_LIST_PERSONS_DATABASE_H
