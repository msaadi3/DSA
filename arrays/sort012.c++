#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
void sort01(int nums[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if ((nums[i] == 1) && (nums[j] == 0) && (i < j))
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        else if (nums[i] == 0 && (i < j))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
*/
// another approach
void sort01(int nums[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        while ((nums[i] == 0) && (i < j))
        {
            i++;
        }

        while ((nums[j] == 1) && (i < j))
        {
            j--;
        }
        if ((nums[i] == 1) && (nums[j] == 0) && (i < j))
        {

            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
}

// another approach

// sort012 / sort colors
// best approach faster than 100% on leetcode

void sort012(int arr[], int n)
{
    int i = 0;
    int m = 0;
    int j = n - 1;
    while (m <= j)
    {
        switch (arr[m])
        {
        case 0:
            swap(arr[i], arr[m]);
            i++;
            m++;
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(arr[j], arr[m]);
            j--;
            break;
        }
    }
}

int main()
{
    // int array[10] = {0, 1, 1, 0, 1, 0, 1, 1, 0, 1};
    // int array[10] = {0, 1, 2, 0, 1, 2, 1, 2, 0, 1};
    // sort01(array, 10);
    // sort012(array, 10);
    // print(array, 10);

    return 0;
}