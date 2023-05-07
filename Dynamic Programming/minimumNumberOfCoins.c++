#include <bits/stdc++.h>
using namespace std;
// Didn't get it / try to understand later
// Find minimum number of coins to make the target amount
// Using recursion / TLE
// T.C is exponential
class Solution
{
    int solveRec(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveRec(coins, amount - coins[i]);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        return (mini == INT_MAX) ? -1 : mini;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        return solveRec(coins, amount);
    }
};

// DP
// Top down approach / Recursion + Memoization
// T.C O(amunt * coins) and S.C is O(N+N)
class Solution
{
    int solveMem(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return INT_MAX;
        }

        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveMem(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }

        dp[amount] = mini;
        return dp[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int res = solveMem(coins, amount, dp);

        if (res == INT_MAX)
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
};

// Bottom up approach / Tabulation
// T.C remains same O(amount * coins ) and S.C is O(amount)
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        if (coins.empty())
        {
            return -1; // no coins available, cannot make change
        }

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Space optimzation for tabulation isn't possible in this question
