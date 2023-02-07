
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

int isFull()
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

struct Node *push(struct Node *top, char x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        newNode->data = x;
        newNode->next = top;
    }
    return newNode;
}

char pop(struct Node **top)
{
    char popedCh;
    if (!isEmpty(*top))
    {
        struct Node *ptr = *top;
        popedCh = ptr->data;
        *top = (*top)->next;
        free(ptr);
        return popedCh;
    }
    return 0;
}

char stackTop(struct Node *top)
{
    return top->data;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

// int infixToPostfix(char *exp)
// {
//     struct Node *topPostfix = NULL;
//     struct Node *operator= NULL;
//     int i = 0;
//     char poped;
//     while (exp[i] != '\0')
//     {
//         if (!isOperator(exp[i]))
//         {
//             topPostfix = push(topPostfix, exp[i]);
//             i++;
//         }
//         else
//         {
//             if (precedence(exp[i]) > precedence(stackTop(operator)))
//             {
//                 operator= push(operator, exp[i]);
//                 i++;
//             }
//             else
//             {
//                 poped = pop(&operator);
//                 topPostfix = push(topPostfix, poped);

//             }
//         }
//     }

//     if (!isEmpty(operator))
//     {
//         do
//         {

//             poped = pop(&operator);
//             topPostfix = push(topPostfix, poped);

//         } while (isEmpty(operator));
//     }
//     // return topPostfix;

//     while (topPostfix!=NULL)
//     {
//         printf("%s", topPostfix->data);
//         topPostfix->next;
//     }

//     return 1;

// }
struct Node* infixToPostfix(char *exp)
{

struct Node *topPostfix = NULL;
struct Node *operator= NULL;
    int i = 0;
    char poped;
    while (exp[i] != '\0')
    {
        if (!isOperator(exp[i]))
        {
            topPostfix = push(topPostfix, exp[i]);
            i++;
        }
        else
        {
            if (precedence(exp[i]) > precedence(stackTop(operator)))
            {
                operator= push(operator, exp[i]);
                i++;
            }
            else
            {
                poped = pop(&operator);
                topPostfix = push(topPostfix, poped);
            }
        }
    }

    if (!isEmpty(operator))
    {
        do
        {

            poped = pop(&operator);
            topPostfix = push(topPostfix, poped);

        } while (isEmpty(operator));
    return topPostfix;
    }
}

    


void traverse(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("%c\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    char *infix = "a+b";
    struct Node* ret;

    ret = infixToPostfix(infix);
    traverse(ret);
    // printf("postfix is %s" , infixToPostfix(infix));
    // infixToPostfix(infix);
    return 0;
}