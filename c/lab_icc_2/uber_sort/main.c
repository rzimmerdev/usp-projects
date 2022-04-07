/*
 *  Property of Rafael Zimmer, rzimmerdev, nUsp 12542612
 *  Created 04/11/2021
 *  Project for Laboratório de Introdução à Ciência da Computação II - SCC0220 , "[Módulo 2] Übersort"
*/

#include <stdio.h>
#include <stdlib.h>

#include "libraries/algorithms/sorting.h"

enum operations {
    MEDIA_DE_TRES = 1,
    RANDOMICO = 2
};

int compare(void *first, void *second) {
    if (*(int *) first < *(int *) second) {
        return -1;
    } else if (*(int *) first == *(int *) second) {
        return 0;
    } else {
        return 1;
    }
}

int main() {

    srand(42);

    int array_size, operation_type;

    scanf("%d ", &array_size);
    scanf("%d ", &operation_type);

    void **array = malloc(sizeof(int *) * array_size);

    for (int i = 0; i < array_size; i++) {

        int *curr = malloc(sizeof(int));
        scanf("%d ", curr);

        array[i] = curr;
    }

    // Decide which kind of pivot selection to use
    // be it random, or using triplet median
    switch(operation_type) {
        case (MEDIA_DE_TRES):
            uber_sort(array, 0, array_size - 1, compare, 0);
            break;
        case (RANDOMICO):
            uber_sort(array, 0, array_size - 1, compare, 1);
            break;
    }

    // Print resulting sorted array after uber_sort
    for (int i = 0; i < array_size; i++) {

        printf("%d\n", *(int *) array[i]);
        free(array[i]);
    }
    free(array);

    return 0;
}