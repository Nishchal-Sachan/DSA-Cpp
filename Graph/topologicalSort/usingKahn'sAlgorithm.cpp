#include <bits/stdc++.h> 
using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm (BFS)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Step 1: Build adjacency list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];   // starting node of edge
        int w = edges[i][1];   // ending node of edge

        adj[u].push_back(w);   // Directed edge: u -> w
    }

    // Step 2: Find indegree of all nodes
    vector<int> indegree(v, 0);  // initially 0 indegree for all vertices
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;  // increment indegree of neighbor
        }
    }

    // Step 3: Push all nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 4: BFS traversal
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front(); // node with 0 indegree
        q.pop();

        ans.push_back(front);  // store result (Topological order)

        // Decrease indegree of all neighbours of 'front'
        for (auto i : adj[front]) {
            indegree[i]--;
            if (indegree[i] == 0) {  // if indegree becomes 0 → push into queue
                q.push(i);
            }
        }
    }

    return ans;
}

// Main function to test
int main() {
    int v = 6;  // number of vertices
    int e = 6;  // number of edges

    // Edges of the Directed Acyclic Graph (DAG)
    vector<vector<int>> edges = {
        {5, 0}, {5, 2}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    // Call Topological Sort function
    vector<int> result = topologicalSort(edges, v, e);

    // Print result
    cout << "Topological Sort Order: ";
    for (auto node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
