#include <bits/stdc++.h>
using namespace std;

// Sliding window approach
vector<int> firstNegative(vector<int> arr, int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    // Process first window of k size
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Store answer for the first window
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining windows
    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}