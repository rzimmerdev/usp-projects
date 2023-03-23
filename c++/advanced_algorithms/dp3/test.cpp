#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> dp(h + 1, vector<int>(w + 1));
    dp[0][1] = 1;

    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++) {
            if (s[j - 1] == '.')
                (dp[i][j] = dp[i - 1][j] + dp[i][j - 1]) %= MOD;
        }
    }
    cout << dp[h][w];
}
