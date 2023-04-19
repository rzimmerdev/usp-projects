#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sorting.h"

// <time.h> for measuring time consumed by specific algorithm

#define TOTAL_CASES 10

int *ascending_order_list(int size);
int *descending_order_list(int size);

int *random_list(int size);

double average_time(void (*function)(int *, int), int list_size, int is_descending);

int main() {

	srand(time(NULL));

	// First experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 1000 elementos ordenados decrescentemente\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 1000, 1));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 1000, 1));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 1000, 1));

	// Second experiment
	printf("\n--------------------------------------------\n");
	printf("\nVetor de 1000 elementos ordenados crescentemente\n");
	printf("Bubble Sort: %lfs\n", average_time(bubble_sort, 1000, 0));
	printf("Insertion Sort: %lfs\n", average_time(insertion_sort, 1000, 0));
	printf("Merge Sort: %lfs\n", average_time(merge_sort, 1000, 0));
	printf("\n--------------------------------------------\n");
}

int *random_list(int size) {
	int *temp = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		temp[i] = rand() % size;
	}

	return temp;
}

int *ascending_order_list(int size) {
	int *temp = malloc(sizeof(int) * size);

	temp[0] = rand() % size;

	for (int i = 1; i < size; i++) {
		temp[i] = rand() % size + temp[i - 1];
	}

	return temp;
}

int *descending_order_list(int size) {
	int *temp = malloc(sizeof(int) * size);

	temp[0] = (size * size) - (rand() % size);
	for (int i = 1; i < size; i++) {
		temp[i] = temp[i - 1] - (rand() % size);
	}

	return temp;
}

double average_time(void (*function)(int *, int), int list_size, int is_descending) {

	double total_time;

	clock_t start, end;

	int *list = is_descending == 1 ? descending_order_list(list_size) : ascending_order_list(list_size);

	for (int i = 0; i < TOTAL_CASES; i++) {
		start = clock();
		function(list, list_size);
		total_time += (double) (clock() - start) / CLOCKS_PER_SEC;
	}

	free(list);

	return total_time / TOTAL_CASES;
}