/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 31/10/2021
 *
 *  Sorting algorithms library, implementing basic popular sorting algorithms for generic use
*/

#include <string.h>
#include <stdlib.h>

/*
 *  Bubble Sort for sorting generic list, using generic compare function
 *
 *  @Input:
 *         pointer to list object: void *,
 *         total elements of list: int,
 *         function to compare two elements of list: void (*compare)(void *, void *)
 */
void bubble_sort(int *list, int list_size) {

	for (int i = 0; i < list_size; i++) {

		for (int j = 1; j < list_size - i; j++) {
			if (list[j - 1] > list[j]) {
				int temp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = temp;
			}
		}
	}
}

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

void merge_arrays(int *first_array, int first_size, int *second_array, int second_size) {
    int temp[first_size + second_size];

    int i = 0, j = 0;

    for (int h = 0; h < (first_size + second_size); h++) {
        if (i >= first_size) {
            temp[h] = second_array[j++];
        } else if (j >= second_size) {
            temp[h] = first_array[i++];
        } else {
            if (first_array[i] < second_array[j]) {
                temp[h] = first_array[i++];
            } else {
                temp[h] = second_array[j++];
            }
        }
    }

    memcpy(first_array, temp, (first_size + second_size) * sizeof(int));
}

void merge_sort(int *list, int list_size) {

    if (list_size > 1) {
        int center = (int) list_size / 2;
        merge_sort(list, center);
        merge_sort(list + center, list_size - center);
        merge_arrays(list, center, list + center, list_size - center);
    }
}

void random_select(void **list, int start, int end, void (change(void *, void *))) {

    int random_index = start + rand() % (end - start);

    change(list[start], list[random_index]);
}

int create_partition(void **list, int start, int end, int (compare)(void *, void *), void (change)(void *, void *)) {

    void *pivot = list[start];

    int i = start + 1;

    for (int j = start + 1; j < end; j++) {
        if (compare(list[j], pivot) == 1) {

            change(list[i], list[j]); i++;
        }
    }

    change(pivot, list[i - 1]);

    return i;
}

void qs_recursive_call(void **list, int start, int end, int (compare)(void *, void *), void (change)(void *, void *)) {

    if (start < end) {

        int partition_index = create_partition(list, start, end, compare, change);

        qs_recursive_call(list, start, partition_index - 1, compare, change);
        qs_recursive_call(list , partition_index + 1, end, compare, change);
    }
}

void quick_sort(void **list, int list_size, int (compare)(void *, void *), void (change)(void *, void *)) {

    qs_recursive_call(list, 0, list_size , compare, change);
}
