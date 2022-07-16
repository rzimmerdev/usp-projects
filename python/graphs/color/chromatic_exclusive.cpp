//
// Created by rzimmerdev on 11/07/2022.
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void print_adjacency(vector<int> adjacency[], int total_nodes) {

    for (int node = 0; node < total_nodes; ++node) {

        cout << "Starting Node " << node << ": \n";
        for (auto neighbor : adjacency[node])
            cout << neighbor << " ";

        printf("\n");
    }
}


int dfs(vector<int> adjacency[], int total_nodes, vector<int> visited, int node) {

    if (visited[node] == true)
        return 0;

    else {
        int depth = 0;
        visited[node] = true;

        for (int neighbour : adjacency[node]) {

            int range = 1 + dfs(adjacency, total_nodes, visited, neighbour);
            depth = range > depth ? range : depth;
        }
        printf("Node: %d, depth: %d\n", node, depth);

        return depth;
    }
}


int main() {
    vector<int> sub_group = {4, 5, 7, 9, 12, 13, 16, 17, 18, 19, 20};

    string empty;

    cin >> empty;
    int total_vertices; cin >> total_vertices;
    total_vertices += 1;
    cin >> empty;

    vector<int> adjacency[total_vertices];

    for (int i = 0; i < total_vertices; i++) {
        int start, end;
        cin >> start >> end;
        if ((count(sub_group.begin(), sub_group.end(), end)))
            adjacency[start].push_back(end);
    }

    for (int node : sub_group) {
        cout << "Starting Node " << node << ": \n";
        for (auto neighbor : adjacency[node]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    vector<int> visited(total_vertices);
    cout << dfs(adjacency, total_vertices, visited, 4);
}