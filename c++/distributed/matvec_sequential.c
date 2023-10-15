#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define n 2
#define p 2

int main() {

    double A[n][n];
    double x[n], y[n];

    int i = 0, j = 0;
    double a, b;

    for (i = 0; i < n; i++) {
        b = rand() / 1e9;
        x[i] = b;
        for (j = 0; j < n; j++) {
            a = rand() / 1e9;
            A[i][j] = a;
            printf("%f ", a);
        }
        printf("  %f\n", b);
    }
    printf("\n");
    int block_size = n / (int) sqrt(p);

    for (i = 0; i < n; i++) {
        double s = 0.0;

        for (j = 0; j < n; j++) {
            s += A[i][j] * x[j];
        }

        y[i] = s;
    }

    for (i = 0; i < n; i++)
        printf("%f\n", y[i]);

    return 0;
}