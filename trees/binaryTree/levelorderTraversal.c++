#include <bits/stdc++.h>
using namespace std;

// Level order traversal of binary tree
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

// -------------------------------------------------------------------------------------------------------------------------------

// level order traversal / bfs

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> tempAns;

        if (root == NULL)
        {
            return ans;
        }

        // Inserting the first node and seperator(NULL) because first level is completed
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                ans.push_back(tempAns);
                tempAns.resize(0);

                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {

                tempAns.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};

// Same as above but with little tweaks
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> lvlAns;

        q.push(root);

        while (!q.empty())
        {
            lvlAns.clear();
            int count = q.size();

            for (int i = 0; i < count; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }

                lvlAns.push_back(temp->val);
            }
            ans.push_back(lvlAns);
        }
        return ans;
    }
};

// Using Recursion / DFS / Not the best solution as 38/11

class Solution
{
    void solve(TreeNode *root, vector<vector<int>> &ans, int lvl)
    {
        if (root == NULL)
        {
            return;
        }

        if (ans.size() == lvl)
        {
            ans.push_back({});
        }

        ans[lvl].push_back(root->val);
        solve(root->left, ans, lvl + 1);
        solve(root->right, ans, lvl + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        solve(root, ans, 0);
        return ans;
    }
};