#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

// Convert BST to min heap

void inorderTraversal(BinaryTreeNode *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left, ans);  // left
    ans.push_back(root->data);          // print/store
    inorderTraversal(root->right, ans); // right
}

void BSTtoMinHeap(BinaryTreeNode *&root, vector<int> &inorder, int &index)
{
    if (root == NULL)
    {
        return;
    }

    root->data = inorder[index++];
    BSTtoMinHeap(root->left, inorder, index);
    BSTtoMinHeap(root->right, inorder, index);
}
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    // Step 1: Get inorder of BST
    vector<int> inorder;
    inorderTraversal(root, inorder);

    // Step 2: Preorder traversal
    int index = 0;
    BSTtoMinHeap(root, inorder, index);

    return root;
}