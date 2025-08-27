#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
void  solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n, unordered_map<int, bool>& leftRow, unordered_map<int, bool>& upperDiagonal, unordered_map<int, bool>& lowerDiagonal){
    if(col==n){
        addSolution(ans,board,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(!board[row][col] && !leftRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[n-1+col-row]){
            board[row][col]=1;
            leftRow[row]=true;
            upperDiagonal[row+col]=true;
            lowerDiagonal[n-1+col-row]=true;
            solve(col+1,ans,board,n, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col]=0;
            leftRow[row]=false;
            upperDiagonal[row+col]=false;
            lowerDiagonal[n-1+col-row]=false;
        }
    }

}
vector<vector<int>> solveNQueens(int n) {
    // using hashmaps
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    unordered_map<int, bool> leftRow;          // to check if a row is occupied
    unordered_map<int, bool> upperDiagonal;    // to check if an upper diagonal is
    unordered_map<int, bool> lowerDiagonal;    // to check if a lower diagonal is occupied
    for (int i = 0; i < n; i++) {
        leftRow[i] = false;
        upperDiagonal[i] = false;
        lowerDiagonal[i] = false;
        upperDiagonal[2 * n - 2 + i] = false; // for negative indices in lower diagonal
        lowerDiagonal[2 * n - 2 + i] = false; // for negative
    }
    solve(0, ans, board, n, leftRow, upperDiagonal, lowerDiagonal);
    return ans;

}