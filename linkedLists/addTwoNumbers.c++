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

// -------------------------------------------------------------------------------------------------------------------------------------------
// Leetcode : Add Two Numbers II

class Solution
{
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
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

    void insertAtTail(ListNode *&ansHead, ListNode *&ansTail, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
            return;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }

    ListNode *add(ListNode *first, ListNode *second)
    {
        int carry = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;

        while (first != NULL && second != NULL)
        {
            int sum = carry + first->data + second->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
            second = second->next;
        }

        while (first != NULL)
        {
            int sum = carry + first->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
        }

        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            second = second->next;
        }

        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }
        return ansHead;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // step 1: reverse both lists
        ListNode *first = reverse(l1);
        ListNode *second = reverse(l2);

        // step 2: add
        ListNode *ans = add(first, second);

        // step 3: reverse the ans
        ans = reverse(ans);
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------

// Same as above but more optimized add function

class Solution
{
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
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

    void insertAtTail(ListNode *&ansHead, ListNode *&ansTail, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
            return;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }

    ListNode *add(ListNode *first, ListNode *second)
    {
        int carry = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }

            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if (first != NULL)
            {
                first = first->next;
            }

            if (second != NULL)
            {
                second = second->next;
            }
        }

        return ansHead;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // step 1: reverse both lists
        ListNode *first = reverse(l1);
        ListNode *second = reverse(l2);

        // step 2: add
        ListNode *ans = add(first, second);

        // step 3: reverse the ans;
        ans = reverse(ans);
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------

// Leetcode : Add Two Numbers / Little difference in problem statment from above

class Solution
{

    void insertAtTail(ListNode *&ansHead, ListNode *&ansTail, int val)
    {
        ListNode *newNode = new ListNode(val);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
            return;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }

    ListNode *add(ListNode *first, ListNode *second)
    {
        int carry = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }

            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if (first != NULL)
            {
                first = first->next;
            }

            if (second != NULL)
            {
                second = second->next;
            }
        }

        return ansHead;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = add(l1, l2);

        return ans;
    }
};