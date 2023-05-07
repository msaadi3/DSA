#include <bits/stdc++.h>
using namespace std;

// MOD is requied in question that's why
#define MOD 1000000007

// Recursion / TLE
// T.C is exponential
long long int countDerangements(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    int ans = ((n - 1) % MOD * (countDerangements(n - 1) % MOD + countDerangements(n - 2) % MOD) % MOD);
    return ans;
}

// Top down approach
// Recursion + MEMOIZATION
// T.C is O(N) and S.C is O(N+N)
long long int solve(vector<int> &dp, int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = ((n - 1) % MOD * (solve(dp, n - 1) % MOD + solve(dp, n - 2) % MOD) % MOD);
    return dp[n];
}
long long int countDerangements(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    vector<int> dp(n + 1, -1);
    return solve(dp, n);
}

// Tabulation
// T.C is O(N) and S.C is O(N)
long long int countDerangements(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;
        dp[i] = ans;
    }

    return dp[n];
}

// Space optimization for tabulation
// T.C O(N) and S.C O(1)
long long int countDerangements(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
