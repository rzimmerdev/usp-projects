#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli double_area(vector<pair<lli, lli>> points) {

    lli total_area = 0;
    int n = (int) points.size();
    int prev = n - 1;

    for (int i = 0; i < n; i++) {

        lli segment_area = (points[prev].first + points[i].first);
        segment_area *= (points[prev].second - points[i].second);
        total_area += segment_area;
        prev = i;
    }

    return abs(total_area);
}


int main() {

    int n; cin >> n;

    vector<pair<lli, lli>> points(n);

    lli x, y;
    for (int i = 0; i < n; i++) {

        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    cout << double_area(points);

    return 0;
}