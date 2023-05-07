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

// Lowest common ancestor of binary tree using recursion
// T.C is O(N) ans S.C is O(h) but in worst case is O(N)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL)
        {
            return root;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else if (left == NULL && right != NULL)
        {
            return right;
        }
        else
        {
            return NULL;
        }
    }
};