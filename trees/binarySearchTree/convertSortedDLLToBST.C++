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

// Count the number of nodes

int countNodes(TreeNode *head)
{
    int count = 0;
    TreeNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }

    return count;
}

// Convert sorted doubly linked list to BST

TreeNode *sortedDLLToBST(TreeNode *head, int nodes)
{
    // base case
    if (nodes <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode *left = sortedDLLToBST(head, nodes / 2);

    TreeNode *root = head;

    root->left = left;

    head = head->right;

    root->right = sortedDLLToBST(head, nodes - nodes / 2 - 1);

    return root;
}
