#include <iostream>
#include <vector>
using namespace std;

// --------------------- DFS FUNCTION ---------------------
// Recursive DFS starting from a given node
void dfs(int node, vector<bool> &visited,
         vector<vector<int>> &adj, vector<int> &ans) {

    visited[node] = true;        // mark node as visited
    ans.push_back(node);         // store node in traversal order

    // explore all neighbors
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, adj, ans); // recursive call
        }
    }
}

// --------------------- WRAPPER FUNCTION ---------------------
// Runs DFS starting from node 0
vector<int> dfsTraversal(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false); // visited array
    vector<int> ans;                // store traversal result
    dfs(0, visited, adj, ans);      // start DFS from node 0
    return ans;
}

// --------------------- MAIN FUNCTION ---------------------
int main() {
    // Example graph:
    // 0 -- 1 -- 2
    // |    |
    // 3    4
    //      |
    //      5

    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // Add undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[4].push_back(5);
    adj[5].push_back(4);

    // Perform DFS traversal
    vector<int> result = dfsTraversal(n, adj);

    // Print result
    cout << "DFS Traversal starting from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
