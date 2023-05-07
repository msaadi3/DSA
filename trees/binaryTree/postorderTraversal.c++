#include <bits/stdc++.h>
using namespace std;

// Post order traversal of binary tree
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

// Using recursion / DFS / 100/45

class Solution
{
    void solve(TreeNode *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        // LRN
        solve(root->left, ans);   // Left
        solve(root->right, ans);  // Right
        ans.push_back(root->val); // print/store
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Iterative using two stacks / Not that good
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<int> ans;
        stack<TreeNode *> s1, s2;
        TreeNode *temp = root;
        s1.push(temp);

        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left)
            {
                s1.push(temp->left);
            }

            if (temp->right)
            {
                s1.push(temp->right);
            }
        }

        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};

// Iterative Using single stack and reverse / 100/72
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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

            if (temp->left)
            {
                s.push(temp->left);
            }

            if (temp->right)
            {
                s.push(temp->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
