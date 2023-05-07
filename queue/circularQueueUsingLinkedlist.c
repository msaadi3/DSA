// CIRCULAR QUEUE USING CIRCULAR SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int data;
    struct circularQueue *next;
};

int isEmpty(struct circularQueue *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void traverse(struct circularQueue* f){
    struct circularQueue* ptr = f;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr->next!=f);
    
}

void enqueueF(struct circularQueue **f, struct circularQueue **b, int x)
{
    struct circularQueue *newNode = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    newNode->data = x;

        if (*f = NULL)
        {
            *f = *b = newNode;
        }

        (*b)->next = newNode;
        newNode->next = *f;
        *f = newNode;
    
}
void enqueueB(struct circularQueue **f, struct circularQueue **b, int x)
{
    struct circularQueue *newNode = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    newNode->data = x;

    if (newNode != NULL)
    {

        (*b)->next = newNode;
        newNode->next = *f;
    }
}

void dequeueB(struct circularQueue **f)
{
    if (!isEmpty(*f))
    {

        struct circularQueue *p = *f;
        struct circularQueue *q = (*f)->next;
        while (q->next != *f)
        {
            p = p->next;
            q = q->next;
        }
        p->next = *f;
        free(q);
    }
}

void dequeueF(struct circularQueue **f)
{
    if (!isEmpty(*f))
    {

        struct circularQueue *p = *f;
        struct circularQueue *q = (*f)->next;
        while (q->next != *f)
        {
            q = q->next;
        }
        *f = (*f)->next;
        q->next = *f;
        free(p);
    }
}

int main()
{
    struct circularQueue* f = NULL;
    struct circularQueue* b = NULL;

    // enqueueB(&f, &b, 1);
    enqueueF(&f, &b, 1);
    traverse(f);


    return 0;
}
