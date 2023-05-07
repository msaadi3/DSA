#include <bits/stdc++.h>
using namespace std;

// GFG
//  BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
    {
        return;
    }

    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            break;
        }
        else if (temp->key > key)
        {
            suc = temp;
            temp = temp->left;
        }
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        return;
    }

    // Find predecessor
    if (temp->left)
    {
        Node *tempPre = temp->left;
        while (tempPre != NULL)
        {
            pre = tempPre;
            tempPre = tempPre->right;
        }
    }

    // Find successor
    if (temp->right)
    {
        Node *tempSuc = temp->right;
        while (tempSuc != NULL)
        {
            suc = tempSuc;
            tempSuc = tempSuc->left;
        }
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------

// Coding ninjas
// Following is the Binary Tree node structure:

class binaryTreeNode
{

public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    binaryTreeNode *curr = root;
    int pred = -1;
    int succ = -1;
    while (curr->data != key)
    {
        if (curr->data < key)
        {
            pred = curr->data;
            curr = curr->right;
        }
        else
        {
            succ = curr->data;
            curr = curr->left;
        }
    }

    // Predecessor
    binaryTreeNode *temp = curr->left;
    while (temp != NULL)
    {
        pred = temp->data;
        temp = temp->right;
    }

    // Successor
    temp = curr->right;
    while (temp != NULL)
    {
        succ = temp->data;
        temp = temp->left;
    }

    vector<int> ans;
    ans.push_back(pred);
    ans.push_back(succ);
    return ans;
}