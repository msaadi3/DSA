#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solveRec(vector<vector<int>> &matrix, int n, int m, int &maxi, int i, int j)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }

        int right = solveRec(matrix, n, m, maxi, i, j + 1);
        int diagonal = solveRec(matrix, n, m, maxi, i + 1, j + 1);
        int down = solveRec(matrix, n, m, maxi, i + 1, j);

        if (matrix[i][j] == 1)
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        if (n == 0)

            return 0;

        int maxi = 0;
        solveRec(mat, n, m, maxi, 0, 0);
        return maxi;
    }
};

// Recursion + Memoization
class Solution
{
    int solveMem(vector<vector<int>> &matrix, int n, int m, int &maxi, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = solveMem(matrix, n, m, maxi, i, j + 1, dp);
        int diagonal = solveMem(matrix, n, m, maxi, i + 1, j + 1, dp);
        int down = solveMem(matrix, n, m, maxi, i + 1, j, dp);

        if (matrix[i][j] == 1)
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = 0;
        }
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        if (n == 0)

            return 0;

        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solveMem(mat, n, m, maxi, 0, 0, dp);
        return maxi;
    }
};

// Tabulation
class Solution
{
    void solveTab(vector<vector<int>> &matrix, int row, int col, int &maxi)
    {

        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        if (n == 0)

            return 0;

        int maxi = 0;
        solveTab(mat, n, m, maxi);
        return maxi;
    }
};

// Space optimization of tabulation
class Solution
{
    void OptimizedsolveTab(vector<vector<int>> &matrix, int row, int col, int &maxi)
    {
        vector<int> curr(col + 1, 0);
        vector<int> next(col + 1, 0);

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if (matrix[i][j] == 1)
                {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
    }

public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        if (n == 0)

            return 0;

        int maxi = 0;
        OptimizedsolveTab(mat, n, m, maxi);
        return maxi;
    }
};
