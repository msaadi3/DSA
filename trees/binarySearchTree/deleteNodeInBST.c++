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

// Delete a node from BST
// T.C is O(h) but in worst case(skewed BST) O(n)
class Solution
{
    TreeNode *minVal(TreeNode *root)
    {

        TreeNode *temp = root;

        while (temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->val == key)
        {
            // 0 child / leaf node
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // 1 child

            // Left child

            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Right child
            if (root->right != NULL && root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // 2 children
            if (root->left != NULL && root->right != NULL)
            {
                // 2 options either we get the minimum value from right sub-tree or maximum value from left sub-tree and replace it with root->val and then recursive call to delete that node
                int mini = minVal(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }

        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
    }
};