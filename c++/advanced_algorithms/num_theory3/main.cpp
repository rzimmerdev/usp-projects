#include <bits/stdc++.h>

using namespace std;


int main() {
    int k = 131071, i, e, r;
    char b;

    bitset<10000> num;

    while ((cin >> b) && b != '#') {
        num.set(0, b == '1');
        i = 1;

        while ((cin >> b) && b != '#') {
            num.set(i++, b == '1');
        }

        e = i, r = 0;
        while (--e >= 0) {
            r = (r * 2 + num[e]) % k;
        }

        cout << (r == 0 ? "YES" : "NO") << endl;
    }
}