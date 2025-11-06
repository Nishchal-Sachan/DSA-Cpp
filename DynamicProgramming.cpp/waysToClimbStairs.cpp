#include <bits/stdc++.h>
using namespace std;

/* 🪜 PROBLEM:
   You are standing at the bottom of a staircase with 'nStairs' steps.
   You can climb either 1 or 2 steps at a time.
   You need to find the total number of distinct ways to reach the top.
   (Answer should be returned modulo 1e9+7)
*/

const int MOD = 1000000007;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 1️⃣ RECURSIVE APPROACH
/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   🔹 Idea:
     - Start from step 0.
     - From each step, you can move either 1 or 2 steps forward.
     - Explore all possible paths recursively.
   🔹 Time Complexity: O(2^n)  (Exponential — calls repeat)
   🔹 Space Complexity: O(n)   (Recursion stack)
*/

int solveRec(int nStairs, int i) {
    // Base Case 1: If we reached exactly the top → 1 valid way
    if (i == nStairs) return 1;

    // Base Case 2: If we exceed the top → invalid way
    if (i > nStairs) return 0;

    // Recursive calls for taking 1 step or 2 steps
    return (solveRec(nStairs, i + 1) + solveRec(nStairs, i + 2)) % MOD;
}

int countDistinctWaysRec(int nStairs) {
    return solveRec(nStairs, 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 2️⃣ TOP-DOWN APPROACH (Recursion + Memoization)
/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   🔹 Idea:
     - Same as recursion, but store intermediate results in a DP array (memoization).
     - Avoid recomputation of overlapping subproblems.
   🔹 Time Complexity: O(n)
   🔹 Space Complexity: O(n) (Recursion + dp array)
*/

int solveMemo(int nStairs, int i, vector<int> &dp) {
    // Base Cases
    if (i == nStairs) return 1;
    if (i > nStairs) return 0;

    // Step 1: If already computed, return cached value
    if (dp[i] != -1) return dp[i];

    // Step 2: Otherwise, compute and store result
    dp[i] = (solveMemo(nStairs, i + 1, dp) + solveMemo(nStairs, i + 2, dp)) % MOD;
    return dp[i];
}

int countDistinctWaysMemo(int nStairs) {
    vector<int> dp(nStairs + 1, -1);
    return solveMemo(nStairs, 0, dp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 3️⃣ BOTTOM-UP APPROACH (Tabulation)
/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   🔹 Idea:
     - Convert recursion into iteration.
     - Build up the solution using a DP array from base cases.
   🔹 Time Complexity: O(n)
   🔹 Space Complexity: O(n)
*/

int countDistinctWaysTab(int nStairs) {
    // Base Cases
    if (nStairs == 0 || nStairs == 1)
        return 1;

    // Step 1: Create dp array of size n+1
    vector<int> dp(nStairs + 1, 0);

    // Step 2: Initialize base values
    dp[0] = 1; // 1 way to stand at the start
    dp[1] = 1; // 1 way to reach step 1 (only one 1-step move)

    // Step 3: Fill dp iteratively
    for (int i = 2; i <= nStairs; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    // Step 4: The answer is stored at dp[n]
    return dp[nStairs];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 4️⃣ SPACE OPTIMIZED APPROACH
/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   🔹 Idea:
     - In Tabulation, each state only depends on previous 2 states.
     - So we can just store two variables instead of the entire dp array.
   🔹 Time Complexity: O(n)
   🔹 Space Complexity: O(1)
*/

int countDistinctWaysOpt(int nStairs) {
    if (nStairs == 0 || nStairs == 1)
        return 1;

    long long prev1 = 1; // dp[i-2]
    long long prev2 = 1; // dp[i-1]

    // Iteratively compute the next value using the last two
    for (int i = 2; i <= nStairs; i++) {
        long long curr = (prev1 + prev2) % MOD;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 🧪 MAIN FUNCTION (Test all approaches)
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "\n🔹 Recursive Approach: " << countDistinctWaysRec(n);
    cout << "\n🔹 Top-Down (Memoization): " << countDistinctWaysMemo(n);
    cout << "\n🔹 Bottom-Up (Tabulation): " << countDistinctWaysTab(n);
    cout << "\n🔹 Space Optimized: " << countDistinctWaysOpt(n) << endl;

    return 0;
}
