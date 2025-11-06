#include <bits/stdc++.h>
using namespace std;

/*
 🧠 PROBLEM: Maximum Non-Adjacent Sum
 ------------------------------------
 Given an array of integers, choose elements such that no two chosen elements are adjacent,
 and the sum of chosen elements is maximum.

 Example:
   Input: [2, 1, 4, 9]
   Output: 11  (2 + 9)
*/


/*---------------------------------------------------
 🧮 APPROACH 1: PURE RECURSION  (Exponential O(2^n))
 ---------------------------------------------------
 Idea:
   - For every index, we have 2 choices:
       1️⃣ Include current element → move to (i - 2)
       2️⃣ Exclude current element → move to (i - 1)
   - Base cases:
       - If n == 0 → return nums[0]
       - If n < 0  → return 0
*/
int solveRecursion(vector<int>& nums, int n) {
    if (n == 0) return nums[0];
    if (n < 0) return 0;

    int include = nums[n] + solveRecursion(nums, n - 2);
    int exclude = 0 + solveRecursion(nums, n - 1);

    return max(include, exclude);
}

int maximumNonAdjacentSum_Recursion(vector<int>& nums) {
    int n = nums.size();
    return solveRecursion(nums, n - 1);
}


/*---------------------------------------------------
 🧮 APPROACH 2: MEMOIZATION (Top-Down DP)  O(N)
 ---------------------------------------------------
 Idea:
   - Store already computed subproblems to avoid recomputation.
   - dp[i] represents the maximum sum we can achieve from subarray [0...i].
*/
int solveMemo(vector<int>& nums, int n, vector<int>& dp) {
    if (n == 0) return nums[0];
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n];

    int include = nums[n] + solveMemo(nums, n - 2, dp);
    int exclude = 0 + solveMemo(nums, n - 1, dp);

    return dp[n] = max(include, exclude);
}

int maximumNonAdjacentSum_Memoization(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMemo(nums, n - 1, dp);
}


/*---------------------------------------------------
 🧮 APPROACH 3: TABULATION (Bottom-Up DP)  O(N)
 ---------------------------------------------------
 Idea:
   - Build the dp array iteratively.
   - Transition:
        dp[i] = max(dp[i-1], nums[i] + dp[i-2])
*/
int maximumNonAdjacentSum_Tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += dp[i - 2]; // take current + dp[i-2]
        int notTake = dp[i - 1];      // skip current
        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
}


/*---------------------------------------------------
 🧮 APPROACH 4: SPACE OPTIMIZATION  O(N) → O(1)
 ---------------------------------------------------
 Idea:
   - We only need last two values (dp[i-1] and dp[i-2]).
   - Replace array with two variables.
*/
int maximumNonAdjacentSum_SpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    long long prev1 = nums[0];
    long long prev2 = 0;

    for (int i = 1; i < n; i++) {
        long long incl = nums[i] + prev2;
        long long excl = prev1;
        long long curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


/*---------------------------------------------------
 🧾 DRIVER FUNCTION (for testing all approaches)
 ---------------------------------------------------
*/
int main() {
    vector<int> nums = {2, 1, 4, 9};
    cout << "Approach 1 (Recursion): " << maximumNonAdjacentSum_Recursion(nums) << endl;
    cout << "Approach 2 (Memoization): " << maximumNonAdjacentSum_Memoization(nums) << endl;
    cout << "Approach 3 (Tabulation): " << maximumNonAdjacentSum_Tabulation(nums) << endl;
    cout << "Approach 4 (Space Optimized): " << maximumNonAdjacentSum_SpaceOptimized(nums) << endl;
    return 0;
}
