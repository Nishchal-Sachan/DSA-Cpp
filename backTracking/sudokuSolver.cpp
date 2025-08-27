#include <bits/stdc++.h> 
using namespace std;

// Function to check whether placing 'val' in board[row][col] is safe
bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        // check row
        if (board[row][i] == val) {
            return false;
        }
        // check column
        if (board[i][col] == val) {
            return false;
        }
        // check 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve Sudoku
bool solve(vector<vector<int>>& board) {
    int n = board.size();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // empty cell found
            if (board[row][col] == 0) {
                // try all values from 1 to 9
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        // place the value
                        board[row][col] = val;

                        // recursive call to solve remaining board
                        bool isSolPossible = solve(board);
                        if (isSolPossible) {
                            return true; // solution found
                        } else {
                            // backtrack if placing val doesn't lead to solution
                            board[row][col] = 0;
                        }
                    }
                }
                // if no valid number can be placed, return false
                return false;
            }
        }
    }
    return true; // sudoku solved
}

// Function to call solve()
void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

// Driver function
int main() {
    // Example Sudoku puzzle (0 means empty cell)
    vector<vector<int>> sudoku = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "Original Sudoku:\n";
    for (auto& row : sudoku) {
        for (auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Solve Sudoku
    solveSudoku(sudoku);

    cout << "\nSolved Sudoku:\n";
    for (auto& row : sudoku) {
        for (auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
