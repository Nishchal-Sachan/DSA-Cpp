// File: HouseRobberII.cpp
// Detailed, educational implementations of House Robber II (circular houses)
// Four approaches are provided:
//   1) Pure Recursion (exponential, educational)
//   2) Top-Down Memoization (recursive + dp cache)
//   3) Bottom-Up Tabulation (iterative dp array)
//   4) Space Optimized (iterative O(1) space)
// For circular constraint (first and last adjacent) we reduce to two linear cases:
//   - rob houses [1..n-1]  (exclude first)
//   - rob houses [0..n-2]  (exclude last)
// Answer = max(case1, case2)
//
// Notes:
//  - House values can be large (up to 1e9), sums can exceed 32-bit int -> use long long for sums.
//  - Input arrays are kept as vector<int> for convenience, but cast to long long when summing.

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
// Utility: solveLinear_* helpers
//   Solve the linear (non-circular) "house robber" problem on a given vector.
//   All helpers return long long (safe for large sums).
//////////////////////////////////////////////////////////////////////////////////////

/* ============================================================
   Approach 1A: Pure Recursion (linear case)
   - Educational only: shows recursion tree and choices.
   - Time: O(2^n) (exponential), Space: O(n) (recursion depth)
   - Not for production, but useful to understand recurrence:
       f(i) = max( nums[i] + f(i-2), f(i-1) )
   ============================================================ */
long long solveLinearRecursion(const vector<int> &nums, int idx) {
    // idx is the last index we consider (0-based)
    if (idx < 0) return 0LL;                // no house -> 0
    if (idx == 0) return (long long)nums[0];// single house -> its value

    // include current: nums[idx] + best up to idx-2
    long long incl = (long long) nums[idx] + solveLinearRecursion(nums, idx - 2);
    // exclude current: best up to idx-1
    long long excl = solveLinearRecursion(nums, idx - 1);

    return max(incl, excl);
}

/* ============================================================
   Approach 1B: Pure Recursion wrapper for a vector
   (keeps API consistent: pass the vector, returns answer)
   ============================================================ */
long long solveLinearRecursion(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0LL;
    return solveLinearRecursion(nums, n - 1);
}

//////////////////////////////////////////////////////////////////////////////////////

/* ============================================================
   Approach 2: Top-Down Memoization (recursive + dp cache)
   - Each subproblem idx is computed once and stored in dp.
   - Time: O(n) (for linear case), Space: O(n) for dp + recursion stack
   - dp vector uses long long to store computed values or -1 sentinel.
   ============================================================ */
long long solveLinearMemoRec(const vector<int> &nums, int idx, vector<long long> &dp) {
    if (idx < 0) return 0LL;
    if (idx == 0) return (long long) nums[0];

    if (dp[idx] != -1) return dp[idx];

    long long incl = (long long) nums[idx] + solveLinearMemoRec(nums, idx - 2, dp);
    long long excl = solveLinearMemoRec(nums, idx - 1, dp);

    dp[idx] = max(incl, excl);
    return dp[idx];
}

long long solveLinearMemo(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0LL;
    vector<long long> dp(n, -1LL);            // -1 indicates "not computed"
    return solveLinearMemoRec(nums, n - 1, dp);
}

//////////////////////////////////////////////////////////////////////////////////////

/* ============================================================
   Approach 3: Bottom-Up Tabulation (iterative)
   - Build dp[0..n-1] where dp[i] = best answer using houses [0..i]
   - Transition:
       dp[0] = nums[0]
       dp[1] = max(nums[0], nums[1])
       dp[i] = max(dp[i-1], dp[i-2] + nums[i]) for i >= 2
   - Time: O(n), Space: O(n)
   ============================================================ */
