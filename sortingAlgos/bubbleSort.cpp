#include <bits/stdc++.h>
using namespace std;

// bubble sort is a sorting algoritham
// time complexity of bubble sort is O(n2) but for already sorted / adaptive bubble sort algoritham is O(n)
// bubble sort isn't a recursive algoritham
// bubble sort is a stable algoritham because order of same occurance/elements remain same
// bubble sort isn't adaptive algoritham by default but it can be made adaptive that means if array is already sorted it can benefit off of it through some special function/coding and time complexity for already sorted / adaptive bubble sort algoritham is O(n)

void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void bubbleSort(int A[], int n)
{
    // here i is initialized with 0
    for (int i = 0; i < n - 1; i++)
    { // for number of passes
        for (int j = 0; j < n - 1 - i; j++)
        { // for number of comparisons/swaps in each pass
            if (A[j] > A[j + 1])
            {
                int temp;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// same as above but a little tweak in code / here is initialized with 1
void bubbleSort2(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // for number of passes/rounds
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Using recursion
void bubbleSortRecursive(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSortRecursive(arr, n - 1);
}

// FOR ADAPTIVE
void bubbleSortAdaptive(int A[], int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    { // for number of passes
        isSorted = 1;
        cout << "working on pass number " << i + 1 << endl;
        for (int j = 0; j < n - 1 - i; j++)
        { // for number of comparisons/swaps in each pass
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    cout << " array before bubble sort " << endl;
    printArr(A, n);
    cout << " array after bubble sort " << endl;
    bubbleSort(A, n);
    bubbleSortAdaptive(A, n);
    printArr(A, n);
}