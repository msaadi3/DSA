#include <bits/stdc++.h>
using namespace std;

// K-th Largest Sum Contiguous Subarray
// Not specific to heap can be through various other approaches but we solved this problem using min heap that's i included in heap folder not in arrays folder

// without using heap / just another approach, not the best one
class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum = sum + Arr[j];
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size() - K];
    }
};

// Question : why we didn't use max heap instead of min heap even though we need kth largest element
// optimized approach using min heap
// T.C is O(N2) and S.C is O(K)
class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {

        priority_queue<int, vector<int>, greater<int>> mini;

        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum = sum + Arr[j];
                if (mini.size() < K)
                {
                    mini.push(sum);
                }
                else
                {
                    if (mini.top() < sum)
                    {
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        return mini.top();
    }
};