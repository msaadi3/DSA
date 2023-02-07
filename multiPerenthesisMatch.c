
#include <stdio.h>
#include <stdlib.h>

struct multiPerenthesisMatch
{
    int size;
    int top;
    char *arr;
};

int isFull(struct multiPerenthesisMatch *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct multiPerenthesisMatch *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }

    return 0;
}

void push(struct multiPerenthesisMatch *ptr, char value)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    else
    {
        printf("stack overflow");
    }
}

char pop(struct multiPerenthesisMatch *ptr)
{
    int data;
    if (!isEmpty(ptr))
    {
        data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}' || a == '[' && b == ']' || a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int multiPerenthesisMatch(char *str)
{

    struct multiPerenthesisMatch *stack = (struct multiPerenthesisMatch *)malloc(sizeof(struct multiPerenthesisMatch));
    stack->arr = (char *)malloc(stack->size * sizeof(char));
    stack->size = 10;
    stack->top = -1;
    char popedCh;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(stack, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (isEmpty(stack))
            {
                return 0;
            }
            popedCh = pop(stack);
            if (match(popedCh, str[i]))
            {
                return 1;
            }
        }
    }
    if (isEmpty(stack))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // char *exp = "a+(da}sa{+][";
    char *exp = "()a+b[]{]";

    if (multiPerenthesisMatch(exp))
    {
        printf("balanced \n");
    }
    else
    {
        printf("unbalanced \n");
    }

    return 0;
}