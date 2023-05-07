#include <bits/stdc++.h>
using namespace std;

/*
vector<int> searchRange(vector<int> &nums, int target)
{
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    vector<int> ans;
    int temp = -1;

    // first occurance
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            temp = mid;
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

    ans.push_back(temp);

    // last occurance

    start = 0;
    end = size - 1;
    mid = start + (end - start) / 2;
    temp = -1;
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            temp = mid;
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

    ans.push_back(temp);

    return ans;
}
*/

int firstOccurance(int nums[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (nums[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurance(int array[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (array[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (array[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    int arr[10] = {2, 5, 55, 5, 5, 5, 5, 5, 1, 4};
    cout << " first ocurance of given element is : " << firstOccurance(arr, 10, 5) << endl;
    cout << " last ocurance of given element is : " << lastOccurance(arr, 10, 5) << endl;

    return 0;
}
