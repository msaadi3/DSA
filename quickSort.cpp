#include <iostream>
using namespace std;

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            // swap A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    // swap A[low]/pivot and A[j]

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {

        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
void print(int A[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << A[i] << endl;
    }
}
int main()
{
    int A[] = {1, 3, 5, 8, 4, 0, 9};
    int n = 7;
    quickSort(A, 0, n - 1);
    print(A, 7);
    return 0;
}