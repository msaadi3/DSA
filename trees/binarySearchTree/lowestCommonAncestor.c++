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

// Find lowest common ancestor of two nodes in BST
// Recursive approach
// T.C is O(N) and S.C is O(h) but in worst case O(N)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};

// Iterative approach
// T.C is O(h) but in balanced BST O(logN) and in worst case(skewed BST) O(N) and S.C is O(1)
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        while (root != NULL)
        {
            if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};