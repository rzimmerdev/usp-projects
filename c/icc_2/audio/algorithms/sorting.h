#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

// Merge sort specifically designed to order a fourier transformed array respective to each component magnitude
// takes in pointer to original in-order index array, as to set new ordered array indexes, in case
// user wants to reinsert values into original position
void merge_sort(double complex *list, int *original_indexes, int list_size);

#endif
