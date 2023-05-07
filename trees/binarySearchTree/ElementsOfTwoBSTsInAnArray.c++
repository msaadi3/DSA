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

// 1305. All Elements in Two Binary Search Trees
class Solution
{
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    vector<int> mergeArrays(vector<int> &first, vector<int> &second)
    {
        vector<int> merge(first.size() + second.size());
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < first.size() && j < second.size())
        {
            if (first[i] < second[j])
            {
                merge[k++] = first[i++];
            }
            else
            {
                merge[k++] = second[j++];
            }
        }

        while (i < first.size())
        {
            merge[k++] = first[i++];
        }

        while (j < second.size())
        {
            merge[k++] = second[j++];
        }
        return merge;
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return {};
        }

        vector<int> tree1;
        vector<int> tree2;
        inorderTraversal(root1, tree1);
        inorderTraversal(root2, tree2);

        return mergeArrays(tree1, tree2);
    }
};

// -------------------------------------------------------

class Solution
{
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return {};
        }

        vector<int> ans;
        inorderTraversal(root1, ans);
        inorderTraversal(root2, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};