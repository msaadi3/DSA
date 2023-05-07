
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

void traverse(struct queue* f)
{
    while (f != NULL)
    {
        printf("%d\n", f->data);
        f = f->next;
    }
}

int isFull()
{
    struct queue *ptr = (struct queue *)malloc(sizeof(struct queue));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *f)
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

struct queue* enqueue(struct queue** b, struct queue** f, int val)
{
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    if (newNode != NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
        if (*f == NULL)
        {
            *b = *f = newNode;
        }
        else
        {
            (*b)->next = newNode;
            *b = newNode;
        }

    }
}

struct queue* dequeue(struct queue *f)
{
    int delete;
    if (!isEmpty(f))
    {
        struct queue *ptr = f;
        f = f->next;
        free(ptr);
        return f;
    }
}

int dequeueOther(struct queue** f)
{
    int delete;
    if (!isEmpty(*f))
    {
        struct queue *ptr = *f;
        *f = (*f)->next;
        delete = ptr->data;
        free(ptr);
        return delete;
        
    }
    return 0;
}


int main()
{

    struct queue* f = NULL;
    struct queue* b = NULL; 
    enqueue(&b,&f,1);
    enqueue(&b,&f,2);
    enqueue(&b,&f,3);
    enqueue(&b,&f,4);
    enqueue(&b,&f,5);
    // traverse(f);
    
    // f = dequeue(f);
    // f = dequeue(f);
    // int deq = dequeueOther(&f);
    // printf("%d deqeued element ", deq);
    // deq = dequeueOther(&f);
    // printf("%d deqeued element ", deq);
    // traverse(f);

    return 0;
}