#include <bits/stdc++.h>
using namespace std;

// Node Structure

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Maximum sum of non-adjacent nodes in a binary tree
// T.C is O(N) and S.C is O(h) but in worst case(skewed tree) O(N)
class Solution
{

    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;
        res.first = root->data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        return res;
    }

public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
