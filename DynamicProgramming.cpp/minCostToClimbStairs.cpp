/*
🧩 Problem: Min Cost Climbing Stairs (LeetCode #746)

You are given an integer array `cost` where cost[i] is the cost of the i-th step on a staircase.
Once you pay the cost, you can climb either one or two steps.

Return the minimum cost to reach the top of the floor.
You can start from step 0 or step 1.

------------------------------------------------------
We’ll solve it using 4 different approaches:
1️⃣ Pure Recursion
2️⃣ Recursion + Memoization (Top-Down DP)
3️⃣ Tabulation (Bottom-Up DP)
4️⃣ Space Optimized DP
------------------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;


/*------------------------------------------------------
1️⃣ PURE RECURSION
--------------------------------------------------------
💡 Approach:
- Recursively calculate the cost to reach the current step.
- Base cases: cost[0] and cost[1]
- For each step n, total cost = cost[n] + min(cost to reach n-1, cost to reach n-2)
- Final answer = min(cost to reach n-1, cost to reach n-2)

🕒 Time Complexity: O(2^n)
💾 Space Complexity: O(n) (due to recursion stack)
------------------------------------------------------*/

class RecursionSolution {
public:
    int solve(vector<int>& cost, int n) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        // Recursively calculate minimum cost for current step
        return cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // The top can be reached either from (n-1)th or (n-2)th step
        return min(solve(cost, n - 1), solve(cost, n - 2));
    }
};


/*------------------------------------------------------
2️⃣ RECURSION + MEMOIZATION (TOP-DOWN DP)
--------------------------------------------------------
💡 Approach:
- Store results of subproblems in a dp array to avoid recomputation.
- dp[n] = cost[n] + min(dp[n-1], dp[n-2])

🕒 Time Complexity: O(n)
💾 Space Complexity: O(n) (dp array + recursion stack)
------------------------------------------------------*/

class MemoizationSolution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];

        if (dp[n] != -1) return dp[n];

        // Store computed result in dp[n]
        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        // Choose the cheaper option between reaching (n-1)th or (n-2)th step
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};


/*------------------------------------------------------
3️⃣ TABULATION (BOTTOM-UP DP)
--------------------------------------------------------
💡 Approach:
- Build the dp array iteratively.
- dp[i] = cost[i] + min(dp[i-1], dp[i-2])
- Answer = min(dp[n-1], dp[n-2])

🕒 Time Complexity: O(n)
💾 Space Complexity: O(n)
------------------------------------------------------*/

class TabulationSolution {
public:
    int solve(vector<int>& cost, int n) {
        vector<int> dp(n + 1);

        // Base initialization
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill dp table bottom-up
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Return minimum cost to reach the top
        return min(dp[n - 1], dp[n - 2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};


/*------------------------------------------------------
4️⃣ SPACE OPTIMIZED DP
--------------------------------------------------------
💡 Approach:
- Instead of storing all dp values, we only need the last two.
- prev1 → cost to reach (i-2)th step
- prev2 → cost to reach (i-1)th step
- curr = cost[i] + min(prev1, prev2)

🕒 Time Complexity: O(n)
💾 Space Complexity: O(1)
------------------------------------------------------*/

class SpaceOptimizedSolution {
public:
    int solve(vector<int>& cost, int n) {
        int prev1 = cost[0];
        int prev2 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};


/*------------------------------------------------------
🧪 MAIN FUNCTION FOR TESTING
------------------------------------------------------*/

int main() {
    vector<int> cost = {10, 15, 20};

    RecursionSolution rec;
    MemoizationSolution memo;
    TabulationSolution tab;
    SpaceOptimizedSolution opt;

    cout << "1️⃣ Recursion: " << rec.minCostClimbingStairs(cost) << endl;
    cout << "2️⃣ Memoization: " << memo.minCostClimbingStairs(cost) << endl;
    cout << "3️⃣ Tabulation: " << tab.minCostClimbingStairs(cost) << endl;
    cout << "4️⃣ Space Optimized: " << opt.minCostClimbingStairs(cost) << endl;

    return 0;
}
