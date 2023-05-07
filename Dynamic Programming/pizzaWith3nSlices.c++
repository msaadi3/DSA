#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solveRec(vector<int> &slices, int index, int lastIndex, int n)
    {
        if (n == 0 || index > lastIndex)
        {
            return 0;
        }

        int include = slices[index] + solveRec(slices, index + 2, lastIndex, n - 1);
        int exclude = 0 + solveRec(slices, index + 1, lastIndex, n);
        return max(include, exclude);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        int case1 = solveRec(slices, 0, n - 2, n / 3);
        int case2 = solveRec(slices, 1, n - 1, n / 3);
        return max(case1, case2);
    }
};

// Recursion + Memoization

class Solution
{
    int solveMem(vector<int> &slices, int index, int lastIndex, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || index > lastIndex)
        {
            return 0;
        }

        if (dp[index][n] != -1)
        {
            return dp[index][n];
        }

        int include = slices[index] + solveMem(slices, index + 2, lastIndex, n - 1, dp);
        int exclude = 0 + solveMem(slices, index + 1, lastIndex, n, dp);
        dp[index][n] = max(include, exclude);
        return dp[index][n];
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>(n / 3 + 1, -1));
        int case1 = solveMem(slices, 0, n - 2, n / 3, dp1);
        // clear dp before computing case2
        // fill(dp.begin(), dp.end(), vector<int>(n, -1)); // i think not the best way
        vector<vector<int>> dp2(n, vector<int>(n / 3 + 1, -1));
        int case2 = solveMem(slices, 1, n - 1, n / 3, dp2);
        return max(case1, case2);
    }
};

// Tabulation
class Solution
{
    int solveTab(vector<int> &slices)
    {
        int size = slices.size();
        // case 1 : include first and skip last one
        vector<vector<int>> dp1(size + 2, vector<int>(size / 3 + 1, 0)); // size+2 to make sure we don't go out of bound in this case index = size - 2 ,dp1[index + 2]

        for (int index = size - 2; index >= 0; index--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int include = slices[index] + dp1[index + 2][n - 1];
                int exclude = 0 + dp1[index + 1][n];
                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][size / 3];

        // case 2 : skip the first one and include last one
        vector<vector<int>> dp2(size + 2, vector<int>(size / 3 + 1, 0));

        for (int index = size - 1; index >= 1; index--)
        {
            for (int n = 1; n <= size / 3; n++)
            {
                int include = slices[index] + dp2[index + 2][n - 1];
                int exclude = 0 + dp2[index + 1][n];
                dp2[index][n] = max(include, exclude);
            }
        }

        int case2 = dp2[1][size / 3];
        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        return solveTab(slices);
    }
};

// Space optimization for tabulation
// Didn't get this approach / gotta try to understand it later
class Solution
{
    int solveTab(vector<int> &slices)
    {
        int size = slices.size();
        // case 1 : include first and skip last one

        vector<int> prev1(size + 2, 0); // dp[index]
        vector<int> curr1(size + 2, 0); // dp[index+1]
        vector<int> next1(size + 2, 0); // dp[index+2]

        for (int index = size - 2; index >= 0; index--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int include = slices[index] + next1[n - 1];
                int exclude = 0 + curr1[n];
                prev1[n] = max(include, exclude);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[size / 3];

        // case 2 : skip the first one and include last one
        vector<vector<int>> dp2(size + 2, vector<int>(size / 3 + 1, 0));

        vector<int> prev2(size + 2, 0); // dp[index]
        vector<int> curr2(size + 2, 0); // dp[index+1]
        vector<int> next2(size + 2, 0); // dp[index+2]

        for (int index = size - 1; index >= 1; index--)
        {
            for (int n = 1; n <= size / 3; n++)
            {
                int include = slices[index] + next2[n - 1];
                int exclude = 0 + curr2[n];
                prev2[n] = max(include, exclude);
            }
            next2 = curr2;
            curr2 = prev2;
        }

        int case2 = curr2[size / 3];
        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        return solveTab(slices);
    }
};