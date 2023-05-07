#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }

        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// same as above but with little tweaks
class Solution
{
    void solve(TreeNode *&root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return;
        }

        if (root->val < val)
        {
            solve(root->right, val);
        }
        else
        {
            solve(root->left, val);
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        solve(root, val);
        return root;
    }
};

// same as above but with little tweaks / optimized than above
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        if (root->left == NULL && root->right == NULL)
        {
            if (root->val < val)
            {
                root->right = new TreeNode(val);
            }
            else
            {
                root->left = new TreeNode(val);
            }
            return root;
        }

        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// Iterative

class Solution
{

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *curr = root;
        while (true)
        {
            if (curr->val < val)
            {
                if (curr->right)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

// same as above but with litte tweaks
class Solution
{

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *curr = root;
        TreeNode *prev = NULL;

        while (curr != NULL)
        {
            prev = curr;
            if (curr->val < val)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        if (prev->val < val)
        {
            prev->right = new TreeNode(val);
        }
        else
        {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};
