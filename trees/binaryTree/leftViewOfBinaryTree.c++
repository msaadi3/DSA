#include <bits/stdc++.h>
using namespace std;

// Left view of binary tree

//  A binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to return a list containing elements of left view of the binary tree.
void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    // condition to see if we are at new level ? if yes then store the first value of that level for left view
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}

vector<int> leftView(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
