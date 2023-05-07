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

// Build tree from level order traversal

void build(TreeNode *&root)
{
    queue<TreeNode *> q;
    cout << "enter data for root node";
    int data;
    cin >> data;
    root = new TreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << "enter left node for " << temp->val;
        int left;
        cin >> left;

        if (left != -1)
        {
            temp->left = new TreeNode(left);
            q.push(temp->left);
        }

        cout << "enter right node for " << temp->val;
        int right;
        cin >> right;

        if (right != -1)
        {
            temp->right = new TreeNode(right);
            q.push(temp->left);
        }
    }
}

int main()
{
    TreeNode *root = NULL;
    build(root);
}