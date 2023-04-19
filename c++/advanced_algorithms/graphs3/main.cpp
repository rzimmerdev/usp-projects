#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vec;
int is_upgradable(const vector<vec>& bandwidth, int path[], int src, int dest, int n);

int connect(const vector<vec>& network, int src, int dest, int n) {
    vector<vec> bandwidth(n, vec(n));
    bandwidth = network;

    int largest_connection_size = 0;
    int pos, path[n];

    while (is_upgradable(bandwidth, path, src, dest, n)) {

        int curr_connection_size = INT_MAX;

        for (pos = dest; pos != src; pos = path[pos])
            curr_connection_size = min(curr_connection_size, bandwidth[path[pos]][pos]);

        for (pos = dest; pos != src; pos = path[pos]) {
            int curr = path[pos];

            bandwidth[curr][pos] -= curr_connection_size;
            bandwidth[pos][curr] += curr_connection_size;
        }

        largest_connection_size += curr_connection_size;
    }

    return largest_connection_size;
}


// BFS for finding if current bandwidth path can be upgraded
int is_upgradable(const vector<vec>& bandwidth, int path[], int src, int dest, int n) {

    vector<bool> visited(n, false);
    queue<int> next;

    visited[src] = true;
    next.push(src);

    path[src] = -1;

    while (!next.empty()) {

        int curr = next.front(); next.pop();

        for (int i = 0; i < n; i++) {

            if (!visited[i] && bandwidth[curr][i] != 0) {


                if (i == dest) {
                    path[i] = curr;
                    return true;
                }

                path[i] = curr;
                visited[i] = true;
                next.push(i);
            }
        }
    }

    return false;
}


int main() {

    int network_id = 0, n, src, dest, connections;
    int node_1, node_2, weight;

    while ((cin >> n) && n != 0) {
        vector<vec> network(n, vec (n, 0));

        if (network_id++ != 0)
            cout << endl;

        cin >> src >> dest >> connections;
        src -= 1; dest -= 1;

        for (int i = 0; i < connections; i++) {
            cin >> node_1 >> node_2 >> weight;
            network[node_1 - 1][node_2 - 1] += weight;
            network[node_2 - 1][node_1 - 1] += weight;
        }

        cout << "Network " << network_id << endl;
        cout << "The bandwidth is " << "" << connect(network, src, dest, n) << "." << endl;
    }
    
    return 0;
}
