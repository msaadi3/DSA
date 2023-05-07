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

// T.C is O(N) and S.C is O(h) but in worst case O(N)
class Solution
{
    bool isBST(TreeNode *root, long min, long max)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val > min && root->val < max)
        {
            bool left = isBST(root->left, min, root->val);
            bool right = isBST(root->right, root->val, max);
            return left && right;
        }
        else
        {
            return false;
        }
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};

// -----------------

class Solution
{
    bool isBST(TreeNode *root, long min, long max)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val <= min || root->val >= max)
        {
            return false;
        }

        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};