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

//-------------------------------
// Reverse singly linked list using iteration / best approach / beats 96/98

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *current = head;
        ListNode *forward = NULL;

        while (current != NULL)
        {
            forward = current->next;
            current->next = prev;

            prev = current;
            current = forward;
        }
        return prev;
    }
};

// --------------------------------------------------------------------------------------------------------------------------------------
// Recursive functions to reverse linked list / Didnt get it fully so for later

class Solution
{
public:
    void reverse(ListNode *&head, ListNode *current, ListNode *prev)
    {
        // base case
        if (current == NULL)
        {
            head = prev;
            return;
        }

        ListNode *forward = current->next;
        reverse(head, forward, current);
        current->next = prev;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
        reverse(head, current, prev);
        return head;
    }
};

// same as above but with little tweaks in code / not that efficient but just to understand recursion
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
};

// same as above but with little tweaks in code / not that efficient  but just to understand recursion
class Solution
{
public:
    ListNode *reverse(ListNode *head, ListNode *prev)
    {
        if (!head)
        {
            return prev;
        }

        ListNode *next = head->next;
        head->next = prev;
        return reverse(next, head);
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverse(head, NULL);
    }
};

int main()
{
    return 0;
}