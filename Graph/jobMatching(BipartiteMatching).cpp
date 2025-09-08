#include <bits/stdc++.h>
using namespace std;

// Helper function to perform DFS and try to assign jobs to candidates
bool bpm(int candidate, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited,
         unordered_map<int, int> &jobAssignment) {
    
    // Try all jobs connected to the current candidate
    for (int job : adj[candidate]) {
        if (!visited[job]) {
            visited[job] = true;

            // If job is not assigned yet OR previously assigned candidate can get another job
            if (jobAssignment[job] == -1 || bpm(jobAssignment[job], adj, visited, jobAssignment)) {
                jobAssignment[job] = candidate;
                return true;  // Job successfully assigned
            }
        }
    }
    return false;  // No valid assignment possible
}

// Function to find maximum bipartite matching
int maxMatch(vector<vector<int>> &mat) {
    unordered_map<int, list<int>> adj;
    int numCandidates = mat.size();
    int numJobs = mat[0].size();

    // Build the bipartite graph as adjacency list
    for (int i = 0; i < numCandidates; i++) {
        for (int j = 0; j < numJobs; j++) {
            if (mat[i][j] == 1) {
                adj[i + 1].push_back(j + 1);  // Using 1-based indexing for clarity
            }
        }
    }

    // Initialize job assignments to -1 (meaning no job assigned yet)
    unordered_map<int, int> jobAssignment;
    for (int j = 1; j <= numJobs; j++) {
        jobAssignment[j] = -1;
    }

    int maxMatching = 0;

    // Try to assign jobs to every candidate
    for (int candidate = 1; candidate <= numCandidates; candidate++) {
        unordered_map<int, bool> visited;  // Reset visited jobs for each candidate

        if (bpm(candidate, adj, visited, jobAssignment)) {
            maxMatching++;  // Found a matching
        }
    }

    return maxMatching;  // Return the total number of matches found
}

// Main function to test maxMatch implementation
int main() {
    // Example bipartite graph matrix (candidates x jobs)
    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 1},
        {1, 0, 1}
    };

    int result = maxMatch(mat);

    cout << "Maximum Bipartite Matching: " << result << endl;

    return 0;
}
