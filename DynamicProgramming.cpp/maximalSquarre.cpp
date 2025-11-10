/*
    🔹 Problem: Maximum Size Square Sub-matrix with All 1s (GFG)

    You are given a binary matrix `mat` of size n x m.
    Your task is to return the **side length** of the largest square sub-matrix that contains only 1s.

    Example:
       Input:
            1 1 1
            1 1 1
            1 1 0
       Output:
            3   (The largest square of 1s is 3x3)

    --------------------------------------------------------------
    Approaches Covered in This File:
        1️⃣ Recursive (Brute Force)  → Exponential (TLE) — for intuition
        2️⃣ Top-Down DP (Memoization) → O(n*m)  — optimized recursion
        3️⃣ Bottom-Up DP (Tabulation) → O(n*m)  — classic DP
        4️⃣ Space Optimized DP → O(n*m) Time & O(m) Space — best version
    --------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*===============================================================
    1️⃣ PURE RECURSION (INTUITION / BRUTE FORCE) → TLE
    -------------------------------------------------
    For each cell, try to extend a square using:
        - right     (i, j+1)
        - down      (i+1, j)
        - diagonal  (i+1, j+1)
    
    No memoization → repeats work → Exponential Time.
================================================================*/
int solveRecursive(vector<vector<int>>& mat, int i, int j, int &maxi) {
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    int right = solveRecursive(mat, i, j+1, maxi);
    int down = solveRecursive(mat, i+1, j, maxi);
    int diagonal = solveRecursive(mat, i+1, j+1, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min({right, down, diagonal});
        maxi = max(maxi, ans);
        return ans;
    }
    return 0;
}


/*===============================================================
    2️⃣ TOP-DOWN DP (MEMOIZATION) → O(n*m)
    --------------------------------------------------------------
    Same recurrence, but store results in `dp`.
================================================================*/
int solveMemo(vector<vector<int>>& mat, int i, int j, int &maxi, vector<vector<int>>& dp){
    if(i >= mat.size() || j >= mat[0].size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int right = solveMemo(mat, i, j+1, maxi, dp);
    int down = solveMemo(mat, i+1, j, maxi, dp);
    int diagonal = solveMemo(mat, i+1, j+1, maxi, dp);

    if(mat[i][j] == 1){
        dp[i][j] = 1 + min({right, down, diagonal});
        maxi = max(maxi, dp[i][j]);
    } else {
        dp[i][j] = 0;
    }
    return dp[i][j];
}


/*===============================================================
    3️⃣ BOTTOM-UP DP (TABULATION) → O(n*m) Time, O(n*m) Space
    --------------------------------------------------------------
    Build dp[][] from bottom-right to top-left.
================================================================*/
int solveBottomUp(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int maxi = 0;

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(mat[i][j] == 1){
                dp[i][j] = 1 + min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}


/*===============================================================
    4️⃣ SPACE OPTIMIZED DP → O(n*m) Time, O(m) Space ✅ Best Approach
    --------------------------------------------------------------
    We only need the current row and next row at any time.
================================================================*/
int solveSpaceOptimized(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<int> curr(m+1, 0), next(m+1, 0);
    int maxi = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(mat[i][j] == 1){
                curr[j] = 1 + min({curr[j+1], next[j], next[j+1]});
                maxi = max(maxi, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        next = curr;  // Shift row
    }
    return maxi;
}


/*===============================================================
    DRIVER FUNCTION
================================================================*/
class Solution {
public:
    int maxSquare(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        // 1️⃣ Recursive (TLE)
        // int maxi = 0;
        // solveRecursive(mat, 0, 0, maxi);
        // return maxi;

        // 2️⃣ Top-Down DP
        // int maxi = 0;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // solveMemo(mat, 0, 0, maxi, dp);
        // return maxi;

        // 3️⃣ Bottom-Up DP (Iterative)
        // return solveBottomUp(mat);

        // 4️⃣ Space Optimized (Recommended)
        return solveSpaceOptimized(mat);
    }
};
