#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, i, size;
    string s;

    cin >> t;

    while (t--) {

        cin >> s;
        size = (int) s.size();

        for (i = 0; i < size; i += 2)
            if (s[i] == 'a')
                s[i] = 'b';
            else
                s[i] = 'a';

        for (i = 1; i < size; i += 2)
            if (s[i] == 'z')
                s[i] = 'y';
            else
                s[i] = 'z';

        cout << s << endl;
    }

    return 0;
}