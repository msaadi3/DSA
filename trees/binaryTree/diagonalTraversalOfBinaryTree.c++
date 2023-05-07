#include <bits/stdc++.h>
using namespace std;
// Diagonal traverse of binary tree
//  A binary tree node
struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    queue<Node *> q;
    vector<int> ans;

    if (root == NULL)
    {
        return {};
    }

    Node *node = root;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        while (node)
        {
            if (node->left)
            {
                q.push(node->left);
            }

            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}