#include <bits/stdc++.h>
using namespace std;
// Leet code defination for linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
    }
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// -----------------------------

// Return the begining / first node of the loop/cycle
class Solution
{
    ListNode *floydCycleDetection(ListNode *slow, ListNode *fast)
    {

        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
            {
                fast = fast->next;
            }

            if (slow == fast)
            {
                return fast;
            }
        }
        return NULL;
    }

public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        ListNode *intersection = floydCycleDetection(slow, fast);
        if (intersection != NULL)
        {
            while (slow != intersection)
            {
                slow = slow->next;
                intersection = intersection->next;
            }
            return slow;
        }
        return NULL;
    }
};
int main()
{
    return 0;
}