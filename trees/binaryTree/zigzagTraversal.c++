#include <bits/stdc++.h>
using namespace std;

// zigzag / spiral traversal
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

// Using BFS of level order traversal / 100/50
// T.C is O(N) cuz we are visiting every node for once and S.C in worst case is O(N)
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<TreeNode *> q;
        vector<vector<int>> ans;

        TreeNode *temp = root;
        q.push(temp);

        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> lvl(size);

            // Process level
            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();

                // Normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                lvl[index] = temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            // Change direction and store the answer of the current level
            leftToRight = !leftToRight;
            ans.push_back(lvl);
        }
        return ans;
    }
};