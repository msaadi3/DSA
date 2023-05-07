#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    deque<int> maxi;
    deque<int> mini;
    long long sum = 0;

    // Process for first window of size k
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && nums[mini.back()] >= nums[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    for (int i = k; i < n; i++)
    {

        sum += nums[maxi.front()] + nums[mini.front()];

        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && nums[mini.back()] >= nums[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    sum += nums[maxi.front()] + nums[mini.front()];

    return sum;
}
