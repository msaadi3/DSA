#include <bits/stdc++.h>
using namespace std;

// Recursion just to practise more / TLE
class Solution
{
    int solve(vector<int> &cost, int n)
    {
        // base case
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans = min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;
    }
};

// DP

// Top down approach / Recursion + Memoization
// T.C is O(N) and S.C is O(N + N)
class Solution
{
    int solve(vector<int> &cost, int n, vector<int> &dp)
    {
        // base case
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        // after base case check if there's something in dp array corresponding to this call if yes then just return no need to process agin
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Store the answer in dp array
        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

// Bottom-up approach / Tabulation
// T.C is O(N) and S.C is O(N)
class Solution
{

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);

        // base case in dp array
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};

// Space optimization for tabulation approach
// T.C is  O(N) and S.C is O(1)
class Solution
{

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // store base case in variables
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr = 0;

        for (int i = 2; i < n; i++)
        {
            curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};