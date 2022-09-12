#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

bool find_word(int n, int m, char **matrix, int word_size, const string &word) {



    return false;
}

int main() {

    int n, m, i, j;
    cin >> n >> m;

    char **chars = (char **) malloc(n * sizeof(char * ));

    for (i = 0; i < n; i++) {

        chars[i] = (char *) malloc(m * sizeof(char));

        for (j = 0; j < m; j++) {

            cin >> chars[i][j];
        }
    }

    int word_size;
    string word;

    cin >> word_size;
    cin >> word;

    cout << (find_word(n, m, chars, word_size, word) ? "Yes" : "No");

    return 0;
}