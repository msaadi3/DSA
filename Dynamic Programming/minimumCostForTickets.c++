#include <bits/stdc++.h>
using namespace std;
// 983. Minimum Cost For Tickets
// Didn't understand this question that much especially last appraoch didn't understand at all / see other people's solution for this problem on leet code
// Recursive / TLE
class Solution
{
    int solveRec(vector<int> &days, vector<int> &costs, int index, int n)
    {
        if (index >= n)
        {
            return 0;
        }

        // option 1: One day pass
        int op1 = costs[0] + solveRec(days, costs, index + 1, n);

        // option 2: Seven day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int op2 = costs[1] + solveRec(days, costs, i, n);

        // option 3: thirty days pass
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;

        int op3 = costs[2] + solveRec(days, costs, i, n);

        return min(op1, min(op2, op3));
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return solveRec(days, costs, 0, days.size());
    }
};

// Top down approach
// Recursion + Memoization

class Solution
{
    int solveMem(vector<int> &days, vector<int> &costs, int index, int n, vector<int> &dp)
    {
        if (index >= n)
        {
            return 0;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        // option 1: One day pass
        int op1 = costs[0] + solveMem(days, costs, index + 1, n, dp);

        // option 2: Seven day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int op2 = costs[1] + solveMem(days, costs, i, n, dp);

        // option 3: thirty days pass
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;

        int op3 = costs[2] + solveMem(days, costs, i, n, dp);

        dp[index] = min(op1, min(op2, op3));
        return dp[index];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solveMem(days, costs, 0, n, dp);
    }
};

// Bottom up approach
// Tabulation

class Solution
{
    int solveTab(vector<int> &days, vector<int> &costs)
    {

        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--)
        {

            // option 1: One day pass
            int op1 = costs[0] + dp[index + 1];

            // option 2: Seven day pass
            int i;
            for (i = index; i < n && days[i] < days[index] + 7; i++)
                ;

            int op2 = costs[1] + dp[i];

            // option 3: thirty days pass
            for (i = index; i < n && days[i] < days[index] + 30; i++)
                ;

            int op3 = costs[2] + dp[i];

            dp[index] = min(op1, min(op2, op3));
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return solveTab(days, costs);
    }
};

// Space optimization for tabulation using sliding window approach with queues

class Solution
{
    int solveTabOpt(vector<int> &days, vector<int> &costs)
    {
        queue<pair<int, int>> monthly; // first is for days and second is for costs
        queue<pair<int, int>> weekly;  // first is for days and second is for costs
        int ans = 0;

        for (int &day : days)
        {
            // Remove expired days
            while (!monthly.empty() && monthly.front().first + 30 <= day)
            {
                monthly.pop();
            }

            while (!weekly.empty() && weekly.front().first + 7 <= day)
            {
                weekly.pop();
            }

            // add cost for current day
            weekly.push(make_pair(day, ans + costs[1]));
            monthly.push(make_pair(day, ans + costs[2]));

            // update ans
            ans = min(costs[0] + ans, min(weekly.front().second, monthly.front().second));
        }

        return ans;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return solveTabOpt(days, costs);
    }
};
