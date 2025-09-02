#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Function to check cycle in a graph using BFS
bool isCyclicBFS(int node, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj) {
    unordered_map<int,int> parent;   // To track parent of each node in BFS

    parent[node] = -1;      // Starting node has no parent
    visited[node] = true;   // Mark starting node as visited

    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Traverse all neighbours of 'front'
        for (auto neighbour : adj[front]) {
            if (visited[neighbour] && neighbour != parent[front]) {
                // If neighbour is already visited and not parent → cycle found
                return true;
            }
            else if (!visited[neighbour]) {
                // If not visited, push in queue and mark visited
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front; // set parent
            }
        }
    }
    return false;  // No cycle detected from this node
}

// Function to build adjacency list
void makeAdj(int m, unordered_map<int, list<int>> &adj, vector<vector<int>> &edges) {
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph → add both edges
    }
}

// Main function to check cycle in graph
string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    unordered_map<int,list<int>> adj;
    makeAdj(m, adj, edges);   // Build adjacency list

    unordered_map<int,bool> visited; // Track visited nodes

    // Check all components (for disconnected graphs)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);
            if (ans) {
                return "Yes";   // Cycle detected
            }
        }
    }
    return "No";   // No cycle in any component
}

// Driver code
int main() {
    int n = 5, m = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // contains a cycle
    };

    cout << "Cycle present? " << cycleDetection(edges, n, m) << endl;
    return 0;
}
