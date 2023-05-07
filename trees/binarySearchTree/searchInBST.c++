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

// Search a node/key in BST
// Recursive approach
// T.C and S.C is O(h) / O(logN) but in worst case(skewed binary tree) O(N)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == val)
        {
            return root;
        }

        if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return searchBST(root->left, val);
        }
    }
};

// Iterative approach
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *temp = root;

        while (temp != NULL)
        {
            if (temp->val == val)
            {
                return temp;
            }

            if (temp->val < val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return NULL;
    }
};