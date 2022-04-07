/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 03/10/2021
 *
 *  Auxiliary Functions library for the creation of a dictionary for Algorithms and Data Structures class
*/

#ifndef USP_PROJECTS_DICTIONARY_H
#define USP_PROJECTS_DICTIONARY_H

/*
 *  Creates a skip list pointer, with default attributes tailored for dictionary values
 *
 *  @Returns:
 *           skip list pointer with dictionary head, compare and delete function: skip_list *;
*/
skip_list *create_dictionary();

/*
 *  Inserts new entry containing pointers to word and description strings into dictionary, with Average(log n) time
 *
 *  @Input:
 *           dictionary pointer: skip_list *,
 *           pointer to word: char *,
 *           pointer to description: char *,
 *  @Returns:
 *           operation output: 1 if success, -1 if error
*/
int add_entry(skip_list *dictionary, char *word, char *description);

/*
 *  Removes entry containing pointers to word with same value as word from dictionary, with Average(log n) time
 *
 *  @Input:
 *           dictionary pointer: skip_list *,
 *           pointer to placeholder word: char *,
 *  @Returns:
 *           operation output: 1 if success, -1 if error
*/
int remove_entry(skip_list *dictionary, char *word);

/*
 *  Returns description string pointer given word value, performing skip list search in Average(n) time
 *
 *  @Input:
 *           dictionary pointer: skip_list *,
 *           pointer to placeholder word: char *,
 *  @Returns:
 *           pointer to description string: char * || NULL if not found
*/
char *get_description(skip_list *dictionary, char *word);

/*
 *  Replaces description pointer with new pointer, freeing previous pointer from dictionary
 *
 *  @Input:
 *           dictionary pointer: skip_list *,
 *           pointer to placeholder word: char *,
 *           pointer to new description: char *,
 *  @Returns:
 *           operation output: 1 if success, -1 if error
*/
int replace_description(skip_list *dictionary, char *word, char *new_description);

/*
 *  Prints all entries with words beginning with prefix in dictionary, using find_node function
 *
 *  @Input:
 *           dictionary pointer: skip_list *,
 *           pointer to placeholder prefix: char *,
 *  @Returns:
 *           operation output: 1 if at least one word found, -1 if no words found
*/
int print_entries(skip_list *dictionary, char *prefix);

#endif //USP_PROJECTS_DICTIONARY_H
