#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Convert BST to sorted doubly linked list
// This function should return head to the DLL
class Solution
{

    void BSTtoSortedDLL(Node *root, Node *&head)
    {
        if (root == NULL)
        {
            return;
        }

        BSTtoSortedDLL(root->right, head);

        root->right = head;

        if (head != NULL)
        {
            head->left = root;
        }

        head = root;

        BSTtoSortedDLL(root->left, head);
    }

public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        Node *head = NULL;
        BSTtoSortedDLL(root, head);
        return head;
    }
};
