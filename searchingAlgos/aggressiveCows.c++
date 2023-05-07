#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int n, int k, int mid)
{
    int cowCount = 1;
    int lastPosition = stalls[0];

    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastPosition >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            else
            {
                lastPosition = stalls[i];
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int n, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(stalls[i], maxi);
    }
    int end = maxi;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (isPossible(stalls, n, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    return 0;
}
