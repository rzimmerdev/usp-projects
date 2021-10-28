#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "../tools/audio_tools.h"

// Merges two arrays, keeping descending order from both arrays, as well as updating original index of the
// component at respective index at original_indexes array
void merge_arrays(double complex *first_array, int first_size, double complex *second_array, int second_size, int *original_indexes) {
    double complex temporary[first_size + second_size];

    int index_temporary[first_size + second_size];

    int i = 0, j = 0;

    // First, verify if one of the two halved arrays have already been iterated through, in which case
    // all their values have been copied and only the other array values remain
    // If both arrays are still being iterated through, decide which of the two top values are bigger
    // and copy it to temporary array
    for (int h = 0; h < (first_size + second_size); h++) {
        if (i >= first_size) {
        	index_temporary[h] = (original_indexes + first_size)[j];
            temporary[h] = second_array[j++];
        } else if (j >= second_size) {
        	index_temporary[h] = original_indexes[i];
            temporary[h] = first_array[i++];
        } else {
            if (component_magnitude(first_array[i]) > component_magnitude(second_array[j])) {
            	index_temporary[h] = original_indexes[i];
                temporary[h] = first_array[i++];
            } else {
            	index_temporary[h] = (original_indexes + first_size)[j];
                temporary[h] = second_array[j++];
            }
        }
    }

	memcpy(original_indexes, index_temporary, (first_size + second_size) * sizeof(int));
    memcpy(first_array, temporary, (first_size + second_size) * sizeof(double complex));
}

// Splits original list into two halves, performs merge sort on halves and merges ordered arrays, keeping
// the two arrays ordered using merge_arrays function
void merge_sort(double complex *list, int *original_indexes, int list_size) {

    if (list_size > 1) {
        int center = (int) list_size / 2;
        merge_sort(list, original_indexes, center);
        merge_sort(list + center, original_indexes + center, list_size - center);
        merge_arrays(list, center, list + center, list_size - center, original_indexes);
    }
}