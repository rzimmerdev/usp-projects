#include <stdio.h>
#include <omp.h>

int main() {
    int n = 11;

    int sum = 0;

    #pragma omp parallel for num_threads(4) reduction(+:sum)
    for (int i = 0; i < n; i++) {
        int t = omp_get_thread_num();
        printf("%d: %d\n", t, i);
        sum += i;
    }

    printf("The sum of values from 0 to 10 using SIMD is: %d\n", sum);

    return 0;
}
