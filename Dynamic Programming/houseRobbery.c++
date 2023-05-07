#include <bits/stdc++.h>
using namespace std;

// Recursion / TLE
class Solution
{
    int solveRec(vector<int> &nums, int index)
    {
        if (index == 0)
        {
            return nums[0];
        }

        if (index < 0)
        {
            return 0;
        }

        int include = solveRec(nums, index - 2) + nums[index];
        int exclude = solveRec(nums, index - 1);

        return max(include, exclude);
    }

public:
    int rob(vector<int> &nums)
    {
        solveRec(nums, nums.size() - 1);
    }
};

// DP
// Recursion + Memoization
// T.C O(N) and S.C is O(N+N)
class Solution
{
    int solve(vector<int> &nums, vector<int> &dp, int index)
    {
        if (index >= nums.size())
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int include = solve(nums, dp, index + 2) + nums[index];
        int exclude = solve(nums, dp, index + 1);

        dp[index] = max(include, exclude);
        return dp[index];
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        solve(nums, dp, 0);
    }
};

// Tabulation
// T.C O(N) and S.C O(N)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

// Space optimization of Tabulation
// T.C is O(N) and S.C O(1)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        int curr = 0;

        for (int i = 2; i < nums.size(); i++)
        {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};