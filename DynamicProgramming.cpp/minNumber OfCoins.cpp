/*******************************************************************************************
 🎯 PROBLEM: Minimum Elements (Coin Change Problem)
 --------------------------------------------------------------------------------------------
 You are given:
   - An array 'num' of positive integers representing coin denominations.
   - An integer 'x' representing the target amount.

 ➤ TASK:
   Find the minimum number of coins required to make up the amount 'x'.
   If it’s not possible, return -1.

********************************************************************************************/

#include <bits/stdc++.h> 
using namespace std;


/*******************************************************************************************
 🧠 APPROACH 1: Pure Recursion
 --------------------------------------------------------------------------------------------
 1️⃣ We try every coin recursively and reduce the target 'x' by that coin’s value.
 2️⃣ Base cases:
     - If x == 0 → 0 coins needed.
     - If x < 0 → invalid case (return INT_MAX).
 3️⃣ We explore all combinations and return the minimum number of coins possible.

 ⚙️ Time Complexity: Exponential (2^X)
 ⚙️ Space Complexity: O(X) (recursive stack)
********************************************************************************************/
int solveRec(vector<int> &num, int x) {
    if (x == 0) return 0;              // Base: no coins needed for sum 0
    if (x < 0) return INT_MAX;         // Base: invalid sum

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++) {
        int ans = solveRec(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

int minimumElementsRecursion(vector<int> &num, int x) {
    int ans = solveRec(num, x);
    return ans == INT_MAX ? -1 : ans;
}


/*******************************************************************************************
 🧠 APPROACH 2: Recursion + Memoization (Top-Down DP)
 --------------------------------------------------------------------------------------------
 1️⃣ Same recursion logic, but we store results in 'dp' array to avoid recomputation.
 2️⃣ dp[x] = minimum coins required to make sum 'x'.
 3️⃣ Before calculating a new subproblem, check dp[x]; if already computed, reuse it.

 ⚙️ Time Complexity: O(N × X)
 ⚙️ Space Complexity: O(X) + O(X) recursion stack
********************************************************************************************/
int solveMemo(vector<int> &num, int x, vector<int> &dp) {
    if (x == 0) return 0;
    if (x < 0) return INT_MAX;
    if (dp[x] != -1) return dp[x];     // Return already computed state

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++) {
        int ans = solveMemo(num, x - num[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    return dp[x] = mini;               // Store result before returning
}

int minimumElementsMemoization(vector<int> &num, int x) {
    vector<int> dp(x + 1, -1);
    int ans = solveMemo(num, x, dp);
    return ans == INT_MAX ? -1 : ans;
}


/*******************************************************************************************
 🧠 APPROACH 3: Tabulation (Bottom-Up DP)
 --------------------------------------------------------------------------------------------
 1️⃣ We create a dp array of size (x + 1).
 2️⃣ dp[i] → minimum coins to form sum = i.
 3️⃣ Base case: dp[0] = 0 (no coins needed for sum 0).
 4️⃣ For each sum from 1 to x:
       For each coin:
         If we can use the coin (i - coin >= 0):
             dp[i] = min(dp[i], 1 + dp[i - coin])

 ⚙️ Time Complexity: O(N × X)
 ⚙️ Space Complexity: O(X)
********************************************************************************************/
int solveTab(vector<int> &num, int x) {
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;  // Base case

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x];
}

int minimumElementsTabulation(vector<int> &num, int x) {
    return solveTab(num, x);
}


/*******************************************************************************************
 🧠 APPROACH 4: Space Optimization (Optional Variant)
 --------------------------------------------------------------------------------------------
 Since we are only using previous dp states (dp[i - num[j]]), we can still use a 1D dp array.
 But for clarity, the standard 1D dp (above) is already optimal for this problem.

 ⚙️ Time Complexity: O(N × X)
 ⚙️ Space Complexity: O(X)
********************************************************************************************/
int minimumElementsOptimized(vector<int> &num, int x) {
    // Same as tabulation — already optimal in space.
    return solveTab(num, x);
}


/*******************************************************************************************
 🚀 DRIVER FUNCTION
 --------------------------------------------------------------------------------------------
 You can test all approaches here.
********************************************************************************************/
int main() {
    vector<int> num = {1, 2, 3};
    int x = 7;

    cout << "🔹 Recursion: " << minimumElementsRecursion(num, x) << endl;
    cout << "🔹 Memoization: " << minimumElementsMemoization(num, x) << endl;
    cout << "🔹 Tabulation: " << minimumElementsTabulation(num, x) << endl;
    cout << "🔹 Optimized: " << minimumElementsOptimized(num, x) << endl;

    return 0;
}
