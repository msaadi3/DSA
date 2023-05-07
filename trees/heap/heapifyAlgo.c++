#include <bits/stdc++.h>
using namespace std;

// HEAPIFY ALGORITHM
// T.C of heapify algorithm is O(logN) but to build heap using heapify is O(N) ? research on it / didn't get it

// Heapify algorithm for max heap and for min heap exactly the same just operators will be changed (< >)
void heapify(int array[], int size, int index)
{
    int largest = index;
    // for 0 based indexing
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;

    if (leftChild < size && array[largest] < array[leftChild])
    {
        largest = leftChild;
    }

    if (rightChild < size && array[largest] < array[rightChild])
    {
        largest = rightChild;
    }

    if (largest != index)
    {
        swap(array[largest], array[index]);
        heapify(array, size, largest);
    }
}

int main()
{
    // Loop for 0 based indexing to build the heap using heapify
    int n;                               // size of array
    for (int i = n / 2 - 1; i >= 0; i--) // these are basically non-leaf nodes
    {
        /* code */
    }

    // Loop for 1 based indexing to build the heap using heapify
    int n;                          // size of array
    for (int i = n / 2; i > 0; i--) // these are basically non-leaf nodes
    {
        /* code */
    }

    return 0;
}