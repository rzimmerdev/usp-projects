#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "lib/sorting.h"

// <time.h> for measuring time consumed by specific algorithm

#define TOTAL_CASES 10

int *random_list(int size);

double average_time(void (*function)(int *, int, int), int list_size);

int compare(void *first, void *second) {
    if (*(int *) first < *(int *) second) {
        return -1;
    } else if (*(int *) first > *(int *) second) {
        return 1;
    } else return 0;
}

int main() {

	srand(time(NULL));

    printf("\n--------------------------------------------\n");
    printf("\nVetor de 100 elementos aleatorios entre 0 e 100\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 100));
    printf("Quick Sort: %lfs\n", average_time(quick_sort, 100));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 100));
    printf("Merge Sort: %lfs\n", average_time(merge_sort, 100));
    printf("\n");
	printf("\nVetor de 1000 elementos aleatorios entre 0 e 1000\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 1000));
	printf("Quick Sort: %lfs\n", average_time(quick_sort, 1000));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 1000));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 1000));
	printf("\n");
	printf("\nVetor de 2500 elementos aleatorios entre 0 e 2500\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 2500));
	printf("Quick Sort: %lfs\n", average_time(quick_sort, 2500));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 2500));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 2500));
	printf("\n");
	printf("\nVetor de 5000 elementos aleatorios entre 0 e 5000\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 5000));
	printf("Quick Sort: %lfs\n", average_time(quick_sort, 5000));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 5000));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 5000));
	printf("\n");
	printf("\nVetor de 7500 elementos aleatorios entre 0 e 7500\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 7500));
	printf("Quick Sort: %lfs\n", average_time(quick_sort, 7500));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 7500));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 7500));
	printf("\n");
	printf("\nVetor de 10000 elementos aleatorios entre 0 e 10000\n");
    printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 10000));
	printf("Quick Sort: %lfs\n", average_time(quick_sort, 10000));
    printf("Heap Sort: %lfs\n", average_time(heap_sort, 10000));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 10000));
	printf("\n--------------------------------------------\n");
}

int *random_list(int size) {
	int *temp = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		temp[i] = rand() % (int) (size * 2);
	}

	return temp;
}

int *ordered_list(int size) {
    int *temp = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        temp[i] = rand() % (int) (size * 2) + ((i > 1) ? temp[i - 1] : 0);
    }

    return temp;
}

double average_time(void (*function)(int *, int, int), int list_size) {

	double total_time;

	clock_t start, end;

	int *list = random_list(list_size);

	for (int i = 0; i < TOTAL_CASES; i++) {
		start = clock();
		function(list, 0, list_size - 1);
		end = clock();
		total_time += (double) (clock() - start) / CLOCKS_PER_SEC;
	}

	free(list);

	return total_time / TOTAL_CASES;
}