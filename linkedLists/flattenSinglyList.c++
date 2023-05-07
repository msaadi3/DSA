#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// ---------------------

Node *merge(Node *first, Node *second)
{
    // if only one element
    if (first->bottom == NULL)
    {
        first->bottom = second;
        return first;
    }

    Node *curr1 = first;
    Node *curr2 = second;
    Node *next1 = first->bottom;
    Node *next2 = second->bottom;

    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            // add node in between the first list
            next2 = curr2->bottom;
            curr1->bottom = curr2;
            curr2->bottom = next1;

            // update the pointers
            curr1 = curr2;
            next1 = curr1->bottom;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->bottom;
            if (next1 == NULL)
            {
                curr1->bottom = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *findMid(Node *head)
{
    // tortoise and hear approach
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *flatten(Node *root)
{

    // base case
    if (root == NULL || root->bottom == NULL)
    {
        return root;
    }

    // Check if the current sublist is already flattened
    if (root->next == NULL)
    {
        root->bottom = flatten(root->bottom);
        return root;
    }

    // Find mid of the linked list and break it into two halves
    Node *mid = findMid(root);
    Node *left = root;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls
    left = flatten(left);
    right = flatten(right);

    // merge
    Node *result = NULL;
    if (left->data <= right->data)
    {
        result = merge(left, right);
    }
    else
    {
        result = merge(right, left);
    }
    return result;
}

// --------------------------------

int main()
{
    return 0;
}

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data < b->data)
    {
        a->bottom = merge(a->bottom, b);
        return a;
    }
    else
    {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}

Node *flatten(Node *root)
{
    if (!root || !root->next)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
