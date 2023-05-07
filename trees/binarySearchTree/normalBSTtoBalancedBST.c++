#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Convert normal BST to Balanced / height balanced BST

class Solution
{
    TreeNode *inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return NULL;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    TreeNode *BST(vector<int> &inorder, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }
        int mid = (s + e) / 2;

        TreeNode *root = new TreeNode(inorder[mid]);

        root->left = BST(inorder, s, mid - 1);
        root->right = BST(inorder, mid + 1, e);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        return BST(inorder, 0, inorder.size() - 1);
    }
};