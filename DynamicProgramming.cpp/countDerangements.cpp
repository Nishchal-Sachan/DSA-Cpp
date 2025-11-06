#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

/***************************************************************************************************
 🧩 PROBLEM: COUNT DERANGEMENTS
 ---------------------------------------------------------------------------------------------------
 Find the number of ways to arrange 'n' items such that no item appears in its original position.

 Example:
 For n = 3 → Derangements are:
   {2, 3, 1} and {3, 1, 2}
 So, output = 2
***************************************************************************************************/


/***************************************************************************************************
 🔹 APPROACH 1: PURE RECURSION
 ---------------------------------------------------------------------------------------------------
 Recurrence Relation:
   f(n) = (n - 1) * (f(n - 1) + f(n - 2))

 Base Cases:
   f(1) = 0
   f(2) = 1

 Intuition:
   - Pick any element (say i). It cannot go to its own position → (n-1) choices.
   - Suppose it goes to position j:
        Case 1: The element originally at j goes to i → subproblem (n-2)
        Case 2: The element at j does NOT go to i → subproblem (n-1)
***************************************************************************************************/
long long int solveRecursive(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    long long int ans = (n - 1) * (solveRecursive(n - 1) + solveRecursive(n - 2));
    return ans;
}


/***************************************************************************************************
 🔹 APPROACH 2: RECURSION + MEMOIZATION (TOP-DOWN DP)
 ---------------------------------------------------------------------------------------------------
 We use a dp array to store already computed results and avoid recomputation.

 dp[n] = (n - 1) * (dp[n - 1] + dp[n - 2])

 Time Complexity: O(n)
 Space Complexity: O(n) [Recursion Stack + dp Array]
***************************************************************************************************/
long long int solveMemo(int n, vector<long long int> &dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != -1) return dp[n];

    dp[n] = ((n - 1) * (solveMemo(n - 1, dp) + solveMemo(n - 2, dp)) % MOD) % MOD;
    return dp[n];
}

long long int countDerangementsMemo(int n) {
    vector<long long int> dp(n + 1, -1);
    return solveMemo(n, dp);
}


/***************************************************************************************************
 🔹 APPROACH 3: TABULATION (BOTTOM-UP DP)
 ---------------------------------------------------------------------------------------------------
 Build dp array iteratively from base cases.

 Transition:
   dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])

 Time Complexity: O(n)
 Space Complexity: O(n)
***************************************************************************************************/
long long int countDerangementsTab(int n) {
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((i - 1) * ((dp[i - 1] + dp[i - 2]) % MOD)) % MOD;
    }

    return dp[n];
}


/***************************************************************************************************
 🔹 APPROACH 4: SPACE OPTIMIZED DP
 ---------------------------------------------------------------------------------------------------
 Instead of using a dp array, we just store the last two values.

 Variables:
   prev2 = f(n - 2)
   prev1 = f(n - 1)

 Transition:
   curr = (n - 1) * (prev1 + prev2)

 Time Complexity: O(n)
 Space Complexity: O(1)
***************************************************************************************************/
long long int countDerangementsOptimized(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    long long int prev2 = 0; // f(1)
    long long int prev1 = 1; // f(2)
    long long int curr;

    for (int i = 3; i <= n; i++) {
        curr = ((i - 1) * ((prev1 + prev2) % MOD)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1 % MOD;
}


/***************************************************************************************************
 ✅ DRIVER CODE
***************************************************************************************************/
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    cout << "\n🔹 Using Pure Recursion: " << solveRecursive(n);
    cout << "\n🔹 Using Memoization: " << countDerangementsMemo(n);
    cout << "\n🔹 Using Tabulation: " << countDerangementsTab(n);
    cout << "\n🔹 Using Space Optimized DP: " << countDerangementsOptimized(n) << endl;

    return 0;
}
