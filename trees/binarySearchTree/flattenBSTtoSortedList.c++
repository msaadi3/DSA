#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

// Flatten BST to sorted singly linked list

void inorderTraversal(TreeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);

    TreeNode<int> *newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int> *curr = newRoot;
    int n = inorder.size();

    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorder[i]);
        curr->right = temp;
        curr = temp;
    }
}

// Another approach
//  Failing one test case on coding ninjas i don't know so i leave it
void inorderTraversal(TreeNode<int> *root, TreeNode<int> *&prev)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, prev);

    prev->right = root;
    prev->left = NULL;
    prev = root;

    inorderTraversal(root->right, prev);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return nullptr;
    }

    TreeNode<int> *dummy = new TreeNode<int>(-1);
    TreeNode<int> *prev = dummy;

    inorderTraversal(root, prev);

    prev->right = NULL;
    prev->left = NULL;

    TreeNode<int> *listRoot = dummy->right;

    return listRoot;
}