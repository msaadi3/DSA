#include <bits/stdc++.h>
using namespace std;

// Structure of node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Check if a given Binary Tree is a Heap
// T.C and S.C is O(N)
class Solution
{
    int countNodes(struct Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);
        int nodes = left + right + 1;
        return nodes;
    }

    bool isCBT(struct Node *root, int index, int totalNodes)
    {
        if (root == NULL)
        {
            return true;
        }

        if (index >= totalNodes)
        {
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, totalNodes);
            bool right = isCBT(root->right, 2 * index + 2, totalNodes);
            return left && right;
        }
    }

    bool isMaxHeap(struct Node *root)
    {
        // Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        if (root->right == NULL)
        {
            return root->data > root->left->data;
        }
        else
        {
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);

            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        int nodes = countNodes(tree);

        if (isCBT(tree, 0, nodes) && isMaxHeap(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};