#include <bits/stdc++.h>
using namespace std;

// Smallest Range From K Sorted List
// Not accepted on leet code but accepted on GFG and coding ninjas
// Node class
class Node
{
public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
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

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // Create a min heap for starting elements of each list while tracking max and min values
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // process ranges till heap is not empty or list doesn't get exhausted
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // update range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // if next element exits then update maxi and push it in heap
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }

    // returning the range difference
    return (end - start) + 1;

    // GFG
    // pair<int, int> ans;
    // ans.first = end;
    // ans.second = start;
    // return ans;
}
