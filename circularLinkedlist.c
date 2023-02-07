
#include <stdio.h>
#include <stdlib.h>

struct circularLinkedlist
{
    int data;
    struct circularLinkedlist *next;
};

// CHECK IF ITS EMPTY

int isEmpty(struct circularLinkedlist *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

// TRAVERSAL OF CIRCULAR LINKEDLIST

void traverse(struct circularLinkedlist *head)
{
    struct circularLinkedlist *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// *****************************************INSERTIONS*****************************************************************************************

// INSERTION AT FIRST

struct circularLinkedlist *insertionAtFirst(struct circularLinkedlist *head, int x)
{
    struct circularLinkedlist *newNode = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    newNode->data = x;
    struct circularLinkedlist *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);

    p->next = newNode;
    newNode->next = head;
    // head = newNode;
    // return head;   // both methods are same
    return newNode;
}

// INSERTION AT INDEX

struct circularLinkedlist *insertionAtIndex(struct circularLinkedlist *head, int x, int index)
{
    struct circularLinkedlist *newNode = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    struct circularLinkedlist *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->data = x;
    return head;
}

//  INSERTION AT END/LAST (NOT SUCCESSFULL/)

struct circularLinkedlist *insertionAtEnd(struct circularLinkedlist *head, int x)
{
    struct circularLinkedlist *newNode = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    newNode->data = x;

    struct circularLinkedlist *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);

    p->next = newNode;
    newNode->next = head;
    return head;
}

struct circularLinkedlist *insertionAtEndOtherWay(struct circularLinkedlist *head, struct circularLinkedlist *last, int x)
{
    struct circularLinkedlist *newNode = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    newNode->data = x;

    last->next = newNode;
    newNode->next = head;
    return head;
}

// INSERTION AFTER A GIVEN NODE

struct circularLinkedlist *insertionAfterNode(struct circularLinkedlist *head, struct circularLinkedlist *node, int x)
{
    struct circularLinkedlist *newNode = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    newNode->data = x;

    newNode->next = node->next;
    node->next = newNode;

    return head;
}

// ****************************************************DELETIONS*******************************************************************************

// DELETION AT FIRST

struct circularLinkedlist *deletionAtFirst(struct circularLinkedlist *head)
{
    if (!isEmpty(head))
    {
        struct circularLinkedlist *p = head;
        struct circularLinkedlist *q = head;

        while (q->next != head)
        {
            q = q->next;
        }

        head = head->next;
        free(p);
        q->next = head;
        return head;
    }
}

// DELETION AT INDEX

struct circularLinkedlist *deletionAtIndex(struct circularLinkedlist *head, int index)
{
    struct circularLinkedlist *p = head;
    struct circularLinkedlist *q = head->next;

    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// DELETE THE LAST NODE

struct circularLinkedlist *deletionAtEnd(struct circularLinkedlist *head)
{
    struct circularLinkedlist *p = head;
    struct circularLinkedlist *q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);

    return head;
}

// DELETE A NODE WITH A GIVEN VALUE

struct circularLinkedlist *deletionNodeWithGivenValue(struct circularLinkedlist *head, int val)
{
    struct circularLinkedlist *p = head;
    struct circularLinkedlist *q = head->next;
    while (q->data != val)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct circularLinkedlist *head = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    struct circularLinkedlist *second = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    struct circularLinkedlist *third = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    struct circularLinkedlist *fourth = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));
    struct circularLinkedlist *last = (struct circularLinkedlist *)malloc(sizeof(struct circularLinkedlist));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = last;

    last->data = 5;
    last->next = head;

    // traverse(head);

    // head = insertionAfterNode(head, second, 2);
    // head = insertionAtEnd(head,101);
    // head = insertionAtFirst(head,55);
    // head = insertionAtIndex(head,55,2);

    // head = deletionAtEnd(head);
    // head = deletionAtFirst(head);
    // head = deletionNodeWithGivenValue(head, 4);
    // head = deletionAtIndex(head, 2);
    // traverse(head);

    return 0;
}
