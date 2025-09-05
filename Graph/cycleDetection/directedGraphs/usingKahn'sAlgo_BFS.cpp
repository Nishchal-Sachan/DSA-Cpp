#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in a directed graph using Kahn's Algorithm (BFS Topological Sort)
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Adjacency list representation
    unordered_map<int, list<int>> adj;

    // Build adjacency list (convert 1-based indexing to 0-based indexing)
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;  // shift to 0-based
        int v = edges[i].second - 1; // shift to 0-based

        adj[u].push_back(v); // directed edge u -> v
    }

    // Step 1: Find indegree of all nodes
    vector<int> indegree(n, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++; // increase indegree of neighbour
        }
    }

    // Step 2: Push all nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: BFS traversal (Kahn’s Algorithm)
    int count = 0; // count how many nodes are processed
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // One node processed
        count++;

        // Decrease indegree of neighbours
        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;
            // If indegree becomes 0, push into queue
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Step 4: If count != n, cycle exists
    // (because not all nodes could be processed in topological order)
    return count != n;
}

// ------------------ MAIN FUNCTION ------------------
int main() {
    int t;
    cin >> t; // number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m; // n = nodes, m = edges
        vector<pair<int, int>> edges;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        // Call function
        int hasCycle = detectCycleInDirectedGraph(n, edges);

        // Print result
        if (hasCycle) {
            cout << 1 << endl; // cycle exists
        } else {
            cout << 0 << endl; // no cycle
        }
    }
    return 0;
}
