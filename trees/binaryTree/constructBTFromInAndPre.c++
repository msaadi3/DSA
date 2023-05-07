#include <bits/stdc++.h>
using namespace std;
// Construct binary tree from inorder and preorder
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

// Not the best solution as it's T.C is O(n2) because of calling that findPosition function every time
class Solution
{
    int findPosition(vector<int> &inorder, int n, int element)
    {
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index, int inorderStart, int inorderEnd, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = preorder[index++];
        TreeNode *root = new TreeNode(element);
        // Find the position of element in inorder
        int position = findPosition(inorder, n, element);

        // In case of inorder and preorder we first build the left subtree
        root->left = solve(preorder, inorder, index, inorderStart, position - 1, n);
        root->right = solve(preorder, inorder, index, position + 1, inorderEnd, n);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preorderIndex = 0;
        int n = preorder.size();
        TreeNode *node = solve(preorder, inorder, preorderIndex, 0, n - 1, n);
        return node;
    }
};

// -----------------------------------------------------------------------------------------

// same as above just a little change to make it more optimized as T.C is O(N) now because we used unordered_map instead of calling that function every time
class Solution
{

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &nodeToIndex, int &index, int inorderStart,
                    int inorderEnd, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = preorder[index++];
        TreeNode *root = new TreeNode(element);
        // Find the position of element in inorder
        int position = nodeToIndex[element];

        // In case of inorder and preorder we first build the left subtree
        root->left = solve(preorder, inorder, nodeToIndex, index, inorderStart, position - 1, n);
        root->right = solve(preorder, inorder, nodeToIndex, index, position + 1, inorderEnd, n);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preorderIndex = 0;
        int n = preorder.size();
        unordered_map<int, int> nodeToIndex;

        // Mapping of values of inorder to their index
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode *node = solve(preorder, inorder, nodeToIndex, preorderIndex, 0, n - 1, n);
        return node;
    }
};
