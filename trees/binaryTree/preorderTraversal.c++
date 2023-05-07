#include <bits/stdc++.h>
using namespace std;

// Pre order traversal of binary tree
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

// Using recursion / DFS / 100/81
class Solution
{
    void solve(TreeNode *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        // NLR
        ans.push_back(root->val); // print/store
        solve(root->left, ans);   // left
        solve(root->right, ans);  // right
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Iterative using stack / 100/50
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *temp = root;
        s.push(temp);

        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);

            if (temp->right)
            {
                s.push(temp->right);
            }

            if (temp->left)
            {
                s.push(temp->left);
            }
        }
        return ans;
    }
};