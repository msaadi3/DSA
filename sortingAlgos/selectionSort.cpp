#include <bits/stdc++.h>
using namespace std;

// PRINT
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// INCREASING ORDER

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

// same as above but with a little tweek in code

void selectionSort2(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// -----------------------------------------------------------------------------------------------------------------------------------------

// DECREASING ORDER

// same as above but with decreasing order
void selectionSortDecr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

// same as above but with a little tweek in code
void selectionSortDecr2(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int maxi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxi])
            {
                maxi = j;
            }
        }
        swap(arr[i], arr[maxi]);
    }
}
int main()
{

    int array[5] = {5, 8, 1, 0, 4};
    // selectionSort2(array, 5);
    selectionSortDecr2(array, 5);
    print(array, 5);

    return 0;
}