
#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int f;
    int b;
    int size;
    int *arr;
};

void createDEQueue(struct DEQueue *q, int size)
{
    q->size = size;
    q->b = -1;
    q->f = -1;
    q->arr = (int *)malloc(size * sizeof(int));
}

int isEmpty(struct DEQueue *q)
{
    if (q->f == q->b)
    {
        return 1;
    }
    return 0;
}

int isFull(struct DEQueue *q)
{
    if (q->b == q->size - 1 && q->f == -1)
    {
        return 1;
    }
    return 0;
}

void enqueueB(struct DEQueue **q, int val)
{
    if (!isFull(*q))
    {
        (*q)->b++;
        (*q)->arr[(*q)->b] = val;
    }
}

void enqueueF(struct DEQueue **q, int val)
{
    if (!isFull(*q))
    {

        (*q)->f++;
        (*q)->arr[(*q)->f] = val;
        (*q)->f--;
    }
}

int dequeueF(struct DEQueue **q)
{
    int data;
    if (!isEmpty(*q))
    {
        (*q)->f++;
        data = (*q)->arr[(*q)->f];
        return data;
    }
    return 0;
}

int dequeueB(struct DEQueue **q)
{
    int data;
    if (!isEmpty(*q))
    {
        data = (*q)->arr[(*q)->b];
        (*q)->b--;
        return data;
    }
    return 0;
}

void traverseBackward(struct DEQueue *q)
{
    int i = q->f + 1;
    do
    {
        printf("%d\n", q->arr[i]);
        i++;
    } while (i <= q->b);
}

void traverseForward(struct DEQueue *q)
{
    int i = q->b;
    while (i > q->f)
    {
        printf("%d\n", q->arr[i]);
        i--;
    }
}

int main()
{
    struct DEQueue *q = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    createDEQueue(q, 10);
    enqueueB(&q, 1);
    enqueueB(&q, 2);
    enqueueB(&q, 3);
    enqueueB(&q, 4);
    enqueueB(&q, 4);
    enqueueB(&q, 4);
    enqueueB(&q, 4);
    enqueueB(&q, 4);
    traverseForward(q);
    traverseBackward(q);
    return 0;
}