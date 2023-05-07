#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ------------------------------------------------------------------

void splitCircularList(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast->next != head)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != head)
        {
            fast = fast->next;
        }
    }

    Node *secondHEad = slow->next;
    slow->next = head;
    fast->next = secondHEad;
}
