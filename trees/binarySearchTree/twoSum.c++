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

// T.C and S.C is O(N)
class Solution
{
    void inorderTraversal(TreeNode *root, int k, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left, k, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, k, inorder);
    }

    bool twoSum(vector<int> &inorder, int k)
    {
        int i = 0;
        int j = inorder.size() - 1;

        while (i < j)
        {
            if (inorder[i] + inorder[j] == k)
            {
                return true;
            }
            else if (inorder[i] + inorder[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, k, inorder);
        return twoSum(inorder, k);
    }
};