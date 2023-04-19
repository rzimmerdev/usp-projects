#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) {
    if (b > a)
        return gcd(b, a);
    return (b == 0 ? a : gcd(b, a % b));
}


int main() {

    int next, prev, diff, ld;

    while ((cin >> next) && next != 0) {
        prev = next, ld = 0;

        while ((cin >> next) && next != 0) {
            diff = (abs(next - prev)); prev = next;
            ld = gcd(ld, diff);
        }

        cout << ld << endl;
    }

    return 0;
}