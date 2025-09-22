#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int edgeCount, int source) {
    // Step 1: Build adjacency list with (node, weight) pairs
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));  // undirected graph
    }

    // Step 2: Initialize distances to all nodes as infinite
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Step 3: Use a set to efficiently get the node with the smallest distance
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty()) {
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // Step 4: Traverse all neighbors of topNode
        for (auto i : adj[topNode]) {
            int neighbor = i.first;
            int weight = i.second;

            // If shorter distance is found
            if (nodeDist + weight < dist[neighbor]) {
                // Remove old record if exists
                auto record = st.find(make_pair(dist[neighbor], neighbor));
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update distance and insert new record
                dist[neighbor] = nodeDist + weight;
                st.insert(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 5;
    int edges = 6;
    int source = 0;

    vector<vector<int>> edgeList = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };

    vector<int> distances = dijkstra(edgeList, vertices, edges, source);

    cout << "Shortest distances from source node " << source << ":" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
