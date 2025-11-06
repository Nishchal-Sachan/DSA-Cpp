#include <bits/stdc++.h>
using namespace std;

/* ============================================================================
   🧩 Problem: Maximum Number of Segments (Cut Segments)
   ---------------------------------------------------------------------------
   Given a rod of length N and three possible cut lengths X, Y, and Z,
   the goal is to find the *maximum number of segments* that can be made
   by cutting the rod into pieces of lengths X, Y, or Z.

   ⚙️ Example:
      Input: n = 7, x = 5, y = 2, z = 2
      Output: 2
      Explanation: 5 + 2 = 7 → total 2 segments

   ============================================================================ */


/* ============================================================================
   🥇 Approach 1: Pure Recursion (Brute Force)
   ---------------------------------------------------------------------------
   🔹 Idea:
       - At each step, try cutting the rod by x, y, and z.
       - Recursively find the max possible segments.
       - Base cases:
            -> If n == 0 → valid cut combination → return 0.
            -> If n < 0  → invalid cut → return INT_MIN (to represent impossible).

   ⚙️ Time Complexity:  O(3^n)
   💾 Space Complexity: O(n) (recursion stack)
   ============================================================================ */
int solveRecursive(int n, int x, int y, int z) {
    if (n == 0) return 0;          // perfect cut achieved
    if (n < 0) return INT_MIN;     // invalid cut

    int a = 1 + solveRecursive(n - x, x, y, z);
    int b = 1 + solveRecursive(n - y, x, y, z);
    int c = 1 + solveRecursive(n - z, x, y, z);

    return max(a, max(b, c));      // take the best of 3 choices
}

int cutSegments_v1(int n, int x, int y, int z) {
    int ans = solveRecursive(n, x, y, z);
    return ans < 0 ? 0 : ans;
}


/* ============================================================================
   🥈 Approach 2: Recursion + Memoization (Top-Down DP)
   ---------------------------------------------------------------------------
   🔹 Idea:
       - Store previously computed results in dp[].
       - Avoid recomputation for same 'n'.

   ⚙️ Time Complexity:  O(n)
   💾 Space Complexity: O(n)
   ============================================================================ */
int solveMemo(int n, int x, int y, int z, vector<int> &dp) {
    if (n == 0) return 0;
    if (n < 0) return INT_MIN;

    if (dp[n] != INT_MIN) return dp[n];

    int a = 1 + solveMemo(n - x, x, y, z, dp);
    int b = 1 + solveMemo(n - y, x, y, z, dp);
    int c = 1 + solveMemo(n - z, x, y, z, dp);

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments_v2(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    int ans = solveMemo(n, x, y, z, dp);
    return ans < 0 ? 0 : ans;
}


/* ============================================================================
   🥉 Approach 3: Bottom-Up DP (Tabulation)
   ---------------------------------------------------------------------------
   🔹 Idea:
       - Build dp[] from 0 → n.
       - dp[i] = max number of cuts for rod length i.
       - Transition:
            dp[i] = max(1 + dp[i - x], 1 + dp[i - y], 1 + dp[i - z])
       - Ensure dp[i - k] is valid (not INT_MIN).

   ⚙️ Time Complexity:  O(n)
   💾 Space Complexity: O(n)
   ============================================================================ */
int solveTabulation(int n, int x, int y, int z) {
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0; // base case: no cuts for length 0

    for (int i = 1; i <= n; i++) {
        if (i - x >= 0 && dp[i - x] != INT_MIN)
            dp[i] = max(dp[i], 1 + dp[i - x]);

        if (i - y >= 0 && dp[i - y] != INT_MIN)
            dp[i] = max(dp[i], 1 + dp[i - y]);

        if (i - z >= 0 && dp[i - z] != INT_MIN)
            dp[i] = max(dp[i], 1 + dp[i - z]);
    }

    return dp[n] < 0 ? 0 : dp[n];
}

int cutSegments_v3(int n, int x, int y, int z) {
    return solveTabulation(n, x, y, z);
}


/* ============================================================================
   🏆 Approach 4: Space Optimization (Optional)
   ---------------------------------------------------------------------------
   🔹 Observation:
       - For each i, we only depend on dp[i - x], dp[i - y], dp[i - z].
       - But since these can be random distant indices, full dp[] is required.
       - Hence, no direct optimization possible here (O(n) is best).

   ✅ So, Approach 3 (Tabulation) is the Final Optimized Version.
   ============================================================================ */


/* ============================================================================
   🚀 DRIVER CODE (For Local Testing)
   Uncomment to test locally
   ============================================================================ */

int main() {
    int n = 7, x = 5, y = 2, z = 2;

    cout << "Brute Force: " << cutSegments_v1(n, x, y, z) << endl;
    cout << "Memoization: " << cutSegments_v2(n, x, y, z) << endl;
    cout << "Tabulation:  " << cutSegments_v3(n, x, y, z) << endl;

    return 0;
}
