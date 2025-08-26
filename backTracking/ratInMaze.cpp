#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n &&
            !visited[newx][newy] && arr[newx][newy] == 1);
}

void solve(int x, int y, vector<vector<int>>& arr, int n,
           vector<string>& ans, vector<vector<bool>>& visited, string path) {
    
    // Base condition: reached destination
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark visited
    visited[x][y] = true;

    // Down
    if (isSafe(x + 1, y, visited, arr, n)) {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }
    // Left
    if (isSafe(x, y - 1, visited, arr, n)) {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }
    // Right
    if (isSafe(x, y + 1, visited, arr, n)) {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }
    // Up
    if (isSafe(x - 1, y, visited, arr, n)) {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }

    // Backtrack
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    if (arr[0][0] == 0) return ans; // If start blocked

    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}

// Example driver
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int n = maze.size();

    vector<string> res = searchMaze(maze, n);
    for (auto& path : res) cout << path << " ";
    return 0;
}
