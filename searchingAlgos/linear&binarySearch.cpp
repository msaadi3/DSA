#include <bits/stdc++.h>
using namespace std;

// LINEAR SEARCH

int linearSearch(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

// LINEAR SEARCH USING RECURSION
bool linearSearchRecursive(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }

    if (arr[0] == key)
    {
        return true;
    }

    return linearSearch(arr + 1, size - 1, key);
}

// BINARY SEARCH  / what about if array is sorted in decreasing order not increasing

int binarySearch(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2; // same as below but it makes sure value doesn't go outside range(prevent integer overflow)
    // int mid = (start+end)/2;         // it is fine too but it doesn't prevent from integer overflow if that happens

    while (start <= end)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}

// BINARY SEARCH using recursion
bool binarySearch(int arr[], int start, int end, int key)
{

    // printForBinarySearch(arr, start, end); // in recursion folder
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    cout << " mid: " << arr[mid] << endl;
    // cout << " mid: " << mid << endl;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] > key)
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    return binarySearch(arr, mid + 1, end, key);
}
int main()
{
    return 0;
}