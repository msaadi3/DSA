
#include <stdio.h>
#include <stdlib.h>

struct doublyCircularLinkedlist
{
    int data;
    struct doublyCircularLinkedlist *next;
    struct doublyCircularLinkedlist *prev;
};

// DOUBLY CIRCULAR LINKEDLIST TRAVERSAL

void traverse(struct doublyCircularLinkedlist *head)
{
    struct doublyCircularLinkedlist *p = head;
    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p->next != head);
}

// INSERTION AT FIRST

struct doublyCircularLinkedlist *insertionAtFirst(struct doublyCircularLinkedlist *head, int x)
{
    struct doublyCircularLinkedlist *newNode = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    newNode->data = x;

    struct doublyCircularLinkedlist* p = head;
    do
    {
        p = p->next;
    } while (p->next!=head);
     
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = p;
    p->next = newNode;

    return newNode;
}

// INSERTION AT INDEX

struct doublyCircularLinkedlist *insertionAtIndex(struct doublyCircularLinkedlist *head, int x, int index)
{
    struct doublyCircularLinkedlist *newNode = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    newNode->data = x;

    struct doublyCircularLinkedlist* p = head;
    struct doublyCircularLinkedlist* q = head->next;
    

    int i = 1;
    while (i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = newNode;
    newNode->prev = p;
    newNode->next = q;
    q->prev = newNode;
    return head;
    
}

// INSERTION AT END

struct doublyCircularLinkedlist *insertionAtEnd(struct doublyCircularLinkedlist *head, int x)
{
    struct doublyCircularLinkedlist *newNode = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    newNode->data = x;

    struct doublyCircularLinkedlist* p = head;

    do
    {
        p = p->next;
    } while (p->next!=head);
    
    p->next = newNode;
    newNode->prev = p;
    newNode->next = head;
    head->prev = newNode;

    return head;
    
}

// INSERTION AFTER A GIVEN NODE

struct doublyCircularLinkedlist *insertionAfterNode(struct doublyCircularLinkedlist *head, struct doublyCircularLinkedlist* node, int x)
{
    struct doublyCircularLinkedlist *newNode = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    newNode->data = x;

    struct doublyCircularLinkedlist* p = node->next; 
    newNode->next = node->next;
    node->next = newNode;
    newNode->prev = node;
    p->prev = newNode;

return head;

}

// DELETION AT FIRST

struct doublyCircularLinkedlist *deletionAtFirst(struct doublyCircularLinkedlist *head)
{
    struct doublyCircularLinkedlist* p = head;
    struct doublyCircularLinkedlist* q = head->next;
    do
    {
        q=q->next;
    } while (q->next!=head);
    
    
    head = head->next;
    head->prev = q;
    q->next = head;
    free(p);
    return head;

}

// DELETION AT INDEX

struct doublyCircularLinkedlist *deletionAtIndex(struct doublyCircularLinkedlist *head, int index)
{
    struct doublyCircularLinkedlist* p = head;
    struct doublyCircularLinkedlist* q = head->next;
    struct doublyCircularLinkedlist* r = q->next;
    int i = 1;
    while (i!=index-1)
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

struct doublyCircularLinkedlist *deletionAtEnd(struct doublyCircularLinkedlist *head)
{
    struct doublyCircularLinkedlist* p = head;
    struct doublyCircularLinkedlist* q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    head->prev = p;
    free(q);
    return head;

}

// DELETION AFTER A GIVEN NODE

struct doublyCircularLinkedlist *deletionAfterNode(struct doublyCircularLinkedlist *head, struct doublyCircularLinkedlist *node)
{
    struct doublyCircularLinkedlist* p = node;
    struct doublyCircularLinkedlist* q = node->next;

    node->next = q->next;
    q->prev = node;
    free(q);
    return head;
}

int main()
{

    struct doublyCircularLinkedlist *head = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    struct doublyCircularLinkedlist *second = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    struct doublyCircularLinkedlist *third = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    struct doublyCircularLinkedlist *fourth = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));
    struct doublyCircularLinkedlist *last = (struct doublyCircularLinkedlist *)malloc(sizeof(struct doublyCircularLinkedlist));

    head->data = 1;
    head->next = second;
    head->prev = last;

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
    last->next = head;
    last->prev = fourth;
    // traverse(head);

    // head = insertionAtFirst(head,10);
    // traverse(head);

    // head = insertionAfterNode(head,second,20);
    // traverse(head);

    // head = insertionAtEnd(head, 20);
    // traverse(head);           remaining

    // head = insertionAtIndex(head,20,4);
    // traverse(head);      

    // head = deletionAfterNode(head,second);
    // traverse(head);

    // head = deletionAtIndex(head, 2);
    // traverse(head);           

    // head = deletionAtEnd(head);
    // traverse(head);

    // head = deletionAtFirst(head);
    // traverse(head);
    return 0;
}