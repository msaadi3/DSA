#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ----------------------------------
// best approach /  100/67
class Solution
{
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {

        // Create a clone list using just next pointer
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Mapping
        unordered_map<Node *, Node *> originalToCloneMapping;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            originalToCloneMapping[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            cloneNode->random = originalToCloneMapping[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

// Another approach / i think not the best one 37/31
class Solution
{
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {

        // step 1: Create a clone list using just next pointer
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // step 2: add clone nodes in between original list
        Node *originalNode = head;
        Node *originalNext = NULL;
        Node *cloneNode = cloneHead;
        Node *cloneNext = NULL;
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNext = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = originalNext;

            // same for clone node
            cloneNext = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = cloneNext;
        }

        // step 3: copy random pointers
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {

                temp->next->random = temp->random ? temp->random->next : temp->random;
                temp = temp->next->next;
            }
        }
        // step 4: revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if (originalNode != NULL)
            {

                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

int main()
{
    return 0;
}