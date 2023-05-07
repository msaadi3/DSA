#include <bits/stdc++.h>
using namespace std;

// Reverse / bottom-up level order traversal
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> lvl;

        TreeNode *temp = root;
        q.push(temp);

        while (!q.empty())
        {
            int size = q.size();
            lvl.clear();

            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();
                lvl.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(lvl);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Same as above but with little tweaks in code / not the best one as 5 / 35

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> lvl;

        TreeNode *temp = root;
        q.push(temp);

        while (!q.empty())
        {
            int size = q.size();
            lvl.clear();

            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();
                lvl.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.insert(ans.begin(), lvl);
        }
        return ans;
    }
};

// Same as above but with little tweaks in code / 100/38
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> ans;
        stack<vector<int>> s;
        vector<int> lvl;

        TreeNode *temp = root;
        q.push(temp);

        while (!q.empty())
        {
            int size = q.size();
            lvl.clear();

            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();
                lvl.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            s.push(lvl);
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
