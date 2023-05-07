#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Bottom view of binary tree
// same as top view just 1 slight change is at line 40 we are not checking if there exits value for corresponding hd or not
class Solution
{
public:
    vector<int> bottomView(Node *root)
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

            mapping[hd] = node->data;

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
