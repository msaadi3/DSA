#include <bits/stdc++.h>
using namespace std;

// T.C is O(nlogn) but in worst case O(n2) and S.C is O(n)
// https://www.geeksforgeeks.org/quick-sort/
int partition(int A[], int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= A[pivot])
        {
            i++;
        }

        while (A[j] > A[pivot])
        {
            j--;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
        }

    } while (i < j);

    swap(A[pivot], A[j]);

    return j;
}

void quickSort(int A[], int low, int high)
{

    if (low < high)
    {
        int partitionIndex = partition(A, low, high);

        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
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
    int arr[10] = {3, 77, 0, 2, 1, 54, 98, 22, 89, 57};
    quickSort(arr, 0, 10);
    print(arr, 10);

    return 0;
}