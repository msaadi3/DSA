#include <bits/stdc++.h>
using namespace std;

// coding ninjas
// T.C is O(nlogn)
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callMedian(priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median, int element)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    // both heaps have n size (even and same)
    case 0:
        if (element > median)
        {
            minHeap.push(element);
            // after inserting new element in min heap, the size of max heap is n(even) and the size of min heap is n+1(odd) so in this
            // case answer would be min heap top
            median = minHeap.top();
        }
        else
        {
            // opposite of above
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    // max heap is even and min heap is odd (n, n-1)
    case 1:
        if (element > median)
        {
            minHeap.push(element);
            // now both are even after inserting new element (n,n)
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            // in this case we have to insert in max heap but max heap is already even (n) so it will create the difference of two
            // so before inserting in maxheap first we will push max heap top in min heap and then push new element in max heap and
            // then the size of both heaps becomes even (n,n) and we know how to find median in this case
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            // now both are even (n,n)
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
        // max heap is odd and min heap is even (n-1, n)
        // case -1 is opposite of case 1. i think so not sure
    case -1:
        if (element > median)
        {
            // in this case we have to insert in min heap but min heap is already even (n) so it will create the difference of two
            // so before inserting in min heap first we will push min heap top in max heap and then push new element in min heap and
            // then the size of both heaps becomes even (n,n) and we know how to find median in this case
            maxHeap.push(minHeap.top());
            minHeap.pop();

            minHeap.push(element);
            // now both are even (n,n)
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        break;
    }
}
vector<int> findMedian(vector<int> &arr, int n)
{

    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = -1;

    for (int i = 0; i < n; i++)
    {
        callMedian(maxHeap, minHeap, median, arr[i]);
        ans.push_back(median);
    }

    return ans;
}

// Leet code

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size() && maxHeap.size() != 0)
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }

        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */