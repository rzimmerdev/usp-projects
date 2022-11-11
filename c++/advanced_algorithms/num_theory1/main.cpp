#include <bits/stdc++.h>

using namespace std;

int is_divisor(int n, int m) {

    return false;
}

vector<bool> crive(int n) {

    int s = ceil(sqrt(n));
    vector<bool> primes(s, true);

    for (int i = 2; i < s; i++) {
        if (!primes[i])
            continue;

        for (int p = 2 * i; p < s; p += p) {
            primes[p - 2] = false;
        }
    }

    return primes;
}


vector<int> factorate(int n, vector<bool> primes) {
    int s = ceil(n / 2);

    if (!primes[0])
        primes = crive(n);

    vector<int> factors(s);

    for (int i = 2; i <= s; i++) {
        if (!primes[i - 2])
            continue;
        while (n % i == 0) {
            n /= i;
            factors[i - 2]++;
        }
    }

    return factors;
}


int prime_factorial(int n, vector<bool> primes) {
    int s = ceil(n / 2);
    vector<int> factors(s);

    for (int i = 2; i < n; i++) {
        factors +=
    }
}


int main() {

    int n, m;
    vector<bool> primes = crive(INT_MAX);

    while (cin >> n >> m) {
        string result = is_divisor(m, n) ? "divide" : "does not divide";
        cout << m << " " << result << " " << n << "!" << endl;
    }



    return 0;
}