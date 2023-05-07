#include <bits/stdc++.h>
using namespace std;

// reverse the array

void reverseArr(int arr[], int n)
{
    int last = n - 1;
    int i = 0;
    while (i <= last)
    {
        swap(arr[i], arr[last]);
        last--;
        i++;
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
    int array[5] = {1, 2, 3, 4, 5};
    reverseArr(array, 5);
    printArr(array, 5);
    return 0;
}