#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure:

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

// ---------------------------------------------------------------------------------------------------------------------------------------

// Merget two BSTs to create a single BST
// T.C and S.C is O(M+N)

void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

vector<int> mergeArrays(vector<int> &first, vector<int> &second)
{
    vector<int> merge(first.size() + second.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < first.size() && j < second.size())
    {
        if (first[i] < second[j])
        {
            merge[k++] = first[i++];
        }
        else
        {
            merge[k++] = second[j++];
        }
    }

    while (i < first.size())
    {
        merge[k++] = first[i++];
    }

    while (j < second.size())
    {
        merge[k++] = second[j++];
    }
    return merge;
}

TreeNode *BST(vector<int> &inorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;

    TreeNode *root = new TreeNode(inorder[mid]);

    root->left = BST(inorder, s, mid - 1);
    root->right = BST(inorder, mid + 1, e);
    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return NULL;
    }

    if (root1 == NULL && root2 != NULL)
    {
        return root2;
    }

    if (root1 != NULL && root2 == NULL)
    {
        return root1;
    }

    // step 1: First get the inorder of both BSTS
    vector<int> firstInorder;
    vector<int> secondInorder;

    inorderTraversal(root1, firstInorder);
    inorderTraversal(root2, secondInorder);

    // Step 2: Merge two inorder into single
    vector<int> result = mergeArrays(firstInorder, secondInorder);

    // Step 3: Use that merged inorder of BSTS to create a single BST and return the root of the BST
    return BST(result, 0, result.size() - 1);
}

// Another approach
// Not accepted on coding ninjas because of run time error. i don't know why so i just left it

// convert BST to sorted Doubly linked list
void BSTtoSortedDLL(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
    {
        return;
    }

    BSTtoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }

    head = root;

    BSTtoSortedDLL(root->left, head);
}

// Merge two sorted doubly linked lists

TreeNode *mergeTwoSortedDLL(TreeNode *head1, TreeNode *head2)
{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Count the number of nodes

int countNodes(TreeNode *head)
{
    int count = 0;
    TreeNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }

    return count;
}

// Convert sorted doubly linked list to BST

TreeNode *sortedDLLToBST(TreeNode *head, int nodes)
{
    // base case
    if (nodes <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode *left = sortedDLLToBST(head, nodes / 2);

    TreeNode *root = head;

    root->left = left;

    head = head->right;

    root->right = sortedDLLToBST(head, nodes - nodes / 2 - 1);

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Step 1: Convert both BSTs to sorted doubly linked lists in place
    TreeNode *head1 = NULL;
    BSTtoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode *head2 = NULL;
    BSTtoSortedDLL(root2, head2);
    head2->left = NULL;

    // Step 2: Merge two sorted doubly linked lists
    TreeNode *head = mergeTwoSortedDLL(head1, head2);

    // Step 3: Convert sorted doubly linked list into single BST

    // First count the number of nodes
    int nodes = countNodes(head);

    TreeNode *root = sortedDLLToBST(head, nodes);

    return root;
}