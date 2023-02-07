
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void createStack(struct stack *ptr, int s)
{
    ptr->size = s;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

void traverse(struct stack *ptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d\n", ptr->arr[i]);
    }
}

int push(struct stack *ptr, int value)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return 1;
    }
    return 0;
}

int pop(struct stack *ptr)
{
    int delete;
    if (!isEmpty(ptr))
    {
        delete = ptr->arr[ptr->top];
        ptr->top--;
        return delete;
    }
    return 0;
}

int peak(struct stack *ptr, int i)
{
    int position = ptr->top - i + 1;
    if (position < 0)
    {
        printf("not valid");
        return 0;
    }

    return ptr->arr[position];
}
int main()
{
    struct stack *myStack = (struct stack *)malloc(sizeof(struct stack));
    createStack(myStack, 5);
    // push(myStack, 1);
    // push(myStack,2 );
    // push(myStack, 3);
    // push(myStack, 41);
    // push(myStack, 5);

    // traverse(myStack, 6);

    // for (int i = 1; i < 6; i++)
    // {
    // printf("%d\n", peak(myStack,i));
    // }
    // int poped;
    // poped = pop(myStack);
    // poped = pop(myStack);
    // printf("%d\n poped", poped);
    // printf("%d\n poped", poped);
    // push(myStack, 55);
    // push(myStack, 69);
    // traverse(myStack,6);

    // printf("%d\n", stackTop(myStack));
    // printf("%d\n", stackBottom(myStack));

    return 0;
}