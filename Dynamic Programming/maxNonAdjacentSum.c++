#include <bits/stdc++.h>
using namespace std;

// Maximum sum of non adjacent elements
// Using only recursion / TLE
int maxNonAdjacentSumRec(vector<int> &vect, int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return vect[0];
    }

    // include recursive call
    int include = maxNonAdjacentSumRec(vect, n - 2) + vect[n];
    // exclude recursive call
    int exclude = maxNonAdjacentSumRec(vect, n - 1) + 0;

    int ans = max(include, exclude);
    return ans;
}

// DP
// Top down approach  /  Recursion + Memoization
// T.C is O(N) and S.C is O(N+N)
int maxNonAdjacentSumMem(vector<int> &vect, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return vect[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // include recursive call
    int include = maxNonAdjacentSumMem(vect, n - 2, dp) + vect[n];
    // exclude recursive call
    int exclude = maxNonAdjacentSumMem(vect, n - 1, dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return maxNonAdjacentSumMem(nums, nums.size() - 1, dp);
}

// USING TABULATION
// T.C is O(N) and S.C is O(N)
int maximumNonAdjacentSumTab(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

// SPACE OPTIMIZED TABULATION
// T.C is O(N) and S.C is O(1)
int optimizedMaxNonAdjacentSumTab(vector<int> &nums)
{
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;
        int answer = max(include, exclude);
        prev2 = prev1;
        prev1 = answer;
    }
    return prev1;
}
