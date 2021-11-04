/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 04/11/2021
 *  Project for Algorithms and Data Structures - SCC0202, "Projeto 1: Dicionários"
*/

#include <stdio.h>
#include <stdlib.h>

#include "libraries/algorithms/sorting.h"

#define t_size 20

int compare(void *first, void *second) {

    return *(int *) first < *(int *) second;
}

void change(void *first, void *second) {

    int temp = *(int *) first;
    *(int *) first = *(int *) second;
    *(int *) second = temp;

}

int main() {

    void **array = malloc(sizeof(int *) * t_size);

    srand(42);

    for (int i = 0; i < t_size; i++) {

        int *curr = malloc(sizeof(int));
        *curr = rand() % t_size;

        array[i] = curr;
    }

    quick_sort(array, t_size, compare, change);

    for (int i = 0; i < t_size; i++) {

        printf("%d ", *(int *) array[i]);
    }

    printf("\n");

    printf("%d ", compare(array[0], array[t_size - 1]));

    return 0;
}