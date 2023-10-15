#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 10
#define P 4

void matvec(double matrix[N][N], double x[N], double result[N]);
void matvec_block(const double matrix[N][N], const double x[N], double padded_result[N * P], int offset_i, int offset_j, int block_size);


int main() {
    double matrix[N][N];
    double x[N];
    double result[N] = { 0 };

    for (int i = 0; i < N; i++) {
        x[i] = (i + 1) * 2.0;
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    matvec(matrix, x, result);

    for (int i = 0; i < N; i++) {
        printf("%6.2f\n", result[i]);
    }

    return 0;
}

void matvec(double matrix[N][N], double x[N], double result[N])
{
    int block_size = N / sqrt(P);

    double padded_result[N * P] = {0};

    int i, j;

    #pragma omp parallel for collapse(2) num_threads(P)
    for (i = 0; i < N; i+= block_size)
    {
        for (j = 0; j < N; j += block_size)
        {
            matvec_block(matrix, x, padded_result, i, j, block_size);
        }
    }

    for (i = 0; i < N * P; i++)
    {
        result[i % N] += padded_result[i];
    }
}

void matvec_block(const double matrix[N][N], const double x[N], double padded_result[N * P], int offset_i, int offset_j, int block_size)
{
    int i, j, k;

    for (i = offset_i; i < offset_i + block_size; i++)
    {
        for (j = offset_j; j < offset_j + block_size; j++)
        {
            double s = 0.0;

            #pragma omp simd
            for (k = 0; k < N; k++) {
                s += matrix[i][k] * x[k];
            }
            int thread_num = omp_get_thread_num();
            padded_result[thread_num * N + i] += s;
        }
    }
}
