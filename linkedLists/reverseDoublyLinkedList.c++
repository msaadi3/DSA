#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------
// Reverse doubly linked list using iteration / loop but using recurion for another day
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    return prev;
}
