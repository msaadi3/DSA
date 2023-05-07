#include <bits/stdc++.h>
using namespace std;
// Vertical order traversal of binary tree using level order traversal
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

// using bfs of level order traversal / 100/87

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, vector<int>>> mapping;
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans;
        }

        // horizontal distance / level
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode *node = temp.first;
            // horizontal distance
            int hd = temp.second.first;
            // level
            int lvl = temp.second.second;

            mapping[hd][lvl].push_back(node->val);

            if (node->left)
            {
                q.push(make_pair(node->left, make_pair(hd - 1, lvl + 1)));
            }
            if (node->right)
            {
                q.push(make_pair(node->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto &col : mapping)
        {
            vector<int> temp;
            for (auto &lvl : col.second)
            {
                sort(lvl.second.begin(), lvl.second.end());
                temp.insert(temp.end(), lvl.second.begin(), lvl.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};