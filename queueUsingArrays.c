
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int b;
    int f;
    int *arr;
};

void createQueue(struct queue *q, int s)
{
    q->size = s;
    q->f = -1;
    q->b = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

int isFull(struct queue *q)
{
    if (q->b == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->b)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (!isFull(q))
    {
        q->b++;
        q->arr[q->b] = val;
    }
}

int dequeue(struct queue *q)
{
    int delete;
    if (!isEmpty(q))
    {
        q->f++;
        delete = q->arr[q->f];
        return delete;
    }
    return 0;
}

void traverse(struct queue *q)
{
    for (int i = 0; i < q->size; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    createQueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    traverse(q);
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));

    if (isFull(q))
    {
        printf("queue is full");
    }
    else
    {
        printf("queue isn't full");
    }
}