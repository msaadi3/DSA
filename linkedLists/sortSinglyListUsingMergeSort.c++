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

// -------------------------------------
// Sort singly linked list using merge sort
// best one with 98/98

class Solution
{
    ListNode *merge(ListNode *&first, ListNode *&second)
    {
        // if only one element in first list
        if (first->next == NULL)
        {
            first->next = second;
            return first;
        }

        ListNode *curr1 = first;
        ListNode *curr2 = second;
        ListNode *next1 = curr1->next;
        ListNode *next2 = curr2->next;

        // Merge two sorted linked lists
        while (curr1->next != NULL && curr2 != NULL)
        {
            if (curr2->data >= curr1->data && curr2->data <= next1->data)
            {
                next1 = curr1->next;
                next2 = curr2->next;

                curr1->next = curr2;
                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                curr1 = curr1->next;
                next1 = curr1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }

    ListNode *findMid(ListNode *head)
    {
        // tortoise and hear approach
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Find mid of the linked list and break it into two halves
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        // recursive calls
        left = sortList(left);
        right = sortList(right);

        // merge
        ListNode *result = NULL;
        if (left->data <= right->data)
        {
            result = merge(left, right);
        }
        else
        {
            result = merge(right, left);
        }
        return result;
    }
};
