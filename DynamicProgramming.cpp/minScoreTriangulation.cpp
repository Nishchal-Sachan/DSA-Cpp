/*
    🟢 Problem: Minimum Score Triangulation of Polygon
    -------------------------------------------------
    We are given an array `values[]` where each value represents 
    a vertex of a polygon. We must triangulate the polygon such 
    that the sum of weights of triangles is minimized.

    For any triangle formed by vertices (i, k, j):
        Cost = values[i] * values[k] * values[j]

    We must choose the triangulation order that results in minimum cost.

    ---------------------------------------------------------
    APPROACHES INCLUDED IN THIS FILE:
    ---------------------------------------------------------

    1️⃣ Pure Recursion (Brute Force, Exponential, for understanding)
    2️⃣ Top-Down DP (Memoization, avoids repeated states)
    3️⃣ Bottom-Up DP (Tabulation)
    4️⃣ Gap Strategy (MCM Pattern) — Cleanest & Best for Interviews

    ---------------------------------------------------------
    KEY INSIGHT:
    ---------------------------------------------------------
    Triangulation is about picking a vertex k between i and j, 
    forming triangle (i, k, j), and solving two sub-polygons:

            i ----- k ----- j
            |             /
            |           /
            |         /
            |       /
            |     /
            |   /
            j /

    So recurrence:

        dp[i][j] = min over k of :
                    (values[i] * values[k] * values[j]
                     + dp[i][k]
                     + dp[k][j])
*/

#include <bits/stdc++.h>
using namespace std;

/*================================================================
    1️⃣ PURE RECURSION (INTUITION BUILDER)
    --------------------------------------------------------------
    Think:
    To compute min cost between vertices i and j, we try all
    possible k between them and choose the minimum.

    Base Case:
      If i+1 == j, there are only two points → can't form triangle → cost = 0
================================================================*/
int solveRecursive(vector<int>& v, int i, int j){
    if(i + 1 == j) return 0; // No triangle possible

    int ans = INT_MAX;

    for(int k = i+1; k < j; k++){
        int cost = v[i]*v[k]*v[j]
                 + solveRecursive(v, i, k)
                 + solveRecursive(v, k, j);
        ans = min(ans, cost);
    }
    return ans;
}

/*================================================================
    2️⃣ TOP-DOWN DP (Memoization)
    --------------------------------------------------------------
    Same as recursion, but we store dp[i][j] to avoid recomputation.
    This converts exponential → O(n³).
================================================================*/
int solveMemo(vector<int>& v, int i, int j, vector<vector<int>>& dp){
    if(i + 1 == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for(int k = i+1; k < j; k++){
        int cost = v[i]*v[k]*v[j]
                 + solveMemo(v, i, k, dp)
                 + solveMemo(v, k, j, dp);
        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}

/*================================================================
    3️⃣ BOTTOM-UP DP (Tabulation)
    --------------------------------------------------------------
    We fill dp table from smaller lengths to larger.
    dp[i][j] stores minimum triangulation cost between i and j.
================================================================*/
int solveBottomUp(vector<int>& v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            int ans = INT_MAX;
            for(int k = i+1; k < j; k++){
                ans = min(ans, v[i]*v[k]*v[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

/*================================================================
    4️⃣ GAP STRATEGY (MCM PATTERN) — BEST STRUCTURED VERSION
    --------------------------------------------------------------
    Same logic as Bottom-Up DP, but with controlled filling order
    using gap = j - i. This is the cleanest and most intuitive DP.
================================================================*/
int solveGapStrategy(vector<int>& v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int gap = 2; gap < n; gap++){
        for(int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++){
                dp[i][j] = min(dp[i][j],
                                v[i]*v[k]*v[j] + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][n-1];
}

/*================================================================
    DRIVER CLASS
================================================================*/
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {

        // 1️⃣ Pure Recursion (Understands logic, but TLE)
        // return solveRecursive(values, 0, values.size()-1);

        // 2️⃣ Memoization (Top-Down DP) ✅ Good
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return solveMemo(values, 0, values.size()-1, dp);

        // 3️⃣ Bottom-Up DP ✅ Efficient
        // return solveBottomUp(values);

        // 4️⃣ Gap Strategy (MCM) ✅ Best Structured / Interview Perfect
        return solveGapStrategy(values);
    }
};
