#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sorting.h"

// <time.h> for measuring time consumed by specific algorithm

#define TOTAL_CASES 10

int *random_list(int size);

double average_time(void (*function)(int *, int), int list_size);

int main() {

	srand(time(NULL));

	// First experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 25 elementos aleatorios entre 0 e 25\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 25));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 25));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 25));
	printf("\n--------------------------------------------\n");

	// Second experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 100 elementos aleatorios entre 0 e 100\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 100));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 100));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 100));
	printf("\n--------------------------------------------\n");

	// Third experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 1000 elementos aleatorios entre 0 e 1000\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 1000));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 1000));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 1000));
	printf("\n--------------------------------------------\n");

	// Fourth experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 10000 elementos aleatorios entre 0 e 10000\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 10000));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 10000));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 10000));
	printf("\n--------------------------------------------\n");

	printf("\n--------------------------------------------\n");
	printf("\nVetor de 10000 elementos aleatorios entre 0 e 7500\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 7500));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 7500));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 7500));
	printf("\n--------------------------------------------\n");
}

int *random_list(int size) {
	int *temp = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		temp[i] = rand() % (int) (size * 2);
	}

	return temp;
}

double average_time(void (*function)(int *, int), int list_size) {

	double total_time;

	clock_t start, end;

	int *list = random_list(list_size);

	for (int i = 0; i < TOTAL_CASES; i++) {
		start = clock();
		function(list, list_size);
		end = clock();
		total_time += (double) (clock() - start) / CLOCKS_PER_SEC;
	}

	free(list);

	return total_time / TOTAL_CASES;
}