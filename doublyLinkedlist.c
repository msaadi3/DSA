
#include <stdio.h>
#include <stdlib.h>

struct doublyLinkedlist
{
    int data;
    struct doublyLinkedlist *next;
    struct doublyLinkedlist *prev;
};

// DOUBLY LINKEDLIST TRAVERSAL

void forwardTraverse(struct doublyLinkedlist *head)
{
    struct doublyLinkedlist *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void backwardTraverse(struct doublyLinkedlist *last)
{
    struct doublyLinkedlist *p = last;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->prev;
    }
}

// INSERTION AT FIRST

struct doublyLinkedlist *insertionAtFirst(struct doublyLinkedlist *head, int x)
{
    struct doublyLinkedlist *newNode = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    newNode->data = x;

    newNode->next = head;
    head->prev = newNode;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

// INSERTION AT INDEX

struct doublyLinkedlist *insertionAtIndex(struct doublyLinkedlist *head, int x, int index)
{
    struct doublyLinkedlist *newNode = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    newNode->data = x;

    struct doublyLinkedlist *p = head;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->prev = p;
    return head;
}

// INSERTION AT END

struct doublyLinkedlist *insertionAtEnd(struct doublyLinkedlist *head, int x)
{
    struct doublyLinkedlist *newNode = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    newNode->data = x;

    struct doublyLinkedlist *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->prev = p;
    newNode->next = NULL;
    return head;
}

void insertionAtEndOtherWay(struct doublyLinkedlist *last, int x)
{
    struct doublyLinkedlist *newNode = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    newNode->data = x;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = NULL;
}

// INSERTION AFTER GIVEN NODE

struct doublyLinkedlist *insertionAfterNode(struct doublyLinkedlist *head, struct doublyLinkedlist *node, int x)
{
    struct doublyLinkedlist *newNode = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    newNode->data = x;

    newNode->next = node->next;
    newNode->prev = node;
    node->next = newNode;

    return head;
}

// DELETION AT FIRST

struct doublyLinkedlist *deletionAtFirst(struct doublyLinkedlist *head)
{
    struct doublyLinkedlist *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);

    return head;
}

// DELETION AT INDEX

struct doublyLinkedlist *deletionAtIndex(struct doublyLinkedlist *head, int index)
{
    struct doublyLinkedlist *p = head;
    struct doublyLinkedlist *q = head->next;
    struct doublyLinkedlist *r = q->next;

    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        r = r->next;
        i++;
    }
    
        p->next = r;
        r->prev = p;
        free(q);
        return head;
    

}    
// DELETION AT END

struct doublyLinkedlist *deletionAtEnd(struct doublyLinkedlist *head)
{
    struct doublyLinkedlist *p = head;
    struct doublyLinkedlist *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// DELETION AFTER A GIVEN NODE

struct doublyLinkedlist *deletionAfterNode(struct doublyLinkedlist *head, struct doublyLinkedlist *node)
{
    struct doublyLinkedlist *q = node;
    struct doublyLinkedlist *p = node->next;
    struct doublyLinkedlist *r = p->next;

    if (node != head && node->next != NULL)
    {
        q->next = r;
        r->prev = q;
        free(p);
        return head;
    }
}

int main()
{

    struct doublyLinkedlist *head = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    struct doublyLinkedlist *second = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    struct doublyLinkedlist *third = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    struct doublyLinkedlist *fourth = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));
    struct doublyLinkedlist *last = (struct doublyLinkedlist *)malloc(sizeof(struct doublyLinkedlist));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = last;
    fourth->prev = third;

    last->data = 5;
    last->next = NULL;
    last->prev = fourth;

    // forwardTraverse(head);
    // backwardTraverse(last);

    // head = insertionAtEnd(head, 20);
    // forwardTraverse(head);

    // head = insertionAtFirst(head,20);
    // forwardTraverse(head);

    // head = insertionAtIndex(head, 20, 2);
    // forwardTraverse(head);

    // head = insertionAfterNode(head, second, 20);
    // forwardTraverse(head);

    // insertionAtEndOtherWay(last, 20);
    // forwardTraverse(head);
    
    // head = deletionAtFirst(head);
    // forwardTraverse(head);

    // head = deletionAtEnd(head);
    // forwardTraverse(head);

    // head = deletionAtIndex(head, 4);
    // forwardTraverse(head);

    // head = deletionAfterNode(head, second);
    // forwardTraverse(head);
    
    return 0;
}