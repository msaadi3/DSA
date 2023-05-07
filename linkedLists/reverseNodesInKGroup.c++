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

// ------------------------------------

class Solution
{
    ListNode *solve(ListNode *&head, int count, int k)
    {
        // base case
        if (head == NULL || count < 0)
        {
            return;
        }

        // Reverse first K nodes
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // Reverse remaining using recursion
        if (next != NULL && count != 0)
        {
            count--;
            head->next = reverseKGroup(next, count, k);
        }
        else
        {
            head->next = next;
        }
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //  To handle the case where the number of nodes is not a multiple of k
        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }

        int count = length / k;
        solve(head, count, k);
        return head;
    }
};

// ----------------------------------

// Coding ninjas && 100/100 on coding ninjas

// Following is the Linked List node structure

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *kReverse(Node *head, int k)
{

    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // Reverse first K nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // Reverse remaining using recursion
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    else
    {
        head->next = next;
    }
    return prev;
}