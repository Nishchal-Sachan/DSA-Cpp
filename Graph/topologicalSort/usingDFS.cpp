#include <bits/stdc++.h> 
using namespace std;

// -------------------------
// Helper function for DFS-based Topological Sort
// -------------------------
void topoSort(int node, unordered_map<int ,bool>& visited, stack<int>& s, unordered_map<int,list<int>>& adj) {
    // Mark current node as visited
    visited[node] = 1;

    // Visit all unvisited neighbors
    for (auto i : adj[node]) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    // After visiting neighbors, push this node into stack
    // (meaning this node should come after all its dependencies)
    s.push(node);
}

// -------------------------
// Main Topological Sort function
// -------------------------
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;

    // Build adjacency list for directed graph
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);  // Directed edge u → v
    }

    unordered_map<int ,bool> visited;
    stack<int> s;

    // Perform DFS for each unvisited node
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    // Pop elements from stack to get topological order
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// -------------------------
// Driver function (for testing)
// -------------------------
int main() {
    // Example: Graph with 6 vertices and 6 edges
    int v = 6, e = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort Order: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
