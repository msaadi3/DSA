#include <bits/stdc++.h>
using namespace std;

// Merge k sorted singly linked lists
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

// Using min heap
// T.C is O(n*k log k) and S.C is O(k) where n is the number of nodes in a singly linked list and k is the number of linked lists
class Solution
{

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        int k = lists.size();

        if (k == 0)
        {
            return NULL;
        }

        // push every linked list's head / first node in min heap
        // T.C of this loop is O(klogk)
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (minHeap.size() > 0)
        {
            ListNode *top = minHeap.top();
            minHeap.pop();

            if (top->next != NULL)
            {
                minHeap.push(top->next);
            }

            // first node
            if (head == NULL)
            {
                head = tail = top;
            }
            else
            {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};