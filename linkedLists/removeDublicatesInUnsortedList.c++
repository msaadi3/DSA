#include <bits/stdc++.h>
using namespace std;

// Remove dublicates from an unsorted linked list. there are three approaches of this problem
// 1. Two nested loops but not the best approach as T.C is O(n2)
// 2. Hashmap approach T.C isO(N) and S.C is O(N)
// 3. Sort the linked list using merge sort and remove dublicates from sorted list
// Following is the class structure of the Node class:
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

// Hashmap approach
Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    unordered_map<int, bool> mp;
    Node *curr = head->next;
    Node *prev = head;
    mp[head->data] = true;

    while (curr != NULL)
    {

        if (mp[curr->data] == true)
        {
            Node *temp = curr;
            prev->next = curr->next;
            delete temp;
            curr = curr->next;
        }
        else
        {
            mp[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
