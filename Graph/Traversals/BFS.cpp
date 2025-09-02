#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

// Function to prepare adjacency list from edge list
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Since it's an undirected graph, add both connections
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

// BFS function to traverse from a given starting node
void bfs(unordered_map<int, set<int>> &adjList,
         unordered_map<int, bool> &visited,
         vector<int> &ans,
         int node) {
    
    queue<int> q;
    q.push(node);          // Start BFS from the given node
    visited[node] = true;  // Mark node as visited

    while (!q.empty()) {
        int frontNode = q.front();  // Get current node
        q.pop();

        // Store the node in the answer (BFS order)
        ans.push_back(frontNode);

        // Traverse all neighbours of the current node
        for (auto neighbour : adjList[frontNode]) {
            if (!visited[neighbour]) {
                q.push(neighbour);       // Push unvisited neighbour into queue
                visited[neighbour] = 1;  // Mark neighbour as visited
            }
        }
    }
}

// BFS Traversal function for a graph with n nodes and adjacency edges
vector<int> bfsTraversal(int n, vector<vector<int>> &edges) {
    unordered_map<int, set<int>> adjList;   // Adjacency list
    vector<int> ans;                        // To store BFS traversal order
    unordered_map<int, bool> visited;       // Track visited nodes

    // Step 1: Build adjacency list
    prepareAdjList(adjList, edges);

    // Step 2: Call BFS for each component (to handle disconnected graphs)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// Driver Code
int main() {
    int n = 5; // Number of nodes (0,1,2,3,4)
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}
    };

    vector<int> bfsResult = bfsTraversal(n, edges);

    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
