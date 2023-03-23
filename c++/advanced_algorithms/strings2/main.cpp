#include <bits/stdc++.h>

using namespace std;


void insert(vector<vector<int>> *trie, const string& s) {
    int node = 0, c;

    for (char i : s) {
        c = i - 'a';

        if (!(*trie)[node][c]) {
            (*trie)[node][c] = (int) (*trie).size();
            vector<int> child(28);
            (*trie).push_back(child);
        }
        (*trie)[node][26] += 1;
        node = (*trie)[node][c];
    }
    (*trie)[node][26] += 1;
    (*trie)[node][27] = -1;
}


void remove(vector<vector<int>> *trie, const string& s) {
    int node = 0, c;

    for (char i : s) {
        c = i - 'a';
        (*trie)[node][26] -= 1;
        node = (*trie)[node][c];
    }
    (*trie)[node][26] -= 1;
    (*trie)[node][27] = 0;
}


int matches(vector<vector<int>> &trie, const string& s) {
    int node = 0, c;

    for (char i : s) {
        c = i - 'a';

        if (!trie[node][c])
            return 0;

        node = trie[node][c];
    }

    return trie[node][26];
}


int main() {

    int q, t; cin >> q;
    string s;

    vector<vector<int>> trie;
    vector<int> root(28);
    trie.push_back(root);

    while (q-- > 0) {
        cin >> t >> s;
        switch (t) {
            case 1:
                insert(&trie, s);
                break;
            case 2:
                remove(&trie, s);
                break;
            case 3:
                cout << matches(trie, s) << endl;
                break;
            default:
                break;
        }
        t++;
    }


    return 0;
}