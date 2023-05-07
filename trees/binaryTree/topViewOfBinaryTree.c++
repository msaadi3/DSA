#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Top view of binary tree
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        queue<pair<Node *, int>> q;
        map<int, int> mapping;

        if (root == NULL)
        {
            return ans;
        }

        Node *node = root;
        q.push(make_pair(node, 0));

        while (!q.empty())
        {
            pair<Node *, int> front = q.front();
            q.pop();

            node = front.first;
            int hd = front.second;

            if (mapping.find(hd) == mapping.end())
            {
                mapping[hd] = node->data;
            }

            if (node->left)
            {
                q.push(make_pair(node->left, hd - 1));
            }

            if (node->right)
            {
                q.push(make_pair(node->right, hd + 1));
            }
        }

        for (auto i : mapping)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
