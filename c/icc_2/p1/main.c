#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG 0

int binary_search(int *array, int size, int target) {
	int low = 0, high = size - 1;
	int index = -1;

	while (low <= high) {
		int center = (low + high)/2;

		if (target == array[center])
		{
			index = center;
			high = center - 1;
		}

		else if (target < array[center]) {
			high = center - 1;
		}

		else {
			low = center + 1;
		}
	}

	return index;
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

unsigned int* search_and_count_optimized(int** matriz, int* vetor, int m, int z) {

	unsigned int *freq = calloc(z, sizeof(unsigned int));
	int array[m * m];

	for (int i = 0; i < m - 1; i++) {

		merge_sort(matriz[i] + i, m - i);
		merge_arrays(matriz[i], i, matriz[i] + i, m - i);
		for (int j = 0; j < m; j++) {
			array[i * m + j] = matriz[i][j];
		}
	}
	for (int k = 0; k < z; k++) {

		int index = binary_search(array, m * m, vetor[k]);
		while (array[index] == vetor[k]) {
			freq[k]++;
			index++;
		}
	}
	return freq;
}

int** alloc_matrix(int m) {
	int **mat = malloc(sizeof(int*)*m);
	srand(m);

	int in = 0;
	// aloca matriz ordenada
	for (int i = 0; i < m; i++) {
		mat[i] = malloc(sizeof(int)*m);
		for (int j = 0; j < m; j++) {
			if (i == j) in+= (rand()%3)+1;
			else in += rand()%3;
			mat[i][j] = in;
		}
	}
	// desordena matriz triangular superior
	for (int i = 0; i < m-2; i++) {
		for (int j = i+1; j < m-1; j++) {
			int swaps = (int)((m-j)/2.0)+1;
			for (int t = 1; t <= swaps; t++) {
				int a = (rand()%(m-j))+j;
				int b = (rand()%(m-j))+j;
				int tmp = mat[i][a];
				mat[i][a] = mat[i][b];
				mat[i][b] = tmp;
			}
		}

	}
	return mat;
}

int* alloc_vec(int z) {
	int *vet = malloc(sizeof(int)*z);
	srand(z);
	vet[0] = rand()%2;
	for (int i = 1; i < z; i++) {
		vet[i] = vet[i-1]+(rand()%9)+1;
	}
	return vet;
}


int main (int argc, char* argv[]) {

	int m;
	int z;
	scanf("%d", &m);
	scanf("%d", &z);

	int** mat = alloc_matrix(m);
	int* vet = alloc_vec(z);

	unsigned int* c = search_and_count_optimized(mat, vet, m, z);

	for (int i = 0; i < z; i++) printf("%hu ", c[i]);
	printf("\n");

	for (int i = 0; i < m; i++) free(mat[i]);
	free(mat);
	free(vet);

	return 0;
}
