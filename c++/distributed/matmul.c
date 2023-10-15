#include <stdio.h>
#include <stdlib.h>


int main() {

    int n = 2;

    double x[n];
    double y[n];

    double A[n][n];

    int i, j;
    double v;

    for (i = 0; i < n; i++) {
        x[i] = rand() / 1e9;
        for (j = 0; j < n; j++) {
            v = rand() / 1e9;

            A[i][j] = v;

            printf("%f ", v);
        }
        printf("   %f\n", x[i]);
    }

    // y = A @ x
    #pragma omp parallel for
    for (i = 0; i < n; i++) {

        double s = 0.0;

        #pragma omp simd reduction(+:s)
        for (j = 0; j < n; j++) {
            s += A[i][j] * x[j];
        }

        y[i] = s;
    }

    printf("\n");

    for (i = 0; i < n; i++)
        printf("%f\n", y[i]);

    return 0;
}