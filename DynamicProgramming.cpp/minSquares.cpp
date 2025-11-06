/*
    🟢 Problem: Minimum Number of Perfect Squares (GFG / LeetCode)
    -------------------------------------------------------------
    Given a number n, return the minimum number of perfect square numbers 
    (e.g., 1, 4, 9, 16, ...) whose sum is equal to n.

    Example:
        Input: 12
        Output: 3
        Explanation: 12 = 4 + 4 + 4

    Approaches Covered in this file:
    1) Recursive (Brute Force)
    2) Top-Down DP (Memoization)
    3) Bottom-Up DP (Tabulation)
*/

#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------
    1️⃣ RECURSIVE (PURE RECURSION) – Exponential Time
    -------------------------------------------------
    Idea:
    Try all squares i*i ≤ n and recursively find the answer for n - i*i.
    This approach is correct but extremely slow for large n.
----------------------------------------------------------------*/
int solveRecursive(int n) {
    if(n == 0) return 0;   // Base Case: No squares needed for 0

    int ans = n;          // Worst case: use all 1's → n times
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solveRecursive(n - i*i));
    }
    return ans;
}


/*---------------------------------------------------------------
    2️⃣ TOP-DOWN DP (MEMOIZATION) – O(n * √n)
    ----------------------------------------
    Optimization: store results of subproblems in dp array.
    This prevents recalculating the same values, making it efficient.
----------------------------------------------------------------*/
int solveMemo(int n, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];  // Return already computed result

    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solveMemo(n - i*i, dp));
    }

    return dp[n] = ans;   // Store result in dp
}


/*---------------------------------------------------------------
    3️⃣ BOTTOM-UP DP (TABULATION) – O(n * √n)
    ----------------------------------------
    Build dp array iteratively.
    dp[j] = minimum perfect squares to sum to j.
----------------------------------------------------------------*/
int solveBottomUp(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;   // Base State

    for(int j = 1; j <= n; j++){
        for(int i = 1; i*i <= j; i++){
            dp[j] = min(dp[j], dp[j - i*i] + 1);
        }
    }
    return dp[n];
}


/*---------------------------------------------------------------
    DRIVER FUNCTION (Select which solution to return)
----------------------------------------------------------------*/
class Solution {
public:
    int minSquares(int n) {

        // OPTION 1: Recursive (VERY SLOW) ❌
        // return solveRecursive(n);

        // OPTION 2: Top-Down DP ✅ Recommended for learning recursion
        /*
        vector<int> dp(n+1, -1);
        return solveMemo(n, dp);
        */

        // OPTION 3: Bottom-Up DP ✅ Best & Clean
        return solveBottomUp(n);
    }
};


/*---------------------------------------------------------------
    MAIN FUNCTION (For Testing)
----------------------------------------------------------------*/
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Minimum Perfect Squares = " << obj.minSquares(n) << endl;

    return 0;
}
