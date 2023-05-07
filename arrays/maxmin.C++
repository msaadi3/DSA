#include <bits/stdc++.h>
using namespace std;
// maximum
int maximum1(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

// another way using builtin function

int maximum2(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

// minimum

int minimum1(int arr[], int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }
    return mini;
}

// another approach of above using builtin functions
int minimum2(int arr[], int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

int main()
{
    return 0;
}