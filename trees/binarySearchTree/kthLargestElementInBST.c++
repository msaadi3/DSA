#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// --------------------------------------
class Solution
{
    void inorder(Node *root, vector<int> &in)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

public:
    int kthLargest(Node *root, int K)
    {
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        return in[n - K];
    }
};

// Using reverse inorder
class Solution
{
    // Reverse inorder / Modified the inorder traversal to visit the right subtree / largest elements first and then left subtree
    void inorder(Node *root, int &K, int &i, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->right, K, i, ans);

        if (++i == K)
        {
            ans = root->data;
            return;
        }

        inorder(root->left, K, i, ans);
    }

public:
    int kthLargest(Node *root, int K)
    {
        int i = 0;
        int ans = -1;
        inorder(root, K, i, ans);
        return ans;
    }
};