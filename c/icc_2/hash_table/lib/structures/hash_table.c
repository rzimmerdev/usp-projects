/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 15/12/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Trabalho 04: Tabela Hash"
*/

#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "linked_list.h"

/*
 *  Hash function using base factor and prime, to create exponential hash and prevent collisions.
 *  Used to find correct index of value in any given hash_table
 *
 *  @Input:
 *           sequence to generate hash of: char *,
 *           total size of table to fit index to: int
 *
 *  @Return:
 *           exponential hash of value using set factors and prime
*/
int hash(char *value, int table_size) {

    long long int hash = 0;
    long int current_factor = 1;

    for (int i = 0; i < strlen(value); i++) {

        hash += (value[i] * current_factor);
        current_factor *= base;
    }

    return (hash % prime) % table_size;
}

/*
 *  Allocates memory for table struct, as well as creating linked lists for each possible index,
 *  setting comparison function for each linked list.
 *
 *  @Input:
 *           total linked lists to be created in index positions: int,
 *           comparison function to compare generic pointers: int *(void *, void *)
 *
 *  @Return:
 *           pointer to created hash table with empty lists: hash_table *
*/
hash_table *create_table(int size, int (*compare)(void *first, void *second)) {

    hash_table *new_table = malloc(sizeof(hash_table));

    new_table->lists = malloc(sizeof(linked_list *) * size);
    new_table->size  = size;

    for (int i = 0; i < size; i++) {

        new_table->lists[i] = create_list(compare);
    }

    return new_table;
}

/*
 *  Function to iterate over all linked lists in table, freeing each individually. Frees table pointer as well.
 *
 *  @Input:
 *           hash table to free each list: hash_table *
*/
void free_table(hash_table *table) {

    for (int i = 0; i < table->size; i++) {

        free_list(table->lists[i]);
    }

    free(table->lists);
    free(table);
}

/*
 *  Finds correct hash for given value, and inserts value into correct linked list, given
 *  linked_list.h function (Frees value if given value already present in another node)
 *
 *  @Input:
 *           table to insert new value into: hash_table *,
 *           new value to insert into new node at start: char *
*/
void add_value(hash_table *table, char *value) {

    linked_list *list = table->lists[hash(value, table->size)];

    add_node(list, value);
}

/*
 *  Removes existing node at linked list at hashed position if any, reconnecting linked list.
 *
 *  @Input:
 *           hash table to search corresponding linked list: hash_table *,
 *           value to find in linked list to be removed: char *
*/
void remove_value(hash_table *table, char *value) {

    linked_list *list = table->lists[hash(value, table->size)];

    remove_node(list, value);
}

/*
 *  Find if value is present in given hash table
 *
 *  @Input:
 *           hash table to search corresponding linked list: hash_table *,
 *           value to find in linked list: char *
 *
 *  @Return:
 *           1 if value exists, 0 if not.
*/
int find_value(hash_table *table, char *value) {

    linked_list *list = table->lists[hash(value, table->size)];

    node *found_node = find_node(list, value);

    return found_node ? 1 : 0;
}