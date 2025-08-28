#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

// Graph class to represent adjacency list
class Graph {
    public:
    // Each node (int) maps to a list of its neighbours
    unordered_map<int, list<int>> adj;

    // Function to add an edge between u and v
    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // Add edge from u to v
        adj[u].push_back(v);

        // If undirected, also add edge from v to u
        if(direction == 0) {
            adj[v].push_back(u);
        }
    }

    // Function to print adjacency list
    void printAdjList() {
        // Iterate through the entire map
        for(auto i : adj) {
            cout << i.first << " -> ";
            // Print all neighbours of the current node
            for(auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;   // Create a graph object

    int n;  // Number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;  // Number of edges
    cout << "Enter the number of edges: ";
    cin >> m;

    // Ensure all nodes (1 to n) exist in the adjacency list
    // Even if a node has no edges, it will still appear
    for(int i = 1; i <= n; i++) {
        g.adj[i]; 
    }

    // Input all edges
    cout << "Enter the edges (u v): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;     // Read edge endpoints
        g.addEdge(u, v, 0); // Here we assume graph is undirected (direction = 0)
    }

    // Print adjacency list
    cout << "\nAdjacency List Representation:\n";
    g.printAdjList();

    return 0;
}