long long solveLinearTabulation(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)nums[0];

    vector<long long> dp(n, 0LL);
    dp[0] = (long long) nums[0];
    dp[1] = max((long long)nums[0], (long long)nums[1]);

    for (int i = 2; i < n; ++i) {
        long long incl = dp[i - 2] + (long long)nums[i]; // pick current
        long long excl = dp[i - 1];                     // skip current
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

//////////////////////////////////////////////////////////////////////////////////////

/* ============================================================
   Approach 4: Space-Optimized Iterative (O(1) space)
   - Keep only the last two dp values: prev1 = dp[i-1], prev2 = dp[i-2]
   - For each i:
       curr = max(prev1, prev2 + nums[i])
       prev2 = prev1
       prev1 = curr
   - Time: O(n), Space: O(1)
   ============================================================ */
long long solveLinearSpaceOptimized(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)nums[0];

    long long prev2 = 0LL;                 // dp[i-2] initially for i=1 -> dp[-1] treated as 0
    long long prev1 = (long long)nums[0];  // dp[0]

    for (int i = 1; i < n; ++i) {
        long long incl = prev2 + (long long)nums[i]; // include current
        long long excl = prev1;                      // exclude current
        long long curr = max(incl, excl);

        // shift window
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

//////////////////////////////////////////////////////////////////////////////////////
// Helper for circular problem (House Robber II)
// For a circular array `valueInHouse` of length n >= 2, we evaluate two cases:
//  - Exclude the first house -> evaluate linear on [1..n-1]
//  - Exclude the last house  -> evaluate linear on [0..n-2]
// Return the max of the two cases.
//
// We'll provide wrappers for each approach so you can test them individually.
//////////////////////////////////////////////////////////////////////////////////////

/* -----------------------
   Recursion-based HouseRobberII
   ----------------------- */
long long houseRobberII_recursion(const vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)valueInHouse[0];
    // Exclude first -> houses [1 .. n-1]
    vector<int> exclFirst(valueInHouse.begin() + 1, valueInHouse.end());
    // Exclude last -> houses [0 .. n-2]
    vector<int> exclLast(valueInHouse.begin(), valueInHouse.end() - 1);

    // solve recursively for both linear subproblems
    long long ans1 = solveLinearRecursion(exclFirst);
    long long ans2 = solveLinearRecursion(exclLast);
    return max(ans1, ans2);
}

/* -----------------------
   Memoization-based HouseRobberII
   ----------------------- */
long long houseRobberII_memo(const vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)valueInHouse[0];

    vector<int> exclFirst(valueInHouse.begin() + 1, valueInHouse.end());
    vector<int> exclLast(valueInHouse.begin(), valueInHouse.end() - 1);

    long long ans1 = solveLinearMemo(exclFirst);
    long long ans2 = solveLinearMemo(exclLast);
    return max(ans1, ans2);
}

/* -----------------------
   Tabulation-based HouseRobberII
   ----------------------- */
long long houseRobberII_tabulation(const vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)valueInHouse[0];

    vector<int> exclFirst(valueInHouse.begin() + 1, valueInHouse.end());
    vector<int> exclLast(valueInHouse.begin(), valueInHouse.end() - 1);

    long long ans1 = solveLinearTabulation(exclFirst);
    long long ans2 = solveLinearTabulation(exclLast);
    return max(ans1, ans2);
}

/* -----------------------
   Space-Optimized HouseRobberII
   ----------------------- */
long long houseRobberII_spaceOpt(const vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 0) return 0LL;
    if (n == 1) return (long long)valueInHouse[0];

    vector<int> exclFirst(valueInHouse.begin() + 1, valueInHouse.end());
    vector<int> exclLast(valueInHouse.begin(), valueInHouse.end() - 1);

    long long ans1 = solveLinearSpaceOptimized(exclFirst);
    long long ans2 = solveLinearSpaceOptimized(exclLast);
    return max(ans1, ans2);
}

//////////////////////////////////////////////////////////////////////////////////////
// Complexity summary (for linear case solved on array length m):
//  - Recursion:       time O(2^m),    space O(m) recursion stack
//  - Memoization:     time O(m),      space O(m)
//  - Tabulation:      time O(m),      space O(m)
//  - Space-optimized: time O(m),      space O(1)
// For circular case we call the linear solver twice (on arrays of size n-1 each),
// so time complexity doubles constant-wise; same asymptotic bounds.
//////////////////////////////////////////////////////////////////////////////////////

// Example main to test and compare all approaches.
// Change the test vectors to run other cases (including edge-cases).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> houses1 = {2, 3, 2};                // expected 3
    vector<int> houses2 = {1, 2, 3, 1};             // expected 4
    vector<int> houses3 = {1000000000, 1, 2, 1000000000}; // expected 2000000000 (fits in long long)

    cout << "===== House Robber II — Multiple Approaches (detailed) =====\n\n";

    // Test 1
    cout << "Houses: {2,3,2}\n";
    cout << " Recursion    : " << houseRobberII_recursion(houses1) << "\n";
    cout << " Memoization  : " << houseRobberII_memo(houses1) << "\n";
    cout << " Tabulation   : " << houseRobberII_tabulation(houses1) << "\n";
    cout << " Space Optim. : " << houseRobberII_spaceOpt(houses1) << "\n\n";

    // Test 2
    cout << "Houses: {1,2,3,1}\n";
    cout << " Recursion    : " << houseRobberII_recursion(houses2) << "\n";
    cout << " Memoization  : " << houseRobberII_memo(houses2) << "\n";
    cout << " Tabulation   : " << houseRobberII_tabulation(houses2) << "\n";
    cout << " Space Optim. : " << houseRobberII_spaceOpt(houses2) << "\n\n";

    // Large values test
    cout << "Houses: {1e9, 1, 2, 1e9}\n";
    cout << " Tabulation   : " << houseRobberII_tabulation(houses3) << "\n";
    cout << " Space Optim. : " << houseRobberII_spaceOpt(houses3) << "\n\n";

    cout << "=============================================================\n";
    return 0;
}
