#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
    // Traverse left boundary except of leaf nodes cuz leaf nodes will be traversed seperately
    void traverseLeft(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        ans.push_back(root->data);

        if (root->left)
        {
            traverseLeft(root->left, ans);
        }
        else
        {
            traverseLeft(root->right, ans);
        }
    }

    // Traverse leaf nodes using inorder traversal
    void traverseLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        // leaf node
        if (root->right == NULL && root->left == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // Traverse right boundary in reverse order except of leaf node cuz leaf node has been traversed in leaf traversal
    void traverseRight(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->right)
        {
            traverseRight(root->right, ans);
        }
        else
        {
            traverseRight(root->left, ans);
        }

        ans.push_back(root->data);
    }

public:
    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        // Store/print root node first
        ans.push_back(root->data);

        // Traverse left
        traverseLeft(root->left, ans);

        // Traverse leaf nodes

        // leaf node in left sub tree
        traverseLeaf(root->left, ans);

        // leaf node in right sub tree
        traverseLeaf(root->right, ans);

        // Traverse right
        traverseRight(root->right, ans);
        return ans;
    }
};