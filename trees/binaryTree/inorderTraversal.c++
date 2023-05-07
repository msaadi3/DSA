#include <bits/stdc++.h>
using namespace std;

// Inorder traversal of a binary tree
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

// ----------------------------------------------------------------------------------------------------------------------------------------
// Using recursion / DFS
class Solution
{
    void solve(TreeNode *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        // LNR
        solve(root->left, ans);   // left
        ans.push_back(root->val); // print/store
        solve(root->right, ans);  // right
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Iterative using stack  / 100/45

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *temp = root;

        while (temp || !s.empty())
        {
            if (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                temp = temp->right;
            }
        }

        return ans;
    }
};
