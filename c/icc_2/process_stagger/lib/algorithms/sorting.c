/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021
 *
 *  Sorting algorithms library, implementing basic popular sorting algorithms for generic use
*/

#include <string.h>
#include <stdlib.h>

void insertion_sort(int *list, int list_size) {

    for (int i = 1; i < list_size; i++) {

        int value = list[i];
        int j = i - 1;

        while (j >= 0 && value < list[j]) {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = value;
    }
}

void merge_arrays(void **first_array, int first_size, void **second_array, int second_size, int (compare)(void *first, void *second)) {
    void **temp = malloc((first_size + second_size) * sizeof(void *));

    int i = 0, j = 0;

    for (int h = 0; h < (first_size + second_size); h++) {
        if (i >= first_size) {
            *(temp + h) = *(second_array + j);
            j++;
        } else if (j >= second_size) {
            *(temp + h) = *(first_array + i);
            i++;
        } else {
            if (compare(*(first_array + i), *(second_array + j))) {
                *(temp + h) = *(first_array + i);
                i++;
            } else {
                *(temp + h) = *(second_array + j);
                j++;
            }
        }
    }

    memcpy(first_array, temp, (first_size + second_size) * sizeof(void *));
    free(temp);
}

void merge_sort(void **list, int list_size, int (compare)(void *first, void *second)) {

    if (list_size > 1) {
        int center = (int) list_size / 2;
        merge_sort(list, center, compare);
        merge_sort(list + center, list_size - center, compare);
        merge_arrays(list, center, list + center, list_size - center, compare);
    }
}

