
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// LINKED LIST TRAVERSAL

void linkedListTraversal(struct Node *head)
{

    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// ---------------------------------------- INSERTION FUNCTIONS ------------------------------------------------------------------------------

// INSERTION AT FIRST IN LINKED LIST

struct Node *insertionAtFirst(struct Node *head, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    newNode->next = head;
    // return newNode;
    // head = newNode;
    // newNode = head;
    return newNode;
}

// INSERTION AT ANY INDEX / MIDDLE OF THE LINKED LIST

struct Node *insertionAtIndex(struct Node *head, int x, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    struct Node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->data = x;
    return head;
}

// INSERTION AFTER GIVEN NODE OF THE LINKED LIST

struct Node *insertionAfterNode(struct Node *head, struct Node *givenPtr, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    newNode->next = givenPtr->next;
    givenPtr->next = newNode;
    return head;
}

// INSERTION AT THE END OF THE LINKED LIST

struct Node *inerstionAtEnd(struct Node *head, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}

/*
create a function to set data / to create linked list and also create a one single function for all cases of insertions
void setData(int data){
    for (int i = 0; i < 5; i++)
    {

    }

}

*/

// ************************************************* DELETIONS FUNCTIONS **********************************************************************

// DELETION OF THE FIRST NODE IN THE LINKED LIST

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// DELETION OF THE NODE AT INDEX IN LINKED LIST

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
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


// DELETE LAST NODE IN THE LINKED LIST

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = NULL;
    free(ptr2);
    return head;
}

// DELETE A NODE WITH A GIVEN VALUE FROM A LINKED LIST

struct Node *deleteNodeWithGivenValue(struct Node *head, int element)
{
    struct Node *ptr = head;
    struct Node *ptr2 = head->next;

    while (ptr2->data != element && ptr2->next == NULL)
    {
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    if (ptr2->data == element)
    {
        ptr->next = ptr2->next;
        free(ptr2);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    // linkedListTraversal(head);
    // printf("\n");

    // head = insertionAtIndex(head,75,1);
    // linkedListTraversal(head);

    // head = insertionAtFirst(head, 55);
    // linkedListTraversal(head);

    // head = inerstionAtEnd(head, 5);
    // linkedListTraversal(head);

    // head = insertionAfterNode(head,third, 9);
    // linkedListTraversal(head);

    // head = deleteFirstNode(head);
    // linkedListTraversal(head);

    // head = deleteAtIndex(head,2);
    // linkedListTraversal(head);

    // head = deleteNodeWithGivenValue(head, 2);
    // linkedListTraversal(head);
    return 0;
}