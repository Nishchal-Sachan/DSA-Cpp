#include <bits/stdc++.h>
using namespace std;

/*
   =====================================================================
   🏁 Problem: Minimum Sideway Jumps (LeetCode 1824)
   Frog starts at:
       Lane = 2, Position = 0
   Goal:
       Reach Position = n with minimum side jumps.

   obstacles[i] = lane number blocked at position i
   If obstacles[i] == lane, frog cannot be in that lane at that position.

   ---------------------------------------------------------------------
   Understanding the problem visually:

       Lane 1:  .  X  .  .  .
       Lane 2:  .  .  .  X  .
       Lane 3:  .  .  X  .  .

   The frog can either:
     • Move FORWARD (no cost) if next cell is not blocked
     • SIDE JUMP (cost = 1) if forward is blocked

   ---------------------------------------------------------------------
   INDEXING NOTE (IMPORTANT):
       We will use a dp array of size [4][n+1]
       Lanes are: 1, 2, 3
       Lane 0 is NOT used — but we keep it to avoid confusion and shifting.
       ✅ YOUR LOGIC IS PRESERVED EXACTLY.

   =====================================================================
*/


/*=====================================================================
   1️⃣ PURE RECURSION (Brute force) — EXPLANATION IN DEPTH
   --------------------------------------------------------------------
   Intuition:
     At (lane, pos), we have 2 cases:

     Case A: Forward is free:
         -> Move forward:  solve(lane, pos+1)

     Case B: Forward is blocked:
         -> Try switching to any other lane that is NOT blocked
         -> Side jump costs 1:
              1 + solve(newLane, pos)

     Base Case:
         If pos == n → already at end → no more jumps needed → return 0

   Drawback:
     This explores the same states repeatedly → EXPONENTIAL complexity.
=====================================================================*/
int solveRec(vector<int>& obstacles, int lane, int pos) {
    int n = obstacles.size() - 1;
    if (pos == n) return 0; // Reached finish line

    // Forward free → just move
    if (obstacles[pos+1] != lane)
        return solveRec(obstacles, lane, pos+1);

    // Forward blocked → try side jumps
    int ans = INT_MAX;
    for(int newLane = 1; newLane <= 3; newLane++){
        if(newLane != lane && obstacles[pos] != newLane){
            ans = min(ans, 1 + solveRec(obstacles, newLane, pos));
        }
    }
    return ans;
}


/*=====================================================================
   2️⃣ TOP DOWN DP (Memoization)
   --------------------------------------------------------------------
   Same logic as recursion, but store answers in dp[lane][pos].

   Why memo works?
   Because (lane, pos) uniquely identifies a subproblem.
   Many recursive calls revisit the same state → cache avoids repetition.

   dp[lane][pos] = minimum jumps needed from (lane, pos)
=====================================================================*/
int solveMemo(vector<int>& obstacles, int lane, int pos, vector<vector<int>>& dp){
    int n = obstacles.size() - 1;
    if(pos == n) return 0;

    if(dp[lane][pos] != -1) return dp[lane][pos];

    if(obstacles[pos+1] != lane)
        return dp[lane][pos] = solveMemo(obstacles, lane, pos+1, dp);

    int ans = INT_MAX;
    for(int newLane = 1; newLane <= 3; newLane++){
        if(newLane != lane && obstacles[pos] != newLane){
            ans = min(ans, 1 + solveMemo(obstacles, newLane, pos, dp));
        }
    }
    return dp[lane][pos] = ans;
}


/*=====================================================================
   3️⃣ BOTTOM UP DP (Your Logic With Explanation)
   --------------------------------------------------------------------
   dp[lane][pos] = minimum jumps needed to go from (lane, pos) to end.

   WHY YOUR TRANSITION USES `dp[newLane][pos+1]`:
   ------------------------------------------------
   In your interpretation:
       A side jump switches lane AND THEN moves forward.

   So your meaning becomes:
       Side jump cost = 1 + dp[newLane][pos+1]

   This is valid because:
       When switching lanes, the frog IMMEDIATELY proceeds forward
       (it does not stay at same `pos` after lane change).

   This is a different but perfectly consistent state definition.

   Final answer also requires choosing best starting lane adjustment:
       min(dp[2][0], dp[1][0] + 1, dp[3][0] + 1)
=====================================================================*/
int solveBottomUp(vector<int>& obstacles){
    int n = obstacles.size() - 1;

    vector<vector<int>> dp(4, vector<int>(n+1, 1e9));

    dp[1][n] = dp[2][n] = dp[3][n] = 0; // At end → no cost

    for(int pos = n-1; pos >= 0; pos--){
        for(int lane = 1; lane <= 3; lane++){

            if(obstacles[pos+1] != lane){
                dp[lane][pos] = dp[lane][pos+1]; // forward move
            } else {
                // must side jump
                int best = INT_MAX;
                for(int newLane = 1; newLane <= 3; newLane++){
                    if(newLane != lane && obstacles[pos] != newLane){
                        best = min(best, 1 + dp[newLane][pos+1]);
                    }
                }
                dp[lane][pos] = best;
            }
        }
    }
    return min({dp[2][0], dp[1][0] + 1, dp[3][0] + 1});
}


/*=====================================================================
   4️⃣ SPACE OPTIMIZED DP (Your Logic)
   --------------------------------------------------------------------
   Observation:
     dp[lane][pos] only depends on dp[lane][pos+1].
     So we do NOT need the entire dp table → Only store current & next row.

   next[lane] = dp[lane][pos+1]
   curr[lane] = dp[lane][pos]
=====================================================================*/
int solveSpaceOptimized(vector<int>& obstacles){
    int n = obstacles.size() - 1;

    vector<int> curr(4, 1e9), next(4, 1e9);

    next[1] = next[2] = next[3] = 0;

    for(int pos = n-1; pos >= 0; pos--){
        curr = vector<int>(4, 1e9);

        for(int lane = 1; lane <= 3; lane++){
            if(obstacles[pos+1] != lane){
                curr[lane] = next[lane];
            } else {
                for(int newLane = 1; newLane <= 3; newLane++){
                    if(newLane != lane && obstacles[pos] != newLane){
                        curr[lane] = min(curr[lane], 1 + next[newLane]);
                    }
                }
            }
        }

        next = curr;
    }

    return min({next[2], next[1] + 1, next[3] + 1});
}


/*=====================================================================
   DRIVER
=====================================================================*/
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {

        // 1️⃣ Recursion:
        // return solveRec(obstacles, 2, 0);

        // 2️⃣ Memoization:
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solveMemo(obstacles, 2, 0, dp);

        // 3️⃣ Bottom Up DP (Your Logic):
        // return solveBottomUp(obstacles);

        // 4️⃣ Space Optimized DP (Your Logic, Best):
        return solveSpaceOptimized(obstacles);
    }
};
