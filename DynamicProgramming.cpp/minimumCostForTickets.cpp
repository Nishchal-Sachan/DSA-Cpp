/*
    🟢 Problem: Minimum Coins for Travel Passes
    ------------------------------------------
    You are given:
      - n : total number of days you will go to the gym.
      - days[] : the exact days you go to the gym (strictly increasing).
      - cost[] : cost[0] = cost of 1-day pass
                 cost[1] = cost of 7-day pass
                 cost[2] = cost of 30-day pass

    A pass (1-day / 7-day / 30-day) covers continuous days starting from
    the *day it is bought*.

    Goal: Return the minimum total cost to cover all the given training days.

    Example:
      days = {1, 3, 4, 5, 7, 8}
      cost = {2, 7, 20}

      Output = 11
*/

#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------
    1️⃣ RECURSIVE BRUTE FORCE (Exponential Time)
    -------------------------------------------------------------
    At each "index" (current gym day), we choose:
      - Buy a 1-day pass → move to next day
      - Buy a 7-day pass → skip days covered
      - Buy a 30-day pass → skip days covered

    This recomputes many states → will cause TLE for large inputs.
----------------------------------------------------------------*/
int solveRecursive(int n, vector<int>& days, vector<int>& cost, int index){
    if(index >= n) return 0;

    // Buy 1-day pass
    int op1 = cost[0] + solveRecursive(n, days, cost, index + 1);

    // Buy 7-day pass
    int i = index;
    while(i < n && days[i] < days[index] + 7) i++;
    int op2 = cost[1] + solveRecursive(n, days, cost, i);

    // Buy 30-day pass
    i = index;
    while(i < n && days[i] < days[index] + 30) i++;
    int op3 = cost[2] + solveRecursive(n, days, cost, i);

    return min(op1, min(op2, op3));
}


/*---------------------------------------------------------------
    2️⃣ TOP-DOWN DP (Memoization) – O(n)
    -----------------------------------
    Same logic as recursion, but store results in dp[index] to
    avoid recalculating the same state again.
----------------------------------------------------------------*/
int solveMemo(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp){
    if(index >= n) return 0;

    if(dp[index] != -1) return dp[index]; // return cached result

    int op1 = cost[0] + solveMemo(n, days, cost, index + 1, dp);

    int i = index;
    while(i < n && days[i] < days[index] + 7) i++;
    int op2 = cost[1] + solveMemo(n, days, cost, i, dp);

    i = index;
    while(i < n && days[i] < days[index] + 30) i++;
    int op3 = cost[2] + solveMemo(n, days, cost, i, dp);

    return dp[index] = min(op1, min(op2, op3));
}


/*---------------------------------------------------------------
    3️⃣ BOTTOM-UP DP (Tabulation) – O(n)
    -----------------------------------
    dp[k] = minimum cost to cover training from day index k onward.
    Compute dp from right → left (reverse order).
----------------------------------------------------------------*/
int solveBottomUp(int n, vector<int>& days, vector<int>& cost){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;  // No cost needed after last day.

    for(int k = n - 1; k >= 0; k--){
        
        // 1-day pass
        if(dp[k+1] != INT_MAX)
            dp[k] = min(dp[k], dp[k+1] + cost[0]);

        // 7-day pass
        int i = k;
        while(i < n && days[i] < days[k] + 7) i++;
        if(dp[i] != INT_MAX)
            dp[k] = min(dp[k], dp[i] + cost[1]);

        // 30-day pass
        i = k;
        while(i < n && days[i] < days[k] + 30) i++;
        if(dp[i] != INT_MAX)
            dp[k] = min(dp[k], dp[i] + cost[2]);
    }

    return dp[0];
}


/*---------------------------------------------------------------
    DRIVER FUNCTION (Choose Approach Here)
----------------------------------------------------------------*/
class Solution {
public:
    int minimumCoins(int n, vector<int> days, vector<int> cost){

        // OPTION 1: Pure Recursion (TLE for large input)
        // return solveRecursive(n, days, cost, 0);

        // OPTION 2: Top-Down DP (Recommended Recursive)
        /*
        vector<int> dp(n, -1);
        return solveMemo(n, days, cost, 0, dp);
        */

        // OPTION 3: Bottom-Up DP (Best Approach)
        return solveBottomUp(n, days, cost);
    }
};


/*---------------------------------------------------------------
    MAIN (For Your Local Testing Only)
----------------------------------------------------------------*/
int main(){
    int n = 6;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> cost = {2,7,15};

    Solution obj;
    cout << "Minimum Cost = " << obj.minimumCoins(n, days, cost) << endl;
}
