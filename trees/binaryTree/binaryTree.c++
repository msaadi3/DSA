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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildTree(Node *root)
{

    cout << " enter data " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << " enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << " enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}