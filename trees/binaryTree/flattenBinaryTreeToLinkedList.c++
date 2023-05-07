#include <bits/stdc++.h>
using namespace std;
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

// Flatten binary tree to linked list using morris traversal
// T.C and S.C is same as morris traversal i.e. O(N) and O(1)

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left)
            {
                // Find the predecessor of current node
                TreeNode *prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL; // point left to NULL
            }
            curr = curr->right;
        }
    }
};

// Iterative approach using stack
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        stack<TreeNode *> s;
        TreeNode *curr = root;
        s.push(curr);

        while (!s.empty())
        {
            curr = s.top();
            s.pop();

            if (curr->right)
            {
                s.push(curr->right);
            }
            if (curr->left)
            {
                s.push(curr->left);
            }

            if (!s.empty())
            {
                curr->right = s.top();
                curr->left = NULL;
            }
        }
    }
};
