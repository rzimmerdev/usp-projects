#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

void bubble_sort(int *list, int list_size);

void insertion_sort(int *list, int list_size);

void merge_sort(int *list, int list_size);

void quick_sort(void **list, int list_size, int (compare)(void *, void *), void (change)(void *, void *));

#endif
