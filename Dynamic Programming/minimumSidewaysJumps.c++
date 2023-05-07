#include <bits/stdc++.h>
using namespace std;

// 1824. Minimum Sideway Jumps
// Didn't get this question comletely / dry run for later

class Solution
{
    int solveRec(vector<int> &obstacles, int currLane, int currPos)
    {
        int n = obstacles.size() - 1;
        if (currPos == n)
        {
            return 0;
        }

        if (obstacles[currPos + 1] != currLane)
        {
            return solveRec(obstacles, currLane, currPos + 1);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (i != currLane && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solveRec(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solveRec(obstacles, 2, 0);
    }
};

// Recursion + Memoization
class Solution
{
    int solveMem(vector<int> &obstacles, int n, int currLane, int currPos, vector<vector<int>> &dp)
    {
        if (currPos == n - 1)
        {
            return 0;
        }

        if (dp[currLane][currPos] != -1)
        {
            return dp[currLane][currPos];
        }

        if (obstacles[currPos + 1] != currLane)
        {
            return solveMem(obstacles, n, currLane, currPos + 1, dp);
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (i != currLane && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solveMem(obstacles, n, i, currPos, dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {

        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solveMem(obstacles, n, 2, 0, dp);
    }
};

// Tabulation
class Solution
{
    int solveTab(vector<int> &obstacles)
    {

        int n = obstacles.size() - 1;

        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        // Analyze base case
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    dp[currLane][currPos] = dp[currLane][currPos + 1];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (i != currLane && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + dp[i][currPos + 1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solveTab(obstacles);
    }
};

// Space optimization for tabulation

class Solution
{
    int solveTab(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        // Analyze base case
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    curr[currLane] = next[currLane];
                }
                else
                {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (i != currLane && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        return solveTab(obstacles);
    }
};