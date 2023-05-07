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

// Detect and remove loop by pointing the node to null

ListNode *floydCycleDetection(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return fast;
        }
    }
    return NULL;
}

ListNode *beginingOfTheLoop(ListNode *head)
{
    ListNode *intersection = floydCycleDetection(head);

    if (intersection != NULL)
    {
        ListNode *slow = head;
        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    return NULL;
}

ListNode *removeLoop(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    ListNode *startingNode = beginingOfTheLoop(head);
    if (startingNode != NULL)
    {
        ListNode *slow = startingNode;
        while (slow->next != startingNode)
        {
            slow = slow->next;
        }

        slow->next = NULL;
    }
    return head;
}

int main()
{
    return 0;
}