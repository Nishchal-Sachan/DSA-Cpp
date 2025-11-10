#include <bits/stdc++.h>
using namespace std;

/*
======================================================================
🍽️ Problem: Maximum Like-Time Coefficient (Reducing Dishes)
We have `satisfaction[i]` for each dish. If a dish is cooked at time `t`,
its contribution = satisfaction[i] * t.

We may choose to skip some dishes, but the order of cooked dishes matters.

Key Observation:
- Sorting the satisfaction values in ascending order is essential.
- Negative values may reduce total score unless cooked later.

======================================================================
APPROACHES WE WILL IMPLEMENT:
1) Pure Recursion (Exponential)  — Understanding the problem
2) Top-Down DP (Memoization)     — Avoid repeated work
3) Bottom-Up DP (Tabulation)     — Convert recursion to DP
4) Space Optimized DP            — Reduce memory usage to O(n)

======================================================================
State Definition:
Let:
    idx = Dish index we are considering
    time = Number of dishes already cooked before it

Choice:
    Either include this dish → contributes satisfaction[idx] * (time+1)
    Or skip this dish → do not increase time

Recurrence:
    result = max( include , exclude )

Base Case:
    if idx == n → return 0
======================================================================
*/


/*====================================================================
1️⃣ PURE RECURSION (Brute Force) - Understanding the Choice
Time Complexity: O(2^n) → TLE for large inputs
====================================================================*/
int solveRec(vector<int>& satisfaction, int idx, int time){
    if(idx == satisfaction.size()) return 0;

    // Include this dish
    int include = satisfaction[idx] * (time + 1) 
                    + solveRec(satisfaction, idx + 1, time + 1);

    // Skip this dish
    int exclude = solveRec(satisfaction, idx + 1, time);

    return max(include, exclude);
}


/*====================================================================
2️⃣ TOP-DOWN DP (Memoization)
Time Complexity: O(n^2)
Space Complexity: O(n^2)
====================================================================*/
int solveMemo(vector<int>& satisfaction, int idx, int time, vector<vector<int>>& dp){
    if(idx == satisfaction.size()) return 0;

    if(dp[idx][time] != -1) 
        return dp[idx][time];

    int include = satisfaction[idx] * (time + 1)
                    + solveMemo(satisfaction, idx + 1, time + 1, dp);

    int exclude = solveMemo(satisfaction, idx + 1, time, dp);

    return dp[idx][time] = max(include, exclude);
}


/*====================================================================
3️⃣ BOTTOM-UP DP (Tabulation)
dp[idx][time] = best result from index `idx` when `time` dishes done
Filling table backwards from end.
====================================================================*/
int solveTab(vector<int>& satisfaction){
    int n = satisfaction.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // dp[n][*] = 0 already initialized

    for(int idx = n-1; idx >= 0; idx--){
        for(int time = idx; time >= 0; time--){
            int include = satisfaction[idx] * (time + 1) + dp[idx+1][time+1];
            int exclude = dp[idx+1][time];
            dp[idx][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}


/*====================================================================
4️⃣ SPACE OPTIMIZED DP — O(n²) → O(n)
We only need the next row to compute the current row.
====================================================================*/
int solveSpaceOpt(vector<int>& satisfaction){
    int n = satisfaction.size();

    vector<int> curr(n+1, 0), next(n+1, 0);

    for(int idx = n-1; idx >= 0; idx--){
        for(int time = idx; time >= 0; time--){
            int include = satisfaction[idx] * (time + 1) + next[time+1];
            int exclude = next[time];
            curr[time] = max(include, exclude);
        }
        next = curr; // Shift row
    }

    return next[0];
}


/*====================================================================
Main Class calling best approach (Space Optimized)
====================================================================*/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        // 1️⃣ Pure Recursion (TLE):
        // return solveRec(satisfaction, 0, 0);

        // 2️⃣ Memoization:
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveMemo(satisfaction, 0, 0, dp);

        // 3️⃣ Tabulation:
        // return solveTab(satisfaction);

        // 4️⃣ Space Optimized ✨ Best Approach:
        return solveSpaceOpt(satisfaction);
    }
};
