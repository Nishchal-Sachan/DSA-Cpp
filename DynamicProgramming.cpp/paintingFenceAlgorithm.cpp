#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

/****************************************************************************************
 * 🧠 PROBLEM STATEMENT:
 * You are given `n` fence posts and `k` colors. 
 * Find the number of ways to paint all the posts such that no more than two adjacent 
 * posts have the same color.
 * 
 * Example:
 *   n = 3, k = 2
 *   Output = 6
 * 
 * Base Cases:
 *   f(1) = k
 *   f(2) = k + k*(k-1)
 * 
 * Recurrence Relation:
 *   f(n) = (k - 1) * ( f(n-1) + f(n-2) )
 * 
 * Explanation:
 *   - If the last two posts are painted with different colors → (k-1) choices for new post.
 *   - If the last two posts are painted with the same color → again (k-1) choices for new post.
 * 
 * Modular Arithmetic is applied to prevent integer overflow.
 ****************************************************************************************/


/*------------------------------ APPROACH 1: RECURSIVE ----------------------------------
 * ❌ Exponential Time Complexity: O(2^n)
 * ❌ Causes Stack Overflow for large n
 * ✅ Conceptually Simple
 ---------------------------------------------------------------------------------------*/
long long solveRecursive(int n, int k) {
    // Base cases
    if (n == 1) return k;
    if (n == 2) return (k + 1LL * k * (k - 1)) % MOD;

    // Recurrence: f(n) = (k-1) * (f(n-1) + f(n-2))
    long long ans = ((k - 1) * ( (solveRecursive(n - 1, k) + solveRecursive(n - 2, k)) % MOD )) % MOD;
    return ans;
}


/*--------------------------- APPROACH 2: MEMOIZATION -----------------------------------
 * ✅ Time Complexity: O(n)
 * ✅ Space Complexity: O(n)
 * ✅ Avoids repeated recursive calls using DP array
 ---------------------------------------------------------------------------------------*/
long long add(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
long long mul(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long solveMemo(int n, int k, vector<long long>& dp) {
    // Base cases
    if (n == 1) return k;
    if (n == 2) return add(k, mul(k, (k - 1)));

    if (dp[n] != -1) return dp[n];

    // Store the result in dp array
    dp[n] = mul((k - 1), add(solveMemo(n - 1, k, dp), solveMemo(n - 2, k, dp)));
    return dp[n];
}

long long numberOfWaysMemoization(int n, int k) {
    vector<long long> dp(n + 1, -1);
    return solveMemo(n, k, dp);
}


/*---------------------------- APPROACH 3: TABULATION -----------------------------------
 * ✅ Iterative Bottom-Up DP
 * ✅ Time Complexity: O(n)
 * ✅ Space Complexity: O(n)
 * 
 * Optimization: Can further reduce space to O(1)
 ---------------------------------------------------------------------------------------*/
long long solveTabulation(int n, int k) {
    vector<long long> dp(n + 1, 0);

    // Base initialization
    dp[1] = k % MOD;
    dp[2] = add(k, mul(k, (k - 1)));

    // Bottom-up computation
    for (int i = 3; i <= n; i++) {
        dp[i] = mul((k - 1), add(dp[i - 1], dp[i - 2]));
    }

    return dp[n];
}


/*---------------------- APPROACH 4: SPACE OPTIMIZATION ---------------------------------
 * ✅ Time Complexity: O(n)
 * ✅ Space Complexity: O(1)
 ---------------------------------------------------------------------------------------*/
long long solveSpaceOptimized(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return add(k, mul(k, (k - 1)));

    long long prev2 = k;                      // f(1)
    long long prev1 = add(k, mul(k, (k - 1))); // f(2)

    for (int i = 3; i <= n; i++) {
        long long curr = mul((k - 1), add(prev1, prev2));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1 % MOD;
}


/*-------------------------------- MAIN FUNCTION ---------------------------------------*/
int numberOfWays(int n, int k) {
    // You can switch between approaches here for testing
    // return solveRecursive(n, k);
    // return numberOfWaysMemoization(n, k);
    // return solveTabulation(n, k);
    return solveSpaceOptimized(n, k);  // ✅ Final optimized version
}


/*-------------------------------- DRIVER CODE -----------------------------------------*/
int main() {
    int n = 4, k = 3;

    cout << "Recursive: " << solveRecursive(n, k) << endl;
    cout << "Memoization: " << numberOfWaysMemoization(n, k) << endl;
    cout << "Tabulation: " << solveTabulation(n, k) << endl;
    cout << "Space Optimized: " << solveSpaceOptimized(n, k) << endl;

    cout << "\n✅ Final Answer (Optimized): " << numberOfWays(n, k) << endl;

    return 0;
}
