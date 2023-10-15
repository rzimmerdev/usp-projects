#include <iostream>
#include <vector>


int primes(int n, bool parallel) {
    std::vector<int> sieve(n, 1);

    int i, k;

    sieve[0] = 0;
    sieve[1] = 0;

    #pragma omp parallel for num_threads(4) shared(n, sieve) private(k) if(parallel)
    for (i = 2; i < n; i++ )
    {
        if (sieve[i] == 0)
            continue;
        sieve[i] = 0;

        for (k = i * i; k < n;)
        {
            sieve[k] = 0;
            k += i;
        }
    }


    int c = 0;
    for (i = 0; i < n; i++)
    {
        if (sieve[i] == 1)
            c++;
        std::cout << i << ": " << sieve[i] << ", ";
    }

    return c;
}

int main() {

    std::cout << "Hello World!" << std::endl;

    primes(100, false);

    return 0;
}