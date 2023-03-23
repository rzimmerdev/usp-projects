#include <bits/stdc++.h>

using namespace std;


int binary_sum(const vector<int>& rows) {
    int n = 0;
    for (auto i : rows)
        n ^= i;

    return n;
}


int cost(const vector<int>& rows, int x) {
    int cost = INT_MAX;
    for (auto i : rows)
        cost = min(cost, abs(i - (x ^ i)));

    return cost;
}


int main() {

    int t, m, i;
    cin >> t;

    while (t--) {
        cin >> m;
        vector<int> rows(m);

        for (i = 0; i < m; i++)
            cin >> rows[i];

        int x = binary_sum(rows);

        cout << !x << endl;
    }

    return 0;
}