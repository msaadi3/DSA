
#include <stdio.h>
#include <stdlib.h>

struct array
{
    int totalSize;
    int usedSize;
    int *arr;
};

void createArray(struct array *ptr, int tsize)
{
    ptr->totalSize = tsize;
    ptr->usedSize = 0;
    ptr->arr = (int *)malloc(ptr->totalSize * sizeof(int));
}

int isFull(struct array *ptr)
{
    if (ptr->usedSize == ptr->totalSize)
    {

        return 1;
    }

    return 0;
}

int isEmpty(struct array *ptr)
{
    if (ptr->usedSize == 0)
    {
        return 1;
    }

    return 0;
}

void traversal(struct array *ptr)
{
    for (int i = 0; i < ptr->usedSize; i++)
    {
        printf("%d\n", ptr->arr[i]);
    }
}

void setValueForUserInputs(struct array *ptr)
{
    int n, element;
    printf("%d\n how many elements you want to isnert");
    scanf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("enter elements");
        scanf("%d", &element);
        ptr->arr[i] = element;
        ptr->usedSize++;
    }
}


void setValue(struct array *ptr, int element)
{
    
         ptr->arr[ptr->usedSize] = element;
        ptr->usedSize++;
    }


int deletion(struct array *ptr, int index)
{

    for (int i = index; i < ptr->usedSize; i++)
    {
        ptr->arr[i] = ptr->arr[i + 1];
    }
    return ptr->usedSize--;
}

int insertion(struct array *ptr, int index, int element)
{
    if (!isFull(ptr))

    {
        for (int i = ptr->usedSize; i = index; i--)
        {
            ptr->arr[i + 1] = ptr->arr[i];
        }
        ptr->arr[index] = element;
        ptr->usedSize++;
    }
    return 0;
}

int main()
{

    struct array *myArray = (struct array *)malloc(sizeof(struct array));
    createArray(myArray, 5);
    setValueForUserInputs(myArray);
    // setValue(myArray,5);
    // insertion(myArray,);
    traversal(myArray);
    deletion(myArray,2);
    traversal(myArray);

    return 0;
}