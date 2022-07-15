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

int main() {

    string filename;
    getline(cin, filename);

    ifstream pajek(filename);

    string neighbors;
    getline(cin, neighbors);

    vector<int> sub_group;

    istringstream in(neighbors);
    copy(istream_iterator<int>( in ), std::istream_iterator<int>(), back_inserter(sub_group) );

    string empty;

    pajek >> empty;
    int total_vertices; pajek >> total_vertices;
    pajek >> empty;

    vector<int> adjacency[total_vertices];

    for (int i = 0; i < total_vertices; i++) {
        int start, end;
        pajek >> start >> end;
        adjacency[start - 1].push_back(end);
    }

    for (int node : sub_group) {
        cout << "Starting Node " << node << ": \n";
        for (auto neighbor : adjacency[node - 1])
            cout << neighbor << " ";

        printf("\n");
    }
}