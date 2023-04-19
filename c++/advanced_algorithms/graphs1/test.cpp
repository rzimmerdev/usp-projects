#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

int minDistance(long int dist[], bool sptSet[], int n)
{

    // Initialize min value
    long int min = LONG_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(long int dist[], int n)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
long int dijkstra(vector<vector<int>> graph, int src, int end, int n)
{
    long int dist[n]; // The output array.  dist[i] will hold the
    // shortest
    // distance from src to i

    bool sptSet[n]; // sptSet[i] will be true if vertex i is
    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < n; i++)
        dist[i] = LONG_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet, n);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    return dist[end];
}

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n, vector<int> (n, 0));

    int a, b, c;
    int i;

    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    for (i = 0; i < q; i++) {
        cin >> a >> b;
        long int path_length = dijkstra(graph,a - 1, b - 1, n);
        if (path_length == LONG_MAX || path_length < 0)
            path_length = -1;
        cout << path_length << endl;
    }

    return 0;
}