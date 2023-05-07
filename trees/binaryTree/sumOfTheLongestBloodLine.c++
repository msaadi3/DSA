#include <bits/stdc++.h>
using namespace std;

// structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
// T.C is O(N) and S.C is O(h) but in worst case is O(N)
class Solution
{
    void solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
    {
        if (root == NULL)
        {
            if (len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen)
            {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum = sum + root->data;

        solve(root->left, len + 1, maxLen, sum, maxSum);
        solve(root->right, len + 1, maxLen, sum, maxSum);
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;

        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};