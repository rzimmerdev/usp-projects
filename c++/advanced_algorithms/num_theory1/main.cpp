#include <bits/stdc++.h>

using namespace std;


pair<vector<bool>, vector<int>> crive(int n) {
    vector<bool> primes(n, true);
    vector<int> idx;

    for (int i = 2; i < n; i++) {
        if (!primes[i])
            continue;
        idx.push_back(i);
        for (int p = i << 1; p < n; p += i) {
            primes[p] = false;
        }
    }

    return make_pair(primes, idx);
}


bool is_divisor(int m, int n, const pair<vector<bool>, vector<int>>& primes) {
    vector<int> idx = primes.second;
    int total_primes = (int) idx.size();

    int current_prime, m_i, n_i;

    for (int i = 0; i < total_primes && idx[i] <= (int) sqrt(m); i++) {

        current_prime = idx[i];

        if (m % current_prime != 0)
            continue;

        m_i = 0, n_i = 0;

        while (m % current_prime == 0) {
            m /= current_prime;
            m_i++;
        }

        long long int to_divide = current_prime;
        while (to_divide <= n) {
            n_i += (int) (n / to_divide);
            to_divide *= current_prime;
        }

        if (n_i < m_i)
            return false;
    }
    return (n >= m && m != 0) || m == 1;
}


int main() {

    int n, m;
    pair<vector<bool>, vector<int>> primes = crive(50000);

    while (cin >> n >> m) {
        string result = is_divisor(m, n, primes) ? "divides" : "does not divide";
        cout << m << " " << result << " " << n << "!" << endl;
    }

    return 0;
}