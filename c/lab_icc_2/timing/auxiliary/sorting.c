#include <stdlib.h>
#include <string.h>

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