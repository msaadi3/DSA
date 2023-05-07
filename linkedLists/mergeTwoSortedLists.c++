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

// --------------------------------

class Solution
{
    ListNode *solve(ListNode *first, ListNode *second)
    {
        // if only one element
        if (first->next == NULL)
        {
            first->next = second;
            return first;
        }

        ListNode *curr1 = first;
        ListNode *curr2 = second;
        ListNode *next1 = first->next;
        ListNode *next2 = second->next;

        while (next1 != NULL && curr2 != NULL)
        {
            if (curr2->data >= curr1->data && curr2->data <= next1->data)
            {
                // add node in between the first list
                next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;

                // update the pointers
                curr1 = curr2;
                next1 = curr1->next;
                curr2 = next2;
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }

        if (list2 == NULL)
        {
            return list1;
        }

        if (list1->data <= list2->data)
        {
            return solve(list1, list2);
        }
        else
        {
            return solve(list2, list1);
        }
        return list1;
    }
};

int main()
{
    return 0;
}