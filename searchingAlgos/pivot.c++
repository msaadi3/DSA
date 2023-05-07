#include <bits/stdc++.h>
using namespace std;

// ACCEPTED ON LEETCODE / FASTER THAN 100% / BEST SOLUTION SO FAR

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
    // or we can return end, both are correct
}

// LOVE BABBAR SOLUTION BUT NOT ALWAYS CORRECT
// int getPivot(int arr[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     int mid = start + (end - start) / 2;

//     while (start < end)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }

//         mid = start + (end - start) / 2;
//     }
//     return start; // or we can return end, both are same/correct
// }

// ------------------------------------------

// MY BRUTE FORCE APPROACE ACCEPTED ON LEETCODE BUT NOT OPTIMIZED
/*
int findMin(vector<int> &nums)
{
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    if (nums[0] < nums[start])
    {
        return nums[0];
    }
    return nums[start];
    // or we can return end, both are correct
}

*/

int main()
{
    // int array[10] = {0, 1, 2, 3, 4, 8, 9, 10, 55, 78};
    // int array[9] = {8, 9, 0, 1, 3, 4, 5, 6, 7};
    // int ans = findMin(array, 9);
    // cout << ans;
    return 0;
}
