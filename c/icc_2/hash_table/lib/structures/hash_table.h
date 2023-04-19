/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 15/12/2021
 *  Project for Introduction to Computer Science II - SCC0201, "Trabalho 04: Tabela Hash"
*/

#ifndef USP_PROJECTS_HASH_TABLE_H
#define USP_PROJECTS_HASH_TABLE_H

#include "linked_list.h"

// Defining prime numbers and base factor for exponential hash function
#define prime 1000000007
#define base 263


typedef struct HashTable_t {

    int size;
    linked_list **lists;

} hash_table;


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
hash_table *create_table(int size, int (*compare)(void *first, void *second));


/*
 *  Function to iterate over all linked lists in table, freeing each individually. Frees table pointer as well.
 *
 *  @Input:
 *           hash table to free each list: hash_table *
*/
void free_table(hash_table *table);


/*
 *  Finds correct hash for given value, and inserts value into correct linked list, given
 *  linked_list.h function (Frees value if given value already present in another node)
 *
 *  @Input:
 *           table to insert new value into: hash_table *,
 *           new value to insert into new node at start: char *
*/
void add_value(hash_table *table, char *value);


/*
 *  Removes existing node at linked list at hashed position if any, reconnecting linked list.
 *
 *  @Input:
 *           hash table to search corresponding linked list: hash_table *,
 *           value to find in linked list to be removed: char *
*/
void remove_value(hash_table *table, char *value);

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
int find_value(hash_table *table, char *value);

#endif //USP_PROJECTS_HASH_TABLE_H
