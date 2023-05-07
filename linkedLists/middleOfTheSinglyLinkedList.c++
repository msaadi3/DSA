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

// ------------------------------------------------------------------------
// Find the middle node of the singly linked list
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        if (head->next->next == NULL)
        {
            return head->next;
        }

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
};

// Another one
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Length of linked list
        ListNode *temp = head;
        int len = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        temp = head;
        int mid = len / 2;
        int cnt = 0;
        while (cnt < mid)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};

int main()
{
    return 0;
}