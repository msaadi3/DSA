#include <bits/stdc++.h>
using namespace std;
// Logic of longest increasing subsequence(LIS) of DP with binary search approach
// Didn't get it why we are using always 1 like envelopes[i][1] and compareator and lower bound and learn how to implement lower bound
// functionality in binary search function
// T.C is O(nlogn) and S.C in worst case is O(n)
class Solution
{
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }

    int solve(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || envelopes[i][1] > ans.back())
            {
                ans.push_back(envelopes[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        return solve(envelopes);
    }
};