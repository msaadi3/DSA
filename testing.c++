#include <bits/stdc++.h>
using namespace std;

// --------------

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        queue<Node *> down;
        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->next == NULL)
            {
                Node *front = down.front();
                down.pop();
                curr->next = front;
                front->prev = curr;
            }
            if (curr->child != NULL)
            {
                down.push(curr->child);
            }
            curr = curr->next;
        }
        return head;
    }
};
int main()
{
    return 0;
}

// ------------------------------------------------------------------------------
