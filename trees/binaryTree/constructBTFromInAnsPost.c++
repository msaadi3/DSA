#include <bits/stdc++.h>
using namespace std;

// Construct binary tree from inorder and postorder
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

// T.C and S.C is O(N)
class Solution
{

    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &nodeToIndex, int &index,
                    int inorderStart, int inorderEnd, int n)
    {
        if (index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        // Find the position of element in inorder
        int position = nodeToIndex[element];

        // In case of inorder and postorder we first build the right subtree
        root->right = solve(postorder, inorder, nodeToIndex, index, position + 1, inorderEnd, n);
        root->left = solve(postorder, inorder, nodeToIndex, index, inorderStart, position - 1, n);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = postorder.size();
        int postorderIndex = n - 1;
        unordered_map<int, int> nodeToIndex;

        // Mapping of values of inorder to their index
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode *node = solve(postorder, inorder, nodeToIndex, postorderIndex, 0, n - 1, n);
        return node;
    }
};