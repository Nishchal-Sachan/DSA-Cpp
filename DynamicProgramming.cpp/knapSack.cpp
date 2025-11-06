#include <bits/stdc++.h>
using namespace std;

/*
===============================================================
🧩 0/1 Knapsack Problem — All 5 Approaches (From Brute Force to Optimized)
===============================================================

🧠 PROBLEM STATEMENT:
Given:
- `n` items with weights[] and values[]
- A knapsack with a maximum capacity `W`

Find:
Maximum total value we can achieve by selecting items such that
their total weight ≤ W.
Each item can be taken **at most once** (0/1 property).

---------------------------------------------------------------
🔹 Approach 1: Recursive (Brute Force)
🔹 Approach 2: Top-Down (Memoization)
🔹 Approach 3: Bottom-Up (Tabulation)
🔹 Approach 4: Space Optimization (Two Arrays)
🔹 Approach 5: Single Array Space Optimization
===============================================================
*/



/*---------------------------------------------------------------
🔹 Approach 1: Pure Recursion (Exponential Time)
---------------------------------------------------------------
- Idea: For each item, decide to either include it or exclude it.
- Time: O(2^n)
- Space: O(n) (due to recursion stack)
---------------------------------------------------------------*/
int solveRecursive(vector<int>& weight, vector<int>& value, int index, int maxWeight) {
    if (index == 0) {
        if (weight[0] <= maxWeight) return value[0];
        return 0;
    }

    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + solveRecursive(weight, value, index - 1, maxWeight - weight[index]);

    int exclude = solveRecursive(weight, value, index - 1, maxWeight);
    return max(include, exclude);
}



/*---------------------------------------------------------------
🔹 Approach 2: Memoization (Top-Down DP)
---------------------------------------------------------------
- Store results of overlapping subproblems in a dp table.
- Time: O(n × W)
- Space: O(n × W) + O(n) recursion stack
---------------------------------------------------------------*/
int solveMemo(vector<int>& weight, vector<int>& value, int index, int maxWeight, vector<vector<int>>& dp) {
    if (index == 0) {
        if (weight[0] <= maxWeight) return value[0];
        return 0;
    }

    if (dp[index][maxWeight] != -1) return dp[index][maxWeight];

    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + solveMemo(weight, value, index - 1, maxWeight - weight[index], dp);

    int exclude = solveMemo(weight, value, index - 1, maxWeight, dp);

    return dp[index][maxWeight] = max(include, exclude);
}



/*---------------------------------------------------------------
🔹 Approach 3: Tabulation (Bottom-Up DP)
---------------------------------------------------------------
- Iteratively fill the dp table from smaller subproblems to larger.
- Time: O(n × W)
- Space: O(n × W)
---------------------------------------------------------------*/
int solveTabulation(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // Base case: first item
    for (int w = 0; w <= maxWeight; w++) {
        if (weight[0] <= w)
            dp[0][w] = value[0];
    }

    // Fill table iteratively
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int include = 0;
            if (weight[i] <= w)
                include = value[i] + dp[i - 1][w - weight[i]];

            int exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }

    return dp[n - 1][maxWeight];
}



/*---------------------------------------------------------------
🔹 Approach 4: Space Optimization (Two 1D Arrays)
---------------------------------------------------------------
- Observation: Current row depends only on the previous row.
- So we can use two arrays: `prev` and `curr`.
- Time: O(n × W)
- Space: O(2 × W)
---------------------------------------------------------------*/
int solveSpaceOptimized(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

    // Base case
    for (int w = weight[0]; w <= maxWeight; w++)
        prev[w] = value[0];

    // Process all items
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            int include = 0;
            if (weight[i] <= w)
                include = value[i] + prev[w - weight[i]];

            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[maxWeight];
}



/*---------------------------------------------------------------
🔹 Approach 5: Single Array Space Optimization (Most Efficient)
---------------------------------------------------------------
- Further optimize the two-array version to one array.
- We update `dp[w]` from right to left.

⚠️ WHY BACKWARD TRAVERSAL?
----------------------------------
If we go left-to-right:
  dp[w - weight[i]] would already be updated for the current item,
  corrupting results for other capacities that depend on previous states.

If we go right-to-left:
  We only use states from the previous iteration (unmodified yet).
  Hence, correctness is preserved.

- Time: O(n × W)
- Space: O(W)
---------------------------------------------------------------*/
int solveSingleArray(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> dp(maxWeight + 1, 0);

    // Base case for first item
    for (int w = weight[0]; w <= maxWeight; w++)
        dp[w] = value[0];

    // Process remaining items
    for (int i = 1; i < n; i++) {
        for (int w = maxWeight; w >= 0; w--) {
            if (weight[i] <= w)
                dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
        }
    }

    return dp[maxWeight];
}



/*---------------------------------------------------------------
🏁 MAIN FUNCTION
---------------------------------------------------------------*/
int main() {
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int maxWeight = 5;
    int n = weight.size();

    cout << "🔹 Recursive: " << solveRecursive(weight, value, n - 1, maxWeight) << endl;

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    cout << "🔹 Memoization: " << solveMemo(weight, value, n - 1, maxWeight, dp) << endl;

    cout << "🔹 Tabulation: " << solveTabulation(weight, value, n, maxWeight) << endl;

    cout << "🔹 Space Optimized (Two Arrays): " << solveSpaceOptimized(weight, value, n, maxWeight) << endl;

    cout << "🔹 Single Array (Final Optimized): " << solveSingleArray(weight, value, n, maxWeight) << endl;

    return 0;
}
