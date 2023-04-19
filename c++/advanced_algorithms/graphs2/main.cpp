#include <bits/stdc++.h>
using namespace std;


typedef long long int lli;
lli max_lli = LONG_LONG_MAX;


bool negative_cycle(vector<tuple<int, int, lli>> edges, int n, int m) {
    vector<lli> distances(n, max_lli);

    int i = 0, j;
    distances[i++] = 0;

    int start, end;
    lli weight;

    for (; i < n; i++) {
        for (j = 0; j < m; j++) {
            start = get<0>(edges[j]);
            end = get<1>(edges[j]);
            weight = get<2>(edges[j]);

            lli curr_distance = distances[start] + weight;

            if (distances[start] != max_lli && curr_distance < distances[end])
                distances[end] = curr_distance;
        }
    }

    for (i = 0; i < m; i++) {
        start = get<0>(edges[i]);
        end = get<1>(edges[i]);
        weight = get<2>(edges[i]);
        if ((distances[start] != max_lli) && (distances[start] + weight < distances[end]))
            return true;
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, lli>> edges(m);

    int start, end;
    lli weight;

    for (int i = 0; i < m; i++) {
        cin >> start >> end >> weight;
        edges[i] = make_tuple(start - 1, end - 1, weight);
    }

    cout << (negative_cycle(edges, n, m) ? "YES" : "NO");

    return 0;
}