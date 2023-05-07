
#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int data;
    struct DEQueue *next;
};

int isFull()
{
    struct DEQueue *ptr = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct DEQueue *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueueB(struct DEQueue **f, struct DEQueue **b, int data)
{
    struct DEQueue *newNode = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        if (*f == NULL)
        {
            *f = *b = newNode;
        }
        else
        {
            (*b)->next = newNode;
            *b = newNode;
        }
    }
}

void enqueueF(struct DEQueue **f, struct DEQueue **b, int data)
{
    struct DEQueue *newNode = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (newNode != NULL)
    {
        newNode->data = data;
        if (*f && *b == NULL)
        {
            *f = *b = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = *f;
            *f = newNode;
        }
    }
}

void dequeueB(struct DEQueue **f, struct DEQueue **b)
{
    // int data;
    if (!isEmpty(*f))
    {
        struct DEQueue *ptr = *f;
        struct DEQueue *ptr2 = (*f)->next;
        while (ptr2->next != NULL)
        {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        // data = ptr2->data;
        ptr->next = NULL;
        free(ptr2);
        *b = ptr;
        // return ptr;
    }
}

void dequeueF(struct DEQueue **f)
{
    int data;
    if (!isEmpty(*f))
    {
        struct DEQueue *ptr = *f;
        // data = (*f)->data;
        *f = (*f)->next;
        free(ptr);
        // return data;
    }

    // return 0;
}

void traverse(struct DEQueue *f)
{
    struct DEQueue *ptr = f;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct DEQueue *f = NULL;
    struct DEQueue *b = NULL;

    enqueueB(&f, &b, 1);
    enqueueB(&f, &b, 2);
    enqueueF(&f, &b, 3);
    enqueueF(&f, &b, 4);
    enqueueF(&f, &b, 5);
    // traverse(f);
    dequeueB(&f, &b);
    // dequeueF(&f);
    traverse(f);

    if (isEmpty(f))
    {
        printf("queue is empty");
    }
    else
    {
        printf("queue isn't empty");
    }

    return 0;
}