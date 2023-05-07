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

// -------------------------------------------------------------------------------------------------------------------------------------

// Delete middle of the singly linked list / best approach / beats 95%/95%

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        // length
        int len = 0;
        ListNode *current = head;
        while (current != NULL)
        {
            len++;
            current = current->next;
        }

        ListNode *prev = NULL;
        current = head;

        for (int i = 0; i < len / 2; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
        return head;
    }
};

// Delete middle of singly linked list using slow and fast pointers approach

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *prev = NULL;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        return head;
    }
};
