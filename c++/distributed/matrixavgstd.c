#include <stdlib.h>
#include <stdio.h>

#define N 3
#define P 4

int main() {

    double A[N][N];
    int i, j;

    double a;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a = (double) random() / 1e9;
            A[i][j] = a;
            printf("%.2f ", a);
        }
        printf("\n");
    }

    double avg = 0;
    #pragma omp parallel for num_threads(P) reduction(+:avg)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            avg += A[i][j];
        }
        printf("\n");
    }
    avg /= N * N;

    printf("%.2f", avg);

    return 0;
}