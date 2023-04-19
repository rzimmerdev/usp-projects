#ifndef ALGORITHMS_SORTING_H
#define ALGORITHMS_SORTING_H

void insertion_sort(void **array, int start, int end, int (compare)(void *, void *));

/*
 *  Function to create three partitions (one with smaller elements, one with bigger and one with repeated values),
 *  given random pivot or median pivot between start, end and center indexes
 *
 *  @Input:
 *         pointer to array object: void **,
 *         index of starting position in array to partition: int,
 *         index of ending position in array to partition: int,
 *         function to compare two elements of array: int (*compare)(void *, void *)
 *         boolean int to specify pivot selection
 *  @Return:
 *         array with both partition indexes
 */
void uber_sort(void **array, int start, int end, int (compare)(void *, void *), int is_random);

#endif
