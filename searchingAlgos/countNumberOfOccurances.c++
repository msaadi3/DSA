#include <bits/stdc++.h>
using namespace std;

int searchRange(vector<int> &nums, int target)
{
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int firstOccur = 0;
    int lastOccur = 0;

    // first occurance
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            firstOccur = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    // last occurance

    start = 0;
    end = size - 1;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            lastOccur = mid;
            start = mid + 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    int ans = (lastOccur - firstOccur) + 1;
    return ans;
}

// MY SOLUTION

int countOccurences(int arr[], int n, int X)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int firstOccur = -1;
    int lastOccur = -1;

    while (start <= end)
    {
        if (arr[mid] == X)
        {
            firstOccur = mid;
            lastOccur = mid;

            while (arr[firstOccur] == X)
            {
                firstOccur--;
            }

            firstOccur++;

            while (arr[lastOccur] == X)
            {
                lastOccur++;
            }

            lastOccur--;

            int ans = (lastOccur - firstOccur) + 1;
            return ans;
        }

        else if (arr[mid] < X)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    return 0;
}
