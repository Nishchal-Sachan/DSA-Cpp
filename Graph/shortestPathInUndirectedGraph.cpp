#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the shortest path between source (s) and target (t) in an unweighted undirected graph
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    
    // Step 1: Build adjacency list from the edges
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);  // Because it's undirected graph
    }

    // Step 2: BFS Initialization
    unordered_map<int, bool> visited;    // Tracks visited nodes
    unordered_map<int, int> parent;      // Tracks parent of each node to reconstruct path
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;   // Source has no parent

    // Step 3: Perform BFS to find shortest path tree
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbor : adj[front]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;  // Store where we came from
            }
        }
    }

    // Step 4: Reconstruct path from t back to s using parent map
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s) {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    // Step 5: Reverse to get the path from s to t
    reverse(ans.begin(), ans.end());

    return ans;
}
