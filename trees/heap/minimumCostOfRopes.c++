#include <bits/stdc++.h>
using namespace std;

// T.C is O(NlogN) and S.C is O(N)
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }

        long long cost = 0;

        while (minHeap.size() > 1)
        {
            long long a = minHeap.top();
            minHeap.pop();

            long long b = minHeap.top();
            minHeap.pop();

            long long sum = a + b;
            cost += sum;
            minHeap.push(sum);
        }
        return cost;
    }
};