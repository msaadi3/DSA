#include <bits/stdc++.h>
using namespace std;

// It can be done using other DS / ways / approaches but i solved it using heap so i put this question in heap folder
// using max heap
class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // Step 1: max heap for the first k elements
        priority_queue<int> maxHeap;
        for (int i = 0; i < k; i++)
        {
            maxHeap.push(arr[i]);
        }

        // Step 2: Compare remaining elements in the array with the top of max heap if the element in the array is less than the top of max heap then we pop that top element of max heap and push it into the max heap
        for (int i = k; i <= r; i++)
        {
            if (arr[i] < maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        // Now max heap contains only first k elements of array and the top would be kth smallest element
        return maxHeap.top();
    }
};