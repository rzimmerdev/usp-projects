#include <bits/stdc++.h>
using namespace std;


int best_fit(string a, string b, int n, int m) {
    vector<vector<int>> fit_table(n + 1, vector<int> (m + 1));

    for (int i = 1; i <= n; i++)
        fit_table[i][0] = i;
    for (int j = 1; j <= m; j++)
        fit_table[0][j] = j;

    int cost = 0;
    int fixed_cost;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1])
                cost = 0;
            else
                cost = 1;

            fixed_cost = min(fit_table[i - 1][j] + 1, fit_table[i][j - 1] + 1);
            fit_table[i][j] = min(fit_table[i - 1][j - 1] + cost, fixed_cost);
        }
    }

    return fit_table[n][m];
}


int main() {

    int t = 1;
    cin >> t;
    string a, b;
    while (t-- > 0) {
        cin >> a >> b;
        cout << best_fit(a, b, a.length(), b.length()) << endl;
    }


    return 0;
}