

#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int b;
    int *arr;
};

void createCircularQueue(struct circularQueue *q, int size)
{
    q->size = size;
    q->f = 0;
    q->b = 0;
    q->arr = (int *)malloc(size * sizeof(int));
}

int isFull(struct circularQueue *q)
{
    if ((q->b + 1) % (q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->b)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (!isFull(q))
    {
        q->b = (q->b + 1) % (q->size); // circular increment
        q->arr[q->b] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int delete;
    if (!isEmpty(q))
    {
        q->f = (q->f + 1) % (q->size); // circular increment
        delete = q->arr[q->f];
        return delete;
    }
    return 0;
}

// traverse reamaining
// void traverse(struct circularQueue* q){
//     int i = q->f;
//     // int i = (q->f + 1) % (q->size);
//     do
//     {
//         printf("%d\n", q->arr[i]);
//         i = (q->f+1) % (q->size);
//     } while (i != q->b);

// }
// void traverse(struct circularQueue* q){

//     for (int i = (q->f + 1); i = q->b ; i = (i++) % (q->size))
//     {
//         printf("%d\n", q->arr[i]);
//     }

// }

int main()
{

    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    createCircularQueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    traverse(q);
    // if (isFull(q))
    // {
    //     printf("queue is full");
    // } else
    // {
    //     printf("queue isn't full");

    // }
    // int deq;
    // deq = dequeue(q);
    // printf("%d deqeued element", deq);
    // deq = dequeue(q);
    // printf("%d deqeued element", deq);
    // if (isFull(q))
    // {
    //     printf("queue is full");
    // } else
    // {
    //     printf("queue isn't full");

    // }

    return 0;
}