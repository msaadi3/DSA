#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
    int solveRec(vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return 1;
        }

        if (target < 0)
        {
            return 0;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += solveRec(nums, target - nums[i]);
        }
        return sum;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        return solveRec(nums, target);
    }
};

// Top down approach
// Recursion + Memoization

class Solution
{
    int solveMem(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
        {
            return 1;
        }

        if (target < 0)
        {
            return 0;
        }

        if (dp[target] != -1)
        {
            return dp[target];
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += solveMem(nums, target - nums[i], dp);
        }
        dp[target] = sum;
        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solveMem(nums, target, dp);
    }
};

// Bottom up approach
// Tabulation

class Solution
{
    int solveTab(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        // Traversing from target 1 to target
        for (int i = 1; i <= target; i++)
        {
            // traversing on nums vector
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {

                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        return solveTab(nums, target);
    }
};

// Space optimization for tabulation is not possible in this question