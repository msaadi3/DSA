#include <bits/stdc++.h>
using namespace std;

// XOR of two same elements returns zero
// find unique

int unique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    return 0;
}