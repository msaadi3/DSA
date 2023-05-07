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

class Solution
{
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int ans = inorder[k - 1];
        return ans;
    }
};

// ----------------------------------

// T.C is O(N) and S.C is O(h) but in worst case(skewed BST) O(N)
class Solution
{
    void inorder(TreeNode *root, int &k, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, k, ans);

        if (--k == 0)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
};
