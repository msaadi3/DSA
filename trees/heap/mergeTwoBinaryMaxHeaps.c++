#include <bits/stdc++.h>
using namespace std;

// Merge two binary Max heaps
class Solution
{
    // heapify algo for max heap
    void heapifyForMaxHeap(vector<int> &array, int size, int index)
    {
        int largest = index;
        // For 0 based indexing
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

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

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // Step 1: merge two binary max heaps / given arrays into single array irrespective of order/sort
        vector<int> maxHeap(a);
        for (auto i : b)
        {
            maxHeap.push_back(i);
        }

        // build heap using maxHeap array
        // This for loop applies only on 0 based indexing
        int size = maxHeap.size();
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyForMaxHeap(maxHeap, size, i);
        }

        return maxHeap;
    }
};