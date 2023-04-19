/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021
 *
 *  Sorting algorithms library, implementing common sorting algorithms for generic use
*/

#include <stdlib.h>

/*
 *  Function to sort two elements in array given both elements indexes
 *
 *  @Input:
 *         pointer to array object: void **,
 *         index of first element: int,
 *         index of second element: int,
 */
void swap(void **array, int first, int second) {

    void *temp = array[first];
    array[first] = array[second];
    array[second] = temp;

}

/*
 *  Insertion sort for sorting generic array using generic comparison input function
 *
 *  @Input:
 *         pointer to array object: void **,
 *         index in array of start position to sort: int,
 *         index in array of end of partition to sort: int,
 *         function to compare two elements of array: int (*compare)(void *, void *)
 */
void insertion_sort(void **array, int start, int end, int (compare)(void *, void *)) {
	for (int i = start + 1; i <= end; i++) {
        void *value = array[i];

        int j = i - 1;

        while (j >= start && compare(value, array[j]) == -1) {
            swap(array, j + 1, j);
            j--;
        }

        array[j + 1] = value;
    }
}

/*
 *  Function to return index of median (middle value if ordered) between three elements in array
 *
 *  @Input:
 *         pointer to array object: void **,
 *         index of first element: int,
 *         index of second element: int,
 *         index of third element: int,
 *         function to compare two elements of array: int (*compare)(void *, void *)
 *  @Return:
 *         the index of the median between the three input values: int
 */
int triplet_median(void **array, int a, int b, int c, int (compare)(void *, void *)) {
    if (compare(array[a], array[b]) == -1) {
        return compare(array[b], array[c]) == -1 ? b : compare(array[a], array[c]) == -1 ? c : a;
    } else {
        return compare(array[a], array[c]) == -1 ? a : compare(array[b], array[c]) == -1 ? c : b;
    };
}

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
int *create_triple_partition(void **array, int start, int end, int (compare)(void *, void *), int is_random) {
    int median = triplet_median(array, start, end, (int) (start + end)/2, compare);
    int random = (rand() % (end - start + 1)) + start; // NOLINT(cert-msc30-c, cert-msc50-cpp)

    int pivot_index = is_random ? random : median;
    void *pivot = array[pivot_index];

    swap(array, end, pivot_index);

    int j = start;

    // While end has not been reached, compare current value to pivot value
    // and swap if necessary
    while (j <= end) {
        if (compare(array[j], pivot) < 0) {

            swap(array, start, j);
            start++; j++;
        }

        // if value is equal to pivot, as to keep next to pivot (second partition),
        // so all equal to pivot become ordered
        else if (compare(array[j], pivot) == 0) {
            j++;
        }

        else {
            swap(array, j, end);
            end--;
        }
    }

    int *indexes = malloc(2 * sizeof(int));
    indexes[0] = start - 1;
    indexes[1] = j;
    return indexes;
}

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
void uber_sort(void **array, int start, int end, int (compare)(void *, void *), int is_random) {
    if (start < end) {
        if (end - start <= 10) {
            insertion_sort(array, start, end, compare);
        } else {
            int *partition_index = create_triple_partition(array, start, end, compare, is_random);

            uber_sort(array, start, partition_index[0], compare, is_random);
            uber_sort(array, partition_index[1], end, compare, is_random);
            free(partition_index);
        }
    }
}
