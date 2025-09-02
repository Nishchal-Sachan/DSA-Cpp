#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// DFS function to check cycle in one connected component
bool isCyclicDFS(int node, int parent, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj) {
    visited[node] = 1;  // mark current node visited

    // Traverse all neighbours
    for (auto i : adj[node]) {
        if (!visited[i]) {
            // Recursive DFS call
            bool isCycle = isCyclicDFS(i, node, visited, adj);
            if (isCycle) {
                return true;  // cycle found
            }
        }
        else if (i != parent) {
            // If neighbour is visited and not parent → cycle
            return true;
        }
    }
    return false; // no cycle in this DFS path
}

// Function to build adjacency list
void makeAdj(int m, unordered_map<int, list<int>> &adj, vector<vector<int>> &edges) {
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph → add both directions
    }
}

// Main function to check cycle in entire graph
string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int,list<int>> adj;
    makeAdj(m, adj, edges);   // Build adjacency list

    unordered_map<int,bool> visited; // Track visited nodes

    // Check all components (to handle disconnected graphs)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(i, -1, visited, adj);  // -1 means no parent for start node
            if (ans) {
                return "Yes";   // Cycle detected
            }
        }
    }
    return "No";   // No cycle in any component
}

// Driver code for testing
int main() {
    int n = 5, m = 5;
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,4}, {4,1}  // contains a cycle
    };

    cout << "Cycle present? " << cycleDetection(edges, n, m) << endl;
    return 0;
}
