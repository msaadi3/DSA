#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// Kth ancestor of a node in a binary tree
// T.C is O(N) and S.C is O(h) but in worst case is O(N)
// ----------------------

Node *solve(Node *root, int node, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *left = solve(root->left, node, k);
    Node *right = solve(root->right, node, k);

    if (left == NULL && right != NULL)
    {
        k--;
        if (k == 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return right;
    }

    if (left != NULL && right == NULL)
    {
        k--;
        if (k == 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return left;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{

    Node *ans = solve(root, node, k);

    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}
