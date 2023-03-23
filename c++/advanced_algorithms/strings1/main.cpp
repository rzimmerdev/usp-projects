#include <bits/stdc++.h>

using namespace std;


vector<int> count_matches(string original, string pattern) {

    int i = 0;
    vector<int> matches;

    int n = (int) original.length();
    int m = (int) pattern.length();

    while (i < n) {
        int pos = i;
        while (pos < n && pos - i < m && original[pos] == pattern[pos - i])
            pos++;

        if (pos - i == m)
            matches.push_back(i);
        i++;
    }

    return matches;
}


vector<int> lps_vec(const string& pattern) {

    int pos = 0, i = 1, n = (int) pattern.size();
    vector<int> lps(n);

    while (i < n) {
        if (pattern[i] == pattern[pos])
            lps[i++] = ++pos;
        else if (pos != 0)
            pos = lps[pos - 1];
        else
            lps[i++] = 0;
    }

    return lps;
}

vector<int> kmp(string original, string pattern) {

    int n = (int) original.size(), m = (int) pattern.size();

    vector<int> lps = lps_vec(pattern);
    vector<int> matches;

    int i = 0, j = 0;

    while (m - j <= n - i) {

        if (original[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != original[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i += 1;
        }
    }

    return matches;
}



int main() {
    int t;
    cin >> t;

    while (t--) {

        string original, pattern;
        cin >> original >> pattern;

        vector<int> matches = kmp(original, pattern);

        if (!matches.empty()) {
            cout << matches.size() << endl;
            for (auto c : matches)
                cout << c + 1 << " ";
            cout << endl;
        }
        else
            cout << "Not Found" << endl;
        cout << endl;
    }

    return 0;
}