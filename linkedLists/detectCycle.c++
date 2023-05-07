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

// Not the best solution
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        unordered_map<ListNode *, bool> visited;
        // map<ListNode *, bool> visited;
        ListNode *temp = head;

        while (temp)
        {
            if (visited[temp])
            {
                return true;
            }

            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};

// ---------------------------
// Floyd's cycle detection Algo
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
            {
                fast = fast->next;
            }

            if (slow == fast)
            {
                return true;
                // return slow;
                // return fast;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}