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
// --------------------------------------------------------------------------------------------------------------------------------------------

// MAX HEAP
class maxHeap
{
public:
    int arr[100];
    int size = 0;

    maxHeap(){};

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

// HEAPIFY FOR MAX HEAP

void heapifyForMaxHeap(int array[], int size, int index)
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
        heapifyForMaxHeap(array, size, largest);
    }
}

void heapify(int arr[], int size)
{
    int i = size / 2;
    while (i > 0)
    {

        int leftChild = i * 2;
        int rightChild = (i * 2) + 1;

        if (leftChild <= size && arr[i] < arr[leftChild])
        {
            swap(arr[i], arr[leftChild]);
            i--;
        }
        else if (rightChild <= size && arr[i] < arr[rightChild])
        {
            swap(arr[i], arr[rightChild]);
            i--;
        }
        else
        {
            return;
        }
    }
}

void heapSort(int arr[], int size){
    int s = size;
    while (s > 1)
    {
    
    swap(arr[1],arr[s]);
    s--;

    heapify(arr,s);

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
        heapifyForMaxHeap(arr, n, i);
    }

    // heapify(arr,n);
    heapSort(arr,n);
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}