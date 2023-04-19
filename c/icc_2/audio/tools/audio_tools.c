#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex *discrete_fourier_transform(unsigned char *wav, int size) {
    double complex *coefficient = (double complex *) calloc(size, sizeof(double complex));

    for (int k = 0; k < size; k++) {
        for (int n = 0; n < size; n++) {
            coefficient[k] += wav[n] * cexp((-2.0 * M_PI * (((k + 1.0) * n * 1.0) / (size * 1.0))) * _Complex_I);
        }
    }
    return coefficient;
}

double component_magnitude(double complex coefficient) {

	return sqrt(pow(creal(coefficient), 2) + pow(cimag(coefficient), 2));

}

double complex *inverse_fourier_transform(double complex *coefficients, int size) {

	double complex *values = (double complex *) calloc(size, sizeof(double complex));

	for (int n = 0; n < size; n++) {
		for (int k = 0; k < size; k++) {
			values[n] += coefficients[k] * cexp((2.0 * M_PI * (((k + 1) * n * 1.0) / (size * 1.0))) * _Complex_I);

		} values[n] = values[n] / (size * 1.0);
	}

	return values;

}