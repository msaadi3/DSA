#include <bits/stdc++.h>
using namespace std;

// Recursive / TLE
class Solution
{
    int solve(int capacity, int wt[], int val[], int index)
    {
        // base case
        if (index == 0)
        {
            if (wt[0] <= capacity)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        int include = 0;
        if (wt[index] <= capacity)
        {
            include = val[index] + solve(capacity - wt[index], wt, val, index - 1);
        }

        int exclude = 0 + solve(capacity, wt, val, index - 1);

        return max(include, exclude);
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        return solve(W, wt, val, n - 1);
    }
};

// DP
// This is a 2D DP Question
// Top down appraoch
// Recursion + Memoization

class Solution
{
    int solveMem(int capacity, int wt[], int val[], int index, vector<vector<int>> &dp)
    {
        // base case
        if (index == 0)
        {
            if (wt[0] <= capacity)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        if (dp[index][capacity] != -1)
        {
            return dp[index][capacity];
        }

        int include = 0;
        if (wt[index] <= capacity)
        {
            include = val[index] + solveMem(capacity - wt[index], wt, val, index - 1, dp);
        }

        int exclude = 0 + solveMem(capacity, wt, val, index - 1, dp);

        dp[index][capacity] = max(include, exclude);
        return dp[index][capacity];
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solveMem(W, wt, val, n - 1, dp);
    }
};

// Bottom up approach
// Tabulation

class Solution
{
    int solveTab(int capacity, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Analyze base case
        for (int w = wt[0]; w <= capacity; w++)
        {
            if (wt[0] <= w)
            {
                dp[0][w] = val[0];
            }
            else
            {
                dp[0][w] = 0;
            }
        }

        for (int index = 0; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {

                int include = 0;
                if (wt[index] <= w)
                {
                    include = val[index] + dp[index - 1][w - wt[index]];
                }

                int exclude = 0 + dp[index - 1][w];

                dp[index][w] = max(include, exclude);
            }
        }
        return dp[n - 1][capacity];
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        return solveTab(W, wt, val, n);
    }
};
