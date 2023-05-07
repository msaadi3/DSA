
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *top)
{
    while (top != NULL)
    {
        printf("Element: %d\n ", top->data);
        top = top->next;
    }
}

int isFull(struct Node *top)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode != NULL)
    {
        newNode->data = x;
        newNode->next = top;
    }

    return newNode;
}

int pop(struct Node **top)
{
    int data;
    if (!isEmpty(*top))
    {
        struct Node *p = *top;
        data = (*top)->data;
        *top = (*top)->next;
        free(p);
        return data;
    }
    return 0;
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *newNode = top;
    while (newNode->next != NULL)
    {
        newNode = newNode->next;
    }
    return newNode->data;
}

int peak(struct Node *top, int pos)
{
    struct Node *newNode = top;
    for (int i = 0; i < (pos - 1 && newNode != NULL); i++)
    {
        newNode = newNode->next;
    }
    if (newNode != NULL)
    {
        return newNode->data;
    }
    return 0;
}

int main()
{

    struct Node *top = NULL;
    struct Node *top2 = NULL;

    top = push(top, 20);
    top = push(top, 10);
    top = push(top, 10);

    top2 = push(top2, 30);
    top2 = push(top2, 30);
    top2 = push(top2, 30);
    top2 = push(top2, 30);
    top2 = push(top2, 30);
    // traverse(top2);
    // traverse(top);
    // printf("%d\n", stackBottom(top));
    // printf("%d\n", stackTop(top));

    // int element = pop(&top);
    // printf("%d\n", element);
    // traverse(top);
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("value at position %d is : %d\n", i, peak(top, i));
    // }

    return 0;
}