#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    // Node()
    // {
    //     this->data = 0;
    //     this->left = NULL;
    //     this->right = NULL;
    // }
};

// T.C of insertion in BST is O(logN) as binary search
Node *insertion(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertion(root->right, d);
    }
    else
    {
        root->left = insertion(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data to insert at root node of BST " << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertion(root, data);
        cin >> data;
    }
}

// Minimum value in BST
// T.C is O(h)
Node *mini(Node *root)
{

    Node *temp = root;

    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

// Maximum value in BST
// T.C is O(h)

Node *maxi(Node *root)
{

    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    return 0;
}