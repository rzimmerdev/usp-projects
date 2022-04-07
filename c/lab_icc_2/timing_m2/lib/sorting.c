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
void bubble_sort(int *list, int start, int list_size) {

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

void insertion_sort(int *list, int start, int list_size) {

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

void merge_sort(int *list, int start, int list_size) {

    if (list_size > 1) {
        int center = (int) list_size / 2;
        merge_sort(list, start, center);
        merge_sort(list + center, start, list_size - center);
        merge_arrays(list, center, list + center, list_size - center);
    }
}

void swap(int *array, int first, int second) {

    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

int create_partition(int *array, int start, int end) {
    int random = (rand() % (end - start + 1)) + start;
    swap(array, end, random);
    int pivot = array[end];

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (array[j] < pivot) {
            swap(array, ++i, j);
        }
    }

    swap(array, ++i, end);

    return i;
}

int create_partition_center(int *array, int start, int end) {
    int pivot = array[(int) (start + end)/2];

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (array[j] < pivot) {
            swap(array, ++i, j);
        }
    }

    swap(array, ++i, end);

    return i;
}

void quick_sort(int *list, int start, int end) {

    if (start < end) {

        int partition_index = create_partition(list, start, end);

        quick_sort(list, start, partition_index - 1);
        quick_sort(list , partition_index + 1, end);
    }
}

void max_heap(int *list, int parent, int end) {

    int child = parent * 2;

    if (child + 1 > end)
        return;

    int sibling_maxed = child < end && list[child + 1] > list[parent];

    if (list[child] > list[parent] || sibling_maxed) {

        if (child < end && list[child + 1] > list[child])
            child++;

        swap(list, parent, child);

        max_heap(list, child, end);

    }
}

void heap_sort(int *list, int start, int end) {

    int parent = end / 2;

    for (int i = parent; i >= 0; i--) {
        max_heap(list, i, end);
    }

    while (end > 0) {

        swap(list, 0, end);
        end--;
        max_heap(list, 0, end);
    }
}
