#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// Function to check cycle using DFS
bool checkCyclic(int node,
                 unordered_map<int,bool>& visited,      // Tracks visited nodes
                 unordered_map<int,bool>& dfsVisited,   // Tracks nodes in current DFS recursion stack
                 unordered_map<int,list<int>>& adj) {   // Graph adjacency list

    // Mark the current node as visited in both maps
    visited[node] = true;
    dfsVisited[node] = true;

    // Explore all neighbors
    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            // If the neighbor is not visited, recursively check
            bool isCycle = checkCyclic(neighbour, visited, dfsVisited, adj);

            if(isCycle) {
                return true; // If cycle found in recursion
            }
        } 
        else if(dfsVisited[neighbour]) {
            // If neighbor is already in the current recursion stack → cycle found
            return true;
        }
    }

    // Backtrack: remove the node from the recursion stack
    dfsVisited[node] = false;
    return false;
}

// Main function to detect cycle in a directed graph
int detectCycleInDirectedGraph(int n, vector<pair<int,int>>& edges) {
    // Step 1: Build adjacency list
    unordered_map<int,list<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);   // directed edge u → v
    }

    // Step 2: Initialize visited maps
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    // Step 3: Run DFS from each unvisited node
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool cycleFound = checkCyclic(i, visited, dfsVisited, adj);

            if(cycleFound) {
                return 1;   // Cycle found
            }
        }
    }
    return 0;   // No cycle found
}

// Driver code (for testing)
int main() {
    int n = 4; // number of nodes
    vector<pair<int,int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,1}   // cycle exists here
    };

    int result = detectCycleInDirectedGraph(n, edges);
    if(result) cout << "Cycle detected ✅" << endl;
    else cout << "No cycle ❌" << endl;

    return 0;
}
