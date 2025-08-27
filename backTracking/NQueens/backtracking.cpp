#include <bits/stdc++.h>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;

    // Check same row (left side only)
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    // Check upper diagonal (left side)
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // Check lower diagonal (left side)
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true; // Safe to place
}

// Store one valid solution
void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

// Recursive function to solve the N-Queens problem
void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    if (col == n) {
        // All queens are placed → store solution
        addSolution(ans, board, n);
        return;
    }

    // Try placing queen in each row of current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;  // Place queen
            solve(col + 1, ans, board, n); // Recurse
            board[row][col] = 0;  // Backtrack
        }
    }
}

// Main N-Queens solver function
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}

// MAIN FUNCTION
int main() {
    int n;
    cout << "Enter the value of N (board size): ";
    cin >> n;

    vector<vector<int>> result = solveNQueens(n);

    cout << "Total solutions = " << result.size() << "\n";

    // Print each solution in matrix form
    for (int k = 0; k < result.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < n * n; i++) {
            cout << result[k][i] << " ";
            if ((i + 1) % n == 0) cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
