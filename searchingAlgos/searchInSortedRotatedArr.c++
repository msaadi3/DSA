#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {

        if (nums[end] < nums[mid])
        {
            start = mid + 1;
        }
        else if (nums[end] > nums[mid])
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    return nums[start];
}

int binarySearch(int arr[], int start, int end, int k)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            return mid;
        }

        if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}

int search(int arr[], int n, int k)
{
    int pivot = findMin(arr, n);
    int ans = -1;
    if ((k >= arr[pivot]) && k <= arr[n - 1])
    {
        ans = binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        ans = binarySearch(arr, 0, pivot - 1, k);
    }
    return ans;
}
int main()

{
    int array[10] = {0, 1, 2, 3, 4, 8, 9, 10, 55, 78};
    // int array[7] = {0, 1, 3, 4, 5, 6, 7};
    // int array[9] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int answer = search(array, 10, 78);
    cout << answer;
    return 0;
}
