#include <bits/stdc++.h>
using namespace std;


int weighted_lcs(string a, string b, int n, int m, vector<int> weights) {
    vector<vector<int>> lcs_table(n + 1, vector<int> (m + 1));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {

            char c = a[i - 1];
            if (a[i - 1] == b[j - 1])
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + weights[(int) (c - 'a')];
            else
                lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
        }
    }

    return lcs_table[n][m];
}


int main() {

    int n, m;
    vector<int> prices(26);
    string a, b;

    cin >> n >> m;
    for (int i = 0; i < 26; i++)
        cin >> prices[i];

    cin >> a >> b;

    cout << weighted_lcs(a, b, n, m, prices);

    return 0;
}