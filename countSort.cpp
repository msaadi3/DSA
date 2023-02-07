#include <iostream>
#include <climits>
using namespace std;

int maximum(int A[], int n)
{
    int max = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    int max = maximum(A, n);
    // int *count = new int[max + 1]; // dynamically allocate memory for array
    // int count[max+1];
    int* count = new int[max+1]; 

    // initialize the count array to zero
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    int i, j = 0;
    while (i <= max )
    {
        if (count[i] > 0)
        {
            A[j] = i;
            j++;
            count[i]--;
        } else
        {
            i++;
        }
        
    }
    delete[] count;
}

void print(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<endl;

    }
    
}
int main()
{
    int A[] = {3,6,0, 33,1,99,55};
    countSort(A, 7);
    print(A,7);


    return 0;
}
