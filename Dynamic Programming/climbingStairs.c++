#include <bits/stdc++.h>
using namespace std;

// Using recursion / TLE
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return 1;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// DP
// Top down approach / Recursion + Memoization
// T.C is O(N) and S.C is O(N + N)

class Solution
{
    int solve(vector<int> &dp, int n)
    {
        // base case
        if (n == 0)
        {
            return 1;
        }

        if (n < 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
        return dp[n];
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};

// Tabulation approach
// T.C is O(N) and S.C is O(N)
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);

        // store base in dp array
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Space optimization for tabulation approach
// T.C is O(N) and S.C is O(1)
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        // store base in variables
        int prev2 = 1;
        int prev1 = 1;
        int curr = 0;

        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};