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

// Morris traversal is best and mostly used for inorder and  preorder but not for postorder as it is not efficient for postorder and more complex and not applicable on levelorder
// T.C is O(N) and S.C is O(1) of morris traversal

// Morris traversal for inorder
class Solution
{
public:
    vector<int> morrisTraversal(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Find the predecessor of current node
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------------
// Morris traversal of preorder
// just 1 line of change of inorder / storing value from line 92 to 86
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Find the predecessor of current node
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};