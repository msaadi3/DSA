#include <bits/stdc++.h>
using namespace std;

// Check if a binary tree is sum tree or not
struct Node
{
    int data;
    Node *left, *right;
};

// T.C is O(N) and S.C is O(height) but in worst case O(N)
class Solution
{
    pair<bool, int> isSum(Node *root)
    {
        // base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // leaf nodes
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> left = isSum(root->left);
        pair<bool, int> right = isSum(root->right);

        bool isLeftSumTree = left.first;
        bool isRightSumTree = right.first;

        int leftSum = left.second;
        int rightSum = right.second;

        bool condn = root->data == leftSum + rightSum;

        pair<bool, int> ans;
        if (isLeftSumTree && isRightSumTree && condn)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return isSum(root).first;
    }
};
