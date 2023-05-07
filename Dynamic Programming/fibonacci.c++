#include <bits/stdc++.h>
using namespace std;

// fibonacci in dynamic promramming using memoziation
int fibonacci(int n, vector<int> dp)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int fibonacciMain(int n)
{
    int r;
    vector<int> dp(n + 1, -1);
    // dp[n] = fibonacci(n, dp);
    // return dp[n];
    // r = fibonacci(n, dp);
    // return r;
    return fibonacci(n, dp);
}

// fibonacci in dynamic promramming using tabulation

int fibonacciTabulation(int n)
{
    vector<int> dp(n + 1, -1);

    // initialize dp with base case of recursion
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// fibonacci in dynamic promramming using tabulation but optimization in space complexity
int optimizedFibonacciTabulation(int n)
{
    int prev1 = 0;
    int prev2 = 1;
    int current;
    for (int i = 2; i <= n; i++)
    {
        // int current = (prev1 - 1) + (prev2 - 2);
        // prev1 = prev2;
        // prev2 = current;
        current = prev1 + prev2;
    }
    return prev1;
}
int main()
{
    int f;
    cout << "enter the number to find its fibonacci sequence ";
    cin >> f;

    // int ans = fibonacciTabulation(f);
    // cout << ans;

    // vector<int> dp(f + 1, -1);
    // int ans = fibonacci(f, dp);
    // cout << ans;

    // int ans = fibonacciMain(f);
    // cout << ans;

    int ans = optimizedFibonacciTabulation(f);
    cout << ans;

    return 0;
}