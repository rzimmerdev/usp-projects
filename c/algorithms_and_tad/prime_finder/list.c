#include <stdlib.h>

typedef struct list {
	int *elements;
	int size;

} List_t;

List_t *create_list() {

	List_t *list = (List_t *) malloc(sizeof(List_t));
	list->elements = malloc(0 * sizeof(int *));
	list->size = 0;

	return list;
}

int get_size(List_t *list) {
	return list->size;
}

void insert_list(List_t *list, int value) {
	list->elements = realloc(list->elements, ++(list->size) * sizeof(int));
	list->elements[list->size - 1] = value;
}

int search_list(List_t *list, int index) {
	return list->elements[index > list->size ? list->size : index];
}

void free_list(List_t *list) {
	list->elements;
	free(list);
}