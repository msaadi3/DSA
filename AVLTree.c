#include <stdio.h>
#include <stdlib.h>

// HAVE TO LOOK AT IT AGAIN, COME BACK STRONGER!

struct AVLTree
{
    int data;
    struct AVLTree *left;
    struct AVLTree *right;
    int height;
};

struct AVLTree *createAVLTree(int x)
{
    struct AVLTree *newNode = (struct AVLTree *)malloc(sizeof(struct AVLTree));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

void preOrder(struct AVLTree *root)
{ // ROOT -> LEFT -> RIGHT
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct AVLTree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// BALANCE FACTOR
int balanceFactor(struct AVLTree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// LEFT ROTATION WHEN RIGHT RIGHT / RR INSERTION
struct AVLTree *leftRotate(struct AVLTree *x)
{
    struct AVLTree *y = x->right;
    struct AVLTree *T2 = y->left;

    // LEFT ROTATION
    y->left = x;
    x->right = T2;

    // UPDATE HEIGHTS
    x->height = maximum(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = maximum(getHeight(y->right), getHeight(y->left)) + 1;

    // return Y as now it is a root node
    return y;
}

// RIGHT ROTATION CASE WHEN LEFT LEFT / LL INSERTION CASE
struct AVLTree *rightRotate(struct AVLTree *y)
{
    struct AVLTree *x = y->left;
    struct AVLTree *T2 = x->right;

    // RIGHT ROTATION
    x->right = y;
    y->left = T2;

    // UPDATE HEIGHTS
    x->height = maximum(getHeight(x->left), getHeight(y->right)) + 1;
    y->height = maximum(getHeight(y->right), getHeight(y->left)) + 1;

    // return x as it is now the root node
    return x;
}

// INSERTION

struct AVLTree *insertion(struct AVLTree *node, int key)
{
    if (node == NULL)
    {
        return createAVLTree(key);
    }

    if (key > node->data)
    {
        node->right = insertion(node->right, key);
    }
    else if (key < node->data)
    {
        node->left = insertion(node->left, key);
    }
    else
    {
        printf("dublicate value %d cannot be inserted in BST! \n", key);
    }

    // UPDATE HEIGHTS
    node->height = maximum(getHeight(node->right), getHeight(node->left)) + 1;
    int bf = balanceFactor(node);

    // LEFT LEFT / LL INSERTION && RIGHT ROTATION CASE
    if (bf > 1 && key < node->left->data)
    {
        return rightRotate(node);
    }

    // RIGHT RIGHT / RR INSERTION && LEFT ROTATION CASE
    if (bf < -1 && key > node->right->data)
    {
        return leftRotate(node);
    }

    // LEFT RIGHT / LR INSERTION && LEFT ROTATION AND THEN RIGHT ROTATION

    if (bf > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RIGHT LEFT / RL INSERTION && RIGHT ROTATION AND THEN LEFT ROTATION WITH RESPECT TO THEIR ROOT NODES

    if (bf < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    struct AVLTree *root = NULL;
    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 4);
    root = insertion(root, 5);
    root = insertion(root, 6);
    root = insertion(root, 3);
    root = insertion(root, 3);

    preOrder(root);

    return 0;
}