#include <bits/stdc++.h>
using namespace std;

// Right view of binary tree
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

// Using recursion
class Solution
{
    void solve(TreeNode *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
        {
            return;
        }

        // condition to see if we are at new level ? if yes then store the first value of that level for right view
        if (lvl == ans.size())
        {
            ans.push_back(root->val);
        }

        solve(root->right, ans, lvl + 1);
        solve(root->left, ans, lvl + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {

        if (root == NULL)
        {
            return {};
        }

        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};