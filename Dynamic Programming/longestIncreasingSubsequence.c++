#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solveRec(vector<int> &nums, int n, int curr, int prev)
    {
        if (curr == n)
        {
            return 0;
        }

        // Include
        int include = 0;
        if (prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + solveRec(nums, n, curr + 1, curr);
        }
        // Exclude
        int exclude = 0 + solveRec(nums, n, curr + 1, prev);

        return max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solveRec(nums, n, 0, -1);
    }
};

// Recursion + Memoization

class Solution
{
    int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        // Include
        int include = 0;
        if (prev == -1 || nums[prev] < nums[curr])
        {
            include = 1 + solveMem(nums, n, curr + 1, curr, dp);
        }
        // Exclude
        int exclude = 0 + solveMem(nums, n, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMem(nums, n, 0, -1, dp);
    }
};

// Tabulation
class Solution
{
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // Include
                int include = 0;
                if (prev == -1 || nums[prev] < nums[curr])
                {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                // Exclude
                int exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        // return dp[0][-1+1];
        return dp[0][0];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return solveTab(nums);
    }
};

// More space optimization

class Solution
{
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // Include
                int include = 0;
                if (prev == -1 || nums[prev] < nums[curr])
                {
                    include = 1 + nextRow[curr + 1];
                }
                // Exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return solveTab(nums);
    }
};

// DP with Binary search
// T.C is O(nlogn) and S.C in worst case is O(n)
class Solution
{
    int solveDPwithBS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // Find just larger element's index in ans using binary search
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return solveDPwithBS(nums);
    }
};