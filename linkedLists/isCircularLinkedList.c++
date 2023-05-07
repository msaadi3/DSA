#include <bits/stdc++.h>
using namespace std;

// Link list Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// -----------------------------------------------------------------------------------------------------------------
// Check if a linked list is circular or not / GFG

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }
    return false;
}

// same as above but with little tweaks in code

bool isCircular2(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == head)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    return 0;
}