#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define coord pair<lli, lli>


int orientation(coord a, coord b, coord c) {
    lli val = (b.second - a.second) * (c.first - b.first) -
              (b.first - a.first) * (c.second - b.second);

    return (val == 0)? 0 : ((val > 0) ? 1 : -1);
}


double distance(coord a, coord b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}


double jarvis_perimeter(vector<coord> points) {

    vector<coord> hull;

    int n = (int) points.size();
    int smallest = 0;

    for (int i = 1; i < n; i++) {
        if (points[i].first < points[smallest].first)
            smallest = i;
    }

    int a = smallest, b;

    do {

        hull.push_back(points[a]);

        b = (a + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[a], points[i], points[b]) == -1)
                b = i;
        }

        a = b;
    } while (a != smallest);

    double perimeter = distance(hull[0], hull[(int) hull.size() - 1]);

    for (int i = 1; i < (int) hull.size(); i++)
        perimeter += distance(hull[i], hull[i - 1]);

    return perimeter;
}


int graham_scan(vector<coord> points) {
    vector<coord> hull;

    int n = (int) points.size();
    coord smallest = make_pair(LONG_LONG_MAX, LONG_LONG_MAX);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        coord point = points[i];
        if (point.second > smallest.second)
            continue;
        if (smallest.second < point.second || smallest.first < point.first) {
            smallest = point;
            idx = i;
        }
    }

    hull.push_back(smallest);
    points.erase(points.begin() + idx);

    return 1;
}


int main() {

    int n; cin >> n;

    vector<pair<lli, lli>> points(n);

    lli x, y;
    for (int i = 0; i < n; i++) {

        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    cout << fixed << setprecision(6) << jarvis_perimeter(points) << "\n";

    return 0;
}