#include <bits/stdc++.h>
using namespace std;

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

// Recursive approach / DFS
class Solution
{
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);
        int nodes = left + right + 1;
        return nodes;
    }

    bool isCBT(TreeNode *root, int index, int totalNodes)
    {
        if (root == NULL)
        {
            return true;
        }

        if (index >= totalNodes)
        {
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, totalNodes);
            bool right = isCBT(root->right, 2 * index + 2, totalNodes);
            return left && right;
        }
    }

public:
    bool isCompleteTree(TreeNode *root)
    {
        int nodes = countNodes(root);
        return isCBT(root, 0, nodes);
    }
};

// Iterative approach / BFS / Using queue
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool seeNULL = false;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front == NULL)
            {
                seeNULL = true;
            }
            else
            {
                if (seeNULL)
                {
                    return false;
                }

                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};