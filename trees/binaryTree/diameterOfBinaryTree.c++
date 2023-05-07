#include <bits/stdc++.h>
using namespace std;

// Diameter / Width of a binary tree
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

// -----------------------------
// Not the best solution as T.C is O(N2)
// Accepted on GFG but not on leet code may be because of slight difference in problem statment
class Solution
{
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right) + 1; // i just removed this +1 on leet code
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

// Accepted on leet code after a slight change in code
class Solution
{
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);

        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

// -----------------------------------------------

// Accepted on GFG but not on leet code may be because of slight difference in problem statment / just like previous one
class Solution
{
    pair<int, int> diameterUtil(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterUtil(root->left);
        pair<int, int> right = diameterUtil(root->right);

        int op1 = left.first;                     // left subtree diameter
        int op2 = right.first;                    // right subtree diameter
        int op3 = left.second + right.second + 1; // height / just removed this +1 in leet code solution and then it got accepted

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = diameterUtil(root).first;
        return ans;
    }
};

// Accepted on leet code by just sligt change in code / by removing +1 in op3 / height
class Solution
{
    pair<int, int> diameterUtil(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterUtil(root->left);
        pair<int, int> right = diameterUtil(root->right);

        int op1 = left.first;                 // left subtree diameter
        int op2 = right.first;                // right subtree diameter
        int op3 = left.second + right.second; // height

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ans = diameterUtil(root).first;
        return ans;
    }
};

// ----------------------------------------------

class Solution
{
public:
    int height(TreeNode *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = height(root->left, diameter);
        int right = height(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
