#include <bits/stdc++.h>
using namespace std;

// Merge K sorted arrays
// T.C is O(n*klogk) and S.C is O(k) excluding of ans vector and including that ans vector then S.C O(n*k) where n is the size of array and k is the number of arrays

class Node
{
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Custom comparator
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        // Insert first element of every array in min heap
        // T.C of this loop and insertion in heap is O(klogk)
        for (int i = 0; i < K; i++)
        {
            Node *temp = new Node(arr[i][0], i, 0);
            minHeap.push(temp);
        }

        vector<int> ans;

        while (!minHeap.empty())
        {
            // Fetch min heap top and push it's value in ans vector
            Node *temp = minHeap.top();
            minHeap.pop();
            ans.push_back(temp->data);

            // Now look for next element in the same array if it exists then make a new node of next element and push it into min heap
            int row = temp->row;
            int col = temp->col;

            if (col + 1 < arr[row].size())
            {
                Node *next = new Node(arr[row][col + 1], row, col + 1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};