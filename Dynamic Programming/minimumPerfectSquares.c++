#include <bits/stdc++.h>
using namespace std;

// 279. Perfect Squares

// Recursive / TLE
class Solution
{
    int solveRec(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solveRec(n - i * i));
        }

        return ans;
    }

public:
    int numSquares(int n)
    {
        return solveRec(n);
    }
};

// Top down approach
// Recursion + Memoization

class Solution
{
    int solveMem(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solveMem(n - i * i, dp));
        }

        dp[n] = ans;
        return dp[n];
    }

public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solveMem(n, dp);
    }
};

// Bottom up approach
// Tabulation

class Solution
{
    int solveTab(int n)
    {

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= n; j++)
            {
                if (dp[i - j * j] >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
        }
    }

public:
    int numSquares(int n)
    {
        return solveTab(n);
    }
};

// Space optimization is not possible