#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli, int> ppair;

vector<lli> shortest_path(vector<vector<int>> graph, int start, int n) {
    vector<lli> distances(n, LONG_LONG_MAX);
    priority_queue<ppair, vector<ppair>, greater<>> next;

    distances[start] = 0;
    next.push(make_pair(0, start));

    while (!next.empty()) {
        tuple<lli, int> closest = (next.top()); next.pop();

        int curr = get<1>(closest);
        vector<int> adjacent_nodes = graph[curr];

        for (int i = 0; i < n; i++) {
            if (adjacent_nodes[i] != -1) {
                lli curr_distance = distances[curr] + adjacent_nodes[i];
                if (curr_distance < distances[i]) {
                    distances[i] = curr_distance;
                    next.push(make_pair(distances[i], i));
                }
            }
        }
    }

    return distances;
}


int main() {

    int n, m;
    lli q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n, vector<int> (n, -1));

    int a, b, c, i;

    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    vector<vector<lli>> distances(n, vector<lli> (n, -1));

    for (i = 0; i < n; i++) {
        distances[i] = shortest_path(graph, i, n);
    }

    for (i = 0; i < q; i++) {
        cin >> a >> b;
        lli path_length = distances[a - 1][b - 1];
        if (path_length == LONG_LONG_MAX)
            path_length = -1;
        cout << path_length << endl;
    }

    return 0;
}