#include <bits/stdc++.h>
using namespace std;

// NOT GOOD / MY BRUTE FORCE APPROACH
/*
void moveZeros(int arr[], int n)
{
    int i = 0;
    int j = 0;

    while (i < n && j < n)
    {
        if (arr[j] != 0 && arr[i] == 0)
        {
            swap(arr[i++], arr[j++]);
        }
        else if (arr[i] != 0)
        {
            i++;
        }
        else if (arr[j] == 0)
        {
            j++;
        }
    }
}

*/

void moveZeroes(int nums[], int n)
{
    int nonZero = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZero]);
            nonZero++;
        }
    }
}

void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
}

int main()
{
    int array[5] = {0, 1, 2, 0, 0};
    moveZeroes(array, 5);
    printArr(array, 5);

    return 0;
}