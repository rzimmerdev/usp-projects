#include <iostream>
#include <utility>
#include <vector>
#include <omp.h>
#include <cstdlib>


double time_it(double (*f)(int n, std::vector<int> a), int n, std::vector<int> a) {
    double wtime;
    wtime = omp_get_wtime ( );
    f(n, std::move(a));
    wtime = omp_get_wtime ( ) - wtime;
    return wtime;
}


double for_reduce(int n, std::vector<int> a) {
    int b = 0;
    #pragma omp parallel for num_threads(5) reduction(+:b) default(none) shared(a, n)
    for (int i = 0; i < n; ++i) {
        b = a[i];
    }
    return b;
}

double for_critical(int n, std::vector<int> a) {
    int b = 0;
    #pragma omp parallel for num_threads(5) default(none) shared(a, n) private(b)
    for (int i = 0; i < n; ++i) {
        #pragma omp critical
        b = a[i];
    }
    return b;
}


std::vector<int> perfect_numbers(int n, int v) {
    std::vector<int> res;
    int i, j;
    #pragma omp parallel for num_threads(v) schedule(dynamic, 1) default(none) shared(v, n, res)
    for (i = 1; i < n; i++) {

        int sum = 0;

        #pragma omp parallel for reduction(+:sum) num_threads(v) default(none) shared(v, n, res) private(i)
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == i) {
            res.push_back(i);
        }
    }

    return res;
}


std::vector<double> mul(const std::vector<double>& a, const std::vector<double>& b) {
    size_t n = a.size();
    std::vector<double> c(n);

    #pragma omp parallel for num_threads(8) schedule(dynamic, 1)
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] * b[i];
    }

    return c;
}

std::vector<std::vector<double>> mat_mul(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    size_t n = a.size();
    size_t m = b.size();
    size_t K = b[0].size();
    std::vector<std::vector<double>> c(n, std::vector<double>(m));

    int i, j, k;

    # pragma omp parallel shared ( a, b, c) private ( i, j, k )
    {
        # pragma omp for collapse(2)
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < K; j++ )
            {
                c[i][j] = 0.0;
                for ( k = 0; k < m; k++ )
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    return c;
}


std::vector<std::vector<double>> random_matrix(int n, int m) {
    std::vector<std::vector<double>> c(n, std::vector<double>(m));

    int i, j;

    #pragma omp parallel private(i, j) num_threads(16)
    {
        #pragma omp for collapse(2) schedule(dynamic, 1)
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                c[i][j] = (double) (random() % 100);
            }
        }
    }

    return c;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    int thread_num = omp_get_max_threads ( );
    std::cout << "thread_num: " << thread_num << std::endl;

    int n = 10000;
    int m;
    std::vector<int> a(n);

    #pragma omp parallel for num_threads(5)
    for (int i = 0; i < n; ++i) {
        a[i] += i;
    }

    std::cout << "for_reduce: " << time_it(for_reduce, n, a) << std::endl;
    std::cout << "for_critical: " << time_it(for_critical, n, a) << std::endl;

    double wtime;
    wtime = omp_get_wtime ( );
    std::vector<int> perfect = perfect_numbers(n, 16);
    wtime = omp_get_wtime ( ) - wtime;

    std::cout << "perfect_numbers: " << wtime << std::endl;

    for (int i : perfect) {
        std::cout << i << std::endl;
    }

    n = 1000;
    m = 1000;
    std::vector<std::vector<double>> a1 = random_matrix(n, m);
    std::vector<std::vector<double>> b1 = random_matrix(m, n);

    wtime = omp_get_wtime ( );
    std::vector<std::vector<double>> c1 = mat_mul(a1, b1);
    wtime = omp_get_wtime ( ) - wtime;

    std::cout << "mat_mul: " << wtime << std::endl;

    return 0;
}
