#include <bits/stdc++.h>
using namespace std;

// Determine if two trees are identical / same or not
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

// Using recursion / 100/80
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool value = p->val == q->val;

        if (left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Iterative approach / 100/9

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);

        while (!queue.empty())
        {
            TreeNode *first = queue.front();
            queue.pop();
            TreeNode *second = queue.front();
            queue.pop();

            if (first == NULL && second == NULL)
            {
                continue;
            }

            if ((first == NULL && second != NULL) || (first != NULL && second == NULL) || (first->val != second->val))
            {
                return false;
            }

            queue.push(first->left);
            queue.push(second->left);

            queue.push(first->right);
            queue.push(second->right);
        }

        return true;
    }
};