#ifndef WORD_FREQUENCY_LIST_H
#define WORD_FREQUENCY_LIST_H

// List type for storing total elements, starting and ending pointers
typedef struct list List_t;

// Allocate memory for list type, as well as initialize list elements array and list size to 0
List_t *create_list();

// Returns total size of list
int get_size(List_t *list);

// Reallocates list and inserts value into end
void insert_list(List_t *list, int value);

// Returns value at list->elements[index]
int search_list(List_t *list, int index);

// Frees allocated list elements and list type
void free_list(List_t *list);

#endif //WORD_FREQUENCY_LIST_H