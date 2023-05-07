#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solveRec(vector<int> &satisfaction, int index, int time, int n)
    {
        if (index >= n)
        {
            return 0;
        }

        int include = satisfaction[index] * (time + 1) + solveRec(satisfaction, index + 1, time + 1, n);
        int exclude = 0 + solveRec(satisfaction, index + 1, time, n);

        return max(include, exclude);
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        return solveRec(satisfaction, 0, 0, n);
    }
};

// Recursion + Memoization

class Solution
{
    int solveMem(vector<int> &satisfaction, int index, int time, int n, vector<vector<int>> &dp)
    {
        if (index >= n)
        {
            return 0;
        }

        if (dp[index][time] != INT_MIN)
        {
            return dp[index][time];
        }

        int include = satisfaction[index] * (time + 1) + solveMem(satisfaction, index + 1, time + 1, n, dp);
        int exclude = 0 + solveMem(satisfaction, index + 1, time, n, dp);

        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN)); // INT_MIN or -1 both are correct
        return solveMem(satisfaction, 0, 0, n, dp);
    }
};

// Tabulation

class Solution
{
    int solveTab(vector<int> &satisfaction)
    {

        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {

                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        return solveTab(satisfaction);
    }
};

// Space optimization for tabulation

class Solution
{
    int optimizedSolveTab(vector<int> &satisfaction)
    {

        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {

                int include = satisfaction[index] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        return optimizedSolveTab(satisfaction);
    }
};

// More space optimization can be done / look for it
// https://leetcode.com/problems/reducing-dishes/solutions/?orderBy=most_votes&languageTags=cpp
