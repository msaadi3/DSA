#include <bits/stdc++.h>
using namespace std;

// Sort singly linked list of 0s 1s 2s / GFG

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

// ---------------------------------------------------------------------------------------------------------------------------------------

// Data replacment approach
class Solution
{
public:
    Node *segregate(Node *head)
    {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zeroCount++;
            }
            else if (temp->data == 1)
            {
                oneCount++;
            }
            else if (temp->data == 2)
            {
                twoCount++;
            }
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            if (zeroCount != 0)
            {
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount != 0)
            {
                temp->data = 1;
                oneCount--;
            }
            else if (twoCount != 0)
            {
                temp->data = 2;
                twoCount--;
            }
            temp = temp->next;
        }

        return head;
    }
};

// --------------------------------
// Another approach no need to replace data
class Solution
{
    void insertAtTail(Node *&tail, Node *&temp)
    {
        tail->next = temp;
        tail = temp;
    }

public:
    Node *segregate(Node *head)
    {
        // Create 3 seperate lists of 0s, 1s, 2s
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                insertAtTail(zeroTail, temp);
            }
            else if (temp->data == 1)
            {
                insertAtTail(oneTail, temp);
            }
            else if (temp->data == 2)
            {
                insertAtTail(twoTail, temp);
            }
            temp = temp->next;
        }

        // Merge 3 seperate lists
        if (oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;
        }
        else
        {
            zeroTail->next = twoHead->next;
        }
        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        head = zeroHead->next;

        // delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};
int main()
{
    return 0;
}