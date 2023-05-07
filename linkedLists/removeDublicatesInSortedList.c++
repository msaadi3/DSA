#include <bits/stdc++.h>
using namespace std;
// Leet code defination for linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     ListNode *next;
 *     ListNode() : data(0), next(nullptr) {}
 *     ListNode(int x) : data(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : data(x), next(next) {}
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

// ------------------------------------------

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *current = head;
        while (current)
        {
            if (current->next != NULL && current->data == current->next->data)
            {
                ListNode *nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};

// my approach / not the best /  above is much better
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *forward = head->next;

        while (forward != NULL)
        {
            if (prev->data == forward->data)
            {
                ListNode *nodeToDelete = forward;
                forward = forward->next;
                delete nodeToDelete;
                prev->next = forward;
            }
            else
            {
                prev = prev->next;
                forward = forward->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}