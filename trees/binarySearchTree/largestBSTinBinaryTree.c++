#include <bits/stdc++.h>
using namespace std;

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

// Largest BST in binary tree
// T.C is O(N)
class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

class Solution
{
    info solve(Node *root, int &maxSize)
    {
        if (root == NULL)
        {
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);

        info currentNode;

        currentNode.size = left.size + right.size + 1;
        currentNode.maxi = max(root->data, right.maxi);
        currentNode.mini = min(root->data, left.mini);

        if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini)
        {
            currentNode.isBST = true;
        }
        else
        {
            currentNode.isBST = false;
        }

        if (currentNode.isBST)
        {
            maxSize = max(currentNode.size, maxSize);
        }

        return currentNode;
    }

public:
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int maxSize = 0;
        info ans = solve(root, maxSize);
        return maxSize;
    }
};