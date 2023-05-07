
#include <stdio.h>
#include <stdlib.h>

// BINARY TREE LINKED REPRESENTATION USING DOUBLY LINKED LIST

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *createBinaryTree(int x)
{
    struct BST *newNode = (struct BST *)malloc(sizeof(struct BST));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(struct BST *root)
{ // ROOT -> LEFT -> RIGHT
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct BST *root)
{ // LEFT -> RIGHT -> ROOT
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}

void inOrder(struct BST *root)
{ // LEFT -> ROOT -> RIGHT
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}

// BINARY SEARCH TREE INSERTION

struct BST *insertion(struct BST *root, int x)
{
    struct BST *prev;
    while (root != NULL)
    {
        prev = root;

        if (root->data == x)
        {
            printf("%d connot insert dublicate value", x);
            return 0;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct BST *newNode = createBinaryTree(x);
    if (prev->data > newNode->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
    return newNode;
}

// INORDER PREDECESSOR

struct BST *inOrderPre(struct BST *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// BINARY SEARCH TREE DELETION

struct BST *deletion(struct BST *root, int x)
{
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (root == NULL)
    {
        return NULL;
    }

    struct BST *iPre;
    if (root->data > x)
    {
        root->left = deletion(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = deletion(root->right, x);
    }
    else if (root->data == x)
    {
        iPre = inOrderPre(root);
        root->data = iPre->data;
        root->left = deletion(root->left, iPre->data);
    }
    return root;
}

// TO SEE IF IT'S A LEAF NODE OR NOT

int isLeaf(struct BST *root)
{
    if (root->right == NULL && root->left == NULL)
    {
        printf("yes");
        return 1;
    }
    printf("NOT");
    return 0;
}

// FIND AN ELEMENT

struct BST *findElement(struct BST *root, int x)
{
    while (root != NULL)
    {

        if (root->data > x)
        {
            root = root->left;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else if (root->data == x)
        {
            printf("%d element found: ", x);
            return root;
        }
    }
}

// FIND/RETURN THE PARENT NODE/ROOT NODE OF A GIVEN NODE

struct BST *parent(struct BST *root, struct BST *node)
{

    while (root->left == node || root->right == node)
    {
        if (root->data < node->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
        return root;
    }
}

// FIND/RETURN THE LEFT CHILD OF THE GIVEN PARENT NODE/ROOT

struct BST *leftChild(struct BST *root)
{

    if (root->left != NULL)
    {
        root = root->left;
        return root;
    }
    // return root;
}

// FIND/RETURN THE RIGHT CHILD OF THE GIVEN PARENT NODE/ROOT

struct BST *rightChild(struct BST *root)
{
    if (root->right != NULL)
    {
        root = root->right;
        return root;
    }
    // return root;
}

// SEARCHING ELEMENET USING RECURSION ||||||||| NOT CLEAR HAVE TO UNDERSTAND AGAIN

struct BST *search(struct BST *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        printf("%d ELEMENT FOUND ", key);
        return root;
    }
    else if (root->data > key)
    {
        // search(root->left, key);
        return search(root->left, key);
    }
    else if (root->data < key)
    {
        // search(root->right, key);
        return search(root->right, key);
    }
}

// SEARCHING ELEMENT USING ITERATION

struct BST *searchIter(struct BST *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            printf("%d ELEMENT FOUND ", key);
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    printf("%d ELEMENT NOT FOUND", key);
    return NULL;
}

int main()
{

    struct BST *root;
    struct BST *leftNode;
    struct BST *rightNode;
    root = createBinaryTree(5);
    leftNode = createBinaryTree(2);
    rightNode = createBinaryTree(7);

    root->left = leftNode;
    root->right = rightNode;

    struct BST *new;
    new = insertion(root, 10);
    // inOrder(root);
    // printf("%d", rightNode->right->data);

    // preOrder(root);
    // postOrder(root);
    // inOrder(root);  //inorder of bst is always a sorted array in assending order

    // printf("%d", root->right->right->data);
    // struct BST* temp;
    // temp = deletion(root,2);
    // inOrder(root);
    // printf("%d", temp->data);

    // isLeaf(root);
    // isLeaf(new);

    // findElement(root,11);
    // struct BST* temp;
    // temp = findElement(root,10);
    // printf("%d", temp->data);

    // struct BST *temp;
    // temp = parent(root, new);
    // printf("%d", temp->data);

    // struct BST *temp;
    // temp = leftChild(root);
    // printf("%d", temp->data);

    // struct BST *temp;
    // temp = rightChild(rightNode);
    // printf("%d", temp->data);

    // struct BST* temp;
    // temp = searchIter(root,5);
    // printf("%d",temp->data);

    // struct BST *temp;
    // temp = search(root,9);
    // search(root, 2);
    // search(root, 9);
    // printf("%d",temp->data);

    return 0;
}
