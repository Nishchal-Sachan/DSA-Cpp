#include <bits/stdc++.h>
using namespace std;

/***************************************************************************************************
 🧠 PROBLEM STATEMENT:
 ---------------------------------------------------------------------------------------------------
 Given an array `num[]` of distinct integers and a target value `tar`,
 count the number of possible combinations that sum up to `tar`.

 👉 Order matters (i.e., [1,2] and [2,1] are considered different combinations).

 Example:
   num = [1, 2, 3], target = 4
   All possible combinations:
   [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [1,3], [3,1]
   ✅ Total = 7 ways

 ---------------------------------------------------------------------------------------------------
 BASE CASES:
   • If target < 0 → no valid combination (return 0)
   • If target == 0 → exactly one way (no elements chosen)
 ---------------------------------------------------------------------------------------------------
***************************************************************************************************/


/***************************************************************************************************
 🔹 APPROACH 1: PURE RECURSION
 ---------------------------------------------------------------------------------------------------
 Try all elements at each step and reduce the target accordingly.

 TIME COMPLEXITY:  Exponential  → O(num.size()^target)
 SPACE COMPLEXITY: O(target) (recursive stack)
***************************************************************************************************/
int solveRecursive(vector<int>& num, int target) {
    // Base cases
    if (target < 0) return 0;
    if (target == 0) return 1;

    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        ans += solveRecursive(num, target - num[i]);
    }
    return ans;
}

int findWaysRecursive(vector<int>& num, int tar) {
    return solveRecursive(num, tar);
}


/***************************************************************************************************
 🔹 APPROACH 2: MEMOIZATION (Top-Down DP)
 ---------------------------------------------------------------------------------------------------
 Store results for each target in a dp[] array to avoid recomputation.

 STATE:
   dp[target] = number of combinations to form `target`

 TRANSITION:
   dp[target] = Σ dp[target - num[i]]   for all i where target ≥ num[i]

 TIME COMPLEXITY:  O(num.size() * target)
 SPACE COMPLEXITY: O(target) + O(target) recursion stack
***************************************************************************************************/
int solveMemo(vector<int>& num, int target, vector<int>& dp) {
    if (target < 0) return 0;
    if (target == 0) return 1;

    // Already computed
    if (dp[target] != -1) return dp[target];

    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        ans += solveMemo(num, target - num[i], dp);
    }

    dp[target] = ans;
    return dp[target];
}

int findWaysMemoization(vector<int>& num, int tar) {
    vector<int> dp(tar + 1, -1);
    return solveMemo(num, tar, dp);
}


/***************************************************************************************************
 🔹 APPROACH 3: TABULATION (Bottom-Up DP)
 ---------------------------------------------------------------------------------------------------
 Build dp[] iteratively from 0 → target.

 dp[i] = number of ways to reach sum = i

 TRANSITION:
   dp[i] = Σ dp[i - num[j]] for all j where i ≥ num[j]

 BASE CASE:
   dp[0] = 1 (One way to reach sum 0 — pick nothing)

 TIME COMPLEXITY:  O(num.size() * target)
 SPACE COMPLEXITY: O(target)
***************************************************************************************************/
int solveTabulation(vector<int>& num, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;  // base case

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }

    return dp[target];
}

int findWaysTabulation(vector<int>& num, int tar) {
    return solveTabulation(num, tar);
}


/***************************************************************************************************
 ✅ DRIVER FUNCTION TO TEST ALL APPROACHES
***************************************************************************************************/
int main() {
    vector<int> num = {1, 2, 3};
    int tar = 4;

    cout << "🔹 Recursive: " << findWaysRecursive(num, tar) << endl;
    cout << "🔹 Memoization: " << findWaysMemoization(num, tar) << endl;
    cout << "🔹 Tabulation: " << findWaysTabulation(num, tar) << endl;

    return 0;
}
