// Rafael Zimmer, nUsp 12542612
// Project for Introduction to Computer Science - SCC0201, "Trabalho 02: Audio"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "tools/io_tools.h"
#include "tools/audio_tools.h"
#include "algorithms/sorting.h"

typedef enum { false, true } bool;

void print_negatives_amount(double complex *coefficients, int total_size);
void filter_nth_biggest(double complex *coefficients, int total_size, int total_coefficients, bool print_biggest);

int main() {

	// Scan input values, as well as .wav audio file
	char *file_name = scan_line();
	int total_coefficients;
	scanf("%d ", &total_coefficients);

	int total_size;
	unsigned char *wav = read_wav(file_name, &total_size);
	printf("%d\n", total_size);

	// Perform fourier transform, as well selecting biggest coefficients from .wav file
	double complex *coefficients = discrete_fourier_transform(wav, total_size);
	free(wav);

	print_negatives_amount(coefficients, total_size);

	bool print_biggest = true;
	filter_nth_biggest(coefficients, total_size, total_coefficients, print_biggest);

	// Invert filtered array of fourier transformed components
	double complex *inverse_transform = inverse_fourier_transform(coefficients, total_size);
	free(coefficients);

	// Write to compressed.wav the values of the fourier inverted array
	unsigned char *compressed_wav = malloc(total_size * sizeof(unsigned char));

	for (int i = 0; i < total_size; i++) {
		compressed_wav[i] = (unsigned char) creal(inverse_transform[i]);
	} free(inverse_transform);

	write_wav(file_name, "compressed.wav", compressed_wav, total_size);
	free(file_name); free(compressed_wav);

	return 0;

}

// Print total amount of components with both real and imaginary parts smaller than zero
void print_negatives_amount(double complex *coefficients, int total_size) {
	int total_negatives = 0;
	for (int i = 0; i < total_size; i++) {
		total_negatives += (creal(coefficients[i]) <= 0.0 && cimag(coefficients[i]) <= 0.0);
	}

	printf("%d\n", total_negatives);
}

// Function for filtering total_size coefficients, based on components with biggest magnitude, and return in-place
// array of total_coefficients coefficients with biggest magnitude, setting the values of the remaining
// (total_size - total_coefficients) coefficients to 0 , as well as allowing user to print ordered biggest coefficients
void filter_nth_biggest(double complex *coefficients, int total_size, int total_coefficients, bool print_biggest) {
	int *original_indexes = malloc(total_size * sizeof(int));

	for (int i = 0; i < total_size; i++) {
		original_indexes[i] = i;
	}

	merge_sort(coefficients, original_indexes, total_size);

	double complex *temporary = malloc(total_coefficients * sizeof(double complex));
	memmove(temporary, coefficients, total_coefficients * sizeof(double complex));

	memset(coefficients, 0, sizeof(double complex) * total_size);

	if (print_biggest) {
		for (int i = 0; i < total_coefficients; i++) {
			printf("%d\n", (int) component_magnitude(temporary[i]));
			coefficients[original_indexes[i]] = temporary[i];
		}
	} else {
		for (int i = 0; i < total_coefficients; i++) {
			coefficients[original_indexes[i]] = temporary[i];
		}
	}

	free(original_indexes);
	free(temporary);
}