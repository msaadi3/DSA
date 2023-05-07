#include <bits/stdc++.h>
using namespace std;

// K Sum Path / Path Sum ||
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

    void solve(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL && accumulate(path.begin(), path.end(), 0) == targetSum)
        {
            ans.push_back(path);
        }

        solve(root->left, targetSum, path, ans);
        solve(root->right, targetSum, path, ans);

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, path, ans);
        return ans;
    }
};
