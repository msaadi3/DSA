#include <iostream>
using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------------------
//                   root at 0       root at 1
// Left child        index*2 + 1     index*2
// Right child       index*2 + 2     index*2 + 1
// Parent            (index-1)/2     index/2

// For a more general case where it may not be a binary heap, but a 3-heap, 4-heap, etc where there are NUM_CHILDREN children for each node instead of 2 the formulas are:

//                   root at 0                  root at 1
// Left child        index*NUM_CHILDREN + 1     index*NUM_CHILDREN
// Right child       index* NUM_CHILDREN + 2    index*NUM_CHILDREN + 1
// Parent            (index-1)/NUM_CHILDREN     index/NUM_CHILDREN

// (n/2 + 1) to n are leaf nodes in complete binary tree/heap where is the no. of nodes in tree

// Loop for 0 based indexing to build the heap using heapify algoritham
// int n; // size of array
// for (int i = n / 2 - 1; i >= 0; i--); // these are basically non-leaf nodes

// Loop for 1 based indexing to build the heap using heapify algoritham
// int n; // size of array
// for (int i = n / 2 ; i > 0; i--); // these are basically non-leaf nodes

// --------------------------------------------------------------------------------------------------------------------------------------------

// STL of heap is priority_queue by including queue header file and by default it is max heap

// MAX HEAP
class maxHeap
{
public:
    int arr[100];
    int size;

    maxHeap()
    {
        size = 0;
        arr[0] = -1;
    };

    // T.C of insertion is O(logN)
    void maxHeapInsert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        int parent = index / 2;

        while (index > 1)
        {
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // T.C of deletion in heap is O(logN)
    void maxHeapDeletion()
    {
        if (size == 0)
        {
            cout << "nothing to delete";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftChild = i * 2;
            int rightChild = (i * 2) + 1;

            if (arr[i] < size && arr[i] < leftChild)
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (arr[i] < size && arr[i] < rightChild)
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }

    void displayMaxHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify Algo
// HEAPIFY FOR MAX HEAP
// T.C of heapify algorithm is O(logN) but to build heap using heapify is O(N) ? research on it / didn't get it

void heapify(int array[], int size, int index)
{
    int largest = index;
    int leftChild = (index * 2) + 1;
    int rightChild = (index * 2) + 2;

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

// Heap sort algorithm to sort the array
// T.C of heap sort is O(nlogN)
// If we are given an array to sort using heap sort first we have to build the heap using heapify algo then we call heap sort on heap to sort the array

void heapSort(int arr[], int size)
{
    int s = size;
    while (s > 1)
    {

        swap(arr[1], arr[s]);
        s--;

        heapify(arr, s, 1);
    }
}
// MIN HEAP

class minHeap
{
public:
    int arr[100];
    int size = 0;

    minHeap(){};

    void minHeapInsert(int val)
    {
        int index = size;
        arr[index] = val;
        size++;

        int parent = (index - 1) / 2;

        while (index > 0)
        {
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void minHeapDeletion()
    {
        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (i < size - 1)
        {
            int leftChild = (i * 2) + 1;
            int rightChild = (i * 2) + 2;

            if (arr[i] < size - 1 && arr[i] > leftChild)
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (arr[i] < size - 1 && arr[i] > rightChild)
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }

    void displayMinHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    // maxHeap m;
    // m.maxHeapInsert(5);
    // m.maxHeapInsert(99);
    // m.maxHeapInsert(19);
    // m.displayMaxHeap();
    // m.maxHeapDeletion();
    // m.displayMaxHeap();

    // minHeap h;
    // h.minHeapInsert(5);
    // h.minHeapInsert(99);
    // h.minHeapInsert(19);
    // h.displayMinHeap();
    // h.minHeapDeletion();
    // h.displayMinHeap();

    // HEAPIFY FOR MAX HEAP

    int arr[8] = {9, 3, 7, 0, 55, 33, 77};
    int n = 7;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    // heapify(arr,n);
    heapSort(arr, n);
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}