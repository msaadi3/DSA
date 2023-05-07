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

// -------------------------------------------------

// Check if the singly linked list is palindrome or not

// Not the best solutionn
class Solution
{
    bool palindrome(vector<int> &temp)
    {
        int i = 0;
        int j = temp.size() - 1;
        while (i < j)
        {
            if (temp[i] != temp[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> temp;
        ListNode *p = head;
        while (p != NULL)
        {
            temp.push_back(p->data);
            p = p->next;
        }
        return palindrome(temp);
    }
};
// ---------------------------
// Not the best solution
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<ListNode *> nodeStack;
        ListNode *temp = head;

        while (temp)
        {
            nodeStack.push(temp);
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            if (temp->data != nodeStack.top()->data)
            {
                return false;
            }
            nodeStack.pop();
            temp = temp->next;
        }
        return true;
    }
};

// ---------------------------------
// not the best solution
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        string s;
        ListNode *temp = head;

        while (temp)
        {
            s += temp->data;
            temp = temp->next;
        }

        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
};
// ------------------------------

// optimized than previous
class Solution
{

    ListNode *middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool palindrome(ListNode *head1, ListNode *head2)
    {
        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        // step 1: get mid
        ListNode *mid = middle(head);

        // step 2: reverse the list after mid and attach mid->next to the reversed list
        ListNode *temp = mid->next;
        mid->next = reverse(temp);

        // step 3: Compare both halves
        ListNode *head1 = head;
        ListNode *head2 = mid->next;
        return palindrome(head1, head2);

        // step 4/optional : make the list as it was by reversing the second half again
        // mid->next = reverse(head2);
    }
};

int main()
{
    return 0;
}
