#include <bits/stdc++.h>
using namespace std;

//  A binary tree node
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

// Flatten binary tree to doubly linked list or to sorted DLL
// it is the same code of to convert BST to sorted DLL, this same code also appiles to convert binary tree to DLL or to sorted DLL
// This function should return head to the DLL
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
        if (root == NULL)
        {
            return root;
        }

        Node *head = NULL;
        BSTtoSortedDLL(root, head);
        return head;
    }
};
