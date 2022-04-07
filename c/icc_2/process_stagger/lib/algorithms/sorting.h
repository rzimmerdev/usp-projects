#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

void insertion_sort(int *list, int list_size);

void merge_sort(void *list[], int list_size, int (compare)(void *first, void *second));

#endif
