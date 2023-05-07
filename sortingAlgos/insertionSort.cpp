#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n)
{
    int key = 0;
    int j = 0;
    // loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && A[j] > key)
        { // 3, 5, 8, 4, 1
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {3, 9, 55, 90, 1, 0, 32, 45, 88};
    int n = 9;
    cout << "before insertion sort " << endl;
    printArr(A, n);
    insertionSort(A, n);
    cout << " after insertion sort " << endl;
    printArr(A, n);
    return 0;
}