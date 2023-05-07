#include <bits/stdc++.h>
using namespace std;

// T.C is O(nlogn) and S.C is O(n)
// https://www.geeksforgeeks.org/merge-sort/
void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        // recursive calls
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{

    int arr[10] = {3, 5, 7, 8, 9, 33, 88, 2, 4, 1};
    mergeSort(arr, 0, 10);
    print(arr, 10);

    return 0;
}