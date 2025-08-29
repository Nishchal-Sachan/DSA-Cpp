#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// --------------------- DFS Function ---------------------
// This function explores one connected component using recursion (DFS).
void dfs(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj,
         vector<int> &component) {

    // Mark the current node as visited
    visited[node] = true;

    // Store the node in the current component
    component.push_back(node);

    // Visit all unvisited neighbors
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, adj, component);
        }
    }
}

// --------------------- DFS Traversal ---------------------
// V = number of vertices
// E = number of edges
// edges = list of edges of the graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;

    // Step 1: Build adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Since it's an undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Prepare visited map
    unordered_map<int, bool> visited;

    // Step 3: Store all connected components
    vector<vector<int>> ans;

    // Step 4: Traverse all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);  // Explore this component
            ans.push_back(component);         // Store it in the result
        }
    }

    return ans;
}

// --------------------- MAIN FUNCTION ---------------------
int main() {
    // Example input
    int V = 8;  // number of vertices (0 to 7)
    int E = 7;  // number of edges

    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, 
        {1, 4}, {1, 7}, 
        {2, 5}, {3, 6}
    };

    // Call DFS traversal
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Print all components
    cout << "DFS Traversal (by components):" << endl;
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (auto node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
