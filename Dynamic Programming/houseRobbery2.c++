#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums)
    {

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

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return nums[0];
        }

        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> first; // 1st element included
        vector<int> last;  // last element included

        // vector<int> first(nums.begin() + 1, nums.end());
        // vector<int> last(nums.begin(), nums.end()-1);

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                last.push_back(nums[i]);
            }

            if (i != n - 1)
            {
                first.push_back(nums[i]);
            }
        }

        return max(solve(first), solve(last));
    }
};

// ------------------------

class Solution
{
    int solve(vector<int> &nums, int l, int r)
    {
        int prev2 = 0;
        int prev1 = 0;
        int curr = 0;

        for (int i = l; i <= r; i++)
        {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums.size() ? nums[0] : 0;
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
    }
};

// little different
class Solution
{

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums.size() ? nums[0] : 0;
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        int first = dp[nums.size() - 2];
        dp[0] = 0;
        dp[1] = nums[1];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        int second = dp[nums.size()];

        return max(first, second);
    }
};