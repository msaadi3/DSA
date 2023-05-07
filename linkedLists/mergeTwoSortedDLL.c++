#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

// Merge two sorted doubly linked lists

TreeNode *mergeTwoSortedDLL(TreeNode *head1, TreeNode *head2)
{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
