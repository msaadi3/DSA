#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ----------------------------------------------------------------------------------------------------------------------------------------

// Convert sorted singly linked list to height balanced BST

class Solution
{
    TreeNode *sortedListToBalancedBST(ListNode *start, ListNode *end)
    {
        if (start == end)
        {
            return NULL;
        }

        ListNode *slow = start;
        ListNode *fast = start;

        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBalancedBST(start, slow);
        root->right = sortedListToBalancedBST(slow->next, end);

        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *end = NULL;
        return sortedListToBalancedBST(head, end);
    }
};

// same as above but with little tweaks

class Solution
{

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return new TreeNode(head->val);
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;

        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = NULL;

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};